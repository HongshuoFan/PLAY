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
#include "XboxControllerState.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class XboxController_UI  : public juce::AnimatedAppComponent,
                           public juce::Button::Listener,
                           public juce::Slider::Listener
{
public:
    //==============================================================================
    XboxController_UI ();
    ~XboxController_UI() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void update() override;
    XboxCotroller::XboxCotrollerInputState _input;
    bool isConnected;
    std::function<void()> XboxVibration;
    uint8_t VibrationData[9];
    void setVibrationData();
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    StickGUI Left_Stick;
    StickGUI Right_Stick;
//    juce::Button::ButtonState onState = juce::Button::buttonDown;
//    juce::Button::ButtonState offState = juce::Button::buttonNormal;

    //std::thread UI_Thread;

    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::TextButton> juce__textButtonX;
    std::unique_ptr<juce::TextButton> juce__textButtonY;
    std::unique_ptr<juce::TextButton> juce__textButtonA;
    std::unique_ptr<juce::TextButton> juce__textButtonB;
    std::unique_ptr<juce::TextButton> juce__textButtonView;
    std::unique_ptr<juce::TextButton> juce__textButtonLeft;
    std::unique_ptr<juce::TextButton> juce__textButtonUp;
    std::unique_ptr<juce::TextButton> juce__textButtonDown;
    std::unique_ptr<juce::TextButton> juce__textButtonRight;
    std::unique_ptr<juce::TextButton> juce__textButtonShare;
    std::unique_ptr<juce::TextButton> juce__textButtonMenu;
    std::unique_ptr<juce::TextButton> juce__textButtonLB;
    std::unique_ptr<juce::TextButton> juce__textButtonRB;
    std::unique_ptr<juce::Slider> juce__slider_L_Trigger;
    std::unique_ptr<juce::Slider> juce__slider_R_Trigger;
    std::unique_ptr<juce::TextButton> juce__textButton_vibration;
    juce::Path internalPath1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (XboxController_UI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

