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
#include "StickGUI.h"
#include "TouchPadGUI.h"
#include "DualSenseState.h"
#include "vec3GUI.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class DualSense_UI  : public juce::AnimatedAppComponent,
                      public juce::Button::Listener,
                      public juce::Slider::Listener
{
public:
    //==============================================================================
    DualSense_UI ();
    ~DualSense_UI() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void update() override;
    DualSense::DualSenseInputState DS_UI_input;
    DualSense::DualSenseEnableStates DS_EnableStats;

    bool isConnected;
    bool enableIMU;
    std::function<void()> UpdateVibration;
    bool virbration = false;
    std::function<void()> UpdateTriggerForce;
    std::function<void()> changeDevice;
    float triggerForce = 0.;
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    std::unique_ptr<StickGUI> Left_Stick;
    std::unique_ptr<StickGUI> Right_Stick;
    std::unique_ptr<TouchPadGUI> TouchPad;
    std::unique_ptr<vec3GUI> Acc;
    std::unique_ptr<vec3GUI> Gyo;
    //float clamp(float v, float min, float max);
    //TouchPadGUI touchPad;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::TextButton> juce__textButton_triangle;
    std::unique_ptr<juce::TextButton> juce__textButton_circle;
    std::unique_ptr<juce::TextButton> juce__textButton_square;
    std::unique_ptr<juce::TextButton> juce__textButton_cross;
    std::unique_ptr<juce::TextButton> juce__textButton_up;
    std::unique_ptr<juce::TextButton> juce__textButton_left;
    std::unique_ptr<juce::TextButton> juce__textButton_right;
    std::unique_ptr<juce::TextButton> juce__textButton_down;
    std::unique_ptr<juce::TextButton> juce__textButton_l1;
    std::unique_ptr<juce::TextButton> juce__textButton_r1;
    std::unique_ptr<juce::TextButton> juce__textButton_Select;
    std::unique_ptr<juce::TextButton> juce__textButton_menu;
    std::unique_ptr<juce::Slider> juce__slider_L_Trigger;
    std::unique_ptr<juce::Slider> juce__slider_R_Trigger;
    std::unique_ptr<juce::ToggleButton> juce__toggleButton_IMU;
    std::unique_ptr<juce::Slider> juce__slider_force_Trigger;
    std::unique_ptr<juce::TextButton> juce__textButton_UpdateTrigger;
    std::unique_ptr<juce::ToggleButton> juce__toggleButton_vibration;
    std::unique_ptr<juce::ToggleButton> juce__toggleButton_enableAll;
    std::unique_ptr<juce::TextButton> juce__textButton_ChangeDevice;
    juce::Path internalPath1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DualSense_UI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

