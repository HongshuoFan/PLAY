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
#include "StickGUI.h"
#include "JoyConState.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class JoyCon_UI  : public juce::AnimatedAppComponent,
                   public juce::Button::Listener,
                   public juce::Slider::Listener
{
public:
    //==============================================================================
    JoyCon_UI ();
    ~JoyCon_UI() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void update() override;
    JoyCon::L_JoyCon_InputState l_jc_input;
    JoyCon::R_JoyCon_InputState r_jc_input;
    bool isConnected = false;
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    std::unique_ptr<StickGUI> Left_Stick;
    std::unique_ptr<StickGUI> Right_Stick;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::TextButton> juce__textButton_zl;
    std::unique_ptr<juce::TextButton> juce__textButton_l;
    std::unique_ptr<juce::TextButton> juce__textButton_minus;
    std::unique_ptr<juce::TextButton> juce__textButton_capture;
    std::unique_ptr<juce::TextButton> juce__textButton_UP;
    std::unique_ptr<juce::TextButton> juce__textButton_Left;
    std::unique_ptr<juce::TextButton> juce__textButton_right;
    std::unique_ptr<juce::TextButton> juce__textButton_down;
    std::unique_ptr<juce::TextButton> juce__textButton_sl_l;
    std::unique_ptr<juce::TextButton> juce__textButton_sr_l;
    std::unique_ptr<juce::TextButton> juce__textButton_zr;
    std::unique_ptr<juce::TextButton> juce__textButton_r;
    std::unique_ptr<juce::TextButton> juce__textButton_plus;
    std::unique_ptr<juce::TextButton> juce__textButton_sr_r;
    std::unique_ptr<juce::TextButton> juce__textButton_sl_r;
    std::unique_ptr<juce::TextButton> juce__textButton_x;
    std::unique_ptr<juce::TextButton> juce__textButton_y;
    std::unique_ptr<juce::TextButton> juce__textButton_a;
    std::unique_ptr<juce::TextButton> juce__textButton_b;
    std::unique_ptr<juce::TextButton> juce__textButton_home;
    std::unique_ptr<juce::Label> juce__label_acc;
    std::unique_ptr<juce::Slider> juce__slider_l_acc_x;
    std::unique_ptr<juce::Slider> juce__slider_l_acc_y;
    std::unique_ptr<juce::Slider> juce__slider_l_acc_z;
    std::unique_ptr<juce::Label> juce__label_Gyroscope;
    std::unique_ptr<juce::Slider> juce__slider_l_gyr_x;
    std::unique_ptr<juce::Slider> juce__slider_l_gyr_y;
    std::unique_ptr<juce::Slider> juce__slider_l_gyr_z;
    std::unique_ptr<juce::Label> juce__label_acc2;
    std::unique_ptr<juce::Label> juce__label_Gyroscope2;
    std::unique_ptr<juce::Slider> juce__slider_r_acc_x;
    std::unique_ptr<juce::Slider> juce__slider_r_acc_y;
    std::unique_ptr<juce::Slider> juce__slider_r_acc_z;
    std::unique_ptr<juce::Slider> juce__slider_r_gyr_x;
    std::unique_ptr<juce::Slider> juce__slider_r_gyr_y;
    std::unique_ptr<juce::Slider> juce__slider_r_gyr_z;
    juce::Path internalPath1;
    juce::Path internalPath2;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JoyCon_UI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

