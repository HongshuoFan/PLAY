/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.10

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
class vec3GUI  : public juce::Component,
                 public juce::Button::Listener
{
public:
    //==============================================================================
    vec3GUI ();
    ~vec3GUI() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    juce::String title = "Name";
    void updateSliders(float x, float y, float z);
    void setRange(double min, double max);
    float slider_min = -1.f;
    float slider_max = 1.f;
    bool is_x_enable = true;
    bool is_y_enable = true;
    bool is_z_enable = true;
    void changeStates(bool new_state);
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Slider> juce__slider_x;
    std::unique_ptr<juce::ToggleButton> juce__toggleButton_x;
    std::unique_ptr<juce::Slider> juce__slider_y;
    std::unique_ptr<juce::Slider> juce__slider_z;
    std::unique_ptr<juce::ToggleButton> juce__toggleButton_y;
    std::unique_ptr<juce::ToggleButton> juce__toggleButton_z;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (vec3GUI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

