/*
  ==============================================================================

    HIDMenu_Win.h
    Created: 7 Jul 2025 1:01:23pm
    Author:  HS Fan

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <windows.h>
#include <map>
#include <functional>
#include "ListHID_Win.h"

//==============================================================================
// Windows version of HIDMenu, matching the cross-platform HIDMenu.h interface
class HIDMenu  : public juce::Component,
                 public juce::ComboBox::Listener,
                 public juce::Button::Listener
{
public:
    //==============================================================================
    HIDMenu();
    ~HIDMenu() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    bool HIDDeviceChanged = false;
    juce::String selectedKey;
    HANDLE selectedDevice = nullptr;
    std::map<juce::String, HANDLE> devicesMap;
    std::function<void()> onHIDMenuChanged;
    void ClickRefresh__textButton();
    juce::String supportDevices[5] = {
        "Xbox Wireless Controller", "DualSense Wireless Controller",
        "Joy-Con (L)", "Joy-Con (R)", "Access Controller"
    };
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

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HIDMenu)
};
