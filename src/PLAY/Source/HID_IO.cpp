/*
  ===============================================================================

    HID_IO.cpp
    Created: 21 Oct 2023 3:03:58pm
    Author:  Hongshuo Fan

  ===============================================================================
*/

#include <JuceHeader.h>
#include "HID_IO.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <memory>
#include <thread>
#include <utility>

class HID_IO::HidBackend
{
public:
    explicit HidBackend(HID_IO& ownerIn) : owner(ownerIn) {}
    virtual ~HidBackend() = default;

    virtual bool connect() = 0;
    virtual void disconnect() = 0;
    virtual bool writeRawData(const uint8_t* data, size_t reportId, size_t length) = 0;
    virtual void startReadingThread() = 0;
    virtual void stopReadingThread() = 0;
    virtual void printReport() = 0;

protected:
    HID_IO& owner;
};

namespace
{
    class NullHidBackend : public HID_IO::HidBackend
    {
    public:
        explicit NullHidBackend(HID_IO& ownerIn) : HidBackend(ownerIn) {}

        bool connect() override
        {
            owner.isConneted = false;
            return false;
        }

        void disconnect() override
        {
            owner.isConneted = false;
        }

        bool writeRawData(const uint8_t* data, size_t reportId, size_t length) override
        {
            juce::ignoreUnused(data, reportId, length);
            return false;
        }

        void startReadingThread() override {}
        void stopReadingThread() override {}
        void printReport() override {}
    };
}

#if JUCE_MAC

#include <IOKit/IOKitLib.h>
#include <IOKit/hid/IOHIDManager.h>
#include <mach/mach_error.h>
#include <stdexcept>

class HID_IO::MacHidBackend : public HID_IO::HidBackend
{
public:
    explicit MacHidBackend(HID_IO& ownerIn) : HidBackend(ownerIn) {}

    ~MacHidBackend() override
    {
        stopReadingThread();
    }

    bool connect() override
    {
        if (deviceRef != nullptr)
            disconnect();

        startReadingThread();
        return owner.isConneted;
    }

    void disconnect() override
    {
        if (deviceRef != nullptr)
            deviceRef = nullptr;

        owner.isConneted = false;
    }

    bool writeRawData(const uint8_t* data, size_t reportId, size_t length) override
    {
        IOReturn result = kIOReturnError;

        if (deviceRef != nullptr)
        {
            result = IOHIDDeviceSetReport(deviceRef,
                                          kIOHIDReportTypeOutput,
                                          static_cast<CFIndex>(reportId),
                                          data,
                                          static_cast<CFIndex>(length));

            if (result == kIOReturnSuccess)
                return true;

            std::cout << mach_error_string(result) << "\n";
        }
        else
        {
            std::cout << "IOReturn error: " << result << " - " << mach_error_string(result) << std::endl;
        }

        return false;
    }

    void startReadingThread() override
    {
        if (! readingThread.joinable())
        {
            stopThreadFlag = false;
            readingThread = std::thread([this]() { createConnection(); });
        }
        else
        {
            owner.isConneted = false;
        }
    }

    void stopReadingThread() override
    {
        if (readingThread.joinable())
        {
            disconnect();
            stopThreadFlag = true;
            readingThread.join();
        }
    }

    void printReport() override
    {
        if (deviceRef != nullptr && owner.reportData != nullptr)
        {
            uint32_t maxInputReportSize = static_cast<uint32_t>(getIntProperty(deviceRef, CFSTR(kIOHIDMaxInputReportSizeKey)));
            for (uint32_t i = 0; i < maxInputReportSize; ++i)
            {
                std::cout << i << ":";
                printf("%02x ", owner.reportData[i]);
            }
            printf("\n");
        }
    }

private:
    struct DeviceInfo
    {
        MacHidBackend* backend = nullptr;
        DeviceIdType deviceId{};
        IOHIDDeviceRef device = nullptr;
    };

