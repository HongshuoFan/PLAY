/*
  ==============================================================================

    HID_IO.h
    Created: 21 Oct 2023 3:03:58pm
    Author:  Hongshuo Fan
 
  ==============================================================================
*/

#pragma once


#include "InputProvider.h"
#include "HIDTypes.h"
#include <JuceHeader.h>
#include <chrono>
#include <cstddef>
#include <functional>
#include <memory>
#include <thread>
#include <vector>

//==============================================================================
/*
 */


class HID_IO  : public juce::Component
{
public:

    using DataReceivedCallback = std::function<void()>;

    HID_IO();
    ~HID_IO() override;

    char *device_name;

    bool connect();
    void disconnect();
    bool isConneted;

    bool writeRawData(const uint8_t* data, size_t reportId, size_t length);
//    bool readRawData(unsigned char* buffer, int bufferSize);

    void setDataReceivedCallback(DataReceivedCallback callback);

    void startReadingThread();
    void stopReadingThread();

    void printReport();

    uint8_t* reportData;
    uint8_t* OuputData;

    std::function<void()> dataReceivedCallback;

private:
    class HidBackend;
    class NullHidBackend;
#if JUCE_MAC
    class MacHidBackend;
#endif

    static std::unique_ptr<HidBackend> createBackend(HID_IO& owner);

    std::unique_ptr<HidBackend> backend;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HID_IO)
};
