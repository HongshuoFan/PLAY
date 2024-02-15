/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.10

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
    Left_Stick.reset(new StickGUI());
    addAndMakeVisible(Left_Stick.get());


    Right_Stick.reset(new StickGUI());
    addAndMakeVisible(Right_Stick.get());


    TouchPad.reset(new TouchPadGUI);
    addAndMakeVisible(TouchPad.get());

    Acc.reset(new vec3GUI);
    addAndMakeVisible(Acc.get());

    Gyo.reset(new vec3GUI);
    Gyo->setRange(-1000, 1000);
    addAndMakeVisible(Gyo.get());

    //[/Constructor_pre]

    juce__textButton_triangle.reset (new juce::TextButton ("triangle_button"));
    addAndMakeVisible (juce__textButton_triangle.get());
    juce__textButton_triangle->setButtonText (TRANS ("Triangle"));
    juce__textButton_triangle->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_circle.reset (new juce::TextButton ("circle_button"));
    addAndMakeVisible (juce__textButton_circle.get());
    juce__textButton_circle->setButtonText (TRANS ("Circle"));
    juce__textButton_circle->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_square.reset (new juce::TextButton ("square_button"));
    addAndMakeVisible (juce__textButton_square.get());
    juce__textButton_square->setButtonText (TRANS ("Square"));
    juce__textButton_square->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_cross.reset (new juce::TextButton ("cross_button"));
    addAndMakeVisible (juce__textButton_cross.get());
    juce__textButton_cross->setButtonText (TRANS ("Cross"));
    juce__textButton_cross->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_up.reset (new juce::TextButton ("up_button"));
    addAndMakeVisible (juce__textButton_up.get());
    juce__textButton_up->setButtonText (TRANS ("U"));
    juce__textButton_up->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_left.reset (new juce::TextButton ("left_button"));
    addAndMakeVisible (juce__textButton_left.get());
    juce__textButton_left->setButtonText (TRANS ("L"));
    juce__textButton_left->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_right.reset (new juce::TextButton ("right_button"));
    addAndMakeVisible (juce__textButton_right.get());
    juce__textButton_right->setButtonText (TRANS ("R"));
    juce__textButton_right->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_down.reset (new juce::TextButton ("down_button"));
    addAndMakeVisible (juce__textButton_down.get());
    juce__textButton_down->setButtonText (TRANS ("D"));
    juce__textButton_down->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_l1.reset (new juce::TextButton ("l1_button"));
    addAndMakeVisible (juce__textButton_l1.get());
    juce__textButton_l1->setButtonText (TRANS ("l1"));
    juce__textButton_l1->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_r1.reset (new juce::TextButton ("r1_button"));
    addAndMakeVisible (juce__textButton_r1.get());
    juce__textButton_r1->setButtonText (TRANS ("r1"));
    juce__textButton_r1->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_Select.reset (new juce::TextButton ("Select_button"));
    addAndMakeVisible (juce__textButton_Select.get());
    juce__textButton_Select->setButtonText (TRANS ("Select"));
    juce__textButton_Select->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_menu.reset (new juce::TextButton ("menu_button"));
    addAndMakeVisible (juce__textButton_menu.get());
    juce__textButton_menu->setButtonText (TRANS ("Menu"));
    juce__textButton_menu->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__slider_L_Trigger.reset (new juce::Slider ("L_Trigger"));
    addAndMakeVisible (juce__slider_L_Trigger.get());
    juce__slider_L_Trigger->setRange (0, 1, 0.01);
    juce__slider_L_Trigger->setSliderStyle (juce::Slider::LinearVertical);
    juce__slider_L_Trigger->setTextBoxStyle (juce::Slider::TextBoxBelow, true, 60, 20);

    juce__slider_R_Trigger.reset (new juce::Slider ("R_Trigger"));
    addAndMakeVisible (juce__slider_R_Trigger.get());
    juce__slider_R_Trigger->setRange (0, 1, 0.01);
    juce__slider_R_Trigger->setSliderStyle (juce::Slider::LinearVertical);
    juce__slider_R_Trigger->setTextBoxStyle (juce::Slider::TextBoxBelow, true, 60, 20);

    juce__toggleButton_IMU.reset (new juce::ToggleButton ("toggleButton_IMU"));
    addAndMakeVisible (juce__toggleButton_IMU.get());
    juce__toggleButton_IMU->setButtonText (TRANS ("IMU"));
    juce__toggleButton_IMU->addListener (this);

    juce__toggleButton_IMU->setBounds (108, 278, 71, 24);

    juce__slider_force_Trigger.reset (new juce::Slider ("Trigger_force"));
    addAndMakeVisible (juce__slider_force_Trigger.get());
    juce__slider_force_Trigger->setRange (0, 1, 0.01);
    juce__slider_force_Trigger->setSliderStyle (juce::Slider::LinearVertical);
    juce__slider_force_Trigger->setTextBoxStyle (juce::Slider::TextBoxBelow, true, 60, 20);
    juce__slider_force_Trigger->addListener (this);

    juce__textButton_UpdateTrigger.reset (new juce::TextButton ("UpdateTrigger_button"));
    addAndMakeVisible (juce__textButton_UpdateTrigger.get());
    juce__textButton_UpdateTrigger->setButtonText (TRANS ("UpdateTrigger"));
    juce__textButton_UpdateTrigger->addListener (this);
    juce__textButton_UpdateTrigger->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__toggleButton_vibration.reset (new juce::ToggleButton ("toggleButton_vibration"));
    addAndMakeVisible (juce__toggleButton_vibration.get());
    juce__toggleButton_vibration->setButtonText (TRANS ("Vibration"));
    juce__toggleButton_vibration->addListener (this);

    juce__toggleButton_vibration->setBounds (108, 247, 71, 24);

    juce__toggleButton_enableAll.reset (new juce::ToggleButton ("toggleButton_enableAll"));
    addAndMakeVisible (juce__toggleButton_enableAll.get());
    juce__toggleButton_enableAll->setButtonText (TRANS ("Dis/Enable All"));
    juce__toggleButton_enableAll->addListener (this);
    juce__toggleButton_enableAll->setToggleState (true, juce::dontSendNotification);

    juce__toggleButton_enableAll->setBounds (108, 216, 96, 24);

    juce__textButton.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (juce__textButton.get());
    juce__textButton->setButtonText (TRANS ("Change Device"));
    juce__textButton->addListener (this);
    juce__textButton->setColour (juce::TextButton::buttonColourId, juce::Colours::red);

    internalPath1.startNewSubPath (354.0f, 226.0f);
    internalPath1.lineTo (444.0f, 226.0f);
    internalPath1.quadraticTo (468.0f, 223.0f, 496.0f, 252.0f);
    internalPath1.lineTo (539.0f, 346.0f);
    internalPath1.quadraticTo (574.0f, 346.0f, 600.0f, 320.0f);
    internalPath1.lineTo (608.0f, 261.0f);
    internalPath1.quadraticTo (617.0f, 175.0f, 557.0f, 39.0f);
    internalPath1.lineTo (470.0f, 22.0f);
    internalPath1.quadraticTo (358.0f, 13.0f, 237.0f, 22.0f);
    internalPath1.lineTo (151.0f, 39.0f);
    internalPath1.quadraticTo (99.0f, 158.0f, 99.0f, 235.0f);
    internalPath1.lineTo (99.0f, 286.0f);
    internalPath1.lineTo (108.0f, 320.0f);
    internalPath1.quadraticTo (125.0f, 346.0f, 168.0f, 346.0f);
    internalPath1.quadraticTo (194.0f, 286.0f, 220.0f, 235.0f);
    internalPath1.quadraticTo (243.0f, 224.0f, 263.0f, 226.0f);
    internalPath1.closeSubPath();


    //[UserPreSize]
    //[/UserPreSize]

    setSize (700, 400);


    //[Constructor] You can add your own custom stuff here..
    setFramesPerSecond (1);
    isConnected = false;
    enableIMU = false;
    Acc->title = "Accelerometer";
    Gyo->title = "Gyrometer";
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
    juce__toggleButton_IMU = nullptr;
    juce__slider_force_Trigger = nullptr;
    juce__textButton_UpdateTrigger = nullptr;
    juce__toggleButton_vibration = nullptr;
    juce__toggleButton_enableAll = nullptr;
    juce__textButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    Left_Stick = nullptr;
    Right_Stick = nullptr;
    TouchPad = nullptr;
    Acc = nullptr;
    Gyo = nullptr;
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

    juce__textButton_triangle->setBounds (proportionOfWidth (0.7057f), proportionOfHeight (0.1950f), proportionOfWidth (0.0771f), proportionOfHeight (0.0525f));
    juce__textButton_circle->setBounds (proportionOfWidth (0.7686f), proportionOfHeight (0.2825f), proportionOfWidth (0.0643f), proportionOfHeight (0.0525f));
    juce__textButton_square->setBounds (proportionOfWidth (0.6557f), proportionOfHeight (0.2825f), proportionOfWidth (0.0671f), proportionOfHeight (0.0525f));
    juce__textButton_cross->setBounds (proportionOfWidth (0.7157f), proportionOfHeight (0.3675f), proportionOfWidth (0.0671f), proportionOfHeight (0.0550f));
    juce__textButton_up->setBounds (proportionOfWidth (0.2386f), proportionOfHeight (0.2125f), proportionOfWidth (0.0414f), proportionOfHeight (0.0425f));
    juce__textButton_left->setBounds (proportionOfWidth (0.1971f), proportionOfHeight (0.2825f), proportionOfWidth (0.0414f), proportionOfHeight (0.0425f));
    juce__textButton_right->setBounds (proportionOfWidth (0.2771f), proportionOfHeight (0.2825f), proportionOfWidth (0.0414f), proportionOfHeight (0.0425f));
    juce__textButton_down->setBounds (proportionOfWidth (0.2386f), proportionOfHeight (0.3575f), proportionOfWidth (0.0414f), proportionOfHeight (0.0425f));
    juce__textButton_l1->setBounds (proportionOfWidth (0.2200f), proportionOfHeight (0.0250f), proportionOfWidth (0.0600f), proportionOfHeight (0.0525f));
    juce__textButton_r1->setBounds (proportionOfWidth (0.7200f), proportionOfHeight (0.0250f), proportionOfWidth (0.0600f), proportionOfHeight (0.0525f));
    juce__textButton_Select->setBounds (proportionOfWidth (0.2943f), proportionOfHeight (0.1375f), proportionOfWidth (0.0414f), proportionOfHeight (0.0325f));
    juce__textButton_menu->setBounds (proportionOfWidth (0.6614f), proportionOfHeight (0.1425f), proportionOfWidth (0.0414f), proportionOfHeight (0.0325f));
    juce__slider_L_Trigger->setBounds (proportionOfWidth (0.0100f), proportionOfHeight (0.2075f), proportionOfWidth (0.1000f), proportionOfHeight (0.5000f));
    juce__slider_R_Trigger->setBounds (proportionOfWidth (0.8857f), proportionOfHeight (0.2075f), proportionOfWidth (0.1000f), proportionOfHeight (0.5000f));
    juce__slider_force_Trigger->setBounds (proportionOfWidth (0.7571f), proportionOfHeight (0.4300f), proportionOfWidth (0.0729f), proportionOfHeight (0.3275f));
    juce__textButton_UpdateTrigger->setBounds (proportionOfWidth (0.7414f), proportionOfHeight (0.7675f), proportionOfWidth (0.1086f), proportionOfHeight (0.0550f));
    juce__textButton->setBounds (proportionOfWidth (0.8586f), proportionOfHeight (0.0175f), 89, 19);
    //[UserResized] Add your own custom resize handling here..
    Left_Stick->setBounds (proportionOfWidth (0.32f), proportionOfHeight (0.33f), proportionOfWidth (0.13f), proportionOfHeight (0.22f));
    Right_Stick->setBounds (proportionOfWidth (0.53f), proportionOfHeight (0.33f), proportionOfWidth (0.13f), proportionOfHeight (0.22f));
    TouchPad->setBounds (proportionOfWidth (0.345f), proportionOfHeight (0.06f), proportionOfWidth (0.3f), proportionOfHeight (0.265f));
    Acc->setBounds (proportionOfWidth (0.29f), proportionOfHeight (0.58f), proportionOfWidth (0.2f), proportionOfHeight (0.4f));
    Gyo->setBounds (proportionOfWidth (0.51f), proportionOfHeight (0.58f), proportionOfWidth (0.2f), proportionOfHeight (0.4f));

    //[/UserResized]
}

