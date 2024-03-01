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

#include "JoyCon_UI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
JoyCon_UI::JoyCon_UI ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    Left_Stick.reset(new StickGUI());
    addAndMakeVisible(Left_Stick.get());

    Right_Stick.reset(new StickGUI());
    addAndMakeVisible(Right_Stick.get());

    Left_Acc.reset(new vec3GUI());
    Left_Acc->title = "Accelerometer";
    Left_Acc->setRange(-1.f, 1.f);
    addAndMakeVisible(Left_Acc.get());

    Left_Gyo.reset(new vec3GUI());
    Left_Gyo->title = "Gyrometer";
    Left_Gyo->setRange(-1000.f, 1000.f);
    addAndMakeVisible(Left_Gyo.get());

    Right_Acc.reset(new vec3GUI());
    Right_Acc->title = "Accelerometer";
    Right_Acc->setRange(-1.f, 1.f);
    addAndMakeVisible(Right_Acc.get());

    Right_Gyo.reset(new vec3GUI());
    Right_Gyo->title = "Gyrometer";
    Right_Gyo->setRange(-1000.f, 1000.f);
    addAndMakeVisible(Right_Gyo.get());
    //[/Constructor_pre]

    juce__textButton_zl.reset (new juce::TextButton ("zl_button"));
    addAndMakeVisible (juce__textButton_zl.get());
    juce__textButton_zl->setButtonText (TRANS ("ZL"));
    juce__textButton_zl->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_l.reset (new juce::TextButton ("l_button"));
    addAndMakeVisible (juce__textButton_l.get());
    juce__textButton_l->setButtonText (TRANS ("L"));
    juce__textButton_l->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_minus.reset (new juce::TextButton ("minus_button"));
    addAndMakeVisible (juce__textButton_minus.get());
    juce__textButton_minus->setButtonText (TRANS ("-"));
    juce__textButton_minus->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_capture.reset (new juce::TextButton ("capture_button"));
    addAndMakeVisible (juce__textButton_capture.get());
    juce__textButton_capture->setButtonText (TRANS ("Capture"));
    juce__textButton_capture->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_UP.reset (new juce::TextButton ("up_button"));
    addAndMakeVisible (juce__textButton_UP.get());
    juce__textButton_UP->setButtonText (TRANS ("Up"));
    juce__textButton_UP->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_Left.reset (new juce::TextButton ("left_button"));
    addAndMakeVisible (juce__textButton_Left.get());
    juce__textButton_Left->setButtonText (TRANS ("Left"));
    juce__textButton_Left->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_right.reset (new juce::TextButton ("right_button"));
    addAndMakeVisible (juce__textButton_right.get());
    juce__textButton_right->setButtonText (TRANS ("Right"));
    juce__textButton_right->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_down.reset (new juce::TextButton ("down_button"));
    addAndMakeVisible (juce__textButton_down.get());
    juce__textButton_down->setButtonText (TRANS ("Down"));
    juce__textButton_down->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_sl_l.reset (new juce::TextButton ("sl_button"));
    addAndMakeVisible (juce__textButton_sl_l.get());
    juce__textButton_sl_l->setButtonText (TRANS ("SL"));
    juce__textButton_sl_l->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_sr_l.reset (new juce::TextButton ("sr_button"));
    addAndMakeVisible (juce__textButton_sr_l.get());
    juce__textButton_sr_l->setButtonText (TRANS ("SR"));
    juce__textButton_sr_l->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_zr.reset (new juce::TextButton ("zr_button"));
    addAndMakeVisible (juce__textButton_zr.get());
    juce__textButton_zr->setButtonText (TRANS ("ZR"));
    juce__textButton_zr->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_r.reset (new juce::TextButton ("r_button"));
    addAndMakeVisible (juce__textButton_r.get());
    juce__textButton_r->setButtonText (TRANS ("R"));
    juce__textButton_r->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_plus.reset (new juce::TextButton ("plus_button"));
    addAndMakeVisible (juce__textButton_plus.get());
    juce__textButton_plus->setButtonText (TRANS ("+"));
    juce__textButton_plus->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_sr_r.reset (new juce::TextButton ("sr_button"));
    addAndMakeVisible (juce__textButton_sr_r.get());
    juce__textButton_sr_r->setButtonText (TRANS ("SR"));
    juce__textButton_sr_r->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_sl_r.reset (new juce::TextButton ("sl_button"));
    addAndMakeVisible (juce__textButton_sl_r.get());
    juce__textButton_sl_r->setButtonText (TRANS ("SL"));
    juce__textButton_sl_r->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_x.reset (new juce::TextButton ("x_button"));
    addAndMakeVisible (juce__textButton_x.get());
    juce__textButton_x->setButtonText (TRANS ("X"));
    juce__textButton_x->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_y.reset (new juce::TextButton ("y_button"));
    addAndMakeVisible (juce__textButton_y.get());
    juce__textButton_y->setButtonText (TRANS ("Y"));
    juce__textButton_y->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_a.reset (new juce::TextButton ("a_button"));
    addAndMakeVisible (juce__textButton_a.get());
    juce__textButton_a->setButtonText (TRANS ("A"));
    juce__textButton_a->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_b.reset (new juce::TextButton ("b_button"));
    addAndMakeVisible (juce__textButton_b.get());
    juce__textButton_b->setButtonText (TRANS ("B"));
    juce__textButton_b->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_home.reset (new juce::TextButton ("home_button"));
    addAndMakeVisible (juce__textButton_home.get());
    juce__textButton_home->setButtonText (TRANS ("Home"));
    juce__textButton_home->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__toggleButton_L_IMU.reset (new juce::ToggleButton ("Left_JC_IMU_toggle"));
    addAndMakeVisible (juce__toggleButton_L_IMU.get());
    juce__toggleButton_L_IMU->setButtonText (TRANS ("Left IMU"));
    juce__toggleButton_L_IMU->addListener (this);

    juce__toggleButton_R_IMU.reset (new juce::ToggleButton ("Right_JC_IMU_toggle"));
    addAndMakeVisible (juce__toggleButton_R_IMU.get());
    juce__toggleButton_R_IMU->setButtonText (TRANS ("Right IMU"));
    juce__toggleButton_R_IMU->addListener (this);

    juce__textButton_L_Virb.reset (new juce::TextButton ("L_Virb_button"));
    addAndMakeVisible (juce__textButton_L_Virb.get());
    juce__textButton_L_Virb->setButtonText (TRANS ("vib"));
    juce__textButton_L_Virb->addListener (this);
    juce__textButton_L_Virb->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_R_Virb.reset (new juce::TextButton ("R_Virb_button"));
    addAndMakeVisible (juce__textButton_R_Virb.get());
    juce__textButton_R_Virb->setButtonText (TRANS ("vib"));
    juce__textButton_R_Virb->addListener (this);
    juce__textButton_R_Virb->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__toggleButton_dis_enableAll.reset (new juce::ToggleButton ("dis_enableAll_toggle"));
    addAndMakeVisible (juce__toggleButton_dis_enableAll.get());
    juce__toggleButton_dis_enableAll->setButtonText (TRANS ("Dis/Enable All"));
    juce__toggleButton_dis_enableAll->addListener (this);
    juce__toggleButton_dis_enableAll->setToggleState (true, juce::dontSendNotification);

    juce__textButton_ChangeDevice.reset (new juce::TextButton ("ChangeDevice_button"));
    addAndMakeVisible (juce__textButton_ChangeDevice.get());
    juce__textButton_ChangeDevice->setButtonText (TRANS ("Change Device"));
    juce__textButton_ChangeDevice->addListener (this);
    juce__textButton_ChangeDevice->setColour (juce::TextButton::buttonColourId, juce::Colours::red);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (700, 400);


    //[Constructor] You can add your own custom stuff here..
    setFramesPerSecond (1);
    //[/Constructor]
}

