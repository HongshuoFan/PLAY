/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.12

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
#include "XboxControllerState.h"
#include "DualSenseState.h"
#include "JoyConState.h"
#include "AccessController_State.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class OSC_Sender_UI  : public juce::Component,
                       public juce::Button::Listener
{
public:
    //==============================================================================
    OSC_Sender_UI ();
    ~OSC_Sender_UI() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void send_Xbox_OSC_message(XboxCotroller::XboxCotrollerInputState _xboxInput, XboxCotroller::XboxCotroller_EnableStates _xboxEnableStates);
    void send_DualSense_OSC_message(DualSense::DualSenseInputState _dualSenseInput, DualSense::DualSenseEnableStates _dualSenseEnableStates);
    void send_AccessController_OSC_message(AccessController::AccessControllerInputStates _AccessControllerInput, AccessController::AccessControllerEnableStates _AccessControllerEnableStates);
    void send_L_JoyCon_OSC_message(JoyCon::L_JoyCon_InputState _l_JC_Input, JoyCon::JoyCon_EnableStates _l_JC_EnableState);
    void send_R_JoyCon_OSC_message(JoyCon::R_JoyCon_InputState _r_JC_Input, JoyCon::JoyCon_EnableStates _r_JC_EnableState);
    juce::OSCSender _oscSender;
    void disConnect();
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    bool isValidIPAddress(const juce::String new_ip);
    bool isValidPort(const juce::String new_port);
    juce::String ip = "127.0.0.1";
    int port = 9001;
    void ConvertAndSend_int(const int val, const int pre_val, const juce::String address, int& pre_val_p);
    void ConvertAndSend_float(const float val, const float pre_val, const juce::String address, float& pre_val_p, float filter);
    void ConvertAndSend_bool(const bool buttonState, const bool pre_buttonStat, const juce::String address, bool& pre_buttonStat_p);
    XboxCotroller::XboxCotrollerInputState last_xboxInput;
    DualSense::DualSenseInputState last_dualSenseInput;
    JoyCon::L_JoyCon_InputState last_l_JC_Input;
    JoyCon::R_JoyCon_InputState last_r_JC_Input;
    AccessController::AccessControllerInputStates last_AccessControllerInput;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::TextButton> juce__textButton_update;
    std::unique_ptr<juce::TextEditor> juce__textEditor_IP;
    std::unique_ptr<juce::TextEditor> juce__textEditor_port;
    std::unique_ptr<juce::ToggleButton> juce__toggleButton_OSC;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OSC_Sender_UI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

