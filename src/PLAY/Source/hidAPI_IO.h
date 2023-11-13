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
/// HID IO class, handles the HID IO raw data.
/// Note: 3 steps to include hidapi:
///1.add "hidapi" in the JUEC External Libraries to link.
///2.add hidapi.h path in the Header Search Paths.
///3.add hidapi lib file path in the Extra Library Search Paths.!
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
