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
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class StickGUI  : public juce::Component,
                  public juce::Button::Listener
{
public:
    //==============================================================================
    StickGUI ();
    ~StickGUI() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

    void updatePoint(float x, float y, bool button);
    bool enableX, enableY;
    void changeStates(bool new_states);
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //float Stickwidth = 52.0f, Stickheight = 52.0f;
    float previousMouseX = 0, previousMouseY = 0;
    float px = 0.f, py = 0.f;
    juce::Colour pointColour = juce::Colours::black;
    juce::Colour offColour = juce::Colours::grey;
    juce::Colour onColour = juce::Colours::red;
//    juce::Colour leftColour = juce::Colours::green;
//    juce::Colour rightColour = juce::Colour (0xffc83e67);
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::ToggleButton> juce__toggleButton_stick_x;
    std::unique_ptr<juce::ToggleButton> juce__toggleButton_stick_y;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StickGUI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

