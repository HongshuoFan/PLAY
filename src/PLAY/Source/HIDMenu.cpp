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
#if defined(__APPLE__) && defined(__MACH__)
//[Headers] You can add your own extra header files here...
//[/Headers]

#include "HIDMenu.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
HIDMenu::HIDMenu ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    HIDcombox__comboBox.reset (new juce::ComboBox ("HID combo box"));
    addAndMakeVisible (HIDcombox__comboBox.get());
    HIDcombox__comboBox->setEditableText (false);
    HIDcombox__comboBox->setJustificationType (juce::Justification::centred);
    HIDcombox__comboBox->setTextWhenNothingSelected (juce::String());
    HIDcombox__comboBox->setTextWhenNoChoicesAvailable (TRANS ("(No Device)"));
    HIDcombox__comboBox->addListener (this);

    Refresh__textButton.reset (new juce::TextButton ("Refresh button"));
    addAndMakeVisible (Refresh__textButton.get());
    Refresh__textButton->setButtonText (TRANS ("Refresh"));
    Refresh__textButton->setRadioGroupId (2);
    Refresh__textButton->addListener (this);
    Refresh__textButton->setColour (juce::TextButton::buttonColourId, juce::Colours::grey);
    Refresh__textButton->setColour (juce::TextButton::textColourOffId, juce::Colours::azure);

    juce__textButton_About.reset (new juce::TextButton ("About_button"));
    addAndMakeVisible (juce__textButton_About.get());
    juce__textButton_About->setButtonText (TRANS ("About"));
    juce__textButton_About->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (700, 40);


    //[Constructor] You can add your own custom stuff here..
    ClickRefresh__textButton();
    //[/Constructor]
}

HIDMenu::~HIDMenu()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    HIDcombox__comboBox = nullptr;
    Refresh__textButton = nullptr;
    juce__textButton_About = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void HIDMenu::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    {
        int x = proportionOfWidth (0.0114f), y = 0, width = 200, height = 30;
        juce::String text (TRANS ("Available Controller"));
        juce::Colour fillColour = juce::Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centredLeft, true);
    }

    //[UserPaint] Add your own custom painting code here..
    if(HIDDeviceChanged){
        HIDDeviceChanged = false;
    }
    //[/UserPaint]
}

void HIDMenu::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    HIDcombox__comboBox->setBounds (proportionOfWidth (0.2141f), 4, proportionOfWidth (0.2141f), 24);
    Refresh__textButton->setBounds (proportionOfWidth (0.4428f), 4, proportionOfWidth (0.1403f), 22);
    juce__textButton_About->setBounds (proportionOfWidth (0.9700f) - 61, 4, 61, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void HIDMenu::comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == HIDcombox__comboBox.get())
    {
        //[UserComboBoxCode_HIDcombox__comboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_HIDcombox__comboBox]
    }

    //[UsercomboBoxChanged_Post]
    if (comboBoxThatHasChanged == HIDcombox__comboBox.get())
    {
        selectedKey = HIDcombox__comboBox->getText();
        seletedDevice = devicesMap[selectedKey];
        HIDDeviceChanged = true;
        onHIDMenuChanged();
    }
    //[/UsercomboBoxChanged_Post]
}

void HIDMenu::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == Refresh__textButton.get())
    {
        //[UserButtonCode_Refresh__textButton] -- add your button handler code here..
        ListHID _listHid;
        _listHid.get_hid_list();

        devicesMap = _listHid.devicesMap;
        if(devicesMap.size()>0){
            updateHIDcombox();
        }
        else{
            HIDcombox__comboBox->setTextWhenNoChoicesAvailable (TRANS ("(No Device)"));
        }
        //[/UserButtonCode_Refresh__textButton]
    }
    else if (buttonThatWasClicked == juce__textButton_About.get())
    {
        //[UserButtonCode_juce__textButton_About] -- add your button handler code here..
        ShowAboutWindow();
        //[/UserButtonCode_juce__textButton_About]
    }

    //[UserbuttonClicked_Post]

    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void HIDMenu::updateHIDcombox()
{

    // update the combox with new map

    //clear the combox
    HIDcombox__comboBox->clear();

    // Populate the ComboBox with keys
    int item_count = 1;

    for (const auto& entry : devicesMap) {
        juce::String key = entry.first;
        //std::cout << key << std::endl;
        for(auto i : supportDevices){
            if (key == i){
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

auto HIDMenu::inVisableAbout(){
    return [ptr = Component::SafePointer (this), this] (int result)
    {
        aboutWindow->setVisible(false);
        if(result == 0){
            juce::URL("https://github.com/HongshuoFan/PLAY").launchInDefaultBrowser();
        }
    };
}

void HIDMenu::ShowAboutWindow()
{

    aboutWindow = std::make_unique<juce::AlertWindow> ("About","",juce::MessageBoxIconType::InfoIcon);
    //aboutWindow->addTextEditor ("text", "enter some text here", "text field:");
    //aboutWindow->addComboBox ("option", { "option 1", "option 2", "option 3", "option 4" }, "some options");

    aboutWindow->addTextBlock("Special thanks to The Oxford Research Centre in the Humanities, Jesus College Oxford, and the Royal Northern College of Music for their support and funding.");
    aboutWindow->addTextBlock("Lead developer: Hongshuo Fan");
    aboutWindow->addTextBlock("Please find more details on our GitHub Page!");

    aboutWindow->addButton ("OK",     1, juce::KeyPress (juce::KeyPress::returnKey, 0, 0));
    aboutWindow->addButton ("GitHub", 0, juce::KeyPress (juce::KeyPress::escapeKey, 0, 0));

    aboutWindow->enterModalState(true, juce::ModalCallbackFunction::create(inVisableAbout()));


}


//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="HIDMenu" componentName=""
                 parentClasses="public juce::Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="0" snapShown="0" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="700" initialHeight="40">
  <BACKGROUND backgroundColour="ff323e44">
    <TEXT pos="1.143% 0 200 30" fill="solid: fff0ffff" hasStroke="0" text="Available Controller"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="33"/>
  </BACKGROUND>
  <COMBOBOX name="HID combo box" id="aee71c7aac27d106" memberName="HIDcombox__comboBox"
            virtualName="" explicitFocusOrder="0" pos="21.414% 4 21.414% 24"
            editable="0" layout="36" items="" textWhenNonSelected="" textWhenNoItems="(No Device)"/>
  <TEXTBUTTON name="Refresh button" id="9e6aa27ce2a7870e" memberName="Refresh__textButton"
              virtualName="" explicitFocusOrder="0" pos="44.283% 4 14.033% 22"
              bgColOff="ff808080" textCol="fff0ffff" buttonText="Refresh" connectedEdges="0"
              needsCallback="1" radioGroupId="2"/>
  <TEXTBUTTON name="About_button" id="357b89fcf67d7ab2" memberName="juce__textButton_About"
              virtualName="" explicitFocusOrder="0" pos="96.985%r 4 61 24"
              buttonText="About" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

#endif // __APPLE__ && __MACH__