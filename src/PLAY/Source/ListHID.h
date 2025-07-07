/*
  ==============================================================================

    ListHID.h
    Created: 20 Oct 2023 2:12:27pm
    Author:  Hongshuo Fan

  ==============================================================================
*/

#pragma once

#if defined(__APPLE__) && defined(__MACH__)

#include <JuceHeader.h>
#include <IOKit/IOKitLib.h>
#include <IOKit/hid/IOHIDManager.h>

//==============================================================================
// macOS-only ListHID
class ListHID  : public juce::Component
{
public:
    ListHID();  
    ~ListHID() override;
    void get_hid_list();
    std::set<IOHIDDeviceRef> uniqueDevices;
    std::map<juce::String, IOHIDDeviceRef> devicesMap;
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ListHID)
};

#endif // __APPLE__ && __MACH__
