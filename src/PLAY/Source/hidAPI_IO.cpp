/*
  ==============================================================================

    hidAPI_IO.cpp
    Created: 22 Oct 2023 1:18:47pm
    Author:  Hongshuo Fan

  ==============================================================================
*/

#include <JuceHeader.h>
#include "hidAPI_IO.h"

//==============================================================================
hidAPI_IO::hidAPI_IO()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

hidAPI_IO::~hidAPI_IO()
{
}

//void hidAPI_IO::paint (juce::Graphics& g)
//{
//    /* This demo code just fills the component's background and
//       draws some placeholder text to get you started.
//
//       You should replace everything in this method with your own
//       drawing code..
//    */
//
//    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background
//
//    g.setColour (juce::Colours::grey);
//    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component
//
//    g.setColour (juce::Colours::white);
//    g.setFont (14.0f);
//    g.drawText ("hidAPI_IO", getLocalBounds(),
//                juce::Justification::centred, true);   // draw some placeholder text
//}
//
//void hidAPI_IO::resized()
//{
//    // This method is where you should set the bounds of any child
//    // components that your component contains..
//
//}

void hidAPI_IO::startIOThread(IOHIDDeviceRef device) {
    if (!hidID_Thread.joinable()) {
        
        stopThreadFlag = false;
        hidID_Thread = std::thread([this]() {
            creatConncet();
        });
    }
}

void hidAPI_IO::creatConncet()
{
    SInt32 vendorIDValue, productIDValue;
    CFNumberRef vendorID = (CFNumberRef)IOHIDDeviceGetProperty(device, CFSTR(kIOHIDVendorIDKey));
    CFNumberRef productID = (CFNumberRef)IOHIDDeviceGetProperty(device, CFSTR(kIOHIDProductIDKey));
    // Check if the properties were retrieved successfully
    if (vendorID && productID) {
        
        // Get the integer values from the CFNumberRefs
        CFNumberGetValue(vendorID, kCFNumberSInt32Type, &vendorIDValue);
        CFNumberGetValue(productID, kCFNumberSInt32Type, &productIDValue);
        // Use vendorIDValue and productIDValue as needed
        printf("Vendor ID: %d, Product ID: %d\n", vendorIDValue, productIDValue);
    } else {
        
        printf("Failed to retrieve Vendor ID and Product ID\n");
    }
    
}
