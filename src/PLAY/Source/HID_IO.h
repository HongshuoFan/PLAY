/*
  ==============================================================================

    HID_IO.h
    Created: 21 Oct 2023 3:03:58pm
    Author:  Hongshuo Fan
 
  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <IOKit/hid/IOHIDManager.h>
//#include <IOKit/hid/IOHIDKeys.h>
#include <iostream>
#include <functional>
#include <thread>
#include <chrono>
#include <vector>
#include "hidapi.h"
//==============================================================================
/*
 */
/// HID IO class, handles the HID IO raw data.
/// Note: 3 steps to include hidapi:
///1.add "hidapi" in the JUEC External Libraries to link.
///2.add hidapi.h path in the Header Search Paths.
///3.add hidapi lib file path in the Extra Library Search Paths.!

class HID_IO  : public juce::Component
{
public:

    using DataReceivedCallback = std::function<void(const std::vector<unsigned char>&)>;
    
    HID_IO();
    ~HID_IO() override;

 
    bool connect(IOHIDDeviceRef device);
    void disconnect();
    
    bool writeRawData(unsigned char* data, int size);
    bool readRawData(unsigned char* buffer, int bufferSize);
    
    void setDataReceivedCallback(DataReceivedCallback callback);
    
    void startReadingThread();
    void stopReadingThread();
    
    std::vector<unsigned char> getInputData() const; // Public function to retrieve inputData
    //std::function<void(const std::vector<unsigned char>&)> dataReceivedCallback;
    
private:
    IOHIDManagerRef manager;
    IOHIDDeviceRef device;
    
    std::vector<unsigned char> inputData; // Dynamic size for input data
    DataReceivedCallback dataReceivedCallback;
    
    void creatConncet();
    
    static int GetIntProperty(IOHIDDeviceRef device, CFStringRef key);
    CFMutableDictionaryRef CreateDeviceMatchingDictionary(uint32_t usagePage, uint32_t usage);
    
    static void OnDeviceMatchedStub(void* context, IOReturn result, void* sender, IOHIDDeviceRef device);
    void OnDeviceMatched(IOReturn result, void* sender, IOHIDDeviceRef device);
    
    IOHIDReportCallback GetCallback(IOHIDDeviceRef device);
    static void InputReportCallbackStub(void* context, IOReturn result, void* sender, IOHIDReportType type, uint32_t reportID, uint8_t* report, CFIndex reportLength);
    void InputReportCallback(IOReturn result, void* sender, IOHIDReportType type, uint32_t reportID, uint8_t* report, CFIndex reportLength);
    
    std::thread readingThread;
    bool stopThreadFlag;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HID_IO)
};
