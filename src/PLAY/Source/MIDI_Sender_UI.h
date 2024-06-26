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
class MIDI_Sender_UI  : public juce::Component,
                        public juce::Button::Listener,
                        public juce::ComboBox::Listener
{
public:
    //==============================================================================
    MIDI_Sender_UI ();
    ~MIDI_Sender_UI() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void send_Xbox_MIDI_message(XboxCotroller::XboxCotrollerInputState _xboxInput, XboxCotroller::XboxCotroller_EnableStates _xboxEnableStat);
    void send_DualSense_MIDI_message(DualSense::DualSenseInputState _dualSenseInput, DualSense::DualSenseEnableStates _dualSenseEnableStat);
    void send_L_JoyCon_MIDI_message(JoyCon::L_JoyCon_InputState _l_JCInput, JoyCon::JoyCon_EnableStates _l_JC_EnableStat);
    void send_R_JoyCon_MIDI_message(JoyCon::R_JoyCon_InputState _r_JCInput, JoyCon::JoyCon_EnableStates _r_JC_EnableStat);

    void send_AccessController_MIDI_message(AccessController::AccessControllerInputStates _AccessControllerInput, AccessController::AccessControllerEnableStates _AccessControllerEnableStates);

    int Selected_midiChannel = 1;
    void closeConnection();
    juce::String MidiDeviceName = "PLAY";
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //std::unique_ptr<juce::MidiOutput> outDevice;
    juce::Array<juce::MidiDeviceInfo> availableDevices;
    void sendToOutput(const juce::MidiMessage& msg);
    void handleNoteOn (int midiChannel, int midiNoteNumber, float velocity);
    void handleNoteOff (int midiChannel, int midiNoteNumber, float velocity);
    void handleContinuousController(int midiChannel, int midiControllerType, int value);
    std::unique_ptr<juce::MidiOutput>  PlayMidiDevice;

    void handleTrigger(int midiControllerType, float triggerValue, float& last_triggerValue_p);
    void handleButton(int midiNoteNumber, bool buttonStat, bool& last_buttonStat_p);

    XboxCotroller::XboxCotrollerInputState last_xboxInput;
    DualSense::DualSenseInputState last_dualSenseInput;
    JoyCon::L_JoyCon_InputState last_l_JCInput;
    JoyCon::R_JoyCon_InputState last_r_JCInput;
    AccessController::AccessControllerInputStates last_AccessControllerInput;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::ToggleButton> juce__toggleButton_MIDI;
    std::unique_ptr<juce::ComboBox> juce__comboBox_MidiChannel;
    std::unique_ptr<juce::TextEditor> juce__textEditor_MidiDeviceName;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MIDI_Sender_UI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

