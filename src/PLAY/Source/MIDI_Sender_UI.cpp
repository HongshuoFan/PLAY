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

    juce__toggleButton_MIDI.reset (new juce::ToggleButton ("MIDI_activeButton"));
    addAndMakeVisible (juce__toggleButton_MIDI.get());
    juce__toggleButton_MIDI->setButtonText (TRANS ("MIDI"));
    juce__toggleButton_MIDI->addListener (this);

    juce__toggleButton_MIDI->setBounds (2, 5, 70, 30);

    juce__comboBox_outputDevicesList.reset (new juce::ComboBox ("MIDI_OuputList"));
    addAndMakeVisible (juce__comboBox_outputDevicesList.get());
    juce__comboBox_outputDevicesList->setEditableText (false);
    juce__comboBox_outputDevicesList->setJustificationType (juce::Justification::centredLeft);
    juce__comboBox_outputDevicesList->setTextWhenNothingSelected (TRANS ("No Devices"));
    juce__comboBox_outputDevicesList->setTextWhenNoChoicesAvailable (TRANS ("(No Devices)"));
    juce__comboBox_outputDevicesList->addListener (this);

    juce__textButton_update.reset (new juce::TextButton ("MIDI_update_button"));
    addAndMakeVisible (juce__textButton_update.get());
    juce__textButton_update->setButtonText (TRANS ("Update"));
    juce__textButton_update->addListener (this);

    juce__comboBox_MidiChannel.reset (new juce::ComboBox ("MidiChannel_ComboBox"));
    addAndMakeVisible (juce__comboBox_MidiChannel.get());
    juce__comboBox_MidiChannel->setEditableText (false);
    juce__comboBox_MidiChannel->setJustificationType (juce::Justification::centredLeft);
    juce__comboBox_MidiChannel->setTextWhenNothingSelected (TRANS ("0"));
    juce__comboBox_MidiChannel->setTextWhenNoChoicesAvailable (TRANS ("(no choices)"));
    juce__comboBox_MidiChannel->addItem (TRANS ("1"), 1);
    juce__comboBox_MidiChannel->addListener (this);


    //[UserPreSize]

    for (int i = 2; i <= 16; i++){
        juce__comboBox_MidiChannel->addItem (TRANS (std::to_string(i)), i);
    }
   
    juce__textButton_update->setVisible(false);
    juce__comboBox_outputDevicesList->setVisible(false);
    //virtual Midi device MAC only
    PlayMidiDevice = juce::MidiOutput::createNewDevice("PLAY");
    //[/UserPreSize]

    setSize (600, 40);


    //[Constructor] You can add your own custom stuff here..
    juce__comboBox_MidiChannel->setSelectedItemIndex(0);
    //[/Constructor]
}

MIDI_Sender_UI::~MIDI_Sender_UI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    juce__toggleButton_MIDI = nullptr;
    juce__comboBox_outputDevicesList = nullptr;
    juce__textButton_update = nullptr;
    juce__comboBox_MidiChannel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    closeConnection();
    //[/Destructor]
}

