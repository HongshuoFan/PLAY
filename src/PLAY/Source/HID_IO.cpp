/*
  ==============================================================================

    HID_IO.cpp
    Created: 21 Oct 2023 3:03:58pm
    Author:  Hongshuo Fan

  ==============================================================================
*/

#include <JuceHeader.h>
#include "HID_IO.h"

//==============================================================================
HID_IO::HID_IO()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
//    manager = IOHIDManagerCreate(kCFAllocatorDefault, kIOHIDOptionsTypeNone);
//    IOHIDManagerSetDeviceMatching(manager, NULL);
//    IOHIDManagerScheduleWithRunLoop(manager, CFRunLoopGetCurrent(), kCFRunLoopDefaultMode);
//    IOHIDManagerOpen(manager, kIOHIDOptionsTypeNone);
    //startReadingThread();
    int res = hid_init();
    std::cout<< res <<" hidapi is available \n";


}

HID_IO::~HID_IO()
{
    stopReadingThread();
//    IOHIDManagerClose(manager, kIOHIDOptionsTypeNone);
//    CFRelease(manager);
}

bool HID_IO::connect(IOHIDDeviceRef newDevice) {
    
    if(device){
//        disconnect();
        stopReadingThread();
    }
    
    if(newDevice){
        device = newDevice;
        startReadingThread();
        return true;
    }
    
    return false;
}

void HID_IO::disconnect() {
    
    if (device) {
//           IOHIDDeviceClose(device, kIOHIDOptionsTypeNone);
           device = NULL;
       }
}


bool HID_IO::writeRawData(unsigned char* data, int size) {
    if (device) {
        IOReturn result = IOHIDDeviceSetReport(device, kIOHIDReportTypeOutput, 0, data, size);
        return result == kIOReturnSuccess;
    }
    return false;
}

void HID_IO::setDataReceivedCallback(DataReceivedCallback callback) {
    dataReceivedCallback = callback;
}

void HID_IO::startReadingThread() {
    if (!readingThread.joinable()) {
        
        stopThreadFlag = false;
        readingThread = std::thread([this]() {
            creatConncet();
        });
    }
}

void HID_IO::stopReadingThread() {
    if (readingThread.joinable()) {
        disconnect();
        stopThreadFlag = true;
        readingThread.join();
    }
}

int HID_IO::GetIntProperty(IOHIDDeviceRef device, CFStringRef key)
{
    int value = 0;
    CFTypeRef property = IOHIDDeviceGetProperty(device, key);
    
    if (property && CFGetTypeID(property) == CFNumberGetTypeID()) {
        CFNumberRef number = static_cast<CFNumberRef>(property);
        CFNumberGetValue(number, kCFNumberSInt32Type, &value);
        return value;
        // Now you can use 'number' as a CFNumberRef
    } else {
        // The property is not a CFNumberRef or it is NULL
        // Handle this case accordingly
    }
    //CFNumberRef ref = static_cast<CFNumberRef>(IOHIDDeviceGetProperty(device, key));
    //CFNumberGetValue(ref, kCFNumberSInt32Type, &value);
    //CFNumberGetValue(ref, kCFNumberSInt32Type, &value);
    
    return value;
}

bool HID_IO::readRawData(unsigned char* buffer, int bufferSize) {
    if (device) {
        CFIndex reportID = 6; // Set the appropriate report ID if necessary
        
        uint32_t max_input_report_size = GetIntProperty(device, CFSTR(kIOHIDMaxInputReportSizeKey));
        uint8_t* report_buffer = static_cast<uint8_t*>(calloc(max_input_report_size, sizeof(uint8_t)));
        CFIndex reportLength = max_input_report_size;
        IOReturn result = IOHIDDeviceGetReport(device, kIOHIDReportTypeInput, reportID, report_buffer, &reportLength);

        
        return result == kIOReturnSuccess;
    }
    return false;
}

std::vector<unsigned char> HID_IO::getInputData() const {
    return inputData;
}

