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
#include <IOKit/hid/IOHIDKeys.h>
#include <iostream>
#include <functional>
#include <thread>
#include <chrono>
#include <vector>
//==============================================================================
/*
 */
/// HID IO class, handles the HID IO raw data
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
//    IOHIDManagerRef manager;
    IOHIDDeviceRef device;
    std::vector<unsigned char> inputData; // Dynamic size for input data
    DataReceivedCallback dataReceivedCallback;
    
    std::thread readingThread;
    bool stopThreadFlag;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HID_IO)
};
