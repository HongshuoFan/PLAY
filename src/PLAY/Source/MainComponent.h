#pragma once

#include <JuceHeader.h>
#include "HIDMenu.h"
#include "HID_IO.h"
#include "OSC_Sender_UI.h"
#include "OSC_Receiver.h"

#include "DualSense_Input.h"
#include "DualSense_Output.h"
#include "DualSense_UI.h"

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
    std::unique_ptr<HIDMenu> m_HIDMenu;
    //HIDMenu m_HIDMenu;
    
    std::unique_ptr<HID_IO> hidIO;
    //HID_IO hidIO;
    uint8_t InputData;
    
    std::unique_ptr<DualSense_Input> DS_input;
    std::unique_ptr<DualSense_Output> DS_output;
    //DualSense_Input DS_input;
    //DualSense_Output DS_output;
    DualSense_UI DS_UI;
    
    std::unique_ptr<XboxController_Input> XC_input;
    //XboxController_Input XC_input;
    //std::unique_ptr<XboxController_UI> xbxUI;
    XboxController_UI xbxUI;
    
    std::unique_ptr<OSC_Sender_UI> OSC_Sender;
    std::unique_ptr<OSC_Receiver> osc_receiver;
    //OSC_Sender_UI OSC_Sender;
    //OSC_Receiver osc_receiver;
    
    void onHIDMenuChanged();
    void onDataReceived();
    void onDualSense_DataReceived();
    void onXboxController_DataReceived();
    void EnableXboxControllerVibration();
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
