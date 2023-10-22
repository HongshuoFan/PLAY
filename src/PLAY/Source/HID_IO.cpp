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



}

HID_IO::~HID_IO()
{
    stopReadingThread();
//    IOHIDManagerClose(manager, kIOHIDOptionsTypeNone);
//    CFRelease(manager);
}


static int GetIntProperty(IOHIDDeviceRef device, CFStringRef key)
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

static DeviceIdType GetDeviceID(IOHIDDeviceRef dev)
{
    DeviceIdType device{0};
    int vendor = GetIntProperty(dev, CFSTR(kIOHIDVendorIDKey));
    int product = GetIntProperty(dev, CFSTR(kIOHIDProductIDKey));
    int location = GetIntProperty(dev, CFSTR(kIOHIDLocationIDKey));
    device.at(0) = vendor & 0xFF;
    device.at(1) = (vendor >> 8) & 0xFF;
    device.at(2) = product & 0xFF;
    device.at(3) = (product >> 8) & 0xFF;
    device.at(4) = (location >> 16) & 0xFF;
    device.at(5) = (location >> 24) & 0xFF;
    return device;
}

bool HID_IO::connect() {
    
    if(deviceRF){
        disconnect();
    }
    startReadingThread();
    
    return true;
    
    
//    return false;
}

void HID_IO::disconnect() {
    
    if (deviceRF) {
//           IOHIDDeviceClose(device, kIOHIDOptionsTypeNone);
        deviceRF = NULL;
       }
}