//==============================================================================
void MIDI_Sender_UI::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    {
        int x = proportionOfWidth (0.3800f), y = proportionOfHeight (0.2500f), width = 50, height = 20;
        juce::String text (TRANS ("Devices"));
        juce::Colour fillColour = juce::Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = proportionOfWidth (0.1167f), y = proportionOfHeight (0.2500f), width = 50, height = 20;
        juce::String text (TRANS ("Channel"));
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

    juce__comboBox_outputDevicesList->setBounds (proportionOfWidth (0.4700f), proportionOfHeight (0.2500f), 187, 24);
    juce__textButton_update->setBounds (490, 10, proportionOfWidth (0.1300f), proportionOfHeight (0.6000f));
    juce__comboBox_MidiChannel->setBounds (proportionOfWidth (0.2200f), proportionOfHeight (0.2500f), proportionOfWidth (0.1133f), proportionOfHeight (0.6000f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MIDI_Sender_UI::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == juce__toggleButton_MIDI.get())
    {
        //[UserButtonCode_juce__toggleButton_MIDI] -- add your button handler code here..
        //[/UserButtonCode_juce__toggleButton_MIDI]
    }
    else if (buttonThatWasClicked == juce__textButton_update.get())
    {
        //[UserButtonCode_juce__textButton_update] -- add your button handler code here..
        availableDevices = juce::MidiOutput::getAvailableDevices();
        juce__comboBox_outputDevicesList->clear();

        if(availableDevices.size() > 0)
        {
            int index = 1;
            for (auto& newDevice : availableDevices)
            {
                juce__comboBox_outputDevicesList->addItem(newDevice.name, index);
                index += 1;
            }
            juce__comboBox_outputDevicesList->setSelectedItemIndex(0);
        }else{
            juce__comboBox_outputDevicesList->setTextWhenNothingSelected(TRANS ("(No Device, Update the list)"));
        }
        //[/UserButtonCode_juce__textButton_update]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void MIDI_Sender_UI::comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == juce__comboBox_outputDevicesList.get())
    {
        //[UserComboBoxCode_juce__comboBox_outputDevicesList] -- add your combo box handling code here..
        int selectedIndex = juce__comboBox_outputDevicesList->getSelectedId() - 1;
        juce::MidiDeviceInfo selectedDevice = availableDevices[selectedIndex];
        //std::cout<<selectedIndex<<" "<< selectedDevice.name <<"  selected \n";

        closeConnection();

        outDevice = juce::MidiOutput::openDevice (selectedDevice.identifier);
        //handleNoteOn(1, 60, 1.f);
        if (outDevice.get() == nullptr)
        {
            DBG ("MidiSenderUI::openDevice: open output device for index = " << selectedIndex << " failed!");
        }
        //[/UserComboBoxCode_juce__comboBox_outputDevicesList]
    }
    else if (comboBoxThatHasChanged == juce__comboBox_MidiChannel.get())
    {
        //[UserComboBoxCode_juce__comboBox_MidiChannel] -- add your combo box handling code here..
        Selected_midiChannel = juce__comboBox_MidiChannel->getSelectedId();
        //[/UserComboBoxCode_juce__comboBox_MidiChannel]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void MIDI_Sender_UI::updateList()
{
    juce__textButton_update->triggerClick();
}

void MIDI_Sender_UI::closeConnection(){

    if (outDevice != nullptr){
        outDevice.reset();
        outDevice = nullptr;
    }
}

void MIDI_Sender_UI::sendToOutput(const juce::MidiMessage& msg)
{
    if(PlayMidiDevice != nullptr){
        PlayMidiDevice->sendMessageNow(msg);
    }
}

void MIDI_Sender_UI::handleNoteOn (int midiChannel, int midiNoteNumber, float velocity)
{
    juce::MidiMessage m (juce::MidiMessage::noteOn (midiChannel, midiNoteNumber, velocity));
    m.setTimeStamp (juce::Time::getMillisecondCounterHiRes() * 0.001);
    sendToOutput (m);
}

void MIDI_Sender_UI::handleNoteOff (int midiChannel, int midiNoteNumber, float velocity)
{
    juce::MidiMessage m (juce::MidiMessage::noteOff (midiChannel, midiNoteNumber, velocity));
    m.setTimeStamp (juce::Time::getMillisecondCounterHiRes() * 0.001);
    sendToOutput (m);
}

void MIDI_Sender_UI::handleContinuousController(int midiChannel, int midiControllerType, int value){
    juce::MidiMessage CC (juce::MidiMessage::controllerEvent(midiChannel, midiControllerType, value));
    CC.setTimeStamp (juce::Time::getMillisecondCounterHiRes() * 0.001);
    sendToOutput (CC);
}

void MIDI_Sender_UI::handleButton(int midiNoteNumber, bool buttonStat,bool& last_buttonStat_p)
{
    if(buttonStat != last_buttonStat_p)
    {
        if(buttonStat)
        {
            handleNoteOn(Selected_midiChannel, midiNoteNumber, 1.f);
        }else{
            handleNoteOff(Selected_midiChannel, midiNoteNumber, 0.f);
        }
        last_buttonStat_p = buttonStat;
    }
}

void MIDI_Sender_UI::handleTrigger(int midiControllerType, float triggerValue, float& last_triggerValue_p)
{
    int val = std::round(std::clamp(triggerValue, 0.f, 1.f) * 127.f);
    if(val != last_triggerValue_p)
    {
        handleContinuousController(Selected_midiChannel, midiControllerType, val);
        last_triggerValue_p = val;
    }
}

void MIDI_Sender_UI::send_Xbox_MIDI_message(XboxCotroller::XboxCotrollerInputState _xboxInput)
{
    if(juce__toggleButton_MIDI->getToggleState())
    {
        handleButton(60, _xboxInput.buttons.a, last_xboxInput.buttons.a);
        handleButton(61, _xboxInput.buttons.b, last_xboxInput.buttons.b);
        handleButton(62, _xboxInput.buttons.x, last_xboxInput.buttons.x);
        handleButton(63, _xboxInput.buttons.y, last_xboxInput.buttons.y);

        handleButton(64, _xboxInput.dpad.up, last_xboxInput.dpad.up);
        handleButton(65, _xboxInput.dpad.down, last_xboxInput.dpad.down);
        handleButton(66, _xboxInput.dpad.left, last_xboxInput.dpad.left);
        handleButton(67, _xboxInput.dpad.right, last_xboxInput.dpad.right);

        handleButton(68, _xboxInput.buttons.rb, last_xboxInput.buttons.rb);
        handleButton(69, _xboxInput.buttons.lb, last_xboxInput.buttons.lb);

        handleButton(70, _xboxInput.buttons.view, last_xboxInput.buttons.view);
        handleButton(71, _xboxInput.buttons.share, last_xboxInput.buttons.share);
        handleButton(72, _xboxInput.buttons.menu, last_xboxInput.buttons.menu);

        handleButton(73, _xboxInput.leftStick.stickPress, last_xboxInput.leftStick.stickPress);
        handleButton(74, _xboxInput.rightStick.stickPress, last_xboxInput.rightStick.stickPress);

        //Modulation Wheel
        handleTrigger(1, _xboxInput.leftTrigger, last_xboxInput.leftTrigger);
        //Breath Controller (MSB)
        handleTrigger(2, _xboxInput.rightTrigger, last_xboxInput.rightTrigger);
        //Volume (MSB)
        handleTrigger(7, _xboxInput.leftStick.x, last_xboxInput.leftStick.x);
        //Balance (MSB)
        handleTrigger(8, _xboxInput.leftStick.y, last_xboxInput.leftStick.y);
        //Pan (MSB)
        handleTrigger(10, _xboxInput.rightStick.x, last_xboxInput.rightStick.x);
        //Expression (MSB)
        handleTrigger(11, _xboxInput.rightStick.y, last_xboxInput.rightStick.y);

    }


}

void MIDI_Sender_UI::send_DualSense_OSC_message(DualSense::DualSenseInputState _dualSenseInput)
{
    if(juce__toggleButton_MIDI->getToggleState())
    {
        handleButton(60, _dualSenseInput.buttons.cross, last_dualSenseInput.buttons.cross);
        handleButton(61, _dualSenseInput.buttons.circle, last_dualSenseInput.buttons.circle);
        handleButton(62, _dualSenseInput.buttons.square, last_dualSenseInput.buttons.square);
        handleButton(63, _dualSenseInput.buttons.triangle, last_dualSenseInput.buttons.triangle);

        handleButton(64, _dualSenseInput.dpad.up, last_dualSenseInput.dpad.up);
        handleButton(65, _dualSenseInput.dpad.down, last_dualSenseInput.dpad.down);
        handleButton(66, _dualSenseInput.dpad.left, last_dualSenseInput.dpad.left);
        handleButton(67, _dualSenseInput.dpad.right, last_dualSenseInput.dpad.right);
        
        handleButton(68, _dualSenseInput.buttons.r1, last_dualSenseInput.buttons.r1);
        handleButton(69, _dualSenseInput.buttons.l1, last_dualSenseInput.buttons.l1);

        handleButton(70, _dualSenseInput.buttons.select, last_dualSenseInput.buttons.select);
        //handleButton(71, _dualSenseInput.buttons., last_xboxInput.buttons.share);
        handleButton(72, _dualSenseInput.buttons.menu, last_dualSenseInput.buttons.menu);

        handleButton(73, _dualSenseInput.leftStick.stickPress, last_dualSenseInput.leftStick.stickPress);
        handleButton(74, _dualSenseInput.rightStick.stickPress, last_dualSenseInput.rightStick.stickPress);
        
        //Modulation Wheel
        handleTrigger(1, _dualSenseInput.leftTrigger, last_dualSenseInput.leftTrigger);
        //Breath Controller (MSB)
        handleTrigger(2, _dualSenseInput.rightTrigger, last_dualSenseInput.rightTrigger);
        //Volume (MSB)
        handleTrigger(7, _dualSenseInput.leftStick.x, last_dualSenseInput.leftStick.x);
        //Balance (MSB)
        handleTrigger(8, _dualSenseInput.leftStick.y, last_dualSenseInput.leftStick.y);
        //Pan (MSB)
        handleTrigger(10, _dualSenseInput.rightStick.x, last_dualSenseInput.rightStick.x);
        //Expression (MSB)
        handleTrigger(11, _dualSenseInput.rightStick.y, last_dualSenseInput.rightStick.y);
    }
}
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
    <TEXT pos="38% 25% 50 20" fill="solid: fff0ffff" hasStroke="0" text="Devices"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="11.667% 25% 50 20" fill="solid: fff0ffff" hasStroke="0"
          text="Channel" fontname="Default font" fontsize="15.0" kerning="0.0"
          bold="0" italic="0" justification="36"/>
  </BACKGROUND>
  <TOGGLEBUTTON name="MIDI_activeButton" id="dc04b5e769d393aa" memberName="juce__toggleButton_MIDI"
                virtualName="" explicitFocusOrder="0" pos="2 5 70 30" buttonText="MIDI"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <COMBOBOX name="MIDI_OuputList" id="56bd8f7ca39cfc55" memberName="juce__comboBox_outputDevicesList"
            virtualName="" explicitFocusOrder="0" pos="47% 25% 187 24" editable="0"
            layout="33" items="" textWhenNonSelected="No Devices" textWhenNoItems="(No Devices)"/>
  <TEXTBUTTON name="MIDI_update_button" id="b8439ee890c80617" memberName="juce__textButton_update"
              virtualName="" explicitFocusOrder="0" pos="490 10 13% 60%" buttonText="Update"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <COMBOBOX name="MidiChannel_ComboBox" id="9aa8a3b1ee702033" memberName="juce__comboBox_MidiChannel"
            virtualName="" explicitFocusOrder="0" pos="22% 25% 11.333% 60%"
            editable="0" layout="33" items="1" textWhenNonSelected="0" textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

