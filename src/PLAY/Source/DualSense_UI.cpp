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

#include "DualSense_UI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
DualSense_UI::DualSense_UI ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    Left_Stick.setBounds(185, 130, 80, 80);
    Left_Stick.resized();
    addAndMakeVisible(Left_Stick);

    Right_Stick.setBounds(333, 130, 80, 80);
    Right_Stick.resized();
    addAndMakeVisible(Right_Stick);

    touchPad.setBounds(224, 25, 160, 100);
    touchPad.resized();
    addAndMakeVisible(touchPad);
    //[/Constructor_pre]

    juce__textButton_triangle.reset (new juce::TextButton ("triangle_button"));
    addAndMakeVisible (juce__textButton_triangle.get());
    juce__textButton_triangle->setButtonText (TRANS ("Triangle"));
    juce__textButton_triangle->addListener (this);
    juce__textButton_triangle->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_circle.reset (new juce::TextButton ("circle_button"));
    addAndMakeVisible (juce__textButton_circle.get());
    juce__textButton_circle->setButtonText (TRANS ("Circle"));
    juce__textButton_circle->addListener (this);
    juce__textButton_circle->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_square.reset (new juce::TextButton ("square_button"));
    addAndMakeVisible (juce__textButton_square.get());
    juce__textButton_square->setButtonText (TRANS ("Square"));
    juce__textButton_square->addListener (this);
    juce__textButton_square->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_cross.reset (new juce::TextButton ("cross_button"));
    addAndMakeVisible (juce__textButton_cross.get());
    juce__textButton_cross->setButtonText (TRANS ("Cross"));
    juce__textButton_cross->addListener (this);
    juce__textButton_cross->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_up.reset (new juce::TextButton ("up_button"));
    addAndMakeVisible (juce__textButton_up.get());
    juce__textButton_up->setButtonText (TRANS ("U"));
    juce__textButton_up->addListener (this);
    juce__textButton_up->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_left.reset (new juce::TextButton ("left_button"));
    addAndMakeVisible (juce__textButton_left.get());
    juce__textButton_left->setButtonText (TRANS ("L"));
    juce__textButton_left->addListener (this);
    juce__textButton_left->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_right.reset (new juce::TextButton ("right_button"));
    addAndMakeVisible (juce__textButton_right.get());
    juce__textButton_right->setButtonText (TRANS ("R"));
    juce__textButton_right->addListener (this);
    juce__textButton_right->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_down.reset (new juce::TextButton ("down_button"));
    addAndMakeVisible (juce__textButton_down.get());
    juce__textButton_down->setButtonText (TRANS ("D"));
    juce__textButton_down->addListener (this);
    juce__textButton_down->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_l1.reset (new juce::TextButton ("l1_button"));
    addAndMakeVisible (juce__textButton_l1.get());
    juce__textButton_l1->setButtonText (TRANS ("l1"));
    juce__textButton_l1->addListener (this);
    juce__textButton_l1->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_r1.reset (new juce::TextButton ("r1_button"));
    addAndMakeVisible (juce__textButton_r1.get());
    juce__textButton_r1->setButtonText (TRANS ("r1"));
    juce__textButton_r1->addListener (this);
    juce__textButton_r1->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_Select.reset (new juce::TextButton ("Select_button"));
    addAndMakeVisible (juce__textButton_Select.get());
    juce__textButton_Select->setButtonText (TRANS ("Select"));
    juce__textButton_Select->addListener (this);
    juce__textButton_Select->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_menu.reset (new juce::TextButton ("menu_button"));
    addAndMakeVisible (juce__textButton_menu.get());
    juce__textButton_menu->setButtonText (TRANS ("Menu"));
    juce__textButton_menu->addListener (this);
    juce__textButton_menu->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__slider_L_Trigger.reset (new juce::Slider ("L_Trigger"));
    addAndMakeVisible (juce__slider_L_Trigger.get());
    juce__slider_L_Trigger->setRange (0, 1, 0);
    juce__slider_L_Trigger->setSliderStyle (juce::Slider::LinearVertical);
    juce__slider_L_Trigger->setTextBoxStyle (juce::Slider::TextBoxBelow, true, 60, 20);
    juce__slider_L_Trigger->addListener (this);

    juce__slider_R_Trigger.reset (new juce::Slider ("R_Trigger"));
    addAndMakeVisible (juce__slider_R_Trigger.get());
    juce__slider_R_Trigger->setRange (0, 1, 0);
    juce__slider_R_Trigger->setSliderStyle (juce::Slider::LinearVertical);
    juce__slider_R_Trigger->setTextBoxStyle (juce::Slider::TextBoxBelow, true, 60, 20);
    juce__slider_R_Trigger->addListener (this);

    internalPath1.startNewSubPath (300.0f, 216.0f);
    internalPath1.lineTo (384.0f, 216.0f);
    internalPath1.quadraticTo (406.0f, 213.0f, 432.0f, 240.0f);
    internalPath1.lineTo (472.0f, 328.0f);
    internalPath1.quadraticTo (504.0f, 328.0f, 528.0f, 304.0f);
    internalPath1.lineTo (536.0f, 248.0f);
    internalPath1.quadraticTo (544.0f, 168.0f, 488.0f, 40.0f);
    internalPath1.lineTo (408.0f, 24.0f);
    internalPath1.quadraticTo (304.0f, 16.0f, 192.0f, 24.0f);
    internalPath1.lineTo (112.0f, 40.0f);
    internalPath1.quadraticTo (64.0f, 152.0f, 64.0f, 224.0f);
    internalPath1.lineTo (64.0f, 272.0f);
    internalPath1.lineTo (72.0f, 304.0f);
    internalPath1.quadraticTo (88.0f, 328.0f, 128.0f, 328.0f);
    internalPath1.quadraticTo (152.0f, 272.0f, 176.0f, 224.0f);
    internalPath1.quadraticTo (197.0f, 214.0f, 216.0f, 216.0f);
    internalPath1.closeSubPath();


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 340);


    //[Constructor] You can add your own custom stuff here..
    setFramesPerSecond (1);
    isConnected = false;
    //[/Constructor]
}

