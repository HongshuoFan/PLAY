/*
  ==============================================================================

    ListHID.cpp
    Created: 20 Oct 2023 2:12:27pm
    Author:  Hongshuo Fan

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ListHID.h"
#include <cstdlib>

#if JUCE_MAC
# include <IOKit/IOKitLib.h>
# include <IOKit/hid/IOHIDManager.h>
#endif

//==============================================================================
ListHID::ListHID()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

ListHID::~ListHID()
{
}

//void ListHID::paint (juce::Graphics& g)
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
//    g.drawText ("ListHID", getLocalBounds(),
//                juce::Justification::centred, true);   // draw some placeholder text
//}
//
//void ListHID::resized()
//{
//    // This method is where you should set the bounds of any child
//    // components that your component contains..
//
//}

void ListHID::get_hid_list()
{
#if JUCE_MAC
    IOHIDManagerRef manager = IOHIDManagerCreate(kCFAllocatorDefault, kIOHIDOptionsTypeNone);
    if (manager){
        //clear map
        devicesMap.clear();
        //
        IOHIDManagerSetDeviceMatching(manager, NULL);
        IOHIDManagerOpen(manager, kIOHIDOptionsTypeNone);
        CFSetRef deviceSet = IOHIDManagerCopyDevices(manager);
        CFIndex deviceCount = CFSetGetCount(deviceSet);
        IOHIDDeviceRef *devices = (IOHIDDeviceRef *)malloc(sizeof(IOHIDDeviceRef) * deviceCount);
        CFSetGetValues(deviceSet, (const void **)devices);

        for (CFIndex i = 0; i < deviceCount; ++i) {
            IOHIDDeviceRef device = devices[i];

            CFStringRef productName = (CFStringRef)IOHIDDeviceGetProperty(device, CFSTR(kIOHIDProductKey));

            // Check if this device is unique
            HidDeviceHandle handle = static_cast<HidDeviceHandle>(device);
            if(productName && uniqueDevices.insert(handle).second){
                // This device is unique, process it
                char productNameCString[256];
                CFStringGetCString(productName, productNameCString, sizeof(productNameCString), kCFStringEncodingUTF8);

                juce::String keyString(productNameCString);

                devicesMap[keyString] = handle;
                //printf("Device Name: %s\n", productNameCString);

            }

        }
        free(devices);
        CFRelease(deviceSet);
        IOHIDManagerClose(manager, kIOHIDOptionsTypeNone);
        CFRelease(manager);
    }

    return ;
#else
    devicesMap.clear();
    uniqueDevices.clear();
#endif
}
