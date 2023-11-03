#pragma once

#include <JuceHeader.h>
#include "HIDMenu.h"
#include "HID_IO.h"
#include "DualSense_Input.h"

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
    DualSense_Input DS_input;
    
    void onHIDMenuChanged();
    void onDataReceived();
    void onDualSense_DataReceived();
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
