/*
  ==============================================================================

    ListHID_Win.cpp
    Created: 7 Jul 2025 1:04:00pm
    Author:  HS Fan

  ==============================================================================
*/

#include "ListHID_Win.h"

void ListHID::get_hid_list()
{
    // Clean up previous handles and data
    for (auto& entry : devicesMap)
    {
        if (entry.second)
            CloseHandle(entry.second);
    }
    devicesMap.clear();
    uniqueDevices.clear();

    GUID hidGuid;
    HidD_GetHidGuid(&hidGuid);

    HDEVINFO deviceInfoSet = SetupDiGetClassDevs(&hidGuid, nullptr, nullptr, DIGCF_PRESENT | DIGCF_DEVICEINTERFACE);
    if (deviceInfoSet == INVALID_HANDLE_VALUE)
        return;

    SP_DEVICE_INTERFACE_DATA deviceInterfaceData;
    deviceInterfaceData.cbSize = sizeof(SP_DEVICE_INTERFACE_DATA);

    for (DWORD i = 0; SetupDiEnumDeviceInterfaces(deviceInfoSet, nullptr, &hidGuid, i, &deviceInterfaceData); ++i)
    {
        DWORD requiredSize = 0;
        SetupDiGetDeviceInterfaceDetail(deviceInfoSet, &deviceInterfaceData, nullptr, 0, &requiredSize, nullptr);
        std::vector<char> detailDataBuffer(requiredSize);
        auto* detailData = reinterpret_cast<SP_DEVICE_INTERFACE_DETAIL_DATA*>(detailDataBuffer.data());
        detailData->cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);

        if (SetupDiGetDeviceInterfaceDetail(deviceInfoSet, &deviceInterfaceData, detailData, requiredSize, nullptr, nullptr))
        {
            HANDLE handle = CreateFile(detailData->DevicePath, GENERIC_READ | GENERIC_WRITE,
                                       FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_EXISTING, 0, nullptr);
            if (handle != INVALID_HANDLE_VALUE)
            {
                wchar_t productNameW[256] = {0};
                if (HidD_GetProductString(handle, productNameW, sizeof(productNameW)))
                {
                    juce::String productName(productNameW);
                    // Only add if unique
                    if (uniqueDevices.insert(productName).second)
                    {
                        devicesMap[productName] = handle;
                    }
                    else
                    {
                        CloseHandle(handle);
                    }
                }
                else
                {
                    CloseHandle(handle);
                }
            }
        }
    }
    SetupDiDestroyDeviceInfoList(deviceInfoSet);
}