bool HID_IO::writeRawData(unsigned char* data, int size) {
    if (deviceRF) {
        IOReturn result = IOHIDDeviceSetReport(deviceRF, kIOHIDReportTypeOutput, 0, data, size);
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


bool HID_IO::readRawData(unsigned char* buffer, int bufferSize) {
    if (deviceRF) {
        CFIndex reportID = 6; // Set the appropriate report ID if necessary
        
        uint32_t max_input_report_size = GetIntProperty(deviceRF, CFSTR(kIOHIDMaxInputReportSizeKey));
        uint8_t* report_buffer = static_cast<uint8_t*>(calloc(max_input_report_size, sizeof(uint8_t)));
        CFIndex reportLength = max_input_report_size;
        IOReturn result = IOHIDDeviceGetReport(deviceRF, kIOHIDReportTypeInput, reportID, report_buffer, &reportLength);

        
        return result == kIOReturnSuccess;
    }
    return false;
}

std::vector<unsigned char> HID_IO::getInputData() const {
    return inputData;
}

void HID_IO::creatConncet()
{
    manager = IOHIDManagerCreate(kCFAllocatorDefault, kIOHIDOptionsTypeNone);
    
    {
        CFDictionaryRef matchingDict[6];
        matchingDict[0] = CreateDeviceMatchingDictionary(kHIDPage_GenericDesktop, kHIDUsage_GD_Joystick);
        matchingDict[1] = CreateDeviceMatchingDictionary(kHIDPage_GenericDesktop, kHIDUsage_GD_GamePad);
        matchingDict[2] = CreateDeviceMatchingDictionary(kHIDPage_GenericDesktop, kHIDUsage_GD_MultiAxisController);
        matchingDict[3] = CreateDeviceMatchingDictionary(kHIDPage_GenericDesktop, kHIDUsage_GD_Pointer);
        matchingDict[4] = CreateDeviceMatchingDictionary(kHIDPage_GenericDesktop, kHIDUsage_GD_AssistiveControl);
        matchingDict[5] = CreateDeviceMatchingDictionary(kHIDPage_GenericDesktop, kHIDUsage_GD_SpatialController);
        CFArrayRef multiple = CFArrayCreate(kCFAllocatorDefault, (const void**)matchingDict, 6, &kCFTypeArrayCallBacks);
        CFRelease(matchingDict[0]);
        CFRelease(matchingDict[1]);
        CFRelease(matchingDict[2]);
        CFRelease(matchingDict[3]);
        CFRelease(matchingDict[4]);
        CFRelease(matchingDict[5]);
        IOHIDManagerSetDeviceMatchingMultiple(manager, multiple);
//        CFDictionaryRef matchingDict = IOServiceMatching(kIOHIDDeviceKey);
//        IOHIDManagerSetDeviceMatching(manager, matchingDict);
//        CFRelease(matchingDict);
        
    }
    IOHIDManagerRegisterDeviceMatchingCallback(manager, OnDeviceMatchedStub, this);
    IOHIDManagerOpen(manager, kIOHIDOptionsTypeNone);
    IOHIDManagerScheduleWithRunLoop(manager, CFRunLoopGetCurrent(), CFSTR("CustomLoop"));
    while(CFRunLoopRunInMode(CFSTR("CustomLoop"), 1, true) != kCFRunLoopRunStopped && !stopThreadFlag){
//        std::cout<<"CFRunLoopRunInMode \n";
    }
    
    IOHIDManagerClose(manager, 0);
    std::cout<<"manager closed \n";
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
    m_devices.push_back(DEVICE_INFO());
    
    auto& deviceInfo = *m_devices.rbegin();
    deviceInfo.provider = this;
    deviceInfo.device = device;
    deviceInfo.deviceId = GetDeviceID(device);
    
    //std::cout<< "check "<< device_name  <<" is match? \n";
   
    
    CFStringRef name_cf = static_cast<CFStringRef>(IOHIDDeviceGetProperty(device, CFSTR(kIOHIDProductKey)));
    CFStringEncoding encodingMethod = CFStringGetSystemEncoding();
    const char *name = CFStringGetCStringPtr(name_cf, encodingMethod);
    
    std::cout<< "check "<< name  <<" is match? \n";
    
    if(!stopThreadFlag){
        if (strcmp(name, device_name) == 0){
            
            deviceRF = device;
            uint32_t max_input_report_size = GetIntProperty(device, CFSTR(kIOHIDMaxInputReportSizeKey));
            uint8_t* report_buffer = static_cast<uint8_t*>(calloc(max_input_report_size, sizeof(uint8_t)));
            auto InputReportCallbackStub = GetCallback(device);
            IOHIDDeviceRegisterInputReportCallback(device, report_buffer, max_input_report_size, InputReportCallbackStub, &deviceInfo);
            std::cout<< name <<" is available \n";
            std::cout<< max_input_report_size <<"  max_input_report_size \n";
            
        }else{
            
//            std::cout<< name <<" Not match \n";
           
            return;
        }
        
        //    CFStringRef size_cf = static_cast<CFStringRef>(IOHIDDeviceGetProperty(device, CFSTR(kIOHIDMaxInputReportSizeKey)));
        return;
    }
   
}

IOHIDReportCallback HID_IO::GetCallback(IOHIDDeviceRef device){
    return &InputReportCallbackStub;
}

void HID_IO::InputReportCallbackStub(void* context, IOReturn result, void* sender, IOHIDReportType type, uint32_t reportID, uint8_t* report, CFIndex reportLength){

//    auto deviceInfo = reinterpret_cast<DEVICE_INFO*>(context);
//    deviceInfo->provider->InputReportCallback_JC(deviceInfo, result, sender, type, reportID, report, reportLength);
    std::cout<<  "RegisterInputReportCallback" << "\n";
    auto deviceInfo = reinterpret_cast<DEVICE_INFO*>(context);
    deviceInfo->provider->InputReportCallback(deviceInfo, result, sender, type, reportID, report, reportLength);
}

void HID_IO::InputReportCallback(DEVICE_INFO* deviceInfo, IOReturn result, void* sender, IOHIDReportType type, uint32_t reportID, uint8_t* report, CFIndex reportLength)
{
    std::cout<<  report[1] << "\n";
}

