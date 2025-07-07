/*
  ==============================================================================

    HID_IO_Win.h
    Created: 7 Jul 2025 12:56:14pm
    Author:  HS Fan

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "InputProvider.h"
#include <iostream>
#include <functional>
#include <thread>
#include <vector>
#include <windows.h>
#include <hidsdi.h>
#include <setupapi.h>
#pragma comment(lib, "hid.lib")
#pragma comment(lib, "setupapi.lib")

class HID_IO : public juce::Component
{
public:
    using DataReceivedCallback = std::function<void(const std::vector<unsigned char>&)>;

    HID_IO();
    ~HID_IO() override;

    // Device name for matching (optional, can be nullptr)
    char* device_name = nullptr;

    bool connect();
    void disconnect();
    bool isConneted = false;

    // Write raw data to the device
    bool writeRawData(const uint8_t* data, size_t reportId, size_t length);

    // Set callback for received data
    void setDataReceivedCallback(DataReceivedCallback callback);

    // Start/stop reading thread
    void startReadingThread();
    void stopReadingThread();

    // Print last report (for debugging)
    void printReport();

    // Last received report data
    std::vector<uint8_t> reportData;
    std::vector<uint8_t> outputData;

    // Callback for received data
    std::function<void()> dataReceivedCallback;

private:
    HANDLE deviceHandle = nullptr;
    std::thread readingThread;
    bool stopThreadFlag = false;

    // Helper: open the first matching HID device (optionally by name)
    HANDLE openFirstHIDDevice();

    // Helper: read loop
    void readLoop();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(HID_IO)
};
