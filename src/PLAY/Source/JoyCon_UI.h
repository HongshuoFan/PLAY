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
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class JoyCon_UI  : public juce::AnimatedAppComponent,
                   public juce::Button::Listener
{
public:
    //==============================================================================
    JoyCon_UI ();
    ~JoyCon_UI() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void update() override;
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    std::unique_ptr<StickGUI> Left_Stick;
    std::unique_ptr<StickGUI> Right_Stick;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::TextButton> juce__textButton_zl;
    std::unique_ptr<juce::TextButton> juce__textButton_l;
    std::unique_ptr<juce::TextButton> juce__textButton_;
    std::unique_ptr<juce::TextButton> juce__textButton_capture;
    std::unique_ptr<juce::TextButton> juce__textButton_UP;
    std::unique_ptr<juce::TextButton> juce__textButton_Left;
    std::unique_ptr<juce::TextButton> juce__textButton_right;
    std::unique_ptr<juce::TextButton> juce__textButton_down;
    std::unique_ptr<juce::TextButton> juce__textButton_sl;
    std::unique_ptr<juce::TextButton> juce__textButton_sr;
    std::unique_ptr<juce::TextButton> juce__textButton_zr;
    std::unique_ptr<juce::TextButton> juce__textButton_r;
    std::unique_ptr<juce::TextButton> juce__textButton_2;
    std::unique_ptr<juce::TextButton> juce__textButton_sr2;
    std::unique_ptr<juce::TextButton> juce__textButton_sl2;
    std::unique_ptr<juce::TextButton> juce__textButton_x;
    std::unique_ptr<juce::TextButton> juce__textButton_y;
    std::unique_ptr<juce::TextButton> juce__textButton_a;
    std::unique_ptr<juce::TextButton> juce__textButton_b;
    std::unique_ptr<juce::TextButton> juce__textButton_home;
    juce::Path internalPath1;
    juce::Path internalPath2;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JoyCon_UI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

