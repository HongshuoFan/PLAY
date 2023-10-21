/*
  ==============================================================================

    ListHID.h
    Created: 20 Oct 2023 2:12:27pm
    Author:  Hongshuo Fan

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <IOKit/IOKitLib.h>
#include <IOKit/hid/IOHIDManager.h>

//==============================================================================
/*
*/
class ListHID  : public juce::Component
{
public:
    ListHID();
    ~ListHID() override;

//    void paint (juce::Graphics&) override;
//    void resized() override;
    
    void get_hid_list();
    
    std::set<IOHIDDeviceRef> uniqueDevices;
    std::map<juce::String, IOHIDDeviceRef> devicesMap;
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ListHID)
};