void DualSense_UI::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == juce__toggleButton_IMU.get())
    {
        //[UserButtonCode_juce__toggleButton_IMU] -- add your button handler code here..
        enableIMU = juce__toggleButton_IMU->getToggleState();
        //[/UserButtonCode_juce__toggleButton_IMU]
    }
    else if (buttonThatWasClicked == juce__textButton_UpdateTrigger.get())
    {
        //[UserButtonCode_juce__textButton_UpdateTrigger] -- add your button handler code here..
        UpdateTriggerForce();
        //[/UserButtonCode_juce__textButton_UpdateTrigger]
    }
    else if (buttonThatWasClicked == juce__toggleButton_vibration.get())
    {
        //[UserButtonCode_juce__toggleButton_vibration] -- add your button handler code here..
        virbration = juce__toggleButton_vibration->getToggleState();
        UpdateVibration();
        //[/UserButtonCode_juce__toggleButton_vibration]
    }
    else if (buttonThatWasClicked == juce__toggleButton_enableAll.get())
    {
        //[UserButtonCode_juce__toggleButton_enableAll] -- add your button handler code here..
        bool new_state = juce__toggleButton_enableAll->getToggleState();
        Left_Stick->changeStates(new_state);
        Right_Stick->changeStates(new_state);
        TouchPad->changeStates(new_state);
        Acc->changeStates(new_state);
        Gyo->changeStates(new_state);
        //[/UserButtonCode_juce__toggleButton_enableAll]
    }
    else if (buttonThatWasClicked == juce__textButton.get())
    {
        //[UserButtonCode_juce__textButton] -- add your button handler code here..
        changeDevice();
        //[/UserButtonCode_juce__textButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void DualSense_UI::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == juce__slider_force_Trigger.get())
    {
        //[UserSliderCode_juce__slider_force_Trigger] -- add your slider handling code here..
        triggerForce = juce__slider_force_Trigger->getValue();
        //[/UserSliderCode_juce__slider_force_Trigger]
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

        Left_Stick->updatePoint(DS_UI_input.leftStick.x, DS_UI_input.leftStick.y, DS_UI_input.leftStick.stickPress);
        Right_Stick->updatePoint(DS_UI_input.rightStick.x, DS_UI_input.rightStick.y, DS_UI_input.rightStick.stickPress);

        DS_EnableStats.leftStickStates.x = Left_Stick->enableX;
        DS_EnableStats.leftStickStates.y = Left_Stick->enableY;

        DS_EnableStats.rightStickStates.x = Right_Stick->enableX;
        DS_EnableStats.rightStickStates.y = Right_Stick->enableY;

        juce__slider_L_Trigger->setValue(std::clamp(DS_UI_input.leftTrigger, 0.f, 1.0f));
        juce__slider_R_Trigger->setValue(std::clamp(DS_UI_input.rightTrigger, 0.f, 1.0f));

        TouchPad->updateTouchPad_1(DS_UI_input.touchPoint1);
        TouchPad->updateTouchPad_2(DS_UI_input.touchPoint2);
        TouchPad->pressTouchPad = DS_UI_input.buttons.touchPad;

        DS_EnableStats.touchPoint1States.x = TouchPad->isP1Enable_x;
        DS_EnableStats.touchPoint1States.y = TouchPad->isP1Enable_y;

        DS_EnableStats.touchPoint2States.x = TouchPad->isP2Enable_x;
        DS_EnableStats.touchPoint2States.y = TouchPad->isP2Enable_y;

        Acc->updateSliders(DS_UI_input.accelerometer.x, DS_UI_input.accelerometer.y, DS_UI_input.accelerometer.z);
        Gyo->updateSliders(DS_UI_input.gyroscope.x, DS_UI_input.gyroscope.y, DS_UI_input.gyroscope.z);

        DS_EnableStats.Acc_states.x = Acc->is_x_enable;
        DS_EnableStats.Acc_states.y = Acc->is_y_enable;
        DS_EnableStats.Acc_states.z = Acc->is_z_enable;

        DS_EnableStats.Gyo_states.x = Gyo->is_x_enable;
        DS_EnableStats.Gyo_states.y = Gyo->is_y_enable;
        DS_EnableStats.Gyo_states.z = Gyo->is_z_enable;
//        juce__slider_acc_x->setValue(std::clamp(DS_UI_input.accelerometer.x, -1.0f, 1.0f));
//        juce__slider_acc_y->setValue(std::clamp(DS_UI_input.accelerometer.y, -1.0f, 1.0f));
//        juce__slider_acc_z->setValue(std::clamp(DS_UI_input.accelerometer.z, -1.0f, 1.0f));
//
//        juce__slider_gyr_x->setValue(std::clamp(DS_UI_input.gyroscope.x, -1000.0f, 1000.0f));
//        juce__slider_gyr_y->setValue(std::clamp(DS_UI_input.gyroscope.y, -1000.0f, 1000.0f));
//        juce__slider_gyr_z->setValue(std::clamp(DS_UI_input.gyroscope.z, -1000.0f, 1000.0f));

    }else{
        setFramesPerSecond(1);
    }

}
//
//static float _clamp(float v, float min, float max)
//{
//    return fmax(min, fmin(v, max));
//}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="DualSense_UI" componentName=""
                 parentClasses="public juce::AnimatedAppComponent" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="0" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="700" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44">
    <PATH pos="0 0 100 100" fill="solid: edfdff" hasStroke="1" stroke="3, mitered, butt"
          strokeColour="solid: ff6495ed" nonZeroWinding="1">s 353.68 226.46 l 444.33 226.46 q 468.08 223.26 496.13 252.08 l 539.3 346 q 573.83 346 599.73 320.38 l 608.37 260.62 q 617 175.23 556.57 38.62 l 470.23 21.54 q 358 13 237.13 21.54 l 150.8 38.62 q 99 158.15 99 235 l 99 286.23 l 107.63 320.38 q 124.9 346 168.07 346 q 193.97 286.23 219.87 235 q 242.53 224.33 263.03 226.46 x</PATH>
  </BACKGROUND>
  <TEXTBUTTON name="triangle_button" id="adfc8a3c333c90c1" memberName="juce__textButton_triangle"
              virtualName="" explicitFocusOrder="0" pos="70.571% 19.5% 7.714% 5.25%"
              bgColOn="ff5f9ea0" buttonText="Triangle" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="circle_button" id="37d4661129ea5fa4" memberName="juce__textButton_circle"
              virtualName="" explicitFocusOrder="0" pos="76.857% 28.25% 6.429% 5.25%"
              bgColOn="ff5f9ea0" buttonText="Circle" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="square_button" id="664054e5b09e5f11" memberName="juce__textButton_square"
              virtualName="" explicitFocusOrder="0" pos="65.571% 28.25% 6.714% 5.25%"
              bgColOn="ff5f9ea0" buttonText="Square" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="cross_button" id="1530d958f2eea907" memberName="juce__textButton_cross"
              virtualName="" explicitFocusOrder="0" pos="71.571% 36.75% 6.714% 5.5%"
              bgColOn="ff5f9ea0" buttonText="Cross" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="up_button" id="803a38bfe0c5cf5a" memberName="juce__textButton_up"
              virtualName="" explicitFocusOrder="0" pos="23.857% 21.25% 4.143% 4.25%"
              bgColOn="ff5f9ea0" buttonText="U" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="left_button" id="6e161f21a51340d7" memberName="juce__textButton_left"
              virtualName="" explicitFocusOrder="0" pos="19.714% 28.25% 4.143% 4.25%"
              bgColOn="ff5f9ea0" buttonText="L" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="right_button" id="348faaa33173332b" memberName="juce__textButton_right"
              virtualName="" explicitFocusOrder="0" pos="27.714% 28.25% 4.143% 4.25%"
              bgColOn="ff5f9ea0" buttonText="R" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="down_button" id="12403ef0daaaeefa" memberName="juce__textButton_down"
              virtualName="" explicitFocusOrder="0" pos="23.857% 35.75% 4.143% 4.25%"
              bgColOn="ff5f9ea0" buttonText="D" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="l1_button" id="4da68bd4fbe75348" memberName="juce__textButton_l1"
              virtualName="" explicitFocusOrder="0" pos="22% 2.5% 6% 5.25%"
              bgColOn="ff5f9ea0" buttonText="l1" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="r1_button" id="afad88da9b7b5250" memberName="juce__textButton_r1"
              virtualName="" explicitFocusOrder="0" pos="72% 2.5% 6% 5.25%"
              bgColOn="ff5f9ea0" buttonText="r1" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="Select_button" id="3a3507360c48e793" memberName="juce__textButton_Select"
              virtualName="" explicitFocusOrder="0" pos="29.429% 13.75% 4.143% 3.25%"
              bgColOn="ff5f9ea0" buttonText="Select" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="menu_button" id="476fde5307adb33" memberName="juce__textButton_menu"
              virtualName="" explicitFocusOrder="0" pos="66.143% 14.25% 4.143% 3.25%"
              bgColOn="ff5f9ea0" buttonText="Menu" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <SLIDER name="L_Trigger" id="108db3ed35a76737" memberName="juce__slider_L_Trigger"
          virtualName="" explicitFocusOrder="0" pos="1% 20.75% 10% 50%"
          min="0.0" max="1.0" int="0.01" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="60" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="R_Trigger" id="e9ba45a333eabc57" memberName="juce__slider_R_Trigger"
          virtualName="" explicitFocusOrder="0" pos="88.571% 20.75% 10% 50%"
          min="0.0" max="1.0" int="0.01" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="60" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <TOGGLEBUTTON name="toggleButton_IMU" id="fc92f293dfd205b2" memberName="juce__toggleButton_IMU"
                virtualName="" explicitFocusOrder="0" pos="108 278 71 24" buttonText="IMU"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <SLIDER name="Trigger_force" id="a625551f52222742" memberName="juce__slider_force_Trigger"
          virtualName="" explicitFocusOrder="0" pos="75.714% 43% 7.286% 32.75%"
          min="0.0" max="1.0" int="0.01" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="60" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <TEXTBUTTON name="UpdateTrigger_button" id="9145f1204ec28b2e" memberName="juce__textButton_UpdateTrigger"
              virtualName="" explicitFocusOrder="0" pos="74.143% 76.75% 10.857% 5.5%"
              bgColOn="ff5f9ea0" buttonText="UpdateTrigger" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="toggleButton_vibration" id="1c127cb27174cff6" memberName="juce__toggleButton_vibration"
                virtualName="" explicitFocusOrder="0" pos="108 247 71 24" buttonText="Vibration"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="toggleButton_enableAll" id="8bcdf7461574a259" memberName="juce__toggleButton_enableAll"
                virtualName="" explicitFocusOrder="0" pos="108 216 96 24" buttonText="Dis/Enable All"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TEXTBUTTON name="new button" id="22ebb74a08c1917" memberName="juce__textButton"
              virtualName="" explicitFocusOrder="0" pos="85.857% 1.75% 89 19"
              bgColOff="ffff0000" buttonText="Change Device" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

