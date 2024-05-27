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
#include "DualSenseState.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TouchPadGUI  : public juce::Component,
                     public juce::Button::Listener
{
public:
    //==============================================================================
    TouchPadGUI ();
    ~TouchPadGUI() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void updateTouchPad_1(DualSense::Touch Point1);
    bool isP1Enable_x, isP1Enable_y;
    void updateTouchPad_2(DualSense::Touch Point2);
    bool isP2Enable_x, isP2Enable_y;
    bool pressTouchPad;
    void changeStates(bool new_state);
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    juce::Colour pointColour = juce::Colours::black;
    juce::Colour offColour = juce::Colours::grey;
    juce::Colour onColour = juce::Colours::red;

    DualSense::Touch touchPoint1;
    DualSense::Touch touchPoint2;
    float pointSize = 10.f;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::ToggleButton> juce__toggleButton_p1x;
    std::unique_ptr<juce::ToggleButton> juce__toggleButton_p1y;
    std::unique_ptr<juce::ToggleButton> juce__toggleButton_p2x;
    std::unique_ptr<juce::ToggleButton> juce__toggleButton_p2y;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TouchPadGUI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