    void createConnection()
    {
        manager = IOHIDManagerCreate(kCFAllocatorDefault, kIOHIDOptionsTypeNone);

        if (manager == nullptr)
            return;

        CFDictionaryRef matchingDict[6];
        matchingDict[0] = createDeviceMatchingDictionary(kHIDPage_GenericDesktop, kHIDUsage_GD_Joystick);
        matchingDict[1] = createDeviceMatchingDictionary(kHIDPage_GenericDesktop, kHIDUsage_GD_GamePad);
        matchingDict[2] = createDeviceMatchingDictionary(kHIDPage_GenericDesktop, kHIDUsage_GD_MultiAxisController);
        matchingDict[3] = createDeviceMatchingDictionary(kHIDPage_GenericDesktop, kHIDUsage_GD_Pointer);
        matchingDict[4] = createDeviceMatchingDictionary(kHIDPage_GenericDesktop, kHIDUsage_GD_AssistiveControl);
        matchingDict[5] = createDeviceMatchingDictionary(kHIDPage_GenericDesktop, kHIDUsage_GD_SpatialController);

        CFArrayRef multiple = CFArrayCreate(kCFAllocatorDefault, (const void**) matchingDict, 6, &kCFTypeArrayCallBacks);

        for (auto dict : matchingDict)
            CFRelease(dict);

        IOHIDManagerSetDeviceMatchingMultiple(manager, multiple);
        CFRelease(multiple);

        IOHIDManagerRegisterDeviceMatchingCallback(manager, &MacHidBackend::onDeviceMatchedStub, this);
        IOHIDManagerOpen(manager, kIOHIDOptionsTypeNone);
        IOHIDManagerScheduleWithRunLoop(manager, CFRunLoopGetCurrent(), CFSTR("CustomLoop"));

        while (CFRunLoopRunInMode(CFSTR("CustomLoop"), 1, true) != kCFRunLoopRunStopped && ! stopThreadFlag)
        {
            owner.isConneted = true;
        }

        IOHIDManagerClose(manager, 0);
        owner.isConneted = false;
        std::cout << "manager closed \n";
        CFRelease(manager);
        manager = nullptr;
    }

    static CFMutableDictionaryRef createDeviceMatchingDictionary(uint32_t usagePage, uint32_t usage)
    {
        CFMutableDictionaryRef result = CFDictionaryCreateMutable(kCFAllocatorDefault,
                                                                   0,
                                                                   &kCFTypeDictionaryKeyCallBacks,
                                                                   &kCFTypeDictionaryValueCallBacks);

        if (result == nullptr)
            throw std::runtime_error("CFDictionaryCreateMutable failed.");

        if (usagePage != 0)
        {
            CFNumberRef pageCFNumberRef = CFNumberCreate(kCFAllocatorDefault, kCFNumberIntType, &usagePage);
            if (pageCFNumberRef == nullptr)
                throw std::runtime_error("CFNumberCreate failed.");

            CFDictionarySetValue(result, CFSTR(kIOHIDDeviceUsagePageKey), pageCFNumberRef);
            CFRelease(pageCFNumberRef);

            if (usage != 0)
            {
                CFNumberRef usageCFNumberRef = CFNumberCreate(kCFAllocatorDefault, kCFNumberIntType, &usage);
                if (usageCFNumberRef == nullptr)
                    throw std::runtime_error("CFNumberCreate failed.");

                CFDictionarySetValue(result, CFSTR(kIOHIDDeviceUsageKey), usageCFNumberRef);
                CFRelease(usageCFNumberRef);
            }
        }

        return result;
    }

    static int getIntProperty(IOHIDDeviceRef device, CFStringRef key)
    {
        int value = 0;
        CFTypeRef property = IOHIDDeviceGetProperty(device, key);

        if (property && CFGetTypeID(property) == CFNumberGetTypeID())
        {
            CFNumberRef number = static_cast<CFNumberRef>(property);
            CFNumberGetValue(number, kCFNumberSInt32Type, &value);
            return value;
        }

        return value;
    }

    static DeviceIdType getDeviceID(IOHIDDeviceRef dev)
    {
        DeviceIdType device{ 0 };
        int vendor = getIntProperty(dev, CFSTR(kIOHIDVendorIDKey));
        int product = getIntProperty(dev, CFSTR(kIOHIDProductIDKey));
        int location = getIntProperty(dev, CFSTR(kIOHIDLocationIDKey));
        device.at(0) = vendor & 0xFF;
        device.at(1) = (vendor >> 8) & 0xFF;
        device.at(2) = product & 0xFF;
        device.at(3) = (product >> 8) & 0xFF;
        device.at(4) = (location >> 16) & 0xFF;
        device.at(5) = (location >> 24) & 0xFF;
        return device;
    }

