#pragma once

#include <JuceHeader.h>
#include "HIDMenu.h"
#include "HID_IO.h"
#include "OSC_Sender_UI.h"
#include "DualSense_Input.h"
//#include "DualSense_Output.h"
#include "XboxController_Input.h"
#include "XboxController_UI.h"

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
    void userTriedToCloseWindow() override;
    
private:
    //==============================================================================
    // Your private member variables go here...
    // write a new funciton 
    HIDMenu m_HIDMenu;
    
    HID_IO hidIO;
    uint8_t InputData;
    
    DualSense_Input DS_input;
    
    XboxController_Input XC_input;
//    DualSense_Output DS_output;
    XboxController_UI xbxUI;
    OSC_Sender_UI OSC_Sender;
    
    
    void onHIDMenuChanged();
    void onDataReceived();
    void onDualSense_DataReceived();
    void onXboxController_DataReceived();
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
