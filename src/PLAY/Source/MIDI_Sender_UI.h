/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.9

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
#include "XboxControllerState.h"
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
    void send_Xbox_MIDI_message(XboxCotroller::XboxCotrollerInputState _xboxInput);
    int Selected_midiChannel = 1;
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    std::unique_ptr<juce::MidiOutput> outDevice;
    juce::Array<juce::MidiDeviceInfo> availableDevices;
    void sendToOutput(const juce::MidiMessage& msg);
    void handleNoteOn (int midiChannel, int midiNoteNumber, float velocity);
    void handleNoteOff (int midiChannel, int midiNoteNumber, float velocity);
    void handleContinuousController(int midiChannel, int midiControllerType, int value);
    
    
    void handleTrigger(int midiControllerType, float triggerValue, float& last_triggerValue_p);
    void handleButton(int midiNoteNumber, bool buttonStat, bool& last_buttonStat_p);
    
    XboxCotroller::XboxCotrollerInputState last_xboxInput;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::ToggleButton> juce__toggleButton_MIDI;
    std::unique_ptr<juce::ComboBox> juce__comboBox_outputDevicesList;
    std::unique_ptr<juce::TextButton> juce__textButton_update;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MIDI_Sender_UI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

