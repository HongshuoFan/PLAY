/*
  ===============================================================================

    HID_IO.cpp
    Created: 21 Oct 2023 3:03:58pm
    Author:  Hongshuo Fan

  ===============================================================================
*/

#include <JuceHeader.h>
#include "HID_IO.h"

#include <atomic>
#include <chrono>
#include <condition_variable>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
#include <utility>
#include <vector>

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

class HID_IO::NullHidBackend : public HID_IO::HidBackend
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

#if JUCE_MAC

#include <IOKit/IOKitLib.h>
#include <IOKit/hid/IOHIDManager.h>
#include <IOKit/hid/IOHIDLib.h>
#include <mach/mach_error.h>

class HID_IO::MacHidBackend : public HID_IO::HidBackend
{
public:
    explicit MacHidBackend(HID_IO& ownerIn)
        : HidBackend(ownerIn)
    {
    }

    ~MacHidBackend() override
    {
        shutdown();
    }

    bool connect() override
    {
        shutdown();

        if (owner.device_name == nullptr)
            return false;

        owner.isConneted = false;
        owner.reportData = nullptr;

        if (! startThread())
            return false;

        if (! waitForConnection())
        {
            shutdown();
            return false;
        }

        return true;
    }

    void disconnect() override
    {
        shutdown();
    }

