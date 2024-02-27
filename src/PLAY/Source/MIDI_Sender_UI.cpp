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

    juce__comboBox_MidiChannel.reset (new juce::ComboBox ("MidiChannel_ComboBox"));
    addAndMakeVisible (juce__comboBox_MidiChannel.get());
    juce__comboBox_MidiChannel->setEditableText (false);
    juce__comboBox_MidiChannel->setJustificationType (juce::Justification::centredLeft);
    juce__comboBox_MidiChannel->setTextWhenNothingSelected (TRANS ("0"));
    juce__comboBox_MidiChannel->setTextWhenNoChoicesAvailable (TRANS ("(no choices)"));
    juce__comboBox_MidiChannel->addItem (TRANS ("1"), 1);
    juce__comboBox_MidiChannel->addListener (this);

    juce__comboBox_MidiChannel->setBounds (434, 11, 68, 24);

    juce__textEditor_MidiDeviceName.reset (new juce::TextEditor ("Midi_DeviceName"));
    addAndMakeVisible (juce__textEditor_MidiDeviceName.get());
    juce__textEditor_MidiDeviceName->setMultiLine (false);
    juce__textEditor_MidiDeviceName->setReturnKeyStartsNewLine (false);
    juce__textEditor_MidiDeviceName->setReadOnly (false);
    juce__textEditor_MidiDeviceName->setScrollbarsShown (true);
    juce__textEditor_MidiDeviceName->setCaretVisible (true);
    juce__textEditor_MidiDeviceName->setPopupMenuEnabled (true);
    juce__textEditor_MidiDeviceName->setText (TRANS ("PLAY"));

    juce__textEditor_MidiDeviceName->setBounds (167, 11, 150, 24);


    //[UserPreSize]

    for (int i = 2; i <= 16; i++){
        juce__comboBox_MidiChannel->addItem (TRANS (std::to_string(i)), i);
    }


    //virtual Midi device MAC only
    MidiDeviceName = juce__textEditor_MidiDeviceName->getText();
    PlayMidiDevice = juce::MidiOutput::createNewDevice(MidiDeviceName);
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
    juce__comboBox_MidiChannel = nullptr;
    juce__textEditor_MidiDeviceName = nullptr;


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
        int x = proportionOfWidth (0.6067f), y = proportionOfHeight (0.2000f), width = 58, height = 28;
        juce::String text (TRANS ("Channel"));
        juce::Colour fillColour = juce::Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = proportionOfWidth (0.1117f), y = proportionOfHeight (0.1750f), width = 102, height = 28;
        juce::String text (TRANS ("DeviceName"));
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
        if(juce__toggleButton_MIDI->getToggleState()){
            
            if(PlayMidiDevice){
                if(MidiDeviceName == juce__textEditor_MidiDeviceName->getText()){
                    std::cout<<"same name "<< PlayMidiDevice->getName()<<"\n";
                }else{
                    std::cout<<"new name \n";
                    closeConnection();
                    MidiDeviceName = juce__textEditor_MidiDeviceName->getText();
                    PlayMidiDevice = juce::MidiOutput::createNewDevice(MidiDeviceName);
                }
                
            }else{
                MidiDeviceName = juce__textEditor_MidiDeviceName->getText();
                PlayMidiDevice = juce::MidiOutput::createNewDevice(MidiDeviceName);
            }
           
        }else{
            //closeConnection();
        }
        //[/UserButtonCode_juce__toggleButton_MIDI]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void MIDI_Sender_UI::comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == juce__comboBox_MidiChannel.get())
    {
        //[UserComboBoxCode_juce__comboBox_MidiChannel] -- add your combo box handling code here..
        Selected_midiChannel = juce__comboBox_MidiChannel->getSelectedId();
        //[/UserComboBoxCode_juce__comboBox_MidiChannel]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void MIDI_Sender_UI::closeConnection(){

    if (PlayMidiDevice != nullptr){
        PlayMidiDevice->clearAllPendingMessages();
        PlayMidiDevice.reset();
        PlayMidiDevice = nullptr;
        juce__toggleButton_MIDI->setToggleState(false, juce::sendNotification);
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

void MIDI_Sender_UI::send_Xbox_MIDI_message(XboxCotroller::XboxCotrollerInputState _xboxInput, XboxCotroller::XboxCotroller_EnableStates _xboxEnableStat)
{
    if(juce__toggleButton_MIDI->getToggleState())
    {
        handleButton(36, _xboxInput.buttons.a, last_xboxInput.buttons.a);
        handleButton(37, _xboxInput.buttons.b, last_xboxInput.buttons.b);
        handleButton(38, _xboxInput.buttons.x, last_xboxInput.buttons.x);
        handleButton(39, _xboxInput.buttons.y, last_xboxInput.buttons.y);

        handleButton(40, _xboxInput.dpad.up, last_xboxInput.dpad.up);
        handleButton(41, _xboxInput.dpad.down, last_xboxInput.dpad.down);
        handleButton(42, _xboxInput.dpad.left, last_xboxInput.dpad.left);
        handleButton(43, _xboxInput.dpad.right, last_xboxInput.dpad.right);

        handleButton(44, _xboxInput.buttons.lb, last_xboxInput.buttons.lb);
        handleButton(45, _xboxInput.buttons.rb, last_xboxInput.buttons.rb);

        handleButton(46, _xboxInput.buttons.view, last_xboxInput.buttons.view);
        handleButton(47, _xboxInput.buttons.share, last_xboxInput.buttons.share);
        handleButton(48, _xboxInput.buttons.menu, last_xboxInput.buttons.menu);

        handleButton(49, _xboxInput.leftStick.stickPress, last_xboxInput.leftStick.stickPress);
        handleButton(50, _xboxInput.rightStick.stickPress, last_xboxInput.rightStick.stickPress);

        //Modulation Wheel
        
        handleTrigger(1, _xboxInput.leftTrigger, last_xboxInput.leftTrigger);
        //Breath Controller (MSB)
        handleTrigger(2, _xboxInput.rightTrigger, last_xboxInput.rightTrigger);
        if(_xboxEnableStat.leftStickStates.x){
            //Volume (MSB)
            handleTrigger(7, _xboxInput.leftStick.x, last_xboxInput.leftStick.x);
        }
        if(_xboxEnableStat.leftStickStates.y){
            //Balance (MSB)
            handleTrigger(8, _xboxInput.leftStick.y, last_xboxInput.leftStick.y);
        }
        if(_xboxEnableStat.rightStickStates.x){
            //Pan (MSB)
            handleTrigger(10, _xboxInput.rightStick.x, last_xboxInput.rightStick.x);
        }
        if(_xboxEnableStat.rightStickStates.y){
            //Expression (MSB)
            handleTrigger(11, _xboxInput.rightStick.y, last_xboxInput.rightStick.y);
        }

    }


}

void MIDI_Sender_UI::send_DualSense_MIDI_message(DualSense::DualSenseInputState _dualSenseInput, DualSense::DualSenseEnableStates _dualSenseEnableState)
{
    if(!juce__toggleButton_MIDI->getToggleState())
    {
        return;
    }
    handleButton(36, _dualSenseInput.buttons.cross, last_dualSenseInput.buttons.cross);
    handleButton(37, _dualSenseInput.buttons.circle, last_dualSenseInput.buttons.circle);
    handleButton(38, _dualSenseInput.buttons.square, last_dualSenseInput.buttons.square);
    handleButton(39, _dualSenseInput.buttons.triangle, last_dualSenseInput.buttons.triangle);

    handleButton(40, _dualSenseInput.dpad.up, last_dualSenseInput.dpad.up);
    handleButton(41, _dualSenseInput.dpad.down, last_dualSenseInput.dpad.down);
    handleButton(42, _dualSenseInput.dpad.left, last_dualSenseInput.dpad.left);
    handleButton(43, _dualSenseInput.dpad.right, last_dualSenseInput.dpad.right);

    handleButton(44, _dualSenseInput.buttons.l1, last_dualSenseInput.buttons.l1);
    handleButton(45, _dualSenseInput.buttons.r1, last_dualSenseInput.buttons.r1);

    handleButton(46, _dualSenseInput.buttons.select, last_dualSenseInput.buttons.select);
    handleButton(47, _dualSenseInput.buttons.menu, last_dualSenseInput.buttons.menu);

    handleButton(48, _dualSenseInput.leftStick.stickPress, last_dualSenseInput.leftStick.stickPress);
    handleButton(49, _dualSenseInput.rightStick.stickPress, last_dualSenseInput.rightStick.stickPress);

    handleButton(50, _dualSenseInput.buttons.touchPad, last_dualSenseInput.buttons.touchPad);

    //MIDI CC
    //Modulation Wheel
    handleTrigger(1, _dualSenseInput.leftTrigger, last_dualSenseInput.leftTrigger);
    //Breath Controller (MSB)
    handleTrigger(2, _dualSenseInput.rightTrigger, last_dualSenseInput.rightTrigger);
        
    if(_dualSenseEnableState.leftStickStates.x){
        //Volume (MSB)
        handleTrigger(7, _dualSenseInput.leftStick.x, last_dualSenseInput.leftStick.x);
    }
        
    if(_dualSenseEnableState.leftStickStates.y){
        //Balance (MSB)
        handleTrigger(8, _dualSenseInput.leftStick.y, last_dualSenseInput.leftStick.y);
    }
        
    if(_dualSenseEnableState.rightStickStates.x){
        //Pan (MSB)
        handleTrigger(10, _dualSenseInput.rightStick.x, last_dualSenseInput.rightStick.x);
    }
        
    if(_dualSenseEnableState.rightStickStates.y){
        //Expression (MSB)
        handleTrigger(11, _dualSenseInput.rightStick.y, last_dualSenseInput.rightStick.y);
    }
        
    if(_dualSenseEnableState.touchPoint1States.x){
        //Effect Controller 1 (MSB)
        handleTrigger(12, _dualSenseInput.touchPoint1.x, last_dualSenseInput.touchPoint1.x);
    }
        
    if(_dualSenseEnableState.touchPoint1States.y){
        //Effect Controller 2 (MSB)
        handleTrigger(13, _dualSenseInput.touchPoint1.y, last_dualSenseInput.touchPoint1.y);
    }
        
    if(_dualSenseEnableState.touchPoint2States.x){
        //Undefined (MSB)
        handleTrigger(14, _dualSenseInput.touchPoint2.x, last_dualSenseInput.touchPoint2.x);
    }
        
    if(_dualSenseEnableState.touchPoint2States.y){
        //Undefined (MSB)
        handleTrigger(15, _dualSenseInput.touchPoint2.y, last_dualSenseInput.touchPoint2.y);
    }
        
    if(_dualSenseEnableState.Gyo_states.x){
        //General Purpose (MSB) gyroscope
        handleTrigger(16, _dualSenseInput.gyroscope.x/2000 + 0.5, last_dualSenseInput.gyroscope.x);
    }
        
    if(_dualSenseEnableState.Gyo_states.y){
        handleTrigger(17, _dualSenseInput.gyroscope.y/2000 + 0.5, last_dualSenseInput.gyroscope.y);
    }
        
    if(_dualSenseEnableState.Gyo_states.z){
        handleTrigger(18, _dualSenseInput.gyroscope.z/2000 + 0.5, last_dualSenseInput.gyroscope.z);
    }
        
    if(_dualSenseEnableState.Acc_states.x){
        handleTrigger(19, _dualSenseInput.accelerometer.x * 0.5 + 0.5, last_dualSenseInput.accelerometer.x);
    }
        
    if(_dualSenseEnableState.Acc_states.y){
        handleTrigger(20, _dualSenseInput.accelerometer.y * 0.5 + 0.5, last_dualSenseInput.accelerometer.y);
    }
        
    if(_dualSenseEnableState.Acc_states.z){
        handleTrigger(21, _dualSenseInput.accelerometer.z * 0.5 + 0.5, last_dualSenseInput.accelerometer.z);
    }

    
}

void MIDI_Sender_UI::send_L_JoyCon_MIDI_message(JoyCon::L_JoyCon_InputState _l_JCInput, JoyCon::JoyCon_EnableStates _l_JC_EnableStat)
{
    if(!juce__toggleButton_MIDI->getToggleState()){
        return;
    }
    handleButton(40, _l_JCInput.dpad.up, last_l_JCInput.dpad.up);
    handleButton(41, _l_JCInput.dpad.down, last_l_JCInput.dpad.down);
    handleButton(42, _l_JCInput.dpad.left, last_l_JCInput.dpad.left);
    handleButton(43, _l_JCInput.dpad.right, last_l_JCInput.dpad.right);
    handleButton(44, _l_JCInput.buttons.l, last_l_JCInput.buttons.l);
    handleButton(46, _l_JCInput.buttons.zl, last_l_JCInput.buttons.zl);
    handleButton(48, _l_JCInput.buttons.minus, last_l_JCInput.buttons.minus);
    handleButton(50, _l_JCInput.stick.stickPress, last_l_JCInput.stick.stickPress);
    handleButton(52, _l_JCInput.buttons.sl, last_l_JCInput.buttons.sl);
    handleButton(54, _l_JCInput.buttons.sr, last_l_JCInput.buttons.sr);
    handleButton(56, _l_JCInput.buttons.capture, last_l_JCInput.buttons.capture);
    if(_l_JC_EnableStat.StickStates.x){
        //Volume (MSB)
        handleTrigger(7, _l_JCInput.stick.x, last_l_JCInput.stick.x);
    }
    
    if(_l_JC_EnableStat.StickStates.y){
        //Balance (MSB)
        handleTrigger(8, _l_JCInput.stick.y, last_l_JCInput.stick.y);
    }
    
    if(_l_JC_EnableStat.Acc_states.x){
        handleTrigger(9, _l_JCInput.accelerometer.x, last_l_JCInput.accelerometer.x);
    }
    if(_l_JC_EnableStat.Acc_states.y){
        handleTrigger(10, _l_JCInput.accelerometer.y, last_l_JCInput.accelerometer.y);
    }
    if(_l_JC_EnableStat.Acc_states.z){
        handleTrigger(11, _l_JCInput.accelerometer.z, last_l_JCInput.accelerometer.z);
    }
    if(_l_JC_EnableStat.Gyo_states.x){
        handleTrigger(12, _l_JCInput.gyroscope.x/2000. + 0.5, last_l_JCInput.gyroscope.x);
    }
    if(_l_JC_EnableStat.Gyo_states.y){
        handleTrigger(13, _l_JCInput.gyroscope.y/2000. + 0.5, last_l_JCInput.gyroscope.y);
    }
    if(_l_JC_EnableStat.Gyo_states.z){
        handleTrigger(14, _l_JCInput.gyroscope.z/2000. + 0.5, last_l_JCInput.gyroscope.z);
    }
    
}

void MIDI_Sender_UI::send_R_JoyCon_MIDI_message(JoyCon::R_JoyCon_InputState _r_JCInput, JoyCon::JoyCon_EnableStates _r_JC_EnableStat)
{
    if(!juce__toggleButton_MIDI->getToggleState()){
        return;
    }
    handleButton(36, _r_JCInput.buttons.b, last_r_JCInput.buttons.b);
    handleButton(37, _r_JCInput.buttons.a, last_r_JCInput.buttons.a);
    handleButton(38, _r_JCInput.buttons.y, last_r_JCInput.buttons.y);
    handleButton(39, _r_JCInput.buttons.x, last_r_JCInput.buttons.x);
    handleButton(45, _r_JCInput.buttons.r, last_r_JCInput.buttons.r);
    handleButton(47, _r_JCInput.buttons.zr, last_r_JCInput.buttons.zr);
    handleButton(49, _r_JCInput.buttons.plus, last_r_JCInput.buttons.plus);
    handleButton(51, _r_JCInput.stick.stickPress, last_r_JCInput.stick.stickPress);
    handleButton(53, _r_JCInput.buttons.sl, last_r_JCInput.buttons.sl);
    handleButton(55, _r_JCInput.buttons.sr, last_r_JCInput.buttons.sr);
    handleButton(57, _r_JCInput.buttons.home, last_r_JCInput.buttons.home);
    
    if(_r_JC_EnableStat.StickStates.x){
        //Pan (MSB)
        handleTrigger(15, _r_JCInput.stick.x, last_r_JCInput.stick.x);
    }

    if(_r_JC_EnableStat.StickStates.y){
        //Expression (MSB)
        handleTrigger(16, _r_JCInput.stick.y, last_r_JCInput.stick.y);
    }
    if(_r_JC_EnableStat.Acc_states.x){
        handleTrigger(17, _r_JCInput.accelerometer.x, last_r_JCInput.accelerometer.x);
    }
    if(_r_JC_EnableStat.Acc_states.y){
        handleTrigger(18, _r_JCInput.accelerometer.y, last_r_JCInput.accelerometer.y);
    }
    if(_r_JC_EnableStat.Acc_states.z){
        handleTrigger(19, _r_JCInput.accelerometer.z, last_r_JCInput.accelerometer.z);
    }
    if(_r_JC_EnableStat.Gyo_states.x){
        handleTrigger(20, _r_JCInput.gyroscope.x/2000. + 0.5, last_r_JCInput.gyroscope.x);
    }
    if(_r_JC_EnableStat.Gyo_states.y){
        handleTrigger(21, _r_JCInput.gyroscope.y/2000. + 0.5, last_r_JCInput.gyroscope.y);
    }
    if(_r_JC_EnableStat.Gyo_states.z){
        handleTrigger(22, _r_JCInput.gyroscope.z/2000. + 0.5, last_r_JCInput.gyroscope.z);
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
    <TEXT pos="60.667% 20% 58 28" fill="solid: fff0ffff" hasStroke="0"
          text="Channel" fontname="Default font" fontsize="15.0" kerning="0.0"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="11.167% 17.5% 102 28" fill="solid: fff0ffff" hasStroke="0"
          text="DeviceName" fontname="Default font" fontsize="15.0" kerning="0.0"
          bold="0" italic="0" justification="36"/>
  </BACKGROUND>
  <TOGGLEBUTTON name="MIDI_activeButton" id="dc04b5e769d393aa" memberName="juce__toggleButton_MIDI"
                virtualName="" explicitFocusOrder="0" pos="2 5 70 30" buttonText="MIDI"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <COMBOBOX name="MidiChannel_ComboBox" id="9aa8a3b1ee702033" memberName="juce__comboBox_MidiChannel"
            virtualName="" explicitFocusOrder="0" pos="434 11 68 24" editable="0"
            layout="33" items="1" textWhenNonSelected="0" textWhenNoItems="(no choices)"/>
  <TEXTEDITOR name="Midi_DeviceName" id="513699a69d967b42" memberName="juce__textEditor_MidiDeviceName"
              virtualName="" explicitFocusOrder="0" pos="167 11 150 24" initialText="PLAY"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

