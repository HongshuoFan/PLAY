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

bool HID_IO::connect(IOHIDDeviceRef newDevice) {
    
    if(device){
        disconnect();
        stopReadingThread();
    }
    
    if(newDevice){
        device = newDevice;
       
        return true;
    }
    
    return false;
}

void HID_IO::disconnect() {
    
    if (device) {
           IOHIDDeviceClose(device, kIOHIDOptionsTypeNone);
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
        IOHIDDeviceOpen(device, kIOHIDOptionsTypeNone);
        stopThreadFlag = false;
        readingThread = std::thread([this]() {
            while (!stopThreadFlag) {
                unsigned char buffer[64];
                if (readRawData(buffer, sizeof(buffer))) {
                    inputData.assign(buffer, buffer + sizeof(buffer));
                    if (dataReceivedCallback) {
                        dataReceivedCallback(inputData);
                    }
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Adjust the delay as needed
            }
        });
        disconnect();
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
    if (device) {
        CFIndex reportID = 0; // Set the appropriate report ID if necessary
        CFIndex reportLength = bufferSize;
        IOReturn result = IOHIDDeviceGetReport(device, kIOHIDReportTypeInput, reportID, buffer, &reportLength);
        return result == kIOReturnSuccess;
    }
    return false;
}

std::vector<unsigned char> HID_IO::getInputData() const {
    return inputData;
}
