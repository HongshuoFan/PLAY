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
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    bool isValidIPAddress(juce::String new_ip);
    bool isValidPort(juce::String new_port);
    juce::String ip = "127.0.0.1";
    int port = 9001;
    juce::OSCSender _oscSender;
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

