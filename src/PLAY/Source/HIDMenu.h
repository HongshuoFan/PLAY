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
#include "ListHID.h"

//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
 Created: 20 Oct 2023 2:12:27pm
 Author:  Hongshuo Fan
                                                                    //[/Comments]
*/
class HIDMenu  : public juce::Component,
                 public juce::ComboBox::Listener,
                 public juce::Button::Listener
{
public:
    //==============================================================================
    HIDMenu ();
    ~HIDMenu() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    bool HIDDeviceChanged;
    juce::String selectedKey;
    IOHIDDeviceRef seletedDevice;
    std::map<juce::String, IOHIDDeviceRef> devicesMap;
    std::function<void()> onHIDMenuChanged;
    void ClickRefresh__textButton();
    juce::String supportDevices[5] =
    {"Xbox Wireless Controller", "DualSense Wireless Controller", "Joy-Con (L)", "Joy-Con (R)", "Access Controller"};
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    void updateHIDcombox();
    void ShowAboutWindow();
    std::unique_ptr<juce::AlertWindow> aboutWindow;
    auto inVisableAbout();
    auto getAsyncAlertBoxResultChosen();

    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::ComboBox> HIDcombox__comboBox;
    std::unique_ptr<juce::TextButton> Refresh__textButton;
    std::unique_ptr<juce::TextButton> juce__textButton_About;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HIDMenu)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