    bool writeRawData(const uint8_t* data, size_t reportId, size_t length) override
    {
        if (activeDevice.device != nullptr)
        {
            const IOReturn result = IOHIDDeviceSetReport(activeDevice.device,
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
            std::cout << "IOReturn error: " << mach_error_string(kIOReturnNotOpen) << std::endl;
        }

        return false;
    }

    void startReadingThread() override
    {
        startThread();
    }

    void stopReadingThread() override
    {
        shutdown();
    }

    void printReport() override
    {
        if (activeDevice.device != nullptr && owner.reportData != nullptr)
        {
            const auto maxInputReportSize = static_cast<uint32_t>(getIntProperty(activeDevice.device, CFSTR(kIOHIDMaxInputReportSizeKey)));
            for (uint32_t i = 0; i < maxInputReportSize; ++i)
            {
                std::cout << i << ":";
                printf("%02x ", owner.reportData[i]);
            }
            printf("\n");
        }
    }

private:
    struct DeviceContext
    {
        IOHIDDeviceRef device = nullptr;
        std::unique_ptr<uint8_t, decltype(&std::free)> reportBuffer{ nullptr, &std::free };
        CFIndex reportLength = 0;
    };

    bool startThread()
    {
        if (readingThread.joinable())
            return true;

        {
            std::lock_guard<std::mutex> lock(stateMutex);
            hasConnectionResult = false;
            connectionResult = false;
        }

        stopThread.store(false);
        runLoop.store(nullptr);
        readingThread = std::thread([this]() { runLoopThread(); });
        return readingThread.joinable();
    }

    bool waitForConnection()
    {
        std::unique_lock<std::mutex> lock(stateMutex);

        if (! stateCV.wait_for(lock, std::chrono::seconds(5), [this]() { return hasConnectionResult; }))
            return false;

        return connectionResult;
    }

    void shutdown()
    {
        stopThread.store(true);

        if (auto loop = runLoop.load())
            CFRunLoopStop(loop);

        if (readingThread.joinable())
            readingThread.join();

        stopThread.store(false);
        runLoop.store(nullptr);
        scheduledLoop = nullptr;

        owner.isConneted = false;
        owner.reportData = nullptr;

        cleanupActiveDevice();

        manager = nullptr;

        std::lock_guard<std::mutex> lock(stateMutex);
        hasConnectionResult = false;
        connectionResult = false;
    }

    void runLoopThread()
    {
        manager = IOHIDManagerCreate(kCFAllocatorDefault, kIOHIDOptionsTypeNone);

        if (manager == nullptr)
        {
            signalConnectionResult(false);
            return;
        }

        std::vector<CFMutableDictionaryRef> matchingDicts = {
            createDeviceMatchingDictionary(kHIDPage_GenericDesktop, kHIDUsage_GD_Joystick),
            createDeviceMatchingDictionary(kHIDPage_GenericDesktop, kHIDUsage_GD_GamePad),
            createDeviceMatchingDictionary(kHIDPage_GenericDesktop, kHIDUsage_GD_MultiAxisController),
            createDeviceMatchingDictionary(kHIDPage_GenericDesktop, kHIDUsage_GD_Pointer),
            createDeviceMatchingDictionary(kHIDPage_GenericDesktop, kHIDUsage_GD_AssistiveControl),
            createDeviceMatchingDictionary(kHIDPage_GenericDesktop, kHIDUsage_GD_SpatialController)
        };

        bool matchingOk = true;

        for (auto dict : matchingDicts)
        {
            if (dict == nullptr)
            {
                matchingOk = false;
                break;
            }
        }

        if (! matchingOk)
        {
            for (auto dict : matchingDicts)
            {
                if (dict != nullptr)
                    CFRelease(dict);
            }

            CFRelease(manager);
            manager = nullptr;
            signalConnectionResult(false);
            return;
        }

        std::vector<const void*> rawMatchingDicts;
        rawMatchingDicts.reserve(matchingDicts.size());

        for (auto dict : matchingDicts)
            rawMatchingDicts.push_back(dict);

        CFArrayRef multiple = CFArrayCreate(kCFAllocatorDefault,
                                            rawMatchingDicts.data(),
                                            static_cast<CFIndex>(rawMatchingDicts.size()),
                                            &kCFTypeArrayCallBacks);

        for (auto dict : matchingDicts)
            CFRelease(dict);

        if (multiple == nullptr)
        {
            CFRelease(manager);
            manager = nullptr;
            signalConnectionResult(false);
            return;
        }

        IOHIDManagerSetDeviceMatchingMultiple(manager, multiple);
        CFRelease(multiple);

        IOHIDManagerRegisterDeviceMatchingCallback(manager, &MacHidBackend::onDeviceMatchedStub, this);
        IOHIDManagerRegisterDeviceRemovalCallback(manager, &MacHidBackend::onDeviceRemovedStub, this);

        const IOReturn openResult = IOHIDManagerOpen(manager, kIOHIDOptionsTypeNone);

        if (openResult != kIOReturnSuccess)
        {
            std::cout << mach_error_string(openResult) << "\n";
            CFRelease(manager);
            manager = nullptr;
            signalConnectionResult(false);
            return;
        }

        CFRunLoopRef currentLoop = CFRunLoopGetCurrent();
        scheduledLoop = currentLoop;
        runLoop.store(currentLoop);
        IOHIDManagerScheduleWithRunLoop(manager, currentLoop, CFSTR("CustomLoop"));

        processExistingDevices();

        while (! stopThread.load())
        {
            const auto status = CFRunLoopRunInMode(CFSTR("CustomLoop"), 1, true);

            if (status == kCFRunLoopRunStopped || status == kCFRunLoopRunFinished)
                break;
        }

        runLoop.store(nullptr);

        if (manager != nullptr && scheduledLoop != nullptr)
            IOHIDManagerUnscheduleFromRunLoop(manager, scheduledLoop, CFSTR("CustomLoop"));

        scheduledLoop = nullptr;

        if (manager != nullptr)
        {
            IOHIDManagerClose(manager, kIOHIDOptionsTypeNone);
            CFRelease(manager);
            manager = nullptr;
        }

        owner.isConneted = false;
        owner.reportData = nullptr;
        cleanupActiveDevice();

        signalConnectionResult(false);
    }

    void processExistingDevices()
    {
        if (manager == nullptr)
            return;

        CFSetRef deviceSet = IOHIDManagerCopyDevices(manager);

        if (deviceSet == nullptr)
            return;

        const CFIndex deviceCount = CFSetGetCount(deviceSet);

        if (deviceCount > 0)
        {
            std::vector<const void*> existingDevices(static_cast<size_t>(deviceCount));
            CFSetGetValues(deviceSet, existingDevices.data());

            for (const void* deviceValue : existingDevices)
            {
                auto device = static_cast<IOHIDDeviceRef>(const_cast<void*>(deviceValue));

                if (device != nullptr)
                    onDeviceMatched(kIOReturnSuccess, device);
            }
        }

        CFRelease(deviceSet);
    }

    void cleanupActiveDevice()
    {
        activeDevice.reportBuffer.reset();
        activeDevice.reportLength = 0;
        activeDevice.device = nullptr;
    }

    void signalConnectionResult(bool success)
    {
        std::lock_guard<std::mutex> lock(stateMutex);

        if (hasConnectionResult)
            return;

        connectionResult = success;
        hasConnectionResult = true;
        stateCV.notify_one();
    }

    static CFMutableDictionaryRef createDeviceMatchingDictionary(uint32_t usagePage, uint32_t usage)
    {
        CFMutableDictionaryRef result = CFDictionaryCreateMutable(kCFAllocatorDefault,
                                                                   0,
                                                                   &kCFTypeDictionaryKeyCallBacks,
                                                                   &kCFTypeDictionaryValueCallBacks);

        if (result == nullptr)
            return nullptr;

        if (usagePage != 0)
        {
            CFNumberRef pageCFNumberRef = CFNumberCreate(kCFAllocatorDefault, kCFNumberIntType, &usagePage);

            if (pageCFNumberRef == nullptr)
            {
                CFRelease(result);
                return nullptr;
            }

            CFDictionarySetValue(result, CFSTR(kIOHIDDeviceUsagePageKey), pageCFNumberRef);
            CFRelease(pageCFNumberRef);

            if (usage != 0)
            {
                CFNumberRef usageCFNumberRef = CFNumberCreate(kCFAllocatorDefault, kCFNumberIntType, &usage);

                if (usageCFNumberRef == nullptr)
                {
                    CFRelease(result);
                    return nullptr;
                }

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

        if (property != nullptr && CFGetTypeID(property) == CFNumberGetTypeID())
        {
            CFNumberRef number = static_cast<CFNumberRef>(property);
            CFNumberGetValue(number, kCFNumberSInt32Type, &value);
        }

        return value;
    }

    static void onDeviceMatchedStub(void* context, IOReturn result, void* sender, IOHIDDeviceRef device)
    {
        juce::ignoreUnused(sender);
        static_cast<MacHidBackend*>(context)->onDeviceMatched(result, device);
    }

    void onDeviceMatched(IOReturn result, IOHIDDeviceRef device)
    {
        juce::ignoreUnused(result);

        if (stopThread.load())
            return;

        if (owner.device_name == nullptr)
            return;

        if (activeDevice.device != nullptr)
        {
            if (activeDevice.device == device)
            {
                if (! owner.isConneted)
                {
                    owner.isConneted = true;
                    signalConnectionResult(true);
                }
            }

            return;
        }

        char nameBuffer[256]{};
        bool hasName = false;

        if (auto nameCF = static_cast<CFStringRef>(IOHIDDeviceGetProperty(device, CFSTR(kIOHIDProductKey))))
            hasName = CFStringGetCString(nameCF, nameBuffer, sizeof(nameBuffer), kCFStringEncodingUTF8);

        if (! hasName)
            return;

        if (std::strcmp(nameBuffer, owner.device_name) != 0)
            return;

        CFIndex maxInputReportSize = getIntProperty(device, CFSTR(kIOHIDMaxInputReportSizeKey));

        if (maxInputReportSize <= 0)
            maxInputReportSize = 64;

        auto* buffer = static_cast<uint8_t*>(std::calloc(static_cast<size_t>(maxInputReportSize), sizeof(uint8_t)));

        if (buffer == nullptr)
        {
            signalConnectionResult(false);
            return;
        }

        activeDevice.reportBuffer.reset(buffer);
        activeDevice.reportLength = maxInputReportSize;
        activeDevice.device = device;

        IOHIDDeviceRegisterInputReportCallback(device,
                                               activeDevice.reportBuffer.get(),
                                               activeDevice.reportLength,
                                               getCallback(),
                                               this);

        owner.reportData = activeDevice.reportBuffer.get();
        owner.isConneted = true;
        signalConnectionResult(true);
    }

    static void onDeviceRemovedStub(void* context, IOReturn result, void* sender, IOHIDDeviceRef device)
    {
        juce::ignoreUnused(result, sender);
        static_cast<MacHidBackend*>(context)->onDeviceRemoved(device);
    }

    void onDeviceRemoved(IOHIDDeviceRef device)
    {
        if (activeDevice.device != device)
            return;

        owner.isConneted = false;
        owner.reportData = nullptr;
        cleanupActiveDevice();
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
        auto* backend = static_cast<MacHidBackend*>(context);
        backend->inputReportCallback(result, sender, type, reportID, report, reportLength);
    }

    void inputReportCallback(IOReturn result,
                             void* sender,
                             IOHIDReportType type,
                             uint32_t reportID,
                             uint8_t* report,
                             CFIndex reportLength)
    {
        juce::ignoreUnused(result, sender, type, reportID, report, reportLength);

        owner.reportData = activeDevice.reportBuffer.get();

        if (owner.dataReceivedCallback)
            owner.dataReceivedCallback();
    }

    IOHIDManagerRef manager = nullptr;
    DeviceContext activeDevice;
    std::thread readingThread;
    std::atomic<bool> stopThread{ false };
    std::atomic<CFRunLoopRef> runLoop { nullptr };
    CFRunLoopRef scheduledLoop = nullptr;

    std::mutex stateMutex;
    std::condition_variable stateCV;
    bool hasConnectionResult = false;
    bool connectionResult = false;
};

#endif // JUCE_MAC


std::unique_ptr<HID_IO::HidBackend> HID_IO::createBackend(HID_IO& owner)
{
#if JUCE_MAC
    return std::make_unique<MacHidBackend>(owner);
#else
    return std::make_unique<NullHidBackend>(owner);
#endif
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
