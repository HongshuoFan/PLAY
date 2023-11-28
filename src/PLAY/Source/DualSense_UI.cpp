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
    juce__slider_L_Trigger->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 60, 20);
    juce__slider_L_Trigger->addListener (this);

    juce__slider_R_Trigger.reset (new juce::Slider ("R_Trigger"));
    addAndMakeVisible (juce__slider_R_Trigger.get());
    juce__slider_R_Trigger->setRange (0, 1, 0);
    juce__slider_R_Trigger->setSliderStyle (juce::Slider::LinearVertical);
    juce__slider_R_Trigger->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 60, 20);
    juce__slider_R_Trigger->addListener (this);

    cachedImage_dualSense_png_1 = juce::ImageCache::getFromMemory (dualSense_png, dualSense_pngSize);
    internalPath2.startNewSubPath (300.0f, 216.0f);
    internalPath2.lineTo (384.0f, 216.0f);
    internalPath2.quadraticTo (408.0f, 208.0f, 432.0f, 240.0f);
    internalPath2.lineTo (472.0f, 328.0f);
    internalPath2.quadraticTo (504.0f, 328.0f, 528.0f, 304.0f);
    internalPath2.lineTo (536.0f, 248.0f);
    internalPath2.quadraticTo (544.0f, 168.0f, 488.0f, 40.0f);
    internalPath2.lineTo (408.0f, 24.0f);
    internalPath2.quadraticTo (304.0f, 16.0f, 192.0f, 24.0f);
    internalPath2.lineTo (112.0f, 40.0f);
    internalPath2.quadraticTo (64.0f, 152.0f, 64.0f, 224.0f);
    internalPath2.lineTo (64.0f, 272.0f);
    internalPath2.lineTo (72.0f, 304.0f);
    internalPath2.quadraticTo (88.0f, 328.0f, 128.0f, 328.0f);
    internalPath2.quadraticTo (152.0f, 272.0f, 176.0f, 224.0f);
    internalPath2.quadraticTo (200.0f, 208.0f, 216.0f, 216.0f);
    internalPath2.closeSubPath();


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
        int x = 47, y = 0, width = 507, height = 340;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (juce::Colours::black.withAlpha (0.500f));
        g.drawImageWithin (cachedImage_dualSense_png_1,
                           x, y, width, height,
                           juce::RectanglePlacement::centred | juce::RectanglePlacement::onlyReduceInSize,
                           false);
    }

    {
        float x = 0, y = 0;
        juce::Colour strokeColour = juce::Colours::cornflowerblue;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.strokePath (internalPath2, juce::PathStrokeType (3.000f), juce::AffineTransform::translation (x, y));
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
    juce__slider_L_Trigger->setBounds (proportionOfWidth (0.0100f), proportionOfHeight (0.0300f), proportionOfWidth (0.0750f), proportionOfHeight (0.5000f));
    juce__slider_R_Trigger->setBounds (proportionOfWidth (0.9100f), proportionOfHeight (0.0300f), proportionOfWidth (0.0750f), proportionOfHeight (0.5000f));
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
    <IMAGE pos="47 0 507 340" resource="dualSense_png" opacity="0.5" mode="2"/>
    <PATH pos="0 0 100 100" fill="solid: edfdff" hasStroke="1" stroke="3, mitered, butt"
          strokeColour="solid: ff6495ed" nonZeroWinding="1">s 300 216 l 384 216 q 408 208 432 240 l 472 328 q 504 328 528 304 l 536 248 q 544 168 488 40 l 408 24 q 304 16 192 24 l 112 40 q 64 152 64 224 l 64 272 l 72 304 q 88 328 128 328 q 152 272 176 224 q 200 208 216 216 x</PATH>
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
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="R_Trigger" id="e9ba45a333eabc57" memberName="juce__slider_R_Trigger"
          virtualName="" explicitFocusOrder="0" pos="91% 2.941% 7.5% 50%"
          min="0.0" max="1.0" int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: dualSense_png, 96461, "../../../../../DualSense.png"
static const unsigned char resource_DualSense_UI_dualSense_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,3,158,0,0,2,134,8,6,0,0,0,34,125,68,165,0,0,1,96,105,67,67,80,73,67,67,32,80,114,
111,102,105,108,101,0,0,40,145,109,144,205,75,2,81,20,197,207,148,33,164,84,96,4,81,11,55,66,129,133,142,6,129,43,179,15,2,23,147,22,165,4,49,142,166,194,56,189,198,137,136,54,110,219,180,138,150,181,
139,160,160,165,27,131,160,117,16,4,5,173,218,245,7,4,179,41,121,221,167,149,90,221,199,229,252,56,220,251,184,28,160,203,173,50,166,59,0,148,12,203,76,44,204,120,215,82,105,175,243,21,46,140,192,131,
97,140,169,90,153,69,21,37,78,35,248,214,206,178,31,33,9,125,152,16,127,5,35,251,125,167,145,249,235,59,158,172,28,250,210,235,127,231,59,170,55,155,43,107,164,31,212,178,198,76,11,144,2,196,202,174,197,
4,87,136,7,77,58,138,248,72,112,190,201,231,130,51,77,174,53,102,150,19,49,226,123,226,1,173,160,102,137,95,136,253,153,54,63,223,198,37,125,71,251,186,65,92,239,206,25,43,73,210,33,234,81,204,98,14,113,
122,94,40,144,17,70,16,83,88,162,140,254,223,9,55,118,98,216,2,195,30,76,20,145,71,1,22,109,71,201,97,208,145,35,94,132,1,13,147,240,19,203,8,80,135,68,214,191,51,108,121,219,7,192,116,157,224,178,229,
109,92,1,181,20,208,111,180,60,223,9,197,120,1,220,122,152,106,170,63,201,74,182,163,188,25,146,155,236,170,2,61,199,156,191,173,2,206,113,160,254,196,249,123,149,243,250,25,208,253,12,220,216,159,144,
41,99,55,128,60,130,75,0,0,0,138,101,88,73,102,77,77,0,42,0,0,0,8,0,4,1,26,0,5,0,0,0,1,0,0,0,62,1,27,0,5,0,0,0,1,0,0,0,70,1,40,0,3,0,0,0,1,0,2,0,0,135,105,0,4,0,0,0,1,0,0,0,78,0,0,0,0,0,0,0,144,0,0,0,
1,0,0,0,144,0,0,0,1,0,3,146,134,0,7,0,0,0,18,0,0,0,120,160,2,0,4,0,0,0,1,0,0,3,158,160,3,0,4,0,0,0,1,0,0,2,134,0,0,0,0,65,83,67,73,73,0,0,0,83,99,114,101,101,110,115,104,111,116,221,194,152,255,0,0,0,
9,112,72,89,115,0,0,22,37,0,0,22,37,1,73,82,36,240,0,0,1,214,105,84,88,116,88,77,76,58,99,111,109,46,97,100,111,98,101,46,120,109,112,0,0,0,0,0,60,120,58,120,109,112,109,101,116,97,32,120,109,108,110,
115,58,120,61,34,97,100,111,98,101,58,110,115,58,109,101,116,97,47,34,32,120,58,120,109,112,116,107,61,34,88,77,80,32,67,111,114,101,32,54,46,48,46,48,34,62,10,32,32,32,60,114,100,102,58,82,68,70,32,120,
109,108,110,115,58,114,100,102,61,34,104,116,116,112,58,47,47,119,119,119,46,119,51,46,111,114,103,47,49,57,57,57,47,48,50,47,50,50,45,114,100,102,45,115,121,110,116,97,120,45,110,115,35,34,62,10,32,32,
32,32,32,32,60,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,32,114,100,102,58,97,98,111,117,116,61,34,34,10,32,32,32,32,32,32,32,32,32,32,32,32,120,109,108,110,115,58,101,120,105,102,61,34,
104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,101,120,105,102,47,49,46,48,47,34,62,10,32,32,32,32,32,32,32,32,32,60,101,120,105,102,58,80,105,120,101,108,89,68,105,109,101,110,
115,105,111,110,62,54,52,54,60,47,101,120,105,102,58,80,105,120,101,108,89,68,105,109,101,110,115,105,111,110,62,10,32,32,32,32,32,32,32,32,32,60,101,120,105,102,58,80,105,120,101,108,88,68,105,109,101,
110,115,105,111,110,62,57,50,54,60,47,101,120,105,102,58,80,105,120,101,108,88,68,105,109,101,110,115,105,111,110,62,10,32,32,32,32,32,32,32,32,32,60,101,120,105,102,58,85,115,101,114,67,111,109,109,101,
110,116,62,83,99,114,101,101,110,115,104,111,116,60,47,101,120,105,102,58,85,115,101,114,67,111,109,109,101,110,116,62,10,32,32,32,32,32,32,60,47,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,
62,10,32,32,32,60,47,114,100,102,58,82,68,70,62,10,60,47,120,58,120,109,112,109,101,116,97,62,10,251,201,254,21,0,0,0,28,105,68,79,84,0,0,0,2,0,0,0,0,0,0,1,67,0,0,0,40,0,0,1,67,0,0,1,67,0,0,213,33,182,
119,187,64,0,0,64,0,73,68,65,84,120,1,236,157,7,216,212,68,247,246,71,197,138,21,65,80,236,34,10,118,16,20,21,197,2,118,68,236,8,246,174,160,98,69,253,254,246,222,123,23,20,27,42,69,1,65,68,65,20,68,20,
177,97,239,162,34,88,176,247,119,191,249,205,251,230,97,121,216,108,146,221,100,55,187,123,159,235,202,179,187,201,204,100,114,39,79,102,206,153,115,238,179,64,198,138,145,8,1,33,32,4,132,128,16,16,2,
66,64,8,8,1,33,32,4,132,128,16,72,8,129,5,164,120,38,132,172,154,21,2,66,64,8,8,1,33,32,4,132,128,16,16,2,66,64,8,8,1,135,128,20,79,61,8,66,64,8,8,1,33,32,4,132,128,16,16,2,66,64,8,8,1,33,144,40,2,82,
60,19,133,87,141,11,1,33,32,4,132,128,16,16,2,66,64,8,8,1,33,32,4,132,128,20,79,61,3,66,64,8,8,1,33,32,4,132,128,16,16,2,66,64,8,8,1,33,144,40,2,82,60,19,133,87,141,11,1,33,32,4,132,128,16,16,2,66,64,
8,8,1,33,32,4,132,128,20,79,61,3,66,64,8,8,1,33,32,4,132,128,16,16,2,66,64,8,8,1,33,144,40,2,82,60,19,133,87,141,11,1,33,32,4,132,128,16,16,2,66,64,8,8,1,33,32,4,132,128,20,79,61,3,66,64,8,8,1,33,32,4,
132,128,16,16,2,66,64,8,8,1,33,144,40,2,82,60,19,133,87,141,11,1,33,32,4,132,128,16,16,2,66,64,8,8,1,33,32,4,132,128,20,79,61,3,66,64,8,8,1,33,32,4,132,128,16,16,2,66,64,8,8,1,33,144,40,2,82,60,19,133,
87,141,11,1,33,32,4,132,128,16,16,2,66,64,8,8,1,33,32,4,132,128,20,79,61,3,66,64,8,8,1,33,32,4,132,128,16,16,2,66,64,8,8,1,33,144,40,2,82,60,19,133,87,141,11,1,33,32,4,132,128,16,16,2,66,64,8,8,1,33,32,
4,132,128,20,79,61,3,66,64,8,8,1,33,32,4,132,128,16,16,2,66,64,8,8,1,33,144,40,2,82,60,19,133,87,141,11,1,33,32,4,132,128,16,16,2,66,64,8,8,1,33,32,4,132,128,20,79,61,3,66,64,8,8,1,33,32,4,132,128,16,
16,2,66,64,8,8,1,33,144,40,2,82,60,19,133,87,141,11,1,33,32,4,132,128,16,16,2,66,64,8,8,1,33,32,4,132,128,20,79,61,3,66,64,8,8,1,33,32,4,132,128,16,16,2,66,64,8,8,1,33,144,40,2,82,60,19,133,87,141,11,
1,33,32,4,132,128,16,16,2,66,64,8,8,1,33,32,4,132,128,20,79,61,3,66,64,8,8,1,33,32,4,132,128,16,16,2,66,64,8,8,1,33,144,40,2,82,60,19,133,87,141,11,1,33,32,4,132,128,16,16,2,66,64,8,8,1,33,32,4,132,128,
20,79,61,3,66,64,8,8,1,33,32,4,132,128,16,16,2,66,64,8,8,1,33,144,40,2,82,60,19,133,87,141,11,1,33,32,4,132,128,16,16,2,66,64,8,8,1,33,32,4,132,128,20,79,61,3,66,64,8,8,1,33,32,4,132,128,16,16,2,66,64,
8,8,1,33,144,40,2,82,60,19,133,87,141,11,1,33,32,4,132,128,16,16,2,66,64,8,8,1,33,32,4,132,128,20,79,61,3,53,143,192,191,255,254,107,126,253,245,87,183,253,242,203,47,134,141,223,222,119,62,127,254,249,
103,243,227,143,63,186,237,167,159,126,114,191,41,179,248,226,139,155,101,150,89,166,110,91,122,233,165,77,195,134,13,205,146,75,46,233,54,239,187,247,201,126,190,47,188,240,194,53,143,187,0,16,2,66,64,
8,8,1,33,80,106,4,254,248,227,143,249,198,249,236,49,223,251,206,88,207,184,63,103,206,28,55,230,255,243,207,63,110,92,103,156,103,243,198,254,165,150,90,106,158,241,222,27,231,189,121,0,243,132,5,22,
88,160,212,151,169,243,9,129,84,34,32,197,51,149,183,69,157,138,27,129,191,255,254,219,124,254,249,231,230,227,143,63,54,31,125,244,145,121,239,189,247,204,244,233,211,205,151,95,126,233,6,22,20,65,182,
69,22,89,196,52,104,208,192,109,11,45,180,80,221,39,251,189,193,102,217,101,151,53,203,45,183,156,27,116,80,72,25,148,216,24,160,254,250,235,47,131,34,203,198,32,197,121,217,216,255,231,159,127,214,109,
139,46,186,168,105,210,164,137,105,218,180,169,89,115,205,53,77,171,86,173,76,203,150,45,221,198,62,137,16,16,2,66,64,8,8,1,33,16,29,1,198,223,79,63,253,212,188,255,254,251,110,123,231,157,119,220,248,
63,107,214,44,243,221,119,223,185,6,25,131,189,141,241,157,241,223,27,251,249,100,252,95,108,177,197,12,227,189,55,230,83,230,251,239,191,159,103,204,199,48,205,88,159,61,238,215,31,251,57,33,115,6,198,
250,245,215,95,223,172,189,246,218,238,59,191,155,53,107,38,165,52,250,45,86,141,10,70,64,138,103,5,223,60,117,125,126,4,254,243,159,255,152,79,62,249,196,188,245,214,91,230,181,215,94,51,83,166,76,49,
159,125,246,153,249,237,183,223,12,86,73,6,16,172,148,188,236,55,222,120,99,179,201,38,155,184,1,160,148,202,94,38,147,49,51,103,206,172,83,130,95,121,229,21,55,56,98,101,101,80,68,73,165,175,173,91,183,
54,155,110,186,169,89,111,189,245,220,247,230,205,155,107,128,154,255,150,107,143,16,16,2,66,64,8,212,32,2,40,120,31,126,248,161,51,34,191,249,230,155,134,177,20,133,243,247,223,127,119,99,104,163,70,
141,156,135,81,155,54,109,204,70,27,109,84,167,236,97,68,46,149,160,144,50,7,193,224,61,117,234,84,55,55,97,156,103,53,245,135,31,126,112,198,104,230,36,235,174,187,174,217,108,179,205,204,6,27,108,224,
54,12,211,18,33,80,141,8,72,241,172,198,187,90,67,215,196,75,253,229,151,95,54,163,71,143,54,99,199,142,53,95,125,245,149,115,121,241,86,19,183,218,106,43,179,197,22,91,184,151,58,214,203,74,144,217,179,
103,27,6,209,9,19,38,184,207,111,191,253,214,176,177,98,202,117,117,232,208,193,109,109,219,182,117,3,105,37,92,147,250,40,4,132,128,16,16,2,66,160,80,4,80,50,223,120,227,13,167,188,77,156,56,209,76,155,
54,205,185,191,98,76,110,220,184,177,89,97,133,21,156,226,198,120,143,7,209,18,75,44,81,232,169,74,90,15,229,147,241,126,252,248,241,230,213,87,95,117,198,103,230,0,24,209,241,130,218,117,215,93,77,151,
46,93,204,90,107,173,85,210,126,233,100,66,32,41,4,164,120,38,133,172,218,77,12,1,148,203,167,158,122,202,60,246,216,99,230,221,119,223,117,131,78,139,22,45,204,238,187,239,110,118,216,97,7,247,59,177,
147,151,177,97,86,73,95,124,241,69,119,237,184,12,127,253,245,215,206,253,247,170,171,174,114,138,104,25,187,166,83,11,1,33,32,4,132,128,16,136,29,1,140,203,119,223,125,183,185,254,250,235,157,50,137,
183,18,238,170,59,239,188,179,97,37,147,56,202,106,148,15,62,248,192,140,24,49,194,140,27,55,206,121,71,17,178,211,177,99,71,211,173,91,55,179,237,182,219,186,149,220,106,188,110,93,83,245,35,32,197,179,
250,239,113,197,95,33,150,191,151,94,122,201,60,241,196,19,238,69,140,229,115,141,53,214,48,219,109,183,157,233,209,163,135,89,105,165,149,42,254,26,11,185,0,6,228,75,47,189,212,12,24,48,192,220,116,211,
77,102,167,157,118,42,164,25,213,17,2,66,64,8,8,1,33,144,74,4,142,63,254,120,51,105,210,36,115,235,173,183,154,205,55,223,60,149,125,76,186,83,204,129,112,35,190,247,222,123,205,235,175,191,238,66,117,
80,192,247,217,103,31,179,219,110,187,105,53,52,233,27,160,246,99,69,64,138,103,172,112,170,177,184,16,32,222,241,233,167,159,54,15,63,252,176,123,225,46,191,252,242,46,206,241,160,131,14,50,91,111,189,
181,11,252,143,235,92,149,222,206,227,143,63,110,206,61,247,92,23,211,90,233,215,162,254,11,1,33,32,4,132,128,16,0,1,72,251,8,41,121,225,133,23,204,138,43,174,40,80,254,135,0,174,184,120,124,49,246,19,
63,10,99,238,46,187,236,98,246,218,107,47,231,110,188,224,130,11,10,43,33,144,90,4,164,120,166,246,214,212,94,199,96,139,27,62,124,184,185,255,254,251,29,65,192,170,171,174,106,182,220,114,75,115,196,
17,71,24,190,75,254,139,0,44,122,196,181,78,158,60,217,197,131,192,200,55,120,240,96,167,160,67,74,36,17,2,66,64,8,8,1,33,80,233,8,140,25,51,198,156,113,198,25,230,134,27,110,112,10,104,165,196,109,150,
18,119,200,8,159,121,230,25,231,249,4,91,63,243,3,230,77,71,30,121,164,227,183,144,18,90,202,187,161,115,133,65,64,138,103,24,148,84,38,49,4,96,119,27,54,108,152,115,33,249,230,155,111,156,203,8,174,35,
7,30,120,160,99,159,77,236,196,21,208,48,138,56,49,172,80,193,19,211,137,85,19,37,19,6,60,152,239,96,233,99,37,24,129,13,239,142,59,238,112,251,42,224,210,212,69,33,80,48,2,176,66,227,102,94,204,134,187,
126,49,245,169,139,251,27,66,127,152,220,145,126,193,219,188,116,12,222,111,62,11,221,23,182,94,193,128,170,162,16,72,41,2,183,221,118,155,11,175,65,249,100,28,100,76,68,177,98,67,9,93,109,181,213,230,
217,106,93,49,229,93,132,81,250,206,59,239,116,140,254,176,249,111,179,205,54,6,79,49,136,22,165,132,166,244,65,175,177,110,73,241,172,177,27,158,134,203,101,208,192,69,228,174,187,238,114,4,57,16,3,237,
189,247,222,102,191,253,246,51,36,90,174,21,129,242,29,234,119,210,191,240,9,89,16,226,77,52,201,251,5,54,108,12,176,236,247,19,136,22,176,112,118,239,222,221,175,136,246,11,129,130,17,128,81,153,73,12,
207,108,253,79,146,177,115,60,59,87,45,251,40,155,253,233,149,227,147,13,178,12,79,1,228,51,123,171,175,20,122,229,216,207,228,10,35,12,147,40,111,227,55,202,93,174,253,249,246,121,199,178,63,179,191,
211,62,191,253,54,0,229,24,125,98,67,25,245,190,123,159,222,190,236,79,239,123,118,29,246,121,155,223,126,239,184,87,223,195,131,242,217,74,110,182,162,203,123,163,254,230,229,44,228,147,92,134,48,126,
103,111,76,224,121,23,123,27,191,189,156,135,245,63,169,199,113,111,203,247,158,42,248,1,84,197,154,68,224,196,19,79,116,255,79,172,120,214,23,230,17,16,238,177,97,180,102,227,221,148,253,238,224,189,
193,255,10,233,83,96,190,101,195,88,235,125,50,198,86,171,50,198,59,1,50,66,148,119,216,128,193,166,115,231,206,230,144,67,14,49,237,218,181,171,15,167,126,11,129,146,33,32,197,179,100,80,215,246,137,
24,12,112,7,185,253,246,219,29,117,56,137,147,137,71,96,101,147,9,75,53,10,47,126,47,95,39,43,150,159,127,254,185,155,108,179,159,141,73,221,234,171,175,94,103,177,37,134,165,208,65,16,146,37,114,146,
158,118,218,105,213,8,165,174,41,0,1,20,57,38,22,196,70,179,121,223,189,207,236,125,76,216,126,252,241,71,151,71,142,92,114,252,102,67,81,228,255,52,91,201,243,38,113,60,151,172,182,163,84,100,43,45,252,
70,201,241,132,231,26,241,148,152,108,197,133,255,243,134,13,27,214,109,148,65,137,161,221,236,207,236,239,245,143,121,191,11,253,63,241,250,89,109,159,220,51,148,255,168,27,207,13,207,198,207,63,255,
60,207,179,195,115,195,243,224,25,15,48,42,120,226,41,218,217,202,47,70,4,111,227,120,182,18,236,61,35,220,127,66,1,80,2,216,240,220,32,21,6,172,164,108,222,179,145,235,59,251,120,94,36,181,133,64,167,
78,157,204,225,135,31,110,122,245,234,85,240,133,243,78,226,249,102,181,116,214,172,89,243,40,170,120,92,121,207,43,207,41,27,207,38,161,61,222,86,204,184,92,112,167,99,174,200,255,42,113,178,183,220,
114,139,203,121,202,123,29,67,63,74,40,70,109,137,16,40,37,2,82,60,75,137,118,13,158,11,133,11,101,19,119,90,242,108,237,184,227,142,230,184,227,142,51,36,118,174,6,97,80,67,185,132,250,156,68,214,51,
102,204,112,147,119,94,244,8,131,22,249,183,194,172,90,22,131,7,228,66,172,154,194,122,39,73,63,2,12,252,76,134,242,109,94,130,113,38,76,228,122,67,89,164,60,74,0,138,70,246,230,41,134,40,133,40,103,124,
214,223,152,84,177,15,197,14,5,128,137,63,27,255,139,88,254,81,2,152,252,103,43,136,222,119,234,73,132,64,16,2,188,15,81,86,61,3,8,6,13,190,243,201,115,236,109,144,198,100,63,207,158,210,202,39,207,183,
247,153,253,157,255,25,79,57,224,121,228,59,134,13,20,5,158,95,54,86,179,248,204,86,112,57,158,253,155,239,212,149,164,31,129,245,214,91,207,17,12,18,90,82,42,225,89,133,176,199,219,240,68,226,185,230,
29,203,198,51,135,178,6,179,62,27,185,181,43,73,248,223,26,57,114,164,115,199,253,232,163,143,92,255,153,147,237,185,231,158,50,238,84,210,141,172,224,190,74,241,172,224,155,151,214,174,51,33,38,245,201,
117,215,93,231,38,204,184,117,156,122,234,169,142,149,54,173,125,14,234,23,19,32,148,75,98,46,249,100,114,229,89,252,81,46,215,89,103,29,151,236,121,229,149,87,46,120,213,50,168,15,249,142,147,239,235,
194,11,47,116,105,103,242,149,211,177,248,16,224,57,103,2,141,82,88,127,195,146,142,235,23,236,131,223,126,251,173,155,100,123,238,168,12,252,76,162,235,175,236,161,48,214,223,60,197,144,9,53,19,28,54,
20,68,38,207,217,27,245,36,66,160,154,17,224,29,140,49,6,227,11,159,158,97,134,85,44,54,254,207,80,108,81,116,249,31,227,255,205,251,244,254,247,188,21,97,207,80,227,253,191,241,127,198,255,86,211,166,
77,221,134,49,198,51,200,100,127,242,63,199,10,153,36,121,4,24,95,215,94,123,109,231,33,133,1,44,45,130,151,0,6,117,148,54,54,222,241,60,79,172,242,99,16,65,41,109,217,178,165,235,59,70,144,52,11,198,
31,66,158,134,12,25,226,254,135,72,201,214,187,119,111,215,255,52,247,91,125,171,108,4,164,120,86,246,253,75,85,239,25,248,137,39,128,149,22,101,12,55,218,131,15,62,216,189,140,83,213,209,60,157,65,153,
96,229,114,250,244,233,6,134,56,38,42,12,128,12,40,12,130,173,91,183,118,74,102,218,220,190,24,0,119,221,117,87,167,24,231,185,60,29,202,131,0,202,32,19,87,158,99,79,97,228,59,10,228,23,95,124,225,86,
179,217,143,27,34,207,5,207,10,207,1,22,112,207,109,148,79,38,179,76,148,152,200,242,127,64,158,217,230,205,155,215,77,100,153,140,48,209,101,178,34,17,2,66,160,180,8,176,122,197,132,27,99,145,183,2,251,
213,87,95,185,255,111,86,183,248,159,71,185,168,191,241,127,207,255,60,99,1,255,231,120,7,240,255,189,202,42,171,184,255,111,254,223,189,56,66,62,249,205,106,171,20,213,194,238,47,161,41,16,13,18,159,
88,41,194,24,2,103,131,71,10,136,97,210,115,59,231,89,89,127,253,245,221,28,2,227,97,218,228,173,183,222,50,151,95,126,185,153,54,109,154,123,118,9,219,65,17,213,56,149,182,59,85,249,253,145,226,89,249,
247,176,236,87,128,210,115,201,37,151,152,137,19,39,58,86,213,115,206,57,199,177,174,150,189,99,1,29,192,165,134,65,237,181,215,94,115,202,5,10,38,147,4,172,149,27,110,184,161,89,119,221,117,157,18,17,
208,76,42,14,99,217,167,191,12,120,76,140,36,115,17,96,240,247,72,40,248,100,114,201,164,6,87,42,190,51,161,100,146,9,134,76,40,81,26,179,55,38,152,40,143,196,37,227,54,77,226,110,220,198,89,133,204,142,
111,156,123,70,125,19,2,66,160,26,17,192,224,196,234,42,198,40,148,85,198,62,20,13,207,32,197,187,36,123,227,157,130,103,3,239,21,148,80,60,98,86,183,113,253,124,242,30,201,222,48,96,73,230,34,240,236,
179,207,154,11,46,184,192,140,31,63,126,238,206,10,254,198,243,242,250,235,175,187,57,7,134,15,220,189,89,65,135,157,30,126,6,12,21,105,16,188,185,8,143,122,244,209,71,157,87,1,4,79,196,216,242,28,75,
132,64,28,8,72,241,140,3,197,26,109,3,122,243,255,247,255,254,159,83,118,182,221,118,91,67,156,33,150,222,52,10,19,0,148,76,168,198,81,54,176,76,162,92,240,194,111,211,166,141,115,175,74,99,191,163,244,
137,235,24,52,104,144,91,153,141,82,175,210,203,114,47,89,145,100,18,200,134,229,150,103,147,9,34,110,121,222,0,239,197,47,114,223,153,240,161,68,98,100,96,53,210,83,38,21,251,85,233,79,131,250,47,4,210,
131,0,147,120,207,232,133,177,11,47,26,20,85,86,90,81,80,179,99,97,49,98,161,136,176,130,202,202,24,134,68,143,31,32,45,74,73,41,145,37,61,216,232,209,163,157,27,104,41,207,91,202,115,241,12,176,194,56,
117,234,84,103,188,192,240,141,199,12,158,85,27,111,188,177,139,33,45,231,138,57,202,255,53,215,92,227,188,192,142,57,230,24,115,244,209,71,59,15,159,82,98,164,115,85,31,2,82,60,171,239,158,38,126,69,
12,158,103,159,125,182,121,255,253,247,205,46,187,236,226,148,79,38,245,105,17,92,169,80,64,120,153,179,2,136,210,137,66,129,101,177,67,135,14,78,201,72,75,95,227,236,199,14,59,236,224,98,105,113,143,
169,86,97,34,135,225,128,251,139,37,156,13,75,50,207,31,46,172,176,95,66,248,208,190,125,123,183,234,206,196,45,141,110,77,213,122,127,116,93,66,64,8,68,71,128,49,203,91,65,125,245,213,87,221,216,197,
170,170,23,199,138,55,14,4,117,144,243,109,190,249,230,78,57,37,30,181,154,13,101,39,157,116,146,115,109,190,233,166,155,162,3,90,193,53,136,101,126,251,237,183,157,66,138,145,194,35,54,226,254,99,40,
199,32,81,234,251,14,175,197,249,231,159,111,120,54,81,64,143,58,234,40,183,138,95,193,48,171,235,101,68,64,138,103,25,193,175,180,83,19,80,143,194,249,230,155,111,186,216,11,86,59,211,160,112,194,230,
250,202,43,175,184,151,53,74,38,22,66,20,142,182,109,219,154,86,173,90,213,140,59,228,62,251,236,99,58,89,250,249,227,143,63,190,210,30,45,183,2,205,68,235,203,47,191,116,19,48,62,189,85,76,62,89,185,
244,226,109,89,25,96,5,192,75,201,195,53,75,185,172,184,91,174,14,11,1,33,16,18,1,20,16,86,255,216,120,55,226,170,137,167,7,171,99,184,64,98,116,131,212,6,229,4,15,14,54,194,3,216,32,71,42,231,170,89,
200,75,156,175,216,246,219,111,111,14,58,232,32,199,19,49,223,193,26,219,129,225,1,238,9,86,71,49,166,19,107,204,61,37,229,11,158,78,172,144,243,44,36,45,24,71,8,165,34,63,104,159,62,125,92,170,155,82,
156,55,233,235,82,251,165,69,64,138,103,105,241,174,200,179,17,191,130,146,249,220,115,207,153,157,119,222,217,197,93,176,178,84,14,97,181,11,37,147,88,9,20,17,100,117,27,51,179,233,166,155,26,168,215,
75,109,9,44,7,6,126,231,60,249,228,147,221,234,110,26,45,196,176,188,226,106,134,18,201,39,70,12,86,204,25,200,112,55,194,96,64,140,83,54,83,43,147,41,8,157,80,50,39,76,152,224,238,247,118,219,109,103,
186,117,235,150,154,120,24,191,123,161,253,66,64,8,8,129,164,16,96,69,108,240,224,193,142,97,29,15,15,20,78,222,167,24,97,61,230,95,140,117,240,24,176,130,70,140,41,99,54,202,41,43,102,124,226,210,139,
226,194,103,26,12,200,245,177,98,60,127,240,193,7,157,167,82,253,99,250,253,95,4,224,41,96,21,146,240,18,238,51,66,252,48,70,119,92,117,147,154,15,97,252,56,235,172,179,220,202,60,115,195,125,247,221,
183,34,141,27,255,69,81,127,75,141,128,20,207,82,35,94,65,231,227,69,118,253,245,215,27,98,45,58,118,236,104,174,186,234,42,103,61,45,213,37,48,128,162,100,226,50,203,119,132,88,60,210,179,224,54,171,
96,247,121,239,4,108,194,80,163,227,126,90,106,33,86,9,171,60,27,74,37,49,150,88,102,97,136,196,61,22,171,40,228,26,94,78,61,220,196,152,88,96,169,101,242,195,96,89,223,114,202,36,106,232,208,161,110,
240,220,127,255,253,165,108,150,250,166,234,124,66,64,8,164,30,1,86,193,158,126,250,105,247,30,237,222,189,251,124,239,81,20,80,140,125,188,155,225,57,32,84,6,194,53,198,84,86,78,249,132,185,20,195,31,
239,97,222,203,24,252,80,104,241,42,65,49,45,53,97,29,238,165,40,211,244,55,141,74,113,154,31,10,114,137,51,103,226,185,96,85,220,243,0,195,56,143,209,33,78,66,60,198,248,51,207,60,211,197,49,223,120,
227,141,110,110,150,102,108,212,183,116,32,32,197,51,29,247,33,117,189,96,117,147,124,78,184,236,144,143,147,60,149,73,10,43,94,184,240,78,153,50,197,185,18,113,46,148,20,94,150,88,239,248,46,201,143,
0,131,244,1,7,28,224,82,193,228,47,89,216,81,238,17,147,23,38,46,108,172,58,163,96,50,113,97,162,64,138,16,92,94,249,196,162,142,11,16,36,9,76,94,162,184,194,146,230,224,222,123,239,117,70,6,44,169,162,
115,47,236,126,169,150,16,16,2,181,131,0,222,64,24,30,121,231,162,128,134,117,175,229,221,237,197,205,243,78,103,131,152,13,229,148,13,197,21,35,47,158,39,27,108,176,129,219,188,188,213,184,242,134,61,
79,148,59,129,242,132,119,21,115,2,73,113,8,112,127,225,68,192,136,207,120,141,219,46,99,42,74,40,243,43,20,252,98,239,225,200,145,35,157,39,28,70,139,171,175,190,218,185,126,23,215,107,213,174,102,4,
164,120,86,243,221,45,224,218,80,34,160,207,198,90,118,202,41,167,56,26,237,2,154,9,172,130,203,229,75,47,189,228,92,68,188,220,104,12,106,155,109,182,153,83,118,3,27,80,129,249,16,96,213,145,52,48,196,
130,20,51,144,48,80,97,33,103,208,103,18,50,121,242,100,183,138,201,202,37,6,0,210,136,16,55,196,192,5,89,19,131,13,86,241,56,20,196,17,35,70,184,21,91,136,12,100,233,158,239,22,107,135,16,16,2,66,32,
47,2,99,198,140,113,169,48,120,135,162,24,22,43,132,180,48,166,120,99,1,238,157,94,254,83,198,4,12,141,120,174,48,118,123,138,41,227,67,49,130,215,14,44,249,24,192,37,241,35,128,242,201,106,37,202,40,
196,65,140,249,120,28,65,94,196,125,36,93,88,84,161,77,238,217,99,143,61,230,210,235,237,185,231,158,81,155,80,249,26,65,64,138,103,141,220,232,48,151,249,252,243,207,59,182,50,92,89,111,185,229,22,23,
19,18,166,94,80,25,114,36,226,250,129,162,201,106,22,47,57,20,21,216,249,24,176,226,116,253,8,234,75,181,31,103,224,199,37,26,5,20,119,214,48,202,32,49,188,172,52,147,135,149,129,30,250,127,220,174,176,
112,51,0,49,16,109,189,245,214,206,146,78,42,146,164,228,178,203,46,115,10,243,25,103,156,145,212,41,212,174,16,16,2,66,160,234,17,96,197,18,143,165,211,79,63,221,121,12,37,117,193,132,82,160,144,146,
118,131,56,67,126,51,158,96,248,100,37,141,152,124,198,121,20,154,48,99,7,225,61,196,15,222,125,247,221,142,44,112,200,144,33,73,117,93,237,214,67,128,121,26,57,205,73,57,7,209,31,110,186,120,42,225,113,
198,6,231,66,24,33,254,24,230,91,188,229,200,7,42,111,181,48,168,213,86,25,41,158,181,117,191,115,94,45,150,42,18,53,147,48,248,188,243,206,51,176,163,22,35,184,201,192,122,198,64,196,203,11,98,3,94,92,
12,64,97,95,94,197,156,191,218,235,130,41,131,51,150,103,226,32,89,61,246,136,150,32,26,128,200,135,216,29,6,18,94,250,40,249,224,207,224,143,27,22,202,36,70,134,225,195,135,59,210,30,86,156,87,92,113,
69,23,35,68,122,156,109,182,217,38,22,75,121,216,251,128,33,2,247,28,172,228,135,29,118,88,216,106,42,39,4,132,128,16,16,2,62,8,160,196,29,119,220,113,6,67,30,49,155,165,18,111,53,141,149,87,12,153,184,
241,162,140,226,41,195,248,130,11,45,6,103,86,218,166,79,159,94,71,22,136,178,204,10,170,71,48,71,188,41,236,244,40,177,140,13,132,111,64,36,200,39,109,73,146,71,128,133,2,188,223,216,248,206,189,229,
254,192,177,193,124,130,121,67,46,161,28,100,135,99,199,142,53,3,7,14,116,97,55,185,202,105,95,109,34,32,197,179,54,239,123,221,85,227,158,185,223,126,251,57,102,209,135,30,122,200,173,146,213,29,12,241,
5,165,133,216,194,73,147,38,185,149,50,170,48,96,108,177,197,22,206,5,83,171,153,33,64,172,87,4,69,140,65,216,35,235,65,193,100,64,102,63,194,42,38,214,68,6,97,54,200,121,114,17,45,17,155,131,245,145,
213,204,23,94,120,193,49,200,18,179,3,211,33,3,55,110,178,61,123,246,116,113,30,229,186,79,12,76,24,61,136,77,61,246,216,99,235,33,161,159,66,64,8,8,1,33,80,40,2,196,229,247,234,213,203,189,227,73,179,
133,39,75,57,132,121,6,4,72,15,63,252,176,83,98,80,138,49,66,179,162,134,82,140,177,19,101,166,101,203,150,57,137,140,48,166,98,100,245,54,92,125,81,72,189,144,146,198,141,27,59,50,36,8,145,24,19,81,142,
36,201,32,192,188,194,11,195,193,168,192,188,132,251,128,145,0,79,43,140,219,222,124,4,86,98,198,247,11,47,188,176,232,5,141,100,174,70,173,150,3,1,41,158,229,64,61,37,231,100,48,32,33,53,138,34,140,168,
97,168,183,81,90,136,249,67,153,33,13,6,10,11,3,6,138,38,140,179,146,112,8,176,66,137,66,73,208,63,44,176,40,154,158,98,73,11,172,74,66,202,195,198,64,202,170,113,92,194,138,244,35,143,60,226,86,68,201,
149,134,43,109,169,133,107,38,237,11,241,161,164,84,129,146,93,34,4,132,128,16,16,2,241,34,128,251,235,105,167,157,230,198,20,8,223,74,157,250,130,113,13,15,40,20,79,12,168,120,62,117,233,210,37,148,235,
109,88,36,184,70,143,81,157,79,230,41,8,10,17,140,188,120,253,120,227,41,70,219,48,33,40,97,207,173,114,198,173,132,50,166,227,229,6,241,32,243,27,238,59,113,163,204,19,49,56,244,235,215,79,30,77,122,
88,28,2,82,60,107,244,65,224,165,176,219,110,187,57,2,151,65,131,6,213,89,14,235,195,129,139,12,171,101,196,113,176,186,9,225,11,43,101,237,219,183,143,117,224,168,127,222,106,248,141,171,43,47,99,136,
25,216,112,127,5,119,239,133,140,117,22,43,33,91,33,193,252,113,96,68,92,39,110,52,173,90,181,50,40,161,73,11,110,194,55,223,124,179,99,194,61,245,212,83,13,20,236,36,162,246,44,164,73,159,95,237,11,1,
33,32,4,106,13,1,98,237,112,141,68,241,195,232,216,183,111,95,55,238,36,137,3,43,99,120,81,49,6,98,152,198,197,182,212,105,89,184,62,230,45,132,163,96,228,101,35,76,133,49,24,65,1,101,236,37,30,149,113,
24,35,111,24,3,188,171,172,63,129,8,176,178,141,75,53,43,164,144,93,145,158,15,163,131,164,182,17,144,226,89,163,247,255,182,219,110,115,41,43,38,76,152,48,207,96,192,11,154,248,63,104,183,121,57,67,48,
179,213,86,91,185,100,196,229,114,199,76,243,45,34,150,1,204,72,222,141,165,15,69,221,83,46,81,166,24,204,112,37,98,131,253,47,173,66,223,137,249,196,26,205,253,78,66,88,105,197,237,230,168,163,142,114,
174,95,196,163,98,169,214,64,148,4,218,106,83,8,8,1,33,240,95,4,112,185,61,242,200,35,205,128,1,3,156,167,203,37,151,92,226,92,83,15,61,244,208,216,33,66,217,232,223,191,191,243,226,161,125,60,170,210,
44,16,233,96,24,70,65,194,149,23,227,168,231,198,139,23,23,99,55,46,192,92,135,86,74,11,191,147,207,60,243,140,11,167,193,91,46,74,122,181,194,207,168,154,105,69,64,138,103,90,239,76,130,253,98,16,194,
15,31,255,123,20,75,8,0,60,74,109,92,82,96,48,101,5,204,139,159,72,176,43,21,211,52,174,35,40,151,80,144,131,21,171,153,40,152,96,68,140,37,121,205,216,202,181,114,25,23,144,79,62,249,164,97,128,192,34,
142,75,82,92,194,202,42,214,111,152,107,151,92,114,73,215,44,238,181,196,126,72,132,128,16,16,2,66,32,89,4,96,170,103,220,239,212,169,147,59,17,185,23,199,141,27,231,82,95,224,18,25,135,48,151,120,234,
169,167,28,169,81,218,21,206,48,215,11,195,59,70,89,198,126,12,204,222,152,207,202,45,174,187,164,20,67,41,85,76,105,24,52,141,227,114,0,47,86,63,37,181,139,128,20,207,26,188,247,80,159,147,171,179,107,
215,174,206,181,132,129,8,171,158,196,24,172,181,12,50,176,237,161,96,242,155,193,134,129,25,197,18,133,156,23,103,53,187,134,194,94,71,60,6,43,159,144,15,21,43,172,164,226,206,139,162,233,25,51,192,24,
98,33,88,23,37,66,64,8,8,1,33,144,44,2,112,58,156,112,194,9,110,53,210,59,19,134,212,107,175,189,214,92,119,221,117,69,17,15,17,199,135,81,145,152,125,200,10,171,93,112,223,197,109,23,252,216,136,41,245,
86,73,49,216,50,79,96,131,244,72,50,23,1,82,181,28,114,200,33,110,126,53,119,175,190,213,26,2,82,60,107,237,142,219,235,197,242,137,242,73,162,223,90,22,98,61,96,228,37,32,158,120,20,20,76,44,153,40,152,
208,189,163,96,150,35,38,37,45,247,132,92,106,224,115,229,149,87,58,197,187,144,126,241,156,49,216,212,207,205,249,127,255,247,127,46,182,83,3,115,33,168,170,142,16,16,2,66,32,58,2,196,211,243,238,205,
126,239,66,114,199,59,158,248,187,66,194,105,80,188,110,184,225,6,115,246,217,103,199,234,37,19,253,234,210,81,131,121,5,108,242,24,175,9,37,193,61,23,165,148,21,96,20,115,182,52,135,221,36,137,34,158,
98,92,63,70,125,185,45,39,137,116,186,219,150,226,153,238,251,147,72,239,88,237,68,201,98,176,168,5,33,14,147,24,14,86,221,112,155,193,213,152,235,199,50,9,35,47,20,224,158,251,103,45,224,17,229,26,95,
121,229,21,115,215,93,119,185,73,73,212,85,94,92,147,32,18,194,18,94,95,72,157,114,235,173,183,214,223,173,223,66,64,8,8,1,33,144,16,2,184,194,18,199,120,240,193,7,207,115,6,200,3,199,143,31,239,60,161,
230,57,16,240,3,195,34,60,17,231,156,115,142,72,121,2,176,130,227,0,146,29,12,221,16,13,162,120,97,216,198,93,151,57,8,4,71,133,40,254,1,167,77,221,97,174,117,196,136,17,46,68,41,117,157,83,135,74,130,
128,20,207,146,192,156,174,147,116,238,220,217,244,232,209,195,36,65,44,80,238,43,197,5,6,11,44,196,53,184,194,160,116,242,130,199,149,24,42,121,86,51,107,225,229,30,231,125,96,192,68,129,60,239,188,243,
34,185,24,179,202,9,153,80,125,133,21,133,20,122,117,40,254,37,66,64,8,8,1,33,80,26,4,24,31,121,239,226,94,91,95,32,28,36,189,26,108,235,97,100,244,232,209,46,238,17,210,34,73,97,8,96,4,103,190,130,226,
207,42,32,243,21,86,71,87,183,236,186,109,219,182,117,49,185,213,230,117,69,206,86,230,5,124,74,106,19,1,41,158,53,120,223,113,35,189,239,190,251,156,34,86,201,151,207,75,27,151,150,169,83,167,58,43,46,
171,152,40,149,196,86,160,100,98,65,244,98,10,43,249,58,211,208,119,92,134,88,33,39,78,51,204,64,136,37,156,65,116,135,29,118,152,175,251,195,134,13,51,43,174,184,98,89,242,135,206,215,25,237,16,2,66,
64,8,212,16,2,126,164,110,40,165,40,4,108,65,194,42,39,249,151,247,223,127,255,160,162,58,30,17,1,230,49,228,34,101,94,195,252,134,121,14,198,115,12,2,158,50,90,201,41,95,186,117,235,102,246,216,99,143,
170,92,248,136,120,171,107,182,184,20,207,26,188,245,40,100,184,80,86,18,165,53,47,95,92,84,120,25,19,147,130,160,0,193,210,199,203,24,11,161,148,204,100,31,230,89,179,102,153,155,110,186,201,173,124,
6,197,103,176,218,121,249,229,151,207,215,33,38,55,164,83,33,206,120,177,197,22,155,239,184,118,8,1,33,32,4,132,64,114,8,16,203,73,172,103,174,241,114,128,77,183,210,174,93,59,23,135,231,215,3,226,254,
73,137,113,196,17,71,248,21,209,254,152,17,240,148,81,230,109,40,163,140,163,140,193,240,80,108,186,233,166,238,51,104,76,142,185,75,5,55,199,10,57,236,255,23,95,124,113,193,109,168,98,101,35,32,197,179,
178,239,95,228,222,179,114,69,186,20,94,94,105,21,148,76,2,243,189,149,76,250,137,146,201,74,45,74,230,106,171,173,150,214,174,87,125,191,136,145,125,244,209,71,93,76,143,223,197,190,248,226,139,230,235,
175,191,54,221,187,119,159,167,8,113,45,16,80,112,127,73,104,46,17,2,66,64,8,8,129,210,34,128,199,9,140,226,228,242,92,122,233,165,231,57,57,44,238,132,84,112,44,151,144,243,18,6,220,75,47,189,52,215,
97,237,43,33,2,40,163,176,195,67,222,199,39,30,70,176,239,51,79,106,223,190,125,106,243,167,226,57,197,243,247,196,19,79,148,16,45,157,42,77,8,72,241,76,211,221,40,65,95,176,84,158,116,210,73,102,210,
164,73,37,56,91,240,41,176,220,121,238,178,31,127,252,177,171,128,146,9,243,153,183,146,25,220,138,74,148,18,129,167,159,126,218,124,254,249,231,230,240,195,15,207,121,218,51,207,60,211,92,116,209,69,
243,144,77,176,90,122,214,89,103,57,162,33,242,199,98,113,151,8,1,33,32,4,132,64,105,17,120,237,181,215,204,79,63,253,100,30,121,228,17,115,250,233,167,207,71,242,66,110,229,222,189,123,207,231,17,197,
88,13,41,28,241,161,34,227,43,237,61,11,123,54,140,186,16,24,49,207,131,155,1,129,193,24,69,116,147,77,54,41,42,101,78,216,62,4,149,123,254,249,231,93,90,31,226,90,37,181,137,128,20,207,26,187,239,131,
6,13,114,241,157,36,143,46,181,96,145,99,197,12,119,17,2,233,189,152,76,220,101,113,23,33,134,33,151,251,79,169,251,169,243,5,35,112,205,53,215,152,14,29,58,184,45,187,244,239,191,255,238,92,104,80,60,
61,153,51,103,142,233,219,183,175,155,176,64,35,143,187,46,249,228,36,66,64,8,8,1,33,80,90,4,80,72,32,222,219,124,243,205,205,169,167,158,106,78,57,229,20,23,170,226,245,2,111,163,151,94,122,201,28,118,
216,97,222,46,247,121,238,185,231,186,216,60,248,19,162,8,171,168,127,254,249,103,148,42,102,169,165,150,138,84,94,133,253,17,248,238,187,239,220,253,132,112,145,116,38,184,228,66,178,184,217,102,155,
153,181,214,90,171,228,115,46,188,161,32,22,98,149,86,82,155,8,72,241,172,177,251,142,11,205,59,239,188,99,6,14,28,152,248,149,19,32,143,27,72,118,76,2,47,60,47,38,65,74,102,226,183,160,238,4,40,127,36,
16,135,212,39,142,88,16,140,6,199,28,115,140,115,185,106,212,168,81,221,121,48,104,44,177,196,18,102,219,109,183,117,251,40,119,252,241,199,59,247,45,226,58,16,98,140,72,233,35,17,2,66,64,8,8,129,210,
34,240,253,247,223,59,143,167,221,118,219,205,160,20,226,1,197,188,32,155,243,1,133,244,170,171,174,170,235,216,11,47,188,224,210,173,144,54,37,170,92,113,197,21,243,229,113,14,106,131,213,85,177,207,
7,161,84,216,113,198,100,22,0,8,137,193,0,129,224,114,141,33,153,248,222,164,185,23,56,63,243,64,20,97,173,156,23,118,15,43,189,150,20,207,74,191,131,17,251,127,224,129,7,186,188,81,48,219,197,41,36,77,
102,37,19,226,1,172,155,40,149,172,96,242,34,99,69,83,131,72,156,104,71,111,235,232,163,143,54,119,220,113,135,193,250,153,173,40,70,111,105,110,13,226,125,112,203,98,5,211,19,38,38,60,91,94,10,149,187,
239,190,219,197,156,96,93,245,132,9,13,19,27,137,16,16,2,66,64,8,148,22,1,120,30,200,231,185,215,94,123,185,19,255,240,195,15,6,229,48,59,110,147,112,9,148,81,140,148,140,231,164,95,123,232,161,135,92,
12,97,212,222,226,218,139,146,19,69,48,106,202,48,29,5,177,226,202,194,191,192,61,98,14,247,219,111,191,185,251,78,190,77,148,209,85,86,89,165,184,198,115,212,198,245,151,185,193,6,27,108,144,227,168,
118,85,59,2,82,60,171,253,14,215,187,62,254,225,33,15,216,101,151,93,234,29,9,255,115,230,204,153,238,5,133,143,62,174,149,12,16,205,155,55,119,49,153,188,172,60,165,35,124,139,42,153,52,2,73,40,158,244,
153,56,33,168,221,61,34,33,38,44,151,93,118,153,187,28,226,136,80,74,137,237,204,22,142,83,78,34,4,132,128,16,16,2,165,69,0,46,5,86,155,246,222,123,239,186,19,143,31,63,222,41,28,222,188,224,222,123,239,
117,174,152,235,174,187,174,99,39,199,45,87,121,23,235,224,170,250,47,172,56,19,43,138,203,53,121,183,9,147,98,85,20,111,53,22,19,178,87,199,11,1,131,124,177,199,29,119,156,115,221,46,164,190,234,84,54,
2,82,60,43,251,254,69,238,61,3,9,238,144,248,246,135,17,252,241,97,151,205,86,50,155,53,107,230,148,204,141,54,218,40,21,193,234,97,174,163,214,203,36,165,120,130,43,214,233,171,175,190,218,52,108,216,
208,177,214,122,52,233,172,108,30,114,200,33,142,220,32,27,127,226,63,11,113,217,202,110,67,223,133,128,16,16,2,66,32,58,2,211,166,77,115,202,68,215,174,93,231,169,12,227,56,70,105,200,253,24,243,81,56,
96,192,199,59,229,158,123,238,153,167,172,126,212,30,2,172,138,98,176,224,217,96,149,28,151,89,188,167,136,249,101,139,162,140,146,255,21,47,168,147,79,62,185,246,128,212,21,27,41,158,53,244,16,192,120,
134,226,249,238,187,239,186,193,165,254,165,195,84,202,139,133,124,153,30,25,0,49,129,176,203,178,146,185,248,226,139,215,175,162,223,41,66,96,226,196,137,206,64,128,37,177,190,228,83,60,153,96,244,239,
223,223,77,48,136,207,140,42,196,137,144,98,133,9,10,238,90,184,218,254,252,243,207,110,181,179,95,191,126,243,53,119,254,249,231,27,136,42,36,66,64,8,8,1,33,80,90,4,136,215,100,124,223,126,251,237,231,
57,49,92,12,112,50,28,124,240,193,46,36,3,215,90,226,65,247,221,119,95,55,111,152,167,112,132,31,204,41,162,178,232,195,11,32,87,219,8,32,151,169,40,207,7,174,212,108,40,163,8,243,68,92,104,97,209,93,
121,229,149,115,246,12,54,101,120,39,8,255,145,212,30,2,82,60,107,228,158,243,79,206,0,0,131,29,22,43,88,101,177,124,18,100,142,91,5,47,249,85,87,93,213,189,44,200,3,37,119,217,202,123,48,112,133,154,
60,121,178,51,28,172,189,246,218,243,92,64,62,197,147,248,157,135,31,126,216,64,115,190,229,150,91,206,83,47,236,15,44,229,76,88,88,77,135,177,246,182,219,110,51,187,239,190,187,115,193,174,223,198,255,
253,223,255,153,11,46,184,160,254,110,253,22,2,66,64,8,8,129,132,17,224,29,13,209,27,46,147,245,133,176,8,98,59,89,205,226,29,141,50,65,222,206,98,68,228,66,197,160,87,121,117,137,17,133,25,25,47,57,184,
63,120,150,16,230,151,44,96,144,42,111,248,240,225,46,174,120,200,144,33,6,15,58,242,143,74,106,7,1,41,158,85,114,175,249,231,198,45,246,195,15,63,116,52,213,252,211,179,178,9,153,12,177,118,196,225,65,
81,78,78,39,92,28,90,180,104,225,148,76,86,64,69,252,83,29,15,1,134,4,98,48,118,221,117,215,249,146,51,251,41,158,172,146,118,236,216,209,236,183,223,126,142,60,162,80,36,102,207,158,237,86,56,137,245,
61,234,168,163,76,190,85,77,220,108,179,211,173,20,122,78,213,19,2,66,64,8,8,129,104,8,220,127,255,253,46,149,10,115,128,250,242,248,227,143,59,230,115,184,32,136,235,196,128,184,241,198,27,215,47,22,
233,55,158,86,108,81,164,16,207,155,40,237,171,108,105,17,96,126,74,26,31,226,70,201,170,192,124,97,220,184,113,46,189,203,47,191,252,226,22,58,136,33,101,133,212,83,78,121,62,9,9,19,243,109,105,239,85,
41,206,38,197,179,20,40,39,116,14,254,153,9,254,190,243,206,59,221,63,49,46,14,248,220,243,210,110,217,178,165,115,145,109,213,170,149,97,245,43,46,38,211,132,46,69,205,198,132,192,145,71,30,105,238,186,
235,46,51,122,244,104,67,0,191,39,185,20,79,8,3,48,66,224,98,197,96,128,69,178,24,193,82,206,224,1,77,63,238,92,61,123,246,204,217,28,177,68,94,28,104,206,2,218,41,4,132,128,16,16,2,137,32,64,58,43,188,
83,114,197,228,225,130,75,108,62,239,104,92,113,159,121,230,153,68,250,160,70,133,128,135,192,191,255,254,107,62,251,236,51,183,104,130,203,46,6,116,8,44,89,57,69,65,229,57,133,43,226,128,3,14,48,77,154,
52,241,170,233,179,130,17,144,226,89,161,55,111,196,136,17,110,242,14,221,57,129,221,199,30,123,172,75,91,82,161,151,163,110,199,132,192,172,89,179,156,209,129,149,71,86,189,89,233,70,114,41,158,196,117,
146,36,156,120,75,92,101,139,21,216,18,137,11,106,218,180,169,115,179,229,51,151,120,238,92,185,142,105,159,16,16,2,66,64,8,36,135,0,222,40,132,59,248,197,80,50,22,144,103,121,216,176,97,230,208,67,15,
77,174,35,106,89,8,4,32,128,33,4,183,92,242,206,195,65,66,220,40,46,224,126,177,163,1,205,233,112,74,16,144,226,153,146,27,17,182,27,184,172,176,146,196,42,21,36,46,4,254,75,132,64,54,2,48,204,66,244,
115,195,13,55,152,222,189,123,187,67,19,38,76,112,207,12,19,9,226,119,33,255,97,85,28,6,67,92,178,227,114,109,34,30,136,20,59,185,72,133,188,62,114,44,59,103,156,183,95,159,66,64,8,8,1,33,144,44,2,40,
150,249,12,141,132,65,172,179,206,58,166,75,151,46,102,153,101,150,41,186,51,40,13,140,69,81,4,79,46,140,234,18,33,224,33,0,79,9,28,37,99,199,142,117,94,93,157,59,119,246,14,233,179,194,16,144,226,89,
97,55,12,22,48,94,226,16,4,137,0,168,194,110,94,137,186,251,215,95,127,153,211,78,59,205,81,149,175,190,250,234,57,207,138,123,11,20,249,184,174,116,235,214,45,103,153,66,118,66,82,68,18,106,220,181,252,
132,24,79,172,238,138,45,246,67,72,251,133,128,16,16,2,201,32,16,164,120,18,186,3,55,68,92,185,150,137,27,37,174,52,138,12,26,52,72,138,103,20,192,106,168,44,207,6,105,88,96,211,87,166,133,202,188,241,
82,60,43,232,190,17,211,9,35,216,229,151,95,238,92,25,43,168,235,234,106,141,32,64,174,47,92,105,111,190,249,102,223,43,190,245,214,91,93,28,232,42,171,172,226,91,70,7,132,128,16,16,2,66,32,126,4,130,
20,79,82,99,193,70,122,210,73,39,197,127,114,181,40,4,98,64,128,248,99,188,253,8,33,146,84,30,2,82,60,43,232,158,65,24,67,208,63,171,157,18,33,144,86,4,112,183,205,55,105,25,51,102,140,163,79,239,212,
169,83,90,47,65,253,18,2,66,64,8,84,29,2,120,186,64,2,71,152,142,159,160,120,174,185,230,154,142,156,208,175,140,246,11,129,114,34,48,106,212,40,23,135,76,152,144,92,178,203,121,39,10,59,183,20,207,194,
112,43,75,45,114,44,238,181,215,94,166,111,223,190,101,57,191,78,42,4,194,32,112,205,53,215,184,65,193,207,149,22,146,0,140,40,164,93,145,8,1,33,32,4,132,64,105,16,128,0,14,198,241,131,14,58,200,247,132,
183,220,114,139,57,226,136,35,148,91,209,23,33,29,72,3,2,164,142,131,24,145,124,225,146,202,66,64,138,103,133,220,47,242,31,225,90,0,83,169,146,237,86,200,77,171,209,110,194,66,183,210,74,43,249,90,204,
113,25,199,221,139,56,79,137,16,16,2,66,64,8,148,6,129,39,159,124,210,44,191,252,242,46,141,150,223,25,47,188,240,194,188,43,162,126,245,180,95,8,148,18,129,27,111,188,209,60,248,224,131,230,197,23,95,
44,229,105,117,174,24,16,144,226,25,3,136,165,104,2,165,147,201,60,110,140,18,33,144,102,4,190,254,250,107,71,197,79,138,31,63,193,213,139,9,142,68,8,8,1,33,32,4,74,131,0,140,231,228,122,38,223,178,159,
144,106,133,148,21,18,33,144,102,4,200,240,64,122,149,251,238,187,207,165,20,76,115,95,213,183,121,17,144,226,57,47,30,169,252,53,99,198,12,179,237,182,219,154,41,83,166,152,229,150,91,46,149,125,84,167,
132,64,54,2,65,147,23,40,251,97,222,21,51,115,54,106,250,46,4,132,128,16,72,14,1,92,19,243,121,154,144,7,250,145,71,30,49,39,156,112,66,114,157,80,203,66,32,38,4,96,94,126,231,157,119,12,204,201,146,202,
65,64,138,103,5,220,171,227,143,63,222,252,242,203,47,230,222,123,239,173,128,222,170,139,105,68,224,159,127,254,49,95,124,241,133,249,228,147,79,204,175,191,254,106,86,91,109,53,183,197,145,167,45,215,
245,6,41,158,35,71,142,52,141,27,55,206,235,242,149,171,93,237,19,2,66,64,8,8,129,194,16,8,122,47,143,24,49,194,165,216,218,108,179,205,10,59,65,158,90,164,104,249,240,195,15,221,246,237,183,223,58,151,
95,86,172,90,183,110,109,22,88,96,129,60,53,117,72,8,228,70,128,124,228,237,219,183,55,132,247,180,104,209,34,119,33,237,77,29,2,82,60,83,119,75,230,237,208,236,217,179,77,135,14,29,204,132,9,19,156,171,
237,188,71,245,75,8,228,71,128,216,96,94,202,228,246,36,167,231,26,107,172,225,86,25,223,126,251,109,195,134,108,181,213,86,166,107,215,174,177,178,195,145,242,7,171,121,195,134,13,115,118,144,137,199,
3,15,60,224,72,136,114,22,208,78,33,32,4,132,128,16,136,13,129,223,127,255,221,133,234,244,235,215,207,183,205,139,47,190,216,156,122,234,169,177,122,162,64,102,52,116,232,80,151,183,121,195,13,55,52,
27,109,180,145,105,222,188,185,203,21,202,188,230,189,247,222,51,235,172,179,142,217,103,159,125,242,186,0,251,118,90,7,106,26,1,22,102,72,227,22,53,87,108,77,131,86,230,139,151,226,89,230,27,16,116,250,
83,78,57,197,229,212,122,248,225,135,131,138,234,184,16,168,67,128,85,77,38,17,12,240,176,199,46,188,240,194,117,199,234,127,25,55,110,156,115,175,34,41,115,203,150,45,235,31,46,232,55,41,83,72,238,220,
177,99,71,223,250,65,214,119,223,138,58,32,4,132,128,16,16,2,145,16,152,52,105,146,249,233,167,159,204,78,59,237,228,91,47,206,119,50,171,81,151,94,122,169,203,61,222,163,71,143,188,171,154,115,230,204,
49,87,94,121,165,217,102,155,109,76,151,46,93,124,251,167,3,66,160,62,2,223,127,255,189,217,98,139,45,12,115,142,85,87,93,181,254,97,253,78,33,2,82,60,83,120,83,188,46,177,42,196,106,231,216,177,99,157,
91,164,183,95,159,66,32,31,2,12,226,231,156,115,142,99,38,108,218,180,105,190,162,117,199,200,239,6,225,207,126,251,237,231,44,210,117,7,10,252,194,96,128,107,56,202,172,159,196,57,201,241,59,135,246,
11,1,33,32,4,132,128,49,215,94,123,173,57,248,224,131,77,163,70,141,114,194,17,39,219,56,74,39,43,171,196,147,194,162,27,86,6,12,24,224,20,84,250,41,17,2,97,17,56,230,152,99,12,43,250,10,71,11,139,88,
121,203,73,241,44,47,254,121,207,78,190,78,24,66,31,122,232,161,188,229,116,80,8,120,8,192,244,134,178,7,121,207,178,203,46,235,237,14,245,201,196,131,201,2,47,113,220,114,139,149,32,197,146,124,113,123,
238,185,167,89,113,197,21,139,61,149,234,11,1,33,32,4,132,64,30,4,130,152,196,63,248,224,3,51,121,242,100,211,171,87,175,60,173,4,31,250,207,127,254,227,114,141,99,252,36,142,63,170,192,82,218,164,73,
19,179,243,206,59,71,173,170,242,53,138,0,241,195,132,12,141,26,53,42,150,185,75,141,194,88,178,203,150,226,89,50,168,163,157,104,230,204,153,102,235,173,183,54,207,62,251,172,89,121,229,149,163,85,86,
233,154,69,0,186,252,221,118,219,205,197,204,20,2,2,138,43,6,15,210,246,44,180,208,66,133,52,81,87,39,72,241,124,245,213,87,205,103,159,125,230,148,207,186,74,250,34,4,132,128,16,16,2,177,34,128,81,17,
70,219,124,105,82,136,185,223,116,211,77,11,30,59,188,14,223,118,219,109,142,240,165,77,155,54,222,174,200,159,167,159,126,186,203,245,188,196,18,75,68,174,171,10,181,137,0,156,18,40,160,90,168,73,255,
253,151,226,153,210,123,116,196,17,71,24,220,31,251,247,239,159,210,30,170,91,105,67,128,248,29,220,169,152,96,20,35,175,188,242,138,121,247,221,119,77,207,158,61,139,105,198,245,229,144,67,14,241,77,
1,4,211,238,37,151,92,98,80,80,37,66,64,8,8,1,33,144,12,2,188,207,167,78,157,106,14,60,240,64,223,19,48,110,156,119,222,121,121,99,49,125,43,255,239,0,36,47,215,92,115,77,222,148,45,65,109,112,252,211,
79,63,117,164,120,189,123,247,14,83,92,101,132,128,35,24,34,214,243,177,199,30,51,173,90,181,18,34,41,70,64,138,103,10,111,206,71,31,125,100,118,221,117,87,3,27,92,33,174,42,41,188,36,117,169,4,8,220,
121,231,157,102,251,237,183,55,107,174,185,102,209,103,195,229,22,98,136,98,4,198,194,63,255,252,211,116,238,220,217,183,153,160,85,81,223,138,58,32,4,132,128,16,16,2,161,16,32,246,109,203,45,183,204,
155,114,34,142,119,241,29,119,220,97,118,216,97,135,212,140,65,161,192,81,161,170,65,224,172,179,206,50,211,166,77,115,46,183,85,115,81,85,120,33,82,60,83,120,83,73,109,65,78,34,44,135,18,33,16,22,1,98,
106,136,237,140,67,88,137,196,229,118,177,197,22,43,184,57,114,207,18,199,137,219,148,159,224,250,197,96,209,160,65,3,191,34,218,47,4,132,128,16,16,2,69,32,128,82,9,209,143,95,190,76,210,109,93,113,197,
21,142,148,174,136,211,56,239,149,124,238,188,81,218,30,56,112,160,203,243,28,23,211,122,148,115,171,108,101,34,240,199,31,127,56,55,239,91,111,189,213,25,90,42,243,42,170,191,215,82,60,83,118,143,95,
126,249,101,115,232,161,135,154,41,83,166,24,197,55,164,236,230,164,188,59,184,74,49,185,136,67,70,142,28,233,86,219,139,77,36,30,100,69,39,191,27,68,70,36,18,151,8,1,33,32,4,132,64,252,8,4,189,135,9,
175,248,234,171,175,92,62,231,98,206,30,116,158,40,109,191,245,214,91,230,157,119,222,113,249,61,163,212,83,217,218,70,224,198,27,111,52,24,45,152,67,75,210,137,128,20,207,148,221,23,220,84,58,117,234,
84,180,229,49,101,151,165,238,148,0,1,226,115,216,226,144,111,190,249,198,197,74,144,156,185,24,9,154,136,48,217,121,252,241,199,205,177,199,30,91,204,105,84,87,8,8,1,33,32,4,114,32,240,219,111,191,153,
27,110,184,193,156,121,230,153,57,142,254,119,23,158,41,221,187,119,55,205,154,53,243,45,19,116,128,52,94,247,220,115,143,243,148,9,42,27,230,56,140,254,195,135,15,119,121,168,195,148,87,25,33,0,2,176,
42,183,107,215,206,133,10,41,39,108,58,159,9,41,158,41,186,47,176,124,30,116,208,65,142,4,96,209,69,23,77,81,207,212,149,74,64,32,78,197,147,235,13,82,26,195,96,114,243,205,55,155,189,246,218,43,239,132,
38,142,243,132,233,139,202,8,1,33,32,4,106,13,129,231,159,127,222,224,130,152,116,172,253,152,49,99,204,226,139,47,110,58,118,236,24,11,196,164,119,97,213,42,31,33,82,44,39,82,35,85,135,0,134,20,226,154,
95,122,233,165,170,187,182,106,184,32,41,158,41,186,139,59,237,180,147,243,79,143,43,70,34,69,151,166,174,148,0,129,184,21,184,56,218,99,226,48,107,214,44,151,226,197,15,130,56,206,227,215,182,246,11,
1,33,32,4,106,25,1,184,34,8,223,89,110,185,229,124,97,136,227,29,12,25,221,137,39,158,24,91,136,16,171,157,77,155,54,117,115,34,223,142,235,128,16,200,129,0,25,33,72,13,196,179,191,237,182,219,230,40,
161,93,229,68,64,138,103,57,209,207,58,247,155,111,190,105,246,219,111,63,183,218,137,213,80,34,4,162,34,16,148,32,60,106,123,151,93,118,153,129,206,190,97,195,134,81,171,214,149,135,213,246,170,171,174,
50,103,159,125,118,221,190,250,95,72,1,115,240,193,7,155,70,141,26,213,63,164,223,66,64,8,8,1,33,80,4,2,65,74,37,41,80,238,186,235,46,115,202,41,167,20,113,22,99,226,30,127,32,202,131,152,110,145,69,22,
41,170,95,170,92,155,8,48,175,32,181,202,196,137,19,107,19,128,20,95,181,20,207,148,220,156,61,246,216,195,37,110,134,89,78,34,4,10,65,0,183,214,189,247,222,219,89,137,11,169,95,191,206,83,79,61,101,150,
92,114,201,162,217,225,130,38,62,147,38,77,50,228,32,101,197,95,34,4,132,128,16,16,2,241,33,16,244,254,125,230,153,103,28,171,248,54,219,108,83,240,73,51,153,140,203,31,29,167,183,86,80,191,11,238,172,
42,214,4,2,228,9,111,211,166,141,185,237,182,219,12,249,61,37,233,65,64,138,103,10,238,197,251,239,191,239,216,228,96,150,99,162,47,17,2,133,32,64,60,195,183,223,126,235,114,192,22,82,191,126,29,218,122,
240,193,7,77,159,62,125,234,31,138,244,59,104,2,65,252,17,46,49,164,85,145,8,1,33,32,4,132,64,60,8,16,230,240,200,35,143,152,19,78,56,193,183,65,140,221,199,29,119,92,81,115,15,114,143,147,119,28,207,
149,56,4,130,24,148,216,184,200,242,226,232,147,218,168,60,4,46,190,248,98,131,97,229,217,103,159,173,188,206,87,113,143,165,120,166,224,230,238,191,255,254,166,73,147,38,6,26,104,137,16,40,20,129,36,
20,184,32,165,49,76,95,239,190,251,110,179,253,246,219,187,180,41,126,229,227,56,143,95,219,218,47,4,132,128,16,168,69,4,70,140,24,97,86,88,97,133,188,113,146,113,188,123,49,80,178,186,180,238,186,235,
198,2,243,219,111,191,109,94,127,253,117,115,192,1,7,196,210,158,26,169,77,4,8,245,225,185,188,255,254,251,149,178,45,69,143,128,20,207,50,223,140,207,63,255,220,144,66,133,213,170,124,193,255,101,238,
166,78,95,33,8,196,49,137,200,190,212,56,218,123,227,141,55,12,171,250,184,1,251,9,57,72,177,110,251,37,56,247,171,167,253,66,64,8,8,1,33,144,27,1,86,124,78,61,245,84,147,143,37,63,142,119,124,220,239,
239,254,253,251,27,92,127,215,92,115,205,220,23,166,189,66,32,36,2,253,250,245,51,112,168,96,132,145,164,3,1,41,158,101,190,15,71,29,117,148,193,23,157,252,87,18,33,80,44,2,113,76,34,178,251,112,229,149,
87,154,99,142,57,198,44,181,212,82,217,187,35,125,231,249,102,2,196,228,196,79,30,120,224,1,199,66,183,206,58,235,248,21,209,126,33,32,4,132,128,16,136,128,64,208,120,48,99,198,12,243,228,147,79,22,157,
43,51,110,98,161,160,126,71,128,64,69,107,28,129,95,127,253,213,180,109,219,214,229,11,215,252,34,29,15,131,20,207,50,222,7,226,47,58,116,232,96,32,87,129,54,92,34,4,138,69,224,246,219,111,119,169,75,
154,55,111,94,108,83,174,126,28,196,19,52,20,52,145,248,240,195,15,29,251,92,92,49,66,177,92,188,26,17,2,66,64,8,84,40,2,16,254,224,69,114,254,249,231,251,94,193,144,33,67,220,170,226,198,27,111,236,91,
38,232,64,24,230,242,160,54,234,31,15,26,47,234,151,215,111,33,144,15,1,216,249,191,251,238,59,199,89,145,175,156,142,149,6,1,41,158,165,193,57,231,89,206,56,227,12,243,201,39,159,184,224,255,156,5,180,
83,8,68,68,96,234,212,169,6,43,54,44,201,113,200,15,63,252,96,112,123,234,219,183,111,81,205,177,218,201,182,224,130,11,230,108,39,9,86,196,156,39,210,78,33,32,4,132,64,13,32,240,193,7,31,152,201,147,
39,155,94,189,122,249,94,45,4,62,144,186,53,104,208,192,183,76,208,129,184,73,237,88,161,130,239,226,204,51,207,12,58,181,142,11,129,80,8,48,143,105,223,190,189,25,55,110,156,89,121,229,149,67,213,81,
161,228,16,144,226,153,28,182,121,91,254,249,231,159,205,70,27,109,100,158,126,250,105,179,214,90,107,229,45,171,131,66,32,44,2,127,253,245,151,129,165,240,156,115,206,9,91,37,176,92,28,214,231,48,174,
180,113,156,39,240,98,84,64,8,8,1,33,80,3,8,148,234,157,123,195,13,55,56,18,32,8,18,227,144,9,19,38,24,198,49,184,47,36,66,32,46,4,240,166,34,107,4,105,231,36,229,69,64,138,103,153,240,191,252,242,203,
13,47,216,145,35,71,150,169,7,58,109,181,34,16,183,2,23,71,123,239,189,247,158,121,249,229,151,77,207,158,61,125,97,191,236,178,203,92,234,150,37,150,88,194,183,140,14,8,1,33,32,4,132,64,48,2,65,132,63,
113,165,44,137,99,124,200,190,154,171,175,190,218,28,113,196,17,102,153,101,150,201,222,93,241,223,193,251,251,239,191,55,179,103,207,118,27,233,202,248,254,247,223,127,155,198,141,27,187,204,6,40,239,
124,103,91,100,145,69,42,254,154,211,116,1,120,130,109,189,245,214,134,180,133,141,26,53,74,83,215,106,174,47,82,60,203,112,203,177,230,181,106,213,202,12,26,52,200,17,170,148,161,11,58,101,21,35,16,247,
68,128,28,155,135,29,118,152,89,118,217,101,11,70,45,76,188,17,171,255,139,45,182,152,233,216,177,99,193,231,81,69,33,32,4,132,128,16,8,142,171,39,101,9,140,227,164,115,43,70,226,30,111,226,110,175,152,
107,43,182,46,220,5,240,36,124,245,213,87,102,206,156,57,142,164,111,165,149,86,50,108,43,174,184,162,251,132,113,152,227,108,95,127,253,181,251,132,255,131,44,7,40,223,140,135,144,227,44,180,208,66,197,
118,167,230,235,239,185,231,158,102,195,13,55,204,27,247,92,243,32,149,0,0,41,158,37,0,185,254,41,96,176,189,239,190,251,204,248,241,227,235,31,210,111,33,80,52,2,228,205,196,77,105,181,213,86,43,186,
45,26,120,238,185,231,28,243,50,185,56,139,145,160,9,5,3,51,125,63,229,148,83,138,57,141,234,10,1,33,32,4,106,26,1,140,219,120,85,193,54,235,39,3,6,12,112,43,64,197,164,44,97,197,238,225,135,31,54,144,
183,196,37,65,227,68,92,231,73,170,29,148,70,22,21,62,251,236,51,23,70,213,181,107,87,83,40,217,223,47,191,252,98,70,143,30,237,98,117,81,68,81,156,90,183,110,157,84,215,171,190,221,233,211,167,155,221,
119,223,221,240,185,248,226,139,87,253,245,166,245,2,165,120,150,248,206,176,242,195,139,131,52,21,187,237,182,91,137,207,174,211,213,2,2,36,222,198,210,186,215,94,123,197,114,185,63,253,244,147,129,45,
247,180,211,78,43,170,189,48,68,22,149,62,233,40,10,32,85,22,2,66,64,8,196,128,0,238,132,172,160,161,244,248,73,28,239,90,66,133,112,11,221,108,179,205,252,78,19,105,255,151,95,126,233,242,45,30,125,244,
209,145,234,165,161,240,55,223,124,99,238,184,227,14,179,240,194,11,155,195,15,63,220,185,206,198,217,47,216,131,31,124,240,65,243,206,59,239,152,3,15,60,208,113,132,196,217,126,173,180,133,81,190,123,
247,238,230,184,227,142,171,149,75,78,221,117,74,241,44,241,45,25,62,124,184,185,232,162,139,12,76,112,18,33,144,4,2,228,205,188,228,146,75,92,10,147,184,218,143,99,146,50,120,240,96,211,162,69,139,188,
3,102,28,231,137,235,154,213,142,16,16,2,66,160,18,17,184,229,150,91,220,234,24,238,156,126,18,199,187,150,185,12,6,73,220,69,227,144,56,210,187,196,209,143,40,109,252,246,219,111,230,214,91,111,53,191,
255,254,187,57,254,248,227,157,139,108,148,250,81,203,50,190,223,123,239,189,206,184,140,242,180,202,42,171,68,109,162,166,203,227,250,124,236,177,199,58,5,94,238,203,229,121,20,164,120,150,24,119,44,
131,135,30,122,168,57,230,152,99,74,124,102,157,174,150,16,136,99,82,145,141,87,28,9,194,113,61,34,142,19,226,8,63,185,237,182,219,156,43,76,161,174,73,126,237,106,191,16,16,2,66,160,86,16,8,122,255,255,
241,199,31,134,216,125,82,169,20,35,65,231,137,218,118,24,175,152,168,109,38,89,126,212,168,81,102,236,216,177,142,20,47,174,208,150,176,253,69,225,189,238,186,235,92,220,40,138,84,49,41,113,194,158,179,
90,202,109,177,197,22,46,164,39,46,175,176,106,193,165,84,215,33,197,179,84,72,219,243,76,153,50,197,77,186,95,125,245,85,189,36,74,136,123,45,158,42,136,209,48,42,38,80,230,247,232,209,195,185,85,69,
173,155,93,62,104,162,50,109,218,52,151,219,22,87,24,137,16,16,2,66,64,8,68,71,32,232,61,251,226,139,47,26,114,27,238,178,203,46,209,27,207,170,193,56,115,254,249,231,103,237,41,238,107,80,191,139,107,
61,190,218,228,26,197,171,168,93,187,118,166,91,183,110,241,53,92,64,75,196,43,178,226,74,174,237,98,226,117,11,56,117,197,86,33,190,153,92,177,228,61,151,148,30,1,41,158,37,196,156,160,102,24,181,46,
190,248,226,18,158,85,167,170,69,4,112,197,217,106,171,173,98,203,17,59,108,216,48,179,250,234,171,155,141,55,222,184,40,56,131,38,22,73,184,9,23,213,97,85,22,2,66,64,8,84,16,2,63,254,248,163,185,243,
206,59,205,169,167,158,234,219,235,56,12,137,196,28,178,106,218,175,95,63,223,243,68,57,192,187,159,185,17,202,108,154,5,207,29,56,58,200,149,221,172,89,179,84,116,149,148,44,23,94,120,161,99,192,237,
220,185,115,42,250,148,230,78,144,218,166,77,155,54,46,167,231,150,91,110,153,230,174,86,101,223,164,120,150,232,182,126,250,233,167,102,199,29,119,116,22,22,146,216,74,132,64,146,8,96,5,125,235,173,183,
204,126,251,237,23,203,105,30,127,252,113,179,234,170,171,154,77,54,217,164,168,246,152,88,192,90,75,218,20,63,9,82,78,253,234,105,191,16,16,2,66,160,214,17,32,134,141,216,181,78,157,58,249,66,17,199,
59,22,230,220,171,174,186,170,104,119,93,175,147,113,147,226,121,237,198,249,249,193,7,31,184,213,69,114,78,199,145,103,243,223,127,255,53,31,125,244,145,105,217,178,101,44,221,36,84,165,105,211,166,46,
190,55,150,6,171,184,145,243,206,59,207,177,5,195,26,44,41,45,2,82,60,75,132,55,65,231,184,103,176,196,47,17,2,73,35,192,128,6,241,67,92,214,227,155,111,190,217,236,189,247,222,110,80,43,166,239,35,70,
140,112,108,127,249,88,16,113,221,194,154,172,192,255,98,144,86,93,33,32,4,106,17,129,43,174,184,194,49,118,230,51,112,199,161,120,130,109,92,237,208,22,105,230,182,219,110,59,231,89,195,239,180,9,57,
54,193,22,101,59,174,177,9,23,217,129,3,7,154,137,19,39,154,5,22,88,32,150,75,70,249,92,123,237,181,77,177,233,207,98,233,76,138,27,97,62,78,126,84,152,153,215,90,107,173,20,247,180,10,187,102,211,123,
72,18,70,192,230,39,204,172,177,198,26,153,207,63,255,60,225,51,169,121,33,48,23,1,75,8,52,247,71,145,223,206,62,251,236,34,91,248,111,245,153,51,103,102,110,186,233,166,188,109,61,250,232,163,153,215,
94,123,45,111,25,29,20,2,66,64,8,8,129,249,17,8,122,239,127,247,221,119,153,107,175,189,118,254,138,5,236,177,228,68,5,212,202,93,197,26,27,51,214,5,50,247,193,50,239,181,68,62,25,187,120,144,225,51,46,
177,49,182,25,155,138,38,99,213,138,140,85,62,227,106,214,181,99,87,243,50,54,159,104,172,109,86,99,99,54,237,77,230,200,35,143,172,198,75,75,245,53,153,84,247,174,74,58,103,227,1,50,54,136,191,74,174,
70,151,81,41,8,216,4,226,153,239,191,255,190,232,238,50,216,50,144,197,37,65,19,35,12,52,54,111,104,92,167,83,59,66,64,8,8,129,154,65,32,232,253,106,93,11,51,47,188,240,66,44,120,60,246,216,99,153,201,
147,39,23,221,150,101,217,205,196,101,220,44,186,51,57,26,56,227,140,51,50,54,199,104,142,35,133,239,58,233,164,147,156,210,137,226,105,89,220,51,63,255,252,115,225,141,213,171,105,227,101,51,189,123,
247,206,240,41,241,71,128,123,202,162,16,70,0,73,233,16,144,226,153,48,214,252,227,219,220,133,25,235,74,145,240,153,212,188,16,152,23,1,94,170,40,159,197,138,117,221,201,188,247,222,123,197,54,83,87,
63,104,98,68,193,48,101,234,26,212,23,33,32,4,132,128,16,200,124,241,197,23,25,222,215,249,196,178,177,102,172,155,97,190,34,161,143,89,82,155,140,141,217,15,93,222,175,160,77,11,18,235,24,227,119,158,
66,246,247,239,223,63,51,126,252,248,66,170,250,214,121,247,221,119,51,11,47,188,112,157,226,137,242,25,231,234,49,39,126,231,157,119,50,54,22,213,183,15,58,240,95,4,118,221,117,87,225,84,226,135,65,49,
158,9,187,79,15,30,60,216,49,191,225,195,47,17,2,165,70,0,246,66,72,38,96,83,46,68,190,249,230,27,71,59,78,188,104,92,66,156,12,121,199,150,90,106,41,223,38,227,140,29,242,61,137,14,8,1,33,32,4,170,8,
129,33,67,134,24,187,130,147,151,4,46,238,119,43,113,251,200,110,187,237,86,16,146,144,224,65,240,146,143,133,183,160,134,99,168,4,153,208,208,161,67,205,233,167,159,30,67,107,115,155,176,202,142,121,
242,201,39,231,238,176,223,32,220,131,20,48,206,148,40,247,221,119,159,123,30,58,118,236,56,207,185,244,99,46,2,164,22,58,232,160,131,140,85,212,149,230,112,46,44,201,126,43,177,162,91,115,167,179,121,
158,50,150,218,188,230,174,91,23,156,14,4,44,201,80,198,230,247,202,204,152,49,35,114,135,176,138,31,119,220,113,177,186,0,209,137,167,159,126,58,208,130,108,149,211,204,79,63,253,20,185,207,170,32,4,
132,128,16,168,85,4,44,49,91,134,85,200,124,146,132,55,137,77,229,145,177,57,17,243,157,54,231,49,188,114,78,60,241,196,84,186,132,50,118,226,174,106,217,123,115,246,189,208,157,163,70,141,170,91,233,
180,12,180,25,155,31,187,238,183,205,9,90,104,179,190,245,78,62,249,228,216,86,184,125,79,82,225,7,182,216,98,139,12,220,18,146,210,32,32,87,219,4,113,230,69,188,254,250,235,7,14,4,9,118,65,77,11,129,
204,239,191,255,158,97,240,177,214,219,208,104,204,158,61,59,115,194,9,39,100,236,138,103,232,58,97,11,18,79,113,245,213,87,231,45,254,236,179,207,102,108,90,128,188,101,116,80,8,8,1,33,32,4,230,34,16,
164,84,218,180,110,153,187,238,186,107,110,133,152,190,161,164,93,122,233,165,25,98,62,195,10,4,114,16,246,196,229,246,27,246,188,97,203,221,125,247,221,153,87,94,121,37,108,241,80,229,80,98,91,181,106,
85,167,104,194,101,192,24,187,204,50,203,212,237,195,48,27,167,224,126,141,123,181,196,31,1,254,39,54,221,116,83,255,2,58,18,43,2,114,181,77,112,65,153,28,138,43,175,188,178,177,147,236,4,207,162,166,
133,64,48,2,36,152,38,37,10,201,197,173,21,215,52,106,212,40,103,165,95,126,249,197,229,41,179,202,170,177,43,165,38,31,37,127,206,6,66,238,180,19,36,151,240,218,175,184,37,90,112,253,136,219,197,201,
239,124,218,47,4,132,128,16,168,100,4,44,35,172,185,224,130,11,12,249,9,253,196,174,234,152,117,214,89,167,224,208,11,191,118,189,253,228,123,38,61,133,93,197,243,205,35,250,217,103,159,25,82,126,144,
194,226,208,67,15,141,45,53,137,215,135,56,62,25,39,73,155,98,87,114,227,104,174,174,13,66,95,236,10,175,251,77,248,203,171,175,190,234,174,159,57,162,231,106,188,222,122,235,25,171,148,199,234,246,105,
89,140,141,93,77,117,110,183,117,157,209,151,58,4,44,23,139,105,211,166,141,75,119,200,167,36,89,4,164,120,38,132,175,93,49,50,29,58,116,48,83,166,76,241,157,228,39,116,106,53,43,4,124,17,248,234,171,
175,12,113,31,228,36,67,90,183,110,237,98,75,172,85,212,252,249,231,159,166,97,195,134,46,95,167,37,196,242,109,35,142,3,97,226,140,194,148,137,163,47,106,67,8,8,1,33,80,233,8,16,31,248,230,155,111,154,
253,247,223,223,247,82,74,145,35,153,113,100,220,184,113,230,245,215,95,55,24,48,17,187,92,98,44,153,142,89,116,209,69,141,77,33,98,246,218,107,47,179,244,210,75,251,246,179,220,7,44,41,159,57,248,224,
131,77,179,102,205,98,235,138,77,99,99,90,182,108,105,44,211,188,107,115,236,216,177,117,185,54,237,74,168,217,96,131,13,204,251,239,191,239,142,161,160,98,32,142,75,184,15,24,37,236,170,116,92,77,86,
93,59,150,36,203,216,144,36,51,104,208,160,170,187,182,180,93,144,20,207,132,238,8,47,120,94,188,4,251,75,132,64,26,17,96,48,242,20,208,85,56,24,233,82,0,0,64,0,73,68,65,84,86,89,197,77,12,74,213,79,203,
98,104,122,245,234,101,150,95,126,121,223,83,74,241,244,133,70,7,132,128,16,16,2,243,32,96,217,87,205,54,219,108,147,151,156,166,92,239,84,20,207,5,22,88,96,158,254,166,245,135,229,22,48,140,79,96,21,
167,216,208,21,231,117,68,155,93,187,118,53,172,14,103,11,36,77,187,239,190,187,219,181,220,114,203,57,37,20,37,61,46,185,229,150,91,204,78,59,237,148,247,249,136,235,92,149,216,14,134,129,205,54,219,
204,64,54,212,164,73,147,74,188,132,138,233,179,20,207,4,110,21,203,246,235,174,187,174,121,228,145,71,220,242,125,2,167,80,147,66,160,162,17,176,121,228,140,205,15,106,186,116,233,226,123,29,150,148,
203,13,148,40,197,18,33,32,4,132,128,16,240,71,32,72,169,180,113,152,6,118,242,115,207,61,215,191,17,29,113,44,238,123,236,177,135,89,117,213,85,99,67,131,213,232,141,55,222,216,48,55,92,100,145,69,220,
202,52,171,159,245,5,197,240,169,167,158,114,187,143,57,230,24,23,110,82,191,76,161,191,109,44,173,177,57,229,243,186,98,23,218,118,181,212,235,222,189,187,155,179,159,115,206,57,213,114,73,169,188,14,
41,158,9,220,22,27,96,111,174,191,254,122,243,252,243,207,39,208,186,154,20,2,149,143,0,131,224,141,55,222,104,206,60,243,76,223,139,121,227,141,55,156,213,119,239,189,247,246,45,163,3,66,64,8,8,1,33,
96,220,10,29,238,148,126,130,27,46,41,35,246,221,119,95,191,34,218,111,17,96,76,178,249,47,99,197,2,3,171,37,13,114,109,90,162,63,151,98,47,215,9,222,126,251,109,179,209,70,27,57,5,117,161,133,22,50,150,
160,210,253,206,85,182,144,125,24,29,250,245,235,231,194,107,10,169,95,237,117,44,153,148,115,85,183,121,86,99,141,177,173,118,220,162,94,159,20,207,168,136,133,40,191,249,230,155,155,35,142,56,194,109,
33,138,171,72,145,8,64,170,64,190,73,203,150,106,32,199,201,222,32,169,225,247,31,127,252,97,22,95,124,113,71,150,3,97,14,27,241,140,222,247,236,223,228,211,146,36,143,64,16,193,144,44,244,201,223,3,157,
65,8,8,129,202,71,128,176,9,8,100,206,58,235,44,223,139,177,44,173,46,166,112,245,213,87,247,45,83,235,7,166,77,155,102,200,221,25,167,114,62,124,248,112,231,90,11,182,132,150,208,62,174,180,126,210,167,
79,31,103,148,229,56,174,211,227,199,143,247,43,26,121,63,156,35,54,133,141,217,115,207,61,35,215,173,149,10,91,109,181,149,33,222,83,24,37,119,199,165,120,198,140,45,46,21,176,217,242,2,35,152,94,18,
47,2,172,148,177,18,134,101,144,88,12,220,53,81,42,87,90,105,37,247,82,207,86,36,179,191,163,76,82,126,206,156,57,110,67,73,245,190,243,153,253,123,217,101,151,53,54,191,150,35,2,224,37,36,87,207,120,
239,161,215,90,144,226,73,185,32,247,49,175,45,125,10,1,33,32,4,106,21,129,73,147,38,57,198,242,157,119,222,217,23,2,189,75,125,161,169,59,0,249,14,164,62,204,29,226,16,72,131,108,74,61,167,108,210,30,
94,62,196,122,230,19,200,135,112,195,37,230,16,33,100,107,159,125,246,201,87,37,244,49,98,109,25,119,113,185,150,228,70,224,214,91,111,53,247,223,127,191,153,56,113,98,238,2,218,91,52,2,82,60,139,134,
112,222,6,14,63,252,112,199,220,70,32,183,36,30,4,88,177,36,16,31,55,33,152,240,182,220,114,75,99,115,46,57,156,227,57,67,238,86,48,34,16,111,193,106,42,105,113,226,142,251,200,125,214,218,217,203,11,
30,76,49,26,248,73,41,88,24,253,206,173,253,66,64,8,8,129,74,64,128,208,158,158,61,123,138,172,173,200,155,69,108,95,156,74,89,118,154,20,24,228,33,156,108,208,160,65,96,47,73,125,230,41,168,171,173,182,
154,155,251,224,177,21,135,196,125,141,113,244,41,77,109,96,44,216,100,147,77,204,224,193,131,29,87,75,154,250,86,45,125,145,226,25,227,157,196,173,147,0,114,98,59,243,77,166,99,60,101,85,55,245,241,199,
31,155,7,30,120,192,197,59,224,250,66,126,171,114,9,171,162,12,238,144,3,224,206,20,215,32,80,174,235,73,195,121,137,167,32,189,11,12,127,126,66,188,52,214,95,114,158,73,132,128,16,16,2,66,96,126,4,130,
86,51,113,197,133,169,149,248,62,73,110,4,24,219,47,190,248,226,216,200,151,102,205,154,229,198,46,114,130,34,79,62,249,164,201,183,34,157,221,43,250,130,242,243,214,91,111,185,221,24,96,185,199,113,8,
57,84,97,207,109,222,188,121,28,205,85,101,27,71,29,117,148,203,175,138,113,92,18,63,2,82,60,99,196,148,135,148,149,185,209,163,71,199,216,106,237,53,133,139,201,77,55,221,100,112,121,61,242,200,35,205,
18,75,44,145,26,16,200,243,4,241,0,49,0,107,172,177,70,106,250,85,137,29,193,178,120,197,21,87,152,124,12,114,228,23,229,255,137,231,64,34,4,132,128,16,16,2,243,35,16,164,120,226,138,75,168,9,172,169,
146,220,8,188,247,222,123,6,99,232,129,7,30,152,187,64,196,189,71,31,125,180,185,227,142,59,92,45,112,31,53,106,84,164,22,200,243,217,185,115,103,87,135,57,16,30,95,113,48,237,226,66,138,23,217,142,59,
238,24,169,63,181,84,248,243,207,63,55,219,110,187,173,99,31,78,211,252,179,90,238,129,20,207,24,239,36,9,128,137,17,216,109,183,221,98,108,181,182,154,130,197,141,85,78,6,82,20,207,52,202,223,127,255,
237,226,36,88,133,109,211,166,77,26,187,88,49,125,82,156,103,197,220,42,117,84,8,8,129,20,34,128,161,150,152,180,19,79,60,209,183,119,97,92,113,125,43,215,200,1,194,106,8,229,233,208,161,67,209,87,140,
75,109,219,182,109,13,4,121,184,214,242,27,87,219,168,210,173,91,183,186,124,159,112,135,60,252,240,195,81,155,152,175,60,185,187,159,120,226,9,131,98,44,241,71,0,165,31,204,33,10,149,196,140,128,13,54,
150,196,128,128,181,40,102,172,107,68,198,50,172,198,208,90,109,54,97,93,107,51,150,202,188,34,46,158,251,108,149,166,140,37,58,170,136,254,166,181,147,96,24,36,97,202,4,181,161,227,66,64,8,8,129,106,
68,192,186,112,102,236,42,86,222,75,211,59,52,47,60,238,224,192,129,3,51,150,113,54,184,96,136,18,157,58,117,202,216,169,186,219,142,63,254,248,16,53,114,23,161,63,139,46,186,168,107,103,129,5,22,200,
60,247,220,115,185,11,70,216,107,13,231,153,11,47,188,48,66,141,218,44,250,232,163,143,102,108,232,92,109,94,124,194,87,109,18,110,191,102,154,183,172,99,153,51,206,56,163,102,174,55,238,11,181,150,193,
140,101,147,203,252,249,231,159,113,55,157,88,123,40,159,214,202,156,177,22,231,196,206,81,237,13,223,115,207,61,153,143,62,250,40,239,101,94,126,249,229,25,27,63,157,183,140,14,10,1,33,32,4,106,17,1,
27,151,152,177,236,238,121,47,93,138,103,94,120,220,193,219,111,191,61,99,83,141,4,23,12,40,97,121,9,234,148,78,235,181,149,153,61,123,118,64,141,252,135,79,59,237,180,186,246,88,220,176,241,159,249,43,
132,56,106,243,121,134,40,85,219,69,152,147,218,156,170,25,235,126,93,219,64,36,112,245,114,181,141,97,5,153,84,28,237,219,183,55,147,39,79,206,203,42,23,195,169,170,182,9,114,140,225,182,74,64,125,37,
9,247,158,56,69,92,172,37,209,17,128,60,129,212,56,249,242,166,61,243,204,51,206,93,137,156,102,18,33,32,4,132,128,16,152,139,64,80,124,39,174,184,118,53,207,156,116,210,73,115,43,233,219,124,8,220,117,
215,93,46,6,22,6,251,66,133,212,110,144,32,66,140,136,192,106,219,183,111,223,66,155,115,245,136,205,133,96,15,118,125,196,42,200,6,242,155,98,4,178,34,171,124,22,211,68,77,212,61,249,228,147,93,90,155,
251,238,187,175,38,174,183,84,23,41,197,51,6,164,97,139,99,114,76,162,96,73,116,4,200,197,9,155,28,91,37,10,169,115,8,212,95,107,173,181,42,177,251,101,237,51,49,48,208,215,231,27,4,97,5,100,82,0,161,
147,68,8,8,1,33,32,4,230,34,16,164,120,66,206,182,212,82,75,185,52,100,115,107,233,91,125,4,48,126,119,233,210,165,168,188,221,24,160,97,189,71,214,94,123,109,199,74,187,200,34,139,212,63,85,228,223,244,
205,139,53,108,210,164,137,121,255,253,247,139,226,192,144,226,25,238,22,204,156,57,211,116,236,216,209,188,250,234,171,238,127,40,92,45,149,10,68,32,129,85,212,154,107,210,6,141,103,198,140,25,83,115,
215,29,215,5,223,121,231,157,25,203,40,23,87,115,37,111,199,38,124,206,216,85,207,146,159,183,90,78,104,89,109,3,47,69,174,98,129,16,169,128,16,16,2,53,134,0,97,10,132,43,228,147,75,46,185,36,208,21,55,
95,253,90,57,134,171,173,77,239,85,240,229,82,215,42,248,117,110,177,195,134,13,43,184,173,250,21,113,251,180,30,97,117,109,19,226,83,140,156,119,222,121,197,84,175,169,186,118,81,33,99,83,208,212,212,
53,39,125,177,138,241,44,18,97,130,250,45,123,153,72,133,138,192,177,82,8,133,242,93,162,181,114,230,59,172,99,121,16,32,222,132,129,53,159,72,241,204,135,142,142,9,1,33,80,139,8,60,244,208,67,25,27,174,
144,247,210,245,238,204,11,79,221,193,123,239,189,55,144,111,160,174,112,142,47,135,30,122,104,157,98,184,221,118,219,229,40,81,220,174,9,19,38,100,32,24,178,171,73,153,133,23,94,56,51,125,250,244,130,
26,36,70,244,130,11,46,40,168,110,45,86,26,58,116,168,139,245,172,197,107,79,234,154,229,106,27,184,38,156,191,0,116,203,228,115,36,183,163,36,58,2,184,81,146,235,202,6,208,71,175,156,162,26,184,139,114,
13,150,129,46,69,189,170,140,174,216,201,147,177,236,113,166,85,171,86,190,29,198,157,185,123,247,238,166,89,179,102,190,101,116,64,8,8,1,33,80,75,8,216,149,43,151,122,108,193,5,23,244,189,236,32,87,92,
223,138,53,118,96,228,200,145,6,55,86,248,58,162,10,249,63,55,219,108,51,99,9,7,205,66,11,45,100,72,11,103,137,105,162,54,19,88,126,255,253,247,55,131,6,13,114,229,112,11,38,5,76,84,153,53,107,150,177,
140,173,198,178,237,70,173,90,147,229,185,167,164,198,177,158,5,21,199,65,146,214,27,38,197,179,136,59,51,103,206,28,211,174,93,59,243,226,139,47,154,198,141,27,23,209,82,237,86,181,86,60,243,215,95,127,
153,29,118,216,161,162,65,176,86,49,103,128,64,129,146,68,67,192,82,198,187,255,161,131,14,58,200,183,34,3,187,117,101,50,93,187,118,245,45,163,3,66,64,8,8,129,90,66,32,72,169,252,236,179,207,204,216,
177,99,205,225,135,31,94,75,176,20,116,173,16,221,189,243,206,59,198,102,40,136,84,223,174,10,185,56,64,235,253,230,234,29,121,228,145,206,152,30,169,145,144,133,185,159,24,104,127,255,253,119,87,227,
241,199,31,143,60,38,190,252,242,203,142,168,72,249,230,67,130,110,139,245,233,211,199,64,242,52,96,192,128,240,149,84,210,23,1,41,158,190,208,4,31,184,241,198,27,13,129,251,88,202,36,133,33,240,224,131,
15,58,107,210,58,235,172,83,88,3,33,107,253,242,203,47,102,201,37,151,12,89,58,122,177,215,94,123,205,124,250,233,167,134,132,207,146,104,8,48,112,67,46,100,221,127,124,43,98,156,128,61,216,198,131,250,
150,209,1,33,32,4,132,64,173,32,96,93,38,141,141,223,116,43,158,126,215,204,202,22,99,235,134,27,110,232,87,68,251,255,135,128,77,229,102,174,186,234,42,115,246,217,103,71,194,228,225,135,31,54,7,28,112,
128,171,179,244,210,75,59,226,159,166,77,155,70,106,35,74,97,140,13,54,15,167,171,210,162,69,11,71,96,20,197,211,170,127,255,254,6,134,248,53,215,92,51,202,105,107,186,44,70,111,72,134,94,127,253,245,
68,231,145,53,3,114,82,62,188,181,208,46,164,66,163,70,141,170,133,75,77,236,26,173,5,169,168,184,138,160,142,145,107,211,178,161,102,172,251,75,134,88,194,164,196,42,157,129,36,15,73,157,187,26,218,21,
193,80,53,220,69,93,131,16,16,2,165,66,192,50,109,102,6,15,30,156,247,116,144,200,196,145,247,49,239,73,170,232,96,152,113,40,251,114,201,159,186,234,170,171,214,197,118,90,86,219,236,195,137,124,183,
70,244,140,77,249,82,240,57,185,70,230,69,146,104,8,88,175,188,140,13,11,139,86,73,165,115,34,32,114,161,156,176,4,239,156,52,105,82,134,100,190,250,7,14,198,42,95,9,235,42,146,88,130,94,8,107,142,61,
246,216,186,23,180,181,38,101,172,53,51,95,119,10,62,102,93,96,50,150,242,188,224,250,181,94,209,210,187,103,236,170,102,94,24,172,165,87,255,111,121,17,210,65,33,32,4,106,5,1,88,88,191,248,226,139,188,
151,43,98,161,188,240,204,119,144,113,200,230,226,156,111,191,223,14,202,51,175,96,179,92,31,25,235,2,235,87,52,244,126,230,148,204,93,48,24,48,38,218,149,88,215,46,74,238,175,191,254,154,249,249,231,
159,29,203,170,119,94,152,116,163,176,241,138,8,49,244,173,152,167,160,245,30,16,201,208,60,136,20,254,67,174,182,246,191,183,16,33,200,123,149,85,86,49,87,94,121,101,33,213,85,231,127,8,144,31,105,198,
140,25,145,227,20,130,0,180,47,110,151,247,42,151,79,190,101,209,53,228,219,138,83,222,126,251,109,231,242,178,239,190,251,198,217,108,205,180,69,140,236,234,171,175,158,55,120,255,129,7,30,48,155,110,
186,169,115,29,171,25,96,116,161,66,64,8,8,129,28,8,4,197,119,50,6,226,146,9,1,145,36,28,2,207,63,255,188,177,138,157,217,101,151,93,2,43,48,111,89,119,221,117,141,85,6,93,217,37,150,88,194,229,122,180,
211,113,71,50,148,253,153,253,221,42,150,44,248,184,205,239,123,224,201,235,21,128,31,193,178,242,214,219,59,255,79,230,41,16,31,245,234,213,107,254,131,218,147,23,1,238,149,93,108,114,56,139,203,35,47,
84,129,7,165,120,6,66,52,127,1,152,88,109,78,37,51,121,242,100,199,130,54,127,9,237,9,139,192,151,95,126,233,98,100,143,58,234,168,176,85,2,203,17,251,194,139,149,216,11,63,129,129,150,152,193,184,228,
133,23,94,48,214,82,90,241,36,73,113,225,17,181,29,107,185,55,214,109,221,228,123,14,32,33,226,127,78,131,102,84,116,85,94,8,8,129,106,67,32,72,241,132,44,7,69,67,198,208,240,119,30,229,2,30,1,98,103,
131,164,103,207,158,6,99,104,26,196,166,89,113,4,125,48,235,230,19,174,235,132,19,78,48,196,162,74,162,35,0,19,48,196,78,48,220,74,10,71,64,138,103,1,216,221,124,243,205,102,196,136,17,110,162,92,64,117,
85,201,66,224,239,191,255,118,10,96,212,128,254,172,38,230,249,10,9,13,41,110,108,242,230,121,246,231,250,209,183,111,95,115,245,213,87,231,58,20,121,223,240,225,195,77,243,230,205,157,65,34,114,101,85,
112,8,88,183,176,58,210,132,92,144,96,37,198,122,111,221,155,114,29,214,62,33,32,4,132,64,77,32,0,89,30,41,166,78,63,253,116,223,235,101,114,188,237,182,219,58,182,117,223,66,58,48,31,2,151,95,126,185,
243,150,90,126,249,229,231,59,230,237,128,253,118,247,221,119,119,63,73,101,131,226,199,230,125,247,62,179,247,101,127,79,226,56,25,22,240,230,242,19,230,90,140,159,23,95,124,177,95,17,237,15,64,128,133,
146,173,183,222,218,188,241,198,27,166,97,195,134,1,165,117,216,15,1,41,158,126,200,228,217,191,193,6,27,56,139,152,247,226,201,83,84,135,66,32,192,203,144,173,88,97,197,145,92,143,172,156,133,149,147,
78,58,201,92,115,205,53,110,208,8,91,39,87,57,220,92,96,138,91,221,186,139,74,10,67,32,72,241,164,213,32,43,127,97,103,86,45,33,32,4,132,64,229,32,240,220,115,207,25,60,123,182,223,126,123,223,78,235,
93,233,11,77,222,3,51,103,206,52,3,7,14,172,248,220,226,245,47,242,254,251,239,55,235,175,191,190,203,153,93,255,152,126,135,71,128,212,127,61,122,244,48,135,29,118,88,248,74,42,57,15,2,82,60,231,129,
35,248,7,249,4,143,56,226,8,51,109,218,180,162,149,149,224,179,213,70,137,184,20,207,31,126,248,193,197,221,122,49,23,97,208,35,255,42,3,13,73,159,139,145,107,175,189,214,229,74,147,11,75,225,40,226,6,
116,242,201,39,155,197,23,95,220,183,145,139,46,186,200,89,249,23,89,100,17,223,50,58,32,4,132,128,16,168,102,4,72,251,65,190,200,101,150,89,198,247,50,165,120,250,66,19,120,128,244,94,150,13,191,106,
92,82,137,247,61,227,140,51,92,186,152,192,139,87,129,188,8,144,2,16,79,57,98,101,37,133,33,32,197,51,34,110,4,113,47,183,220,114,230,250,235,175,143,88,83,197,253,16,136,75,241,164,253,247,222,123,207,
124,252,241,199,243,4,247,123,1,252,217,159,222,119,86,175,177,2,22,43,184,127,50,208,227,78,35,41,12,129,39,159,124,210,253,111,117,232,208,193,183,129,39,158,120,194,172,184,226,138,6,183,34,137,16,
16,2,66,160,22,17,8,82,42,241,254,193,147,199,50,152,214,34,60,69,95,243,215,95,127,237,72,100,242,185,174,22,125,146,18,54,128,219,53,188,36,34,197,41,30,116,148,120,112,132,67,100,189,245,214,43,190,
193,26,108,65,138,103,132,155,78,92,197,70,27,109,100,32,146,97,242,43,137,7,129,56,21,207,120,122,20,189,21,20,79,172,164,146,194,17,152,61,123,182,123,153,247,238,221,219,183,17,86,167,135,12,25,98,
142,59,238,56,223,50,58,32,4,132,128,16,168,102,4,130,20,207,23,95,124,209,224,1,20,134,157,181,154,113,42,230,218,80,220,187,117,235,102,214,92,115,205,98,154,41,123,221,57,115,230,184,149,78,188,133,
36,241,32,0,9,98,131,6,13,92,156,117,60,45,214,86,43,82,60,35,220,111,155,167,209,12,26,52,200,140,25,51,38,66,45,21,13,66,64,138,103,16,66,181,115,92,113,158,181,115,175,117,165,66,64,8,68,71,32,140,
241,237,134,27,110,48,7,28,112,128,88,247,163,195,91,87,195,230,207,116,238,169,132,209,84,178,39,19,44,189,132,176,228,35,75,170,187,104,125,9,133,0,94,117,157,59,119,118,172,209,139,46,186,104,168,58,
42,52,23,1,41,158,115,177,8,252,214,182,109,91,23,112,78,14,79,73,124,8,192,34,215,167,79,159,188,177,125,241,157,45,153,150,180,226,25,15,174,82,60,227,193,81,173,8,1,33,80,157,8,16,110,176,210,74,43,
185,156,198,126,87,24,180,34,234,87,79,251,231,69,224,165,151,94,114,249,185,15,63,252,240,121,15,84,200,175,209,163,71,187,60,163,123,237,181,87,133,244,184,114,186,217,169,83,39,115,204,49,199,24,233,
3,209,239,153,20,207,144,152,77,159,62,221,61,96,175,189,246,90,209,68,52,33,79,89,51,197,6,12,24,96,248,39,174,100,70,88,41,158,241,60,174,87,94,121,165,57,250,232,163,243,146,58,64,172,129,171,139,136,
156,226,193,92,173,8,1,33,80,57,8,92,120,225,133,110,37,46,31,193,154,20,207,248,238,39,227,13,46,203,173,91,183,142,175,209,18,180,196,202,56,43,223,97,114,146,150,160,59,85,119,138,59,238,184,195,197,
1,79,156,56,177,234,174,45,233,11,146,226,25,18,97,18,199,146,35,242,206,59,239,12,89,67,197,194,34,64,250,147,70,141,26,153,160,228,199,97,219,43,71,57,41,158,241,160,254,236,179,207,58,183,38,242,207,
249,201,184,113,227,220,161,124,101,252,234,106,191,16,16,2,66,160,146,17,8,82,42,137,237,236,223,191,191,33,79,181,164,120,4,32,147,193,85,149,252,151,75,45,181,84,241,13,150,168,5,184,18,46,187,236,
50,229,155,76,8,111,92,177,33,25,26,57,114,100,197,199,1,39,4,145,111,179,82,60,125,161,153,123,0,133,115,221,117,215,53,79,63,253,180,89,107,173,181,230,30,208,183,88,16,120,245,213,87,205,140,25,51,
76,215,174,93,99,105,175,28,141,72,241,140,7,245,31,127,252,209,25,119,78,61,245,84,223,6,127,250,233,39,131,181,49,95,25,223,202,58,32,4,132,128,16,168,80,4,50,153,140,129,19,129,241,198,79,152,167,44,
182,216,98,166,99,199,142,126,69,180,63,34,2,223,125,247,157,97,165,25,194,161,5,23,92,48,98,237,210,23,191,229,150,91,76,151,46,93,76,139,22,45,74,127,242,26,58,227,129,7,30,232,82,248,161,224,75,194,
35,32,197,51,4,86,143,62,250,168,185,233,166,155,12,73,155,37,241,35,240,229,151,95,26,82,105,144,151,172,18,5,139,40,238,44,196,39,74,138,71,64,113,158,197,99,168,22,132,128,16,168,62,4,72,23,70,46,113,
38,188,126,2,103,194,9,39,156,160,149,46,63,128,10,220,255,246,219,111,27,230,130,105,103,175,39,6,248,231,159,127,206,251,140,20,8,129,170,213,67,224,141,55,222,48,221,187,119,119,105,252,138,205,5,95,
175,233,170,254,41,197,51,196,237,221,122,235,173,93,124,167,82,56,132,0,171,128,34,127,255,253,183,185,226,138,43,204,217,103,159,93,64,237,242,87,193,26,74,82,225,124,105,64,202,223,203,202,233,129,
20,207,202,185,87,234,169,16,16,2,165,67,96,224,192,129,102,243,205,55,55,107,175,189,182,239,73,131,92,113,125,43,234,64,32,2,196,243,141,31,63,62,181,115,149,17,35,70,152,207,63,255,92,233,198,2,239,
100,124,5,182,216,98,11,3,115,176,82,23,133,199,84,138,103,0,86,252,19,227,178,0,169,16,238,43,146,100,16,168,228,148,42,31,126,248,161,129,253,46,159,21,58,25,212,170,179,85,8,17,122,244,232,97,26,55,
110,236,123,129,184,18,97,105,108,214,172,153,111,25,29,16,2,66,64,8,84,19,2,40,149,184,217,230,75,239,33,197,51,217,59,254,242,203,47,155,71,30,121,196,92,112,193,5,169,98,226,191,245,214,91,93,127,14,
57,228,144,100,1,80,235,243,32,112,233,165,151,154,9,19,38,24,184,74,36,225,16,144,226,25,128,19,47,113,220,91,200,223,41,73,14,129,74,86,60,167,76,153,98,88,245,220,121,231,157,147,3,168,134,90,158,52,
105,146,33,142,115,167,157,118,242,189,106,6,127,88,251,118,223,125,119,223,50,58,32,4,132,128,16,168,38,4,130,148,74,184,18,8,91,129,245,91,146,28,2,95,125,245,149,35,238,57,236,176,195,28,193,76,114,
103,10,110,249,219,111,191,117,161,62,164,76,217,114,203,45,131,43,168,68,172,8,48,87,217,116,211,77,13,171,225,77,154,52,137,181,237,106,109,76,138,103,158,59,251,159,255,252,199,145,10,61,240,192,3,
166,93,187,118,121,74,234,80,177,8,84,178,226,73,174,172,101,151,93,214,185,64,21,139,131,234,27,243,219,111,191,153,235,175,191,222,244,235,215,207,23,14,24,229,160,185,175,84,247,108,223,11,211,1,33,
32,4,132,64,14,4,120,231,145,110,10,183,62,63,25,58,116,168,75,75,182,201,38,155,248,21,209,254,152,16,96,126,8,201,29,138,31,172,183,13,27,54,140,169,229,112,205,64,52,117,223,125,247,25,60,174,32,218,
91,102,153,101,194,85,84,169,216,17,216,99,143,61,28,153,151,8,15,195,65,43,197,51,15,78,207,60,243,140,57,235,172,179,156,27,101,158,98,58,20,3,2,149,172,120,18,223,137,197,171,101,203,150,49,32,161,
38,64,64,113,158,122,14,132,128,16,16,2,115,17,192,179,102,214,172,89,102,183,221,118,155,187,179,222,55,220,63,49,216,45,188,240,194,245,142,232,103,82,8,64,142,8,249,36,113,183,7,31,124,112,73,242,188,
67,116,57,100,200,16,23,146,82,201,105,232,146,186,39,165,110,119,236,216,177,166,79,159,62,6,2,42,73,48,2,82,60,243,96,180,231,158,123,154,13,54,216,192,249,242,231,41,166,67,49,32,80,201,138,39,131,
206,254,251,239,159,55,38,49,6,136,106,170,137,48,138,39,236,130,60,55,249,226,157,106,10,52,93,172,16,16,2,85,139,0,227,204,190,251,238,107,86,88,97,5,223,107,12,114,197,245,173,168,3,69,35,0,15,8,222,
113,27,110,184,161,57,224,128,3,76,131,6,13,138,110,179,126,3,207,63,255,188,25,54,108,152,217,106,171,173,76,183,110,221,52,246,213,7,168,76,191,89,125,110,219,182,173,33,206,86,134,128,224,155,32,197,
211,7,163,57,115,230,184,85,44,172,140,141,26,53,242,41,165,221,113,33,64,30,164,147,78,58,169,34,9,156,46,186,232,34,103,101,22,157,118,92,79,131,49,183,223,126,187,217,117,215,93,205,202,43,175,236,
219,232,189,247,222,235,6,96,229,214,245,133,72,7,132,128,16,168,18,4,130,148,74,92,63,33,30,202,151,227,179,74,160,72,245,101,144,151,156,213,72,242,191,195,83,176,205,54,219,20,181,10,250,214,91,111,
25,92,168,137,37,68,225,132,215,160,18,114,137,166,250,38,37,208,57,230,175,63,252,240,131,97,94,34,201,143,128,20,79,31,124,96,205,28,62,124,184,152,170,124,240,137,123,119,255,254,253,205,118,219,109,
103,86,91,109,181,184,155,78,188,189,74,94,173,77,28,156,2,79,192,224,13,163,52,86,93,63,193,173,133,60,90,172,54,75,132,128,16,16,2,213,140,64,144,23,200,187,239,190,107,120,111,194,8,46,41,63,2,127,
252,241,135,121,225,133,23,12,68,120,124,95,124,241,197,221,252,102,213,85,87,117,159,43,174,184,226,60,10,41,177,162,159,125,246,153,27,247,248,252,254,251,239,157,203,244,58,235,172,99,182,223,126,123,
179,252,242,203,151,255,162,212,3,95,4,112,185,38,245,226,155,111,190,105,150,88,98,9,223,114,58,96,140,20,79,159,167,128,224,124,44,140,184,219,74,146,71,0,38,62,210,103,180,111,223,62,249,147,197,124,
6,41,158,49,3,106,155,195,90,76,34,116,38,91,126,130,133,159,152,38,240,151,8,1,33,32,4,170,21,1,86,82,48,206,246,237,219,215,247,18,195,228,248,244,173,172,3,137,35,128,242,9,27,238,215,95,127,237,62,
191,249,230,27,243,243,207,63,155,127,255,253,215,44,185,228,146,110,254,179,210,74,43,25,54,148,82,145,5,37,126,75,98,63,1,139,39,48,29,247,236,217,51,246,182,171,169,65,41,158,57,238,38,174,13,248,232,
227,179,47,247,201,28,0,37,176,11,43,209,251,239,191,111,160,4,175,52,33,214,80,238,77,241,223,181,32,11,63,103,12,114,63,139,191,87,106,81,8,8,1,33,80,90,4,158,126,250,105,23,134,210,177,99,71,223,19,
43,230,221,23,26,29,16,2,37,65,224,238,187,239,54,108,164,132,147,248,35,32,197,51,7,54,176,83,145,210,225,174,187,238,202,113,84,187,146,64,32,204,10,87,18,231,45,182,77,172,149,40,157,172,188,73,226,
69,0,165,18,108,243,145,7,113,156,244,2,50,16,197,139,189,90,19,2,66,32,61,8,192,129,208,187,119,239,188,41,59,100,132,75,207,253,82,79,106,19,1,82,30,109,188,241,198,46,68,111,245,213,87,175,77,16,66,
92,181,20,207,122,32,253,253,247,223,46,119,231,168,81,163,148,30,163,30,54,73,255,36,117,205,197,23,95,156,87,209,72,186,15,81,219,231,57,89,108,177,197,204,182,219,110,27,181,170,202,7,32,16,134,60,
232,209,71,31,117,255,175,176,79,75,132,128,16,16,2,213,136,64,144,247,7,134,219,43,174,184,34,111,142,207,106,196,69,215,36,4,210,134,0,156,19,164,214,185,240,194,11,211,214,181,212,244,71,138,103,189,
91,241,196,19,79,184,36,205,208,86,75,74,139,0,185,169,126,252,241,71,211,181,107,215,210,158,184,136,179,193,100,118,237,181,215,86,148,178,92,196,229,150,180,234,244,233,211,93,160,126,62,242,160,79,
63,253,212,60,251,236,179,46,174,162,164,157,211,201,132,128,16,16,2,37,66,32,104,53,243,149,87,94,49,144,155,144,200,94,34,4,132,64,249,16,128,76,234,192,3,15,52,239,189,247,158,230,133,62,183,65,138,
103,61,96,118,220,113,71,199,32,118,250,233,167,215,59,162,159,165,64,224,148,83,78,49,151,92,114,137,89,116,209,69,75,113,186,162,206,49,96,192,0,183,42,190,197,22,91,20,213,142,42,231,70,0,55,102,172,
134,65,228,65,65,147,178,220,173,107,175,16,16,2,66,32,253,8,192,238,61,102,204,24,115,196,17,71,248,118,150,252,129,48,128,67,74,35,17,2,66,160,188,8,64,146,137,7,66,167,78,157,202,219,145,148,158,93,
138,103,214,141,153,61,123,182,217,114,203,45,205,212,169,83,205,82,75,45,149,117,68,95,75,133,0,131,44,10,29,202,68,154,229,245,215,95,119,147,129,211,78,59,45,205,221,172,248,190,5,185,152,113,129,82,
60,43,254,54,235,2,132,128,16,240,65,224,177,199,30,115,6,206,13,55,220,208,167,68,250,223,129,48,144,147,27,157,57,22,105,67,188,79,92,132,73,19,210,164,73,19,199,234,234,125,46,188,240,194,190,215,170,
3,149,139,0,44,190,176,249,206,156,57,211,109,124,39,109,76,131,6,13,220,253,111,214,172,153,97,107,218,180,169,219,42,97,1,34,215,221,232,215,175,159,249,232,163,143,204,35,143,60,146,235,112,205,239,
147,226,153,245,8,224,50,137,219,30,249,59,37,229,67,96,228,200,145,46,17,111,90,41,169,201,177,117,227,141,55,58,139,150,18,57,39,251,156,176,218,137,242,153,143,60,136,184,224,83,79,61,181,34,86,201,
147,69,75,173,11,1,33,80,109,8,132,33,80,75,163,241,141,48,136,103,158,121,198,229,165,68,233,36,183,33,43,178,94,202,16,62,225,71,240,210,139,144,106,132,109,214,172,89,166,81,163,70,46,157,8,121,17,
219,182,109,155,247,253,95,109,247,187,154,174,231,151,95,126,49,227,199,143,119,25,34,32,222,65,193,92,121,229,149,231,217,72,27,131,97,2,99,196,140,25,51,234,54,158,11,198,125,22,129,182,218,106,43,
211,174,93,187,138,121,14,120,134,59,116,232,96,88,160,32,85,142,100,94,4,164,120,102,225,129,69,17,246,184,93,118,217,37,107,175,190,150,3,129,59,239,188,211,52,111,222,60,117,247,2,11,29,138,206,85,
87,93,101,22,89,100,145,114,64,83,83,231,28,52,104,144,89,127,253,245,205,122,235,173,231,123,221,35,70,140,48,43,172,176,66,69,230,128,245,189,40,29,16,2,66,64,8,88,4,130,188,62,88,69,194,213,54,13,225,
65,172,94,177,202,195,106,15,10,6,49,167,133,178,123,162,180,140,30,61,218,76,158,60,217,44,187,236,178,206,149,152,177,64,146,126,4,48,56,140,29,59,214,96,152,223,117,215,93,205,230,155,111,238,190,23,
210,115,50,76,240,28,76,156,56,209,44,183,220,114,102,191,253,246,115,228,61,133,180,85,202,58,157,59,119,118,177,158,135,28,114,72,41,79,91,17,231,146,226,249,191,219,244,198,27,111,152,94,189,122,153,
105,211,166,21,252,15,82,17,119,188,130,58,121,221,117,215,57,106,234,180,248,201,99,181,61,251,236,179,29,249,20,214,91,73,242,8,48,129,129,232,43,223,203,27,183,157,33,67,134,152,227,142,59,46,249,14,
233,12,66,64,8,8,129,18,33,64,156,251,69,23,93,100,200,209,233,39,144,242,253,243,207,63,142,155,194,175,76,210,251,81,56,111,191,253,118,67,127,15,59,236,48,183,170,25,231,57,89,45,123,248,225,135,13,
57,214,123,244,232,97,54,217,100,147,56,155,87,91,49,33,64,44,50,74,34,74,215,78,59,237,20,59,185,14,74,40,108,247,132,100,29,126,248,225,166,69,139,22,49,245,60,254,102,232,39,6,33,12,39,146,121,17,144,
226,249,63,60,78,56,225,4,195,203,141,149,182,90,16,148,40,220,90,176,42,54,108,216,208,89,146,112,111,193,245,37,77,2,209,208,14,59,236,80,246,213,172,95,127,253,213,89,148,89,237,196,250,154,70,201,
100,50,238,25,198,61,165,90,98,100,184,38,38,93,65,121,82,211,232,106,150,198,103,68,125,18,2,66,160,114,16,120,243,205,55,205,187,239,190,107,246,217,103,31,223,78,95,125,245,213,142,120,8,151,197,82,
11,115,38,20,206,239,190,251,206,48,135,34,70,51,73,65,177,189,239,190,251,28,99,232,177,199,30,107,86,91,109,181,36,79,167,182,67,34,192,194,77,255,254,253,221,92,141,21,206,164,229,143,63,254,112,207,
221,15,63,252,224,242,219,18,39,156,54,33,126,153,156,158,132,142,173,177,198,26,105,235,94,89,251,35,197,211,194,143,181,112,157,117,214,113,73,95,91,182,108,89,214,27,146,196,201,241,159,231,197,240,
254,251,239,59,202,117,20,78,252,206,215,92,115,77,23,75,129,82,197,63,48,86,75,254,161,253,100,241,197,23,119,229,81,80,217,112,123,240,190,39,73,198,132,171,17,238,21,229,114,179,225,5,2,219,46,253,
192,165,179,148,194,189,99,80,247,2,242,249,100,35,237,76,125,89,96,129,5,92,156,35,147,1,92,92,184,39,75,47,189,180,251,108,211,166,77,170,173,131,245,175,37,251,119,144,171,25,101,165,120,102,35,166,
239,66,64,8,84,3,2,119,223,125,183,155,204,231,83,176,202,245,238,27,55,110,156,121,252,241,199,157,194,89,234,149,167,223,127,255,221,92,127,253,245,134,57,9,158,46,213,98,104,173,180,103,150,185,227,
53,215,92,227,12,14,71,30,121,100,201,99,48,153,179,98,120,105,213,170,149,73,35,39,8,169,224,208,41,130,12,231,149,118,223,139,237,175,20,79,139,32,49,98,196,118,190,240,194,11,197,226,153,186,250,4,
118,51,56,240,79,73,144,126,49,194,203,158,127,116,111,243,148,85,126,19,103,82,95,96,36,67,89,132,41,184,24,139,20,202,215,153,103,158,105,142,58,234,168,146,43,79,88,88,97,174,37,95,231,170,171,174,
90,255,18,11,250,205,42,30,204,126,158,18,233,41,149,185,148,73,20,72,176,243,88,222,60,198,183,40,214,237,191,255,254,219,173,228,19,184,143,59,57,47,233,74,18,82,170,156,113,198,25,121,99,106,161,46,
103,2,162,64,254,74,186,179,234,171,16,16,2,249,16,8,163,84,134,41,147,239,28,81,143,97,156,102,190,132,177,254,128,3,14,136,90,61,214,242,172,6,223,116,211,77,230,196,19,79,172,136,184,191,88,47,190,
204,141,145,253,129,213,103,198,102,136,162,202,41,132,227,12,29,58,212,133,66,21,51,215,140,251,26,94,122,233,37,115,208,65,7,57,175,5,22,6,36,255,69,64,138,167,197,1,215,0,148,163,179,206,58,171,106,
158,11,92,105,153,140,179,212,191,239,190,251,150,229,186,80,24,39,77,154,228,94,8,184,127,50,56,64,24,84,136,176,42,141,2,216,183,111,95,179,202,42,171,20,210,68,228,58,40,136,60,19,196,23,50,200,22,
35,40,125,188,28,81,50,127,250,233,39,183,82,236,41,147,124,162,80,70,81,38,11,233,11,10,232,13,55,220,224,220,169,81,210,42,229,69,56,108,216,48,231,82,149,47,174,7,34,3,200,158,96,65,148,8,1,33,32,4,
170,1,129,32,111,15,216,51,33,243,193,205,181,20,130,183,20,225,38,40,27,113,25,98,139,237,55,115,3,250,68,238,196,157,119,222,185,216,230,84,63,4,2,196,219,194,58,139,65,62,45,243,8,12,247,24,97,142,
62,250,104,211,186,117,235,16,87,81,154,34,176,241,146,49,3,102,94,201,127,17,168,121,197,147,85,59,94,88,47,191,252,114,106,99,247,162,62,172,111,191,253,182,185,237,182,219,92,108,92,90,172,63,196,146,
162,8,179,2,90,168,34,140,11,41,105,51,74,229,242,138,123,196,238,187,239,94,20,145,1,43,155,184,4,65,35,143,229,43,13,43,114,60,235,79,63,253,116,197,24,90,62,254,248,99,103,192,200,231,74,195,255,49,
249,95,79,62,249,228,168,255,46,42,47,4,132,128,16,72,29,2,16,169,96,40,196,219,199,79,136,31,107,220,184,177,217,108,179,205,252,138,196,182,159,52,98,184,85,178,218,137,139,107,218,4,183,100,194,75,
10,157,95,164,237,122,210,218,31,112,198,72,190,247,222,123,167,174,139,44,118,48,63,36,38,154,69,151,52,8,97,90,24,136,6,14,28,152,134,238,164,162,15,53,175,120,162,160,225,138,58,106,212,168,84,220,
144,98,59,49,125,250,116,115,255,253,247,59,11,96,26,115,76,62,241,196,19,142,24,128,213,203,66,132,152,2,172,173,48,253,37,73,242,67,220,0,6,137,142,29,59,22,210,77,87,7,229,14,90,113,146,9,39,189,154,
25,181,147,184,151,131,37,177,179,105,23,6,19,140,22,249,38,96,92,67,169,93,206,210,142,155,250,39,4,132,64,229,34,64,232,15,202,103,151,46,93,124,47,130,149,62,188,128,146,86,4,49,160,98,136,101,92,76,
115,60,229,61,247,220,227,140,188,90,249,244,125,100,138,58,240,232,163,143,186,250,249,200,174,138,58,65,12,149,241,84,99,206,197,202,103,26,72,125,240,18,96,30,9,35,115,210,255,167,49,192,87,154,38,
236,77,170,105,177,113,143,25,155,43,176,42,48,176,131,84,166,119,239,222,25,27,151,152,234,235,177,46,167,25,155,20,59,99,21,138,130,250,105,87,183,50,199,31,127,124,198,198,149,22,84,63,168,146,53,70,
100,158,124,242,201,160,98,121,143,91,171,96,198,178,188,229,45,83,238,131,86,121,207,216,116,37,229,238,70,168,243,95,126,249,229,129,229,172,165,51,176,140,10,8,1,33,32,4,42,1,1,187,186,152,177,252,
9,121,187,106,39,216,121,143,199,113,208,122,26,101,172,43,111,198,134,136,196,209,92,226,109,48,174,89,54,224,196,207,83,107,39,176,241,138,25,235,50,90,17,151,109,9,33,221,51,107,221,111,83,209,95,155,
18,48,99,221,147,83,209,151,52,116,162,166,87,60,63,252,240,67,151,224,248,245,215,95,55,13,26,52,40,141,166,159,224,89,110,188,241,70,23,175,10,91,109,218,133,124,169,196,166,176,114,73,252,103,84,153,
61,123,182,179,192,94,117,213,85,142,201,53,106,125,191,242,15,62,248,160,179,232,22,99,209,227,62,144,52,27,55,221,52,11,108,189,36,29,39,95,106,218,5,75,59,46,43,249,132,235,192,157,25,166,101,137,16,
16,2,66,160,146,17,8,138,239,228,218,240,2,193,245,53,73,193,147,228,208,67,15,77,197,234,81,152,235,196,67,134,85,224,243,206,59,47,81,175,168,48,125,169,150,50,184,138,94,121,229,149,110,139,227,154,
200,176,240,222,123,239,185,56,81,86,4,9,149,33,99,0,33,73,16,21,109,176,193,6,5,243,129,120,253,35,27,0,30,1,204,29,202,29,135,10,1,214,224,193,131,13,76,208,18,139,64,26,180,223,114,245,225,156,115,
206,201,216,100,196,229,58,125,172,231,101,181,211,18,225,196,218,102,210,141,89,70,186,140,141,201,203,96,81,45,68,190,248,226,139,140,37,44,202,88,210,156,66,170,207,87,199,186,92,103,172,171,206,124,
251,163,236,176,147,128,140,37,186,137,82,165,172,101,109,194,231,204,240,225,195,203,218,135,48,39,199,250,31,36,19,38,76,200,112,61,18,33,32,4,132,64,165,35,192,252,36,159,48,110,158,125,246,217,249,
138,20,125,12,111,176,98,189,127,138,238,68,1,13,176,82,204,220,66,82,60,2,120,208,245,233,211,167,104,15,179,137,19,39,102,108,136,85,198,166,23,201,160,122,228,219,172,162,152,217,116,211,77,51,172,
94,219,240,177,130,47,194,242,89,100,110,190,249,230,130,235,199,85,209,134,53,185,235,182,10,124,92,77,86,116,59,53,173,120,218,180,18,25,220,62,171,65,112,237,180,164,66,21,119,41,150,176,192,185,7,
91,242,161,130,250,110,87,173,51,150,112,168,104,247,98,27,139,153,177,36,64,5,245,129,74,184,13,159,123,238,185,25,203,226,91,112,27,229,170,104,87,18,203,117,234,208,231,181,73,202,51,24,87,242,9,207,
80,24,151,220,124,109,232,152,16,16,2,66,160,220,8,48,65,181,196,66,121,187,97,87,140,50,119,220,113,71,222,50,197,28,100,108,182,113,157,197,52,81,214,186,40,58,204,139,36,197,33,96,87,235,50,214,67,
173,224,70,158,125,246,217,204,230,155,111,158,87,209,12,82,66,187,117,235,150,177,49,146,5,245,129,121,157,205,99,95,80,221,56,43,217,236,25,153,91,110,185,37,206,38,43,182,173,154,117,181,181,49,0,46,
183,229,107,175,189,86,246,101,120,251,79,87,180,148,194,229,166,232,78,250,52,64,138,17,136,11,112,139,40,132,48,8,66,165,135,30,122,200,144,239,177,16,151,138,41,83,166,212,145,0,249,116,49,239,110,
114,125,90,203,179,33,89,112,90,152,212,242,118,184,222,65,176,91,111,189,245,204,134,27,110,88,239,72,122,126,90,171,187,75,105,179,214,90,107,229,237,148,8,134,242,194,163,131,66,64,8,84,0,2,97,216,
106,33,175,179,51,207,188,228,67,133,94,42,237,194,16,142,27,239,98,139,45,230,219,12,57,188,9,155,41,135,144,154,109,221,117,215,205,123,234,75,46,185,196,205,243,210,146,250,37,111,103,83,120,144,112,
52,200,55,131,194,92,114,117,29,23,90,187,82,234,92,76,179,143,147,246,140,80,164,22,45,90,24,198,115,62,73,41,247,249,231,159,27,203,57,97,56,39,159,214,163,205,48,183,242,132,144,44,203,97,226,230,121,
81,178,3,224,122,77,218,23,24,153,203,25,82,247,192,3,15,24,194,176,38,79,158,236,93,82,237,126,86,172,202,92,100,199,45,51,106,166,87,175,94,69,182,146,142,234,184,156,86,186,37,5,194,32,155,91,50,99,
149,208,130,64,197,165,2,183,140,168,2,9,65,49,238,74,184,59,217,120,146,12,110,195,149,42,144,52,225,34,156,102,121,245,213,87,67,121,39,136,96,40,205,119,81,125,19,2,66,32,12,2,140,101,191,255,254,123,
222,162,144,215,21,227,134,152,175,113,107,140,12,245,190,37,172,196,206,158,203,178,29,121,228,145,249,46,193,29,3,67,198,103,73,97,8,88,133,45,3,81,79,84,193,61,219,114,45,204,243,92,88,229,50,99,57,
57,50,97,189,219,102,206,156,233,92,115,27,54,108,56,79,59,107,175,189,118,228,21,76,86,75,203,237,114,251,199,31,127,100,108,62,248,140,205,127,26,21,206,170,43,95,179,174,182,60,0,214,242,80,21,55,148,
184,196,74,97,39,205,7,56,47,36,216,243,112,241,41,68,112,115,37,134,32,104,192,246,218,182,169,93,156,43,81,161,44,192,184,126,18,251,240,201,39,159,120,77,86,236,167,93,41,76,117,223,191,252,242,203,
80,172,112,184,5,49,96,73,132,128,16,16,2,149,138,64,80,124,39,215,101,61,132,50,150,64,37,246,75,36,30,13,195,124,24,73,187,226,201,53,48,206,43,246,63,204,221,156,183,76,161,184,217,116,126,25,187,58,
89,167,44,218,20,34,25,158,231,176,10,231,188,189,200,56,69,237,176,195,14,203,216,244,128,117,109,46,189,244,210,153,23,95,124,177,126,209,188,191,45,217,84,198,166,5,202,91,38,233,131,150,112,50,99,
87,61,147,62,77,234,219,175,73,87,91,220,107,97,105,179,171,40,5,185,102,166,109,125,220,198,22,26,155,158,36,109,221,42,168,63,118,5,177,46,7,147,53,14,68,110,99,198,140,25,46,233,182,141,41,48,221,187,
119,207,89,223,42,38,198,210,130,155,45,182,216,194,177,26,231,44,20,176,211,174,18,186,126,226,98,11,19,91,165,11,207,15,44,138,105,204,253,10,182,60,23,48,24,131,119,62,177,148,239,134,156,115,54,158,
34,95,49,29,19,2,66,64,8,164,18,1,59,107,52,140,233,132,159,228,147,67,14,57,196,216,85,207,216,231,48,176,131,239,185,231,158,102,181,213,86,203,119,122,119,140,60,213,59,236,176,131,251,142,219,100,
49,121,175,3,79,102,11,88,163,116,29,51,168,93,241,52,54,198,53,76,53,231,54,140,171,101,33,161,56,161,78,80,101,133,112,79,37,215,58,140,176,81,132,231,129,28,170,150,240,209,85,219,100,147,77,92,24,
84,33,115,185,250,231,29,63,126,188,115,155,182,70,104,119,104,249,229,151,55,140,247,65,225,55,94,59,204,11,108,170,60,99,149,96,111,87,201,63,109,74,21,231,242,75,120,87,45,75,77,42,158,164,144,128,
30,122,192,128,1,85,113,239,161,13,103,171,22,241,98,38,247,219,111,63,195,139,171,16,177,171,159,102,234,212,169,102,206,156,57,198,186,56,24,98,2,248,228,101,213,172,89,51,179,203,46,187,184,125,133,
180,77,92,11,74,26,19,3,218,171,6,33,206,19,172,131,98,102,202,121,173,196,105,4,165,126,225,30,51,193,176,12,207,229,236,170,206,45,4,132,128,16,40,8,1,98,220,44,49,142,57,248,224,131,243,214,71,225,
179,43,142,121,203,68,61,104,189,133,12,113,145,240,37,132,145,108,197,179,103,207,158,102,224,192,129,97,170,21,92,102,232,208,161,117,6,229,40,138,39,253,100,108,144,65,50,28,244,195,134,13,51,141,27,
55,54,91,109,181,85,184,10,182,20,70,129,182,109,219,26,210,152,32,93,186,116,49,180,99,87,60,221,239,56,254,16,55,186,253,246,219,27,27,218,228,154,35,237,10,49,147,75,44,177,68,168,230,225,17,57,246,
216,99,203,150,114,13,3,250,70,27,109,228,140,39,213,176,96,17,10,244,92,133,82,191,38,155,64,7,161,115,174,22,55,91,224,129,77,181,218,4,150,88,92,35,94,120,225,133,162,47,237,159,127,254,41,154,10,220,
235,4,254,249,199,31,127,124,38,45,137,137,189,126,21,251,249,206,59,239,100,108,14,211,98,155,73,180,254,1,7,28,16,170,125,197,121,134,130,73,133,132,128,16,72,33,2,150,132,36,144,161,30,110,1,230,49,
113,203,157,119,222,25,137,175,32,219,213,214,42,158,113,119,103,190,246,134,12,25,82,231,110,25,38,198,51,187,1,216,239,37,225,16,32,100,41,138,48,199,178,74,106,221,189,177,70,236,130,93,107,131,206,
251,233,167,159,102,136,23,181,250,140,219,142,57,230,152,160,42,117,199,9,217,9,147,154,173,174,66,2,95,112,183,13,98,172,78,224,180,169,106,178,230,98,60,161,133,182,204,163,46,253,69,170,238,68,129,
157,33,240,187,16,82,157,2,79,87,242,106,54,105,113,102,244,232,209,37,63,111,174,19,242,194,179,172,106,25,98,96,170,77,200,133,154,118,234,124,6,182,48,34,197,51,12,74,42,35,4,132,64,26,17,32,222,62,
136,119,0,178,181,118,237,218,197,222,125,235,13,22,169,205,74,82,60,73,201,69,250,53,73,126,4,72,211,19,53,13,13,41,75,60,69,112,185,229,150,75,156,247,130,20,45,94,28,41,57,63,199,141,27,151,255,162,
178,142,18,191,204,194,70,185,4,226,174,36,254,119,203,117,61,133,156,183,230,20,79,94,172,214,133,165,16,172,82,89,7,101,8,114,161,106,22,24,123,31,123,236,177,178,94,34,47,99,18,82,99,105,174,86,73,
59,193,144,141,201,205,204,158,61,59,16,126,114,219,89,106,246,192,114,42,32,4,132,128,16,72,27,2,97,136,133,120,199,29,125,244,209,177,118,157,49,46,234,92,162,146,20,79,27,34,147,122,246,246,88,111,
104,129,141,93,122,233,165,25,27,162,20,186,54,99,242,50,203,44,83,167,120,66,46,84,10,97,46,239,41,187,214,229,54,195,170,107,24,25,60,120,112,198,198,88,134,41,154,72,25,235,242,237,216,109,173,219,
112,34,237,87,66,163,53,167,120,194,102,27,149,13,43,205,55,18,151,97,168,171,171,93,238,187,239,190,140,141,201,45,203,101,190,254,250,235,142,229,47,236,139,173,44,157,140,225,164,105,119,217,134,217,
206,230,174,11,188,82,86,3,112,201,146,8,1,33,32,4,42,9,1,60,152,194,120,158,160,28,244,235,215,47,214,75,179,68,50,145,89,63,43,73,241,4,172,184,49,139,245,6,164,164,49,203,143,16,169,39,54,135,124,157,
2,104,227,47,35,213,45,166,48,158,103,54,63,107,221,185,195,134,10,193,174,91,110,47,193,90,103,183,173,41,197,19,5,194,6,246,150,117,153,189,152,127,180,92,117,71,140,24,17,187,245,230,167,159,126,202,
117,170,178,239,27,52,104,80,134,173,148,98,89,211,50,172,4,150,211,53,163,84,215,155,118,197,211,50,239,134,162,34,199,109,152,178,18,33,32,4,132,64,37,33,128,33,153,52,22,65,66,42,149,168,10,66,80,155,
133,228,179,174,52,197,147,60,146,172,124,74,114,35,0,54,24,32,194,10,41,229,112,173,245,86,30,201,167,94,74,193,37,216,59,119,251,246,237,67,159,186,144,103,61,116,227,33,10,178,42,28,165,191,33,154,
172,168,34,53,165,120,98,237,42,69,0,124,41,159,0,203,34,151,249,224,131,15,98,57,37,19,246,253,247,223,223,189,72,108,90,146,88,218,140,187,17,6,14,12,8,165,144,47,190,248,34,116,62,179,82,244,199,59,
7,131,195,214,91,111,29,123,144,60,147,153,52,187,18,67,54,21,118,80,12,227,174,230,225,169,79,33,32,4,132,64,26,16,128,211,224,135,31,126,200,219,21,8,238,238,186,235,174,76,156,147,103,12,171,133,196,
198,87,154,226,249,252,243,207,167,134,51,34,239,77,46,211,193,167,158,122,42,51,97,194,132,208,103,183,233,65,234,20,191,109,182,217,38,116,189,184,10,50,95,89,97,133,21,234,250,0,73,98,24,97,46,193,
124,183,92,66,174,121,200,193,106,53,231,120,77,41,158,54,85,68,164,127,170,114,61,148,81,206,75,252,227,55,223,124,19,165,74,206,178,184,145,218,244,37,117,255,192,12,40,105,20,72,23,250,244,233,19,72,
190,80,108,223,25,136,57,15,47,136,180,9,49,10,158,149,47,78,118,52,200,23,96,125,75,171,48,49,194,240,16,68,188,65,255,153,192,201,178,157,214,59,169,126,9,1,33,144,11,129,48,171,152,184,20,98,108,142,
83,241,196,200,74,220,104,84,169,52,197,147,216,69,198,16,73,110,4,96,124,141,50,110,178,144,227,205,69,96,68,46,135,64,248,232,245,129,113,63,140,176,226,72,76,115,57,197,166,246,201,48,127,175,69,169,
25,197,243,173,183,222,202,16,128,92,109,46,147,188,68,139,117,141,69,233,236,209,163,71,221,63,47,255,196,54,239,85,106,255,31,108,142,206,204,163,143,62,154,104,255,32,51,138,98,249,75,180,51,245,26,
231,218,189,23,45,140,110,113,189,240,113,99,158,62,125,122,189,179,165,231,39,147,50,44,178,175,188,242,74,96,167,88,21,135,61,78,34,4,132,128,16,168,4,4,88,233,188,226,138,43,2,187,234,133,17,196,233,
213,193,88,23,38,126,190,126,231,42,77,241,164,255,105,39,209,171,143,113,41,127,71,197,102,173,181,214,170,155,139,148,139,208,143,112,51,111,62,180,231,158,123,134,130,139,52,125,204,37,202,41,253,251,
247,207,64,152,88,139,82,51,138,39,255,80,184,145,86,155,64,50,0,75,86,161,194,234,81,175,94,189,234,254,113,189,127,224,40,244,212,133,158,187,152,122,4,180,39,41,81,105,229,147,236,75,253,182,31,121,
228,145,121,238,215,130,11,46,152,193,229,186,88,73,34,94,184,216,62,101,215,231,158,67,40,16,214,221,86,68,18,217,232,233,187,16,16,2,105,70,224,222,123,239,13,204,223,137,225,28,55,65,164,16,215,88,
191,235,199,139,166,144,16,150,74,84,60,211,206,101,224,119,143,74,177,63,10,54,184,185,50,247,96,206,216,184,113,227,82,116,47,231,57,240,210,242,230,173,173,91,183,206,89,166,254,206,119,223,125,55,
67,190,220,114,10,115,153,181,215,94,59,20,83,127,57,251,153,196,185,107,70,241,92,111,189,245,10,178,232,37,1,122,156,109,194,206,5,19,94,33,130,210,121,200,33,135,212,253,211,122,255,188,124,142,31,
63,190,144,38,75,86,39,206,65,183,126,167,103,205,154,149,185,238,186,235,234,239,78,205,239,236,184,10,239,158,53,104,208,160,232,148,51,88,188,137,129,73,171,120,198,0,111,226,21,212,207,11,47,188,48,
177,36,214,65,231,214,113,33,32,4,132,64,20,4,200,47,24,36,40,135,40,137,200,37,151,92,146,129,220,37,14,41,148,43,66,138,103,28,232,167,167,141,40,138,39,233,64,188,249,199,198,27,111,92,182,139,192,
24,227,229,244,108,210,164,73,168,126,124,246,217,103,145,115,149,134,106,56,98,161,157,118,218,201,197,107,71,172,86,241,197,107,66,241,124,255,253,247,51,40,158,213,152,14,3,66,152,66,20,79,254,89,15,
63,252,240,186,23,135,247,2,241,62,211,234,102,234,253,199,93,118,217,101,110,245,203,251,29,231,39,74,119,154,93,141,137,241,241,238,83,246,231,34,139,44,146,25,62,124,120,193,80,112,205,207,61,247,92,
193,245,147,172,136,145,196,155,152,221,120,227,141,161,226,154,113,175,39,13,143,68,8,8,1,33,144,102,4,32,243,187,254,250,235,3,187,72,12,155,23,90,3,163,39,121,188,227,16,86,127,152,39,69,21,41,158,
81,17,75,119,249,176,70,93,174,130,184,96,111,254,81,110,134,214,69,23,93,212,245,165,81,163,70,161,0,254,248,227,143,203,150,158,47,187,131,196,120,150,131,148,41,187,15,229,248,94,19,138,39,150,193,
189,246,218,171,28,248,38,126,78,86,60,11,97,231,34,158,196,123,105,228,250,196,7,62,205,130,139,113,92,214,222,250,215,153,118,151,83,38,9,185,238,25,251,150,95,126,249,80,228,59,245,175,153,223,105,
94,241,252,238,187,239,50,220,115,132,201,22,68,72,97,196,91,37,13,83,86,101,132,128,16,16,2,229,64,224,242,203,47,15,229,114,151,29,131,55,106,212,168,12,124,7,113,8,198,76,220,15,163,138,20,207,168,
136,165,187,124,20,197,147,152,78,111,30,82,110,197,115,177,197,22,139,164,120,126,242,201,39,25,98,44,203,45,63,254,248,99,166,69,139,22,25,72,175,106,73,106,66,241,36,119,231,227,143,63,94,149,247,181,
80,197,147,21,207,163,142,58,170,238,197,225,189,64,188,207,137,19,39,166,26,175,56,137,21,234,95,40,171,126,12,168,105,21,220,162,188,251,84,255,179,123,247,238,5,19,104,113,205,105,93,233,134,38,157,
20,2,158,120,171,159,222,111,191,207,1,3,6,100,88,249,148,8,1,33,32,4,210,136,0,30,75,97,226,209,49,184,101,191,3,33,130,139,43,175,53,99,202,135,31,126,24,25,30,41,158,145,33,75,117,133,40,174,182,164,
2,241,230,31,16,119,150,75,240,100,244,98,77,155,54,109,26,170,27,105,113,181,165,179,59,236,176,67,6,150,221,90,146,170,87,60,177,202,144,70,165,16,119,212,74,120,16,112,57,45,116,229,207,143,88,136,
151,201,139,47,190,152,234,203,79,146,92,104,246,236,217,177,231,200,140,19,76,220,71,189,23,126,246,231,238,187,239,94,84,30,206,52,175,120,66,118,197,74,180,39,164,145,97,240,8,18,210,225,196,153,118,
32,232,124,58,46,4,132,128,16,136,130,0,147,206,169,83,167,6,86,129,119,224,219,111,191,173,43,7,57,9,43,165,113,8,76,233,133,24,232,164,120,198,129,126,122,218,136,162,120,226,105,7,183,4,115,144,101,
150,89,166,108,23,193,234,165,55,15,218,112,195,13,67,245,131,213,125,86,249,211,32,184,207,239,184,227,142,105,232,74,201,250,80,245,138,39,47,235,174,93,187,150,12,208,82,159,136,9,56,110,136,133,10,
47,143,125,246,217,167,238,31,215,251,7,158,60,121,114,161,77,38,94,143,88,196,108,37,36,137,19,158,118,218,105,73,52,27,75,155,172,226,121,247,201,251,220,101,151,93,138,98,55,166,99,184,110,165,213,
224,192,228,236,181,215,94,171,195,143,220,181,24,93,194,8,41,10,72,186,46,17,2,66,64,8,164,9,1,60,143,78,57,229,148,80,93,202,69,168,23,69,81,200,119,146,103,159,125,182,32,66,193,74,84,60,179,221,149,
243,97,82,139,199,162,98,3,139,172,55,7,41,36,70,56,14,140,179,211,203,133,205,92,1,137,226,152,49,99,226,56,125,209,109,176,208,177,230,154,107,38,198,89,82,116,7,19,104,160,234,21,79,124,207,227,72,
53,145,0,246,177,52,137,18,130,197,167,24,97,53,152,213,50,239,5,194,231,148,41,83,138,105,50,177,186,184,85,244,233,211,167,96,119,210,176,29,131,164,167,220,121,158,252,250,122,207,61,247,204,115,175,
176,150,177,178,87,172,12,29,58,52,51,109,218,180,98,155,73,164,62,36,90,245,227,32,250,246,237,27,42,158,149,132,216,94,238,187,68,58,167,70,133,128,16,16,2,5,32,0,67,109,152,240,6,220,106,115,229,37,
142,75,241,252,232,163,143,10,34,91,169,52,197,147,85,98,143,43,160,128,219,85,245,85,88,168,137,178,144,145,29,174,85,174,76,0,135,30,122,104,221,124,232,166,155,110,10,117,143,240,26,43,151,162,156,
171,131,157,58,117,170,99,171,206,117,188,218,246,85,181,226,73,90,12,242,228,20,234,138,90,9,55,251,137,39,158,200,188,242,202,43,69,119,21,197,165,115,231,206,117,255,192,113,180,89,116,167,114,52,192,
160,81,8,9,194,255,103,239,76,192,230,152,210,61,126,198,110,236,196,32,214,8,177,37,196,37,246,93,236,75,44,35,150,32,36,65,236,219,216,141,125,39,134,16,107,196,46,171,136,32,98,205,144,224,18,177,11,
134,144,100,144,113,237,102,120,184,215,125,234,190,191,115,167,63,221,245,85,119,157,170,58,85,93,85,125,222,231,249,190,238,174,58,235,91,85,167,206,187,253,223,128,166,66,15,157,124,242,201,109,8,130,
161,133,51,44,0,154,97,69,73,192,53,179,117,127,199,133,212,207,98,234,65,49,157,40,6,76,45,223,88,71,129,127,119,228,56,224,56,224,56,144,7,14,96,237,228,29,99,66,245,192,244,0,131,161,157,164,132,66,
55,10,176,76,165,191,162,9,158,83,167,78,245,198,141,27,87,25,190,251,244,113,128,112,155,40,169,244,120,255,86,246,34,205,72,169,2,194,243,162,139,46,170,199,240,187,223,253,206,40,252,134,41,115,175,
231,41,203,5,222,12,224,115,180,10,149,90,240,36,16,159,60,57,101,166,151,95,126,217,123,236,177,199,172,76,17,109,32,154,23,252,245,17,218,243,70,36,216,30,59,118,108,102,195,194,5,226,196,19,79,204,
213,2,197,228,71,141,26,165,23,218,237,182,219,206,154,208,73,187,104,11,243,120,221,25,91,16,248,6,27,46,172,223,38,132,181,52,200,85,205,164,174,43,227,56,224,56,224,56,96,155,3,88,48,77,80,105,9,135,
185,232,162,139,2,187,7,153,243,147,132,30,79,149,134,227,0,246,21,77,240,228,29,231,20,144,149,43,222,254,147,247,36,49,135,166,132,183,220,242,203,47,223,38,124,102,237,37,198,88,43,130,47,32,61,166,
148,55,220,7,82,211,224,110,91,86,44,26,255,117,41,181,224,137,16,69,206,191,50,211,103,159,125,102,156,90,194,132,15,0,14,229,81,248,184,229,150,91,188,49,99,198,152,76,193,106,153,233,211,167,123,196,
123,198,73,89,99,117,32,85,141,113,141,64,222,253,249,231,159,171,142,38,255,122,241,197,23,231,106,158,213,51,170,183,41,186,249,230,155,189,183,223,126,187,186,104,221,239,67,134,12,241,112,89,115,228,
56,224,56,224,56,208,76,14,160,228,53,197,17,192,66,247,218,107,175,5,14,247,173,183,222,178,230,162,71,218,185,127,254,243,159,129,253,212,59,88,52,193,243,236,179,207,174,55,21,119,252,223,28,136,202,
35,0,174,42,194,223,250,235,175,159,153,162,30,160,45,210,199,85,250,158,56,113,162,209,53,196,74,202,189,158,55,218,108,179,205,114,27,222,101,155,87,165,21,60,185,185,58,119,238,236,17,223,85,102,66,
8,41,123,252,218,181,215,94,235,77,152,48,161,105,151,241,195,15,63,212,150,79,27,113,148,77,155,132,65,199,182,226,133,12,186,138,84,132,103,184,94,252,8,27,56,83,112,14,180,137,199,31,127,188,21,215,
180,72,19,112,133,29,7,28,7,28,7,170,56,128,146,15,43,135,9,53,90,151,113,23,164,45,27,68,120,77,84,229,110,145,4,79,66,82,202,190,87,178,113,31,32,72,70,217,55,255,235,95,255,242,58,118,236,216,38,0,
94,115,205,53,54,134,17,218,198,161,135,30,218,214,231,86,91,109,21,90,190,82,128,20,68,245,20,57,149,50,205,248,196,187,174,95,191,126,205,232,58,243,62,75,43,120,114,115,109,187,237,182,153,51,180,25,
29,54,122,49,53,99,60,182,250,196,149,146,60,165,81,98,14,108,245,237,111,135,77,194,113,199,29,23,89,35,236,111,39,207,191,243,122,31,97,221,109,116,15,240,162,252,248,227,143,141,88,203,230,10,43,169,
35,199,1,199,1,199,129,102,112,128,28,217,196,233,155,16,249,139,195,114,252,217,90,183,121,223,6,197,210,55,26,103,145,4,207,17,35,70,24,165,173,105,52,223,86,56,71,62,215,219,110,187,45,210,84,113,27,
175,88,30,23,88,96,129,212,249,76,42,148,74,127,243,206,59,175,247,230,155,111,26,143,247,244,211,79,55,46,155,101,65,188,177,48,150,97,76,42,59,149,86,240,236,213,171,87,172,96,249,34,94,112,91,47,158,
60,205,157,135,15,247,202,60,161,235,226,130,124,204,49,199,68,66,125,203,19,79,195,198,146,215,251,8,119,249,239,191,255,190,238,240,137,75,137,242,50,193,130,94,157,154,165,110,195,238,132,227,128,227,
128,227,128,69,14,96,73,2,80,200,20,16,136,53,249,151,95,126,105,56,2,128,135,108,121,227,176,54,70,137,129,44,146,224,249,167,63,253,169,33,31,221,201,223,56,96,234,6,254,91,13,79,131,227,84,132,193,
149,87,94,217,251,199,63,254,81,125,218,218,119,172,149,11,45,180,80,155,224,25,197,138,61,123,246,108,239,250,235,175,183,54,22,219,13,109,176,193,6,185,77,105,103,115,174,165,20,60,89,168,9,212,253,
244,211,79,109,242,42,183,109,213,67,188,203,237,128,67,6,70,60,37,11,159,105,236,94,80,115,188,216,103,205,154,165,81,79,9,64,199,29,9,45,51,96,76,184,134,196,37,4,160,99,143,61,54,210,203,57,110,95,
89,215,203,171,224,73,30,206,48,162,12,46,209,38,132,82,3,183,150,40,176,241,38,237,186,50,142,3,142,3,142,3,245,56,192,186,3,24,154,169,27,35,155,100,19,140,10,188,65,200,109,109,131,88,19,73,93,101,
74,69,17,60,73,19,70,10,13,71,102,28,32,157,28,185,93,163,16,247,117,167,78,157,218,4,194,110,221,186,89,207,159,141,194,248,15,127,248,67,91,31,0,44,70,65,167,5,164,235,219,111,191,141,50,173,76,203,
30,118,216,97,198,161,67,153,14,204,114,103,191,163,61,209,82,148,138,36,49,172,18,45,136,18,151,150,82,205,171,222,100,30,127,252,113,181,196,18,75,168,77,54,217,164,94,145,194,28,23,165,129,58,243,204,
51,149,8,119,106,181,213,86,139,53,110,17,88,149,128,17,169,14,29,58,168,237,183,223,94,243,101,190,249,230,83,115,230,204,81,226,182,169,254,243,63,255,83,173,184,226,138,106,224,192,129,74,52,103,145,
251,16,237,178,30,227,73,39,157,164,100,161,141,92,63,143,21,4,193,87,137,123,186,18,119,226,220,13,239,47,127,249,139,18,43,65,195,113,73,172,167,18,212,90,37,26,251,134,229,42,39,69,129,160,4,217,78,
151,231,222,112,228,56,224,56,224,56,144,38,7,36,108,68,237,189,247,222,106,157,117,214,49,234,70,20,129,74,60,57,66,223,81,18,187,174,36,174,78,9,40,140,81,187,97,133,68,73,171,223,191,75,46,185,100,
88,81,37,2,175,18,52,81,93,110,235,173,183,86,188,19,211,36,222,221,18,90,161,187,56,226,136,35,148,184,132,26,117,7,31,69,160,86,226,150,105,84,190,213,11,33,22,8,118,130,241,251,180,194,47,1,187,82,
91,108,177,133,18,144,42,125,104,133,21,86,80,130,188,220,118,143,84,202,197,249,20,195,129,190,191,196,112,160,171,139,113,73,239,229,150,94,122,105,163,230,196,99,77,209,134,32,228,27,149,111,70,161,
41,83,166,40,238,107,113,177,111,70,247,217,245,105,89,144,205,69,115,4,232,2,34,210,42,4,186,215,224,193,131,11,63,93,44,145,196,81,162,233,141,67,104,148,113,163,0,136,38,76,11,70,31,104,159,227,230,
43,5,168,6,80,155,178,160,164,2,131,62,121,242,228,56,108,79,181,14,238,205,247,223,127,191,81,31,196,165,68,113,205,38,13,1,215,144,251,198,145,227,128,227,128,227,64,90,28,184,245,214,91,61,81,136,27,
55,79,156,157,137,181,179,210,224,121,231,157,87,249,154,248,147,52,98,245,210,183,248,27,175,182,120,202,174,181,205,18,149,197,119,217,160,251,135,19,248,91,132,213,208,56,217,192,138,45,126,16,148,
216,56,169,250,176,192,47,188,240,194,109,247,2,249,53,15,60,240,64,143,247,109,28,98,143,70,134,138,234,123,106,165,149,86,242,120,70,162,16,233,212,242,108,237,100,46,236,69,186,118,237,234,17,219,93,
102,42,157,171,45,46,150,4,232,38,113,211,44,226,5,183,249,226,105,198,252,89,16,136,159,252,226,139,47,98,117,207,117,39,206,143,4,209,81,8,88,109,192,107,226,16,139,4,208,227,81,251,140,211,87,218,117,
216,104,216,138,19,178,57,86,114,150,146,50,200,132,112,209,62,250,232,163,141,227,167,104,147,117,130,107,104,26,115,101,50,14,87,198,113,192,113,192,113,160,194,1,20,103,128,29,70,33,66,77,162,172,199,
8,182,166,40,185,38,227,64,232,53,217,252,230,93,240,228,29,141,130,217,41,23,77,174,122,251,50,167,156,114,74,172,180,109,128,253,116,233,210,165,70,88,156,127,254,249,53,106,171,88,245,66,223,183,188,
203,113,247,221,115,207,61,61,4,215,106,161,83,44,235,145,67,157,112,209,141,10,152,212,158,27,217,28,217,119,223,125,115,153,238,197,230,236,75,231,106,43,66,128,118,161,156,54,109,154,220,171,173,67,
23,92,112,129,118,29,44,162,43,9,110,158,140,31,87,36,92,134,227,16,245,247,218,107,47,213,189,123,247,200,213,113,193,217,105,167,157,212,134,27,110,24,185,174,60,140,74,132,87,237,94,130,171,81,81,9,
247,19,137,21,206,221,240,113,157,149,151,159,241,184,36,46,69,225,82,115,192,1,7,24,215,145,151,146,26,61,122,180,194,197,108,174,185,230,50,174,231,10,58,14,56,14,56,14,52,226,0,225,11,184,194,30,114,
200,33,141,138,213,156,19,207,19,37,0,63,106,255,253,247,175,57,222,232,7,229,199,143,31,175,247,62,141,202,153,158,147,141,191,18,48,30,69,152,67,163,53,81,242,92,43,137,175,55,109,214,106,57,177,130,
41,137,137,107,216,38,33,55,132,32,197,217,23,52,108,184,69,78,206,156,57,83,135,224,8,218,113,228,25,19,254,194,59,149,119,56,247,83,53,45,178,200,34,58,76,137,80,165,85,86,89,69,73,220,166,18,76,22,
69,127,98,25,213,159,146,167,188,186,138,90,108,177,197,244,30,81,148,203,106,238,185,231,174,57,215,232,135,40,29,116,168,14,247,114,148,122,141,218,76,243,220,131,15,62,168,247,148,165,150,97,108,74,
177,121,104,75,226,3,189,131,15,62,56,15,67,201,116,12,184,24,202,230,57,211,62,109,116,6,0,20,96,61,81,19,87,87,247,13,176,12,90,180,184,132,181,75,226,253,188,119,222,121,39,110,19,158,44,106,26,200,
40,118,3,77,172,248,210,75,47,89,75,66,110,115,26,104,169,77,128,133,252,125,162,165,37,143,111,20,34,17,59,86,6,52,173,142,28,7,28,7,28,7,146,114,224,222,123,239,141,236,226,201,250,19,55,215,48,174,
132,54,9,244,208,33,67,134,216,108,50,211,182,0,155,35,213,150,163,100,28,136,26,194,226,239,141,235,32,138,23,79,132,190,26,203,165,8,111,70,191,127,255,251,223,235,119,51,46,224,113,104,208,160,65,158,
40,72,226,84,109,74,29,60,29,176,22,167,133,10,220,148,73,249,58,45,157,171,173,4,238,123,184,127,180,34,69,129,105,207,3,127,102,204,152,161,221,96,162,184,20,249,199,125,211,77,55,121,196,34,36,37,132,
28,4,143,168,113,3,213,253,222,126,251,237,30,185,194,138,70,228,110,203,163,192,133,11,116,28,55,104,92,115,227,184,158,115,237,217,244,137,166,182,104,151,208,141,215,113,192,113,32,71,28,16,75,91,44,
69,48,24,5,113,21,160,184,199,218,222,172,50,30,16,97,139,70,100,54,0,47,2,44,6,71,201,56,128,98,94,64,163,26,166,52,51,233,129,52,61,184,132,239,178,203,46,30,110,183,141,4,79,177,110,122,226,181,228,
145,31,148,116,105,113,137,156,185,69,113,177,173,158,227,206,59,239,236,177,159,44,43,149,202,213,22,19,253,238,187,239,174,64,214,42,130,73,221,182,185,30,68,44,217,116,71,114,209,177,61,6,211,246,112,
209,25,54,108,152,118,239,140,235,30,44,26,101,37,218,48,37,62,241,166,221,54,44,39,128,68,218,189,8,23,35,208,216,226,144,8,158,10,23,147,254,253,251,199,169,158,121,157,15,62,248,64,9,24,128,58,234,
168,163,50,239,59,172,67,144,169,37,151,107,172,103,89,22,109,237,94,213,163,71,143,176,110,106,206,75,140,177,146,120,87,133,107,145,0,24,212,156,115,63,28,7,28,7,28,7,26,113,64,54,233,26,61,117,227,
141,55,86,59,238,184,99,163,162,237,206,137,34,86,141,25,51,70,175,61,237,78,26,28,0,181,125,236,216,177,26,145,214,160,184,81,17,230,67,168,3,161,44,139,47,190,184,81,157,60,20,18,197,163,126,7,75,62,
201,60,12,167,240,99,144,52,59,250,190,22,235,161,146,152,203,196,243,249,233,167,159,148,164,187,211,46,229,184,137,139,112,169,64,167,237,216,177,163,254,227,221,155,20,109,158,119,57,104,207,146,78,
47,241,120,179,110,215,144,143,139,0,0,64,0,73,68,65,84,64,192,66,213,195,15,63,172,81,163,179,238,59,147,254,202,36,81,227,238,216,171,87,175,50,77,41,242,92,36,86,207,3,229,54,207,4,74,25,46,209,73,
2,254,229,5,235,221,117,215,93,214,167,41,113,5,90,83,10,154,106,92,34,40,30,100,221,34,16,110,169,97,9,202,155,49,15,172,224,81,18,67,251,199,136,150,22,235,37,215,51,42,81,71,4,94,79,98,166,162,86,117,
229,29,7,28,7,90,148,3,188,119,89,115,226,88,44,121,23,98,161,139,179,94,85,179,155,144,17,219,4,240,31,243,202,163,87,76,208,92,69,161,237,61,245,212,83,65,167,220,177,4,28,192,242,93,20,215,101,158,
35,66,184,146,228,108,79,192,170,196,85,89,75,36,93,76,105,189,175,74,229,106,43,65,228,169,8,35,137,239,162,12,27,192,45,225,196,19,79,12,69,13,203,112,72,53,93,17,247,34,90,168,68,227,227,165,114,227,
141,55,214,180,107,243,7,139,21,8,187,73,160,183,39,77,154,20,41,17,183,205,241,155,182,69,252,14,227,204,35,129,4,9,18,93,18,18,160,130,68,194,43,202,13,20,57,81,227,69,147,140,217,213,117,28,112,28,
40,30,7,4,212,204,19,79,153,216,110,129,164,67,35,166,50,41,225,154,72,188,186,109,250,219,223,254,166,149,113,182,219,181,221,30,41,107,202,236,162,104,155,95,81,219,19,43,156,199,30,46,207,132,18,135,
52,105,113,211,242,229,101,110,160,247,142,27,55,46,47,195,177,58,142,210,184,218,98,170,199,173,78,22,111,5,98,86,43,147,64,89,43,137,123,140,237,178,147,6,239,100,17,80,18,47,162,118,219,109,55,181,
221,118,219,197,238,130,4,210,18,247,151,250,220,184,159,68,123,172,17,251,22,90,104,161,88,227,21,203,174,18,1,74,157,47,137,192,243,228,166,36,43,136,194,101,102,245,213,87,87,226,33,16,107,110,105,
87,34,121,53,99,76,74,32,196,225,202,45,176,236,177,154,2,33,23,87,157,205,55,223,92,163,38,199,106,196,85,114,28,112,28,40,37,7,8,171,0,213,85,192,64,84,159,62,125,98,205,17,84,237,231,159,127,94,73,
218,143,88,245,171,43,137,165,71,143,7,87,83,219,36,0,134,106,194,132,9,250,125,102,195,221,210,246,248,158,121,230,25,5,47,121,119,56,74,143,3,247,221,119,159,118,183,141,123,191,167,55,50,165,8,151,
146,244,104,26,237,120,237,181,215,78,179,171,212,219,22,204,17,133,251,60,252,46,29,89,21,99,155,216,216,3,15,60,224,109,191,253,246,77,28,65,190,186,70,243,135,219,77,179,130,235,113,223,20,88,120,79,
98,67,188,35,143,60,82,163,227,137,95,127,34,38,161,201,181,141,220,215,104,64,228,20,77,234,254,132,203,4,215,225,238,187,239,206,133,171,18,40,194,184,77,225,238,156,87,2,161,89,22,91,107,195,195,101,
87,98,89,19,181,247,196,19,79,104,79,130,34,161,227,37,154,176,171,236,56,224,56,208,144,3,184,226,19,170,96,154,103,56,168,49,188,41,88,143,147,132,157,248,219,149,20,22,169,185,24,98,149,101,206,121,
115,97,196,189,246,230,155,111,246,179,194,253,78,137,3,120,3,73,250,53,171,247,109,210,161,178,215,98,191,134,117,190,12,196,158,5,119,91,155,107,67,94,248,82,26,139,231,222,123,239,173,214,91,111,61,
29,4,95,58,237,64,204,9,1,86,32,168,175,58,63,37,57,193,26,229,227,50,233,66,98,60,20,57,55,9,218,22,244,60,253,201,119,2,197,253,132,149,9,141,211,6,27,108,160,86,182,16,224,47,136,163,74,208,201,212,
21,87,92,145,120,30,254,177,54,250,45,73,185,117,30,42,172,94,243,204,51,79,163,162,13,207,9,164,184,182,212,98,65,67,91,12,79,150,92,114,201,182,63,242,151,98,21,77,11,20,11,77,184,184,214,42,81,8,40,
113,197,86,113,173,184,13,39,105,233,36,26,107,174,115,92,208,41,255,48,208,130,10,226,179,206,41,150,196,242,76,62,190,161,67,135,106,64,4,137,31,81,203,45,183,156,191,43,247,219,113,192,113,160,228,
28,144,141,173,18,33,71,237,176,195,14,106,215,93,119,141,61,91,217,4,106,48,59,128,204,200,99,104,139,120,87,2,24,55,96,192,0,91,77,214,180,195,187,159,156,207,228,38,141,147,251,186,166,177,132,63,240,
76,34,143,54,121,184,197,240,144,176,53,87,61,10,7,36,150,89,9,74,173,182,48,147,139,179,153,36,134,22,37,217,44,180,151,26,249,62,203,66,120,113,10,90,181,206,69,91,150,57,49,143,82,8,158,108,44,113,
117,97,177,117,72,148,237,111,207,23,95,124,81,163,229,129,30,134,123,229,26,107,172,161,255,248,142,48,37,90,215,54,33,178,34,80,214,19,38,65,30,91,102,153,101,212,178,203,46,171,63,249,14,178,108,154,
4,82,47,130,31,8,101,73,132,191,184,99,180,45,244,74,206,82,45,188,124,243,205,55,74,226,72,21,159,252,241,18,21,237,86,224,48,81,26,44,186,232,162,109,130,42,66,43,194,106,69,120,245,35,192,209,222,203,
47,191,172,112,77,158,58,117,170,78,214,44,144,232,250,250,7,118,144,147,131,239,191,255,190,126,129,136,230,210,234,136,224,51,238,103,184,239,250,121,21,181,163,239,191,255,94,145,152,28,33,126,224,
192,129,86,55,141,81,199,226,202,59,14,56,14,100,195,1,148,134,130,45,160,209,55,197,139,71,73,74,136,68,29,95,123,237,181,106,203,45,183,212,33,66,137,26,10,168,44,224,125,90,56,76,203,37,22,180,219,
59,238,184,67,187,2,162,212,107,70,120,211,200,145,35,181,107,45,40,244,75,45,181,84,0,23,220,161,180,57,128,66,155,16,170,5,22,88,64,9,46,134,53,101,177,233,184,217,175,10,168,168,218,104,163,141,172,
101,55,48,237,59,139,114,135,30,122,168,90,126,249,229,245,179,156,69,127,89,245,81,10,193,19,129,83,64,64,212,75,47,189,148,21,223,10,217,143,32,133,234,116,43,8,114,252,33,136,162,117,69,160,65,128,
172,252,33,84,166,45,76,154,50,80,220,39,180,21,27,161,147,197,173,89,132,118,143,23,29,169,54,210,122,153,55,154,27,215,9,129,199,47,172,86,132,86,172,113,21,66,176,194,178,215,169,83,39,253,135,54,114,
193,5,23,172,156,206,245,39,214,206,75,46,185,36,149,241,10,216,144,182,250,10,50,159,21,171,57,188,199,10,207,115,69,250,28,167,244,202,245,173,229,6,231,56,16,139,3,40,30,73,253,197,26,138,167,3,202,
190,164,36,32,64,90,1,102,43,21,152,127,60,2,26,167,16,10,36,103,162,255,148,213,223,196,160,97,145,225,93,115,248,225,135,103,162,24,70,153,10,255,246,217,103,31,37,0,44,86,231,227,26,139,199,1,210,178,
145,194,140,52,66,127,252,227,31,83,223,35,137,171,183,246,58,192,11,15,37,53,123,216,50,18,86,92,12,6,236,63,203,68,165,16,60,185,48,220,136,184,193,57,42,15,7,176,196,162,80,192,237,178,25,26,85,63,
39,177,28,226,210,1,232,144,35,251,28,0,24,2,43,109,154,57,69,223,126,251,109,53,106,212,40,237,118,107,107,6,220,167,108,76,113,203,238,217,179,167,206,223,151,150,203,180,173,49,187,118,28,7,28,7,234,
115,128,156,224,15,61,244,144,246,4,194,155,138,205,180,45,23,190,199,30,123,76,43,125,143,56,226,136,250,3,176,112,6,112,146,172,114,24,146,59,157,188,218,93,187,118,85,7,29,116,80,42,150,47,192,141,
88,187,113,239,237,221,187,183,21,229,161,5,54,187,38,170,56,64,46,121,158,27,192,248,0,46,180,253,30,172,188,107,81,250,242,252,172,184,226,138,85,189,151,239,43,222,156,235,174,187,174,122,252,241,199,
173,132,172,229,133,67,165,16,60,215,92,115,77,237,246,193,205,238,168,28,28,192,138,196,139,83,128,97,114,229,70,3,162,46,200,201,184,23,57,178,203,1,1,217,208,241,180,182,98,59,235,141,14,5,2,11,185,
109,228,71,220,164,121,241,130,80,137,59,53,155,48,146,200,227,65,224,200,113,192,113,32,191,28,0,171,0,207,41,148,95,108,150,5,212,67,199,13,226,230,102,147,64,155,39,222,159,181,46,109,2,209,155,56,
244,205,54,219,44,237,174,218,218,135,127,244,75,24,2,113,151,219,108,179,77,34,225,131,120,90,218,251,250,235,175,181,53,13,43,167,109,97,166,109,240,238,139,53,14,96,149,6,1,153,251,128,88,104,44,211,
113,223,235,132,32,61,250,232,163,122,223,197,253,124,192,1,7,148,94,224,172,190,16,123,236,177,135,246,92,192,149,185,44,84,120,193,147,69,28,96,33,52,110,73,193,115,202,114,81,139,62,15,220,39,136,219,
0,116,161,99,199,142,185,155,14,26,107,92,128,251,246,237,155,187,177,21,117,64,143,60,242,136,126,126,73,183,147,5,241,98,20,164,90,45,124,166,225,58,141,107,244,123,239,189,167,133,80,54,181,104,46,
137,143,94,109,181,213,116,156,45,238,207,113,95,196,89,240,199,245,225,56,80,6,14,160,192,196,29,180,242,71,120,73,229,59,159,8,49,60,139,224,30,108,177,197,22,170,123,247,238,169,9,54,146,3,81,9,170,
184,118,215,205,130,183,196,97,158,126,250,233,26,27,33,139,254,170,251,192,205,23,37,28,74,62,190,19,186,3,159,1,213,227,15,101,92,245,186,139,37,107,214,172,89,138,112,8,62,137,167,101,125,68,1,128,
23,9,97,64,142,138,199,1,174,61,24,35,120,50,241,44,34,136,178,167,171,254,67,152,228,56,207,102,245,31,202,6,238,27,92,219,17,92,177,252,85,223,51,197,227,70,188,17,3,100,54,98,196,8,13,78,25,175,133,
252,213,42,188,224,73,128,190,164,237,208,230,253,252,177,215,141,40,14,7,206,61,247,92,157,135,137,77,122,94,9,52,183,110,221,186,101,170,77,206,43,47,146,142,139,151,19,46,213,128,4,100,73,228,89,149,
4,205,58,110,55,11,165,21,154,219,10,34,52,232,208,132,7,240,50,174,252,161,112,113,148,29,7,80,14,56,42,39,7,16,40,249,3,23,128,120,119,220,100,43,127,213,191,179,194,13,144,116,90,26,79,225,176,195,
14,203,148,225,184,166,226,142,184,233,166,155,102,218,175,191,51,214,184,138,80,129,192,207,58,200,250,135,66,110,225,133,23,214,194,5,194,8,66,8,159,54,226,104,253,99,112,191,155,207,1,64,43,81,42,240,
199,61,80,249,14,46,5,200,206,40,24,248,228,15,69,173,83,206,42,141,235,1,120,210,155,111,190,153,235,108,4,81,238,174,194,11,158,184,145,128,48,151,245,130,30,133,201,174,172,57,7,238,185,231,30,13,210,
130,139,78,222,9,171,236,5,23,92,160,95,156,121,31,107,158,199,39,121,231,20,232,109,54,210,238,68,157,231,187,239,190,171,221,244,129,228,207,106,19,26,117,140,174,188,227,128,227,64,49,57,128,114,227,
170,171,174,82,235,172,179,142,218,125,247,221,51,159,4,86,79,48,48,80,208,55,3,17,62,243,9,187,14,29,7,74,200,1,44,190,0,47,238,185,231,158,165,152,93,161,5,79,220,51,254,227,63,254,67,251,126,151,21,
213,170,20,119,153,225,36,208,126,225,86,112,254,249,231,27,214,104,110,49,52,184,0,42,224,18,236,40,30,7,112,119,37,213,9,113,27,205,34,16,158,17,60,207,62,251,108,13,93,222,172,113,184,126,29,7,28,7,
202,195,1,172,59,127,254,243,159,85,159,62,125,244,62,165,89,51,3,113,116,252,248,241,26,51,161,89,99,112,253,58,14,56,14,196,231,192,41,167,156,162,45,159,119,221,117,87,252,70,114,84,179,208,130,39,
65,231,67,134,12,81,207,62,251,108,142,88,234,134,18,151,3,164,209,0,174,158,252,148,69,33,210,171,176,40,224,46,228,40,26,7,112,185,2,138,31,161,175,217,132,43,24,150,87,52,139,128,98,56,114,28,112,28,
112,28,136,203,1,132,61,214,54,194,70,242,0,46,70,170,11,98,228,72,119,225,200,113,192,113,160,88,28,0,141,31,44,27,48,109,202,16,231,90,104,193,19,216,110,226,23,200,203,231,168,216,28,0,17,20,75,39,
194,103,145,104,250,244,233,234,245,215,95,215,90,237,34,141,187,217,99,173,184,128,145,42,39,47,57,99,225,9,65,252,239,191,255,190,34,1,187,115,189,109,246,93,226,250,119,28,40,22,7,112,173,37,173,27,
233,30,112,141,203,139,123,43,227,66,65,138,162,52,15,169,201,138,117,85,221,104,29,7,154,207,129,245,215,95,95,221,121,231,157,26,0,173,249,163,73,54,130,194,10,158,44,164,128,207,128,48,74,58,21,71,
197,230,0,129,211,104,115,200,151,86,52,34,45,7,47,116,71,230,28,24,52,104,144,182,44,146,114,36,111,52,123,246,108,197,248,246,219,111,63,141,116,153,183,241,185,241,56,14,56,14,228,143,3,160,88,19,42,
114,240,193,7,43,192,64,242,70,132,178,16,235,137,178,207,145,227,128,227,64,177,56,64,238,90,188,22,240,162,40,58,21,86,240,156,54,109,154,78,32,75,78,69,71,197,231,192,216,177,99,181,34,129,7,171,104,
4,192,16,127,142,204,56,64,46,84,18,180,231,25,16,12,197,214,253,247,223,175,176,104,99,185,88,106,169,165,204,38,231,74,57,14,56,14,180,20,7,136,81,31,60,120,176,94,35,142,58,234,168,92,35,113,62,249,
228,147,218,26,219,204,152,250,150,186,57,254,61,89,222,39,32,153,87,35,251,130,81,242,227,143,63,234,52,98,11,45,180,144,70,93,174,70,246,117,239,156,86,188,83,234,207,121,244,232,209,90,105,132,236,
83,116,42,172,224,121,225,133,23,234,60,121,184,198,57,42,62,7,136,65,217,117,215,93,11,9,238,226,4,79,243,251,15,173,251,53,215,92,163,145,30,205,107,53,175,36,46,115,215,93,119,157,134,248,31,48,96,
64,110,92,231,154,199,17,215,179,227,128,227,0,28,0,60,232,150,91,110,81,223,127,255,189,198,38,32,5,68,17,136,112,150,3,15,60,80,117,238,220,185,8,195,45,236,24,73,23,242,244,211,79,171,143,63,254,88,
145,42,107,249,229,151,87,157,58,117,210,185,73,87,90,105,37,69,10,145,106,2,103,128,60,166,148,231,143,119,229,252,243,207,175,17,145,183,219,110,59,45,152,86,151,119,223,91,139,3,172,55,228,25,38,7,
121,209,211,13,21,86,240,4,205,22,196,56,2,110,29,21,159,3,64,206,31,119,220,113,185,138,247,51,229,170,19,60,205,56,85,137,235,4,76,168,104,96,76,164,93,33,190,130,180,8,184,210,185,252,98,102,215,220,
149,114,28,40,27,7,200,63,73,28,231,87,95,125,165,250,247,239,175,133,137,34,205,17,33,232,228,147,79,214,110,183,126,225,167,72,243,200,227,88,121,199,145,27,250,197,23,95,212,194,1,161,67,93,186,116,
73,52,84,188,250,30,122,232,33,245,203,47,191,168,157,119,222,89,33,132,58,106,77,14,244,236,217,83,175,57,40,142,138,76,133,20,60,89,240,201,223,73,92,224,130,11,46,88,100,254,187,177,255,155,3,69,22,
222,46,191,252,114,13,220,128,118,210,81,125,14,96,233,4,49,182,91,183,110,245,11,229,252,204,27,111,188,161,112,121,193,53,138,220,163,43,172,176,66,206,71,236,134,231,56,224,56,96,131,3,132,7,144,206,
0,183,201,126,253,250,169,85,86,89,197,70,179,77,105,131,185,144,51,187,40,169,203,154,194,164,8,157,114,79,16,46,132,192,185,239,190,251,234,253,105,132,234,70,69,233,3,76,147,103,158,121,70,245,234,
213,75,21,33,215,185,209,196,92,33,99,14,96,108,3,252,144,61,72,145,169,144,130,231,3,15,60,160,95,0,196,43,56,42,7,7,138,44,120,14,27,54,76,161,137,194,125,198,81,48,7,120,89,18,223,114,200,33,135,4,
23,40,216,81,148,95,35,71,142,84,179,102,205,82,107,173,181,150,246,188,88,124,241,197,11,54,11,55,92,199,1,199,129,70,28,32,199,47,2,197,167,159,126,170,49,8,176,96,21,41,221,87,163,185,97,153,131,246,
218,107,175,70,197,220,185,16,14,224,250,56,124,248,112,45,112,110,181,213,86,33,165,237,156,198,2,58,121,242,100,69,76,241,26,107,172,97,167,81,215,74,238,57,240,209,71,31,105,229,61,64,156,115,205,53,
87,238,199,91,111,128,133,20,60,89,252,215,94,123,109,135,36,90,239,170,22,240,120,145,5,79,180,144,196,247,244,232,209,163,128,156,79,127,200,108,222,110,188,241,70,133,101,184,140,132,6,242,145,71,30,
209,160,29,43,175,188,178,214,70,47,183,220,114,101,156,170,155,147,227,64,169,57,64,156,221,148,41,83,244,31,41,190,240,104,0,123,160,172,74,69,176,50,80,6,174,186,234,170,165,190,174,105,76,142,216,
94,188,120,86,95,125,117,205,195,172,243,43,226,50,77,30,251,255,254,239,255,86,39,158,120,162,142,7,77,99,158,174,205,124,113,96,195,13,55,212,232,217,69,222,111,22,78,240,196,135,158,7,253,137,39,158,
208,26,200,124,221,18,110,52,113,57,80,100,193,243,213,87,95,85,255,248,199,63,212,238,187,239,30,119,250,165,173,87,137,39,186,250,234,171,91,194,45,30,112,136,9,19,38,168,25,51,102,40,98,193,136,9,229,
5,1,40,128,11,11,40,237,109,238,38,86,80,14,32,92,98,57,122,254,249,231,213,175,191,254,170,49,6,54,217,100,19,197,95,43,228,241,173,172,207,8,80,173,48,95,91,183,233,75,47,189,164,70,141,26,165,206,57,
231,28,213,161,67,7,91,205,198,106,7,32,34,210,228,156,112,194,9,137,227,73,99,13,192,85,202,148,3,196,119,98,229,102,207,92,84,42,156,224,249,202,43,175,168,99,142,57,70,177,217,119,84,30,14,20,89,240,
196,13,107,226,196,137,10,212,83,71,181,28,32,191,233,65,7,29,212,146,74,34,54,117,228,4,69,8,37,166,10,65,244,231,159,127,214,32,17,0,69,224,178,7,210,33,86,149,165,151,94,186,208,174,51,181,87,221,253,
114,28,104,14,7,80,76,147,166,130,20,39,32,82,243,87,249,206,57,220,225,23,91,108,177,182,79,158,65,158,63,16,94,91,21,104,135,247,215,77,55,221,164,0,125,115,20,206,129,123,239,189,87,223,99,199,30,123,
108,120,225,140,74,160,52,185,244,210,75,213,166,155,110,170,118,220,113,199,140,122,117,221,52,131,3,184,89,95,124,241,197,170,200,169,36,11,39,120,34,160,124,240,193,7,218,167,190,25,23,221,245,153,
14,7,138,44,120,226,234,130,198,248,236,179,207,78,135,57,5,109,245,193,7,31,212,233,71,0,66,112,84,203,1,128,34,190,251,238,59,109,41,159,51,103,142,250,250,235,175,53,104,73,109,41,247,203,113,192,113,
32,10,7,112,119,4,248,107,145,69,22,81,139,46,186,168,254,172,124,119,224,111,245,57,73,12,62,2,104,223,190,125,235,23,114,103,212,109,183,221,166,195,106,242,26,23,139,2,1,183,112,231,125,85,222,155,
149,112,128,245,214,91,79,97,117,47,106,174,215,194,9,158,164,81,57,247,220,115,213,62,251,236,83,222,59,171,5,103,86,100,193,147,203,85,244,241,219,190,229,136,123,4,148,195,9,227,182,57,235,218,115,
28,112,28,112,28,176,207,129,235,175,191,94,109,190,249,230,138,24,50,71,237,57,0,146,40,138,13,48,70,242,76,92,71,194,59,200,252,224,168,156,28,0,204,18,15,187,3,14,56,160,144,19,44,148,224,137,219,204,
198,27,111,172,211,168,252,254,247,191,47,36,195,221,160,219,115,160,12,22,67,39,120,254,118,93,113,41,61,235,172,179,212,117,215,93,167,230,158,123,238,223,78,184,111,142,3,142,3,142,3,142,3,185,228,
0,94,24,167,158,122,170,94,187,113,253,119,244,27,7,8,241,34,85,202,73,39,157,244,219,193,28,127,227,253,123,230,153,103,106,183,242,28,15,211,13,45,38,7,80,232,19,219,59,98,196,136,152,45,52,183,90,161,
4,79,130,185,113,117,120,250,233,167,155,203,53,215,187,85,14,0,204,3,180,251,192,129,3,173,182,155,101,99,78,240,252,127,110,179,121,249,211,159,254,164,95,122,110,243,146,229,29,232,250,114,28,112,28,
112,28,72,198,129,127,254,243,159,218,75,229,47,127,249,139,14,147,72,214,90,57,106,127,249,229,151,234,202,43,175,212,225,52,69,153,17,202,252,51,206,56,67,131,14,101,141,182,91,20,30,21,121,156,120,
148,225,78,77,90,149,34,94,223,66,9,158,125,250,244,209,64,0,44,2,142,202,195,129,233,211,167,171,119,222,121,71,245,238,221,187,176,147,114,130,231,255,95,186,27,110,184,65,123,37,108,180,209,70,133,
189,150,110,224,142,3,142,3,142,3,173,202,1,114,5,222,119,223,125,138,119,90,171,19,138,84,172,156,0,247,44,188,240,194,133,98,199,180,105,211,20,57,70,243,4,130,84,40,6,230,124,176,235,175,191,190,186,
235,174,187,116,188,103,206,135,218,110,120,133,17,60,89,0,72,163,130,101,172,107,215,174,237,38,226,14,20,151,3,47,188,240,130,250,233,167,159,212,14,59,236,80,216,73,56,193,83,169,103,159,125,86,205,
154,53,75,29,126,248,225,133,189,142,110,224,142,3,142,3,142,3,173,206,1,210,213,225,137,212,234,96,67,183,220,114,139,142,151,220,96,131,13,10,121,75,160,8,222,102,155,109,84,183,110,221,10,57,126,55,
232,250,28,32,214,152,88,94,44,219,69,163,194,8,158,88,196,14,62,248,96,245,198,27,111,20,141,199,110,188,33,28,120,228,145,71,84,199,142,29,85,81,23,119,166,119,249,229,151,171,83,78,57,165,101,147,56,
35,112,226,6,143,102,216,145,227,128,227,128,227,128,227,64,177,57,48,100,200,16,157,127,24,192,161,86,36,98,232,198,140,25,163,78,63,253,244,194,78,159,20,66,88,108,113,157,118,120,11,133,189,140,129,
3,39,173,15,207,40,86,237,162,81,97,4,79,210,85,0,31,76,138,6,71,229,226,192,221,119,223,173,182,218,106,43,213,169,83,167,194,78,108,216,176,97,10,164,49,160,204,91,141,128,247,62,237,180,211,212,160,
65,131,90,86,240,110,181,107,238,230,235,56,224,56,80,126,14,0,80,67,222,244,86,124,175,161,72,70,161,108,154,134,231,229,151,95,86,143,62,250,168,206,177,152,230,157,1,120,31,251,96,83,107,52,70,155,
201,147,39,171,163,143,62,58,205,97,185,182,51,230,192,247,223,127,175,141,53,111,190,249,166,78,33,149,113,247,137,186,43,140,224,185,197,22,91,104,23,190,254,253,251,39,154,176,171,156,63,14,160,141,
235,215,175,95,161,17,216,30,123,236,49,157,223,11,215,135,86,35,52,194,104,85,177,90,59,114,28,72,147,3,95,125,245,149,78,156,189,242,202,43,171,46,93,186,68,6,86,248,226,139,47,180,215,204,106,171,173,
166,58,119,238,28,121,168,108,250,94,125,245,85,189,86,225,190,54,207,60,243,68,106,131,124,173,36,254,94,113,197,21,213,26,107,172,17,105,252,88,47,136,135,39,118,139,241,147,246,194,116,83,28,105,144,
174,176,227,192,191,57,240,203,47,191,104,164,219,43,174,184,162,112,49,142,73,46,34,174,198,191,254,250,171,218,109,183,221,140,154,121,238,185,231,212,30,123,236,161,0,103,2,92,239,234,171,175,54,170,
23,181,16,235,207,174,187,238,170,5,201,139,46,186,72,253,249,207,127,54,106,226,252,243,207,215,239,232,37,150,88,194,168,188,43,84,12,14,108,189,245,214,218,34,111,122,159,230,102,86,18,59,153,123,146,
248,63,111,213,85,87,245,228,165,157,251,177,186,1,70,231,128,196,71,122,178,169,138,94,209,87,99,234,212,169,222,186,235,174,235,201,166,204,147,77,169,39,27,59,111,173,181,214,242,214,94,123,109,79,
226,130,245,57,73,188,235,73,80,182,39,249,96,189,77,54,217,196,147,184,68,95,43,241,126,210,183,184,12,199,171,92,224,90,226,234,225,73,140,110,129,103,224,134,94,4,14,124,240,193,7,158,228,44,243,230,
154,107,46,79,94,158,250,143,103,90,114,197,26,173,29,111,189,245,150,39,73,223,61,65,0,108,171,47,174,253,222,132,9,19,140,166,47,241,110,158,40,87,188,5,22,88,160,173,254,242,203,47,239,73,194,118,79,
54,231,161,109,252,237,111,127,243,14,58,232,160,154,241,179,46,137,43,159,209,248,197,157,74,175,95,149,185,243,217,161,67,7,239,158,123,238,9,237,219,21,112,28,72,194,129,255,250,175,255,242,78,60,241,
68,239,127,255,247,127,147,52,83,152,186,236,69,78,62,249,228,72,227,21,97,179,109,93,224,217,20,75,113,164,250,38,133,127,248,225,7,79,12,48,109,253,44,184,224,130,158,184,3,155,84,245,68,225,230,73,
24,140,81,89,87,168,56,28,16,43,182,39,217,32,138,51,224,127,143,84,21,97,196,162,125,242,36,206,160,8,67,117,99,140,193,1,209,198,197,168,213,190,10,66,80,245,198,204,228,251,9,39,156,208,190,161,24,
71,102,207,158,237,13,29,58,52,70,205,226,86,121,234,169,167,60,113,49,46,238,4,220,200,11,193,1,54,87,139,47,190,120,221,103,155,231,190,17,137,171,153,39,121,159,235,214,191,255,254,251,27,85,247,196,
138,225,173,185,230,154,117,235,31,117,212,81,13,235,207,156,57,211,19,75,67,221,250,146,240,189,97,125,201,33,232,205,55,223,124,117,235,75,190,220,134,245,221,73,199,129,164,28,120,247,221,119,189,11,
47,188,48,105,51,133,168,255,248,227,143,123,79,62,249,100,164,177,34,172,34,4,84,239,57,206,61,247,220,72,109,52,42,44,110,149,222,102,155,109,214,214,62,66,103,212,49,114,253,190,251,238,187,70,221,
184,115,5,227,0,74,127,222,77,69,163,66,184,218,226,198,247,227,143,63,170,219,111,191,93,158,107,71,101,227,128,77,68,88,98,82,76,211,237,224,26,51,122,244,104,43,238,106,228,205,34,14,153,196,190,173,
64,0,47,220,121,231,157,169,199,179,216,224,37,238,98,242,194,85,196,68,4,125,146,7,107,177,197,22,83,34,220,4,126,58,119,70,27,87,33,126,27,98,169,84,15,63,252,112,221,6,22,90,104,33,245,201,39,159,168,
122,121,99,65,117,196,21,174,30,45,181,212,82,186,254,34,139,44,18,88,4,119,182,75,46,185,36,240,92,229,32,248,3,226,65,81,249,89,243,9,250,96,35,108,2,217,68,234,100,224,203,46,187,108,77,189,202,143,
141,55,222,88,145,192,190,30,137,80,173,68,184,173,59,255,122,245,220,113,187,28,32,214,189,122,125,225,123,245,111,217,28,214,172,49,213,235,13,223,185,142,121,38,220,79,231,204,153,163,14,59,236,176,
60,15,51,241,216,8,29,185,234,170,171,34,183,195,245,21,37,84,205,62,149,189,13,110,174,73,72,44,157,106,231,157,119,214,24,39,180,195,122,193,122,24,53,11,128,40,199,117,189,227,143,63,62,201,112,92,
221,28,113,64,188,16,52,98,241,196,137,19,11,21,135,93,8,193,147,244,41,131,7,15,86,219,109,183,93,142,46,185,27,138,45,14,216,20,60,25,211,57,231,156,163,46,187,236,178,134,195,219,111,191,253,148,88,
58,212,188,243,206,219,176,92,148,147,182,231,17,165,239,44,203,18,199,114,214,89,103,105,164,60,155,252,75,58,7,132,15,113,201,84,196,241,17,11,200,31,49,117,108,8,196,45,177,238,31,231,43,229,131,62,
197,189,179,166,238,50,203,44,163,68,203,168,136,51,116,148,46,7,80,22,44,185,228,146,138,248,198,70,116,235,173,183,170,35,143,60,178,93,145,191,255,253,239,70,47,228,145,35,71,214,205,35,44,97,30,90,
48,109,215,120,213,129,227,142,59,78,145,186,192,79,196,100,33,84,176,65,104,68,160,19,2,226,226,39,54,139,38,247,25,249,220,76,193,70,252,125,184,223,209,56,240,233,167,159,42,177,0,234,116,35,95,126,
249,165,226,143,117,131,117,2,229,7,107,141,255,147,99,156,175,148,173,124,82,175,242,253,127,254,231,127,106,234,162,136,144,80,17,181,202,42,171,68,27,96,138,165,111,190,249,102,189,209,5,115,163,140,
196,122,49,126,252,248,216,185,47,89,167,142,56,226,8,5,216,96,133,80,90,177,39,137,67,172,127,8,157,21,228,210,184,66,103,165,111,82,111,152,42,230,43,117,220,103,190,57,64,124,231,62,251,236,163,10,
133,127,35,155,174,92,147,104,216,116,172,158,88,148,114,61,78,55,184,248,28,176,229,106,91,61,2,177,82,180,185,165,200,178,81,243,253,144,67,14,241,4,56,160,186,184,149,239,105,204,195,202,192,44,54,
66,156,15,177,110,196,253,52,147,112,109,122,239,189,247,60,201,179,230,113,173,229,197,238,9,188,184,118,139,76,123,92,184,61,201,70,95,247,121,222,121,231,121,146,70,198,35,134,207,145,125,14,224,226,
231,127,126,131,126,215,115,107,195,21,41,168,188,255,152,120,43,212,29,188,0,8,133,182,209,171,87,175,192,250,196,166,250,251,10,250,93,47,38,76,144,50,141,234,11,248,75,96,255,238,96,114,14,72,170,40,
79,144,215,61,158,117,214,25,158,247,111,190,249,38,121,195,33,45,176,206,136,87,73,219,58,115,199,29,119,120,51,102,204,8,169,149,254,105,238,85,220,199,203,72,2,116,232,17,207,157,132,120,71,30,122,
232,161,53,207,109,156,231,83,172,229,158,120,59,180,181,19,199,189,214,63,143,251,238,187,207,123,251,237,183,253,135,221,239,2,115,128,216,93,241,222,43,212,12,114,31,227,201,102,114,199,29,119,44,20,
83,221,96,163,113,32,45,129,77,44,144,109,139,118,101,179,39,218,200,212,64,18,210,154,71,52,110,166,91,90,224,229,61,129,239,78,183,147,58,173,19,107,55,110,220,56,45,104,138,230,86,11,127,98,125,168,
83,58,187,195,196,247,178,41,100,76,108,78,1,153,146,208,128,236,6,80,226,158,190,253,246,219,26,64,158,202,115,236,255,68,1,17,68,8,13,254,178,65,191,71,140,24,17,84,93,31,19,139,99,104,27,199,30,123,
108,96,125,0,65,36,127,94,104,253,27,111,188,49,176,62,10,158,106,64,164,160,177,115,108,212,168,81,129,245,221,193,232,28,64,201,61,105,210,36,79,80,67,53,72,12,0,82,31,126,248,97,244,134,44,215,64,216,
67,232,69,240,227,221,70,140,223,207,63,255,108,185,151,240,230,0,211,226,126,23,107,126,120,225,130,149,144,80,25,43,35,70,177,221,167,79,159,154,231,190,145,114,203,223,41,235,222,70,27,109,212,86,223,
134,208,73,31,180,43,110,196,254,238,220,239,2,115,0,12,4,192,87,81,120,20,133,114,47,120,246,238,221,91,107,252,138,194,80,55,206,232,28,72,83,96,187,248,226,139,219,22,111,128,132,176,148,165,69,105,
206,35,173,49,71,105,87,220,17,189,135,30,122,40,74,149,196,101,37,110,202,147,248,56,79,92,123,245,102,11,11,80,154,215,48,233,128,89,252,177,178,33,128,178,137,145,88,28,35,212,211,164,253,150,185,254,
238,187,239,222,246,12,7,9,94,0,7,53,178,82,84,35,65,6,213,7,248,7,235,82,61,226,222,11,170,87,125,108,202,148,41,245,170,107,52,221,234,178,254,239,32,229,126,254,249,231,117,235,163,205,246,215,169,
254,45,174,223,165,20,2,234,50,36,133,19,172,41,207,63,255,188,126,110,185,222,0,26,230,217,203,10,193,6,68,118,44,176,120,124,60,253,244,211,153,110,60,121,222,36,207,101,174,215,226,168,183,9,239,26,
246,11,182,136,107,180,255,254,251,215,60,187,38,64,96,88,211,37,85,82,91,61,132,78,238,71,91,196,61,227,168,92,28,0,161,93,210,124,21,102,82,185,22,60,121,25,72,174,53,79,114,151,21,134,161,110,160,209,
57,144,182,192,70,202,129,122,22,145,232,163,173,95,35,237,121,212,239,57,253,51,8,124,215,94,123,109,250,29,253,187,7,172,136,18,27,163,173,136,244,93,84,66,8,21,176,10,79,98,142,27,10,23,69,157,95,22,
227,254,232,163,143,60,1,127,106,219,136,85,11,93,124,15,67,133,197,66,207,230,205,95,175,242,27,55,202,70,132,213,146,244,76,149,242,254,207,1,3,6,52,170,174,83,30,72,156,103,221,250,131,6,13,106,88,
255,147,79,62,105,56,127,20,51,142,226,113,0,171,157,196,45,106,33,10,37,81,26,33,24,241,70,102,94,11,101,151,128,139,120,167,158,122,170,126,22,26,41,81,204,91,13,47,41,249,100,189,40,86,188,240,22,155,
91,130,148,69,182,83,162,73,220,174,39,224,98,109,207,62,222,11,245,188,27,152,61,66,39,66,68,101,141,177,45,116,210,7,138,138,60,43,111,25,163,163,104,28,16,204,18,15,111,180,162,80,174,5,79,226,123,
200,203,232,168,220,28,192,58,84,6,42,203,60,252,215,2,119,86,242,148,101,241,178,66,200,64,35,139,144,155,213,6,202,63,223,52,126,179,161,192,197,137,151,126,89,227,163,210,224,91,165,77,226,121,247,
222,123,239,182,13,25,27,179,213,87,95,93,187,152,154,220,151,111,188,241,134,39,32,29,53,245,201,3,106,186,209,4,107,128,116,9,2,166,213,214,134,0,200,120,2,122,103,100,209,126,255,253,247,189,125,247,
221,183,198,109,150,124,195,184,248,154,140,31,87,79,220,27,5,193,87,247,79,62,211,61,247,220,211,251,235,95,255,90,97,145,251,140,192,1,148,9,172,49,172,53,121,136,155,140,48,244,134,69,5,28,199,67,1,
42,0,50,153,196,161,226,5,67,248,67,25,136,212,96,166,121,49,163,204,23,203,121,245,218,133,240,25,164,8,39,79,61,249,197,211,20,58,25,55,138,150,207,62,251,44,202,20,92,217,156,115,0,229,233,166,155,
110,154,243,81,254,54,188,92,163,218,130,100,43,238,36,74,22,54,121,22,29,149,149,3,34,176,41,137,167,41,252,244,68,168,40,68,122,145,40,140,254,233,167,159,20,240,242,164,138,17,151,192,40,85,35,149,
21,171,142,134,161,95,110,185,229,52,58,91,222,83,11,68,154,92,85,97,80,78,73,11,37,130,168,70,97,93,113,197,21,171,206,186,175,97,28,16,23,63,37,150,22,141,244,186,246,218,107,107,164,208,176,58,213,
231,101,195,165,94,127,253,117,37,66,159,90,99,141,53,20,169,116,162,16,233,49,166,78,157,170,211,238,116,239,222,93,73,126,205,40,213,53,226,178,184,68,105,164,221,117,214,89,39,242,248,73,217,33,66,
184,70,58,5,237,215,81,52,14,176,158,241,252,129,38,11,10,114,89,159,63,158,19,144,158,89,71,73,241,177,232,162,139,70,99,84,132,210,32,200,11,184,150,226,126,46,50,137,155,173,70,107,23,48,49,235,211,
16,225,83,145,86,73,20,93,186,109,214,29,137,215,85,226,45,161,127,131,190,78,122,20,214,38,72,44,157,122,223,43,248,38,250,183,205,127,146,167,84,73,120,65,221,244,79,54,251,114,109,101,195,1,137,221,
85,61,122,244,80,2,28,165,239,157,108,122,141,223,75,174,5,207,237,183,223,94,195,4,139,166,55,254,12,93,205,220,115,64,92,97,149,104,107,148,88,48,114,63,214,122,3,148,24,45,37,241,143,177,97,216,235,
181,219,204,227,162,159,82,167,157,118,154,18,23,46,133,64,152,6,177,65,18,240,14,157,50,131,141,96,89,5,78,63,239,16,64,69,235,173,243,19,147,70,163,94,14,74,127,61,247,219,113,192,113,32,58,7,72,85,
66,202,25,242,15,35,136,173,146,163,20,37,209,103,99,94,131,247,18,41,80,72,1,69,154,143,52,114,18,139,197,94,157,124,242,201,58,95,101,145,149,33,105,167,67,35,159,52,105,47,38,76,152,160,47,32,233,117,
4,148,78,145,79,188,103,207,158,74,188,50,244,241,52,133,78,58,64,113,38,160,101,138,52,28,142,202,195,1,82,28,113,15,115,47,229,157,114,43,120,74,172,133,214,72,11,104,67,106,155,222,188,95,156,86,25,
31,47,71,172,218,65,121,236,138,194,3,114,248,137,59,141,90,97,133,21,138,50,228,208,113,138,43,154,218,106,171,173,148,0,29,132,150,141,90,64,80,95,181,192,201,134,16,197,146,196,240,69,109,162,20,229,
177,124,74,204,143,90,100,145,69,212,192,129,3,11,161,173,44,5,227,221,36,90,134,3,88,153,4,165,86,245,235,215,79,145,19,188,21,73,92,181,181,133,13,171,8,57,172,163,90,250,195,120,38,97,17,10,143,31,
73,71,162,4,197,57,172,120,46,207,167,45,120,50,105,65,33,86,123,237,181,151,18,176,32,205,3,132,79,242,244,226,241,3,225,85,36,177,198,42,13,75,167,238,64,254,97,21,147,244,95,74,92,255,43,135,220,103,
9,56,192,250,134,226,7,239,180,188,83,110,5,207,23,95,124,81,107,209,4,88,36,239,60,116,227,179,192,129,34,39,54,22,112,7,237,162,35,49,124,22,56,145,143,38,120,249,241,146,20,84,62,171,3,194,138,42,113,
109,218,165,232,248,227,143,79,197,213,141,62,112,137,68,171,203,31,110,117,184,40,226,238,20,244,199,4,113,153,12,250,67,251,140,53,242,15,127,248,131,254,67,64,182,189,105,163,127,54,30,67,134,12,209,
150,127,183,33,128,35,142,28,7,146,113,64,226,106,181,187,233,46,187,236,146,218,70,30,5,218,151,95,126,217,246,135,203,27,150,45,20,106,172,53,213,159,172,75,172,49,18,39,92,243,201,49,92,31,89,103,42,
127,11,47,188,112,178,201,215,169,61,121,242,100,53,102,204,24,45,132,175,183,222,122,117,74,197,59,12,191,105,91,114,234,198,107,160,201,181,178,16,60,153,34,239,34,137,207,86,130,68,92,51,227,44,132,
78,58,196,157,87,192,251,180,123,116,205,0,220,143,66,115,64,0,198,20,251,104,1,211,203,253,60,114,43,120,94,120,225,133,138,133,108,248,240,225,185,103,162,27,96,114,14,224,110,75,204,86,26,214,181,228,
163,107,220,130,36,249,86,196,123,173,191,254,250,141,11,22,228,236,59,239,188,163,198,143,31,175,36,29,136,213,17,19,155,134,123,41,26,119,220,66,108,18,46,187,146,14,65,9,32,153,22,58,5,132,69,91,55,
136,59,34,150,47,110,124,42,155,4,214,33,218,229,143,223,130,80,170,186,117,235,166,173,193,182,93,100,137,105,135,247,199,29,119,156,142,67,180,201,163,178,183,197,61,240,220,115,207,233,24,80,174,207,
54,219,108,19,73,177,33,121,98,149,160,16,43,54,231,184,150,83,159,251,199,84,209,128,144,193,166,238,165,151,94,210,49,156,220,227,81,238,15,188,124,112,183,163,62,253,111,185,229,150,218,69,178,236,
215,205,246,252,80,152,73,218,10,237,182,47,128,80,90,208,179,213,7,130,38,215,231,149,87,94,209,10,45,126,179,190,172,185,230,154,250,15,23,94,172,88,81,8,87,85,1,5,210,235,12,107,13,127,8,163,220,59,
188,15,55,219,108,51,171,49,154,40,74,135,14,29,170,227,141,37,37,138,178,41,228,62,250,232,163,138,48,130,3,14,56,32,10,11,114,81,54,43,193,147,201,114,141,177,190,115,45,42,36,160,80,138,49,164,77,8,
38,40,58,177,188,58,42,15,7,88,247,4,140,85,97,172,67,145,149,103,202,173,224,185,241,198,27,107,139,103,17,23,176,60,95,240,188,142,141,5,248,196,19,79,84,146,90,32,149,56,148,180,230,141,53,77,210,57,
148,6,84,8,215,79,148,62,184,76,69,221,64,213,227,49,27,114,120,4,104,3,2,149,13,240,6,218,100,3,136,144,192,70,7,139,228,118,219,109,167,23,94,83,65,161,222,120,195,142,179,81,68,64,64,72,132,95,108,
220,182,222,122,107,13,214,96,195,205,12,75,9,252,98,243,137,27,178,13,126,133,205,169,232,231,1,6,97,211,198,181,169,166,147,78,58,73,175,41,97,247,50,27,102,73,248,174,4,237,180,186,186,2,103,96,212,
168,81,218,133,169,230,132,239,7,33,33,135,30,122,104,155,203,28,167,185,23,4,13,90,3,167,113,45,27,17,155,133,67,14,57,68,225,18,89,33,238,99,214,68,129,201,143,173,56,169,180,213,42,159,92,7,172,110,
196,28,226,194,104,131,80,196,61,245,212,83,10,0,24,174,35,10,5,132,193,184,202,44,211,49,177,14,112,95,160,80,3,20,137,205,36,247,35,74,78,27,107,28,138,154,171,175,190,90,237,180,211,78,86,45,194,188,
195,89,139,139,166,136,101,253,224,47,109,18,148,120,173,212,18,52,229,154,174,136,191,229,222,149,188,197,53,199,109,255,120,235,173,183,148,160,199,235,120,83,219,109,187,246,154,203,1,214,7,246,12,
196,18,231,154,196,253,35,119,36,90,68,157,191,83,220,229,114,55,54,55,160,244,56,48,107,214,172,204,210,118,216,154,5,73,180,203,146,246,131,28,118,226,254,234,217,124,238,100,211,230,137,176,233,73,
76,73,98,150,139,80,225,201,198,82,167,11,56,243,204,51,61,1,105,48,74,101,145,184,227,144,6,196,10,170,211,114,136,155,139,39,27,23,143,124,112,140,53,41,145,78,10,222,125,240,193,7,73,155,42,117,125,
177,222,180,165,32,144,151,109,187,239,228,80,109,68,178,17,243,100,211,215,174,94,165,173,93,119,221,181,225,245,148,152,169,134,121,66,101,35,208,168,123,125,125,69,121,81,183,255,195,15,63,188,97,125,
119,210,243,68,219,175,243,254,10,128,144,21,118,144,190,231,138,43,174,208,57,120,239,189,247,222,76,82,147,132,13,156,20,48,164,223,33,47,240,165,151,94,234,145,159,214,6,137,98,69,167,121,98,223,101,
131,88,251,68,225,227,137,11,178,141,230,50,107,131,52,52,105,19,105,76,72,3,85,89,91,200,239,43,192,79,109,191,69,177,145,122,122,26,81,216,122,130,108,155,246,84,93,251,77,224,192,9,39,156,224,9,136,
88,19,122,142,214,101,46,243,120,62,249,228,147,158,104,21,163,205,196,149,46,5,7,120,153,34,84,228,61,145,55,227,99,156,108,90,203,66,146,210,198,19,23,32,107,211,145,180,5,58,193,120,210,107,201,166,
146,182,196,250,227,9,114,176,39,214,206,216,99,100,83,196,6,142,220,164,8,118,188,132,249,155,62,125,186,62,38,238,150,13,133,140,176,142,197,74,161,115,75,50,86,113,193,246,248,157,132,152,43,130,147,
184,162,39,105,166,180,117,17,250,197,37,177,109,227,86,217,208,85,127,10,82,178,71,142,188,122,36,232,142,13,235,211,150,128,129,212,171,238,9,16,72,195,250,98,157,242,16,78,235,145,184,188,53,172,79,
255,226,218,89,175,122,203,31,175,228,56,253,228,147,79,18,241,66,188,110,244,250,130,208,36,169,46,60,214,130,36,36,158,24,158,0,231,121,8,177,98,185,212,10,41,214,25,132,143,164,235,140,88,64,61,114,
247,49,86,9,71,74,252,190,100,76,40,29,27,221,167,81,120,193,26,139,210,44,201,90,29,165,63,27,101,89,103,89,79,210,34,238,5,113,203,110,123,214,5,47,64,223,23,188,115,5,148,176,237,56,194,231,216,177,
99,211,26,134,39,248,13,158,164,116,74,173,125,215,112,243,56,192,94,70,220,254,155,55,0,195,158,115,233,106,75,222,64,220,90,128,154,118,212,122,28,16,11,143,70,60,197,229,147,120,186,188,145,88,180,
212,3,15,60,160,0,199,41,114,10,152,106,190,18,75,77,174,55,27,16,235,196,61,225,178,68,110,183,36,177,156,196,44,144,2,97,230,204,153,218,141,145,24,96,19,18,65,87,201,6,79,187,61,130,182,136,251,100,
229,15,183,92,230,217,161,67,135,182,63,89,43,117,188,22,110,211,252,81,134,24,81,202,85,254,184,15,87,93,117,85,181,214,90,107,25,163,54,18,75,115,255,253,247,171,46,93,186,232,241,135,185,91,54,154,
219,51,207,60,163,193,40,68,43,159,186,139,95,163,113,228,237,28,49,153,38,247,152,108,228,52,234,180,127,252,220,43,92,107,220,26,27,17,174,155,160,60,251,137,123,157,123,68,20,26,254,83,53,191,197,66,
21,24,51,141,203,56,174,218,97,253,159,115,206,57,234,146,75,46,169,105,211,253,80,58,47,34,113,181,196,163,199,117,73,231,218,225,226,136,91,43,107,22,72,222,38,68,61,98,245,72,209,2,168,16,107,12,113,
194,149,79,82,67,85,175,51,184,199,86,214,24,246,55,172,51,92,251,202,26,3,178,53,235,76,167,78,157,52,222,129,169,219,62,241,166,184,131,3,22,116,224,129,7,38,226,3,136,152,43,173,180,146,149,24,77,222,
227,140,11,180,219,34,16,239,64,220,152,89,227,109,211,23,95,124,161,182,221,118,91,157,131,151,182,185,230,32,219,110,178,201,38,186,43,81,154,232,52,24,220,75,16,0,84,236,49,200,253,105,155,136,127,
38,44,160,200,169,111,108,243,164,44,237,17,178,70,236,48,251,133,142,29,59,230,118,90,185,20,60,89,64,137,107,17,23,167,220,50,206,13,44,93,14,240,34,39,110,11,95,117,147,141,101,186,163,17,147,131,8,
39,196,249,136,53,94,39,234,5,32,39,44,110,44,237,49,217,106,159,141,27,241,138,228,235,76,74,196,175,240,236,178,217,88,118,217,101,99,53,199,102,28,176,41,32,223,251,247,239,175,5,183,70,13,113,109,
128,136,255,235,95,255,170,21,86,148,221,96,131,13,116,236,146,173,188,117,128,10,129,26,7,175,216,64,18,83,10,248,12,194,112,88,188,21,160,68,8,208,0,222,16,71,104,186,161,244,207,217,6,111,253,109,22,
253,55,201,208,77,222,19,240,191,111,223,190,237,166,203,230,159,13,127,24,113,31,2,200,226,39,64,97,216,168,135,81,61,193,21,1,4,225,36,140,200,61,9,48,151,163,223,56,64,28,52,249,41,227,226,64,176,110,
0,228,5,32,21,235,57,185,164,195,8,128,52,82,179,16,31,73,125,246,42,160,230,162,188,176,65,40,219,16,72,166,77,155,166,155,3,96,136,117,134,205,100,216,58,195,218,132,162,11,64,162,222,189,123,199,126,
63,145,126,134,184,86,241,232,9,237,51,108,206,180,197,218,201,120,242,78,204,153,181,218,54,146,59,168,199,196,188,210,62,132,208,201,187,196,127,191,137,213,89,11,159,40,51,32,20,41,247,221,119,159,
245,241,240,110,102,111,229,168,156,28,32,102,27,197,2,123,141,220,146,44,158,185,34,226,203,86,91,109,53,15,87,18,71,173,205,1,220,34,31,123,236,49,29,247,41,185,14,61,73,141,145,57,67,112,141,146,69,
218,19,141,186,39,130,167,135,59,86,153,136,56,28,220,181,224,117,82,34,158,83,54,216,137,220,149,112,165,165,141,48,23,102,220,119,69,88,214,49,149,196,86,202,134,203,19,107,66,210,41,24,215,231,94,196,
253,149,190,197,50,239,9,0,72,168,187,155,108,38,53,175,185,167,227,18,113,88,196,113,216,136,153,141,59,134,60,213,35,46,92,94,174,161,127,146,52,189,238,176,5,132,38,180,190,88,59,3,235,227,74,45,130,
107,104,253,155,111,190,57,176,62,235,137,8,158,161,245,5,176,37,176,126,43,30,132,103,178,121,214,241,222,113,231,47,150,114,237,186,207,26,210,136,232,139,184,114,194,16,136,173,196,125,94,132,206,70,
85,172,158,99,125,22,225,67,247,77,252,248,164,73,147,66,215,25,73,69,167,231,38,233,58,98,143,69,132,88,239,180,211,78,75,28,42,192,0,174,188,242,202,208,245,60,246,64,45,86,228,157,114,222,121,231,89,
108,209,211,113,174,130,52,218,246,124,179,86,112,239,213,35,177,140,122,162,204,104,43,47,74,74,253,110,171,87,62,206,113,241,158,136,83,205,213,41,8,7,206,58,235,44,239,160,131,14,202,245,104,115,23,
227,41,26,72,79,52,124,185,102,154,27,92,246,28,96,163,45,26,127,45,104,176,112,2,178,32,86,81,107,3,225,165,131,144,73,187,60,184,2,195,223,182,209,16,228,82,107,253,228,169,33,230,76,28,142,13,112,164,
215,94,123,77,11,231,113,5,115,4,77,226,34,195,54,75,196,201,72,190,84,189,41,18,173,113,232,38,44,11,126,19,199,36,168,168,90,65,130,128,192,230,161,17,1,138,132,176,79,236,87,28,162,63,54,133,196,168,
58,242,60,113,143,108,219,168,5,9,161,130,64,218,80,177,34,238,133,13,235,3,0,210,8,40,5,69,64,80,191,149,99,212,111,20,99,74,172,120,165,108,208,167,88,211,188,57,115,230,184,75,45,28,96,125,65,217,19,
55,22,81,242,23,234,117,93,220,24,27,222,19,40,150,80,54,136,23,136,142,137,75,26,171,109,227,226,177,94,3,10,35,72,201,122,13,100,45,108,68,227,198,141,243,0,191,35,6,54,14,9,242,169,86,2,38,157,59,215,
140,181,189,8,239,81,222,253,182,136,103,94,144,125,219,158,109,0,196,4,133,61,180,121,234,109,180,209,70,109,245,16,62,137,231,181,65,220,255,245,148,96,54,218,119,109,52,159,3,130,184,175,1,172,154,
63,146,250,35,200,157,171,45,113,115,178,192,42,121,56,228,29,236,200,113,160,61,7,184,63,136,225,195,245,176,146,172,27,247,204,70,127,242,242,211,13,213,115,87,194,173,5,248,125,226,241,136,219,108,
133,248,7,226,206,246,221,119,95,157,127,174,61,151,205,143,224,126,38,200,143,138,246,234,241,183,94,107,184,58,146,186,5,119,195,35,143,60,178,174,27,42,9,175,113,117,196,77,9,183,199,188,230,169,34,
134,139,216,116,92,230,6,12,24,160,150,95,126,249,192,169,115,175,178,198,17,35,40,66,168,90,112,193,5,3,203,213,59,72,124,153,108,192,213,192,129,3,85,231,206,157,235,21,107,137,227,184,168,225,198,140,
123,190,159,112,181,38,214,150,92,139,245,136,107,65,92,31,177,219,65,132,219,55,169,78,234,17,113,196,164,142,32,78,43,136,100,211,168,93,159,130,206,113,140,123,0,215,112,98,226,130,136,251,132,235,
236,72,105,23,126,92,107,201,175,26,133,170,159,55,17,130,116,142,207,160,250,34,224,43,1,50,211,49,118,172,51,184,212,231,145,184,215,89,103,136,39,101,157,169,231,238,77,236,176,120,11,233,124,145,162,
32,137,156,170,140,152,67,238,63,177,90,198,118,221,133,127,226,201,166,196,98,171,227,164,243,28,162,114,167,228,228,222,124,243,205,67,195,59,194,238,9,230,219,179,103,207,54,151,105,98,121,69,225,168,
115,243,134,213,229,60,215,117,143,61,246,208,169,116,248,13,207,120,255,9,194,53,63,99,19,247,194,222,123,239,93,247,189,20,187,97,87,49,55,28,16,113,79,187,230,139,103,149,90,69,242,10,231,146,234,203,
164,205,57,35,47,20,237,66,215,156,222,93,175,142,3,173,193,1,1,211,208,8,142,73,103,43,155,109,173,85,143,99,233,196,186,137,91,109,35,205,61,231,112,127,194,146,152,20,101,50,233,92,163,212,199,138,
140,139,25,110,184,141,44,160,104,160,177,6,224,170,27,149,100,51,173,235,130,208,219,234,4,15,176,80,97,41,16,229,135,135,123,155,196,26,123,178,113,54,98,141,108,244,180,75,35,8,183,2,236,225,137,194,
64,223,215,166,104,178,184,95,210,159,40,1,180,165,66,114,60,106,119,39,137,59,110,104,89,171,12,14,11,155,228,84,244,68,241,165,235,131,108,41,113,113,218,3,192,134,27,124,165,159,34,127,146,222,132,
84,69,81,9,183,81,16,91,27,121,24,96,209,198,157,150,107,104,211,147,38,234,88,163,150,103,77,100,109,100,141,108,180,142,242,28,96,153,7,245,50,42,225,141,98,195,5,21,196,122,188,85,242,76,132,122,145,
170,38,9,209,70,181,197,18,143,5,214,129,168,68,88,69,53,98,182,8,159,26,221,61,106,59,213,229,113,23,119,84,126,14,72,220,185,55,108,216,176,220,78,52,87,22,79,128,22,72,204,12,80,72,18,4,200,92,74,248,
110,80,142,3,57,225,0,22,74,113,195,82,226,86,148,104,68,0,108,8,4,189,146,141,143,182,16,152,54,134,53,16,13,58,86,168,122,192,32,160,67,222,116,211,77,26,45,148,132,200,88,58,139,72,88,38,134,12,25,
162,45,154,226,190,93,215,210,130,85,12,11,190,184,208,70,90,251,224,165,184,222,41,16,160,151,90,106,169,34,178,200,250,152,5,31,160,46,159,77,58,131,167,88,74,163,90,239,105,91,222,244,74,226,78,181,
165,12,84,211,56,68,125,60,0,108,1,214,196,25,67,222,234,176,22,224,141,130,21,201,148,240,10,184,225,134,27,180,23,197,49,199,28,19,104,177,3,248,6,208,38,214,27,214,153,162,62,67,88,221,225,17,150,49,
230,26,4,152,197,189,41,155,81,141,172,43,46,184,145,214,108,188,1,68,57,166,200,56,144,132,36,148,69,175,229,38,128,96,73,250,73,82,23,132,100,214,83,144,101,163,18,150,74,192,93,42,222,19,172,1,88,158,
36,124,44,106,83,186,60,30,93,128,29,73,10,20,253,155,53,9,11,52,96,99,81,9,192,42,113,187,174,251,206,141,218,158,43,159,95,14,224,93,0,80,214,232,209,163,243,57,200,60,137,196,228,46,18,244,175,60,13,
201,141,197,113,160,84,28,192,178,131,246,159,120,161,36,132,69,79,54,56,30,90,217,40,68,220,144,108,240,60,64,97,130,8,235,14,9,219,137,123,35,183,92,89,136,249,18,151,73,12,113,61,11,86,24,111,234,241,
130,107,202,181,16,183,229,122,69,220,113,199,129,194,114,128,103,70,54,80,145,198,143,151,1,235,28,86,182,122,68,155,196,75,226,181,81,22,98,205,36,6,22,224,179,122,235,12,120,9,172,193,130,200,28,105,
218,196,212,147,79,57,41,73,74,40,111,198,140,25,73,155,73,173,62,49,114,130,130,29,185,125,172,207,226,166,219,22,155,73,254,96,73,107,17,185,29,127,5,98,108,69,65,219,214,46,30,29,128,45,70,37,238,139,
164,241,186,81,251,116,229,155,195,1,240,31,0,105,205,43,161,161,205,13,73,28,139,94,16,115,51,32,55,16,199,129,18,113,128,141,8,96,19,141,128,82,76,166,203,203,11,80,162,70,128,41,65,237,128,10,12,26,
101,189,151,31,224,78,113,221,193,130,250,203,227,49,73,221,160,221,99,235,1,126,136,181,77,11,221,81,93,111,113,245,196,101,55,169,66,33,143,60,115,99,106,93,14,224,162,40,30,3,145,24,0,208,25,46,252,
8,2,65,132,208,195,179,18,134,104,27,84,183,40,199,112,169,69,240,174,7,64,38,150,94,45,160,130,216,27,133,16,104,37,69,74,148,42,237,202,178,254,35,248,230,57,115,1,10,9,66,25,76,9,165,159,196,137,183,
9,135,18,179,175,81,240,77,235,135,149,99,93,239,215,175,95,91,251,8,159,146,78,40,172,90,219,121,238,131,91,111,189,181,237,183,251,82,110,14,176,215,147,20,76,30,202,236,60,82,174,4,79,201,137,23,43,
214,41,143,140,117,99,114,28,200,27,7,208,146,74,146,244,196,195,2,249,207,52,118,174,210,25,41,1,234,189,248,120,169,10,192,144,254,139,242,178,175,180,93,180,79,54,94,196,58,113,61,234,197,198,14,30,
60,56,178,149,135,24,54,172,9,142,28,7,202,192,1,44,115,40,170,162,16,86,57,113,255,15,180,246,241,172,137,155,162,71,172,168,184,48,70,105,182,144,101,89,75,89,87,137,125,174,183,174,94,119,221,117,222,
131,15,62,24,105,126,240,143,184,217,36,84,177,204,38,105,35,205,186,164,6,3,69,223,148,136,13,23,159,70,253,135,208,41,249,190,77,171,26,151,67,152,64,153,80,233,7,225,19,132,116,19,66,225,92,79,225,
107,82,223,149,41,30,7,184,39,5,144,42,151,3,207,141,224,73,14,62,128,21,220,195,145,203,251,196,13,170,224,28,0,198,253,182,219,110,75,60,11,132,165,168,90,114,22,191,122,174,114,51,103,206,212,214,211,
122,154,249,196,3,206,113,3,21,208,147,122,46,197,184,28,35,176,71,33,0,155,242,250,178,137,50,15,87,182,181,57,0,64,11,155,236,122,2,83,16,119,36,14,206,147,56,199,160,83,58,29,13,237,145,75,183,213,
136,181,21,15,21,214,218,32,194,138,73,30,100,83,66,0,194,162,220,8,52,205,164,45,172,217,121,94,171,80,226,153,230,14,199,165,22,215,90,64,197,80,126,164,73,184,204,34,124,242,89,79,113,89,221,63,121,
163,73,247,229,168,181,56,0,88,218,62,251,236,147,203,73,231,70,240,116,241,157,185,188,63,220,160,74,192,1,220,48,137,47,76,74,184,202,222,121,231,157,145,154,97,67,51,106,212,168,192,58,79,60,241,132,
119,238,185,231,122,184,151,182,42,225,110,198,6,162,30,234,33,249,219,162,90,36,176,234,68,85,14,180,42,255,221,188,243,199,1,4,27,242,220,70,113,229,199,194,84,207,37,23,165,27,235,95,43,199,64,179,
198,178,214,214,19,138,16,62,163,172,51,184,49,35,204,70,81,12,4,221,105,120,118,76,157,58,53,232,84,211,143,161,252,136,130,2,139,240,73,158,213,44,200,212,115,137,248,127,220,134,29,181,30,7,8,93,202,
107,156,103,110,80,109,43,168,115,98,81,201,39,10,147,27,149,227,64,1,57,32,26,81,157,39,82,220,163,18,161,100,10,16,133,70,127,36,87,167,41,141,31,63,94,35,40,74,108,74,187,42,98,125,213,200,161,125,
251,246,109,119,174,21,15,136,27,178,18,109,185,10,226,7,104,149,242,2,81,2,173,111,204,26,208,39,79,61,245,84,181,204,50,203,24,215,113,5,29,7,242,192,1,137,93,211,121,85,201,141,106,66,18,207,168,68,
184,12,68,92,21,143,1,157,19,145,253,133,35,165,64,207,6,181,57,8,21,149,117,134,28,214,59,236,176,131,17,171,196,21,90,163,102,158,115,206,57,70,229,131,10,137,56,160,215,41,218,200,35,162,176,8,234,
138,92,211,127,252,227,31,131,134,159,251,99,240,149,188,181,121,205,71,155,123,6,22,120,128,60,91,146,86,76,103,48,200,93,174,239,188,232,1,200,223,9,240,134,35,199,1,199,1,123,28,32,47,29,154,175,36,
132,86,27,237,54,128,20,166,196,179,76,252,80,16,145,223,50,141,24,152,160,190,138,116,12,208,142,122,60,139,154,195,16,235,14,174,133,38,174,88,69,226,145,27,107,185,57,128,165,62,10,114,170,164,94,171,
155,99,82,82,169,88,201,85,92,54,142,227,185,194,122,18,68,172,205,81,114,165,142,28,57,210,56,206,48,168,63,142,97,89,4,84,46,175,107,21,185,152,63,41,32,242,49,158,70,166,49,160,245,174,141,59,94,108,
14,72,218,162,92,230,243,204,133,171,237,55,223,124,227,137,166,173,37,2,254,139,125,27,187,209,23,137,3,184,253,12,31,62,60,241,144,217,164,124,240,193,7,198,237,0,204,32,121,164,2,203,95,125,245,213,
30,174,111,142,130,57,192,166,144,13,115,16,1,234,84,15,13,55,168,60,169,36,0,23,113,228,56,80,4,14,32,128,0,130,98,74,164,3,161,124,144,192,66,172,103,86,110,143,166,227,205,83,57,214,96,0,206,130,72,
242,88,122,0,59,153,18,235,18,225,28,73,136,181,234,154,107,174,73,210,68,106,117,1,162,66,241,154,103,20,94,255,228,185,30,40,157,29,181,54,7,206,59,239,60,111,191,253,246,203,29,19,114,33,120,138,75,
158,39,9,118,115,199,28,55,32,199,129,162,114,128,77,153,184,217,36,30,254,139,47,190,232,221,113,199,29,198,237,240,194,35,62,43,104,51,8,74,32,113,157,142,26,115,96,220,184,113,129,121,228,176,60,99,
197,140,18,251,6,24,20,233,37,28,57,14,228,157,3,228,238,5,100,208,132,136,49,36,37,71,144,23,6,160,92,81,226,21,77,250,43,99,25,188,78,130,192,152,88,103,176,64,70,185,22,128,13,37,37,226,76,81,188,229,
145,0,128,35,86,146,248,227,188,19,241,188,60,27,46,181,86,222,175,84,250,227,195,35,4,163,94,222,40,23,130,39,139,156,196,28,228,141,55,110,60,142,3,133,228,0,27,135,122,155,178,40,19,66,195,75,190,59,
83,66,51,76,191,65,32,30,15,60,240,64,93,100,91,211,246,91,169,28,155,103,0,215,252,132,85,40,10,168,7,10,0,132,213,86,72,31,225,231,149,251,93,28,14,128,188,9,42,173,9,113,79,163,220,10,66,28,165,141,
168,0,104,38,125,150,181,204,152,49,99,2,17,109,191,255,254,251,72,235,12,224,104,81,144,113,235,241,19,235,233,167,159,126,90,239,116,83,143,131,136,44,24,7,77,29,67,88,231,60,27,120,1,160,120,118,228,
56,128,162,132,52,149,179,102,205,202,21,51,114,33,120,74,0,108,110,53,93,185,186,90,110,48,142,3,6,28,184,228,146,75,34,185,74,213,107,146,151,236,236,217,179,235,157,110,119,28,212,196,32,200,126,180,
216,245,114,120,182,107,196,29,104,227,0,9,194,131,220,146,113,131,3,42,221,148,112,207,205,171,27,155,233,28,92,185,242,114,0,235,101,20,228,77,220,245,223,120,227,141,118,12,193,59,99,208,160,65,237,
142,187,3,141,57,64,154,173,160,152,123,214,13,226,27,77,137,245,255,203,47,191,52,45,30,88,14,101,103,20,197,90,96,35,41,30,68,192,206,171,240,73,42,66,1,148,75,140,233,144,34,251,92,211,77,224,192,78,
59,237,228,161,200,206,19,53,29,213,22,196,48,208,235,222,122,235,45,37,137,119,11,140,33,229,134,238,56,208,124,14,8,152,128,70,225,235,221,187,119,162,193,72,238,55,37,0,65,202,20,13,82,44,154,170,67,
135,14,237,144,87,5,216,72,137,219,155,146,68,240,137,198,147,164,178,44,184,10,84,222,207,63,255,92,205,153,51,71,201,70,87,201,6,167,237,79,18,113,43,201,193,166,215,31,62,23,93,116,81,181,220,114,203,
169,142,29,59,170,21,86,88,65,113,190,89,36,155,57,117,248,225,135,43,63,42,157,88,118,148,104,51,213,222,123,239,109,52,52,73,34,175,122,245,234,213,174,29,163,202,174,144,227,64,138,28,16,69,153,234,
223,191,191,126,230,194,186,17,37,150,18,75,167,234,211,167,79,77,81,1,127,81,2,74,164,46,187,236,178,154,227,89,255,16,247,84,37,110,153,122,157,225,251,143,63,254,216,182,206,176,14,177,190,44,180,208,
66,250,19,20,87,214,24,254,154,141,58,122,241,197,23,43,201,249,167,4,228,177,134,101,2,120,166,68,160,81,251,238,187,111,205,241,160,31,226,141,161,68,41,160,162,32,159,7,181,243,209,71,31,169,17,35,
70,40,214,190,60,210,171,175,190,170,4,59,65,137,80,174,22,94,120,225,92,12,81,114,170,42,174,33,72,230,157,58,117,202,197,152,220,32,242,193,1,9,97,208,123,31,113,101,207,199,128,100,20,77,23,60,69,211,
166,120,241,60,255,252,243,185,97,138,27,136,227,64,17,57,192,134,71,114,56,234,231,41,233,248,197,149,77,137,149,76,205,51,207,60,161,77,137,102,92,11,151,44,112,213,36,160,97,74,44,115,10,161,103,174,
185,230,170,62,149,250,119,120,193,38,85,92,76,148,196,186,232,52,1,93,187,118,85,107,174,185,166,222,244,53,26,0,155,197,247,222,123,79,9,72,146,154,49,99,134,154,119,222,121,245,203,188,103,207,158,
70,155,227,70,109,71,61,199,216,37,126,74,111,168,23,89,100,145,154,234,108,124,14,59,236,48,181,242,202,43,215,28,15,250,33,174,182,74,220,216,244,181,8,58,239,142,57,14,52,131,3,2,90,166,216,3,136,59,
120,104,247,108,174,73,181,226,23,46,81,94,87,238,109,158,213,44,73,226,173,213,179,207,62,171,215,11,9,113,208,235,195,90,107,173,165,215,25,148,87,141,136,249,48,127,214,26,113,47,213,235,12,105,147,
88,103,178,22,68,81,98,137,139,166,18,48,18,181,228,146,75,214,12,27,129,230,224,131,15,54,18,104,238,186,235,46,197,58,187,225,134,27,214,180,17,245,7,202,202,249,230,155,79,237,177,199,30,81,171,102,
82,30,229,7,247,33,10,222,205,54,219,44,147,62,235,117,34,152,0,74,114,161,42,1,133,74,148,50,173,94,251,238,120,177,57,128,162,228,144,67,14,209,235,76,110,102,210,108,243,43,62,253,178,121,106,246,48,
92,255,142,3,133,230,0,64,2,182,144,247,0,183,49,5,121,32,158,52,200,53,138,88,19,98,183,137,73,204,138,136,45,149,141,143,78,250,141,203,157,88,65,172,117,141,219,25,40,144,36,20,151,220,128,153,34,28,
226,190,70,220,142,31,216,2,16,137,40,41,83,162,92,87,107,140,115,13,57,14,52,224,0,174,129,38,241,199,220,251,196,117,6,197,143,211,134,8,113,13,122,177,123,138,241,18,27,9,24,146,8,101,30,136,172,182,
136,212,87,160,145,158,113,198,25,30,113,241,65,224,73,182,250,242,183,195,90,29,148,214,132,249,178,198,155,128,213,176,238,71,193,5,240,143,161,250,247,249,231,159,111,117,13,175,110,219,198,119,238,
73,0,145,0,241,51,5,98,178,209,111,165,13,194,90,120,47,184,148,41,21,142,184,207,32,14,240,220,174,177,198,26,153,174,145,65,227,168,62,214,116,139,103,143,30,61,180,166,198,212,101,44,55,18,187,27,136,
227,64,142,56,32,66,145,214,14,163,109,79,66,178,113,80,167,157,118,154,177,101,12,107,166,228,138,210,26,254,234,126,37,141,135,218,126,251,237,117,2,227,234,227,105,124,199,226,49,116,232,80,133,245,
161,111,223,190,10,171,65,154,244,254,251,239,43,137,153,208,214,141,126,253,250,133,90,80,109,140,229,149,87,94,81,2,110,161,142,62,250,232,154,230,36,214,77,73,108,155,177,75,52,214,83,174,89,51,221,
135,107,38,224,126,180,44,7,94,122,233,37,37,49,228,106,255,253,247,15,229,193,221,119,223,173,189,22,252,214,37,137,79,84,221,186,117,83,155,110,186,105,104,27,73,11,224,114,202,56,240,130,96,204,132,
8,165,73,132,41,136,146,75,187,226,226,138,156,69,40,146,160,96,106,11,52,46,155,213,196,113,137,111,52,178,76,99,193,198,83,131,247,66,18,130,223,88,97,89,175,176,126,230,149,240,236,17,244,112,133,71,
202,192,129,3,83,191,78,244,55,100,200,16,109,221,228,125,144,197,125,145,87,222,187,113,153,113,0,47,10,238,21,19,151,121,179,22,147,149,106,170,224,137,251,23,49,5,108,168,22,91,108,177,100,51,113,181,
29,7,90,148,3,108,8,112,41,69,232,74,74,130,76,168,68,59,102,228,42,133,155,152,228,202,83,184,229,86,147,36,32,87,108,84,142,56,226,136,234,195,214,191,227,218,38,8,150,74,52,191,250,133,191,210,74,43,
89,239,163,81,131,31,127,252,177,98,227,11,191,14,61,244,80,53,247,220,115,55,42,158,248,156,228,247,84,91,110,185,165,234,222,189,123,77,91,146,103,85,29,120,224,129,70,46,183,132,52,32,160,59,69,95,
13,11,221,143,38,112,0,225,134,152,192,48,55,124,73,209,164,4,156,76,137,5,172,102,148,172,49,207,60,243,76,187,245,167,166,144,133,31,184,161,142,28,57,82,239,83,16,0,147,42,247,162,14,9,65,151,117,134,
48,129,44,214,25,73,159,165,231,232,23,242,185,86,108,92,87,93,117,213,208,41,32,48,138,215,73,98,5,151,120,173,40,98,211,252,215,62,116,0,77,40,192,88,225,29,110,210,188,139,109,239,105,121,14,120,223,
161,28,150,44,16,106,233,165,151,110,194,44,93,151,69,228,128,120,44,0,36,171,21,22,185,24,127,181,249,51,235,239,83,166,76,241,54,217,100,147,172,187,117,253,57,14,148,134,3,184,97,70,65,132,108,52,113,
220,164,112,91,51,37,92,170,64,210,171,38,137,143,212,46,113,213,199,210,248,46,113,85,218,165,75,226,48,211,104,62,82,155,175,191,254,186,118,81,99,61,75,147,184,62,184,214,226,98,91,77,184,227,225,114,
101,74,81,202,154,182,89,182,114,160,124,146,227,16,244,84,19,23,195,178,205,63,237,249,188,252,242,203,158,0,200,24,117,131,123,59,200,183,213,132,251,103,20,55,243,234,186,81,190,75,124,148,238,7,196,
220,102,83,86,235,12,243,12,114,107,102,221,49,205,215,73,190,230,137,19,39,90,97,25,105,165,76,83,237,88,233,48,97,35,32,193,19,234,193,187,84,60,113,60,114,91,199,37,17,102,61,208,205,197,11,73,175,
71,205,112,233,141,59,118,87,47,63,28,96,191,36,158,33,185,25,80,83,45,158,104,234,113,21,3,193,204,145,227,128,227,64,52,14,200,42,162,93,145,0,153,1,137,53,41,141,31,63,94,45,190,248,226,106,171,173,
182,10,109,10,64,3,92,139,112,167,173,38,128,40,112,63,93,126,249,229,171,15,91,251,254,195,15,63,168,43,175,188,82,173,183,222,122,26,216,193,90,195,22,26,194,253,22,68,70,217,40,167,6,242,128,86,125,
244,232,209,186,143,234,33,115,237,22,88,96,129,118,168,194,213,101,42,223,177,82,227,186,230,191,118,149,243,238,83,233,123,172,2,150,133,229,2,75,243,214,91,111,173,182,217,102,27,237,98,153,182,117,
187,236,215,0,222,130,126,26,198,199,23,94,120,65,35,82,31,112,192,1,53,44,1,248,108,175,189,246,74,205,173,94,132,44,109,177,195,170,52,96,192,128,80,171,108,205,224,82,254,193,58,3,160,27,235,76,90,
168,170,32,128,19,190,0,216,80,53,137,48,169,45,110,187,237,182,91,245,225,192,239,132,108,96,37,181,65,88,60,177,54,103,237,213,146,116,236,0,71,77,154,52,73,1,36,37,74,98,253,206,172,32,25,87,62,113,
75,134,223,21,212,117,62,241,6,4,228,9,224,56,214,105,62,29,57,14,196,229,0,235,25,33,9,175,189,246,154,190,7,227,182,99,173,94,51,69,96,121,145,123,226,154,208,204,33,184,190,29,7,10,203,129,91,110,185,
197,19,183,86,107,227,55,181,156,2,40,20,100,53,67,35,79,78,184,180,8,235,3,86,214,160,196,241,105,245,25,181,93,217,52,104,11,137,164,135,138,90,213,184,60,26,112,217,208,180,43,143,149,2,171,104,24,
1,138,129,6,221,81,125,14,136,82,212,147,151,108,224,223,18,75,44,225,73,140,159,6,178,74,98,205,168,223,123,185,207,144,220,158,123,56,140,184,79,121,222,249,172,38,242,216,74,220,95,245,33,171,223,37,
132,192,59,246,216,99,115,151,116,189,122,146,146,22,74,175,51,65,249,76,171,203,37,249,46,233,105,60,9,131,106,215,4,86,79,19,47,128,97,195,134,89,203,41,137,87,71,16,136,93,187,193,229,248,0,107,51,
22,75,193,8,240,68,161,162,173,184,240,8,64,188,71,31,125,84,191,203,1,177,251,246,219,111,219,221,243,57,158,150,27,90,65,56,32,6,133,192,124,189,205,24,62,126,191,77,33,30,41,237,190,31,0,0,20,201,73,
68,65,84,66,137,21,240,216,168,57,114,28,112,28,136,198,1,4,27,1,240,137,86,169,65,105,94,134,184,5,153,144,196,153,180,75,224,94,217,36,154,8,62,38,125,248,203,128,34,41,86,142,66,188,144,225,129,64,
237,123,146,3,207,63,13,43,191,113,111,70,200,244,19,238,128,166,238,139,18,47,154,235,141,181,127,110,89,255,110,36,120,86,11,164,18,159,232,109,177,197,22,90,144,114,239,50,179,171,4,111,37,206,56,180,
48,207,207,211,79,63,221,174,28,130,15,174,182,105,16,104,222,98,93,243,80,174,229,157,88,115,225,229,67,15,61,148,202,80,89,199,64,185,245,11,254,40,0,77,18,210,19,118,1,47,109,17,239,40,230,235,200,
113,192,113,32,58,7,36,238,88,35,48,71,175,105,191,70,211,4,79,98,179,4,21,206,254,140,92,139,142,3,37,231,192,79,63,253,100,61,190,233,130,11,46,8,76,85,224,103,37,154,238,32,107,153,228,93,243,38,77,
154,228,47,110,229,55,155,28,1,61,178,210,86,150,141,224,205,33,110,177,169,116,137,134,60,40,134,10,75,180,127,163,24,52,0,65,70,212,194,113,208,57,119,204,211,27,220,106,1,211,228,187,228,188,245,196,
253,83,95,151,180,20,48,69,191,54,172,31,164,80,51,161,32,175,10,4,209,180,226,253,16,116,5,157,212,100,104,185,42,131,197,140,212,43,105,208,115,207,61,23,184,134,225,29,99,114,143,139,171,174,213,212,
83,130,42,156,218,123,38,13,254,185,54,29,7,242,194,1,148,247,27,111,188,113,46,134,211,52,193,19,55,193,61,247,220,51,23,76,112,131,112,28,40,18,7,254,252,231,63,123,184,171,217,34,172,7,231,158,123,
174,81,115,8,82,146,6,161,166,44,27,144,160,77,98,77,161,152,63,36,118,81,231,74,139,89,189,233,213,4,141,51,53,247,22,44,63,126,33,147,141,185,105,94,55,4,0,19,151,185,166,51,177,9,3,48,181,120,214,19,
72,5,173,221,19,36,84,163,205,121,19,166,215,180,46,185,55,77,20,84,130,212,237,241,236,251,41,200,210,239,47,19,231,183,160,61,27,185,255,198,105,59,139,58,184,108,62,246,216,99,169,116,197,218,238,95,
39,38,79,158,108,100,105,197,21,216,182,210,16,161,215,196,98,158,10,51,92,163,142,3,5,229,0,202,102,188,76,243,224,205,209,52,193,115,159,125,246,241,4,92,160,160,151,208,13,219,113,160,57,28,192,210,
133,117,209,38,225,170,229,23,38,235,181,31,100,237,68,24,77,3,245,145,152,81,1,18,170,55,148,194,28,191,232,162,139,172,197,58,85,79,26,183,192,32,33,51,232,26,85,215,171,124,71,72,5,189,213,81,123,14,
36,21,60,43,2,41,168,237,146,246,163,125,7,45,122,4,101,135,95,89,18,196,138,51,206,56,163,157,208,14,82,170,0,99,5,21,79,116,76,0,193,140,21,111,137,58,74,185,50,238,253,111,190,249,166,245,94,192,17,
8,114,225,55,93,103,184,150,54,137,24,200,180,20,157,54,199,233,218,114,28,200,27,7,122,244,232,225,77,157,58,181,233,195,106,154,224,217,165,75,23,239,221,119,223,109,58,3,220,0,28,7,138,194,1,128,76,
76,221,212,162,204,73,16,38,141,138,243,188,18,223,233,39,83,80,34,127,189,70,191,1,16,98,115,97,178,73,109,212,78,30,206,97,45,32,86,138,13,147,109,10,226,61,105,64,36,199,104,104,87,88,170,207,62,251,
236,208,114,173,88,192,84,240,220,96,131,13,180,208,34,8,149,129,64,68,8,160,130,54,236,225,230,212,234,68,74,148,75,46,185,36,148,13,159,125,246,89,96,252,122,208,189,30,218,88,72,1,198,84,116,208,154,
202,20,121,158,177,8,167,145,114,35,136,247,132,18,16,119,25,70,0,65,9,170,107,88,177,72,231,177,184,98,229,117,228,56,224,56,96,206,1,12,126,54,177,65,204,123,174,45,217,20,193,19,16,6,73,194,92,138,
77,101,45,59,221,47,199,129,116,56,128,0,6,194,163,63,159,93,210,222,76,55,131,244,67,28,40,128,17,213,244,202,43,175,120,163,70,141,170,62,148,248,59,27,40,4,53,73,157,146,184,173,188,52,128,155,75,144,
107,108,210,241,17,223,229,207,101,250,221,119,223,25,123,147,0,254,225,207,11,154,116,76,101,168,111,34,120,74,10,35,15,180,77,8,215,119,73,81,83,87,248,36,254,147,205,114,43,19,86,51,19,20,86,73,193,
209,14,185,58,10,248,89,20,30,35,80,229,25,37,59,202,92,40,251,253,247,223,235,181,147,53,212,38,225,101,227,247,138,249,215,191,254,229,225,205,17,70,51,103,206,244,8,173,178,77,60,163,32,28,59,114,28,
112,28,48,227,0,104,226,59,239,188,179,89,225,20,75,53,69,240,68,251,187,195,14,59,164,56,45,215,180,227,64,185,56,64,154,18,255,139,223,198,12,17,26,37,183,83,104,83,32,169,6,197,129,158,115,206,57,30,
231,108,18,26,185,52,211,145,216,28,107,148,182,16,210,111,190,249,230,40,85,66,203,2,52,21,132,28,137,101,220,100,243,137,48,148,86,108,88,232,224,115,92,192,68,240,220,124,243,205,107,102,208,179,103,
207,186,130,39,150,79,226,62,243,16,95,83,51,232,12,127,152,88,215,81,176,5,121,96,72,174,98,35,240,179,40,211,193,98,86,70,101,0,194,189,73,186,154,40,188,226,190,13,186,126,172,255,38,247,116,26,158,
58,188,119,176,86,219,126,255,68,225,139,43,235,56,80,36,14,204,152,49,195,91,125,245,213,155,62,228,166,8,158,44,22,228,201,114,228,56,224,56,16,206,1,242,202,165,21,235,24,180,153,8,26,17,194,9,0,28,
213,132,181,244,226,139,47,174,62,148,248,59,66,48,174,162,101,165,65,131,6,5,230,224,76,50,95,144,35,253,86,75,98,225,0,104,9,35,220,128,131,20,10,97,245,202,126,222,68,240,220,102,155,109,106,216,112,
212,81,71,53,20,60,17,62,177,80,183,34,33,28,224,49,17,70,196,19,250,211,131,0,126,6,160,154,77,34,174,147,107,92,86,34,93,146,137,117,57,202,252,113,147,246,123,161,176,198,152,196,221,194,107,172,177,
182,41,205,119,163,237,177,186,246,28,7,242,192,129,174,93,187,122,120,33,52,147,84,51,58,239,222,189,187,7,48,134,35,199,1,199,129,198,28,64,155,156,86,12,18,22,49,211,13,29,2,170,223,130,6,180,189,205,
56,109,230,138,139,173,191,159,198,28,42,214,89,230,120,252,241,199,91,157,35,150,84,127,12,33,253,152,94,91,172,22,142,106,57,16,71,240,60,250,232,163,67,5,79,222,125,173,72,147,36,213,146,201,59,31,
225,212,175,68,25,55,110,156,85,111,15,172,170,172,51,105,229,2,205,195,245,101,13,101,157,97,29,176,69,184,59,251,99,252,233,199,100,253,32,247,231,216,177,99,109,13,165,166,157,219,111,191,221,234,253,
81,211,184,251,225,56,80,50,14,224,106,155,86,250,37,83,86,101,46,120,18,19,211,185,115,231,118,177,98,166,3,118,229,28,7,90,137,3,87,93,117,149,135,86,55,13,2,221,204,111,93,8,234,135,205,11,86,53,63,
217,118,159,66,75,63,125,250,116,127,55,165,251,61,109,218,52,111,232,208,161,86,231,21,116,45,216,16,154,128,51,221,119,223,125,45,193,247,40,12,79,75,240,196,234,105,83,89,19,101,78,205,44,139,103,68,
37,30,182,209,56,130,60,48,184,183,77,238,227,70,237,86,159,187,231,158,123,90,66,80,225,62,27,50,100,72,245,212,19,127,15,90,103,80,112,133,9,184,8,168,166,138,176,168,131,228,222,0,255,128,152,83,71,
142,3,142,3,141,57,0,104,227,128,1,3,26,23,74,249,108,230,130,231,11,47,188,224,109,186,233,166,41,79,203,53,239,56,80,124,14,96,201,74,3,148,161,194,25,64,60,76,144,86,113,167,34,149,65,53,81,207,166,
251,47,0,31,38,64,21,213,99,40,242,119,220,91,1,1,178,69,108,236,253,192,79,88,24,76,160,211,1,123,187,241,198,27,109,13,165,20,237,164,41,120,218,142,191,43,2,195,77,220,185,73,59,51,124,248,240,154,
233,32,172,218,92,23,8,15,8,18,158,106,58,45,209,15,98,99,191,252,242,75,107,51,226,157,225,207,161,57,113,226,196,118,97,24,65,29,154,88,70,131,234,153,28,99,13,75,75,176,53,233,223,149,113,28,40,10,
7,8,153,234,214,173,91,83,135,155,185,224,73,140,211,126,251,237,215,212,73,187,206,29,7,242,206,1,64,99,112,7,179,169,233,247,207,217,100,51,72,157,32,107,5,174,26,54,243,19,226,98,7,242,107,171,16,169,
113,200,187,103,139,136,141,27,63,126,124,77,115,196,84,33,64,153,144,233,189,96,210,86,25,202,164,41,120,246,239,223,191,12,44,50,158,3,10,17,147,123,157,189,129,95,168,33,182,124,202,148,41,198,125,
133,21,196,131,228,211,79,63,13,43,86,154,243,172,169,8,159,182,8,43,42,30,18,213,132,114,192,36,214,127,240,224,193,214,211,170,84,143,99,228,200,145,70,238,220,213,117,220,119,199,129,86,227,64,197,
235,148,61,102,179,40,115,193,115,151,93,118,241,88,128,28,57,14,56,14,212,231,0,130,24,41,26,210,34,4,90,83,13,113,144,80,98,83,123,141,182,154,13,97,171,17,155,53,255,70,59,46,15,234,185,178,153,94,
167,160,107,28,119,44,101,168,151,166,224,185,219,110,187,149,129,69,198,115,64,195,254,228,147,79,134,150,15,186,7,113,241,7,0,203,6,225,97,96,2,112,100,163,175,60,181,193,218,58,103,206,28,107,67,10,
90,83,130,174,157,191,67,188,47,30,126,248,97,255,97,171,191,73,143,99,211,147,196,234,224,92,99,142,3,57,225,192,102,155,109,102,85,161,23,117,90,153,11,158,64,249,186,220,75,81,47,147,43,223,74,28,192,
181,213,175,85,182,61,255,15,63,252,208,8,97,19,215,180,32,171,153,201,70,195,116,204,160,37,182,146,181,179,194,23,54,131,184,174,217,162,160,107,130,155,162,9,136,10,177,96,54,55,167,182,230,212,172,
118,210,20,60,81,190,182,18,93,123,237,181,161,207,55,49,130,65,66,97,208,61,29,151,119,164,105,74,83,153,23,119,92,105,215,99,109,189,244,210,75,173,117,195,53,241,123,226,240,188,240,174,104,68,172,
67,38,150,209,70,109,132,157,195,173,184,149,92,169,195,248,225,206,59,14,4,113,0,175,83,155,123,143,160,62,26,29,203,84,240,100,99,179,214,90,107,181,91,180,26,13,208,157,115,28,104,37,14,240,242,62,
249,228,147,83,159,50,249,59,77,114,101,62,251,236,179,30,127,213,100,42,180,86,215,169,247,29,4,75,83,203,107,189,54,138,124,156,77,82,24,48,135,233,252,16,30,177,30,87,211,35,143,60,226,225,134,27,70,
228,136,157,48,97,66,88,177,150,57,159,166,224,217,171,87,175,150,225,35,19,13,2,38,243,51,224,245,215,95,247,30,124,240,193,154,195,95,124,241,133,53,239,40,60,2,206,56,227,140,154,246,91,233,7,194,162,
31,45,56,238,252,239,189,247,94,15,132,219,106,10,122,79,84,159,175,124,207,98,173,7,48,207,173,101,21,142,187,79,199,129,246,28,192,235,180,153,10,208,76,5,79,96,209,183,223,126,251,246,92,112,71,28,
7,28,7,52,7,216,32,16,255,151,54,161,121,54,73,188,141,86,204,159,127,13,84,72,91,94,11,8,192,64,237,183,42,97,221,38,142,205,6,5,109,222,185,151,76,128,131,80,120,180,162,187,115,61,190,167,41,120,246,
238,221,187,94,183,165,60,110,34,120,146,18,99,246,236,217,53,243,103,191,96,2,142,85,83,169,206,15,82,185,152,164,115,169,83,189,240,135,89,99,89,107,109,16,57,80,253,105,85,120,71,152,88,80,178,16,60,
153,227,105,167,157,230,92,110,109,92,108,215,70,41,57,192,254,173,75,151,46,77,155,91,166,130,231,233,167,159,238,181,26,176,66,211,174,172,235,184,112,28,96,99,4,64,66,22,100,178,25,100,28,65,229,56,
230,119,181,138,59,230,86,119,139,130,143,65,41,36,226,240,19,203,105,16,2,168,233,102,47,232,90,199,25,71,25,234,164,41,120,158,121,230,153,101,96,145,209,28,176,52,6,185,208,250,43,7,221,123,40,199,
76,220,196,253,109,5,253,38,46,209,86,172,104,80,251,69,56,102,235,190,99,205,10,186,94,65,199,252,124,225,185,202,34,237,9,46,183,182,214,85,255,28,220,111,199,129,162,115,128,103,24,239,211,44,140,28,
65,188,202,84,240,220,120,227,141,219,37,58,15,26,148,59,230,56,208,106,28,64,99,124,234,169,167,102,54,109,147,77,2,131,9,42,23,116,44,206,192,113,253,178,137,184,24,103,12,121,168,131,149,219,214,166,
56,232,218,4,29,11,154,183,105,185,160,186,101,59,150,166,224,249,248,227,143,151,141,93,117,231,131,21,19,107,102,24,5,221,123,65,199,194,218,9,58,143,240,27,4,136,19,84,182,204,199,88,107,109,185,219,
6,93,155,160,99,126,126,142,25,51,198,123,243,205,55,253,135,83,249,61,122,244,104,35,80,171,84,58,119,141,58,14,228,156,3,120,159,250,145,240,179,26,114,102,130,39,18,118,231,206,157,61,242,245,57,114,
28,112,28,168,229,0,27,35,98,154,178,34,147,77,2,207,236,249,231,159,223,110,72,38,117,219,85,10,56,128,155,105,43,187,191,85,88,66,76,146,45,151,194,160,107,19,116,172,210,119,245,167,105,185,234,58,
101,253,158,150,224,185,220,114,203,25,185,184,151,133,175,32,218,154,60,227,65,247,94,208,177,56,124,121,227,141,55,172,185,153,198,233,63,47,117,184,14,147,38,77,178,50,156,160,107,131,101,155,119,70,
35,194,229,55,109,100,219,234,254,79,57,229,148,80,208,163,234,242,238,187,227,64,171,112,160,95,191,126,77,3,226,202,76,240,36,24,189,123,247,238,173,114,77,221,60,29,7,140,57,240,244,211,79,103,230,
98,203,160,126,248,225,7,163,120,28,220,48,110,186,233,166,154,121,96,153,189,230,154,107,106,142,197,253,113,229,149,87,186,77,129,48,15,101,220,245,215,95,31,151,141,53,245,64,8,246,199,238,18,123,197,
53,15,35,92,27,109,1,29,133,245,149,247,243,105,9,158,228,170,108,37,34,223,175,31,136,198,63,127,242,202,93,126,249,229,53,135,235,185,141,215,20,50,252,193,26,246,217,103,159,25,150,46,111,177,122,8,
229,113,102,12,66,240,183,223,126,91,83,245,230,155,111,14,69,198,230,157,2,8,90,86,4,216,154,137,171,119,86,227,113,253,56,14,228,133,3,132,117,145,86,165,25,148,153,224,9,18,90,51,81,148,154,193,92,
215,167,227,64,24,7,216,12,160,149,205,146,8,44,55,73,215,130,118,218,239,138,241,246,219,111,123,184,48,217,32,211,216,67,27,125,229,189,13,91,188,184,235,174,187,188,143,63,254,184,102,186,195,135,15,
247,222,123,239,189,154,99,65,63,110,185,229,22,183,65,255,55,99,210,16,60,123,244,232,97,205,213,49,232,250,229,241,24,2,74,88,94,69,192,106,0,44,171,166,89,179,102,121,119,220,113,71,245,161,216,223,
109,61,91,177,7,144,163,138,182,120,49,118,236,88,15,75,114,53,129,160,29,230,185,129,219,115,214,225,21,0,33,129,218,237,200,113,192,113,224,55,14,144,101,4,47,212,48,47,133,223,106,216,251,150,153,224,
57,112,224,64,239,164,147,78,178,55,114,215,146,227,64,9,56,128,203,82,214,249,19,95,124,241,69,111,226,196,137,161,220,3,109,245,149,87,94,169,41,247,196,19,79,120,47,188,240,66,205,177,184,63,130,220,
181,226,182,85,244,122,182,120,241,228,147,79,182,75,12,77,170,3,19,23,59,210,89,100,21,127,149,215,235,133,192,3,197,17,60,225,223,74,43,173,228,41,165,218,253,13,24,48,160,29,58,116,94,121,96,115,92,
38,238,151,83,166,76,105,23,139,135,160,96,43,22,214,214,179,101,147,47,205,106,203,22,47,72,209,228,79,89,130,208,137,240,25,70,65,225,27,97,117,146,156,103,99,125,194,9,39,88,3,170,74,50,22,87,215,113,
32,79,28,88,119,221,117,61,20,127,89,83,102,130,231,250,235,175,111,20,235,145,53,3,92,127,142,3,205,226,192,228,201,147,219,105,250,179,24,11,27,6,147,220,142,88,33,252,139,210,253,247,223,111,45,149,
74,214,27,144,44,120,27,183,15,91,27,194,215,94,123,205,35,13,69,53,33,76,250,115,36,86,159,175,124,127,230,153,103,188,231,158,123,174,242,179,101,62,63,248,224,3,237,142,7,188,252,182,219,110,171,231,
29,71,240,164,34,155,92,44,206,143,62,250,168,119,195,13,55,104,225,41,107,197,82,158,46,156,137,155,35,49,127,211,166,77,171,25,182,137,245,172,166,66,131,31,182,158,173,6,93,20,230,148,173,53,55,200,
74,205,125,143,199,69,24,217,26,67,88,63,213,231,241,242,105,53,55,247,234,249,187,239,142,3,65,28,216,121,231,157,189,17,35,70,4,157,74,245,88,38,130,39,241,26,152,116,253,249,0,83,157,153,107,220,113,
32,199,28,32,77,192,137,39,158,216,148,17,226,42,139,203,108,24,17,139,227,7,3,35,94,202,22,8,146,201,166,52,108,140,101,57,111,107,51,198,230,239,238,187,239,174,97,139,233,134,48,200,138,81,211,80,137,
126,16,243,119,237,181,215,122,27,110,184,97,141,117,50,169,224,89,34,22,89,153,138,201,51,142,219,255,135,31,126,88,211,95,208,177,154,2,17,126,216,122,182,34,116,153,219,162,182,220,92,191,250,234,43,
173,88,169,158,104,208,177,234,243,149,239,205,186,30,8,158,182,242,79,87,230,226,62,29,7,138,204,129,99,142,57,166,41,251,208,76,4,207,183,222,122,203,219,96,131,13,138,124,125,220,216,29,7,172,114,224,
186,235,174,243,176,180,52,131,136,183,246,111,244,130,198,1,136,144,31,148,134,99,196,165,218,160,75,47,189,212,70,51,165,104,195,214,102,12,240,14,64,62,170,9,139,155,255,88,245,249,202,119,98,182,136,
221,42,43,125,243,205,55,222,208,161,67,189,237,182,219,206,155,107,174,185,106,4,206,138,123,108,82,193,243,235,175,191,214,86,227,27,111,188,209,35,188,100,139,45,182,240,86,93,117,85,175,67,135,14,
222,252,243,207,239,45,182,216,98,222,106,171,173,230,109,186,233,166,222,30,123,236,225,129,44,120,213,85,87,233,58,89,228,55,204,250,218,154,8,158,164,91,249,244,211,79,107,134,118,219,109,183,89,139,
55,182,245,108,213,12,176,160,63,252,32,78,113,167,241,211,79,63,121,128,195,85,211,143,63,254,168,239,229,234,99,65,223,155,117,61,154,169,236,13,226,131,59,230,56,208,108,14,128,225,129,242,53,107,202,
68,240,28,54,108,152,126,201,102,61,57,215,159,227,64,30,57,128,181,165,153,66,87,16,0,77,16,159,112,55,100,131,81,77,108,92,64,161,180,65,160,168,58,250,127,14,216,218,140,5,89,29,72,166,142,219,103,
24,217,4,142,10,235,43,171,243,220,191,163,70,141,242,246,218,107,47,45,248,85,4,204,122,159,113,4,79,20,72,103,158,121,166,215,181,107,215,64,97,182,94,95,254,227,243,206,59,175,183,227,142,59,122,183,
222,122,107,40,32,79,86,252,75,218,143,137,224,137,82,196,159,200,28,111,11,91,158,21,182,158,173,164,188,200,67,253,203,46,187,204,202,48,64,206,6,65,187,154,16,236,76,218,111,230,245,32,188,133,112,
17,71,142,3,142,3,158,199,126,1,111,84,64,191,178,164,76,4,207,254,253,251,123,167,157,118,90,150,243,114,125,57,14,228,150,3,167,159,126,186,53,171,97,156,73,130,242,247,201,39,159,132,86,69,240,244,
11,153,8,158,182,146,144,219,114,251,10,157,72,1,10,216,218,140,97,113,27,60,120,112,205,140,131,132,209,154,2,255,254,241,206,59,239,88,67,44,14,106,63,171,99,188,68,1,84,234,219,183,175,183,200,34,139,
68,18,6,227,8,158,92,59,191,16,153,244,247,162,139,46,234,209,110,24,34,108,86,60,141,219,143,137,224,25,228,190,31,228,230,31,119,12,182,158,173,184,253,231,169,158,45,101,31,225,83,126,193,19,97,212,
68,161,218,236,235,113,246,217,103,123,120,63,56,114,28,112,28,240,116,154,203,172,189,239,50,17,60,215,91,111,61,189,17,112,23,217,113,160,213,57,0,120,75,51,130,185,171,249,78,12,224,140,25,51,170,15,
5,126,199,5,208,239,254,135,123,149,223,10,26,88,217,224,160,201,38,197,160,153,82,20,177,181,25,35,38,23,55,207,106,194,114,100,146,59,143,144,136,49,99,198,84,87,45,212,119,44,46,164,224,88,115,205,
53,35,11,130,184,27,17,243,89,201,247,24,5,92,136,107,23,38,104,254,238,119,191,243,120,15,246,233,211,199,99,243,143,21,22,240,46,148,47,245,144,112,105,147,115,254,180,21,69,186,40,38,130,39,105,124,
252,0,76,65,86,208,184,243,182,245,108,197,237,63,79,245,184,175,109,80,144,117,19,133,164,137,43,111,179,175,7,138,56,91,105,101,108,240,210,181,225,56,208,76,14,144,230,146,124,203,89,82,234,130,103,
5,88,200,31,43,150,229,36,93,95,142,3,121,224,192,175,191,254,170,97,221,155,61,22,147,164,238,140,241,250,235,175,111,167,25,38,54,213,150,182,248,162,139,46,106,54,43,114,211,191,173,205,216,223,255,
254,119,143,152,185,106,154,61,123,182,142,109,172,62,22,244,29,100,81,16,70,139,72,88,56,137,157,12,19,0,171,207,83,30,196,211,247,223,127,191,221,148,109,9,158,221,186,117,211,238,135,0,60,213,35,64,
198,170,199,229,255,222,169,83,39,143,181,163,136,100,34,120,226,129,49,115,230,204,154,233,17,158,227,63,86,83,32,194,15,91,207,86,132,46,115,91,212,111,165,140,59,80,128,34,253,40,177,28,67,121,19,70,
121,184,30,220,95,97,57,71,195,230,225,206,59,14,148,129,3,199,30,123,108,230,0,67,169,11,158,196,13,57,96,161,50,220,158,110,14,73,57,128,102,31,171,82,179,137,116,27,164,221,8,35,172,71,8,45,213,20,
116,172,250,124,148,239,121,216,128,68,25,111,154,101,109,165,124,152,62,125,122,59,139,250,123,239,189,231,13,31,62,60,116,248,196,63,61,245,212,83,161,229,242,86,128,49,207,51,207,60,13,133,183,138,
48,183,204,50,203,104,229,207,203,47,191,220,112,26,73,4,79,192,132,112,231,107,132,28,141,91,34,105,141,122,247,238,29,58,246,37,151,92,210,67,129,91,68,50,17,60,177,254,190,251,238,187,53,211,3,121,
27,215,111,27,100,235,217,178,49,150,102,183,97,107,205,197,51,0,0,168,106,250,252,243,207,117,124,114,245,177,160,239,182,198,16,212,182,233,49,220,241,201,237,153,117,108,155,233,248,92,57,199,129,172,
56,0,192,80,143,30,61,178,234,78,247,243,127,0,0,0,255,255,198,252,136,42,0,0,64,0,73,68,65,84,236,157,5,184,20,213,251,199,95,66,41,21,165,37,44,66,82,84,66,4,81,64,82,4,17,73,17,165,12,4,197,32,36,164,
27,145,86,186,164,4,4,5,4,148,144,144,20,233,16,41,27,84,4,21,3,69,220,255,124,207,239,191,215,189,123,103,239,157,153,157,217,59,51,251,125,159,103,159,221,157,61,115,226,51,187,179,231,61,231,13,9,56,
44,179,102,205,10,60,248,224,131,14,183,194,234,73,192,221,4,126,252,241,199,64,159,62,125,92,209,201,117,235,214,5,54,110,220,152,98,95,222,121,231,157,192,190,125,251,18,149,91,186,116,105,96,239,222,
189,137,142,89,125,211,187,119,111,171,167,250,238,60,187,88,108,217,178,37,240,225,135,31,38,226,179,117,235,214,192,234,213,171,19,29,211,123,179,114,229,202,192,246,237,219,245,62,114,245,177,186,117,
235,6,68,36,217,71,149,42,85,20,131,75,151,46,233,142,229,223,127,255,13,108,219,182,45,48,121,242,100,245,249,208,161,67,147,173,15,237,161,78,8,126,215,215,95,127,125,160,83,167,78,138,31,234,210,19,
28,255,248,227,143,3,207,62,251,108,32,103,206,156,41,214,143,54,210,166,77,27,152,59,119,174,94,117,158,56,102,228,158,135,239,43,184,132,202,218,181,107,3,155,54,109,10,61,100,249,181,93,191,45,203,
29,112,209,137,118,177,56,112,224,64,96,209,162,69,137,70,118,232,208,161,192,219,111,191,157,232,152,222,27,35,223,9,189,243,236,62,246,233,167,159,6,166,77,155,102,119,181,172,143,4,60,69,224,135,31,
126,8,20,44,88,48,16,233,127,203,137,193,136,19,149,134,214,249,204,51,207,4,94,120,225,133,208,67,124,77,2,113,71,160,87,175,94,129,115,231,206,185,98,220,123,246,236,9,64,129,76,73,48,241,195,4,48,84,
140,42,49,161,231,68,122,109,215,36,40,82,253,94,58,254,234,171,175,218,210,93,189,197,130,119,223,125,55,128,73,86,74,50,103,206,156,192,231,159,127,158,82,49,215,125,62,118,236,216,20,149,184,111,190,
249,70,183,223,24,47,38,194,133,10,21,82,117,84,173,90,85,149,51,163,120,158,57,115,38,240,207,63,255,232,214,143,131,251,247,239,15,188,242,202,43,129,155,110,186,41,197,126,134,42,208,183,222,122,171,
161,5,162,136,13,187,224,131,65,131,6,5,254,250,235,175,100,123,162,119,63,210,83,108,146,173,36,153,15,237,250,109,37,211,132,103,62,178,235,158,171,183,48,176,97,195,134,192,250,245,235,83,100,225,22,
197,19,29,197,255,242,79,63,253,148,98,159,89,128,4,252,76,224,182,219,110,11,156,56,113,34,102,67,116,92,241,44,83,166,76,96,213,170,85,49,27,16,27,34,1,183,17,216,189,123,119,96,234,212,169,174,233,
214,183,223,126,27,152,52,105,82,138,253,193,141,8,22,11,161,242,213,87,95,217,54,22,76,130,98,185,202,22,58,14,55,189,198,196,188,127,255,254,182,116,105,204,152,49,73,38,82,111,188,241,70,224,244,233,
211,41,214,255,250,235,175,7,126,254,249,231,20,203,185,173,0,190,67,163,71,143,14,100,200,144,33,162,98,87,164,72,145,64,139,22,45,2,221,187,119,15,60,245,212,83,106,183,50,111,222,188,129,52,105,210,
36,58,199,138,226,169,199,227,212,169,83,129,33,67,134,4,74,149,42,149,168,254,80,197,50,210,235,59,238,184,35,48,115,230,204,20,21,54,189,118,221,118,12,59,200,145,148,254,96,95,191,255,254,251,192,132,
9,19,130,111,213,51,190,135,248,62,218,33,248,109,165,164,252,218,209,142,219,235,192,239,196,46,37,124,198,140,25,1,124,199,67,101,222,188,121,129,207,62,251,44,244,80,146,215,191,253,246,91,96,216,176,
97,73,142,167,214,129,179,103,207,6,236,82,198,83,107,12,108,151,4,162,37,80,171,86,173,192,226,197,139,163,173,198,240,249,142,42,158,184,209,97,11,151,43,74,134,175,7,11,250,140,0,126,3,207,63,255,124,
224,242,229,203,174,25,25,204,13,141,40,58,152,172,97,199,34,84,176,179,211,175,95,191,208,67,150,95,195,132,16,230,89,241,46,59,119,238,12,96,87,210,14,209,155,68,97,135,1,223,195,148,196,77,59,17,41,
245,85,239,243,47,190,248,34,208,177,99,199,64,166,76,153,76,43,123,65,37,48,26,197,19,38,75,80,160,42,85,170,148,68,161,13,214,31,233,25,187,161,61,122,244,8,28,60,120,80,111,104,158,61,182,98,197,138,
0,190,223,201,9,190,155,125,251,246,77,82,68,239,187,156,164,144,129,3,239,189,247,94,96,199,142,29,6,74,250,187,8,118,247,177,160,97,135,224,255,35,220,108,29,86,2,127,252,241,71,178,213,163,15,111,189,
245,86,178,101,98,253,33,22,97,195,93,74,98,221,7,182,71,2,169,73,160,109,219,182,202,42,39,86,125,112,84,241,60,126,252,120,160,116,233,210,177,26,11,219,33,1,215,17,192,42,112,184,255,146,27,58,105,
116,82,167,87,78,239,152,149,49,97,39,36,124,167,195,74,61,94,63,231,181,215,94,179,109,113,78,239,218,232,29,211,99,102,180,156,222,185,110,58,118,254,252,249,192,146,37,75,148,18,90,188,120,113,83,74,
160,21,197,19,126,181,117,234,212,9,92,113,197,21,166,20,222,28,57,114,4,218,183,111,31,216,188,121,179,161,133,1,55,49,54,218,23,152,25,27,89,73,215,251,238,233,29,51,218,110,104,57,184,56,140,24,49,
34,244,80,92,190,198,238,243,169,176,93,74,171,32,244,174,141,222,177,240,250,97,162,107,36,190,64,248,121,78,190,199,98,42,252,179,41,36,16,175,4,48,79,173,92,185,114,204,134,239,168,226,137,63,28,108,
225,82,72,32,30,9,192,172,168,107,215,174,174,28,186,145,73,2,58,174,87,78,239,152,213,65,194,244,49,222,197,78,6,122,215,198,168,121,157,222,185,126,184,54,176,184,129,114,7,255,87,236,110,96,23,255,
197,23,95,84,150,8,3,6,12,8,188,249,230,155,74,57,194,132,248,187,239,190,83,67,54,227,227,137,157,226,72,59,153,225,199,51,103,206,28,104,214,172,89,96,249,242,229,129,191,255,254,219,15,120,147,29,195,
133,11,23,2,195,135,15,79,182,12,62,212,251,238,233,29,75,177,162,8,5,236,252,141,69,104,194,245,135,237,100,160,119,109,244,142,133,67,129,242,251,245,215,95,135,31,78,245,247,240,77,53,178,64,146,234,
29,101,7,72,192,1,2,176,22,42,92,184,176,3,53,235,87,233,168,226,137,27,29,182,112,41,36,16,143,4,224,227,229,198,63,89,92,11,35,147,4,148,131,89,109,120,224,20,76,36,127,253,245,87,124,28,181,192,223,
199,45,65,151,162,30,140,133,10,160,232,192,47,211,14,129,175,220,184,113,227,18,85,5,211,183,112,115,233,68,5,254,255,13,204,29,189,110,106,171,55,46,171,199,236,84,60,211,167,79,31,168,93,187,118,96,
246,236,217,182,253,110,172,142,43,53,206,51,114,175,25,60,120,112,18,51,77,248,38,7,23,2,162,237,55,126,99,118,213,21,109,95,82,227,252,95,126,249,37,0,198,118,8,22,84,241,251,8,21,163,247,15,220,99,
140,152,253,135,214,29,171,215,157,59,119,14,96,108,20,18,136,55,2,248,77,22,43,86,44,0,119,145,88,136,163,138,231,189,247,222,235,58,123,254,88,64,101,27,36,0,147,38,152,80,186,85,16,9,212,200,77,6,225,
241,17,97,50,84,62,250,232,163,0,82,178,216,33,39,79,158,84,59,78,118,212,229,197,58,16,64,197,72,224,31,35,99,91,182,108,89,18,127,58,164,71,129,159,93,74,130,239,43,83,11,252,71,105,225,194,133,129,
236,217,179,39,187,147,25,154,78,37,124,103,19,65,139,238,186,235,46,181,168,128,168,183,241,44,70,20,79,124,71,195,83,249,236,218,181,203,80,244,109,35,108,241,27,179,43,88,145,145,246,220,86,6,193,237,
142,30,61,106,75,183,16,189,118,205,154,53,137,234,66,221,70,124,55,141,90,95,36,170,60,70,111,176,72,108,100,145,46,70,221,97,51,36,16,83,2,248,63,11,79,197,230,84,7,28,85,60,17,73,16,19,75,10,9,196,
27,1,172,158,254,249,231,159,174,29,54,204,10,195,39,15,122,157,133,9,198,148,41,83,18,125,244,251,239,191,219,182,122,142,138,187,116,233,226,218,85,240,68,3,183,249,13,2,78,217,105,138,141,221,233,112,
243,77,236,244,24,89,96,64,112,35,76,244,41,255,17,64,240,20,152,224,33,56,216,141,55,222,152,68,9,213,83,60,145,2,5,215,225,216,177,99,255,85,20,231,175,16,56,40,165,224,106,248,142,134,239,252,131,191,
94,208,33,171,56,241,91,75,169,31,86,235,118,251,121,248,63,178,75,176,219,9,19,234,80,65,244,115,35,169,152,220,172,120,98,60,248,14,166,20,153,55,116,220,124,77,2,126,33,208,180,105,83,67,110,17,118,
140,215,49,197,19,126,53,248,19,118,171,89,133,29,240,88,7,9,232,17,192,142,96,120,114,109,189,114,169,121,12,166,87,70,124,175,208,71,228,58,11,151,158,61,123,134,31,178,252,30,171,108,241,152,114,9,
62,69,8,76,99,151,232,93,19,189,99,122,237,193,215,241,226,197,139,122,31,241,152,70,0,255,99,200,133,138,137,115,48,69,74,80,241,68,128,44,228,170,254,228,147,79,200,74,135,192,252,249,243,13,69,175,
118,250,62,131,32,111,240,243,141,55,193,226,9,124,138,237,18,189,123,10,174,93,74,115,61,152,58,195,124,218,205,130,133,59,6,26,114,243,21,98,223,156,34,0,11,189,6,13,26,56,85,125,162,122,29,83,60,113,
179,131,169,45,133,4,226,137,128,151,34,228,233,77,244,244,174,149,222,68,3,171,222,80,94,237,18,4,123,137,39,193,36,205,206,49,99,199,8,185,44,67,5,187,59,70,119,24,140,126,23,66,235,143,231,215,136,
216,110,87,10,28,191,115,132,213,211,244,233,211,83,28,38,190,171,225,59,146,112,9,176,211,84,25,191,185,148,20,164,20,59,234,177,2,118,142,25,59,157,122,190,162,122,255,17,225,152,16,105,26,139,55,110,
23,184,145,48,208,144,219,175,18,251,103,55,1,252,54,75,148,40,97,119,181,186,245,165,193,81,205,63,197,118,209,76,22,68,91,97,20,109,231,199,246,186,89,33,9,184,149,128,230,39,39,101,202,148,145,219,
111,191,221,173,93,76,232,151,54,209,19,45,31,155,104,254,104,9,199,244,94,104,249,54,69,75,106,47,90,106,138,132,143,247,236,217,35,39,78,156,144,70,141,26,37,28,139,230,133,246,103,47,154,9,175,212,
175,95,63,154,106,60,115,174,182,11,36,90,238,70,185,251,238,187,109,233,179,102,234,166,234,210,220,27,18,234,211,118,224,228,219,111,191,21,109,21,51,225,152,222,11,109,177,68,6,14,28,40,154,89,163,
222,199,60,70,2,81,19,192,189,70,219,85,79,182,158,165,75,151,202,13,55,220,160,238,159,193,130,154,130,47,155,54,109,146,54,109,218,4,15,69,245,188,117,235,86,209,124,249,68,51,43,139,170,30,175,156,
172,89,147,136,102,178,44,117,235,214,181,165,203,184,70,249,243,231,151,114,229,202,37,212,167,45,44,136,230,247,153,226,53,194,253,69,91,224,18,45,216,86,194,185,110,125,161,153,101,171,251,161,22,133,
218,173,93,100,191,72,192,86,2,90,222,118,209,20,79,57,124,248,176,92,121,229,149,182,214,157,164,50,93,117,212,134,131,176,23,134,249,22,133,4,226,133,192,207,63,255,28,48,178,242,235,22,30,48,129,11,
15,28,164,215,183,179,103,207,6,70,142,28,153,232,35,236,26,32,225,189,157,242,210,75,47,5,180,155,159,157,85,186,178,46,248,200,194,175,213,78,209,75,149,128,157,9,35,209,135,17,212,5,129,137,40,36,224,
20,1,35,59,234,248,174,34,18,120,184,232,125,183,195,203,152,121,143,223,30,162,61,251,93,224,35,11,19,112,59,5,247,252,240,29,99,68,210,54,18,49,216,75,255,141,8,52,164,247,93,180,147,37,235,34,1,183,
17,208,22,148,2,123,247,238,117,188,91,142,153,218,194,15,198,78,255,37,199,73,176,1,18,136,146,128,182,123,24,64,74,11,175,8,250,26,110,158,25,169,239,122,147,63,140,23,74,148,93,2,243,69,55,71,2,182,
107,156,218,238,162,173,105,118,206,159,63,159,36,189,1,250,170,119,205,244,198,96,183,217,180,94,27,60,22,223,4,16,85,213,72,160,65,189,239,172,221,41,151,190,250,234,43,93,115,81,191,93,33,4,202,57,
114,228,136,109,195,66,176,60,109,215,50,73,125,122,215,44,188,144,222,226,101,120,25,183,189,71,20,100,252,39,81,72,32,94,8,60,248,224,131,42,237,151,211,227,117,68,241,132,159,91,193,130,5,13,173,182,
59,61,64,214,79,2,177,32,128,40,150,70,149,184,88,244,199,104,27,70,119,45,17,64,5,19,182,80,217,183,111,95,96,222,188,121,161,135,162,126,141,201,210,193,131,7,163,174,199,173,21,32,114,236,164,73,147,
108,237,30,162,14,135,71,81,69,122,3,35,126,117,232,136,209,239,128,173,157,102,101,113,69,0,247,142,55,223,124,51,197,49,35,165,79,248,119,89,51,233,183,253,55,131,190,236,222,189,59,197,254,120,181,
0,34,204,142,24,49,194,214,238,35,181,86,184,143,38,252,111,71,141,26,149,98,59,176,174,217,191,127,127,138,229,220,84,0,193,214,96,133,67,33,129,120,33,240,236,179,207,218,110,37,161,199,206,17,197,19,
147,30,205,39,76,175,61,30,35,1,95,18,120,249,229,151,61,25,21,212,168,57,38,118,71,245,242,224,217,153,14,4,95,12,44,90,61,247,220,115,190,52,185,197,238,48,82,115,132,155,170,69,251,131,208,187,6,48,
19,195,78,104,74,242,227,143,63,234,94,215,148,206,227,231,36,96,150,128,145,5,142,115,231,206,233,238,222,235,125,199,205,182,31,90,30,65,140,240,91,244,163,201,45,76,108,59,118,236,152,36,181,82,232,
248,173,188,214,187,6,227,199,143,79,178,32,169,87,183,145,107,175,119,94,106,31,67,126,217,149,43,87,166,118,55,216,62,9,196,132,0,178,49,84,172,88,209,241,182,28,81,60,17,17,172,86,173,90,142,119,158,
13,144,128,27,8,32,130,179,87,195,244,195,158,127,193,130,5,134,48,118,235,214,45,73,57,236,222,217,109,142,116,234,212,41,93,147,174,36,141,123,236,0,38,95,90,176,31,91,123,141,93,132,217,179,103,39,
170,19,138,237,43,175,188,146,232,88,164,55,122,59,76,145,202,242,56,9,68,67,192,232,34,23,190,187,225,139,51,90,128,51,219,125,143,190,249,230,27,221,84,81,209,140,209,13,231,130,179,145,156,154,102,
250,138,123,178,94,42,20,189,255,132,240,122,225,183,223,187,119,239,240,195,158,121,143,168,192,241,16,123,192,51,23,132,29,117,140,0,242,182,107,1,10,29,171,63,88,177,35,81,109,181,155,140,138,28,55,
99,198,140,36,193,140,120,128,4,252,68,64,155,32,137,102,142,35,154,153,173,103,135,165,249,232,136,182,67,150,98,255,181,244,17,146,59,119,238,68,145,88,181,240,250,162,153,90,9,126,243,118,138,22,236,
70,180,156,106,182,69,205,181,179,111,86,234,122,235,173,183,228,250,235,175,151,234,213,171,91,57,61,226,57,136,22,170,5,237,144,140,25,51,38,148,89,187,118,173,224,123,89,179,102,205,132,99,145,94,24,
189,246,145,206,231,113,18,48,74,64,11,100,38,120,60,250,232,163,201,158,178,122,245,106,201,144,33,131,84,173,90,53,161,28,34,46,34,242,114,74,145,113,19,78,48,248,226,131,15,62,16,45,231,120,138,125,
50,88,93,170,23,211,118,232,68,243,197,148,198,141,27,219,218,23,176,215,44,81,36,107,214,172,9,245,106,139,150,162,249,144,74,243,230,205,19,142,233,189,208,114,52,75,150,44,89,68,75,175,167,247,177,
235,143,105,74,188,224,59,169,237,144,187,190,175,236,32,9,68,67,64,83,12,165,88,177,98,130,232,223,217,178,101,139,166,170,228,207,13,106,160,118,62,107,19,158,192,196,137,19,237,172,146,117,145,128,
43,9,192,143,46,220,239,197,149,29,77,166,83,88,33,71,68,222,148,4,38,92,122,129,36,250,245,235,103,107,78,207,96,63,134,15,31,30,208,210,182,4,223,122,246,121,219,182,109,1,228,35,180,91,96,38,139,107,
23,46,216,133,8,207,135,24,94,6,239,97,62,29,30,173,88,175,28,143,145,128,93,4,140,236,196,227,187,171,87,14,65,176,144,175,214,110,129,143,226,206,157,59,237,174,54,230,245,105,105,16,28,201,36,128,220,
157,125,250,244,73,50,30,68,42,134,31,100,74,130,255,12,35,247,163,148,234,73,205,207,145,161,225,244,233,211,169,217,5,182,77,2,49,33,80,185,114,229,128,150,194,202,209,182,28,49,181,45,90,180,168,161,
52,13,142,142,140,149,147,128,195,4,240,135,172,167,136,57,220,172,237,213,195,44,11,81,39,141,8,34,76,134,79,254,16,122,222,9,5,6,230,118,240,157,133,73,156,87,5,145,60,245,38,209,118,140,7,74,167,222,
181,48,26,228,10,105,16,112,237,40,36,16,43,2,136,90,29,254,157,213,107,27,254,228,225,102,233,88,104,25,52,104,144,94,241,168,142,225,62,3,255,197,47,191,252,50,170,122,82,243,100,44,34,117,234,212,73,
249,200,219,221,15,40,230,48,193,11,21,248,143,35,58,119,74,130,255,72,68,63,247,186,252,242,203,47,190,248,175,247,250,117,96,255,157,39,240,200,35,143,232,154,213,219,217,178,237,138,39,86,192,16,209,
150,54,241,118,94,38,214,229,70,2,8,224,18,62,57,114,99,63,141,244,73,47,112,132,222,121,152,224,96,231,33,92,224,195,99,100,215,52,252,188,148,222,35,132,63,34,173,25,153,172,166,84,87,172,63,199,119,
3,65,62,156,184,23,130,135,222,196,15,147,60,35,65,133,192,194,232,53,143,53,55,182,231,95,2,88,68,66,228,234,148,68,51,127,213,253,126,67,241,196,61,200,110,193,188,165,67,135,14,1,68,105,245,154,224,
247,222,190,125,251,192,111,191,253,102,123,215,161,112,233,229,96,133,50,106,100,209,74,115,183,10,96,39,214,15,130,177,124,242,201,39,126,24,10,199,64,2,17,9,192,98,170,77,155,54,17,63,183,227,3,219,
21,79,4,43,65,18,82,10,9,248,153,0,210,3,96,247,207,47,50,107,214,44,195,86,10,80,50,49,33,9,21,76,216,244,20,161,208,50,86,95,99,213,28,10,28,2,92,120,69,16,217,219,201,168,153,184,6,136,0,26,42,216,
17,50,122,13,182,111,223,30,64,16,56,10,9,196,154,128,209,5,15,44,162,132,127,199,161,100,105,126,205,142,116,25,138,27,34,106,35,125,139,87,4,139,91,88,152,51,186,216,100,118,92,176,170,248,238,187,239,
18,157,134,72,192,70,163,212,118,233,210,37,209,185,94,126,19,140,132,140,29,114,10,9,248,149,128,230,207,28,40,83,166,140,163,195,179,93,241,68,94,191,186,117,235,58,218,105,86,78,2,169,77,0,171,66,78,
172,48,167,214,184,48,153,48,58,161,195,100,71,79,233,198,42,184,221,209,20,131,60,176,107,168,5,209,9,104,193,64,130,135,92,251,252,222,123,239,169,168,188,240,137,117,66,16,201,86,47,39,34,252,144,160,
124,26,17,152,136,107,193,155,140,20,101,25,18,176,149,192,242,229,203,3,27,55,110,76,177,78,236,108,234,153,214,34,146,54,22,184,157,16,252,38,112,31,212,2,226,56,81,189,173,117,194,15,11,138,157,83,
41,97,160,128,235,185,80,192,148,31,46,4,41,9,242,60,135,71,220,78,233,28,183,127,190,121,243,230,0,114,146,82,72,192,175,4,224,203,92,168,80,33,71,135,103,187,226,9,127,166,118,237,218,57,218,105,86,
78,2,169,73,0,230,54,51,103,206,76,205,46,56,210,54,118,24,140,154,203,98,66,24,30,108,1,202,33,252,140,156,20,252,233,35,208,5,114,98,186,77,176,51,11,229,120,201,146,37,142,117,13,171,238,216,149,65,
190,211,80,129,15,150,209,132,241,48,211,213,51,151,14,173,143,175,73,192,41,2,248,238,26,73,195,129,246,241,61,13,247,241,14,230,250,117,50,96,13,82,76,185,245,62,131,251,44,238,191,8,108,231,164,188,
240,194,11,73,130,7,193,4,26,92,140,8,76,116,225,42,225,55,113,82,217,247,27,43,142,199,155,4,138,23,47,238,136,75,67,144,134,237,138,231,253,247,223,239,248,13,49,216,121,62,147,64,106,16,128,114,229,
228,164,39,53,198,132,54,17,92,195,104,96,154,72,193,22,182,108,217,226,184,82,14,223,34,45,133,77,0,59,39,110,17,228,113,197,132,196,105,31,49,236,116,238,222,189,59,201,176,59,119,238,108,88,25,199,
100,222,9,63,185,36,157,226,1,18,136,64,0,129,173,140,152,206,99,49,71,79,73,69,180,107,189,188,146,17,154,179,116,24,10,47,130,155,185,233,62,179,110,221,58,181,184,231,180,57,176,150,254,73,55,178,37,
76,252,207,158,61,155,34,79,44,110,33,6,130,31,197,204,34,159,31,199,207,49,249,159,128,150,250,40,240,209,71,31,57,54,80,219,21,79,45,7,76,224,224,193,131,142,117,152,21,147,64,106,18,208,114,89,6,180,
60,137,169,217,5,71,219,134,9,166,209,85,106,36,117,135,233,81,184,192,228,51,60,10,98,120,25,59,222,175,92,185,50,128,85,121,167,204,238,140,244,17,187,223,88,136,192,132,208,105,129,223,40,82,204,132,
11,204,143,141,238,178,254,250,235,175,134,77,170,195,219,225,123,18,176,139,0,20,74,163,166,253,111,191,253,182,238,36,8,59,252,90,30,73,187,186,20,177,158,224,125,6,166,163,169,37,159,125,246,153,82,
130,177,192,229,180,32,126,1,82,100,133,11,210,134,77,153,50,37,252,176,238,123,189,136,219,186,5,61,122,16,227,243,75,96,65,143,94,2,118,219,65,2,136,108,59,97,194,4,199,90,176,85,241,132,9,8,35,218,
58,118,173,88,113,42,19,128,255,15,118,218,252,44,240,209,28,63,126,188,161,33,34,200,2,148,174,240,92,110,120,143,96,64,78,249,56,134,118,14,109,192,228,12,187,141,177,92,240,194,142,11,118,25,177,51,
16,110,246,26,218,63,187,94,71,98,10,63,99,51,223,73,164,179,192,196,146,66,2,169,77,192,204,119,17,11,76,225,190,140,248,237,227,62,19,126,255,113,98,92,104,107,218,180,105,234,62,115,232,208,33,39,154,
208,173,243,248,241,227,42,29,19,118,119,99,49,78,220,203,192,52,124,241,17,227,135,137,191,17,75,31,236,136,250,33,133,138,238,5,249,255,131,88,192,243,67,42,181,228,198,200,207,226,151,0,2,192,181,109,
219,214,49,0,182,42,158,7,14,28,8,148,45,91,214,177,206,178,98,18,72,77,2,48,115,140,229,164,35,181,198,10,63,197,240,168,181,145,250,130,157,77,189,72,170,216,157,211,59,30,169,158,104,143,99,209,11,
171,241,80,132,225,7,26,62,113,138,182,126,156,15,191,82,40,154,104,3,62,190,177,12,206,3,19,55,189,93,100,236,26,133,71,157,140,52,86,76,8,251,246,237,27,233,99,30,39,129,152,18,192,174,167,209,232,168,
48,175,215,219,133,131,123,128,209,157,83,59,6,7,229,111,242,228,201,202,210,98,209,162,69,142,164,74,130,146,135,0,101,80,182,97,146,28,75,127,118,152,199,234,237,34,99,145,0,187,174,70,4,74,167,23,211,
95,25,25,91,104,25,44,120,98,23,152,66,2,126,35,176,98,197,10,71,179,147,164,1,48,177,73,180,27,177,104,63,70,209,34,194,217,84,35,171,33,1,119,16,208,86,56,69,51,237,18,205,140,212,29,29,114,176,23,90,
208,32,209,114,150,137,54,41,52,212,138,166,140,73,129,2,5,164,74,149,42,137,202,107,230,159,234,125,195,134,13,19,29,119,242,13,110,103,218,110,164,172,89,179,70,180,20,3,146,39,79,30,169,94,189,186,
148,40,81,66,210,164,73,99,170,105,212,165,69,144,21,205,180,90,52,165,77,178,101,203,38,53,107,214,148,210,165,75,155,170,39,218,194,154,73,179,106,187,78,157,58,137,170,210,76,0,69,83,176,69,51,139,
73,116,60,210,27,77,233,20,109,215,66,178,103,207,30,169,8,143,147,64,76,9,104,74,156,220,125,247,221,82,170,84,169,20,219,213,22,148,36,87,174,92,162,197,145,72,84,86,51,53,23,45,154,179,60,246,216,99,
137,142,59,249,6,247,6,205,204,94,214,175,95,175,238,51,55,220,112,131,212,168,81,67,138,20,41,98,169,89,45,74,172,186,103,225,249,154,107,174,81,247,82,112,73,155,54,173,165,250,172,156,180,108,217,50,
209,22,240,164,113,227,198,137,78,199,56,53,191,114,121,250,233,167,19,29,215,123,163,249,237,10,238,251,154,111,172,222,199,190,58,166,237,254,170,113,106,113,17,124,53,46,14,134,4,180,133,62,117,159,
213,44,224,28,129,97,171,226,169,173,72,10,110,60,218,110,128,35,157,101,165,36,144,90,4,52,159,14,209,146,234,42,69,38,181,250,16,203,118,181,212,40,82,175,94,61,209,194,106,27,106,86,51,205,16,205,220,
85,114,230,204,153,168,188,150,118,69,106,215,174,29,115,101,45,216,9,45,64,136,104,169,27,68,91,197,23,205,44,85,180,221,3,209,118,42,213,4,54,111,222,188,114,253,245,215,195,234,67,180,93,67,129,194,
141,9,108,134,12,25,36,75,150,44,234,81,178,100,73,209,28,237,5,101,83,67,118,236,216,33,90,206,77,209,118,89,19,53,143,254,106,62,24,162,69,183,76,116,60,210,27,205,12,89,52,127,92,209,18,205,71,42,194,
227,36,16,115,2,154,105,167,104,38,235,98,116,242,174,5,26,82,147,125,40,160,161,50,118,236,88,41,95,190,188,84,168,80,33,244,112,204,94,99,222,131,251,204,177,99,199,4,139,148,120,164,75,151,78,221,55,
130,247,25,40,145,193,251,12,158,113,31,130,146,137,199,45,183,220,34,247,221,119,159,20,46,92,56,102,125,14,109,72,179,86,19,109,151,67,52,243,209,208,195,162,89,190,8,22,172,94,127,253,117,67,11,119,
184,150,88,156,205,148,41,83,162,122,252,250,6,139,146,248,79,121,232,161,135,252,58,68,142,43,14,9,96,78,84,180,104,81,193,252,227,218,107,175,181,159,128,214,128,109,162,77,84,13,71,197,180,173,81,86,
68,2,14,19,128,79,156,94,80,23,135,155,77,213,234,97,186,10,147,82,163,2,159,23,189,52,31,240,3,69,100,200,240,148,8,70,235,117,162,28,252,148,144,112,29,166,171,8,24,130,188,152,48,217,67,42,25,35,62,
76,78,244,73,175,78,228,202,211,139,232,9,19,223,14,29,58,36,241,121,211,171,3,199,112,13,112,109,96,194,71,33,1,183,17,64,78,79,163,185,17,97,158,171,119,159,193,152,144,202,205,233,104,175,102,216,193,
44,23,209,163,225,118,176,115,231,206,128,54,137,83,230,170,136,124,237,132,43,128,153,190,133,150,213,148,224,192,139,47,190,152,228,222,135,251,6,142,35,133,138,17,65,238,83,152,8,199,155,128,81,44,
221,46,226,141,47,199,155,58,4,42,86,172,24,208,22,189,29,105,220,86,31,79,109,119,64,221,92,29,233,41,43,37,129,84,34,128,32,2,8,226,18,111,130,9,225,156,57,115,12,15,251,240,225,195,186,126,157,152,
100,65,81,130,178,71,49,70,64,219,121,85,19,108,189,9,13,124,218,204,76,176,225,251,138,232,187,20,18,112,43,1,220,99,141,42,56,240,53,68,228,236,112,193,111,5,74,105,60,248,23,134,143,221,234,123,248,
242,71,90,196,210,118,57,13,251,48,154,13,114,102,181,191,110,60,15,113,31,16,255,129,66,2,126,34,80,191,126,125,199,82,227,217,166,120,98,117,12,17,109,141,6,37,241,211,5,226,88,252,75,0,169,58,166,78,
157,234,223,1,166,48,50,4,181,193,138,184,81,129,83,186,158,178,10,165,19,19,156,88,6,202,48,218,103,183,149,195,61,244,217,103,159,13,96,23,57,92,160,68,154,73,231,115,234,212,41,221,197,128,240,122,
249,158,4,82,147,192,185,115,231,2,136,164,104,84,222,127,255,125,21,232,43,188,60,118,68,241,219,225,60,36,156,76,210,247,136,18,140,123,178,158,194,143,180,97,11,22,44,72,122,82,132,35,102,255,39,34,
84,227,217,195,189,122,245,82,22,51,158,29,0,59,78,2,97,4,158,121,230,25,21,185,63,236,176,45,111,109,83,60,97,142,168,5,8,176,165,83,172,132,4,220,66,0,102,52,241,108,162,136,149,236,231,159,127,94,153,
107,26,189,38,8,253,175,151,124,88,243,161,140,184,139,103,180,110,191,151,11,238,14,235,37,105,135,41,27,34,41,26,149,96,106,132,88,164,97,48,218,39,150,35,129,72,4,144,47,115,241,226,197,145,62,78,114,
28,187,76,90,112,159,36,199,161,72,65,249,116,147,57,107,146,78,166,242,1,252,167,225,190,174,151,139,18,102,193,200,145,106,84,180,64,110,134,77,165,141,214,233,181,114,248,111,211,252,237,189,214,109,
246,151,4,34,18,192,92,67,11,228,22,241,243,104,62,176,77,241,196,205,71,139,106,25,77,95,120,46,9,184,138,0,190,211,241,232,179,18,126,17,96,166,105,52,183,103,240,92,164,62,128,239,100,184,96,7,14,105,
2,224,67,74,73,76,0,59,16,48,21,212,243,135,197,100,112,232,208,161,137,79,72,225,29,82,32,32,197,21,133,4,188,66,0,59,103,102,242,204,226,62,3,63,237,112,129,66,133,124,148,225,185,63,195,203,197,227,
123,152,36,99,65,21,57,66,195,69,11,142,164,124,101,97,193,102,68,224,18,128,28,202,148,128,138,3,97,230,187,75,102,36,224,102,2,152,59,20,47,94,220,145,46,218,166,120,98,98,218,168,81,35,71,58,201,74,
73,32,214,4,16,100,6,10,18,229,127,4,180,8,170,166,252,183,193,15,19,18,189,201,13,2,249,96,82,136,96,62,148,255,17,192,14,39,118,105,244,204,154,225,59,139,124,135,70,39,131,168,113,195,134,13,42,225,
61,249,146,128,151,8,96,151,18,247,6,163,86,38,201,221,103,240,91,194,111,74,207,122,192,75,76,236,236,43,204,247,193,23,11,128,225,2,101,29,1,229,140,178,199,253,8,187,166,52,107,254,31,73,88,7,193,87,
153,66,2,126,32,128,123,49,220,39,97,57,101,183,216,166,120,106,57,158,28,179,7,182,123,208,172,143,4,82,34,48,111,222,188,192,182,109,219,82,42,22,55,159,99,146,241,210,75,47,5,176,194,109,84,176,178,
142,137,140,158,50,5,115,56,76,128,140,38,37,55,218,166,23,203,97,101,49,210,4,14,145,119,193,221,204,205,31,19,72,51,254,114,94,100,198,62,251,151,128,150,59,46,208,191,127,127,195,3,132,162,132,251,
140,158,217,40,148,34,124,166,103,125,97,184,1,159,20,196,110,38,238,185,122,138,56,238,199,240,247,52,99,158,60,114,228,200,128,150,51,217,39,116,236,25,6,124,240,245,118,224,237,169,157,181,144,64,108,
9,220,126,251,237,186,155,7,209,246,194,54,197,83,75,118,28,120,231,157,119,162,237,15,207,39,129,84,39,0,51,80,45,31,89,170,247,195,109,29,8,174,150,27,93,17,71,255,97,234,134,201,14,82,8,132,11,234,
129,95,12,148,252,120,149,25,51,102,40,127,42,189,52,46,90,18,103,165,144,154,49,75,134,63,103,164,40,149,241,202,152,227,246,30,1,184,56,188,253,246,219,134,59,158,220,125,6,191,45,248,44,226,183,22,
175,178,112,225,66,21,9,88,47,74,54,2,191,153,13,200,4,127,92,189,32,114,241,202,55,56,110,252,167,193,140,153,66,2,126,32,0,31,79,252,214,237,22,219,20,79,45,217,104,0,43,149,20,18,240,58,1,152,149,114,
39,78,255,42,98,213,28,17,252,204,8,76,144,224,187,168,103,222,133,122,62,252,240,67,101,150,171,23,93,209,76,59,94,42,139,148,15,152,160,192,36,86,79,112,47,197,78,141,153,29,8,212,131,157,78,250,25,
233,17,229,49,175,17,128,143,242,174,93,187,12,119,27,247,25,44,114,193,74,64,79,144,30,10,191,57,228,214,140,23,129,82,137,123,66,164,201,35,22,4,161,116,154,73,117,117,228,200,145,0,124,107,41,250,4,
150,46,93,170,27,244,74,191,52,143,146,128,123,9,52,110,220,56,48,122,244,104,219,59,152,6,53,74,148,162,173,200,75,137,18,37,68,155,172,75,250,244,233,163,172,141,167,147,64,234,17,208,118,245,68,91,
29,23,45,79,92,234,117,194,229,45,107,19,56,57,120,240,160,104,59,107,134,123,170,173,180,139,22,56,68,26,52,104,32,21,42,84,72,114,158,54,241,81,220,53,211,14,105,210,164,73,146,207,253,114,0,183,219,
185,115,231,138,150,84,94,52,31,88,185,230,154,107,146,12,13,124,181,192,86,210,183,111,95,83,247,83,205,244,77,42,87,174,44,229,203,151,79,82,39,15,136,104,11,31,2,182,120,78,109,201,148,41,147,250,29,
220,117,215,93,130,215,148,164,4,240,91,209,148,38,209,22,96,36,127,254,252,73,11,232,28,193,125,70,91,24,19,45,222,132,238,239,0,247,119,77,161,149,194,133,11,203,99,143,61,38,105,210,164,209,169,197,
31,135,52,11,52,209,2,195,169,251,76,246,236,217,147,12,10,247,240,105,211,166,201,192,129,3,37,75,150,44,73,62,215,59,160,185,90,168,242,90,142,79,73,151,46,157,94,17,30,211,8,104,241,33,100,212,168,
81,190,254,126,241,66,251,159,128,22,91,66,180,133,58,117,159,176,115,180,182,40,158,218,10,152,180,108,217,82,180,213,73,59,251,198,186,72,32,230,4,180,200,161,242,196,19,79,200,245,215,95,31,243,182,
189,212,160,150,227,77,41,69,152,224,25,21,76,36,181,221,100,201,152,49,163,180,107,215,78,247,52,45,13,139,104,102,118,162,229,144,18,205,138,66,183,140,87,15,106,190,156,162,229,132,85,138,117,165,74,
149,146,12,3,124,180,84,52,114,229,149,87,202,147,79,62,153,228,243,228,14,104,102,111,114,245,213,87,203,67,15,61,148,92,177,184,252,76,51,63,86,139,30,154,159,172,250,109,151,46,93,58,213,57,104,187,
115,178,100,201,18,89,189,122,181,60,245,212,83,162,69,132,79,245,62,185,177,3,88,212,126,249,229,151,69,51,201,151,172,89,179,26,234,34,126,71,227,198,141,83,191,135,214,173,91,235,158,179,101,203,22,
209,204,79,165,109,219,182,114,219,109,183,233,150,241,234,65,205,90,66,180,84,51,82,183,110,93,169,94,189,186,238,48,48,246,147,39,79,42,197,62,109,218,180,186,101,194,15,106,230,204,74,137,29,54,108,
152,92,117,213,85,225,31,243,125,8,129,143,63,254,88,180,20,43,162,237,24,133,28,229,75,18,240,22,129,101,203,150,201,224,193,131,101,251,246,237,246,118,92,187,73,71,45,90,231,2,53,106,212,136,186,30,
86,64,2,169,73,0,185,184,180,31,89,106,118,193,83,109,35,146,245,218,181,107,77,247,121,211,166,77,42,96,14,146,198,235,9,252,144,96,238,140,212,10,48,73,245,186,224,123,213,179,103,207,192,228,201,147,
35,70,140,196,56,97,90,187,99,199,14,211,195,93,177,98,69,64,83,104,77,159,23,47,39,104,59,199,186,129,103,220,50,254,33,67,134,4,52,37,192,45,221,113,93,63,112,159,48,27,248,6,131,208,22,177,148,175,
126,164,232,217,240,199,195,111,18,191,77,252,70,189,46,8,26,212,167,79,159,192,216,177,99,35,166,171,130,57,50,34,100,191,255,254,251,166,134,11,86,8,128,230,7,78,166,6,30,69,97,4,133,3,55,10,9,120,149,
0,178,18,220,122,235,173,182,119,223,150,29,79,152,93,104,121,230,4,187,32,20,18,240,42,1,152,130,98,117,221,232,202,186,87,199,105,103,191,181,73,179,84,173,90,85,215,124,54,185,118,96,90,139,221,101,
152,134,62,248,224,131,186,69,181,9,103,194,14,32,118,64,245,204,82,117,79,116,201,65,140,17,59,15,216,81,104,223,190,125,196,239,21,118,190,62,253,244,83,233,214,173,155,233,49,194,116,116,247,238,221,
162,249,174,185,100,212,238,234,134,22,160,73,52,159,43,209,38,205,238,234,88,72,111,176,171,7,211,126,152,60,82,244,9,104,17,107,149,41,62,204,100,205,184,243,104,126,227,234,62,131,157,191,90,181,106,
233,86,174,69,190,85,191,83,45,114,183,250,157,94,119,221,117,186,229,220,122,16,187,231,19,39,78,20,205,31,92,52,127,77,209,51,171,69,223,55,111,222,172,118,217,97,190,108,198,162,7,92,94,121,229,21,
181,51,95,168,80,33,183,98,112,93,191,96,202,140,157,162,72,214,61,174,235,48,59,68,2,97,4,96,37,4,203,179,67,135,14,73,134,12,25,194,62,181,254,214,22,197,19,230,44,121,243,230,85,230,48,214,187,194,
51,73,32,245,8,156,56,113,66,180,0,12,162,5,193,73,189,78,120,180,229,87,95,125,85,154,54,109,42,37,75,150,52,61,130,229,203,151,139,182,3,42,218,234,112,196,201,16,38,157,218,206,132,50,157,131,9,170,
219,23,6,160,112,78,154,52,73,224,111,166,165,153,146,220,185,115,235,114,129,82,164,57,238,171,9,113,205,154,53,117,203,36,119,16,202,234,170,85,171,148,79,91,114,229,226,249,51,152,20,34,254,0,30,110,
22,44,122,105,41,68,220,220,197,84,239,155,182,250,46,90,186,10,165,72,154,245,205,196,226,14,22,199,177,176,152,51,103,78,221,177,192,151,9,191,91,152,186,227,119,235,118,5,244,194,133,11,138,135,182,
163,171,76,243,11,20,40,160,59,46,124,14,133,189,88,177,98,210,162,69,11,221,50,201,29,212,118,81,229,145,71,30,241,157,73,114,114,99,182,235,51,45,175,167,224,255,49,115,230,204,118,85,201,122,72,32,
166,4,202,148,41,163,226,82,216,233,250,100,139,226,137,96,33,112,66,173,95,191,126,76,129,176,49,18,176,139,0,118,155,180,72,125,202,255,208,174,58,227,165,158,224,138,120,155,54,109,44,249,101,98,2,
53,102,204,24,165,80,98,103,243,138,43,174,208,69,7,5,20,62,146,90,122,4,21,24,164,72,145,34,186,229,82,235,224,225,195,135,69,75,13,147,224,195,154,39,79,30,221,174,96,135,11,190,174,80,76,177,19,103,
101,82,162,229,37,20,45,221,132,218,37,51,59,9,215,237,148,79,15,46,94,188,88,240,61,113,187,31,31,21,79,99,95,192,189,123,247,170,93,59,220,171,205,126,239,177,179,137,133,158,92,185,114,41,69,45,210,
206,169,22,233,85,221,103,224,27,12,69,13,10,155,155,4,139,164,179,103,207,86,93,194,110,90,36,133,19,247,229,89,179,102,9,202,35,216,77,142,28,57,76,15,35,104,149,162,231,147,110,186,178,56,60,65,139,
176,44,239,190,251,174,226,31,135,195,231,144,125,64,64,115,163,84,1,222,34,89,166,89,25,162,45,138,39,52,97,205,207,72,104,134,97,229,18,240,156,212,38,128,201,12,30,173,90,181,74,237,174,120,182,125,
40,131,88,124,106,222,188,185,32,50,173,21,65,164,87,236,108,98,146,243,240,195,15,71,156,88,66,81,197,14,6,162,104,103,203,150,77,149,77,173,123,15,250,128,96,72,216,85,192,174,26,250,29,41,66,164,230,
40,161,148,69,236,84,66,193,46,88,176,160,21,76,162,249,129,170,251,45,38,223,70,3,131,88,106,200,7,39,105,62,105,106,49,0,59,93,110,149,223,127,255,93,16,176,133,59,158,198,174,16,126,63,136,216,10,243,
100,43,145,85,97,2,57,125,250,116,209,114,212,169,0,60,145,90,197,117,129,153,54,204,204,174,189,246,90,21,145,91,243,119,138,84,220,209,227,8,4,132,190,104,126,156,106,33,165,97,195,134,201,90,126,172,
95,191,94,16,24,4,145,123,203,150,45,107,186,111,184,87,193,244,251,190,251,238,147,123,239,189,215,244,249,60,225,63,2,216,49,134,43,4,190,67,20,18,240,26,1,88,179,85,172,88,81,41,159,118,245,61,106,
197,83,115,158,86,43,130,136,108,27,105,167,194,174,206,178,30,18,112,130,0,38,165,195,135,15,183,52,137,113,162,63,94,173,19,147,21,68,64,131,105,70,237,218,181,45,15,3,126,139,88,37,198,10,27,38,135,
201,9,204,227,62,248,224,3,129,25,30,252,17,238,184,227,14,229,115,106,101,117,63,185,118,130,159,105,65,128,4,147,58,236,56,98,199,4,19,81,248,142,165,212,30,76,98,181,124,165,42,202,33,110,226,86,5,
74,46,162,86,118,238,220,57,162,98,110,181,110,191,158,135,93,27,44,136,220,120,227,141,174,28,34,38,248,112,87,201,151,47,159,43,251,231,198,78,97,190,1,179,88,68,187,141,180,208,147,82,191,241,123,196,
239,18,102,164,247,220,115,79,178,197,145,70,4,247,25,252,246,112,159,65,100,100,248,182,99,247,212,9,129,127,59,34,124,195,127,27,139,75,88,164,194,125,38,37,223,76,100,22,128,213,5,20,70,171,17,174,
97,145,129,148,52,248,205,220,121,231,157,78,12,47,174,234,196,127,20,22,58,96,118,75,33,1,175,17,128,53,32,220,135,176,41,96,151,68,173,120,98,194,135,188,123,184,65,82,72,192,107,4,16,112,1,202,4,38,
31,20,123,8,204,156,57,83,176,43,25,141,191,44,148,88,88,81,96,242,5,5,180,90,181,106,41,118,14,187,174,251,246,237,83,65,52,190,249,230,27,129,153,19,124,207,111,190,249,102,245,184,229,150,91,228,166,
155,110,82,190,162,201,85,134,92,127,200,245,24,250,128,249,29,206,133,89,27,2,34,193,116,211,200,110,35,210,101,96,194,10,69,60,82,112,147,228,250,18,252,12,60,16,196,13,202,73,179,102,205,130,135,249,
108,128,0,22,71,181,72,159,42,125,4,210,255,148,43,87,206,192,89,206,22,193,14,57,22,87,240,125,69,64,24,44,152,80,204,17,192,132,30,187,196,200,135,139,223,166,21,193,239,10,187,167,219,182,109,19,236,
34,26,49,41,133,9,43,22,158,224,155,14,243,127,220,39,160,16,226,254,18,188,215,224,57,165,148,35,72,79,130,123,20,118,51,81,7,158,81,31,22,72,112,223,130,50,140,239,69,36,147,224,208,241,98,23,120,254,
252,249,202,218,4,10,163,149,157,96,212,7,11,1,44,132,96,178,121,195,13,55,132,54,193,215,81,16,192,130,44,204,162,157,90,168,136,162,107,60,149,4,146,37,0,119,21,184,40,32,69,144,93,18,181,226,137,73,
21,118,139,214,173,91,103,87,159,88,15,9,196,140,0,76,96,48,161,55,235,47,20,179,14,122,180,33,152,131,34,202,53,204,140,162,49,49,10,42,160,27,54,108,80,147,66,172,226,27,157,84,65,17,197,206,1,204,211,
16,221,18,207,120,96,194,7,101,4,62,150,120,134,32,160,8,44,54,240,192,14,10,118,48,17,29,18,207,120,32,208,136,209,118,81,103,48,152,9,130,6,69,163,112,162,111,232,51,204,10,97,10,78,5,5,68,172,9,56,
226,207,19,139,165,248,94,165,166,224,59,118,247,221,119,171,5,12,163,223,171,212,236,175,91,219,198,111,24,138,82,249,242,229,35,70,199,54,210,119,40,147,248,205,66,1,133,149,69,157,58,117,12,255,39,
232,221,103,112,191,129,169,46,238,5,193,7,190,115,184,191,4,239,53,153,50,101,74,114,159,129,235,128,17,69,51,56,38,88,95,32,40,30,238,11,48,137,51,115,110,176,142,224,51,234,194,124,14,247,108,43,126,
231,193,122,248,156,148,0,118,140,176,248,5,182,20,18,240,18,1,88,151,96,193,22,46,7,118,73,212,138,39,210,5,64,233,132,86,76,33,1,47,17,208,114,153,169,73,0,156,167,41,246,19,128,210,7,83,184,122,245,
234,73,149,42,85,162,110,0,81,41,113,205,48,73,68,157,216,185,114,203,130,1,38,149,152,180,98,18,136,201,31,2,173,217,97,166,134,137,32,38,132,90,174,65,211,169,86,162,6,206,10,72,192,35,4,176,107,137,
93,72,164,253,128,66,103,85,240,59,134,21,12,204,112,161,32,98,23,212,74,180,110,171,237,27,57,15,230,190,139,22,45,82,138,45,204,125,161,40,27,177,190,136,84,55,148,119,68,189,133,53,71,203,150,45,35,
21,227,241,40,9,140,28,57,82,89,7,70,10,6,21,101,245,60,157,4,28,33,128,32,107,136,95,113,236,216,177,168,238,51,161,157,139,90,241,68,180,52,172,248,141,27,55,46,180,94,190,38,1,87,19,128,242,2,63,57,
236,118,82,156,37,48,119,238,92,229,27,5,147,184,148,204,207,140,244,4,59,150,107,214,172,81,185,47,177,155,128,224,25,200,211,23,235,52,43,88,197,70,63,246,236,217,163,38,169,80,132,209,143,140,25,51,
26,25,70,178,101,16,129,19,150,36,216,201,192,106,35,133,4,72,32,121,2,48,175,31,49,98,132,218,249,139,198,143,58,216,10,126,131,88,72,66,180,106,40,164,48,125,133,239,100,52,138,109,176,110,51,207,80,
12,161,12,195,247,29,255,91,136,210,12,247,3,236,142,70,43,184,119,193,255,16,243,56,171,193,206,162,237,67,188,156,143,124,171,240,55,199,14,61,133,4,188,68,0,62,237,112,125,178,107,209,36,106,197,19,
166,100,240,57,66,42,5,10,9,120,133,0,82,81,192,135,5,230,110,20,231,9,192,119,8,43,190,152,184,97,183,210,46,193,162,23,34,18,195,223,10,138,32,118,64,239,186,235,46,193,125,41,26,179,51,189,254,97,2,
8,159,77,248,83,97,34,10,83,92,140,199,168,191,167,94,157,122,199,176,123,131,221,93,44,140,68,202,57,168,119,30,143,145,64,188,19,192,239,18,169,70,144,66,4,191,159,107,174,185,198,22,36,248,237,195,
125,96,235,214,173,2,5,2,201,212,17,237,213,169,136,175,219,183,111,87,150,14,127,254,249,167,82,116,145,178,14,202,180,29,139,90,0,130,197,59,44,186,194,141,224,169,167,158,178,109,39,195,22,216,62,174,
4,27,52,15,60,240,0,149,124,31,95,99,63,14,13,243,28,248,211,227,217,14,137,90,241,44,85,170,148,204,212,130,137,32,146,37,133,4,188,64,0,81,9,97,146,5,243,34,74,108,9,96,7,97,237,218,181,210,161,67,7,
71,254,124,113,109,15,28,56,160,2,117,64,17,13,62,16,204,5,130,137,22,148,185,160,239,38,158,49,89,13,250,127,134,62,163,60,124,59,67,31,216,21,128,217,137,221,74,45,218,66,58,25,184,46,64,49,79,41,154,
47,202,83,72,128,4,244,9,32,96,220,168,81,163,148,153,236,163,143,62,106,187,73,62,20,55,44,64,33,40,16,252,57,241,128,107,1,142,99,65,10,247,152,240,7,204,97,17,29,23,15,244,47,248,26,231,66,161,196,
14,38,206,197,3,1,134,96,201,97,135,133,72,56,33,164,101,129,2,221,169,83,39,201,159,63,127,248,199,124,239,32,1,44,36,96,2,63,100,200,16,7,91,97,213,36,96,47,129,6,13,26,168,116,82,118,165,28,140,90,
241,44,92,184,176,90,9,180,195,236,195,94,84,172,141,4,244,9,204,152,49,67,249,223,193,124,128,18,123,2,240,25,128,130,133,157,3,68,190,141,38,248,144,153,222,35,77,0,204,231,194,31,216,37,133,153,110,
248,3,62,94,177,16,76,60,177,18,30,220,125,136,85,187,177,24,27,219,32,129,212,36,0,5,11,214,45,80,62,97,9,225,180,192,2,3,247,23,44,116,133,62,227,53,22,184,130,247,24,220,243,240,58,248,236,196,66,86,
248,88,17,65,25,255,125,92,216,10,39,19,219,247,72,75,1,179,237,226,197,139,199,182,97,182,70,2,22,9,32,34,51,34,119,35,200,161,29,18,149,226,137,155,43,76,64,144,68,157,66,2,94,32,0,229,163,119,239,222,
42,97,187,23,250,235,231,62,34,29,194,132,9,19,18,20,46,187,204,200,188,194,12,187,35,19,39,78,84,169,103,176,3,12,197,147,66,2,36,96,47,1,248,69,34,213,8,76,242,97,86,138,197,242,120,146,175,190,250,
74,45,244,21,42,84,72,158,120,226,9,71,172,53,226,137,103,180,99,133,217,54,242,164,194,135,159,66,2,94,32,0,179,252,45,91,182,168,212,83,118,244,55,42,197,19,142,233,237,219,183,23,248,35,80,72,192,11,
4,176,211,134,156,144,183,222,122,171,23,186,27,23,125,68,122,139,169,83,167,170,60,120,48,229,240,251,142,31,118,124,17,208,3,193,80,48,17,182,154,131,48,46,190,28,28,36,9,216,68,0,191,59,220,103,224,
111,254,244,211,79,251,62,79,37,114,15,227,255,14,59,171,24,47,82,248,80,220,65,0,238,105,8,28,71,171,43,119,92,15,246,34,121,2,200,167,254,242,203,47,203,238,221,187,147,47,104,240,211,168,20,79,248,
10,76,154,52,73,5,220,48,216,30,139,145,64,170,17,192,14,19,210,123,224,65,113,31,1,228,137,66,96,16,36,98,199,202,188,223,118,64,241,253,131,194,137,36,241,173,91,183,86,209,41,221,119,21,216,35,18,240,
55,1,152,248,79,153,50,69,249,101,62,249,228,147,202,159,210,79,35,254,238,187,239,4,230,156,136,190,11,133,51,86,174,12,126,98,232,244,88,24,103,194,105,194,172,223,78,2,95,126,249,165,202,71,110,151,
117,107,84,138,231,232,209,163,213,110,39,18,197,83,72,192,237,4,198,140,25,35,15,61,244,16,119,152,92,126,161,112,115,131,2,10,191,113,236,128,122,221,4,21,38,197,88,225,190,112,225,130,26,15,76,222,
40,36,64,2,169,75,0,10,232,180,105,211,212,14,104,211,166,77,213,14,84,234,246,40,186,214,145,246,5,169,171,160,104,66,161,166,194,25,29,79,167,207,198,181,130,229,21,130,72,81,72,192,205,4,176,80,82,
180,104,81,57,114,228,136,92,113,197,21,81,119,53,42,197,19,102,182,48,223,96,116,208,168,175,3,43,112,152,0,38,253,200,241,134,136,114,20,111,16,128,73,28,124,179,240,12,95,242,186,117,235,122,102,23,
20,209,11,151,45,91,38,187,118,237,82,145,35,155,55,111,46,185,114,229,242,6,120,246,146,4,226,136,0,124,238,222,125,247,93,21,165,54,111,222,188,210,164,73,19,21,72,195,11,8,16,25,119,209,162,69,130,
29,137,146,37,75,170,156,191,177,206,51,234,5,78,110,236,35,2,81,117,237,218,85,165,25,115,99,255,216,39,18,8,37,0,211,112,164,122,131,69,90,180,18,149,226,137,144,255,48,137,123,252,241,199,163,237,7,
207,39,1,71,9,96,113,4,147,255,124,249,242,57,218,14,43,183,159,0,162,65,34,175,37,210,176,96,1,1,9,212,235,212,169,227,186,201,33,76,104,223,127,255,125,149,202,5,249,3,107,213,170,165,162,39,35,106,
46,197,31,4,16,25,20,41,122,16,133,20,59,21,126,51,7,247,199,85,178,62,138,175,191,254,90,45,24,225,183,12,223,72,220,103,144,50,206,77,191,97,236,58,32,45,21,82,63,229,201,147,71,234,215,175,47,55,223,
124,179,245,65,243,204,84,35,192,124,226,169,134,158,13,155,36,80,181,106,85,21,152,19,207,209,74,84,138,39,115,120,70,139,159,231,199,130,0,38,138,99,199,142,149,62,125,250,196,162,57,182,225,48,129,
207,63,255,92,41,161,240,101,130,96,37,14,137,141,99,109,146,11,19,218,141,27,55,10,148,17,228,232,67,78,188,234,213,171,59,146,159,212,97,164,172,94,135,0,118,194,144,19,54,152,163,26,121,33,95,122,233,
165,132,146,149,43,87,150,77,155,54,37,188,231,11,127,17,64,154,163,117,235,214,201,193,131,7,229,210,165,75,74,185,195,164,43,214,81,113,145,43,116,195,134,13,130,251,30,204,220,96,242,134,251,12,45,
40,188,255,125,67,196,229,46,93,186,112,215,211,251,151,210,247,35,176,51,151,103,84,138,39,110,192,200,147,133,68,201,20,18,112,43,129,161,67,135,170,96,46,185,115,231,118,107,23,217,47,139,4,224,123,
128,52,9,8,245,13,115,51,236,84,192,111,6,57,210,138,21,43,166,94,71,187,43,5,179,89,248,157,98,167,1,126,84,152,0,222,112,195,13,42,40,9,242,177,221,118,219,109,146,46,93,58,139,35,224,105,110,37,0,51,
105,152,119,195,28,14,17,253,96,49,17,26,207,32,67,134,12,130,72,169,148,248,32,112,242,228,73,181,208,128,123,1,34,113,99,161,9,247,152,224,35,218,121,208,185,115,231,212,61,6,247,25,60,112,63,43,88,
176,160,82,116,239,189,247,94,6,35,243,233,215,108,241,226,197,106,231,26,255,37,20,18,112,43,1,4,68,188,241,198,27,165,111,223,190,81,119,209,178,226,249,251,239,191,171,157,134,163,71,143,186,202,12,
37,106,34,172,192,87,4,176,106,141,144,242,200,155,69,241,63,1,236,82,193,4,13,190,79,120,224,250,67,57,192,142,133,222,3,126,54,16,152,78,98,55,33,248,140,215,193,7,124,166,178,103,207,174,22,216,48,
185,196,206,42,62,163,248,159,0,148,141,134,13,27,170,133,12,196,52,120,244,209,71,85,26,28,140,156,138,167,255,175,127,164,17,98,167,10,138,34,238,49,184,223,224,1,55,0,44,132,5,239,51,225,175,225,50,
16,188,167,132,222,103,130,175,17,47,35,120,127,193,61,6,247,28,46,104,69,186,2,254,57,142,239,5,22,182,144,43,145,66,2,110,37,48,120,240,96,101,1,132,184,27,209,138,101,197,19,43,114,240,237,252,228,
147,79,162,237,3,207,39,1,199,8,32,117,10,66,202,199,218,12,211,177,1,177,98,91,9,224,79,31,226,38,31,46,91,7,200,202,162,38,128,69,214,118,237,218,169,93,111,164,169,192,36,113,243,230,205,84,60,163,
38,203,10,72,128,4,64,0,169,9,177,208,128,157,109,10,9,184,145,192,138,21,43,100,192,128,1,178,99,199,142,168,187,103,89,241,252,240,195,15,101,216,176,97,202,7,34,234,94,176,2,18,112,128,0,86,163,145,
175,173,71,143,30,14,212,206,42,73,128,4,226,129,64,237,218,181,213,78,39,124,122,17,164,108,214,172,89,130,63,97,88,82,32,192,30,118,205,135,12,25,34,229,203,151,143,7,28,28,35,9,144,128,205,4,184,235,
105,51,80,86,103,59,1,108,54,54,106,212,72,144,111,61,90,177,172,120,34,255,21,34,56,46,89,178,36,218,62,240,124,18,112,132,0,86,103,58,116,232,160,242,65,58,210,0,43,37,1,18,240,61,1,152,90,111,219,182,
77,165,245,193,96,145,91,22,1,65,174,191,254,122,105,209,162,133,242,195,27,63,126,188,138,128,234,123,24,28,32,9,144,128,35,4,144,210,7,185,171,185,235,233,8,94,86,26,37,1,228,61,46,93,186,180,156,56,
113,34,202,154,52,11,51,109,165,229,127,182,102,38,171,234,221,187,183,242,117,153,62,125,186,201,51,89,156,4,156,39,128,221,137,25,51,102,200,43,175,188,226,124,99,108,129,4,72,192,183,4,50,103,206,44,
31,127,252,177,12,31,62,92,41,159,35,71,142,84,166,183,8,96,53,117,234,84,65,116,91,4,48,171,81,163,134,111,25,112,96,36,64,2,206,18,224,174,167,179,124,89,123,244,4,16,72,13,129,28,177,64,18,141,88,86,
60,155,53,107,166,180,223,238,221,187,71,211,62,207,37,1,71,8,244,239,223,95,158,123,238,57,185,238,186,235,28,169,159,149,146,0,9,196,7,1,152,218,34,130,59,22,177,96,94,139,0,49,47,188,240,130,60,243,
204,51,42,250,40,204,249,17,125,52,218,63,227,248,160,201,81,146,0,9,68,34,64,95,207,72,100,120,220,13,4,42,84,168,32,147,38,77,82,186,95,52,253,177,172,120,162,3,240,157,67,242,98,10,9,184,137,192,153,
51,103,148,31,86,183,110,221,220,212,45,246,133,4,72,192,131,4,144,71,17,249,27,177,136,85,167,78,29,185,246,218,107,5,81,77,161,108,34,229,197,136,17,35,100,238,220,185,42,183,162,7,135,199,46,147,0,
9,184,132,0,119,61,93,114,33,216,13,93,2,53,107,214,148,78,157,58,169,52,99,186,5,12,30,180,172,120,150,40,81,66,222,126,251,109,41,89,178,164,193,166,88,140,4,98,67,0,187,157,207,63,255,188,154,32,198,
166,69,182,66,2,36,224,103,2,72,211,179,103,207,30,65,110,79,44,104,193,207,19,129,133,144,231,115,211,166,77,202,215,19,238,39,240,41,167,144,0,9,144,128,85,2,136,155,146,43,87,46,97,94,79,171,4,121,
158,83,4,16,92,8,46,37,200,20,17,141,88,86,60,11,21,42,164,254,132,177,250,75,33,1,183,16,224,110,167,91,174,4,251,65,2,254,33,240,203,47,191,72,159,62,125,4,1,22,176,187,9,165,51,79,158,60,234,15,184,
92,185,114,130,93,209,63,255,252,83,229,251,244,207,168,57,18,18,32,129,88,19,192,174,103,231,206,157,5,190,228,20,18,112,19,129,39,159,124,82,114,231,206,45,3,7,14,140,170,91,150,20,79,252,249,150,41,
83,70,142,30,61,26,85,227,60,153,4,236,38,192,221,78,187,137,178,62,18,32,129,75,151,46,169,212,97,23,47,94,76,4,163,98,197,138,106,119,34,209,65,190,33,1,18,32,129,40,8,44,90,180,72,242,229,203,39,184,
191,80,72,192,45,4,16,68,15,150,63,176,118,141,70,44,41,158,80,56,17,70,30,102,71,20,18,112,11,1,68,178,157,57,115,166,50,133,115,75,159,216,15,18,32,1,18,32,1,18,32,1,18,48,74,0,62,228,93,187,118,85,
121,131,141,158,195,114,36,224,52,129,101,203,150,201,224,193,131,101,251,246,237,81,53,101,73,241,92,191,126,189,32,71,226,71,31,125,20,85,227,60,153,4,236,36,128,239,100,199,142,29,25,201,214,78,168,
172,139,4,72,128,4,72,128,4,72,32,166,4,230,207,159,175,2,152,149,47,95,62,166,237,178,49,18,136,68,224,192,129,3,130,140,38,135,14,29,138,84,196,208,113,75,138,231,156,57,115,100,225,194,133,2,237,151,
66,2,110,32,240,195,15,63,200,180,105,211,132,233,125,220,112,53,216,7,18,32,1,18,32,1,18,32,1,171,4,46,95,190,172,82,56,33,106,54,133,4,220,64,224,167,159,126,18,100,52,57,118,236,88,84,221,177,164,120,
34,145,246,190,125,251,84,144,133,168,90,231,201,36,96,19,1,56,59,183,111,223,94,178,103,207,110,83,141,172,134,4,72,128,4,72,128,4,72,128,4,82,135,192,91,111,189,165,50,71,220,113,199,29,169,211,1,182,
74,2,33,4,16,248,170,72,145,34,178,127,255,126,201,148,41,83,200,39,230,94,90,82,60,49,193,191,234,170,171,84,254,50,115,205,177,52,9,216,79,224,236,217,179,42,169,109,207,158,61,237,175,156,53,146,0,
9,144,0,9,144,0,9,144,64,140,9,252,243,207,63,210,163,71,15,193,102,15,133,4,220,64,0,139,32,239,188,243,142,220,114,203,45,150,187,99,73,241,68,18,237,135,31,126,88,158,122,234,41,203,13,243,68,18,176,
139,192,144,33,67,164,93,187,118,146,51,103,78,187,170,100,61,36,64,2,36,64,2,36,64,2,36,144,170,4,224,66,4,243,198,18,37,74,164,106,63,216,56,9,128,192,189,247,222,43,152,115,87,170,84,201,50,16,75,138,
39,52,222,81,163,70,73,149,42,85,44,55,204,19,73,192,14,2,231,207,159,151,241,227,199,203,171,175,190,106,71,117,172,131,4,72,128,4,72,128,4,72,128,4,92,65,224,239,191,255,150,222,189,123,11,82,89,80,
72,32,181,9,60,240,192,3,210,166,77,27,105,212,168,145,229,174,88,82,60,139,23,47,46,239,189,247,158,20,46,92,216,114,195,60,145,4,236,32,0,19,148,199,31,127,92,37,115,183,163,62,214,65,2,36,64,2,36,64,
2,36,64,2,110,33,240,230,155,111,74,245,234,213,57,231,118,203,5,137,227,126,52,109,218,84,238,185,231,30,121,238,185,231,44,83,176,164,120,22,42,84,72,37,17,189,250,234,171,45,55,204,19,73,32,90,2,191,
254,250,171,188,254,250,235,210,183,111,223,104,171,226,249,36,64,2,36,144,132,192,95,127,253,37,200,169,103,68,50,100,200,32,105,211,166,53,82,148,101,72,128,4,72,192,48,129,63,255,252,83,16,64,113,208,
160,65,134,207,97,65,18,112,130,192,51,207,60,35,215,94,123,109,84,59,240,166,21,207,223,126,251,77,202,148,41,35,71,143,30,117,98,76,172,147,4,12,19,128,210,217,164,73,19,201,159,63,191,225,115,88,144,
4,72,128,4,82,34,176,116,233,82,245,31,119,238,220,57,217,180,105,147,124,247,221,119,201,158,2,255,43,248,97,221,112,195,13,202,2,35,93,186,116,201,150,231,135,36,64,2,36,96,134,192,232,209,163,165,97,
195,134,234,30,99,230,60,150,37,1,59,9,192,228,123,239,222,189,178,96,193,2,203,213,154,86,60,143,31,63,174,38,251,187,119,239,182,220,40,79,36,129,104,9,252,241,199,31,50,120,240,96,181,10,24,109,93,
60,159,4,72,128,4,130,4,224,70,130,221,203,218,181,107,7,15,201,215,95,127,45,223,124,243,141,32,156,124,168,100,204,152,81,77,4,115,228,200,161,14,127,250,233,167,114,248,240,97,105,217,178,101,104,49,
190,38,1,18,32,129,168,8,92,184,112,65,94,123,237,53,233,215,175,95,84,245,240,100,18,136,134,0,34,218,34,198,207,199,31,127,108,185,26,211,138,231,150,45,91,164,123,247,238,106,21,216,114,171,60,145,
4,162,36,128,128,66,112,114,142,38,164,115,148,93,224,233,36,64,2,62,36,128,180,76,209,152,180,245,234,213,139,11,98,62,252,94,112,72,36,144,218,4,134,13,27,38,173,90,181,146,220,185,115,167,118,87,216,
126,156,18,192,226,42,190,131,7,14,28,176,76,192,180,226,185,100,201,18,153,58,117,170,172,92,185,210,114,163,60,145,4,162,33,0,191,43,248,117,34,164,51,133,4,72,128,4,236,36,128,63,214,25,51,102,72,141,
26,53,4,17,220,175,184,226,138,20,171,199,78,40,220,79,150,47,95,46,15,61,244,144,220,119,223,125,41,158,195,2,36,64,2,36,96,134,0,76,255,17,104,136,57,203,205,80,99,89,59,9,192,242,231,254,251,239,143,
202,221,210,180,226,137,47,253,250,245,235,101,209,162,69,118,142,133,117,145,128,97,2,88,248,64,14,161,98,197,138,25,62,135,5,163,35,0,101,255,151,95,126,73,120,252,252,243,207,9,175,113,28,102,64,191,
255,254,187,32,244,123,214,172,89,149,243,57,28,208,67,95,7,223,227,24,125,224,162,187,30,60,219,89,2,72,211,132,21,221,207,63,255,92,144,196,61,37,73,147,38,141,50,185,189,243,206,59,185,27,145,18,44,
126,158,234,4,46,93,186,36,8,206,135,7,238,221,225,175,113,12,129,178,174,185,230,26,65,16,201,72,207,233,211,167,79,245,177,196,91,7,6,12,24,160,34,138,226,255,148,66,2,177,38,128,57,94,209,162,69,229,
196,137,19,130,255,61,43,98,90,241,236,211,167,143,242,119,153,62,125,186,149,246,120,14,9,68,69,0,147,192,30,61,122,8,210,168,80,156,33,0,255,89,56,143,239,218,181,75,249,181,193,191,13,74,37,148,69,
68,215,195,231,184,14,184,1,93,190,124,89,69,253,196,251,139,23,47,170,14,161,28,38,45,65,229,18,81,65,131,229,240,26,55,43,40,159,217,179,103,151,156,57,115,74,222,188,121,165,108,217,178,82,170,84,41,
41,88,176,160,192,111,142,66,2,36,64,2,36,96,157,0,22,79,142,29,59,38,216,193,199,34,202,247,223,127,47,63,253,244,147,122,32,72,36,238,195,193,123,53,238,215,120,96,231,62,244,126,141,214,113,12,247,
111,60,7,39,154,120,157,37,75,22,185,253,246,219,213,61,60,79,158,60,130,52,123,8,178,5,247,151,224,189,223,122,239,121,102,36,2,167,79,159,150,185,115,231,74,231,206,157,35,21,225,113,18,112,148,0,54,
125,224,118,153,45,91,54,75,237,152,86,60,91,183,110,173,162,136,98,213,133,66,2,177,38,128,27,46,190,244,216,89,160,216,67,0,59,150,112,20,199,4,5,74,37,76,11,49,161,184,242,202,43,101,243,230,205,178,
127,255,126,193,159,29,20,203,76,153,50,73,190,124,249,18,30,80,26,241,62,248,140,32,43,193,201,73,164,222,65,97,253,226,139,47,4,129,202,240,128,137,226,190,125,251,4,102,68,88,137,135,82,138,137,204,
77,55,221,36,181,106,213,146,154,53,107,170,96,47,145,234,227,113,18,32,1,18,136,103,2,103,207,158,21,184,65,109,221,186,85,45,22,254,240,195,15,106,145,16,65,178,10,20,40,32,165,75,151,86,57,32,145,10,
15,143,235,175,191,62,197,212,63,184,23,159,57,115,70,190,253,246,91,21,213,57,244,25,139,145,104,19,247,114,44,30,98,247,13,147,80,212,139,255,15,236,144,226,61,254,171,17,237,153,138,168,189,223,206,
87,95,125,85,197,90,201,156,57,179,189,21,179,54,18,48,64,0,27,5,115,230,204,81,59,159,6,138,39,41,98,90,241,196,36,176,121,243,230,2,5,148,66,2,177,36,128,85,214,46,93,186,168,200,110,177,108,215,143,
109,33,61,4,162,119,66,1,132,50,9,155,125,164,165,193,228,5,74,40,86,202,49,169,128,2,90,181,106,85,53,121,192,142,164,211,166,85,152,236,28,57,114,68,229,9,222,185,115,167,108,216,176,65,48,137,194,228,
6,59,164,232,3,162,141,162,95,152,80,165,164,228,250,241,218,113,76,36,64,2,241,73,0,247,71,152,127,239,216,177,67,62,248,224,3,249,242,203,47,149,2,136,221,77,236,56,226,94,13,191,100,60,110,188,241,
70,199,239,143,48,201,253,228,147,79,100,219,182,109,178,118,237,90,249,234,171,175,228,186,235,174,83,10,231,131,15,62,168,204,207,177,51,130,69,203,114,229,202,73,181,106,213,12,249,76,199,231,213,53,
62,106,152,57,174,94,189,90,58,116,232,96,252,36,150,36,1,155,8,32,134,1,54,31,239,189,247,94,75,53,154,86,60,177,211,132,252,137,85,170,84,177,212,32,79,34,1,171,4,222,125,247,93,181,138,106,245,203,
110,181,93,191,156,7,19,42,4,5,251,232,163,143,212,46,101,211,166,77,213,14,231,228,201,147,213,228,1,43,216,88,161,174,87,175,158,10,172,130,213,107,55,8,204,124,15,29,58,164,204,197,160,140,98,7,22,
38,99,88,136,192,238,40,86,215,175,186,234,42,165,152,194,247,0,99,128,82,10,69,218,200,14,108,44,198,8,83,53,40,242,152,56,226,57,210,107,124,142,7,174,21,198,7,193,115,240,129,227,144,224,115,240,120,
240,25,159,5,149,241,224,115,164,99,56,14,73,169,92,240,243,224,115,232,57,161,199,84,101,6,234,211,43,103,246,24,202,167,212,118,74,117,130,25,196,234,115,176,125,43,207,193,54,131,125,12,237,71,172,
143,5,219,14,239,83,114,239,131,159,5,159,131,117,132,62,135,190,14,45,135,227,144,208,99,193,215,193,231,208,207,193,23,102,160,161,156,241,90,239,129,243,112,28,59,108,216,121,131,213,70,240,57,185,
215,193,186,113,126,106,9,220,21,96,89,130,224,29,80,40,113,207,131,69,72,184,31,38,92,17,96,97,130,124,234,216,121,40,89,178,164,218,205,116,122,81,208,8,23,92,191,131,7,15,202,154,53,107,84,160,45,252,
167,192,244,182,122,245,234,106,167,21,10,51,202,224,253,61,247,220,147,112,77,141,212,205,50,137,9,188,242,202,43,106,242,143,239,55,133,4,98,73,0,25,37,218,182,109,43,143,60,242,136,165,102,77,43,158,
176,225,95,188,120,177,154,220,89,106,145,39,145,128,69,2,47,191,252,178,140,28,57,210,226,217,241,123,26,38,46,179,102,205,82,147,25,220,48,238,190,251,110,25,55,110,156,250,29,99,98,128,69,164,86,90,
120,108,76,4,48,193,243,138,96,181,29,147,180,96,142,197,160,249,46,76,194,160,172,226,1,5,13,190,72,48,73,194,3,147,54,76,50,131,19,217,224,51,198,140,178,120,4,253,81,195,159,35,125,158,210,57,161,254,
81,193,182,209,110,176,237,224,235,224,51,202,4,39,194,122,207,161,199,244,202,134,78,222,131,215,50,210,177,72,199,131,231,5,159,141,150,67,121,51,101,131,245,27,121,214,171,215,200,121,86,202,4,25,91,
57,55,150,253,68,255,162,233,107,112,124,122,117,68,115,44,82,191,130,117,6,159,131,237,71,42,31,252,60,200,20,191,53,72,240,125,114,207,193,223,43,202,4,95,227,57,252,61,234,11,254,246,130,62,143,193,
103,28,15,190,14,125,70,255,67,223,135,150,11,125,29,44,19,108,51,244,25,247,133,160,207,60,238,85,216,21,132,114,140,251,20,22,212,176,99,9,179,88,60,99,17,13,15,184,53,160,140,87,4,174,27,203,150,45,
147,105,211,166,201,169,83,167,148,18,250,244,211,79,171,197,0,184,113,32,45,200,163,143,62,170,20,105,175,140,201,45,253,132,123,10,30,143,63,254,184,91,186,196,126,196,9,129,198,141,27,43,235,133,246,
237,219,91,26,177,105,197,179,72,145,34,202,143,32,152,48,219,82,171,60,137,4,76,18,64,36,101,252,73,215,173,91,215,228,153,241,91,28,230,180,248,195,199,14,26,76,227,49,161,65,64,130,13,154,249,42,34,
21,118,235,214,77,176,235,233,231,96,62,248,206,32,168,6,204,117,241,140,104,188,152,240,5,31,152,136,226,53,4,43,199,216,53,8,127,214,59,22,94,38,252,189,222,57,241,251,77,228,200,73,192,189,4,160,12,
98,183,17,247,73,51,207,102,202,134,42,182,80,70,241,192,61,3,243,168,92,185,114,41,5,12,238,4,110,216,181,116,234,74,97,55,23,89,17,38,77,154,164,254,127,160,112,98,215,100,254,252,249,202,92,184,81,
163,70,202,165,195,169,246,253,88,47,92,143,144,219,19,223,47,10,9,196,138,0,230,147,55,223,124,179,244,238,221,219,82,147,166,20,79,76,208,160,120,194,199,0,55,78,10,9,196,138,0,20,166,17,35,70,216,178,
186,31,171,62,167,86,59,48,211,66,202,25,152,159,62,249,228,147,42,237,73,167,78,157,148,31,78,249,242,229,85,14,176,138,21,43,166,86,247,216,46,9,144,0,9,144,64,156,18,128,130,191,112,225,66,101,38,138,
29,81,228,189,237,223,191,191,172,88,177,66,249,174,54,108,216,80,237,166,196,41,30,83,195,222,180,105,147,192,191,23,12,41,36,16,43,2,48,243,70,48,72,184,105,89,17,83,138,231,143,63,254,40,85,52,179,
60,248,30,44,181,224,195,0,0,64,0,73,68,65,84,80,72,32,86,4,144,214,3,193,110,16,212,138,18,153,0,118,56,177,162,140,8,131,48,103,194,14,223,11,47,188,160,252,55,17,232,1,105,104,224,111,67,33,1,18,32,
1,18,32,129,212,38,128,120,3,216,53,129,187,68,253,250,245,101,208,160,65,178,106,213,42,129,66,133,255,48,4,147,163,36,79,128,46,72,201,243,225,167,246,19,120,227,141,55,212,239,116,249,242,229,150,42,
55,165,120,34,218,36,236,201,17,197,140,66,2,177,34,0,147,80,252,33,249,217,12,41,26,150,240,117,28,63,126,188,170,2,81,238,144,163,13,10,39,34,13,194,124,9,171,83,240,165,161,144,0,9,144,0,9,144,128,
219,8,32,149,87,247,238,221,149,31,40,220,63,240,26,86,59,136,79,0,197,10,110,34,20,125,2,136,78,143,72,194,12,186,168,207,135,71,237,39,128,197,161,62,125,250,8,130,61,90,17,83,138,39,210,44,244,236,
217,83,54,110,220,104,165,45,158,67,2,166,9,192,172,27,171,162,88,253,164,36,38,0,223,36,228,53,69,114,112,152,210,34,186,43,148,116,132,89,71,16,33,172,36,195,111,136,66,2,36,64,2,36,64,2,110,39,176,
103,207,30,21,135,0,65,239,158,125,246,89,169,83,167,142,140,26,53,74,153,146,194,218,142,146,148,0,226,20,224,127,31,174,72,20,18,136,5,129,221,187,119,203,19,79,60,161,230,158,86,218,51,165,120,34,157,
197,196,137,19,213,196,214,74,99,60,135,4,204,18,232,213,171,151,90,236,64,174,73,202,127,4,160,144,99,151,179,89,179,102,42,74,45,94,79,153,50,69,16,117,26,127,64,136,128,72,33,1,18,32,1,18,32,1,175,
17,64,196,219,224,78,39,130,231,156,60,121,82,229,119,238,218,181,171,138,93,224,181,241,56,221,223,153,51,103,170,244,58,52,77,118,154,52,235,7,1,196,17,169,85,171,150,124,246,217,103,150,128,152,82,
60,167,79,159,174,28,192,145,100,158,66,2,78,19,64,20,188,121,243,230,169,63,32,167,219,242,74,253,216,229,132,31,39,194,239,195,156,22,230,239,120,254,235,175,191,84,138,20,228,217,165,144,0,9,144,0,
9,144,128,151,9,4,45,122,134,12,25,34,8,134,7,165,115,194,132,9,210,164,73,19,245,222,203,99,179,187,239,200,11,221,183,111,95,25,60,120,176,221,85,179,62,18,72,66,0,238,92,165,75,151,150,19,39,78,36,
249,204,200,1,83,138,231,107,175,189,38,216,98,133,50,64,33,1,167,9,12,28,56,80,224,179,8,255,5,138,168,144,243,3,6,12,80,126,214,183,221,118,155,218,9,134,173,253,75,47,189,36,173,180,60,156,122,185,
241,200,141,4,72,128,4,72,128,4,188,74,0,49,12,16,167,0,254,100,240,253,68,20,215,159,126,250,73,253,239,49,238,195,127,87,117,204,152,49,130,136,192,5,10,20,248,239,32,95,145,128,67,4,10,22,44,168,54,
62,172,228,21,54,165,120,34,42,38,108,239,173,134,208,117,104,252,172,214,135,4,126,249,229,23,193,141,212,106,158,32,191,33,217,191,127,191,192,226,0,97,231,17,1,16,254,47,80,200,241,91,68,30,56,10,9,
144,0,9,144,0,9,248,149,0,20,79,252,239,97,209,181,99,199,142,234,255,16,10,41,221,74,254,119,197,17,136,105,244,232,209,156,51,249,245,7,224,178,113,193,173,107,253,250,245,150,2,87,154,82,60,145,236,
55,79,158,60,42,194,168,203,24,176,59,62,35,128,27,232,35,143,60,194,213,59,237,186,174,89,179,70,182,111,223,46,240,119,133,143,53,66,89,35,175,41,156,187,41,36,64,2,36,64,2,36,16,15,4,46,94,188,40,207,
63,255,188,10,106,130,133,105,196,29,169,86,173,154,84,175,94,61,30,134,159,226,24,97,37,6,165,28,41,213,40,36,224,36,129,50,101,202,40,235,215,91,111,189,213,116,51,166,20,79,36,169,197,15,252,185,231,
158,51,221,16,79,32,1,163,4,232,175,240,31,169,5,11,22,200,207,63,255,44,237,218,181,83,145,125,97,234,142,99,86,126,236,255,213,202,87,36,64,2,36,64,2,36,224,77,2,139,22,45,82,233,28,224,247,9,23,19,
236,246,113,94,42,242,237,183,223,202,219,111,191,173,204,144,189,121,101,217,107,175,16,168,84,169,146,138,56,93,190,124,121,211,93,54,165,120,34,79,16,126,220,141,27,55,54,221,16,79,32,1,163,4,16,161,
173,108,217,178,82,178,100,73,163,167,248,178,28,118,55,179,101,203,166,82,163,52,104,208,64,141,113,233,210,165,114,245,213,87,251,114,188,28,20,9,144,0,9,144,0,9,24,33,128,52,98,152,139,98,67,228,225,
135,31,22,252,55,194,21,37,67,134,12,70,78,247,109,25,184,196,33,199,98,188,115,240,237,5,118,201,192,238,191,255,126,229,123,93,163,70,13,211,61,50,165,120,222,126,251,237,202,239,238,190,251,238,51,
221,16,79,32,1,35,4,16,201,14,171,152,241,158,147,10,227,135,47,11,126,115,181,107,215,150,34,69,138,168,156,157,12,166,96,228,91,196,50,36,64,2,36,64,2,126,39,128,29,190,154,53,107,170,255,74,68,191,
69,0,76,40,159,88,176,141,87,57,120,240,160,236,218,181,75,5,28,140,87,6,28,183,243,4,144,43,190,77,155,54,210,168,81,35,211,141,153,82,60,177,3,53,103,206,28,53,25,54,221,18,79,32,1,3,4,222,127,255,125,
201,156,57,179,84,173,90,213,64,105,255,21,129,226,13,63,13,140,255,250,235,175,87,74,39,18,103,35,136,16,163,214,250,239,122,115,68,36,64,2,36,64,2,214,9,32,224,37,252,60,115,231,206,173,124,206,250,
245,235,167,118,98,226,57,232,80,151,46,93,226,126,241,222,250,55,138,103,26,33,0,43,131,122,245,234,41,229,211,72,249,208,50,166,20,207,162,69,139,202,202,149,43,229,150,91,110,9,173,131,175,73,192,54,
2,8,154,131,85,203,120,20,40,157,48,145,193,143,57,99,198,140,82,183,110,93,21,96,105,212,168,81,241,136,131,99,38,1,18,32,1,18,32,129,20,9,32,10,62,22,104,97,94,138,20,99,80,62,17,132,40,94,231,170,235,
214,173,147,124,249,242,9,230,236,20,18,112,130,64,211,166,77,85,62,221,78,157,58,153,174,222,148,226,89,184,112,97,217,186,117,171,228,204,153,211,116,67,60,129,4,82,34,0,243,144,227,199,143,75,179,102,
205,82,42,234,187,207,161,116,34,117,12,86,145,32,80,62,31,123,236,49,25,54,108,152,239,198,202,1,145,0,9,144,0,9,144,128,157,4,144,239,19,150,66,151,47,95,150,143,62,250,72,153,220,34,194,107,188,42,
159,175,190,250,170,32,239,55,133,4,156,32,240,248,227,143,43,23,48,100,91,48,43,166,20,79,252,128,15,29,58,36,153,50,101,50,219,14,203,147,64,138,4,144,147,11,102,166,241,232,199,136,157,78,4,73,128,
96,167,19,169,82,134,14,29,154,34,51,22,32,1,18,32,1,18,32,1,18,16,249,237,183,223,212,206,231,165,75,151,100,227,198,141,210,183,111,95,149,122,44,30,205,110,177,104,13,31,60,110,20,241,151,225,4,129,
14,29,58,40,203,188,145,35,71,154,174,222,176,226,137,85,36,236,120,158,60,121,210,116,35,60,129,4,82,34,240,197,23,95,200,138,21,43,84,14,170,148,202,250,237,243,65,131,6,9,34,131,193,183,21,207,45,90,
180,136,91,115,99,191,93,91,142,135,4,72,128,4,72,32,118,4,160,124,86,174,92,89,53,136,157,79,236,200,96,231,239,186,235,174,139,93,39,92,208,210,143,63,254,40,51,102,204,80,193,26,93,208,29,118,193,103,
4,122,246,236,41,103,206,156,145,105,211,166,153,30,153,97,197,19,121,146,202,149,43,39,71,143,30,53,221,8,79,32,129,148,8,192,39,227,165,151,94,138,187,84,33,240,223,188,243,206,59,165,64,129,2,130,116,
69,216,245,156,48,97,66,74,184,248,57,9,144,0,9,144,0,9,144,128,14,1,204,87,43,86,172,168,230,19,203,151,47,87,59,159,136,29,129,216,9,241,36,80,186,241,136,183,113,199,211,53,78,173,177,226,247,180,125,
251,118,89,188,120,177,233,46,24,86,60,79,159,62,173,118,99,16,170,153,66,2,118,18,64,96,128,177,99,199,10,124,18,226,73,166,79,159,46,185,114,229,146,10,21,42,8,146,240,222,115,207,61,50,107,214,44,70,
175,141,167,47,1,199,74,2,36,64,2,36,96,59,129,159,126,250,73,238,186,235,46,101,169,55,101,202,20,149,236,30,105,202,210,166,77,107,123,91,110,173,240,200,145,35,42,46,75,219,182,109,221,218,69,246,203,
163,4,166,78,157,42,139,22,45,146,15,62,248,192,244,8,12,43,158,8,250,130,100,189,123,246,236,49,221,8,79,32,129,228,8,140,30,61,90,229,2,138,39,63,140,101,203,150,9,20,110,252,166,240,231,136,29,207,
247,222,123,79,210,165,75,151,28,42,126,70,2,36,64,2,36,64,2,36,96,128,192,119,223,125,39,119,223,125,183,202,245,137,40,183,248,143,181,18,12,197,64,83,174,45,130,212,42,195,135,15,231,130,182,107,175,
144,55,59,246,206,59,239,168,197,156,143,63,254,216,244,0,12,43,158,7,14,28,16,172,154,236,220,185,211,116,35,60,129,4,34,17,64,16,0,68,115,69,242,231,120,17,252,134,54,111,222,172,76,139,107,215,174,
45,48,11,218,176,97,131,10,5,31,47,12,56,78,18,32,1,18,32,1,18,112,154,192,177,99,199,84,180,219,151,95,126,89,138,23,47,46,80,70,91,183,110,237,116,179,174,169,127,237,218,181,242,207,63,255,168,156,
224,174,233,20,59,226,121,2,235,215,175,23,252,166,172,108,70,26,86,60,119,236,216,161,38,202,91,182,108,241,60,48,14,192,61,4,230,207,159,175,66,50,151,41,83,198,61,157,114,176,39,95,126,249,165,188,
241,198,27,42,77,10,124,90,97,166,128,20,69,89,179,102,117,176,85,86,77,2,36,64,2,36,64,2,241,73,0,139,189,176,46,154,61,123,182,138,83,130,64,153,72,189,18,15,130,84,109,93,187,118,21,152,25,83,72,192,
46,2,208,9,219,181,107,39,216,148,52,43,134,21,79,132,166,198,206,20,158,41,36,96,23,129,206,157,59,199,77,4,215,223,127,255,93,186,117,235,38,175,191,254,122,130,201,15,18,61,199,147,137,177,93,223,27,
214,67,2,36,64,2,36,64,2,70,9,188,251,238,187,202,204,22,255,185,227,199,143,87,187,158,241,146,227,19,209,109,17,71,162,68,137,18,70,113,177,28,9,36,75,96,255,254,253,210,188,121,115,149,98,51,217,130,
58,31,26,86,60,177,51,3,59,113,252,104,41,36,96,7,1,216,134,159,61,123,86,26,52,104,96,71,117,174,174,3,171,142,80,178,161,120,158,59,119,78,154,52,105,34,51,103,206,84,17,109,93,221,113,118,142,4,72,
128,4,72,128,4,124,64,0,187,126,171,86,173,18,68,186,197,127,49,114,93,102,201,146,197,7,35,75,126,8,23,47,94,84,57,210,145,39,157,66,2,118,16,248,252,243,207,85,22,6,4,176,50,43,134,21,79,56,101,195,
68,208,74,4,35,179,157,98,249,248,32,128,27,63,124,59,227,33,202,28,162,246,34,188,123,209,162,69,149,175,197,139,47,190,40,143,60,242,72,124,92,104,142,146,4,72,128,4,72,128,4,92,64,224,137,39,158,144,
43,175,188,82,41,98,80,68,145,22,34,30,4,74,54,226,180,228,200,145,35,30,134,203,49,58,76,0,110,99,53,107,214,180,148,98,211,176,226,185,112,225,66,181,67,179,114,229,74,135,135,195,234,227,129,192,169,
83,167,4,223,165,14,29,58,248,126,184,155,54,109,18,68,133,110,211,166,141,50,77,128,121,207,160,65,131,124,63,110,14,144,4,72,128,4,72,128,4,220,68,224,239,191,255,86,19,230,102,205,154,73,233,210,165,
101,239,222,189,210,190,125,123,55,117,209,145,190,124,255,253,247,242,214,91,111,41,203,43,71,26,96,165,113,69,224,204,153,51,82,185,114,101,65,240,46,179,98,88,241,196,23,22,202,39,76,20,40,36,16,45,
129,126,253,250,169,96,85,87,95,125,117,180,85,185,250,124,152,18,195,68,61,248,128,121,49,124,77,226,97,151,215,213,23,134,157,35,1,18,32,1,18,136,75,2,200,75,255,208,67,15,201,196,137,19,5,65,82,238,
184,227,14,149,79,219,239,48,122,244,232,33,152,123,93,113,197,21,126,31,42,199,231,48,129,243,231,207,75,217,178,101,229,196,137,19,166,91,50,172,120,78,155,54,77,41,157,152,52,83,72,32,26,2,23,46,92,
80,249,127,16,172,202,207,2,191,78,68,174,197,141,126,223,190,125,202,167,4,187,188,215,94,123,173,159,135,205,177,145,0,9,144,0,9,144,128,171,9,32,165,25,230,32,200,169,221,167,79,31,121,245,213,87,229,
186,235,174,115,117,159,163,237,28,82,95,192,39,239,209,71,31,141,182,42,158,31,231,4,16,44,179,100,201,146,2,235,69,179,98,88,241,196,202,208,154,53,107,4,73,67,41,36,16,13,129,9,19,38,200,3,15,60,32,
55,223,124,115,52,213,184,254,220,233,211,167,75,177,98,197,84,238,176,250,245,235,171,104,182,241,146,54,198,245,23,135,29,36,1,18,32,1,18,136,107,2,131,7,15,86,166,130,136,52,143,192,59,35,71,142,244,
61,143,46,93,186,48,181,138,239,175,178,243,3,188,116,233,146,32,45,209,23,95,124,97,186,49,195,138,231,184,113,227,84,210,123,152,219,82,72,192,42,129,127,255,253,87,186,119,239,174,162,201,89,173,195,
11,231,225,199,136,28,165,24,107,203,150,45,85,244,90,4,20,162,144,0,9,144,0,9,144,0,9,164,62,1,88,37,213,171,87,79,153,221,98,145,24,254,106,173,91,183,78,253,142,57,216,3,108,30,229,203,151,47,46,76,
139,29,196,24,247,85,227,183,131,205,35,71,21,79,172,8,33,9,239,130,5,11,226,30,56,1,88,39,176,98,197,10,129,95,231,125,247,221,103,189,18,151,159,137,31,36,148,76,68,145,67,254,44,152,215,34,42,116,154,
52,105,92,222,115,118,143,4,72,128,4,72,128,4,226,135,0,130,238,32,165,219,236,217,179,101,241,226,197,42,213,89,193,130,5,125,11,224,159,127,254,81,102,197,200,40,64,33,129,104,8,64,241,196,98,77,250,
244,233,77,85,99,120,199,19,193,81,16,253,107,222,188,121,166,26,96,97,18,8,37,16,15,102,30,240,135,134,237,123,206,156,57,149,47,5,148,206,220,185,115,135,98,224,107,18,32,1,18,32,1,18,32,1,23,16,128,
159,39,220,201,150,44,89,34,152,163,140,30,61,90,210,165,75,231,130,158,57,211,133,81,163,70,73,211,166,77,37,111,222,188,206,52,192,90,227,130,0,22,104,14,29,58,36,25,51,102,52,53,94,195,138,39,86,71,
208,192,156,57,115,76,53,192,194,36,16,36,112,248,240,97,21,65,206,207,166,44,200,109,52,119,238,92,121,229,149,87,148,9,79,171,86,173,164,113,227,198,65,4,124,38,1,18,32,1,18,32,1,18,112,25,129,199,31,
127,92,144,234,172,97,195,134,130,20,104,29,59,118,116,89,15,237,235,206,185,115,231,100,242,228,201,106,158,98,95,173,172,41,222,8,192,199,19,27,146,89,178,100,49,53,116,195,138,39,28,175,143,30,61,170,
242,0,153,106,129,133,73,224,255,9,32,130,28,194,121,155,93,29,241,10,64,152,216,190,240,194,11,42,117,10,130,20,236,222,189,91,153,238,120,165,255,236,39,9,144,0,9,144,0,9,196,35,129,159,127,254,89,238,
191,255,126,65,80,192,15,63,252,80,30,126,248,97,41,84,168,144,111,81,244,234,213,75,153,220,102,200,144,193,183,99,228,192,156,37,80,164,72,17,217,181,107,151,92,115,205,53,166,26,50,172,120,246,239,
223,95,142,31,63,174,236,224,77,181,192,194,36,160,17,64,232,229,215,94,123,77,133,45,247,43,16,252,97,149,40,81,66,178,101,203,38,141,26,53,82,127,94,52,177,245,235,213,230,184,72,128,4,72,128,4,252,
68,0,233,2,199,140,25,163,226,50,192,106,9,38,183,126,141,205,176,127,255,126,149,230,13,193,15,41,36,96,133,192,173,183,222,42,219,183,111,55,157,134,200,176,226,217,183,111,95,21,189,104,230,204,153,
86,250,199,115,226,156,0,148,178,138,21,43,74,209,162,69,125,73,226,219,111,191,85,43,165,88,69,172,89,179,166,82,60,159,126,250,105,95,142,149,131,34,1,18,32,1,18,32,1,63,18,168,91,183,174,148,45,91,
86,253,143,35,98,103,139,22,45,252,56,76,53,166,120,136,185,225,219,139,231,130,129,97,62,191,101,203,22,201,158,61,187,169,222,24,86,60,145,92,55,56,185,54,213,2,11,147,128,70,160,107,215,174,202,4,213,
175,48,94,122,233,37,149,7,108,202,148,41,202,199,19,171,64,105,211,166,245,235,112,57,46,18,32,1,18,32,1,18,240,29,1,196,105,192,226,49,204,109,39,77,154,164,230,46,215,94,123,173,239,198,137,1,33,138,
111,129,2,5,228,174,187,238,242,229,248,56,40,103,9,32,5,209,230,205,155,37,71,142,28,166,26,162,226,105,10,23,11,91,33,0,147,14,60,30,123,236,49,43,167,187,254,28,228,182,197,15,15,55,239,10,21,42,8,
162,218,150,47,95,222,245,253,102,7,73,128,4,72,128,4,72,128,4,18,19,128,229,18,230,44,248,47,127,227,141,55,124,235,34,132,212,42,136,189,49,120,240,224,196,0,248,142,4,12,16,128,226,137,64,92,200,224,
96,70,12,43,158,248,33,158,62,125,90,253,16,205,52,192,178,36,208,167,79,31,233,222,189,187,47,131,10,157,63,127,94,70,140,24,161,110,220,47,191,252,178,156,58,117,74,133,100,231,85,39,1,18,32,1,18,32,
1,18,240,30,1,196,164,40,83,166,140,138,105,130,224,41,85,170,84,145,226,197,139,123,111,32,6,122,140,216,27,136,232,155,43,87,46,3,165,89,132,4,254,35,224,184,226,73,83,219,255,96,243,149,113,2,127,254,
249,167,12,27,54,76,224,35,236,71,233,217,179,167,64,225,188,124,249,178,84,171,86,77,144,179,19,33,217,41,36,64,2,36,64,2,36,64,2,222,36,240,230,155,111,202,210,165,75,229,253,247,223,87,230,182,200,
125,233,71,249,254,251,239,85,182,138,206,157,59,251,113,120,28,147,131,4,28,87,60,177,29,255,245,215,95,203,140,25,51,28,28,6,171,246,27,129,217,179,103,203,157,119,222,41,37,75,150,244,219,208,148,109,
251,55,223,124,35,205,155,55,151,103,158,121,70,254,253,247,95,149,27,203,119,3,229,128,72,128,4,72,128,4,72,32,142,8,192,12,21,65,134,134,14,29,170,254,219,17,221,182,78,157,58,190,36,0,139,180,1,3,6,
72,250,244,233,125,57,62,14,202,25,2,142,251,120,50,170,173,51,23,206,239,181,118,235,214,77,237,120,250,109,156,151,46,93,18,68,132,67,184,117,4,221,122,224,129,7,228,131,15,62,144,60,121,242,248,109,
168,28,15,9,144,0,9,144,0,9,196,29,129,249,243,231,11,2,6,174,95,191,94,94,124,241,69,229,86,227,71,229,108,219,182,109,114,230,204,25,149,187,52,238,46,50,7,108,153,0,162,218,110,221,186,85,165,16,52,
83,137,97,31,79,230,241,52,131,149,101,65,224,200,145,35,178,99,199,14,105,213,170,149,239,128,64,225,68,216,245,194,133,11,75,187,118,237,228,170,171,174,82,74,168,239,6,202,1,145,0,9,144,0,9,144,64,
28,18,128,21,19,130,6,194,213,12,46,52,72,29,225,215,52,105,126,207,60,16,135,95,95,199,135,140,60,158,152,227,155,141,250,108,88,241,28,56,112,160,28,61,122,84,217,130,59,62,26,54,224,11,2,253,250,245,
19,248,13,100,201,146,197,23,227,9,14,2,225,214,23,44,88,32,216,205,197,110,39,20,80,132,94,167,115,126,144,16,159,73,128,4,72,128,4,72,192,251,4,16,181,126,242,228,201,178,118,237,90,165,128,98,78,147,
53,107,86,239,15,44,108,4,136,224,123,207,61,247,8,148,9,10,9,24,33,80,164,72,17,65,240,173,107,174,185,198,72,241,132,50,134,21,207,33,67,134,200,193,131,7,85,142,194,132,179,249,130,4,34,16,248,235,
175,191,84,94,75,248,13,248,77,240,199,131,113,101,202,148,73,249,118,94,113,197,21,50,110,220,56,191,13,147,227,33,1,18,32,1,18,32,129,184,38,16,220,245,196,127,254,29,119,220,33,83,167,78,21,4,21,244,
155,252,241,199,31,42,215,186,95,3,65,250,237,122,185,97,60,176,248,219,187,119,175,233,205,37,195,138,39,82,70,236,217,179,71,230,205,155,231,134,241,178,15,46,39,240,246,219,111,75,161,66,133,84,72,
114,151,119,213,84,247,224,199,249,247,223,127,75,189,122,245,228,236,217,179,82,163,70,13,21,245,46,111,222,188,166,234,97,97,18,32,1,18,32,1,18,32,1,247,19,152,53,107,150,192,223,115,245,234,213,50,
114,228,72,105,212,168,145,220,120,227,141,238,239,184,201,30,66,233,132,201,109,230,204,153,77,158,201,226,241,72,160,96,193,130,114,232,208,33,211,169,18,13,43,158,8,37,13,91,94,152,24,82,72,32,37,2,
126,12,42,4,133,243,149,87,94,145,215,95,127,93,13,31,193,133,126,248,225,7,193,159,18,133,4,72,128,4,72,128,4,72,192,127,4,16,76,16,17,110,97,114,91,170,84,41,65,204,19,68,187,245,155,192,157,14,126,
172,109,218,180,241,219,208,56,30,7,8,220,124,243,205,114,236,216,49,211,209,144,13,43,158,48,37,220,188,121,179,192,222,157,66,2,201,17,56,121,242,164,242,121,68,138,17,63,201,152,49,99,84,244,90,152,
23,32,63,41,252,33,96,1,64,159,8,63,93,101,142,133,4,72,128,4,72,128,4,18,19,192,130,51,148,178,119,222,121,71,102,206,156,41,165,75,151,86,166,183,137,75,121,255,29,22,215,253,168,84,123,255,202,184,
107,4,129,64,64,160,120,126,241,197,23,166,59,102,88,241,156,56,113,162,172,89,179,70,253,232,76,183,194,19,226,138,192,224,193,131,165,67,135,14,190,114,192,71,168,113,56,223,7,125,59,96,110,131,223,
3,76,111,40,36,64,2,36,64,2,36,64,2,254,37,112,225,194,5,169,80,161,130,172,90,181,74,242,229,203,167,2,39,194,18,208,111,2,11,174,114,229,202,73,241,226,197,253,54,52,142,199,70,2,176,0,196,166,203,169,
83,167,76,215,106,88,241,156,62,125,186,44,91,182,76,222,125,247,93,211,141,240,132,248,33,128,164,203,189,123,247,22,40,159,126,18,40,156,48,31,70,244,46,172,244,84,172,88,81,6,13,26,36,213,170,85,243,
211,48,57,22,18,32,1,18,32,1,18,32,1,29,2,29,59,118,84,49,30,96,114,187,98,197,10,185,242,202,43,165,102,205,154,58,37,189,123,232,247,223,127,87,238,68,72,33,67,33,129,72,4,126,251,237,55,185,237,182,
219,4,22,142,102,197,176,226,57,103,206,28,65,192,152,229,203,151,155,109,131,229,227,136,0,110,198,8,53,94,185,114,101,223,140,122,247,238,221,178,111,223,62,105,221,186,181,26,19,2,12,33,178,237,254,
253,251,37,77,154,52,190,25,39,7,66,2,36,64,2,36,64,2,36,160,79,224,196,137,19,82,191,126,125,149,66,2,81,237,95,124,241,69,21,108,40,109,218,180,250,39,120,244,104,175,94,189,4,129,134,210,167,79,239,
209,17,176,219,78,19,56,119,238,156,148,47,95,94,142,31,63,110,186,41,195,138,39,124,59,97,215,190,114,229,74,211,141,240,132,248,33,0,255,0,164,222,241,147,66,246,194,11,47,168,21,192,224,159,75,237,
218,181,85,84,91,152,19,83,72,128,4,72,128,4,72,128,4,226,131,64,213,170,85,213,255,255,75,47,189,36,219,182,109,19,228,245,110,214,172,153,175,6,15,95,214,159,126,250,73,41,217,190,26,24,7,99,27,1,184,
159,97,131,9,193,133,204,138,97,197,19,102,182,19,38,76,16,236,246,80,72,64,143,192,233,211,167,213,174,56,20,53,191,200,123,239,189,39,87,93,117,149,220,127,255,253,106,72,223,127,255,189,90,229,57,112,
224,128,233,164,185,126,97,194,113,144,0,9,144,0,9,144,64,60,18,192,92,24,110,54,200,242,0,129,245,19,22,219,145,207,219,47,2,119,162,238,221,187,51,200,144,95,46,168,3,227,64,80,161,90,181,106,9,34,33,
155,21,195,138,39,20,206,225,195,135,203,186,117,235,204,182,193,242,113,66,0,81,223,90,180,104,33,185,115,231,246,197,136,17,66,29,59,184,8,36,20,20,236,114,194,196,0,57,189,40,36,64,2,36,64,2,36,64,
2,241,67,0,113,44,16,205,19,139,210,119,222,121,167,202,99,184,117,235,86,121,242,201,39,125,5,1,243,158,150,45,91,74,174,92,185,124,53,46,14,198,30,2,80,56,27,52,104,32,71,142,28,49,93,161,97,197,115,
211,166,77,2,103,227,141,27,55,154,110,132,39,248,159,128,31,87,200,16,64,160,82,165,74,82,162,68,137,132,11,136,40,94,8,180,133,227,20,18,32,1,18,32,1,18,32,129,248,34,128,28,222,48,49,12,6,219,196,238,
32,130,42,194,239,211,47,242,237,183,223,170,44,22,207,63,255,188,95,134,196,113,216,72,0,113,79,30,125,244,81,181,240,98,182,90,195,138,231,206,157,59,5,38,148,88,217,161,144,64,56,1,44,72,32,26,218,
3,15,60,16,254,145,39,223,35,98,23,204,103,96,82,19,20,4,78,106,223,190,189,124,245,213,87,190,242,97,13,142,143,207,36,64,2,36,64,2,36,64,2,201,19,248,252,243,207,5,190,158,48,55,132,137,45,82,74,192,
4,183,83,167,78,201,159,232,177,79,153,211,211,99,23,44,134,221,221,190,125,187,218,229,135,219,153,89,49,172,120,30,60,120,80,218,180,105,35,80,64,41,36,16,78,160,71,143,30,50,96,192,0,73,151,46,93,248,
71,158,124,63,98,196,8,105,222,188,185,228,207,159,63,161,255,85,170,84,81,54,237,88,221,164,144,0,9,144,0,9,144,0,9,196,39,1,152,217,98,199,7,62,158,16,236,120,226,53,82,174,249,69,22,45,90,36,183,220,
114,139,148,41,83,198,47,67,226,56,108,34,128,60,246,72,49,136,172,15,102,197,176,226,137,48,210,141,26,53,146,61,123,246,152,109,131,229,125,78,224,151,95,126,81,129,167,160,124,250,65,206,158,61,43,
19,39,78,20,132,20,15,202,249,243,231,165,112,225,194,114,248,240,97,250,60,4,161,240,153,4,72,128,4,72,128,4,226,144,192,220,185,115,229,181,215,94,75,152,19,127,247,221,119,130,99,48,195,245,139,252,
245,215,95,42,39,123,191,126,253,252,50,36,142,195,38,2,139,23,47,150,49,99,198,200,230,205,155,77,215,104,88,241,68,232,220,234,213,171,11,118,62,41,36,16,74,96,210,164,73,82,163,70,13,181,50,22,122,
220,171,175,177,115,251,236,179,207,74,246,236,217,19,134,128,196,209,95,127,253,181,10,40,144,112,144,47,72,128,4,72,128,4,72,128,4,226,142,0,148,178,2,5,10,168,128,155,165,74,149,82,227,239,223,191,
191,60,247,220,115,114,221,117,215,249,134,71,159,62,125,4,155,10,25,50,100,240,205,152,56,144,232,9,32,6,202,146,37,75,100,245,234,213,166,43,51,172,120,94,184,112,65,202,150,45,107,41,116,174,233,94,
241,4,79,17,192,118,251,176,97,195,60,213,231,72,157,213,91,181,68,224,164,226,197,139,11,126,104,200,91,68,33,1,18,32,1,18,32,1,18,136,111,2,200,229,9,63,79,76,192,33,63,252,240,131,76,155,54,77,165,
34,241,11,153,79,63,253,84,96,241,216,164,73,19,191,12,137,227,176,129,0,178,156,124,242,201,39,2,115,108,179,98,88,241,188,124,249,178,50,53,196,23,48,77,154,52,102,219,97,121,159,18,216,191,127,191,
192,185,24,105,84,252,32,122,126,26,75,151,46,85,127,36,159,125,246,153,31,134,200,49,144,0,9,144,0,9,144,0,9,68,73,224,203,47,191,148,106,213,170,9,230,65,89,178,100,81,181,33,32,225,211,79,63,45,57,
114,228,136,178,118,247,156,206,32,67,238,185,22,110,233,9,98,157,252,248,227,143,50,117,234,84,211,93,50,172,120,162,230,130,5,11,42,37,35,115,230,204,166,27,226,9,254,36,208,183,111,95,229,96,236,135,
48,226,136,86,251,206,59,239,200,139,47,190,152,232,98,193,140,184,113,227,198,242,212,83,79,37,58,206,55,36,64,2,36,64,2,36,64,2,241,75,160,102,205,154,114,255,253,247,171,121,16,40,32,70,4,220,143,122,
246,236,233,27,40,99,199,142,85,49,94,242,230,205,235,155,49,113,32,209,17,128,59,26,22,91,16,136,211,172,152,82,60,139,20,41,162,28,73,115,231,206,109,182,29,150,247,33,1,248,56,96,117,15,126,13,126,
16,228,169,133,217,240,85,87,93,149,48,28,152,222,222,123,239,189,178,119,239,222,68,199,19,10,240,5,9,144,0,9,144,0,9,144,64,92,18,128,143,27,230,64,161,169,6,7,15,30,172,22,170,253,178,235,9,19,226,
57,115,230,8,76,139,41,36,0,2,45,91,182,148,162,69,139,90,90,96,49,165,120,22,43,86,76,150,47,95,46,133,10,21,34,121,18,80,182,221,126,9,181,29,105,183,19,201,147,145,211,115,250,244,233,188,226,36,64,
2,36,64,2,36,64,2,36,144,64,224,223,127,255,21,204,141,161,152,149,43,87,78,29,247,227,174,39,205,109,19,46,57,95,104,4,154,54,109,42,149,42,85,18,204,145,205,138,41,197,179,100,201,146,242,214,91,111,
201,29,119,220,97,182,29,150,247,33,1,63,5,21,130,111,103,215,174,93,19,237,106,194,175,25,249,171,102,206,156,41,183,223,126,187,15,175,32,135,68,2,36,64,2,36,64,2,36,16,13,1,236,120,34,227,195,194,133,
11,19,170,129,53,216,51,207,60,147,40,58,126,194,135,30,124,241,238,187,239,74,158,60,121,164,66,133,10,30,236,61,187,108,55,129,6,13,26,8,30,173,90,181,50,93,181,41,197,19,9,115,95,127,253,117,169,82,
165,138,233,134,120,130,191,8,4,83,139,32,205,136,215,229,155,111,190,81,127,24,225,102,36,240,247,196,159,135,149,4,185,94,103,194,254,147,0,9,144,0,9,144,0,9,164,76,224,244,233,211,42,200,16,162,124,
6,93,117,130,129,87,16,132,197,15,114,233,210,37,101,82,140,116,115,20,18,168,83,167,142,60,249,228,147,210,176,97,67,211,48,76,41,158,80,56,177,130,211,172,89,51,211,13,241,4,127,17,128,67,113,235,214,
173,125,17,185,13,121,170,58,119,238,44,87,95,125,117,162,139,84,187,118,109,229,80,223,174,93,187,68,199,249,134,4,72,128,4,72,128,4,72,128,4,130,4,48,17,175,90,181,170,178,156,10,30,243,91,94,207,126,
253,250,169,241,249,33,152,100,240,26,241,217,26,1,68,115,70,126,215,234,213,171,155,174,192,148,226,249,240,195,15,171,221,206,78,157,58,153,110,136,39,248,135,0,242,90,226,11,55,100,200,16,207,15,74,
47,111,39,6,133,227,88,104,217,179,103,79,66,152,116,207,15,150,3,32,1,18,32,1,18,32,1,18,176,157,0,130,12,13,28,56,80,62,254,248,227,132,186,207,156,57,163,220,211,186,116,233,146,112,204,203,47,246,
237,219,39,135,15,31,150,230,205,155,123,121,24,236,187,13,4,224,223,57,122,244,232,4,191,102,51,85,154,82,60,177,173,154,51,103,78,65,196,46,74,252,18,216,176,97,131,252,249,231,159,130,21,62,175,11,
86,240,94,120,225,5,201,154,53,107,162,161,224,216,175,191,254,202,160,66,137,168,240,13,9,144,0,9,144,0,9,144,64,56,1,4,25,42,81,162,132,10,50,132,216,16,65,137,100,81,21,252,220,107,207,12,50,228,181,
43,230,76,127,241,29,95,176,96,129,20,46,92,216,116,3,166,20,79,228,37,66,88,229,41,83,166,152,110,136,39,248,135,0,190,7,48,33,73,151,46,157,167,7,133,239,50,162,213,226,70,26,42,248,3,41,91,182,172,
76,155,54,141,129,180,66,193,240,53,9,144,0,9,144,0,9,144,128,46,1,228,53,63,122,244,168,204,159,63,63,225,115,68,204,95,186,116,169,248,197,82,112,252,248,241,42,168,76,254,252,249,19,198,200,23,241,
71,0,139,44,216,132,194,102,164,89,49,165,120,34,176,208,174,93,187,100,222,188,121,102,219,97,121,159,16,192,46,224,184,113,227,44,229,238,113,27,2,152,197,32,9,110,182,108,217,18,117,13,209,219,240,
25,190,235,20,18,32,1,18,32,1,18,32,1,18,72,137,0,92,116,106,212,168,33,59,119,238,76,228,162,131,197,122,228,9,207,152,49,99,74,85,184,254,115,4,77,154,53,107,150,138,139,225,250,206,178,131,142,16,128,
187,29,118,58,143,28,57,34,87,92,113,133,233,54,76,41,158,51,102,204,144,101,203,150,169,213,27,211,45,241,4,95,16,192,46,224,189,247,222,107,105,123,221,77,0,206,157,59,39,111,190,249,166,174,2,93,183,
110,93,121,232,161,135,84,2,104,55,245,153,125,33,1,18,32,1,18,32,1,18,112,47,129,90,181,106,9,30,161,81,242,177,11,186,113,227,70,223,204,41,104,110,235,222,239,95,44,122,134,13,40,100,57,57,126,252,
184,165,230,76,41,158,239,189,247,158,76,156,56,81,86,173,90,101,169,49,158,228,125,2,126,185,225,12,27,54,76,69,229,205,149,43,87,162,139,130,176,232,136,76,135,221,206,96,88,244,68,5,248,134,4,72,128,
4,72,128,4,72,128,4,116,8,172,92,185,82,48,191,128,162,25,42,200,19,142,248,40,233,211,167,15,61,236,201,215,208,5,48,119,186,251,238,187,61,217,127,118,58,58,2,95,126,249,165,138,241,130,64,83,86,196,
148,226,185,121,243,102,101,46,0,187,94,74,252,17,192,170,221,214,173,91,149,194,230,229,209,99,181,6,102,227,240,199,8,23,68,159,251,254,251,239,101,246,236,217,225,31,241,61,9,144,0,9,144,0,9,144,0,
9,68,36,112,249,242,101,41,85,170,148,114,73,187,253,246,219,19,202,125,250,233,167,202,255,243,209,71,31,77,56,230,213,23,204,233,233,213,43,103,79,191,145,219,190,85,171,86,178,127,255,126,75,21,154,
82,60,161,221,162,49,216,175,83,226,143,0,252,30,225,32,31,158,239,210,107,36,160,116,54,105,210,68,194,157,227,17,84,232,174,187,238,82,38,184,8,46,68,33,1,18,32,1,18,32,1,18,32,1,51,4,224,207,249,197,
23,95,168,84,42,161,231,33,95,56,114,160,167,73,147,38,244,176,39,95,51,167,167,39,47,155,45,157,70,234,160,222,189,123,91,214,5,77,41,158,136,2,122,255,253,247,203,129,3,7,108,233,60,43,241,14,1,172,
226,225,139,54,104,208,32,239,116,90,167,167,127,252,241,135,50,119,129,18,29,46,48,145,233,213,171,151,96,53,135,66,2,36,64,2,36,64,2,36,64,2,102,9,124,253,245,215,242,192,3,15,200,142,29,59,36,115,230,
204,9,167,111,218,180,73,206,159,63,175,98,72,36,28,244,232,139,189,123,247,202,103,159,125,38,205,154,53,243,232,8,216,109,171,4,38,79,158,44,8,194,137,57,179,21,49,165,120,254,243,207,63,82,180,104,
81,249,252,243,207,37,109,218,180,86,218,227,57,30,37,0,191,94,220,64,239,187,239,62,143,142,224,127,221,126,227,141,55,148,227,127,193,130,5,147,140,163,126,253,250,82,187,118,109,21,233,54,201,135,60,
64,2,36,64,2,36,64,2,36,64,2,6,8,84,175,94,93,30,126,248,97,233,208,161,67,162,210,47,191,252,178,140,28,57,50,209,49,175,190,241,75,204,15,175,242,79,173,126,99,131,230,204,153,51,50,117,234,84,75,93,
48,165,120,162,133,91,111,189,85,249,249,101,207,158,221,82,131,60,201,155,4,186,119,239,174,118,10,189,108,34,242,247,223,127,171,93,219,161,67,135,38,185,8,8,17,142,104,189,219,183,111,151,172,89,179,
38,249,156,7,72,128,4,72,128,4,72,128,4,72,192,8,1,4,224,25,61,122,180,124,244,209,71,137,138,191,255,254,251,146,41,83,38,169,86,173,90,162,227,94,124,131,212,122,13,27,54,148,124,249,242,121,177,251,
236,179,69,2,109,219,182,85,174,106,48,183,182,34,166,21,79,56,77,47,94,188,88,41,160,86,26,228,57,222,35,128,212,35,88,217,64,84,54,47,11,210,1,149,43,87,78,74,150,44,153,100,24,200,179,117,226,196,9,
89,176,96,65,146,207,120,128,4,72,128,4,72,128,4,72,128,4,140,18,128,133,224,109,183,221,166,230,203,197,139,23,79,56,13,57,16,17,196,240,181,215,94,75,56,230,213,23,112,191,155,51,103,78,162,212,49,94,
29,11,251,109,156,64,211,166,77,213,70,77,248,110,190,209,26,76,43,158,200,221,50,102,204,24,169,92,185,178,209,54,88,206,227,4,144,239,18,254,10,55,222,120,163,103,71,2,31,85,152,133,192,177,63,92,240,
71,128,176,224,8,58,84,177,98,197,240,143,249,158,4,72,128,4,72,128,4,72,128,4,76,17,192,98,253,217,179,103,101,250,244,233,137,206,195,2,55,220,125,176,16,238,117,161,185,173,215,175,160,249,254,215,
171,87,79,30,127,252,113,105,220,184,177,249,147,181,51,76,43,158,53,106,212,80,13,182,108,217,210,82,131,60,201,123,4,252,112,99,89,180,104,145,20,40,80,64,42,84,168,144,228,2,172,95,191,94,173,216,193,
89,158,66,2,36,64,2,36,64,2,36,64,2,209,18,56,121,242,164,242,243,68,38,136,12,25,50,36,84,135,133,112,184,47,13,31,62,60,225,152,87,95,44,89,178,68,153,93,150,47,95,222,171,67,96,191,77,18,128,153,120,
159,62,125,44,199,124,49,173,120,182,110,221,90,237,124,233,229,64,52,217,119,22,247,0,129,67,135,14,169,40,175,94,95,104,72,206,161,255,145,71,30,145,74,149,42,209,92,196,3,223,71,118,145,4,72,128,4,
72,128,4,188,66,0,1,25,159,120,226,9,105,211,166,77,162,46,79,153,50,69,89,14,34,96,167,151,5,177,51,144,37,160,127,255,254,94,30,6,251,110,130,0,210,14,206,156,57,83,138,21,43,102,226,172,255,138,154,
86,60,161,229,126,251,237,183,150,163,25,253,215,52,95,121,129,0,110,38,80,218,178,100,201,226,133,238,234,246,241,195,15,63,20,152,211,214,170,85,43,201,231,8,109,14,165,115,243,230,205,194,128,89,73,
240,240,0,9,144,0,9,144,0,9,144,128,69,2,111,191,253,182,154,47,175,89,179,38,81,13,23,47,94,148,1,3,6,120,62,69,29,6,5,189,160,71,143,30,137,118,117,19,13,150,111,124,69,160,68,137,18,106,206,156,45,
91,54,75,227,50,173,120,78,156,56,81,69,233,194,143,137,226,111,2,112,142,199,206,182,94,206,75,47,141,28,138,51,28,249,245,34,242,98,108,159,126,250,169,44,93,186,212,75,67,98,95,73,128,4,72,128,4,72,
128,4,92,78,224,175,191,254,146,210,165,75,171,156,135,183,220,114,75,162,222,142,26,53,74,249,201,229,207,159,63,209,113,175,189,249,228,147,79,228,171,175,190,18,88,143,81,252,77,0,11,38,8,50,139,180,
154,122,115,106,35,163,55,173,120,34,105,40,76,4,16,18,154,226,111,2,184,198,215,92,115,141,167,3,73,193,183,226,212,169,83,130,40,92,122,130,221,78,172,58,250,33,180,185,222,248,120,140,4,72,128,4,72,
128,4,72,32,245,8,116,236,216,81,254,253,247,95,65,30,241,80,249,245,215,95,85,202,149,222,189,123,135,30,246,228,107,63,196,2,241,36,248,24,119,250,203,47,191,84,193,70,225,134,103,85,76,43,158,59,118,
236,80,105,53,54,110,220,104,181,77,158,231,17,2,126,200,221,137,168,114,67,134,12,145,116,233,210,37,161,142,239,50,252,46,14,30,60,104,121,229,38,73,165,60,64,2,36,64,2,36,64,2,36,64,2,255,79,224,240,
225,195,210,162,69,11,193,206,96,250,244,233,19,113,25,52,104,144,180,111,223,94,172,154,45,38,170,44,21,223,32,43,192,99,143,61,38,185,114,229,74,197,94,176,105,167,9,32,215,253,179,207,62,171,98,191,
88,109,203,180,226,137,237,244,6,13,26,68,213,168,213,206,242,188,216,17,128,239,227,228,201,147,165,91,183,110,177,107,212,230,150,96,10,128,228,205,79,63,253,180,110,205,205,155,55,23,216,170,247,234,
213,75,247,115,30,36,1,18,32,1,18,32,1,18,32,129,104,9,32,32,11,220,126,154,52,105,146,168,170,51,103,206,200,91,111,189,165,114,123,38,250,192,99,111,16,251,5,17,110,159,123,238,57,143,245,156,221,53,
67,96,254,252,249,202,234,21,217,32,172,138,105,197,19,17,172,96,223,123,228,200,17,73,155,54,173,213,118,121,158,203,9,192,151,183,118,237,218,114,211,77,55,185,188,167,145,187,7,133,178,103,207,158,
146,41,83,166,36,133,126,255,253,119,193,31,1,2,15,229,205,155,55,201,231,60,64,2,36,64,2,36,64,2,36,64,2,118,16,152,49,99,134,44,92,184,80,86,173,90,149,164,186,87,95,125,85,165,87,201,156,57,115,146,
207,188,116,128,230,182,94,186,90,214,250,138,184,47,48,183,197,247,217,170,152,86,60,209,80,241,226,197,213,78,82,238,220,185,173,182,203,243,92,78,192,235,55,16,172,34,206,153,51,71,58,119,238,172,75,
122,244,232,209,234,15,224,131,15,62,208,253,156,7,73,128,4,72,128,4,72,128,4,72,192,14,2,88,236,46,83,166,140,96,167,40,124,177,251,248,241,227,130,168,183,48,185,245,178,204,155,55,79,74,150,44,41,183,
221,118,155,151,135,193,190,39,67,0,238,105,8,146,21,141,165,160,37,197,243,206,59,239,84,225,161,241,76,241,31,129,207,62,251,76,96,199,221,170,85,43,207,14,46,37,191,9,228,214,130,82,90,175,94,61,207,
142,145,29,39,1,18,32,1,18,32,1,18,240,6,1,228,243,204,145,35,135,140,28,57,50,73,135,225,214,132,121,75,184,15,104,146,130,46,62,240,199,31,127,168,12,2,126,8,150,228,98,204,169,218,181,70,141,26,73,
221,186,117,165,117,235,214,150,251,97,73,241,196,164,189,83,167,78,210,176,97,67,203,13,243,68,247,18,192,205,239,249,231,159,151,171,175,190,218,189,157,76,166,103,23,46,92,80,55,118,152,4,232,9,162,
113,33,236,55,130,10,121,249,38,175,55,54,30,35,1,18,32,1,18,32,1,18,112,31,1,4,23,194,174,38,158,195,83,81,236,218,181,75,142,29,59,38,136,61,225,101,193,78,24,230,94,156,91,121,249,42,70,238,123,173,
90,181,148,175,114,205,154,53,35,23,74,225,19,75,138,39,34,87,193,220,22,9,99,41,254,34,128,144,223,184,113,12,30,60,216,179,3,27,55,110,156,218,201,140,228,159,138,149,154,156,57,115,202,240,225,195,
61,59,70,118,156,4,72,128,4,72,128,4,72,192,91,4,144,211,115,216,176,97,42,134,70,120,207,97,133,133,156,227,94,22,100,188,192,206,103,157,58,117,188,60,12,246,61,2,129,187,239,190,91,5,23,130,73,181,
85,177,164,120,98,27,253,187,239,190,83,230,182,86,27,230,121,238,36,176,118,237,90,213,177,234,213,171,187,179,131,41,244,234,159,127,254,81,138,243,208,161,67,117,75,34,56,22,252,44,144,143,182,96,193,
130,186,101,120,144,4,72,128,4,72,128,4,72,128,4,236,38,48,118,236,88,193,60,107,217,178,101,73,170,70,204,9,4,237,172,81,163,70,146,207,188,114,32,16,8,168,77,41,164,177,163,248,143,0,50,65,108,218,180,
73,178,103,207,110,121,112,150,20,79,68,60,197,15,103,241,226,197,150,27,230,137,238,36,128,93,236,129,3,7,122,54,98,49,156,219,111,189,245,86,165,92,234,17,70,36,174,169,83,167,202,150,45,91,244,62,230,
49,18,32,1,18,32,1,18,32,1,18,112,132,192,185,115,231,4,187,70,136,163,113,221,117,215,37,106,3,74,91,151,46,93,60,191,235,9,165,19,185,30,179,102,205,154,104,124,124,227,109,2,23,47,94,84,41,8,17,12,
43,220,84,220,204,200,44,41,158,216,45,130,242,185,122,245,106,51,109,177,172,203,9,192,55,18,171,113,72,65,226,85,73,201,84,5,59,185,48,181,69,50,103,10,9,144,0,9,144,0,9,144,0,9,196,146,64,131,6,13,
228,246,219,111,87,190,144,225,237,206,157,59,87,185,178,221,113,199,29,225,31,121,230,61,20,147,13,27,54,72,187,118,237,60,211,103,118,52,101,2,95,125,245,149,218,141,63,122,244,104,202,133,147,41,97,
73,241,196,74,13,18,225,114,215,40,25,178,30,252,104,214,172,89,82,190,124,121,41,86,172,152,7,123,47,42,76,249,159,127,254,169,34,110,233,13,0,63,154,106,213,170,201,129,3,7,116,115,123,234,157,195,99,
36,64,2,36,64,2,36,64,2,36,96,23,129,117,235,214,169,5,126,204,165,195,229,210,165,75,130,188,158,145,220,133,194,203,187,245,189,215,83,242,185,149,107,106,246,11,223,215,39,159,124,82,205,161,163,233,
135,37,197,19,201,67,235,215,175,47,251,246,237,139,166,109,158,235,50,2,94,191,81,192,68,5,1,131,34,153,0,116,232,208,65,254,250,235,47,250,38,187,236,123,199,238,144,0,9,144,0,9,144,64,188,16,64,16,
71,44,240,207,158,61,91,238,186,235,174,36,195,78,41,64,98,146,19,92,120,96,242,228,201,2,11,51,228,124,164,248,131,192,156,57,115,100,218,180,105,242,209,71,31,69,53,32,75,138,39,38,239,248,209,96,59,
29,142,208,20,239,19,192,110,224,138,21,43,148,93,190,23,71,115,228,200,17,217,186,117,171,180,109,219,86,183,251,184,209,35,239,44,124,60,189,108,194,162,59,56,30,36,1,18,32,1,18,32,1,18,240,12,1,164,
28,57,124,248,176,44,92,184,48,73,159,83,74,9,151,228,4,23,30,56,127,254,188,64,249,68,126,82,138,63,8,96,39,254,235,175,191,150,153,51,103,70,53,32,75,138,39,90,68,68,80,76,244,115,231,206,29,85,7,120,
178,59,8,32,132,119,171,86,173,84,114,99,119,244,200,92,47,144,2,6,143,140,25,51,234,158,136,8,114,248,124,255,254,253,186,159,243,32,9,144,0,9,144,0,9,144,0,9,196,130,192,55,223,124,163,118,4,247,236,
217,163,235,250,131,124,234,200,249,153,45,91,182,88,116,199,145,54,186,119,239,174,82,243,69,178,66,115,164,81,86,234,24,129,150,45,91,74,145,34,69,148,41,120,52,141,88,86,60,177,227,9,39,104,236,34,
81,188,79,192,203,102,182,63,254,248,163,76,159,62,61,217,149,181,7,30,120,64,240,232,216,177,163,247,47,22,71,64,2,36,64,2,36,64,2,36,224,105,2,85,170,84,145,134,13,27,202,243,207,63,159,100,28,167,79,
159,22,68,233,71,60,21,175,202,242,229,203,149,226,92,169,82,37,175,14,129,253,14,33,0,23,75,124,95,177,73,21,141,88,86,60,239,187,239,62,21,177,10,26,48,197,219,4,118,238,220,41,88,125,195,23,202,139,
2,191,78,252,16,114,229,202,165,219,125,132,47,47,87,174,156,236,218,181,43,73,248,114,221,19,120,144,4,72,128,4,72,128,4,72,128,4,28,36,240,206,59,239,200,232,209,163,101,243,230,205,186,173,32,195,64,
239,222,189,37,67,134,12,186,159,187,253,32,2,37,245,239,223,95,6,12,24,224,246,174,178,127,6,8,64,239,131,185,45,124,119,163,17,203,138,39,194,36,195,4,0,147,126,138,183,9,244,233,211,71,37,252,245,226,
205,13,254,198,184,177,193,44,37,146,224,230,125,232,208,33,65,26,32,10,9,144,0,9,144,0,9,144,0,9,164,54,129,191,255,254,91,229,29,255,240,195,15,165,112,225,194,73,186,131,121,11,54,6,144,2,206,171,2,
95,86,88,212,69,114,131,242,234,184,226,177,223,72,1,4,159,100,152,219,70,35,150,21,79,40,156,187,119,239,150,5,11,22,68,211,62,207,77,101,2,88,145,194,106,20,148,55,47,10,82,192,148,41,83,70,74,150,44,
25,177,251,101,203,150,85,11,36,72,165,66,33,1,18,32,1,18,32,1,18,32,1,55,16,64,180,125,164,129,131,187,144,158,164,20,173,95,239,28,55,29,251,244,211,79,229,228,201,147,210,184,113,99,55,117,139,125,
49,73,32,16,8,168,216,62,88,12,201,148,41,147,201,179,19,23,183,172,120,66,235,197,15,101,245,234,213,137,107,228,59,79,17,64,208,157,28,57,114,72,197,138,21,61,213,239,96,103,113,83,30,49,98,68,240,109,
146,103,228,29,106,209,162,133,28,59,118,140,17,152,147,208,225,1,18,32,1,18,32,1,18,32,129,212,34,112,240,224,65,105,210,164,137,202,141,152,46,93,186,36,221,88,191,126,189,92,188,120,81,197,168,72,242,
161,71,14,120,57,134,136,71,16,59,222,77,248,28,195,87,23,139,8,209,138,101,197,19,219,255,112,136,214,75,128,27,109,167,120,126,236,8,120,57,234,24,114,9,253,241,199,31,82,183,110,221,136,192,224,183,
90,170,84,41,233,215,175,95,196,50,252,128,4,72,128,4,72,128,4,72,128,4,82,131,64,233,210,165,149,187,83,211,166,77,117,155,239,220,185,179,32,243,128,87,101,228,200,145,242,248,227,143,75,206,156,57,
189,58,132,184,239,55,252,144,17,101,25,11,37,209,138,101,197,19,145,68,239,185,231,30,57,122,244,104,180,125,224,249,169,68,224,231,159,127,150,73,147,38,37,27,13,54,149,186,102,168,217,174,93,187,202,
208,161,67,35,238,100,98,149,176,68,137,18,178,97,195,6,41,80,160,128,161,58,89,136,4,72,128,4,72,128,4,72,128,4,98,69,0,243,48,88,17,174,91,183,78,183,73,100,144,40,94,188,184,103,115,144,35,120,229,
123,239,189,39,48,43,166,120,147,0,130,96,225,251,137,72,197,209,138,101,197,19,13,223,116,211,77,178,119,239,94,185,246,218,107,163,237,7,207,79,5,2,83,167,78,149,170,85,171,42,187,237,84,104,62,170,
38,79,156,56,33,112,200,199,10,76,36,193,15,5,81,227,34,69,140,139,116,30,143,147,0,9,144,0,9,144,0,9,144,64,44,8,252,250,235,175,42,78,5,252,33,245,118,5,17,139,3,209,109,135,12,25,18,139,238,56,210,
6,205,109,29,193,26,179,74,219,182,109,171,50,71,216,241,29,140,74,241,68,46,207,217,179,103,171,84,21,49,27,61,27,178,141,128,151,111,4,48,157,69,126,171,171,174,186,42,34,15,248,173,190,248,226,139,
116,106,143,72,136,31,144,0,9,144,0,9,144,0,9,164,54,1,248,121,230,207,159,95,94,127,253,117,221,174,96,33,189,81,163,70,170,140,110,1,151,31,68,32,200,242,229,203,11,244,6,138,247,8,212,171,87,79,165,
92,180,35,194,114,84,138,103,173,90,181,228,161,135,30,146,103,159,125,214,123,20,227,188,199,95,124,241,133,124,240,193,7,242,244,211,79,123,142,196,133,11,23,100,212,168,81,106,5,48,82,231,17,76,8,81,
108,177,51,122,229,149,87,70,42,198,227,36,64,2,36,64,2,36,64,2,36,144,170,4,96,153,5,83,212,253,251,247,235,246,3,174,81,227,199,143,151,94,189,122,233,126,238,246,131,152,183,141,29,59,86,144,222,142,
226,61,2,8,44,4,215,182,202,149,43,71,221,249,168,20,207,110,221,186,201,185,115,231,100,202,148,41,81,119,132,21,196,150,0,34,193,98,235,28,185,88,189,38,111,188,241,134,212,169,83,71,110,190,249,230,
136,93,135,35,251,213,87,95,45,19,38,76,136,88,134,31,144,0,9,144,0,9,144,0,9,144,64,106,19,64,186,138,66,133,10,169,249,116,164,212,111,200,137,137,64,67,201,89,122,165,246,56,146,107,191,71,143,30,50,
112,224,192,136,113,57,146,59,151,159,165,46,1,236,84,35,160,103,158,60,121,162,238,72,84,138,231,204,153,51,101,241,226,197,178,98,197,138,168,59,194,10,98,75,0,209,108,237,176,213,142,109,175,69,112,
115,198,130,7,242,200,70,146,203,151,47,43,71,252,37,75,150,168,224,66,145,202,241,56,9,144,0,9,144,0,9,144,0,9,184,129,0,230,100,91,182,108,137,56,167,62,117,234,148,172,90,181,202,179,86,134,176,178,
131,5,26,98,139,80,188,67,224,252,249,243,114,231,157,119,10,190,127,118,72,84,138,231,182,109,219,254,175,189,51,129,243,169,250,255,255,219,150,37,178,71,246,109,154,16,33,178,143,157,66,89,38,133,65,
100,95,178,12,190,74,225,107,151,8,33,42,100,223,203,86,118,165,34,202,158,157,144,37,66,164,102,236,244,248,127,95,231,255,27,6,159,115,103,187,159,251,185,231,243,121,157,199,131,153,185,231,222,115,
222,231,121,63,51,143,251,190,231,253,126,189,37,60,60,92,240,149,205,28,2,219,183,111,151,147,39,79,74,104,104,168,57,70,255,159,165,168,27,155,44,89,50,169,86,173,154,214,246,217,179,103,43,199,84,23,
178,162,189,144,29,36,64,2,36,64,2,36,64,2,36,224,3,2,127,252,241,135,148,41,83,70,149,172,208,237,106,226,197,251,176,97,195,196,83,205,79,31,152,28,167,41,177,41,0,145,164,161,67,135,198,233,58,158,
236,91,2,240,241,218,182,109,107,75,41,21,172,36,65,142,39,194,108,241,75,114,228,200,17,223,82,225,236,113,34,128,112,13,8,11,165,72,145,34,78,215,185,225,100,148,80,121,255,253,247,37,81,162,68,90,115,
42,87,174,44,97,97,97,234,23,69,123,18,59,72,128,4,72,128,4,72,128,4,72,192,69,4,106,212,168,33,33,33,33,210,175,95,63,143,86,97,71,244,194,133,11,210,160,65,3,143,253,110,63,8,97,72,60,199,165,76,153,
210,237,166,210,190,255,35,128,212,188,31,127,252,81,150,44,89,98,11,147,4,57,158,176,32,127,254,252,170,92,69,182,108,217,108,49,136,131,120,151,192,157,59,119,4,142,39,226,236,77,107,191,254,250,171,
170,35,100,37,136,132,55,134,37,75,150,148,131,7,15,170,28,79,211,214,72,123,73,128,4,72,128,4,72,128,4,2,147,0,82,215,224,156,109,219,182,77,11,0,121,158,163,70,141,210,246,187,185,3,37,24,15,29,58,36,
141,27,55,118,179,153,180,45,26,1,108,228,160,142,172,93,194,80,9,118,60,241,144,143,95,146,58,117,234,68,51,147,223,186,149,0,242,3,82,165,74,37,149,42,85,114,171,137,90,187,98,83,66,165,75,151,46,74,
240,106,238,220,185,218,113,216,65,2,36,64,2,36,64,2,36,64,2,110,35,128,112,84,8,39,46,91,182,76,138,23,47,238,209,188,249,243,231,43,33,34,60,127,155,216,76,46,229,103,34,239,132,218,140,93,120,84,47,
177,107,151,61,193,142,103,155,54,109,148,50,170,149,216,75,66,23,205,235,237,35,96,170,170,216,213,171,87,5,219,253,216,173,213,53,8,15,21,41,82,68,169,194,149,45,91,86,119,26,143,147,0,9,144,0,9,144,
0,9,144,128,43,9,32,143,243,248,241,227,178,104,209,34,143,246,33,114,13,161,184,38,10,68,98,65,168,85,218,172,89,51,121,242,201,39,61,174,143,7,221,69,0,47,64,22,44,88,32,79,63,253,180,45,134,37,216,
241,156,52,105,146,172,91,183,78,160,32,202,230,110,2,145,145,145,130,34,196,38,214,129,66,201,30,228,110,6,5,5,105,33,175,92,185,82,186,119,239,206,156,99,45,33,118,144,0,9,144,0,9,144,0,9,184,153,0,
156,206,154,53,107,202,254,253,251,37,121,242,228,30,77,197,179,92,163,70,141,36,123,246,236,30,251,221,124,240,204,153,51,178,116,233,82,65,132,26,155,187,9,92,187,118,77,158,125,246,89,57,122,244,168,
109,130,86,9,118,60,81,244,22,165,57,54,109,218,228,110,122,180,78,160,246,90,172,88,49,245,33,50,13,7,146,209,99,218,85,127,241,197,23,5,33,1,61,123,246,52,109,121,180,151,4,72,128,4,72,128,4,72,128,
4,20,1,8,119,54,111,222,92,58,119,238,236,145,8,74,92,160,166,185,93,121,119,30,39,241,226,65,134,219,122,17,174,141,67,255,244,211,79,210,186,117,107,219,20,109,97,90,130,29,207,43,87,174,72,233,210,
165,85,178,176,149,210,168,141,28,56,84,60,9,152,90,187,19,47,55,240,57,123,249,229,151,181,43,71,255,115,207,61,39,59,118,236,144,76,153,50,105,207,99,7,9,144,0,9,144,0,9,144,0,9,184,153,0,242,56,199,
143,31,175,234,122,234,236,28,48,96,128,170,107,14,221,14,211,218,140,25,51,148,239,240,204,51,207,152,102,122,64,217,139,42,18,16,186,90,188,120,177,109,235,78,176,227,9,75,130,131,131,5,97,142,80,184,
101,115,39,129,243,231,207,11,4,119,122,244,232,225,78,3,45,172,194,155,49,212,125,178,170,91,133,240,225,61,123,246,200,138,21,43,44,70,98,23,9,144,0,9,144,0,9,144,0,9,184,155,192,205,155,55,85,106,209,
55,223,124,163,132,132,60,89,139,240,71,244,91,41,253,123,186,206,13,199,34,34,34,148,99,13,221,17,54,247,18,128,250,112,169,82,165,108,141,36,180,197,241,68,238,29,182,98,17,22,192,230,78,2,19,39,78,
148,122,245,234,73,142,28,57,220,105,160,198,42,148,71,129,195,28,30,30,174,57,227,255,31,126,254,249,231,85,125,207,234,213,171,91,158,199,78,18,32,1,18,32,1,18,32,1,18,112,59,1,40,137,94,191,126,93,
62,255,252,115,173,169,72,67,26,49,98,132,36,78,156,88,123,142,91,59,224,116,98,83,129,209,146,110,189,67,34,85,170,84,81,186,48,213,170,85,179,205,72,91,28,79,196,152,99,71,109,202,148,41,182,25,198,
129,236,37,96,106,152,45,148,108,91,182,108,41,153,51,103,214,2,217,178,101,139,160,206,16,234,124,154,248,199,87,187,48,118,144,0,9,144,0,9,144,0,9,4,36,1,136,11,189,250,234,171,42,191,78,23,241,181,
113,227,70,129,112,100,221,186,117,141,99,132,72,201,212,169,83,75,72,72,136,113,182,7,130,193,168,20,81,184,112,97,249,254,251,239,109,77,97,179,197,241,92,178,100,137,124,242,201,39,178,122,245,234,
64,184,23,198,173,17,14,217,119,223,125,167,118,165,77,50,30,245,172,16,66,27,147,100,120,195,134,13,85,126,39,242,29,216,72,128,4,72,128,4,72,128,4,72,192,31,8,160,148,69,175,94,189,212,203,117,221,122,
122,247,238,173,202,205,233,250,221,122,28,101,97,80,159,125,240,224,193,110,53,49,160,237,58,113,226,132,212,174,93,91,14,30,60,104,43,7,91,28,207,147,39,79,170,48,206,221,187,119,219,106,28,7,179,135,
0,146,131,145,3,144,46,93,58,123,6,116,104,20,20,80,134,80,80,249,242,229,181,51,162,190,39,68,133,224,88,155,40,43,174,93,24,59,72,128,4,72,128,4,72,128,4,2,154,192,212,169,83,101,206,156,57,42,151,83,
7,98,214,172,89,234,57,168,104,209,162,186,83,92,123,28,181,217,17,145,167,43,27,227,90,195,3,192,48,124,174,16,230,141,60,98,59,155,45,142,39,12,130,50,21,182,252,179,102,205,106,167,125,28,203,6,2,166,
134,217,198,166,132,10,66,113,177,211,190,97,195,6,27,72,113,8,18,32,1,18,32,1,18,32,1,18,112,7,1,188,92,71,29,197,205,155,55,75,182,108,217,60,26,117,235,214,45,181,115,136,124,73,211,26,20,83,79,157,
58,37,161,161,161,166,153,238,247,246,66,187,39,87,174,92,98,119,52,161,109,142,103,197,138,21,149,0,76,131,6,13,252,254,102,152,180,192,237,219,183,11,118,164,77,251,165,70,1,229,181,107,215,74,135,14,
29,44,113,151,43,87,78,189,45,179,42,181,98,57,0,59,73,128,4,72,128,4,72,128,4,72,192,165,4,222,120,227,13,121,226,137,39,148,10,172,206,68,188,132,111,209,162,133,100,201,146,69,119,138,107,143,155,186,
57,226,90,160,54,25,86,171,86,45,233,214,173,155,10,183,181,105,72,53,140,109,142,39,212,169,254,249,231,31,153,48,97,130,157,246,113,172,4,18,64,252,124,159,62,125,36,69,138,20,9,28,201,217,203,135,12,
25,34,93,187,118,85,127,108,117,51,239,219,183,79,234,215,175,175,106,200,38,77,154,84,119,26,143,147,0,9,144,0,9,144,0,9,144,128,145,4,176,129,208,166,77,27,217,185,115,167,86,64,241,226,197,139,50,109,
218,52,245,188,103,218,34,71,142,28,169,214,151,33,67,6,211,76,247,91,123,33,44,84,162,68,9,181,1,100,37,238,25,31,0,182,57,158,203,151,47,23,196,162,35,47,143,205,29,4,32,206,211,191,127,127,37,87,237,
14,139,98,103,5,194,70,6,13,26,36,112,62,173,26,148,108,115,230,204,169,164,196,173,206,99,31,9,144,0,9,144,0,9,144,0,9,152,74,0,249,155,120,38,122,229,149,87,180,75,64,133,9,60,243,153,150,47,137,8,183,
245,235,215,75,187,118,237,180,107,99,135,179,4,80,35,182,105,211,166,130,80,104,187,155,109,142,39,234,45,162,78,228,214,173,91,89,147,199,238,187,20,207,241,144,247,136,183,22,166,213,182,92,176,96,
129,42,152,140,218,156,186,118,237,218,53,41,89,178,164,202,239,68,12,58,27,9,144,0,9,144,0,9,144,0,9,248,35,1,84,142,64,5,9,171,234,17,123,247,238,149,93,187,118,169,144,91,211,24,188,253,246,219,220,
68,112,209,77,155,62,125,186,44,93,186,84,253,179,219,44,219,28,79,24,134,124,187,25,51,102,72,80,80,144,221,118,114,188,120,16,64,41,18,132,218,234,234,63,197,99,72,71,46,137,141,168,208,152,49,99,228,
235,175,191,86,111,201,28,49,138,147,144,0,9,144,0,9,144,0,9,144,128,15,8,160,86,39,66,31,33,226,169,19,25,130,89,166,150,86,129,99,141,156,194,60,121,242,248,128,46,167,124,152,64,219,182,109,165,96,
193,130,74,187,231,225,190,132,254,108,171,227,137,66,183,117,234,212,145,86,173,90,37,212,46,94,159,64,2,55,111,222,84,245,47,33,85,109,82,67,189,32,236,154,199,244,25,130,152,21,28,84,138,10,153,116,
119,105,43,9,144,0,9,144,0,9,144,64,124,8,64,100,40,125,250,244,50,118,236,88,237,229,43,86,172,144,180,105,211,74,72,72,136,246,28,55,118,92,186,116,73,229,168,194,113,102,243,61,1,212,239,236,215,175,
159,148,45,91,214,118,99,108,117,60,199,141,27,39,216,234,159,50,101,138,237,134,114,192,184,17,64,72,6,222,138,149,46,93,58,110,23,250,248,108,56,202,112,40,83,165,74,165,181,100,207,158,61,242,218,107,
175,201,129,3,7,140,219,205,213,46,138,29,36,64,2,36,64,2,36,64,2,36,160,33,0,113,33,148,184,216,177,99,135,86,100,232,223,127,255,85,74,255,168,223,110,90,163,186,173,59,238,24,82,217,42,87,174,44,63,
252,240,131,87,242,133,109,117,60,161,188,133,228,230,53,107,214,184,131,94,0,91,129,95,224,97,195,134,25,149,111,139,122,85,163,70,141,138,177,102,80,147,38,77,84,14,232,224,193,131,3,248,14,115,233,
36,64,2,36,64,2,36,64,2,129,68,160,120,241,226,106,39,170,97,195,134,218,101,79,156,56,81,90,182,108,41,143,63,254,184,246,28,55,118,44,90,180,72,242,231,207,175,66,138,221,104,95,160,216,132,112,110,
212,132,93,183,110,157,87,150,108,171,227,121,231,206,29,41,83,166,140,124,243,205,55,150,101,48,188,178,18,14,122,143,64,68,68,132,170,247,132,18,55,38,53,168,34,87,168,80,65,130,131,131,181,102,195,
57,133,168,16,126,33,114,228,200,161,61,143,29,36,64,2,36,64,2,36,64,2,36,224,79,4,62,251,236,51,89,188,120,177,229,6,15,74,27,206,155,55,79,218,183,111,111,212,210,175,95,191,46,40,173,50,96,192,0,163,
236,246,55,99,177,129,136,93,79,104,169,120,163,217,234,120,194,192,42,85,170,8,212,169,144,36,204,230,27,2,179,102,205,18,40,194,22,42,84,200,55,6,196,115,214,216,136,10,97,71,116,237,218,181,234,95,
60,167,225,101,36,64,2,36,64,2,36,64,2,36,96,28,1,188,124,47,86,172,152,124,251,237,183,150,47,223,241,60,133,112,219,68,137,18,25,181,70,56,61,40,167,103,154,40,166,81,144,99,48,182,65,131,6,74,25,25,
95,189,209,108,119,60,17,226,137,29,183,9,19,38,120,195,94,142,25,11,2,38,198,201,255,244,211,79,114,230,204,25,9,13,13,181,92,33,148,147,145,240,252,210,75,47,89,158,199,78,18,32,1,18,32,1,18,32,1,18,
240,55,2,109,218,180,81,185,119,8,169,213,53,68,133,161,156,94,205,154,53,117,167,184,242,56,202,0,34,79,181,70,141,26,174,180,207,223,141,2,123,108,92,33,101,242,201,39,159,244,202,114,109,119,60,81,
4,118,196,136,17,44,115,225,149,219,21,243,160,23,47,94,148,153,51,103,74,207,158,61,99,62,217,69,103,32,44,24,111,185,146,38,77,170,181,10,206,105,139,22,45,4,202,183,137,19,39,214,158,199,14,18,32,1,
18,32,1,18,32,1,18,240,71,2,16,241,12,11,11,19,136,13,233,158,153,224,116,246,233,211,71,133,174,154,196,0,142,15,54,23,144,99,200,230,60,1,212,129,69,85,137,221,187,119,123,109,114,219,29,79,196,5,163,
214,16,84,183,76,75,108,246,26,101,7,7,158,60,121,178,218,13,204,157,59,183,131,179,38,108,170,203,151,47,11,242,22,240,71,210,170,97,55,20,159,45,132,98,176,145,0,9,144,0,9,144,0,9,144,64,32,18,120,225,
133,23,228,173,183,222,146,230,205,155,107,151,143,218,152,213,170,85,83,98,140,218,147,92,216,129,77,8,148,85,73,153,50,165,11,173,243,111,147,240,28,142,210,54,222,172,78,98,187,227,137,91,130,186,47,
189,122,245,138,49,108,210,191,111,159,111,86,103,98,152,237,71,31,125,164,62,43,217,179,103,215,66,187,114,229,138,42,13,3,121,103,111,109,255,107,39,103,7,9,144,0,9,144,0,9,144,0,9,184,132,192,156,57,
115,4,130,140,16,243,212,53,228,131,126,240,193,7,98,90,61,119,236,186,29,57,114,68,94,127,253,117,221,210,120,220,75,4,170,87,175,46,93,186,116,145,250,245,235,123,105,6,17,175,56,158,195,135,15,23,124,
112,22,46,92,232,53,195,57,240,163,4,78,159,62,45,203,151,47,151,206,157,59,63,218,233,210,35,8,7,129,179,140,240,108,171,214,191,127,127,249,229,151,95,100,233,210,165,86,167,177,143,4,72,128,4,72,128,
4,72,128,4,252,154,192,205,155,55,165,112,225,194,178,106,213,42,9,10,10,210,174,21,187,135,61,122,244,144,52,105,210,104,207,113,99,135,137,155,40,110,228,24,23,155,16,177,90,180,104,81,21,194,253,196,
19,79,196,229,210,56,157,235,21,199,51,42,254,28,142,2,155,115,4,198,142,29,43,168,113,153,37,75,22,231,38,77,224,76,200,9,134,243,105,149,72,142,254,82,165,74,41,105,231,138,21,43,38,112,70,94,78,2,36,
64,2,36,64,2,36,64,2,102,19,8,15,15,87,97,145,51,102,204,208,46,228,248,241,227,74,40,166,99,199,142,218,115,220,216,129,10,6,200,53,204,152,49,163,27,205,243,75,155,230,206,157,43,227,198,141,19,232,
169,120,179,121,197,241,132,193,121,243,230,85,187,83,207,61,247,156,55,237,231,216,209,8,152,248,134,8,165,119,176,67,110,37,249,189,114,229,74,129,52,248,190,125,251,162,173,150,223,146,0,9,144,0,9,
144,0,9,144,64,96,18,56,113,226,132,212,169,83,71,105,170,88,229,67,154,88,90,229,183,223,126,83,14,179,105,181,72,77,254,36,190,242,202,43,82,185,114,101,193,11,13,111,54,175,57,158,120,187,114,251,246,
109,175,38,168,122,19,140,105,99,31,61,122,84,144,255,248,230,155,111,26,99,250,217,179,103,101,209,162,69,210,173,91,55,75,155,95,124,241,69,193,47,68,167,78,157,44,207,99,39,9,144,0,9,144,0,9,144,0,
9,4,10,129,170,85,171,42,231,211,170,146,129,169,165,85,76,220,76,49,245,115,7,53,225,224,224,96,229,236,231,203,151,207,171,203,240,154,227,9,39,8,138,91,222,148,228,245,42,25,195,6,31,57,114,164,180,
109,219,86,210,167,79,111,140,229,176,185,117,235,214,150,161,20,191,255,254,187,132,132,132,168,207,145,105,57,10,198,220,8,26,74,2,36,64,2,36,64,2,36,96,28,1,68,132,13,30,60,88,182,108,217,162,181,221,
212,210,42,168,210,128,141,135,60,121,242,104,215,198,14,123,8,124,253,245,215,170,12,227,161,67,135,236,25,208,98,20,175,57,158,240,158,115,229,202,165,188,103,36,64,179,121,151,128,105,111,134,238,220,
185,35,16,12,26,54,108,152,37,152,14,29,58,200,221,187,119,85,185,21,203,19,217,73,2,36,64,2,36,64,2,36,64,2,1,68,0,207,218,5,11,22,84,10,183,21,42,84,208,174,28,78,92,205,154,53,197,219,187,89,90,3,226,
209,241,231,159,127,202,244,233,211,85,149,140,120,92,206,75,226,64,0,81,133,40,209,243,222,123,239,197,225,170,248,157,234,53,199,19,230,32,52,50,50,50,82,102,206,156,25,63,235,120,85,172,8,64,204,9,
255,154,54,109,26,171,243,221,112,210,178,101,203,36,83,166,76,82,190,124,121,173,57,183,110,221,82,117,59,17,142,139,63,172,108,36,64,2,36,64,2,36,64,2,36,64,2,247,9,160,100,10,162,12,81,213,64,215,34,
34,34,148,64,35,94,248,155,212,76,219,84,49,137,109,148,173,216,8,130,50,242,134,13,27,28,121,49,225,85,199,115,219,182,109,170,184,237,193,131,7,45,197,99,162,22,207,175,241,35,48,116,232,80,149,39,153,
58,117,234,248,13,224,131,171,80,164,246,253,247,223,183,156,121,210,164,73,50,123,246,108,217,188,121,179,229,121,236,36,1,18,32,1,18,32,1,18,32,129,64,36,112,249,242,101,181,91,133,112,219,204,153,51,
107,17,160,158,39,132,134,82,165,74,165,61,199,109,29,243,230,205,147,66,133,10,9,133,74,189,119,103,176,57,8,21,97,167,42,145,120,213,241,4,38,108,235,79,156,56,81,94,122,233,222,195,6,179,0,0,31,98,
73,68,65,84,37,239,81,11,240,145,77,123,35,4,121,239,181,107,215,10,194,104,173,26,118,67,123,245,234,37,13,26,52,176,58,141,125,36,64,2,36,64,2,36,64,2,36,16,176,4,194,194,194,148,211,137,178,122,186,
118,248,240,97,181,51,218,166,77,27,221,41,174,59,142,218,146,163,71,143,150,126,253,250,185,206,54,127,49,168,82,165,74,210,184,113,99,113,170,228,142,215,29,79,148,202,216,184,113,163,202,245,244,151,
155,228,166,117,252,252,243,207,2,1,30,147,156,51,236,208,66,120,202,170,64,45,118,203,17,58,140,68,231,36,73,146,184,9,57,109,33,1,18,32,1,18,32,1,18,32,1,215,16,128,144,103,139,22,45,100,231,206,157,
146,52,105,82,173,93,189,123,247,22,132,230,154,212,250,246,237,43,67,134,12,145,196,137,19,155,100,182,17,182,94,186,116,73,160,195,131,200,84,167,196,73,189,238,120,254,241,199,31,42,79,15,111,90,168,
74,106,255,231,16,161,19,216,241,76,158,60,185,253,131,123,97,68,228,109,14,26,52,72,253,17,177,26,190,126,253,250,82,170,84,41,121,247,221,119,173,78,99,31,9,144,0,9,144,0,9,144,0,9,4,60,1,136,195,64,
91,165,101,203,150,90,22,43,86,172,144,116,233,210,73,197,138,21,181,231,184,173,99,213,170,85,42,60,24,59,115,108,246,18,64,57,195,83,167,78,201,146,37,75,236,29,216,98,52,175,59,158,152,27,114,200,136,
207,142,41,167,207,194,78,118,121,32,0,181,215,1,3,6,196,232,196,121,184,212,103,135,22,44,88,160,146,152,75,148,40,161,181,1,74,102,101,202,148,145,173,91,183,42,1,34,237,137,236,32,1,18,32,1,18,32,1,
18,32,1,18,144,133,11,23,202,248,241,227,85,56,173,14,7,158,27,241,66,127,196,136,17,186,83,92,119,28,226,55,3,7,14,84,101,99,92,103,156,225,6,65,184,243,147,79,62,81,101,11,157,90,138,35,142,231,250,
245,235,149,248,205,254,253,251,157,90,87,64,204,131,162,192,8,61,168,86,173,154,49,235,69,98,59,234,119,90,181,30,61,122,200,185,115,231,100,254,252,249,86,167,177,143,4,72,128,4,72,128,4,72,128,4,72,
224,127,4,110,223,190,173,42,0,44,94,188,88,138,21,43,166,101,50,102,204,24,121,253,245,215,37,91,182,108,218,115,220,214,129,77,22,56,204,143,61,246,152,219,76,51,214,158,47,191,252,82,137,77,29,61,122,
212,81,1,88,71,28,79,20,175,45,80,160,128,124,248,225,135,82,175,94,61,99,111,146,219,12,199,47,33,194,86,77,201,129,68,190,230,143,63,254,40,111,190,249,166,22,37,222,108,21,47,94,92,149,224,193,87,54,
18,32,1,18,32,1,18,32,1,18,32,129,152,9,96,103,16,234,164,95,124,241,133,246,100,68,149,77,157,58,85,80,93,192,148,134,103,71,216,141,122,147,108,246,16,64,184,117,147,38,77,84,120,182,61,35,198,110,20,
71,28,79,152,242,241,199,31,11,100,145,81,107,136,45,225,4,110,220,184,161,66,151,241,22,200,148,134,63,136,80,169,125,252,241,199,181,38,227,143,33,182,253,33,154,196,70,2,36,64,2,36,64,2,36,64,2,36,
16,59,2,23,46,92,144,114,229,202,41,97,70,43,145,33,8,246,224,153,44,89,178,100,177,27,216,199,103,97,3,11,155,45,195,134,13,243,177,37,254,49,61,118,57,67,66,66,4,95,157,46,197,232,152,227,121,245,234,
85,149,219,135,176,91,212,228,97,75,24,1,132,82,228,201,147,71,74,150,44,153,176,129,28,186,250,250,245,235,42,167,0,127,232,172,90,133,10,21,164,123,247,238,242,234,171,175,90,157,198,62,18,32,1,18,32,
1,18,32,1,18,32,129,135,8,32,140,182,102,205,154,210,186,117,235,135,122,238,255,136,202,1,39,78,156,144,215,94,123,237,254,65,151,127,135,138,8,93,187,118,165,80,169,13,247,41,52,52,84,114,229,202,37,
8,187,118,186,57,230,120,98,97,111,191,253,182,28,56,112,64,150,47,95,238,244,58,253,110,62,211,106,119,206,154,53,75,229,28,20,41,82,68,123,47,176,203,137,90,84,144,117,182,122,83,167,29,128,29,36,64,
2,36,64,2,36,64,2,36,16,192,4,118,237,218,165,74,214,109,218,180,201,146,130,105,165,85,160,19,131,181,53,107,214,204,114,93,236,180,38,240,215,95,127,73,209,162,69,149,128,103,246,236,217,173,79,246,
66,175,163,142,39,66,0,158,127,254,121,21,70,249,212,83,79,121,97,57,129,49,228,149,43,87,84,56,170,73,241,249,177,17,21,66,236,62,212,108,17,2,194,70,2,36,64,2,36,64,2,36,64,2,36,16,119,2,65,65,65,50,
123,246,108,41,93,186,180,246,226,25,51,102,168,168,57,212,113,52,165,153,182,233,226,70,174,237,218,181,147,200,200,72,153,59,119,174,79,204,115,212,241,196,10,219,183,111,47,8,187,197,47,4,91,252,8,
32,15,18,177,217,248,195,98,66,219,183,111,159,42,106,140,226,198,186,118,254,252,121,149,151,128,240,143,12,25,50,232,78,227,113,18,32,1,18,32,1,18,32,1,18,32,1,11,2,40,151,2,65,30,171,8,67,164,64,13,
31,62,92,137,84,90,12,229,170,46,136,148,54,111,222,92,50,103,206,236,42,187,76,49,6,14,39,202,91,174,92,185,82,130,131,131,125,98,182,227,142,231,233,211,167,149,211,4,7,35,83,166,76,62,89,180,233,147,
154,246,198,7,2,72,8,179,78,153,50,165,22,61,138,30,227,133,4,222,192,177,145,0,9,144,0,9,144,0,9,144,0,9,196,143,0,194,41,161,1,178,121,243,102,201,154,53,171,118,144,193,131,7,43,93,141,52,105,210,104,
207,113,83,199,169,83,167,228,171,175,190,114,92,137,213,77,12,18,98,11,202,21,30,63,126,92,150,45,91,150,144,97,18,116,173,227,142,39,172,69,57,13,40,84,125,254,249,231,9,50,62,16,47,254,253,247,223,
5,181,119,222,122,235,45,35,150,127,237,218,53,85,183,243,191,255,253,175,214,222,155,55,111,170,18,42,144,255,70,49,91,54,18,32,1,18,32,1,18,32,1,18,32,129,248,19,192,179,54,234,94,78,158,60,89,59,200,
177,99,199,4,162,159,136,70,52,165,97,35,3,59,186,108,113,35,128,221,78,164,59,46,89,178,196,167,34,175,62,113,60,207,156,57,35,149,43,87,86,111,98,178,100,201,18,55,114,1,126,246,184,113,227,84,225,95,
171,55,88,110,66,132,151,11,200,219,180,114,40,17,58,129,183,47,223,125,247,157,155,76,167,45,36,64,2,36,64,2,36,64,2,36,96,36,129,195,135,15,75,131,6,13,84,170,83,138,20,41,180,107,136,141,6,135,246,
98,31,116,76,153,50,69,170,84,169,34,249,243,231,247,193,236,230,78,137,221,206,147,39,79,170,205,43,95,174,194,39,142,39,22,140,29,59,20,131,69,109,79,182,216,19,128,240,142,73,117,140,98,243,7,173,84,
169,82,50,100,200,16,169,85,171,86,236,65,240,76,18,32,1,18,32,1,18,32,1,18,32,1,45,1,56,104,181,107,215,22,40,216,234,26,242,64,211,167,79,47,21,43,86,212,157,226,170,227,8,35,254,244,211,79,197,36,129,
77,95,3,188,116,233,146,148,45,91,86,86,173,90,229,115,135,221,103,142,103,84,252,249,210,165,75,197,170,196,134,175,111,150,155,230,71,152,45,118,6,145,15,105,66,219,189,123,183,42,141,210,164,73,19,
173,185,136,213,135,115,10,153,236,68,137,18,105,207,99,7,9,144,0,9,144,0,9,144,0,9,144,64,236,9,32,140,22,161,169,208,85,209,61,99,221,189,123,87,222,123,239,61,37,52,20,251,145,125,123,166,105,90,39,
190,165,37,170,84,97,186,116,233,100,226,196,137,190,54,69,124,230,120,98,229,147,38,77,146,249,243,231,51,196,50,150,31,3,124,96,16,54,145,45,91,182,88,94,225,219,211,250,245,235,167,254,152,37,79,158,
92,107,72,181,106,213,84,232,48,228,157,217,72,128,4,72,128,4,72,128,4,72,128,4,236,33,0,61,21,108,238,32,170,172,126,253,250,218,65,71,141,26,37,168,60,240,228,147,79,106,207,113,83,7,180,78,114,228,
200,33,47,188,240,130,155,204,114,165,45,59,118,236,80,207,217,219,183,111,23,56,159,190,110,62,117,60,255,253,247,95,65,152,101,155,54,109,164,99,199,142,190,102,225,250,249,223,125,247,93,25,58,116,
168,235,237,132,129,17,17,17,50,118,236,88,129,243,169,107,7,14,28,144,186,117,235,170,221,78,43,197,91,221,245,60,78,2,36,64,2,36,64,2,36,64,2,36,160,39,48,109,218,52,153,53,107,150,124,251,237,183,218,
147,254,248,227,15,85,215,49,60,60,92,123,142,155,58,32,74,137,82,48,86,194,149,110,178,215,87,182,224,197,67,249,242,229,149,120,212,27,111,188,225,43,51,30,152,215,167,142,39,44,217,179,103,143,242,
196,81,111,136,245,27,31,184,55,15,252,0,9,105,196,102,155,162,60,134,248,251,170,85,171,74,129,2,5,30,88,71,244,31,26,53,106,36,79,63,253,180,49,206,116,116,219,249,61,9,144,0,9,144,0,9,144,0,9,184,157,
0,156,180,66,133,10,73,76,169,109,8,201,133,134,72,226,196,137,221,190,36,101,31,54,54,80,174,47,105,210,164,70,216,235,11,35,81,46,103,237,218,181,242,253,247,223,107,67,173,157,182,203,231,142,39,22,
140,4,225,131,7,15,90,22,186,117,26,140,219,230,131,242,43,222,86,100,204,152,209,109,166,121,180,39,38,81,33,8,75,65,237,22,53,166,168,108,236,17,33,15,146,0,9,144,0,9,144,0,9,144,64,130,9,192,65,219,
187,119,175,165,162,41,118,68,111,220,184,33,47,189,244,82,130,231,115,98,0,56,83,168,255,110,138,189,78,48,137,62,7,234,117,214,172,89,83,214,173,91,39,121,243,230,141,222,229,211,239,93,225,120,222,
186,117,75,133,220,118,238,220,89,152,235,231,249,243,96,82,152,237,214,173,91,229,236,217,179,210,176,97,67,207,139,249,223,81,168,26,95,190,124,89,230,204,153,163,61,135,29,36,64,2,36,64,2,36,64,2,36,
64,2,9,35,128,151,253,165,75,151,150,45,91,182,104,243,56,17,150,137,93,207,247,223,127,63,97,147,57,116,53,210,245,32,138,100,82,165,7,135,208,8,216,64,165,56,44,44,204,117,130,164,174,112,60,113,35,
160,106,138,196,103,40,112,229,206,157,219,169,123,99,196,60,80,35,67,237,83,8,11,153,208,224,36,15,28,56,80,27,254,128,176,143,226,197,139,203,226,197,139,125,90,196,214,4,150,180,145,4,72,128,4,72,128,
4,72,128,4,18,74,160,85,171,86,2,177,199,201,147,39,107,135,26,63,126,188,122,22,207,153,51,167,246,28,55,117,64,52,169,123,247,238,146,58,117,106,55,153,229,115,91,122,246,236,41,191,252,242,139,10,179,
213,169,25,251,202,72,215,56,158,0,0,213,214,217,179,103,203,166,77,155,36,73,146,36,190,98,226,186,121,145,60,13,103,46,89,178,100,174,179,237,97,131,176,139,137,252,78,188,53,211,53,188,77,91,189,122,
181,101,162,187,238,90,30,39,1,18,32,1,18,32,1,18,32,1,18,136,27,129,35,71,142,72,189,122,245,100,231,206,157,162,19,116,68,169,67,56,166,40,87,98,66,195,166,213,174,93,187,164,89,179,102,38,152,235,136,
141,107,214,172,145,46,93,186,8,180,115,50,103,206,236,200,156,113,153,196,85,142,39,12,199,47,5,242,24,161,194,197,38,114,237,218,53,65,126,39,194,9,76,104,49,189,45,67,40,71,201,146,37,229,131,15,62,
80,226,67,38,172,137,54,146,0,9,144,0,9,144,0,9,144,128,233,4,144,243,135,16,76,171,138,3,125,251,246,149,65,131,6,105,163,214,220,198,128,53,61,239,223,145,11,23,46,168,251,251,217,103,159,73,72,72,200,
253,14,23,125,231,58,199,51,50,50,82,137,206,116,234,212,201,117,113,201,190,184,111,211,167,79,151,178,101,203,74,112,112,176,47,166,143,211,156,177,201,15,64,221,86,196,227,35,4,128,141,4,72,128,4,72,
128,4,72,128,4,72,192,25,2,136,40,196,110,24,118,61,117,234,181,200,3,69,121,21,83,210,187,80,186,175,113,227,198,146,53,107,86,103,32,186,116,150,59,119,238,72,165,74,149,228,229,151,95,182,140,58,244,
181,249,174,115,60,1,4,225,0,80,169,66,221,161,114,229,202,249,154,145,79,231,55,233,77,206,55,223,124,35,16,138,122,241,197,23,181,204,240,166,13,53,91,155,54,109,170,61,135,29,36,64,2,36,64,2,36,64,
2,36,64,2,246,19,120,254,249,231,149,192,99,203,150,45,181,131,199,84,153,64,123,161,15,58,32,102,249,197,23,95,168,53,249,96,122,215,76,137,231,106,68,73,46,89,178,196,53,165,83,60,193,113,165,227,9,
67,145,3,216,181,107,87,129,51,147,35,71,14,79,182,251,253,177,237,219,183,203,201,147,39,37,52,52,212,136,181,198,84,3,10,165,83,240,135,14,165,115,88,119,201,136,91,74,35,73,128,4,72,128,4,72,128,4,
252,136,0,156,180,209,163,71,171,28,64,221,178,144,231,137,176,220,124,249,242,233,78,113,213,113,60,127,142,24,49,194,85,54,57,105,12,202,229,44,95,190,92,149,40,76,149,42,149,147,83,199,121,46,215,58,
158,88,201,184,113,227,228,243,207,63,87,98,67,129,168,88,133,188,78,8,11,153,224,164,157,59,119,78,16,70,219,163,71,15,237,135,16,187,216,53,106,212,144,240,240,112,237,57,236,32,1,18,32,1,18,32,1,18,
32,1,18,240,14,129,187,119,239,170,138,2,31,127,252,177,84,171,86,205,227,36,255,252,243,143,64,179,3,194,150,38,52,147,210,210,236,230,57,99,198,12,25,58,116,168,108,220,184,81,178,101,203,102,247,240,
182,143,231,106,199,19,171,69,44,58,242,1,55,108,216,96,132,170,171,93,119,232,252,249,243,50,119,238,92,75,71,206,174,185,236,24,7,98,65,216,205,212,41,104,253,250,235,175,234,237,25,238,101,32,190,68,
176,131,49,199,32,1,18,32,1,18,32,1,18,32,129,132,18,128,211,137,144,204,117,235,214,105,135,194,230,7,118,210,76,168,168,240,247,223,127,43,53,222,62,125,250,104,215,227,143,29,40,65,217,174,93,59,89,
182,108,153,20,41,82,196,136,37,186,222,241,68,17,212,134,13,27,170,220,193,175,190,250,74,155,12,109,4,237,56,24,137,146,35,109,219,182,149,12,25,50,196,225,42,223,156,138,183,103,80,72,179,42,226,251,
250,235,175,171,250,172,35,71,142,244,141,145,156,149,4,72,128,4,72,128,4,72,128,4,72,64,174,95,191,46,133,11,23,150,21,43,86,168,175,158,144,160,134,252,111,191,253,38,141,26,53,242,212,237,186,99,112,
148,7,15,30,236,234,252,70,59,161,65,32,10,247,102,202,148,41,82,165,74,21,59,135,246,234,88,174,119,60,177,122,8,214,32,214,60,83,166,76,178,104,209,34,191,255,80,33,57,24,14,26,194,108,77,104,120,211,
130,123,83,190,124,121,143,230,94,188,120,81,41,243,34,199,51,75,150,44,30,207,225,65,18,32,1,18,32,1,18,32,1,18,32,1,103,8,96,55,115,239,222,189,242,229,151,95,106,39,52,73,100,8,145,145,137,18,37,10,
136,82,125,135,15,31,150,58,117,234,8,54,169,76,209,129,137,250,144,25,225,120,194,88,56,99,85,171,86,85,137,206,115,230,204,241,107,231,19,73,221,200,133,204,159,63,127,212,125,114,245,215,152,254,48,
117,232,208,65,189,93,67,28,58,27,9,144,0,9,144,0,9,144,0,9,144,128,111,9,92,190,124,89,74,149,42,37,63,252,240,131,54,55,240,147,79,62,145,234,213,171,27,241,60,138,146,126,136,190,27,50,100,136,111,
193,122,121,246,99,199,142,169,202,31,8,43,110,221,186,181,151,103,179,127,120,99,28,79,44,29,201,206,216,78,126,230,153,103,100,246,236,217,126,233,124,162,14,15,126,113,134,15,31,110,255,221,246,194,
136,200,221,132,242,48,98,204,61,181,171,87,175,10,164,187,17,206,17,20,20,228,233,20,30,35,1,18,32,1,18,32,1,18,32,1,18,112,152,64,167,78,157,212,198,0,132,60,61,53,60,119,127,244,209,71,130,48,86,19,
26,194,78,33,152,148,55,111,94,19,204,141,179,141,120,230,174,93,187,182,170,250,1,13,28,19,155,81,142,39,0,35,129,24,206,39,156,152,121,243,230,249,93,206,39,106,151,34,65,184,88,177,98,70,124,158,16,
79,15,37,91,157,96,16,20,209,246,236,217,35,200,207,101,35,1,18,32,1,18,32,1,18,32,1,18,112,7,129,83,167,78,169,29,205,159,127,254,89,210,165,75,231,209,40,147,68,134,144,187,10,177,203,254,253,251,123,
92,139,201,7,15,29,58,36,47,191,252,178,116,238,220,89,186,119,239,110,236,82,140,115,60,65,26,206,39,182,254,33,27,140,122,68,38,148,27,137,205,39,4,34,61,168,69,132,95,26,19,218,141,27,55,212,206,236,
192,129,3,61,154,123,251,246,109,41,81,162,132,42,137,83,178,100,73,143,231,240,32,9,144,0,9,144,0,9,144,0,9,144,128,111,8,64,160,38,103,206,156,242,225,135,31,122,52,0,78,233,233,211,167,141,201,37,156,
48,97,130,212,175,95,95,114,228,200,225,113,61,38,30,220,189,123,183,188,250,234,171,202,225,52,117,167,51,138,187,145,142,39,140,143,136,136,144,90,181,106,9,10,165,98,55,45,69,138,20,81,107,50,246,43,
118,112,11,20,40,160,98,238,77,88,4,114,54,225,80,66,25,205,83,27,51,102,140,74,90,71,254,0,27,9,144,0,9,144,0,9,144,0,9,144,128,187,8,236,223,191,95,169,163,66,37,85,247,44,141,124,66,8,217,152,208,76,
19,232,140,137,41,234,115,182,106,213,74,213,84,109,211,166,77,76,167,187,190,223,88,199,19,100,177,165,142,109,231,200,200,72,89,189,122,181,54,76,192,245,119,225,127,6,98,183,19,34,61,163,71,143,54,
193,92,101,163,149,168,16,202,224,32,105,29,234,188,186,2,197,198,44,148,134,146,0,9,144,0,9,144,0,9,144,128,159,18,64,229,136,144,144,16,109,46,231,164,73,147,148,160,77,158,60,121,140,32,48,117,234,
84,41,87,174,156,20,44,88,208,8,123,117,70,46,92,184,80,122,247,238,173,158,165,81,150,208,31,154,209,142,39,110,0,194,57,155,52,105,34,136,125,94,185,114,165,228,202,149,203,200,251,50,115,230,76,41,
84,168,144,218,65,52,97,1,59,118,236,16,36,57,235,126,17,176,30,236,120,238,218,181,203,132,229,208,70,18,32,1,18,32,1,18,32,1,18,8,72,2,91,182,108,17,84,32,192,179,157,167,244,181,43,87,174,8,156,207,
119,222,121,199,8,62,16,234,132,173,166,164,174,121,130,58,106,212,40,25,63,126,188,124,246,217,103,170,164,164,167,115,76,60,102,188,227,9,232,144,80,238,214,173,155,114,60,231,206,157,43,47,188,240,
130,81,247,226,230,205,155,42,17,218,148,48,6,192,133,104,16,234,140,38,75,150,204,35,235,178,101,203,170,183,52,13,27,54,244,216,207,131,36,64,2,36,64,2,36,64,2,36,64,2,238,32,128,231,182,102,205,154,
41,241,26,79,22,245,237,219,87,6,13,26,228,209,49,245,116,190,175,143,161,226,2,84,121,145,239,105,82,131,79,3,181,225,85,171,86,201,226,197,139,141,217,144,138,45,99,191,112,60,163,22,139,29,182,177,
99,199,202,176,97,195,36,44,44,44,234,176,235,191,194,230,6,13,26,72,238,220,185,93,111,43,12,252,235,175,191,4,181,157,32,132,228,169,45,93,186,84,240,7,106,223,190,125,126,167,58,236,105,189,60,70,2,
36,64,2,36,64,2,36,64,2,38,19,88,187,118,173,122,118,131,152,80,226,196,137,31,89,10,244,58,176,243,137,20,55,83,26,114,83,161,202,155,38,77,26,35,76,70,126,42,54,108,78,156,56,161,54,211,242,231,207,
111,132,221,113,49,210,175,28,79,44,124,217,178,101,242,214,91,111,169,16,80,228,23,38,74,148,40,46,60,28,63,247,240,225,195,170,14,102,199,142,29,29,159,59,190,19,162,166,19,126,49,116,138,97,229,203,
151,87,111,204,154,54,109,26,223,41,120,29,9,144,0,9,144,0,9,144,0,9,144,128,131,4,80,119,189,125,251,246,30,107,179,99,39,14,27,14,38,69,231,157,63,127,94,160,114,139,210,127,110,111,103,206,156,145,
186,117,235,74,242,228,201,149,211,153,49,99,70,183,155,28,47,251,252,206,241,4,5,200,14,135,134,134,170,90,159,40,183,242,248,227,143,199,11,142,183,47,186,117,235,150,244,235,215,79,149,36,241,244,118,
201,219,243,199,103,124,136,6,97,55,115,196,136,17,30,47,7,111,212,79,250,229,151,95,36,73,146,36,30,207,225,65,18,32,1,18,32,1,18,32,1,18,32,1,119,17,88,179,102,205,189,93,79,79,207,112,227,198,141,83,
10,184,40,103,104,74,155,51,103,142,100,201,146,69,149,97,116,171,205,80,174,109,221,186,181,74,21,68,197,136,199,30,123,204,173,166,38,216,46,191,116,60,65,229,194,133,11,106,87,14,53,63,17,35,29,28,
28,156,96,88,118,15,128,55,48,144,70,126,234,169,167,236,30,218,107,227,225,143,18,18,207,61,41,213,226,109,88,153,50,101,84,110,39,234,13,177,145,0,9,144,0,9,144,0,9,144,0,9,152,67,0,207,113,175,189,
246,154,132,135,135,63,98,244,197,139,23,5,142,81,175,94,189,30,233,115,243,129,174,93,187,42,93,146,12,25,50,184,206,76,248,2,159,126,250,169,122,118,134,157,254,222,252,214,241,196,141,67,137,18,36,
66,227,151,164,123,247,238,234,159,91,110,232,180,105,211,148,204,51,146,185,77,106,136,151,199,110,167,167,16,230,201,147,39,171,95,30,168,162,121,234,55,105,157,180,149,4,72,128,4,72,128,4,72,128,4,
2,141,192,143,63,254,168,194,109,183,109,219,230,177,174,39,194,109,135,15,31,110,212,115,222,159,127,254,41,3,6,12,80,97,183,110,121,62,133,94,74,163,70,141,228,244,233,211,2,97,84,132,57,7,66,243,107,
199,51,234,6,110,223,190,93,154,55,111,174,118,22,177,229,238,235,29,70,228,161,66,234,25,225,192,38,181,223,126,251,77,197,157,67,109,235,225,6,101,94,212,237,68,254,103,229,202,149,31,238,230,207,36,
64,2,36,64,2,36,64,2,36,64,2,6,16,168,93,187,182,20,46,92,216,99,57,146,213,171,87,171,80,208,170,85,171,26,176,146,251,38,66,229,246,192,129,3,210,165,75,151,251,7,125,244,221,244,233,211,101,200,144,
33,82,165,74,21,37,138,234,214,148,64,111,224,9,8,199,19,224,224,24,225,109,199,130,5,11,148,19,138,82,32,190,200,171,196,47,236,239,191,255,174,98,185,189,113,67,189,57,38,126,73,32,220,148,54,109,218,
71,166,249,207,127,254,163,242,58,177,62,54,18,32,1,18,32,1,18,32,1,18,32,1,51,9,28,61,122,84,224,124,110,218,180,73,229,71,70,95,5,180,62,80,82,15,187,158,166,53,212,196,204,147,39,143,212,168,81,195,
39,166,99,3,231,205,55,223,84,126,192,148,41,83,164,98,197,138,62,177,195,151,147,6,140,227,25,5,25,42,178,200,171,68,109,159,129,3,7,58,90,223,103,197,138,21,114,252,248,113,85,115,52,202,30,83,190,222,
184,113,67,149,169,65,232,242,195,237,220,185,115,18,18,18,162,106,14,21,40,80,224,225,110,254,76,2,36,64,2,36,64,2,36,64,2,36,96,16,1,228,27,158,61,123,86,233,164,60,108,54,82,174,160,126,155,62,125,
250,135,187,92,255,51,210,194,80,166,196,73,231,243,234,213,171,210,163,71,15,65,201,26,136,8,33,109,205,159,5,132,172,62,4,1,231,120,70,193,64,184,107,239,222,189,213,155,28,148,93,241,102,174,37,68,
119,32,63,141,184,114,124,216,76,108,51,103,206,148,18,37,74,200,179,207,62,251,136,249,245,234,213,19,56,156,163,71,143,126,164,143,7,72,128,4,72,128,4,72,128,4,72,128,4,204,34,128,13,26,60,247,77,157,
58,85,42,85,170,244,128,241,39,79,158,148,175,191,254,90,60,165,94,61,112,162,75,127,152,63,127,190,68,68,68,72,219,182,109,189,106,33,170,87,64,60,8,209,150,69,139,22,21,168,2,103,207,158,221,171,115,
186,125,240,128,117,60,113,99,110,223,190,45,147,38,77,146,15,63,252,80,242,230,205,171,118,244,236,118,64,247,238,221,43,19,39,78,148,198,141,27,27,157,251,136,80,90,56,232,15,183,149,43,87,42,209,166,
93,187,118,185,182,108,205,195,54,243,103,18,32,1,18,32,1,18,32,1,18,32,1,107,2,179,103,207,86,218,29,91,182,108,121,164,68,30,68,134,116,165,245,172,71,117,71,239,207,63,255,172,68,125,222,121,231,157,
71,194,137,19,106,33,162,4,63,248,224,3,53,126,166,76,153,20,195,226,197,139,39,116,88,191,184,62,160,29,207,168,59,24,25,25,169,146,123,17,251,141,55,17,8,31,8,11,11,83,101,67,162,206,137,235,215,99,
199,142,201,250,245,235,5,31,56,236,8,162,4,137,169,13,202,102,136,75,135,250,86,244,134,188,89,200,110,35,95,22,107,100,35,1,18,32,1,18,32,1,18,32,1,18,240,15,2,136,216,67,42,21,68,35,177,115,23,189,
65,137,21,81,112,216,201,51,181,93,185,114,69,229,170,98,29,16,33,77,104,67,104,50,210,248,190,251,238,59,165,135,2,199,28,2,66,108,247,9,208,241,188,207,66,240,134,226,139,47,190,144,241,227,199,203,
229,203,151,37,40,40,72,237,84,54,108,216,48,198,221,60,124,120,241,65,219,191,127,191,100,205,154,85,138,21,43,166,66,20,162,13,111,236,183,72,34,135,115,153,44,89,178,7,214,0,101,48,228,172,98,215,147,
141,4,72,128,4,72,128,4,72,128,4,72,192,191,8,68,9,13,33,63,17,209,129,81,45,42,140,244,97,135,52,170,223,164,175,120,150,253,254,251,239,5,58,48,16,79,122,238,185,231,212,115,124,193,130,5,99,44,27,3,
62,200,27,197,174,48,52,79,80,231,30,66,156,24,131,237,81,2,116,60,31,101,162,142,160,174,14,156,208,89,179,102,169,15,18,18,168,159,120,226,9,245,47,95,190,124,170,36,203,158,61,123,84,226,53,118,76,
17,11,143,68,225,220,185,115,11,250,107,213,170,37,229,203,151,87,78,168,102,10,35,14,95,184,112,65,32,251,140,80,219,232,109,231,206,157,170,192,240,15,63,252,224,243,242,52,209,237,226,247,36,64,2,36,
64,2,36,64,2,36,64,2,246,17,24,58,116,168,138,226,67,73,146,232,117,48,81,66,175,126,253,250,146,43,87,46,251,38,243,193,72,40,113,136,82,43,107,214,172,81,66,153,136,242,67,195,90,211,165,75,39,105,210,
164,145,224,224,96,21,21,137,13,166,243,231,207,171,28,209,191,255,254,91,174,93,187,166,118,133,177,99,90,189,122,117,73,158,60,185,186,150,255,121,38,64,199,211,51,151,7,142,194,169,68,34,53,254,225,
195,136,55,34,151,46,93,18,188,9,65,157,163,167,159,126,90,41,100,225,77,199,142,29,59,228,167,159,126,82,18,212,23,47,94,84,59,165,168,27,10,135,212,68,103,20,37,84,58,118,236,40,25,51,102,188,199,4,
191,160,112,170,59,116,232,32,173,90,181,186,119,156,223,144,0,9,144,0,9,144,0,9,144,0,9,248,23,1,60,247,149,46,93,90,69,1,66,152,51,170,193,233,130,83,138,127,166,180,232,78,38,242,60,17,30,139,77,150,
36,73,146,40,231,18,161,197,37,75,150,20,228,100,34,18,242,200,145,35,234,185,31,155,77,127,254,249,167,138,134,132,160,38,158,235,241,15,41,122,38,167,211,57,125,223,232,120,122,145,56,98,227,79,156,
56,113,207,25,197,238,32,62,180,40,20,11,103,20,181,132,106,214,172,233,218,157,81,56,218,139,22,45,146,94,189,122,61,64,169,123,247,238,42,164,120,221,186,117,15,28,231,15,36,64,2,36,64,2,36,64,2,36,
64,2,254,71,0,59,125,72,61,67,189,246,232,33,183,136,12,124,230,153,103,164,84,169,82,174,91,116,148,147,137,48,97,108,10,97,131,8,187,149,158,156,76,68,53,178,121,159,0,29,79,239,51,126,96,134,232,206,
232,214,173,91,213,206,168,91,157,209,158,61,123,10,118,60,83,166,76,121,111,13,155,55,111,86,187,156,200,103,133,243,204,70,2,36,64,2,36,64,2,36,64,2,36,224,255,4,32,150,3,93,143,141,27,55,74,226,196,
137,213,130,241,92,139,13,137,81,163,70,61,162,5,226,36,17,58,153,78,210,142,255,92,116,60,227,207,206,182,43,99,235,140,86,168,80,193,118,201,103,221,34,80,115,8,138,188,72,146,142,106,8,169,64,136,237,
123,239,189,39,161,161,161,81,135,249,149,4,72,128,4,72,128,4,72,128,4,72,192,207,9,64,120,7,161,168,248,55,108,216,176,123,171,133,192,206,146,37,75,30,209,3,185,119,130,205,223,208,201,180,25,168,131,
195,209,241,116,16,118,92,166,130,51,10,149,45,228,140,98,103,20,59,141,158,118,70,189,225,140,34,143,21,161,19,253,250,245,123,192,100,56,155,169,82,165,82,125,15,116,240,7,18,32,1,18,32,1,18,32,1,18,
32,1,191,39,0,241,77,108,74,76,154,52,233,129,205,137,169,83,167,170,252,71,56,165,118,54,56,153,7,15,30,20,132,203,226,121,56,122,184,44,52,86,162,114,50,75,148,40,161,4,64,237,156,155,99,217,79,128,
142,167,253,76,189,54,98,108,156,209,40,1,163,44,89,178,196,203,142,219,183,111,11,66,108,17,50,1,149,222,168,134,48,138,77,155,54,41,185,105,56,159,108,36,64,2,36,64,2,36,64,2,36,64,2,129,71,0,121,158,
93,187,118,149,101,203,150,41,161,205,40,2,120,126,132,46,72,124,83,177,232,100,70,145,244,223,175,116,60,13,191,183,118,58,163,112,58,223,126,251,109,9,15,15,87,42,93,81,104,240,51,222,52,109,216,176,
193,177,80,223,168,185,249,149,4,72,128,4,72,128,4,72,128,4,72,192,93,4,166,77,155,38,35,71,142,148,133,11,23,74,209,162,69,149,113,87,175,94,21,168,222,226,95,116,1,34,79,150,71,119,50,33,252,3,117,217,
40,225,159,232,59,153,80,151,77,155,54,173,167,33,120,204,64,2,116,60,13,188,105,49,153,172,115,70,83,167,78,253,136,154,46,118,70,81,46,6,181,58,255,250,235,47,105,221,186,181,228,200,145,67,77,129,63,
10,45,90,180,80,181,141,240,118,43,107,214,172,49,77,205,126,18,32,1,18,32,1,18,32,1,18,32,129,0,32,48,99,198,12,37,66,57,102,204,24,169,91,183,174,90,241,205,155,55,101,220,184,113,74,57,54,44,44,76,
61,59,90,57,153,65,65,65,82,169,82,165,123,37,76,232,100,250,247,7,135,142,167,127,223,223,123,171,131,51,122,236,216,177,7,114,70,81,139,20,225,180,136,213,239,209,163,135,170,69,26,117,1,222,60,53,106,
212,72,224,172,162,164,10,101,166,163,200,240,43,9,144,0,9,144,0,9,144,0,9,144,0,8,172,95,191,94,218,183,111,175,106,124,162,18,66,162,68,137,20,24,228,98,34,82,14,169,91,145,145,145,202,17,141,218,201,
68,233,21,238,100,6,230,231,135,142,103,96,222,119,181,106,56,163,120,75,53,113,226,68,41,82,164,136,244,233,211,71,133,210,34,108,2,59,160,77,154,52,81,2,67,81,146,217,1,140,138,75,39,1,18,32,1,18,32,
1,18,32,1,18,240,64,0,53,235,177,89,129,221,74,228,120,66,232,103,222,188,121,50,127,254,124,137,136,136,144,21,43,86,72,190,124,249,60,92,201,67,129,70,128,142,103,160,221,113,15,235,133,122,46,84,108,
33,133,13,169,236,194,133,11,75,183,110,221,164,76,153,50,30,206,230,33,18,32,1,18,32,1,18,32,1,18,32,1,18,184,79,0,58,33,19,38,76,144,175,190,250,74,206,156,57,163,28,77,164,111,213,169,83,231,129,122,
240,247,175,224,119,129,72,128,142,103,32,222,117,174,153,4,72,128,4,72,128,4,72,128,4,72,128,4,72,128,4,28,36,64,199,211,65,216,156,138,4,72,128,4,72,128,4,72,128,4,72,128,4,72,128,4,2,145,0,29,207,64,
188,235,92,51,9,144,0,9,144,0,9,144,0,9,144,0,9,144,0,9,56,72,128,142,167,131,176,57,21,9,144,0,9,144,0,9,144,0,9,144,0,9,144,0,9,4,34,1,58,158,129,120,215,185,102,18,32,1,18,32,1,18,32,1,18,32,1,18,32,
1,18,112,144,0,29,79,7,97,115,42,18,32,1,18,32,1,18,32,1,18,32,1,18,32,1,18,8,68,2,116,60,3,241,174,115,205,36,64,2,36,64,2,36,64,2,36,64,2,36,64,2,36,224,32,1,58,158,14,194,230,84,36,64,2,36,64,2,36,
64,2,36,64,2,36,64,2,36,16,136,4,232,120,6,226,93,231,154,73,128,4,72,128,4,72,128,4,72,128,4,72,128,4,72,192,65,2,116,60,29,132,205,169,72,128,4,72,128,4,72,128,4,72,128,4,72,128,4,72,32,16,9,208,241,
12,196,187,206,53,147,0,9,144,0,9,144,0,9,144,0,9,144,0,9,144,128,131,4,232,120,58,8,155,83,145,0,9,144,0,9,144,0,9,144,0,9,144,0,9,144,64,32,18,160,227,25,136,119,157,107,38,1,18,32,1,18,32,1,18,32,1,
18,32,1,18,32,1,7,9,208,241,116,16,54,167,34,1,18,32,1,18,32,1,18,32,1,18,32,1,18,32,129,64,36,64,199,51,16,239,58,215,76,2,36,64,2,36,64,2,36,64,2,36,64,2,36,64,2,14,18,160,227,233,32,108,78,69,2,36,
64,2,36,64,2,36,64,2,36,64,2,36,64,2,129,72,128,142,103,32,222,117,174,153,4,72,128,4,72,128,4,72,128,4,72,128,4,72,128,4,28,36,64,199,211,65,216,156,138,4,72,128,4,72,128,4,72,128,4,72,128,4,72,128,4,
2,145,0,29,207,64,188,235,92,51,9,144,0,9,144,0,9,144,0,9,144,0,9,144,0,9,56,72,128,142,167,131,176,57,21,9,144,0,9,144,0,9,144,0,9,144,0,9,144,0,9,4,34,1,58,158,129,120,215,185,102,18,32,1,18,32,1,18,
32,1,18,32,1,18,32,1,18,112,144,192,255,3,114,159,155,78,79,212,62,19,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* DualSense_UI::dualSense_png = (const char*) resource_DualSense_UI_dualSense_png;
const int DualSense_UI::dualSense_pngSize = 96461;


//[EndFile] You can add extra defines here...
//[/EndFile]