void HID_IO::creatConncet()
{
    manager = IOHIDManagerCreate(kCFAllocatorDefault, 0);
    
    {
        CFDictionaryRef matchingDict[4];
        matchingDict[0] = CreateDeviceMatchingDictionary(kHIDPage_GenericDesktop, kHIDUsage_GD_Joystick);
        matchingDict[1] = CreateDeviceMatchingDictionary(kHIDPage_GenericDesktop, kHIDUsage_GD_GamePad);
        matchingDict[2] = CreateDeviceMatchingDictionary(kHIDPage_GenericDesktop, kHIDUsage_GD_MultiAxisController);
        matchingDict[3] = CreateDeviceMatchingDictionary(kHIDPage_GenericDesktop, kHIDUsage_GD_Pointer);
        
        CFArrayRef multiple = CFArrayCreate(kCFAllocatorDefault, (const void**)matchingDict, 3, &kCFTypeArrayCallBacks);
        CFRelease(matchingDict[0]);
        CFRelease(matchingDict[1]);
        CFRelease(matchingDict[2]);
        CFRelease(matchingDict[3]);
        IOHIDManagerSetDeviceMatchingMultiple(manager, multiple);
    }
    IOHIDManagerRegisterDeviceMatchingCallback(manager, OnDeviceMatchedStub, this);
    IOHIDManagerOpen(manager, kIOHIDOptionsTypeNone);
    IOHIDManagerScheduleWithRunLoop(manager, CFRunLoopGetCurrent(), CFSTR("CustomLoop"));
    while(CFRunLoopRunInMode(CFSTR("CustomLoop"), 1, true) != kCFRunLoopRunStopped && stopThreadFlag){
        
    }
    IOHIDManagerClose(manager, 0);
}

CFMutableDictionaryRef HID_IO::CreateDeviceMatchingDictionary(uint32_t usagePage, uint32_t usage)
{
    CFMutableDictionaryRef result = CFDictionaryCreateMutable(kCFAllocatorDefault, 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
    if(result == nullptr) throw std::runtime_error("CFDictionaryCreateMutable failed.");
    if(usagePage != 0)
    {
        // Add key for device type to refine the matching dictionary.
        CFNumberRef pageCFNumberRef = CFNumberCreate(kCFAllocatorDefault, kCFNumberIntType, &usagePage);
        if(pageCFNumberRef == nullptr) throw std::runtime_error("CFNumberCreate failed.");
        CFDictionarySetValue(result, CFSTR(kIOHIDDeviceUsagePageKey), pageCFNumberRef);
        CFRelease(pageCFNumberRef);
        // note: the usage is only valid if the usage page is also defined
        if(usage != 0){
            CFNumberRef usageCFNumberRef = CFNumberCreate(kCFAllocatorDefault, kCFNumberIntType, &usage);
            if(usageCFNumberRef == nullptr) throw std::runtime_error("CFNumberCreate failed.");
            CFDictionarySetValue(result, CFSTR(kIOHIDDeviceUsageKey), usageCFNumberRef);
            CFRelease(usageCFNumberRef);
        }
    }
    return result;
}

void HID_IO::OnDeviceMatchedStub(void* context, IOReturn result, void* sender, IOHIDDeviceRef device)
{
    reinterpret_cast<HID_IO*>(context)->OnDeviceMatched(result, sender, device);
}

void HID_IO::OnDeviceMatched(IOReturn result, void* sender, IOHIDDeviceRef device)
{
    CFStringRef name_cf = static_cast<CFStringRef>(IOHIDDeviceGetProperty(device, CFSTR(kIOHIDProductKey)));
    CFStringEncoding encodingMethod = CFStringGetSystemEncoding();
    const char *name = CFStringGetCStringPtr(name_cf, encodingMethod);
    
    
//    CFStringRef size_cf = static_cast<CFStringRef>(IOHIDDeviceGetProperty(device, CFSTR(kIOHIDMaxInputReportSizeKey)));
    
    uint32_t max_input_report_size = GetIntProperty(device, CFSTR(kIOHIDMaxInputReportSizeKey));
    
    uint8_t* report_buffer = static_cast<uint8_t*>(calloc(max_input_report_size, sizeof(uint8_t)));
    auto InputReportCallbackStub = GetCallback(device);
    IOHIDDeviceRegisterInputReportCallback(device, report_buffer, max_input_report_size, InputReportCallbackStub, nullptr);
    
    std::cout<< name <<" is available \n";
}

IOHIDReportCallback HID_IO::GetCallback(IOHIDDeviceRef device){
    return &InputReportCallbackStub;
}

void HID_IO::InputReportCallbackStub(void* context, IOReturn result, void* sender, IOHIDReportType type, uint32_t reportID, uint8_t* report, CFIndex reportLength){

//    auto deviceInfo = reinterpret_cast<DEVICE_INFO*>(context);
//    deviceInfo->provider->InputReportCallback_JC(deviceInfo, result, sender, type, reportID, report, reportLength);
    std::cout<<  "RegisterInputReportCallback" << "\n";
    reinterpret_cast<HID_IO*>(context)->InputReportCallback(result, sender, type, reportID, report, reportLength);
}

void HID_IO::InputReportCallback(IOReturn result, void* sender, IOHIDReportType type, uint32_t reportID, uint8_t* report, CFIndex reportLength)
{
    std::cout<<  "report[13]" << "\n";
}