    static void onDeviceMatchedStub(void* context, IOReturn result, void* sender, IOHIDDeviceRef device)
    {
        juce::ignoreUnused(result, sender);
        static_cast<MacHidBackend*>(context)->onDeviceMatched(device);
    }

    void onDeviceMatched(IOHIDDeviceRef device)
    {
        devices.emplace_back();

        auto& deviceInfo = devices.back();
        deviceInfo.backend = this;
        deviceInfo.device = device;
        deviceInfo.deviceId = getDeviceID(device);

        CFStringRef name_cf = static_cast<CFStringRef>(IOHIDDeviceGetProperty(device, CFSTR(kIOHIDProductKey)));
        CFStringEncoding encodingMethod = CFStringGetSystemEncoding();
        const char* name = CFStringGetCStringPtr(name_cf, encodingMethod);

        if (! stopThreadFlag && name)
        {
            if (owner.device_name != nullptr && std::strcmp(name, owner.device_name) == 0)
            {
                deviceRef = device;
                uint32_t maxInputReportSize = static_cast<uint32_t>(getIntProperty(device, CFSTR(kIOHIDMaxInputReportSizeKey)));
                uint8_t* reportBuffer = static_cast<uint8_t*>(calloc(maxInputReportSize, sizeof(uint8_t)));
                IOHIDDeviceRegisterInputReportCallback(device,
                                                       reportBuffer,
                                                       maxInputReportSize,
                                                       getCallback(),
                                                       &deviceInfo);
                owner.isConneted = true;
            }
            else
            {
                std::cout << name << " Not match \n";
            }
        }
    }

    static IOHIDReportCallback getCallback()
    {
        return &MacHidBackend::inputReportCallbackStub;
    }

    static void inputReportCallbackStub(void* context,
                                        IOReturn result,
                                        void* sender,
                                        IOHIDReportType type,
                                        uint32_t reportID,
                                        uint8_t* report,
                                        CFIndex reportLength)
    {
        auto* deviceInfo = reinterpret_cast<DeviceInfo*>(context);
        deviceInfo->backend->inputReportCallback(*deviceInfo, result, sender, type, reportID, report, reportLength);
    }

    void inputReportCallback(DeviceInfo& deviceInfo,
                             IOReturn result,
                             void* sender,
                             IOHIDReportType type,
                             uint32_t reportID,
                             uint8_t* report,
                             CFIndex reportLength)
    {
        juce::ignoreUnused(deviceInfo, result, sender, type, reportID, reportLength);
        owner.reportData = report;

        if (owner.dataReceivedCallback)
            owner.dataReceivedCallback();
    }

    IOHIDManagerRef manager = nullptr;
    IOHIDDeviceRef deviceRef = nullptr;
    std::list<DeviceInfo> devices;
    std::thread readingThread;
    bool stopThreadFlag = false;
};

#endif // JUCE_MAC

namespace
{
    std::unique_ptr<HID_IO::HidBackend> createBackend(HID_IO& owner)
    {
       #if JUCE_MAC
        return std::make_unique<HID_IO::MacHidBackend>(owner);
       #else
        return std::make_unique<NullHidBackend>(owner);
       #endif
    }
}

HID_IO::HID_IO()
    : backend(createBackend(*this))
{
    device_name = nullptr;
    reportData = nullptr;
    OuputData = nullptr;
    isConneted = false;
}

HID_IO::~HID_IO()
{
    stopReadingThread();
}

bool HID_IO::connect()
{
    if (backend != nullptr)
        isConneted = backend->connect();
    else
        isConneted = false;

    return isConneted;
}

void HID_IO::disconnect()
{
    if (backend != nullptr)
        backend->disconnect();

    isConneted = false;
}

bool HID_IO::writeRawData(const uint8_t* data, size_t reportId, size_t length)
{
    if (backend != nullptr)
        return backend->writeRawData(data, reportId, length);

    return false;
}

void HID_IO::setDataReceivedCallback(DataReceivedCallback callback)
{
    dataReceivedCallback = std::move(callback);
}

void HID_IO::startReadingThread()
{
    if (backend != nullptr)
        backend->startReadingThread();
}

void HID_IO::stopReadingThread()
{
    if (backend != nullptr)
        backend->stopReadingThread();
}

void HID_IO::printReport()
{
    if (backend != nullptr)
        backend->printReport();
}