JoyCon_UI::~JoyCon_UI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    juce__textButton_zl = nullptr;
    juce__textButton_l = nullptr;
    juce__textButton_minus = nullptr;
    juce__textButton_capture = nullptr;
    juce__textButton_UP = nullptr;
    juce__textButton_Left = nullptr;
    juce__textButton_right = nullptr;
    juce__textButton_down = nullptr;
    juce__textButton_sl_l = nullptr;
    juce__textButton_sr_l = nullptr;
    juce__textButton_zr = nullptr;
    juce__textButton_r = nullptr;
    juce__textButton_plus = nullptr;
    juce__textButton_sr_r = nullptr;
    juce__textButton_sl_r = nullptr;
    juce__textButton_x = nullptr;
    juce__textButton_y = nullptr;
    juce__textButton_a = nullptr;
    juce__textButton_b = nullptr;
    juce__textButton_home = nullptr;
    juce__toggleButton_L_IMU = nullptr;
    juce__toggleButton_R_IMU = nullptr;
    juce__textButton_L_Virb = nullptr;
    juce__textButton_R_Virb = nullptr;
    juce__toggleButton_dis_enableAll = nullptr;
    juce__textButton_ChangeDevice = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    Left_Stick  = nullptr;
    Right_Stick = nullptr;
    Left_Acc = nullptr;
    Left_Gyo = nullptr;
    Right_Acc = nullptr;
    Right_Gyo = nullptr;
    //[/Destructor]
}

