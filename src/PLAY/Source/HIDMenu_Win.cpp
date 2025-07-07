/*
  ==============================================================================

    HIDMenu_Win.cpp
    Created: 7 Jul 2025 1:01:23pm
    Author:  HS Fan

  ==============================================================================
*/

#include "HIDMenu_Win.h"

//==============================================================================

HIDMenu::HIDMenu()
{
    HIDcombox__comboBox.reset(new juce::ComboBox("HID combo box"));
    addAndMakeVisible(HIDcombox__comboBox.get());
    HIDcombox__comboBox->setEditableText(false);
    HIDcombox__comboBox->setJustificationType(juce::Justification::centred);
    HIDcombox__comboBox->setTextWhenNothingSelected(juce::String());
    HIDcombox__comboBox->setTextWhenNoChoicesAvailable(TRANS("(No Device)"));
    HIDcombox__comboBox->addListener(this);

    Refresh__textButton.reset(new juce::TextButton("Refresh button"));
    addAndMakeVisible(Refresh__textButton.get());
    Refresh__textButton->setButtonText(TRANS("Refresh"));
    Refresh__textButton->setRadioGroupId(2);
    Refresh__textButton->addListener(this);
    Refresh__textButton->setColour(juce::TextButton::buttonColourId, juce::Colours::grey);
    Refresh__textButton->setColour(juce::TextButton::textColourOffId, juce::Colours::azure);

    juce__textButton_About.reset(new juce::TextButton("About_button"));
    addAndMakeVisible(juce__textButton_About.get());
    juce__textButton_About->setButtonText(TRANS("About"));
    juce__textButton_About->addListener(this);

    setSize(700, 40);

    ClickRefresh__textButton();
}

HIDMenu::~HIDMenu()
{
    HIDcombox__comboBox = nullptr;
    Refresh__textButton = nullptr;
    juce__textButton_About = nullptr;
}

//==============================================================================

void HIDMenu::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colour(0xff323e44));

    int x = proportionOfWidth(0.0114f), y = 0, width = 200, height = 30;
    juce::String text(TRANS("Available Controller"));
    juce::Colour fillColour = juce::Colours::azure;
    g.setColour(fillColour);
    g.setFont(juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centredLeft, true);

    if (HIDDeviceChanged)
        HIDDeviceChanged = false;
}

void HIDMenu::resized()
{
    HIDcombox__comboBox->setBounds(proportionOfWidth(0.2141f), 4, proportionOfWidth(0.2141f), 24);
    Refresh__textButton->setBounds(proportionOfWidth(0.4428f), 4, proportionOfWidth(0.1403f), 22);
    juce__textButton_About->setBounds(proportionOfWidth(0.9700f) - 61, 4, 61, 24);
}

void HIDMenu::comboBoxChanged(juce::ComboBox* comboBoxThatHasChanged)
{
    if (comboBoxThatHasChanged == HIDcombox__comboBox.get())
    {
        selectedKey = HIDcombox__comboBox->getText();
        selectedDevice = devicesMap[selectedKey];
        HIDDeviceChanged = true;
        if (onHIDMenuChanged)
            onHIDMenuChanged();
    }
}

void HIDMenu::buttonClicked(juce::Button* buttonThatWasClicked)
{
    if (buttonThatWasClicked == Refresh__textButton.get())
    {
        ListHID _listHid;
        _listHid.get_hid_list();

        devicesMap = _listHid.devicesMap;
        if (devicesMap.size() > 0)
            updateHIDcombox();
        else
            HIDcombox__comboBox->setTextWhenNoChoicesAvailable(TRANS("(No Device)"));
    }
    else if (buttonThatWasClicked == juce__textButton_About.get())
    {
        ShowAboutWindow();
    }
}

void HIDMenu::updateHIDcombox()
{
    HIDcombox__comboBox->clear();
    int item_count = 1;
    for (const auto& entry : devicesMap)
    {
        juce::String key = entry.first;
        for (auto& i : supportDevices)
        {
            if (key == i)
            {
                HIDcombox__comboBox->addItem(key, item_count);
                item_count += 1;
            }
        }
    }
}

void HIDMenu::ClickRefresh__textButton()
{
    Refresh__textButton->triggerClick();
}

auto HIDMenu::inVisableAbout()
{
    return [ptr = Component::SafePointer(this), this](int result)
        {
            aboutWindow->setVisible(false);
            if (result == 0)
            {
                juce::URL("https://github.com/HongshuoFan/PLAY").launchInDefaultBrowser();
            }
        };
}

void HIDMenu::ShowAboutWindow()
{
    aboutWindow = std::make_unique<juce::AlertWindow>("About", "", juce::MessageBoxIconType::InfoIcon);
    aboutWindow->addTextBlock("Special thanks to The Oxford Research Centre in the Humanities, Jesus College Oxford, and the Royal Northern College of Music for their support and funding.");
    aboutWindow->addTextBlock("Lead developer: Hongshuo Fan");
    aboutWindow->addTextBlock("Please find more details on our GitHub Page!");
    aboutWindow->addButton("OK", 1, juce::KeyPress(juce::KeyPress::returnKey, 0, 0));
    aboutWindow->addButton("GitHub", 0, juce::KeyPress(juce::KeyPress::escapeKey, 0, 0));
    aboutWindow->enterModalState(true, juce::ModalCallbackFunction::create(inVisableAbout()));
}