DualSense_UI::~DualSense_UI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    juce__textButton_triangle = nullptr;
    juce__textButton_circle = nullptr;
    juce__textButton_square = nullptr;
    juce__textButton_cross = nullptr;
    juce__textButton_up = nullptr;
    juce__textButton_left = nullptr;
    juce__textButton_right = nullptr;
    juce__textButton_down = nullptr;
    juce__textButton_l1 = nullptr;
    juce__textButton_r1 = nullptr;
    juce__textButton_Select = nullptr;
    juce__textButton_menu = nullptr;
    juce__slider_L_Trigger = nullptr;
    juce__slider_R_Trigger = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void DualSense_UI::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    {
        float x = 0, y = 0;
        juce::Colour strokeColour = juce::Colours::cornflowerblue;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.strokePath (internalPath1, juce::PathStrokeType (3.000f), juce::AffineTransform::translation (x, y));
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void DualSense_UI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    juce__textButton_triangle->setBounds (proportionOfWidth (0.7133f), proportionOfHeight (0.1853f), proportionOfWidth (0.0600f), proportionOfHeight (0.0500f));
    juce__textButton_circle->setBounds (proportionOfWidth (0.7700f), proportionOfHeight (0.2823f), proportionOfWidth (0.0600f), proportionOfHeight (0.0500f));
    juce__textButton_square->setBounds (proportionOfWidth (0.6550f), proportionOfHeight (0.2823f), proportionOfWidth (0.0600f), proportionOfHeight (0.0500f));
    juce__textButton_cross->setBounds (proportionOfWidth (0.7133f), proportionOfHeight (0.3794f), proportionOfWidth (0.0600f), proportionOfHeight (0.0529f));
    juce__textButton_up->setBounds (proportionOfWidth (0.2383f), proportionOfHeight (0.2118f), proportionOfWidth (0.0417f), proportionOfHeight (0.0441f));
    juce__textButton_left->setBounds (proportionOfWidth (0.1967f), proportionOfHeight (0.2823f), proportionOfWidth (0.0417f), proportionOfHeight (0.0441f));
    juce__textButton_right->setBounds (proportionOfWidth (0.2767f), proportionOfHeight (0.2823f), proportionOfWidth (0.0417f), proportionOfHeight (0.0441f));
    juce__textButton_down->setBounds (proportionOfWidth (0.2383f), proportionOfHeight (0.3559f), proportionOfWidth (0.0417f), proportionOfHeight (0.0441f));
    juce__textButton_l1->setBounds (proportionOfWidth (0.2200f), proportionOfHeight (0.0265f), proportionOfWidth (0.0600f), proportionOfHeight (0.0500f));
    juce__textButton_r1->setBounds (proportionOfWidth (0.7200f), proportionOfHeight (0.0265f), proportionOfWidth (0.0600f), proportionOfHeight (0.0500f));
    juce__textButton_Select->setBounds (proportionOfWidth (0.2950f), proportionOfHeight (0.1382f), proportionOfWidth (0.0417f), proportionOfHeight (0.0323f));
    juce__textButton_menu->setBounds (proportionOfWidth (0.6617f), proportionOfHeight (0.1441f), proportionOfWidth (0.0417f), proportionOfHeight (0.0323f));
    juce__slider_L_Trigger->setBounds (proportionOfWidth (0.0100f), proportionOfHeight (0.0294f), proportionOfWidth (0.0750f), proportionOfHeight (0.5000f));
    juce__slider_R_Trigger->setBounds (proportionOfWidth (0.9100f), proportionOfHeight (0.0294f), proportionOfWidth (0.0750f), proportionOfHeight (0.5000f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void DualSense_UI::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == juce__textButton_triangle.get())
    {
        //[UserButtonCode_juce__textButton_triangle] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_triangle]
    }
    else if (buttonThatWasClicked == juce__textButton_circle.get())
    {
        //[UserButtonCode_juce__textButton_circle] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_circle]
    }
    else if (buttonThatWasClicked == juce__textButton_square.get())
    {
        //[UserButtonCode_juce__textButton_square] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_square]
    }
    else if (buttonThatWasClicked == juce__textButton_cross.get())
    {
        //[UserButtonCode_juce__textButton_cross] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_cross]
    }
    else if (buttonThatWasClicked == juce__textButton_up.get())
    {
        //[UserButtonCode_juce__textButton_up] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_up]
    }
    else if (buttonThatWasClicked == juce__textButton_left.get())
    {
        //[UserButtonCode_juce__textButton_left] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_left]
    }
    else if (buttonThatWasClicked == juce__textButton_right.get())
    {
        //[UserButtonCode_juce__textButton_right] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_right]
    }
    else if (buttonThatWasClicked == juce__textButton_down.get())
    {
        //[UserButtonCode_juce__textButton_down] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_down]
    }
    else if (buttonThatWasClicked == juce__textButton_l1.get())
    {
        //[UserButtonCode_juce__textButton_l1] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_l1]
    }
    else if (buttonThatWasClicked == juce__textButton_r1.get())
    {
        //[UserButtonCode_juce__textButton_r1] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_r1]
    }
    else if (buttonThatWasClicked == juce__textButton_Select.get())
    {
        //[UserButtonCode_juce__textButton_Select] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_Select]
    }
    else if (buttonThatWasClicked == juce__textButton_menu.get())
    {
        //[UserButtonCode_juce__textButton_menu] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_menu]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void DualSense_UI::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == juce__slider_L_Trigger.get())
    {
        //[UserSliderCode_juce__slider_L_Trigger] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider_L_Trigger]
    }
    else if (sliderThatWasMoved == juce__slider_R_Trigger.get())
    {
        //[UserSliderCode_juce__slider_R_Trigger] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider_R_Trigger]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void DualSense_UI::update()
{
    if(isConnected){
        setFramesPerSecond(12);
        juce__textButton_cross->setToggleState(DS_UI_input.buttons.cross, juce::sendNotification);
        juce__textButton_circle->setToggleState(DS_UI_input.buttons.circle, juce::sendNotification);
        juce__textButton_triangle->setToggleState(DS_UI_input.buttons.triangle, juce::sendNotification);
        juce__textButton_square->setToggleState(DS_UI_input.buttons.square, juce::sendNotification);

        juce__textButton_Select->setToggleState(DS_UI_input.buttons.select, juce::sendNotification);
        juce__textButton_menu->setToggleState(DS_UI_input.buttons.menu, juce::sendNotification);
        juce__textButton_r1->setToggleState(DS_UI_input.buttons.r1, juce::sendNotification);
        juce__textButton_l1->setToggleState(DS_UI_input.buttons.l1, juce::sendNotification);

        juce__textButton_up->setToggleState(DS_UI_input.dpad.up, juce::sendNotification);
        juce__textButton_right->setToggleState(DS_UI_input.dpad.right, juce::sendNotification);
        juce__textButton_left->setToggleState(DS_UI_input.dpad.left, juce::sendNotification);
        juce__textButton_down->setToggleState(DS_UI_input.dpad.down, juce::sendNotification);

        Left_Stick.updatePoint(DS_UI_input.leftStick.x, DS_UI_input.leftStick.y, DS_UI_input.leftStick.stickPress);
        Right_Stick.updatePoint(DS_UI_input.rightStick.x, DS_UI_input.rightStick.y, DS_UI_input.rightStick.stickPress);

        juce__slider_L_Trigger->setValue(DS_UI_input.leftTrigger);
        juce__slider_R_Trigger->setValue(DS_UI_input.rightTrigger);

        touchPad.updateTouchPad_1(DS_UI_input.touchPoint1);
        touchPad.updateTouchPad_2(DS_UI_input.touchPoint2);
        touchPad.pressTouchPad = DS_UI_input.buttons.touchPad;

    }else{
        setFramesPerSecond(1);
    }

}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="DualSense_UI" componentName=""
                 parentClasses="public juce::AnimatedAppComponent" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="0" snapShown="0"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="600" initialHeight="340">
  <BACKGROUND backgroundColour="ff323e44">
    <PATH pos="0 0 100 100" fill="solid: edfdff" hasStroke="1" stroke="3, mitered, butt"
          strokeColour="solid: ff6495ed" nonZeroWinding="1">s 300 216 l 384 216 q 406 213 432 240 l 472 328 q 504 328 528 304 l 536 248 q 544 168 488 40 l 408 24 q 304 16 192 24 l 112 40 q 64 152 64 224 l 64 272 l 72 304 q 88 328 128 328 q 152 272 176 224 q 197 214 216 216 x</PATH>
  </BACKGROUND>
  <TEXTBUTTON name="triangle_button" id="adfc8a3c333c90c1" memberName="juce__textButton_triangle"
              virtualName="" explicitFocusOrder="0" pos="71.333% 18.529% 6% 5%"
              bgColOn="ff5f9ea0" buttonText="Triangle" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="circle_button" id="37d4661129ea5fa4" memberName="juce__textButton_circle"
              virtualName="" explicitFocusOrder="0" pos="77% 28.235% 6% 5%"
              bgColOn="ff5f9ea0" buttonText="Circle" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="square_button" id="664054e5b09e5f11" memberName="juce__textButton_square"
              virtualName="" explicitFocusOrder="0" pos="65.5% 28.235% 6% 5%"
              bgColOn="ff5f9ea0" buttonText="Square" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="cross_button" id="1530d958f2eea907" memberName="juce__textButton_cross"
              virtualName="" explicitFocusOrder="0" pos="71.333% 37.941% 6% 5.294%"
              bgColOn="ff5f9ea0" buttonText="Cross" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="up_button" id="803a38bfe0c5cf5a" memberName="juce__textButton_up"
              virtualName="" explicitFocusOrder="0" pos="23.833% 21.176% 4.167% 4.412%"
              bgColOn="ff5f9ea0" buttonText="U" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="left_button" id="6e161f21a51340d7" memberName="juce__textButton_left"
              virtualName="" explicitFocusOrder="0" pos="19.667% 28.235% 4.167% 4.412%"
              bgColOn="ff5f9ea0" buttonText="L" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="right_button" id="348faaa33173332b" memberName="juce__textButton_right"
              virtualName="" explicitFocusOrder="0" pos="27.667% 28.235% 4.167% 4.412%"
              bgColOn="ff5f9ea0" buttonText="R" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="down_button" id="12403ef0daaaeefa" memberName="juce__textButton_down"
              virtualName="" explicitFocusOrder="0" pos="23.833% 35.588% 4.167% 4.412%"
              bgColOn="ff5f9ea0" buttonText="D" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="l1_button" id="4da68bd4fbe75348" memberName="juce__textButton_l1"
              virtualName="" explicitFocusOrder="0" pos="22% 2.647% 6% 5%"
              bgColOn="ff5f9ea0" buttonText="l1" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="r1_button" id="afad88da9b7b5250" memberName="juce__textButton_r1"
              virtualName="" explicitFocusOrder="0" pos="72% 2.647% 6% 5%"
              bgColOn="ff5f9ea0" buttonText="r1" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="Select_button" id="3a3507360c48e793" memberName="juce__textButton_Select"
              virtualName="" explicitFocusOrder="0" pos="29.5% 13.824% 4.167% 3.235%"
              bgColOn="ff5f9ea0" buttonText="Select" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="menu_button" id="476fde5307adb33" memberName="juce__textButton_menu"
              virtualName="" explicitFocusOrder="0" pos="66.167% 14.412% 4.167% 3.235%"
              bgColOn="ff5f9ea0" buttonText="Menu" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <SLIDER name="L_Trigger" id="108db3ed35a76737" memberName="juce__slider_L_Trigger"
          virtualName="" explicitFocusOrder="0" pos="1% 2.941% 7.5% 50%"
          min="0.0" max="1.0" int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="60" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="R_Trigger" id="e9ba45a333eabc57" memberName="juce__slider_R_Trigger"
          virtualName="" explicitFocusOrder="0" pos="91% 2.941% 7.5% 50%"
          min="0.0" max="1.0" int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="60" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

