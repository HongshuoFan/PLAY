/*
  ==============================================================================

    HID_IO_Win.cpp
    Created: 7 Jul 2025 12:56:14pm
    Author:  hs_remote

  ==============================================================================
*/

#include "HID_IO_Win.h"

HID_IO::HID_IO()
{
    // Nothing to do here for now
}

HID_IO::~HID_IO()
{
    stopReadingThread();
    disconnect();
}

HANDLE HID_IO::openFirstHIDDevice()
{
    GUID hidGuid;
    HidD_GetHidGuid(&hidGuid);

    HDEVINFO deviceInfoSet = SetupDiGetClassDevs(&hidGuid, nullptr, nullptr, DIGCF_PRESENT | DIGCF_DEVICEINTERFACE);
    if (deviceInfoSet == INVALID_HANDLE_VALUE)
        return nullptr;

    SP_DEVICE_INTERFACE_DATA deviceInterfaceData;
    deviceInterfaceData.cbSize = sizeof(SP_DEVICE_INTERFACE_DATA);

    HANDLE foundHandle = nullptr;
    for (DWORD i = 0; SetupDiEnumDeviceInterfaces(deviceInfoSet, nullptr, &hidGuid, i, &deviceInterfaceData); ++i)
    {
        DWORD requiredSize = 0;
        SetupDiGetDeviceInterfaceDetail(deviceInfoSet, &deviceInterfaceData, nullptr, 0, &requiredSize, nullptr);
        std::vector<char> detailDataBuffer(requiredSize);
        auto* detailData = reinterpret_cast<SP_DEVICE_INTERFACE_DETAIL_DATA*>(detailDataBuffer.data());
        detailData->cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);

        if (SetupDiGetDeviceInterfaceDetail(deviceInfoSet, &deviceInterfaceData, detailData, requiredSize, nullptr, nullptr))
        {
            // Optionally, filter by device_name here using detailData->DevicePath
            HANDLE handle = CreateFile(detailData->DevicePath, GENERIC_READ | GENERIC_WRITE,
                                       FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, nullptr);
            if (handle != INVALID_HANDLE_VALUE)
            {
                foundHandle = handle;
                break;
            }
        }
    }
    SetupDiDestroyDeviceInfoList(deviceInfoSet);
    return foundHandle;
}

bool HID_IO::connect()
{
    disconnect();
    deviceHandle = openFirstHIDDevice();
    isConneted = (deviceHandle != nullptr);
    return isConneted;
}

void HID_IO::disconnect()
{
    if (deviceHandle)
    {
        CloseHandle(deviceHandle);
        deviceHandle = nullptr;
    }
    isConneted = false;
}

bool HID_IO::writeRawData(const uint8_t* data, size_t reportId, size_t length)
{
    if (!deviceHandle)
        return false;

    std::vector<uint8_t> buffer(length + 1);
    buffer[0] = static_cast<uint8_t>(reportId);
    memcpy(buffer.data() + 1, data, length);

    DWORD bytesWritten = 0;
    BOOL result = WriteFile(deviceHandle, buffer.data(), static_cast<DWORD>(buffer.size()), &bytesWritten, nullptr);
    return result && (bytesWritten == buffer.size());
}

void HID_IO::setDataReceivedCallback(DataReceivedCallback callback)
{
    /*dataReceivedCallback = std::move(callback);*/
}

void HID_IO::startReadingThread()
{
    if (readingThread.joinable())
        return;

    stopThreadFlag = false;
    readingThread = std::thread([this]() { readLoop(); });
}

void HID_IO::stopReadingThread()
{
    stopThreadFlag = true;
    if (readingThread.joinable())
        readingThread.join();
}

void HID_IO::readLoop()
{
    if (!deviceHandle)
        return;

    // Get input report length
    HIDD_ATTRIBUTES attributes;
    attributes.Size = sizeof(HIDD_ATTRIBUTES);
    HidD_GetAttributes(deviceHandle, &attributes);

    PHIDP_PREPARSED_DATA preparsedData = nullptr;
    HidD_GetPreparsedData(deviceHandle, &preparsedData);

    HIDP_CAPS caps;
    HidP_GetCaps(preparsedData, &caps);
    size_t reportLen = caps.InputReportByteLength;

    HidD_FreePreparsedData(preparsedData);

    std::vector<uint8_t> buffer(reportLen);

    while (!stopThreadFlag)
    {
        DWORD bytesRead = 0;
        OVERLAPPED overlapped = {};
        overlapped.hEvent = CreateEvent(nullptr, TRUE, FALSE, nullptr);

        BOOL result = ReadFile(deviceHandle, buffer.data(), static_cast<DWORD>(buffer.size()), &bytesRead, &overlapped);
        if (!result)
        {
            if (GetLastError() == ERROR_IO_PENDING)
            {
                DWORD waitResult = WaitForSingleObject(overlapped.hEvent, 100);
                if (waitResult == WAIT_OBJECT_0)
                {
                    GetOverlappedResult(deviceHandle, &overlapped, &bytesRead, FALSE);
                }
            }
        }
        CloseHandle(overlapped.hEvent);

        if (bytesRead > 0)
        {
            reportData.assign(buffer.begin(), buffer.begin() + bytesRead);
         /*   if (dataReceivedCallback)
                dataReceivedCallback(reportData);*/
            if (dataReceivedCallback) // legacy callback
                dataReceivedCallback();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

void HID_IO::printReport()
{
    if (reportData.empty())
    {
        std::cout << "No report data.\n";
        return;
    }
    std::cout << "Report: ";
    for (size_t i = 0; i < reportData.size(); ++i)
        printf("%02X ", reportData[i]);
    printf("\n");
}
