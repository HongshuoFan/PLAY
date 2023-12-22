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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "MIDI_Sender_UI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MIDI_Sender_UI::MIDI_Sender_UI ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    juce__toggleButton_OSC.reset (new juce::ToggleButton ("OSC_activeButton"));
    addAndMakeVisible (juce__toggleButton_OSC.get());
    juce__toggleButton_OSC->setButtonText (TRANS ("MIDI"));
    juce__toggleButton_OSC->addListener (this);

    juce__toggleButton_OSC->setBounds (2, 5, 70, 30);

    juce__comboBox.reset (new juce::ComboBox ("new combo box"));
    addAndMakeVisible (juce__comboBox.get());
    juce__comboBox->setEditableText (false);
    juce__comboBox->setJustificationType (juce::Justification::centredLeft);
    juce__comboBox->setTextWhenNothingSelected (juce::String());
    juce__comboBox->setTextWhenNoChoicesAvailable (TRANS ("(no choices)"));
    juce__comboBox->addListener (this);

    juce__textButton_update.reset (new juce::TextButton ("MIDI_update_button"));
    addAndMakeVisible (juce__textButton_update.get());
    juce__textButton_update->setButtonText (TRANS ("Update"));
    juce__textButton_update->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 40);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MIDI_Sender_UI::~MIDI_Sender_UI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    juce__toggleButton_OSC = nullptr;
    juce__comboBox = nullptr;
    juce__textButton_update = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MIDI_Sender_UI::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    {
        int x = 90, y = 10, width = 50, height = 20;
        juce::String text (TRANS ("Devices"));
        juce::Colour fillColour = juce::Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MIDI_Sender_UI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    juce__comboBox->setBounds (proportionOfWidth (0.2900f), proportionOfHeight (0.2250f), 283, 24);
    juce__textButton_update->setBounds (490, 10, proportionOfWidth (0.1300f), proportionOfHeight (0.6000f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MIDI_Sender_UI::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == juce__toggleButton_OSC.get())
    {
        //[UserButtonCode_juce__toggleButton_OSC] -- add your button handler code here..
        //[/UserButtonCode_juce__toggleButton_OSC]
    }
    else if (buttonThatWasClicked == juce__textButton_update.get())
    {
        //[UserButtonCode_juce__textButton_update] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_update]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void MIDI_Sender_UI::comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == juce__comboBox.get())
    {
        //[UserComboBoxCode_juce__comboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_juce__comboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MIDI_Sender_UI" componentName=""
                 parentClasses="public juce::Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="0" snapShown="0" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="600" initialHeight="40">
  <BACKGROUND backgroundColour="ff323e44">
    <TEXT pos="90 10 50 20" fill="solid: fff0ffff" hasStroke="0" text="Devices"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
  </BACKGROUND>
  <TOGGLEBUTTON name="OSC_activeButton" id="dc04b5e769d393aa" memberName="juce__toggleButton_OSC"
                virtualName="" explicitFocusOrder="0" pos="2 5 70 30" buttonText="MIDI"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <COMBOBOX name="new combo box" id="56bd8f7ca39cfc55" memberName="juce__comboBox"
            virtualName="" explicitFocusOrder="0" pos="29% 22.5% 283 24"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <TEXTBUTTON name="MIDI_update_button" id="b8439ee890c80617" memberName="juce__textButton_update"
              virtualName="" explicitFocusOrder="0" pos="490 10 13% 60%" buttonText="Update"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

