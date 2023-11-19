/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.8

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
#include "StickGUI.h"
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
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;
    void update() override;
    // Binary resources:
    static const char* fab86afd63d645a9862f798e5e45cda2_jpg;
    static const int fab86afd63d645a9862f798e5e45cda2_jpgSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    StickGUI Left_Stick;
    StickGUI Right_Stick;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::TextButton> juce__textButtonX;
    std::unique_ptr<juce::TextButton> juce__textButtonY;
    std::unique_ptr<juce::TextButton> juce__textButtonA;
    std::unique_ptr<juce::TextButton> juce__textButtonB;
    std::unique_ptr<juce::TextButton> juce__textButtonView;
    std::unique_ptr<juce::TextButton> juce__textButtonL;
    std::unique_ptr<juce::TextButton> juce__textButtonUp;
    std::unique_ptr<juce::TextButton> juce__textButtonDown;
    std::unique_ptr<juce::TextButton> juce__textButtonRight;
    std::unique_ptr<juce::TextButton> juce__textButtonShare;
    std::unique_ptr<juce::TextButton> juce__textButtonMenu;
    std::unique_ptr<juce::TextButton> juce__textButtonLB;
    std::unique_ptr<juce::TextButton> juce__textButtonRB;
    std::unique_ptr<juce::Slider> juce__slider_L_Trigger;
    std::unique_ptr<juce::Slider> juce__slider_R_Trigger;
    juce::Path internalPath1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (XboxController_UI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

