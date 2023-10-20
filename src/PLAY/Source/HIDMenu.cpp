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

    HIDcombox__comboBox->setBounds (150, 4, 150, 24);

    Refresh__textButton.reset (new juce::TextButton ("Refresh button"));
    addAndMakeVisible (Refresh__textButton.get());
    Refresh__textButton->setButtonText (TRANS ("Refresh"));
    Refresh__textButton->setRadioGroupId (2);
    Refresh__textButton->addListener (this);
    Refresh__textButton->setColour (juce::TextButton::buttonColourId, juce::Colours::grey);
    Refresh__textButton->setColour (juce::TextButton::textColourOffId, juce::Colours::azure);

    Refresh__textButton->setBounds (310, 4, 50, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (400, 40);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

HIDMenu::~HIDMenu()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    HIDcombox__comboBox = nullptr;
    Refresh__textButton = nullptr;


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
        int x = 8, y = 0, width = 200, height = 30;
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
    //[/UserPaint]
}

void HIDMenu::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void HIDMenu::comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == HIDcombox__comboBox.get())
    {
        juce::String key = HIDcombox__comboBox->getText();
        std::cout << key << std::endl;
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void HIDMenu::buttonClicked (juce::Button* buttonThatWasClicked)
{
    
    // cilcked refresh the HID list

    if (buttonThatWasClicked == Refresh__textButton.get())
    {
        //get the HID list
        ListHID _listHid;
        _listHid.get_hid_list();
        
        devicesMap = _listHid.devicesMap;
        
        updateHIDcombox();
        
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void HIDMenu::updateHIDcombox() {
    
    // update the combox with new map
    
    //clear the combox
    HIDcombox__comboBox->clear();
    
    // Populate the ComboBox with keys
    int item_count = 1;
    
    for (const auto& entry : devicesMap) {
        juce::String key = entry.first;
        std::cout << key << std::endl;

        HIDcombox__comboBox->addItem(key, item_count);
        item_count += 1;
    }
    
}




//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="HIDMenu" componentName=""
                 parentClasses="public juce::Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="400" initialHeight="40">
  <BACKGROUND backgroundColour="ff323e44">
    <TEXT pos="8 0 200 30" fill="solid: fff0ffff" hasStroke="0" text="Available Controller"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="33"/>
  </BACKGROUND>
  <COMBOBOX name="HID combo box" id="aee71c7aac27d106" memberName="HIDcombox__comboBox"
            virtualName="" explicitFocusOrder="0" pos="150 4 150 24" editable="0"
            layout="36" items="" textWhenNonSelected="" textWhenNoItems="(No Device)"/>
  <TEXTBUTTON name="Refresh button" id="9e6aa27ce2a7870e" memberName="Refresh__textButton"
              virtualName="" explicitFocusOrder="0" pos="310 4 150 24" bgColOff="ff808080"
              textCol="fff0ffff" buttonText="Refresh" connectedEdges="0" needsCallback="1"
              radioGroupId="2"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