//==============================================================================
void JoyCon_UI::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    {
        float x = 0, y = 0;
        juce::Colour strokeColour = juce::Colours::crimson;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.strokePath (internalPath1, juce::PathStrokeType (2.000f), juce::AffineTransform::translation (x, y));
    }

    {
        float x = 0, y = 0;
        juce::Colour strokeColour = juce::Colours::cornflowerblue;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.strokePath (internalPath2, juce::PathStrokeType (2.000f), juce::AffineTransform::translation (x, y));
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void JoyCon_UI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    juce__textButton_zl->setBounds (proportionOfWidth (0.2500f), proportionOfHeight (0.0350f), proportionOfWidth (0.0586f), proportionOfHeight (0.0475f));
    juce__textButton_l->setBounds (proportionOfWidth (0.3386f), proportionOfHeight (0.0150f), proportionOfWidth (0.0586f), proportionOfHeight (0.0475f));
    juce__textButton_minus->setBounds (proportionOfWidth (0.3543f), proportionOfHeight (0.0900f), proportionOfWidth (0.0457f), proportionOfHeight (0.0375f));
    juce__textButton_capture->setBounds (proportionOfWidth (0.3414f), proportionOfHeight (0.8350f), proportionOfWidth (0.0600f), proportionOfHeight (0.0400f));
    juce__textButton_UP->setBounds (proportionOfWidth (0.3029f), proportionOfHeight (0.5275f), proportionOfWidth (0.0514f), proportionOfHeight (0.0400f));
    juce__textButton_Left->setBounds (proportionOfWidth (0.2529f), proportionOfHeight (0.6000f), proportionOfWidth (0.0514f), proportionOfHeight (0.0400f));
    juce__textButton_right->setBounds (proportionOfWidth (0.3486f), proportionOfHeight (0.6000f), proportionOfWidth (0.0514f), proportionOfHeight (0.0400f));
    juce__textButton_down->setBounds (proportionOfWidth (0.3029f), proportionOfHeight (0.6775f), proportionOfWidth (0.0514f), proportionOfHeight (0.0400f));
    juce__textButton_sl_l->setBounds (proportionOfWidth (0.4200f), proportionOfHeight (0.1600f), proportionOfWidth (0.0500f), proportionOfHeight (0.1000f));
    juce__textButton_sr_l->setBounds (proportionOfWidth (0.4200f), proportionOfHeight (0.6600f), proportionOfWidth (0.0500f), proportionOfHeight (0.1000f));
    juce__textButton_zr->setBounds (proportionOfWidth (0.7000f), proportionOfHeight (0.0350f), proportionOfWidth (0.0586f), proportionOfHeight (0.0475f));
    juce__textButton_r->setBounds (proportionOfWidth (0.6143f), proportionOfHeight (0.0150f), proportionOfWidth (0.0586f), proportionOfHeight (0.0475f));
    juce__textButton_plus->setBounds (proportionOfWidth (0.6114f), proportionOfHeight (0.0900f), proportionOfWidth (0.0414f), proportionOfHeight (0.0475f));
    juce__textButton_sr_r->setBounds (proportionOfWidth (0.5400f), proportionOfHeight (0.1600f), proportionOfWidth (0.0500f), proportionOfHeight (0.1000f));
    juce__textButton_sl_r->setBounds (proportionOfWidth (0.5400f), proportionOfHeight (0.6600f), proportionOfWidth (0.0500f), proportionOfHeight (0.1000f));
    juce__textButton_x->setBounds (proportionOfWidth (0.6671f), proportionOfHeight (0.2050f), proportionOfWidth (0.0514f), proportionOfHeight (0.0400f));
    juce__textButton_y->setBounds (proportionOfWidth (0.6200f), proportionOfHeight (0.2775f), proportionOfWidth (0.0514f), proportionOfHeight (0.0400f));
    juce__textButton_a->setBounds (proportionOfWidth (0.7100f), proportionOfHeight (0.2775f), proportionOfWidth (0.0514f), proportionOfHeight (0.0400f));
    juce__textButton_b->setBounds (proportionOfWidth (0.6671f), proportionOfHeight (0.3475f), proportionOfWidth (0.0514f), proportionOfHeight (0.0400f));
    juce__textButton_home->setBounds (proportionOfWidth (0.6114f), proportionOfHeight (0.8350f), proportionOfWidth (0.0600f), proportionOfHeight (0.0400f));
    juce__toggleButton_L_IMU->setBounds (proportionOfWidth (0.4429f), proportionOfHeight (0.3500f), 82, 24);
    juce__toggleButton_R_IMU->setBounds (proportionOfWidth (0.4429f), proportionOfHeight (0.5000f), 82, 24);
    juce__textButton_L_Virb->setBounds (proportionOfWidth (0.4171f), proportionOfHeight (0.8700f), proportionOfWidth (0.0600f), proportionOfHeight (0.0650f));
    juce__textButton_R_Virb->setBounds (proportionOfWidth (0.5329f), proportionOfHeight (0.8700f), proportionOfWidth (0.0614f), proportionOfHeight (0.0625f));
    juce__toggleButton_dis_enableAll->setBounds (proportionOfWidth (0.4429f), proportionOfHeight (0.0250f), 100, 24);
    juce__textButton_ChangeDevice->setBounds (proportionOfWidth (0.8657f), proportionOfHeight (0.0250f), 89, 19);
    internalPath1.clear();
    internalPath1.startNewSubPath (static_cast<float> (proportionOfWidth (0.4133f)), static_cast<float> (proportionOfHeight (0.8971f)));
    internalPath1.lineTo (static_cast<float> (proportionOfWidth (0.4133f)), static_cast<float> (proportionOfHeight (0.0265f)));
    internalPath1.quadraticTo (static_cast<float> (proportionOfWidth (0.2400f)), static_cast<float> (proportionOfHeight (0.0235f)), static_cast<float> (proportionOfWidth (0.2400f)), static_cast<float> (proportionOfHeight (0.1912f)));
    internalPath1.lineTo (static_cast<float> (proportionOfWidth (0.2400f)), static_cast<float> (proportionOfHeight (0.7323f)));
    internalPath1.quadraticTo (static_cast<float> (proportionOfWidth (0.2400f)), static_cast<float> (proportionOfHeight (0.9647f)), static_cast<float> (proportionOfWidth (0.4133f)), static_cast<float> (proportionOfHeight (0.9647f)));
    internalPath1.closeSubPath();

    internalPath2.clear();
    internalPath2.startNewSubPath (static_cast<float> (proportionOfWidth (0.6000f)), static_cast<float> (proportionOfHeight (0.9647f)));
    internalPath2.quadraticTo (static_cast<float> (proportionOfWidth (0.7733f)), static_cast<float> (proportionOfHeight (0.9882f)), static_cast<float> (proportionOfWidth (0.7733f)), static_cast<float> (proportionOfHeight (0.8000f)));
    internalPath2.lineTo (static_cast<float> (proportionOfWidth (0.7733f)), static_cast<float> (proportionOfHeight (0.2118f)));
    internalPath2.quadraticTo (static_cast<float> (proportionOfWidth (0.7733f)), static_cast<float> (proportionOfHeight (0.0000f)), static_cast<float> (proportionOfWidth (0.6000f)), static_cast<float> (proportionOfHeight (0.0235f)));
    internalPath2.closeSubPath();

    //[UserResized] Add your own custom resize handling here..
    Left_Stick->setBounds (proportionOfWidth (0.25f), proportionOfHeight (0.2f), proportionOfWidth (0.15f), proportionOfHeight (0.25f));
    Right_Stick->setBounds (proportionOfWidth (0.61f), proportionOfHeight (0.53f), proportionOfWidth (0.15f), proportionOfHeight (0.25f));
    Left_Acc->setBounds (proportionOfWidth (0.01f), proportionOfHeight (0.1f), proportionOfWidth (0.2f), proportionOfHeight (0.4f));
    Left_Gyo->setBounds (proportionOfWidth (0.01f), proportionOfHeight (0.51f), proportionOfWidth (0.2f), proportionOfHeight (0.4f));
    Right_Acc->setBounds (proportionOfWidth (0.78f), proportionOfHeight (0.1f), proportionOfWidth (0.2f), proportionOfHeight (0.4f));
    Right_Gyo->setBounds (proportionOfWidth (0.78f), proportionOfHeight (0.51f), proportionOfWidth (0.2f), proportionOfHeight (0.4f));
    //[/UserResized]
}

