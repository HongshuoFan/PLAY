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
#include "StickGUI.h"
#include "AccessController_State.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class AccessController_UI  : public juce::AnimatedAppComponent,
                             public juce::Button::Listener
{
public:
    //==============================================================================
    AccessController_UI ();
    ~AccessController_UI() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    bool isConnected;
    AccessController::AccessControllerInputStates AC_input;
    AccessController::AccessControllerEnableStates AC_EnableStats;
    void update() override;
    std::function<void()> changeDevice;
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    std::unique_ptr<StickGUI> Stick_UI;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::TextButton> juce__textButton_1;
    std::unique_ptr<juce::TextButton> juce__textButton_2;
    std::unique_ptr<juce::TextButton> juce__textButton_3;
    std::unique_ptr<juce::TextButton> juce__textButton_5;
    std::unique_ptr<juce::TextButton> juce__textButton_4;
    std::unique_ptr<juce::TextButton> juce__textButton_7;
    std::unique_ptr<juce::TextButton> juce__textButton_8;
    std::unique_ptr<juce::TextButton> juce__textButton_6;
    std::unique_ptr<juce::TextButton> juce__textButton_0;
    std::unique_ptr<juce::TextButton> juce__textButton_profile;
    std::unique_ptr<juce::TextButton> juce__textButton_PS;
    std::unique_ptr<juce::TextButton> juce__textButton_ChangeDevice;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AccessController_UI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

