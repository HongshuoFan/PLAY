#pragma once

#include <JuceHeader.h>
#include "HIDMenu.h"
#include "HID_IO.h"
/*
  ==============================================================================

    Created: 20 Oct 2023 2:12:27pm
    Author:  Hongshuo Fan

  ==============================================================================
*/
class MainComponent  : public juce::Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    
private:
    //==============================================================================
    // Your private member variables go here...
    // write a new funciton 
    HIDMenu m_HIDMenu;
    HID_IO hidIO;
    void onHIDMenuChanged();
    void onDataReceived(const std::vector<unsigned char>& data);
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
