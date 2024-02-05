#pragma once

#include <JuceHeader.h>
#include "HIDMenu.h"
#include "HID_IO.h"
#include "OSC_Sender_UI.h"
#include "OSC_Receiver.h"

#include "MIDI_Sender_UI.h"

#include "DualSense_Input.h"
#include "DualSense_Output.h"
#include "DualSense_UI.h"

#include "XboxController_Input.h"
#include "XboxController_UI.h"

#include "JoyCon_Input.h"
#include "JoyCon_Output.h"
#include "JoyCon_UI.h"

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
    // HID manager and relative stuffs.
    std::unique_ptr<HIDMenu> m_HIDMenu;
    std::unique_ptr<HID_IO> hidIO_1;
    std::unique_ptr<HID_IO> hidIO_2;
    uint8_t InputData;

    // DualSense stuffs.
    std::unique_ptr<DualSense_Input> DS_input;
    std::unique_ptr<DualSense_Output> DS_output;
    DualSense_UI DS_UI;
    void update_DualSense_TriggerForce();
    void update_DualSense_Vibration();
    
    // Xbox Controller stuffs.
    std::unique_ptr<XboxController_Input> XC_input;
    XboxController_UI xbxUI;

    // JoyCon stuffs.
    std::unique_ptr<JoyCon_Input> JC_input;
    std::unique_ptr<JoyCon_Output> JC_output;
    JoyCon_UI JC_UI;
    juce::String L_JoyConName = "Joy-Con (L)";
    juce::String R_JoyConName = "Joy-Con (R)";
    
    // OSC stuffs.
    std::unique_ptr<OSC_Sender_UI> osc_sender;
    std::unique_ptr<OSC_Receiver> osc_receiver;
    
    // MIDI stuffs.
    std::unique_ptr<MIDI_Sender_UI> midi_sender;
    
    void onHIDMenuChanged();
    void onDataReceived();
    
    void onDualSense_DataReceived();
    
    
    void onXboxController_DataReceived();
    void EnableXboxControllerVibration();
    
    void onJoyCon_L_DataReceived();
    void onJoyCon_R_DataReceived();
    
    void Left_JC_IMU();
    void Left_JC_Vib();
    void Right_JC_IMU();
    void Right_JC_Vib();
    
    void WarningWindow(juce::String WarningMessage);
    void initialConnection(juce::String nameOfDevice);
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
