/*
  ==============================================================================

    HID_IO.h
    Created: 21 Oct 2023 3:03:58pm
    Author:  Hongshuo Fan
 
  ==============================================================================
*/

#pragma once


#include <IOKit/hid/IOHIDManager.h>
#include <IOKit/IOKitLib.h>
#include "InputProvider.h"
#include <iostream>
#include <functional>
#include <thread>
#include <chrono>
#include <vector>
#include <JuceHeader.h>
//==============================================================================
/*
 */


class HID_IO  : public juce::Component
{
public:

    using DataReceivedCallback = std::function<void(const std::vector<unsigned char>&)>;
    
    HID_IO();
    ~HID_IO() override;

    char *device_name;
 
    bool connect();
    void disconnect();
    bool isConneted;
    
    bool writeRawData(const uint8_t* data, CFIndex index, CFIndex Length);
//    bool readRawData(unsigned char* buffer, int bufferSize);
    
    void setDataReceivedCallback(DataReceivedCallback callback);
    
    void startReadingThread();
    void stopReadingThread();
    
    void printReport();
    
    uint8_t* reportData;
    uint8_t* OuputData;
    
    std::function<void()> dataReceivedCallback;
    
private:
    IOHIDManagerRef manager;
    IOHIDDeviceRef deviceRF;
    
    struct DEVICE_INFO
    {
        HID_IO* provider = nullptr;
        DeviceIdType deviceId;
        IOHIDDeviceRef device;
        //      *  bool first_run = true;
//        uint8_t prev_btn_state[50];
    };
    
    
    
    //DataReceivedCallback dataReceivedCallback;
    
    void creatConncet();
    
    CFMutableDictionaryRef CreateDeviceMatchingDictionary(uint32_t usagePage, uint32_t usage);
    
    static void OnDeviceMatchedStub(void* context, IOReturn result, void* sender, IOHIDDeviceRef device);
    void OnDeviceMatched(IOReturn result, void* sender, IOHIDDeviceRef device);
    
    IOHIDReportCallback GetCallback(IOHIDDeviceRef device);
    static void InputReportCallbackStub(void* context, IOReturn result, void* sender, IOHIDReportType type, uint32_t reportID, uint8_t* report, CFIndex reportLength);
    void InputReportCallback(DEVICE_INFO* deviceInfo, IOReturn result, void* sender, IOHIDReportType type, uint32_t reportID, uint8_t* report, CFIndex reportLength);
    
    std::list<DEVICE_INFO> m_devices;
    
    std::thread readingThread;
    bool stopThreadFlag;
   
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HID_IO)
};
