/*
  ==============================================================================

    hidAPI_IO.h
    Created: 22 Oct 2023 1:18:47pm
    Author:  Hongshuo Fan

  ==============================================================================
*/

#pragma once

#include <thread>
#include <chrono>
#include <JuceHeader.h>
#include <IOKit/hid/IOHIDLib.h>
#include "hidapi.h"
//==============================================================================
/*
*/
class hidAPI_IO  : public juce::Component
{
public:
    hidAPI_IO();
    ~hidAPI_IO() override;
    
//    void getVendorAndProductID(IOHIDDeviceRef device);
    void creatConncet();
//    void paint (juce::Graphics&) override;
//    void resized() override;
    void startIOThread(IOHIDDeviceRef device);
private:
    //hid_device_info deviceInfo;
    IOHIDDeviceRef device;
    std::thread hidID_Thread;
    bool stopThreadFlag;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (hidAPI_IO)
};