void JoyCon_UI::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == juce__toggleButton_L_IMU.get())
    {
        //[UserButtonCode_juce__toggleButton_L_IMU] -- add your button handler code here..
        left_imu = juce__toggleButton_L_IMU->getToggleState();
        onLeftIMUChanged();
        //[/UserButtonCode_juce__toggleButton_L_IMU]
    }
    else if (buttonThatWasClicked == juce__toggleButton_R_IMU.get())
    {
        //[UserButtonCode_juce__toggleButton_R_IMU] -- add your button handler code here..
        right_imu = juce__toggleButton_R_IMU->getToggleState();
        onRightIMUChanged();
        //[/UserButtonCode_juce__toggleButton_R_IMU]
    }
    else if (buttonThatWasClicked == juce__textButton_L_Virb.get())
    {
        //[UserButtonCode_juce__textButton_L_Virb] -- add your button handler code here..
        onLeftVibration();
        //[/UserButtonCode_juce__textButton_L_Virb]
    }
    else if (buttonThatWasClicked == juce__textButton_R_Virb.get())
    {
        //[UserButtonCode_juce__textButton_R_Virb] -- add your button handler code here..
        onRightVibration();
        //[/UserButtonCode_juce__textButton_R_Virb]
    }
    else if (buttonThatWasClicked == juce__toggleButton_dis_enableAll.get())
    {
        //[UserButtonCode_juce__toggleButton_dis_enableAll] -- add your button handler code here..
        Left_Stick->changeStates(juce__toggleButton_dis_enableAll->getToggleState());
        Right_Stick->changeStates(juce__toggleButton_dis_enableAll->getToggleState());
        Left_Acc->changeStates(juce__toggleButton_dis_enableAll->getToggleState());
        Left_Gyo->changeStates(juce__toggleButton_dis_enableAll->getToggleState());
        Right_Acc->changeStates(juce__toggleButton_dis_enableAll->getToggleState());
        Right_Gyo->changeStates(juce__toggleButton_dis_enableAll->getToggleState());
        //[/UserButtonCode_juce__toggleButton_dis_enableAll]
    }
    else if (buttonThatWasClicked == juce__textButton_ChangeDevice.get())
    {
        //[UserButtonCode_juce__textButton_ChangeDevice] -- add your button handler code here..
        juce__toggleButton_L_IMU->setToggleState(false, juce::sendNotification);
        juce__toggleButton_R_IMU->setToggleState(false, juce::sendNotification);
        changeDevice();
        //[/UserButtonCode_juce__textButton_ChangeDevice]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void JoyCon_UI::update()
{
    if(isConnected){
        setFramesPerSecond(10);
        juce__textButton_zl->setToggleState(l_jc_input.buttons.zl, juce::sendNotification);
        juce__textButton_l->setToggleState(l_jc_input.buttons.l, juce::sendNotification);
        juce__textButton_minus->setToggleState(l_jc_input.buttons.minus, juce::sendNotification);
        juce__textButton_capture->setToggleState(l_jc_input.buttons.capture, juce::sendNotification);
        juce__textButton_sl_l->setToggleState(l_jc_input.buttons.sl, juce::sendNotification);
        juce__textButton_sr_l->setToggleState(l_jc_input.buttons.sr, juce::sendNotification);

        juce__textButton_UP->setToggleState(l_jc_input.dpad.up, juce::sendNotification);
        juce__textButton_down->setToggleState(l_jc_input.dpad.down, juce::sendNotification);
        juce__textButton_Left->setToggleState(l_jc_input.dpad.left, juce::sendNotification);
        juce__textButton_right->setToggleState(l_jc_input.dpad.right, juce::sendNotification);

        Left_Stick->updatePoint(l_jc_input.stick.x, l_jc_input.stick.y, l_jc_input.stick.stickPress);
        left_EnableStates.StickStates.x = Left_Stick->enableX;
        left_EnableStates.StickStates.y = Left_Stick->enableY;

        Left_Acc->updateSliders(l_jc_input.accelerometer.x, l_jc_input.accelerometer.y, l_jc_input.accelerometer.z);
        left_EnableStates.Acc_states.x = Left_Acc->is_x_enable;
        left_EnableStates.Acc_states.y = Left_Acc->is_y_enable;
        left_EnableStates.Acc_states.z = Left_Acc->is_z_enable;

        Left_Gyo->updateSliders(l_jc_input.gyroscope.x, l_jc_input.gyroscope.y, l_jc_input.gyroscope.z);
        left_EnableStates.Gyo_states.x = Left_Gyo->is_x_enable;
        left_EnableStates.Gyo_states.y = Left_Gyo->is_y_enable;
        left_EnableStates.Gyo_states.z = Left_Gyo->is_z_enable;


        juce__textButton_zr->setToggleState(r_jc_input.buttons.zr, juce::sendNotification);
        juce__textButton_r->setToggleState(r_jc_input.buttons.r, juce::sendNotification);
        juce__textButton_plus->setToggleState(r_jc_input.buttons.plus, juce::sendNotification);
        juce__textButton_home->setToggleState(r_jc_input.buttons.home, juce::sendNotification);
        juce__textButton_sl_r->setToggleState(r_jc_input.buttons.sl, juce::sendNotification);
        juce__textButton_sr_r->setToggleState(r_jc_input.buttons.sr, juce::sendNotification);

        juce__textButton_x->setToggleState(r_jc_input.buttons.x, juce::sendNotification);
        juce__textButton_y->setToggleState(r_jc_input.buttons.y, juce::sendNotification);
        juce__textButton_a->setToggleState(r_jc_input.buttons.a, juce::sendNotification);
        juce__textButton_b->setToggleState(r_jc_input.buttons.b, juce::sendNotification);

        Right_Stick->updatePoint(r_jc_input.stick.x, r_jc_input.stick.y, r_jc_input.stick.stickPress);
        right_EnableStates.StickStates.x = Right_Stick->enableX;
        right_EnableStates.StickStates.y = Right_Stick->enableY;

        Right_Acc->updateSliders(r_jc_input.accelerometer.x, r_jc_input.accelerometer.y, r_jc_input.accelerometer.z);
        right_EnableStates.Acc_states.x = Right_Acc->is_x_enable;
        right_EnableStates.Acc_states.y = Right_Acc->is_y_enable;
        right_EnableStates.Acc_states.z = Right_Acc->is_z_enable;

        Right_Gyo->updateSliders(r_jc_input.gyroscope.x, r_jc_input.gyroscope.y, r_jc_input.gyroscope.z);
        right_EnableStates.Gyo_states.x = Right_Gyo->is_x_enable;
        right_EnableStates.Gyo_states.y = Right_Gyo->is_y_enable;
        right_EnableStates.Gyo_states.z = Right_Gyo->is_z_enable;


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

<JUCER_COMPONENT documentType="Component" className="JoyCon_UI" componentName=""
                 parentClasses="public juce::AnimatedAppComponent" constructorParams=""
                 variableInitialisers="" snapPixels="2" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="700" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44">
    <PATH pos="0 0 100 100" fill="solid: a52a5f" hasStroke="1" stroke="2, mitered, butt"
          strokeColour="solid: ffdc143c" nonZeroWinding="1">s 41.334% 89.706% l 41.334% 2.647% q 24% 2.353% 24% 19.118% l 24% 73.235% q 24% 96.471% 41.334% 96.471% x</PATH>
    <PATH pos="0 0 100 100" fill="solid: a5392a" hasStroke="1" stroke="2, mitered, butt"
          strokeColour="solid: ff6495ed" nonZeroWinding="1">s 60% 96.471% q 77.333% 98.824% 77.333% 80% l 77.333% 21.176% q 77.334% 0% 60% 2.353% x</PATH>
  </BACKGROUND>
  <TEXTBUTTON name="zl_button" id="1cc67156ee26efac" memberName="juce__textButton_zl"
              virtualName="" explicitFocusOrder="0" pos="25% 3.5% 5.857% 4.75%"
              bgColOn="ff5f9ea0" buttonText="ZL" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="l_button" id="a20fe6afd4607943" memberName="juce__textButton_l"
              virtualName="" explicitFocusOrder="0" pos="33.857% 1.5% 5.857% 4.75%"
              bgColOn="ff5f9ea0" buttonText="L" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="minus_button" id="995bf07d41bd7cf2" memberName="juce__textButton_minus"
              virtualName="" explicitFocusOrder="0" pos="35.429% 9% 4.571% 3.75%"
              bgColOn="ff5f9ea0" buttonText="-" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="capture_button" id="dd3b2e191ddd1126" memberName="juce__textButton_capture"
              virtualName="" explicitFocusOrder="0" pos="34.143% 83.5% 6% 4%"
              bgColOn="ff5f9ea0" buttonText="Capture" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="up_button" id="60a341aecef994de" memberName="juce__textButton_UP"
              virtualName="" explicitFocusOrder="0" pos="30.286% 52.75% 5.143% 4%"
              bgColOn="ff5f9ea0" buttonText="Up" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="left_button" id="353c25528095ee94" memberName="juce__textButton_Left"
              virtualName="" explicitFocusOrder="0" pos="25.286% 60% 5.143% 4%"
              bgColOn="ff5f9ea0" buttonText="Left" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="right_button" id="643e5d0931220731" memberName="juce__textButton_right"
              virtualName="" explicitFocusOrder="0" pos="34.857% 60% 5.143% 4%"
              bgColOn="ff5f9ea0" buttonText="Right" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="down_button" id="96446f9ae02af8a5" memberName="juce__textButton_down"
              virtualName="" explicitFocusOrder="0" pos="30.286% 67.75% 5.143% 4%"
              bgColOn="ff5f9ea0" buttonText="Down" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="sl_button" id="5a6ddc9a283427fc" memberName="juce__textButton_sl_l"
              virtualName="" explicitFocusOrder="0" pos="42% 16% 5% 10%" bgColOn="ff5f9ea0"
              buttonText="SL" connectedEdges="0" needsCallback="0" radioGroupId="0"/>
  <TEXTBUTTON name="sr_button" id="55c7c15a26ad5788" memberName="juce__textButton_sr_l"
              virtualName="" explicitFocusOrder="0" pos="42% 66% 5% 10%" bgColOn="ff5f9ea0"
              buttonText="SR" connectedEdges="0" needsCallback="0" radioGroupId="0"/>
  <TEXTBUTTON name="zr_button" id="612844c53a7abbf0" memberName="juce__textButton_zr"
              virtualName="" explicitFocusOrder="0" pos="70% 3.5% 5.857% 4.75%"
              bgColOn="ff5f9ea0" buttonText="ZR" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="r_button" id="569fe346efcede6a" memberName="juce__textButton_r"
              virtualName="" explicitFocusOrder="0" pos="61.429% 1.5% 5.857% 4.75%"
              bgColOn="ff5f9ea0" buttonText="R" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="plus_button" id="e13f508f32787f45" memberName="juce__textButton_plus"
              virtualName="" explicitFocusOrder="0" pos="61.143% 9% 4.143% 4.75%"
              bgColOn="ff5f9ea0" buttonText="+" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="sr_button" id="82e6498f7ab5583b" memberName="juce__textButton_sr_r"
              virtualName="" explicitFocusOrder="0" pos="54% 16% 5% 10%" bgColOn="ff5f9ea0"
              buttonText="SR" connectedEdges="0" needsCallback="0" radioGroupId="0"/>
  <TEXTBUTTON name="sl_button" id="aef97be374c91d95" memberName="juce__textButton_sl_r"
              virtualName="" explicitFocusOrder="0" pos="54% 66% 5% 10%" bgColOn="ff5f9ea0"
              buttonText="SL" connectedEdges="0" needsCallback="0" radioGroupId="0"/>
  <TEXTBUTTON name="x_button" id="f392b142ac2be96d" memberName="juce__textButton_x"
              virtualName="" explicitFocusOrder="0" pos="66.714% 20.5% 5.143% 4%"
              bgColOn="ff5f9ea0" buttonText="X" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="y_button" id="e1327e3abe5f6601" memberName="juce__textButton_y"
              virtualName="" explicitFocusOrder="0" pos="62% 27.75% 5.143% 4%"
              bgColOn="ff5f9ea0" buttonText="Y" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="a_button" id="45678a3db2453320" memberName="juce__textButton_a"
              virtualName="" explicitFocusOrder="0" pos="71% 27.75% 5.143% 4%"
              bgColOn="ff5f9ea0" buttonText="A" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="b_button" id="b8895522617ca8c8" memberName="juce__textButton_b"
              virtualName="" explicitFocusOrder="0" pos="66.714% 34.75% 5.143% 4%"
              bgColOn="ff5f9ea0" buttonText="B" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="home_button" id="c339f80e78117710" memberName="juce__textButton_home"
              virtualName="" explicitFocusOrder="0" pos="61.143% 83.5% 6% 4%"
              bgColOn="ff5f9ea0" buttonText="Home" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TOGGLEBUTTON name="Left_JC_IMU_toggle" id="9b99ae182d27bbd5" memberName="juce__toggleButton_L_IMU"
                virtualName="" explicitFocusOrder="0" pos="44.286% 35% 82 24"
                buttonText="Left IMU" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="Right_JC_IMU_toggle" id="c42986959dcca701" memberName="juce__toggleButton_R_IMU"
                virtualName="" explicitFocusOrder="0" pos="44.286% 50% 82 24"
                buttonText="Right IMU" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <TEXTBUTTON name="L_Virb_button" id="ba471e8ab99c2e40" memberName="juce__textButton_L_Virb"
              virtualName="" explicitFocusOrder="0" pos="41.714% 87% 6% 6.5%"
              bgColOn="ff5f9ea0" buttonText="vib" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="R_Virb_button" id="85734151709505e4" memberName="juce__textButton_R_Virb"
              virtualName="" explicitFocusOrder="0" pos="53.286% 87% 6.143% 6.25%"
              bgColOn="ff5f9ea0" buttonText="vib" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TOGGLEBUTTON name="dis_enableAll_toggle" id="eaf2ec4b71d0bae" memberName="juce__toggleButton_dis_enableAll"
                virtualName="" explicitFocusOrder="0" pos="44.286% 2.5% 100 24"
                buttonText="Dis/Enable All" connectedEdges="0" needsCallback="1"
                radioGroupId="0" state="1"/>
  <TEXTBUTTON name="ChangeDevice_button" id="22ebb74a08c1917" memberName="juce__textButton_ChangeDevice"
              virtualName="" explicitFocusOrder="0" pos="86.571% 2.5% 89 19"
              bgColOff="ffff0000" buttonText="Change Device" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

