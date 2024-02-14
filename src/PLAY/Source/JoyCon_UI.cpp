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
    Left_Stick->setBounds(157, 70, 80, 80);
    Left_Stick->resized();

    Right_Stick.reset(new StickGUI());
    addAndMakeVisible(Right_Stick.get());
    Right_Stick->setBounds(372, 180, 80, 80);
    Right_Stick->resized();
    //[/Constructor_pre]

    juce__textButton_zl.reset (new juce::TextButton ("zl_button"));
    addAndMakeVisible (juce__textButton_zl.get());
    juce__textButton_zl->setButtonText (TRANS ("ZL"));
    juce__textButton_zl->addListener (this);
    juce__textButton_zl->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_l.reset (new juce::TextButton ("l_button"));
    addAndMakeVisible (juce__textButton_l.get());
    juce__textButton_l->setButtonText (TRANS ("L"));
    juce__textButton_l->addListener (this);
    juce__textButton_l->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_minus.reset (new juce::TextButton ("minus_button"));
    addAndMakeVisible (juce__textButton_minus.get());
    juce__textButton_minus->setButtonText (TRANS ("-"));
    juce__textButton_minus->addListener (this);
    juce__textButton_minus->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_capture.reset (new juce::TextButton ("capture_button"));
    addAndMakeVisible (juce__textButton_capture.get());
    juce__textButton_capture->setButtonText (TRANS ("Capture"));
    juce__textButton_capture->addListener (this);
    juce__textButton_capture->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_UP.reset (new juce::TextButton ("up_button"));
    addAndMakeVisible (juce__textButton_UP.get());
    juce__textButton_UP->setButtonText (TRANS ("Up"));
    juce__textButton_UP->addListener (this);
    juce__textButton_UP->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_Left.reset (new juce::TextButton ("left_button"));
    addAndMakeVisible (juce__textButton_Left.get());
    juce__textButton_Left->setButtonText (TRANS ("Left"));
    juce__textButton_Left->addListener (this);
    juce__textButton_Left->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_right.reset (new juce::TextButton ("right_button"));
    addAndMakeVisible (juce__textButton_right.get());
    juce__textButton_right->setButtonText (TRANS ("Right"));
    juce__textButton_right->addListener (this);
    juce__textButton_right->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_down.reset (new juce::TextButton ("down_button"));
    addAndMakeVisible (juce__textButton_down.get());
    juce__textButton_down->setButtonText (TRANS ("Down"));
    juce__textButton_down->addListener (this);
    juce__textButton_down->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_sl_l.reset (new juce::TextButton ("sl_button"));
    addAndMakeVisible (juce__textButton_sl_l.get());
    juce__textButton_sl_l->setButtonText (TRANS ("SL"));
    juce__textButton_sl_l->addListener (this);
    juce__textButton_sl_l->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_sr_l.reset (new juce::TextButton ("sr_button"));
    addAndMakeVisible (juce__textButton_sr_l.get());
    juce__textButton_sr_l->setButtonText (TRANS ("SR"));
    juce__textButton_sr_l->addListener (this);
    juce__textButton_sr_l->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_zr.reset (new juce::TextButton ("zr_button"));
    addAndMakeVisible (juce__textButton_zr.get());
    juce__textButton_zr->setButtonText (TRANS ("ZR"));
    juce__textButton_zr->addListener (this);
    juce__textButton_zr->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_r.reset (new juce::TextButton ("r_button"));
    addAndMakeVisible (juce__textButton_r.get());
    juce__textButton_r->setButtonText (TRANS ("R"));
    juce__textButton_r->addListener (this);
    juce__textButton_r->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_plus.reset (new juce::TextButton ("plus_button"));
    addAndMakeVisible (juce__textButton_plus.get());
    juce__textButton_plus->setButtonText (TRANS ("+"));
    juce__textButton_plus->addListener (this);
    juce__textButton_plus->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_sr_r.reset (new juce::TextButton ("sr_button"));
    addAndMakeVisible (juce__textButton_sr_r.get());
    juce__textButton_sr_r->setButtonText (TRANS ("SR"));
    juce__textButton_sr_r->addListener (this);
    juce__textButton_sr_r->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_sl_r.reset (new juce::TextButton ("sl_button"));
    addAndMakeVisible (juce__textButton_sl_r.get());
    juce__textButton_sl_r->setButtonText (TRANS ("SL"));
    juce__textButton_sl_r->addListener (this);
    juce__textButton_sl_r->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_x.reset (new juce::TextButton ("x_button"));
    addAndMakeVisible (juce__textButton_x.get());
    juce__textButton_x->setButtonText (TRANS ("X"));
    juce__textButton_x->addListener (this);
    juce__textButton_x->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_y.reset (new juce::TextButton ("y_button"));
    addAndMakeVisible (juce__textButton_y.get());
    juce__textButton_y->setButtonText (TRANS ("Y"));
    juce__textButton_y->addListener (this);
    juce__textButton_y->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_a.reset (new juce::TextButton ("a_button"));
    addAndMakeVisible (juce__textButton_a.get());
    juce__textButton_a->setButtonText (TRANS ("A"));
    juce__textButton_a->addListener (this);
    juce__textButton_a->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_b.reset (new juce::TextButton ("b_button"));
    addAndMakeVisible (juce__textButton_b.get());
    juce__textButton_b->setButtonText (TRANS ("B"));
    juce__textButton_b->addListener (this);
    juce__textButton_b->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_home.reset (new juce::TextButton ("home_button"));
    addAndMakeVisible (juce__textButton_home.get());
    juce__textButton_home->setButtonText (TRANS ("Home"));
    juce__textButton_home->addListener (this);
    juce__textButton_home->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__label_acc.reset (new juce::Label ("accelerometer",
                                            TRANS ("Accelerometer")));
    addAndMakeVisible (juce__label_acc.get());
    juce__label_acc->setFont (juce::Font (10.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label_acc->setJustificationType (juce::Justification::centredTop);
    juce__label_acc->setEditable (false, false, false);
    juce__label_acc->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label_acc->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__slider_l_acc_x.reset (new juce::Slider ("L_Acc_x"));
    addAndMakeVisible (juce__slider_l_acc_x.get());
    juce__slider_l_acc_x->setRange (0, 1, 0);
    juce__slider_l_acc_x->setSliderStyle (juce::Slider::LinearHorizontal);
    juce__slider_l_acc_x->setTextBoxStyle (juce::Slider::TextBoxBelow, true, 80, 20);
    juce__slider_l_acc_x->setColour (juce::Slider::backgroundColourId, juce::Colour (0xff263238));
    juce__slider_l_acc_x->setColour (juce::Slider::trackColourId, juce::Colour (0xff263238));
    juce__slider_l_acc_x->setColour (juce::Slider::rotarySliderFillColourId, juce::Colour (0xff263238));
    juce__slider_l_acc_x->addListener (this);

    juce__slider_l_acc_y.reset (new juce::Slider ("L_Acc_y"));
    addAndMakeVisible (juce__slider_l_acc_y.get());
    juce__slider_l_acc_y->setRange (0, 1, 0);
    juce__slider_l_acc_y->setSliderStyle (juce::Slider::LinearHorizontal);
    juce__slider_l_acc_y->setTextBoxStyle (juce::Slider::TextBoxBelow, true, 80, 20);
    juce__slider_l_acc_y->setColour (juce::Slider::backgroundColourId, juce::Colour (0xff263238));
    juce__slider_l_acc_y->setColour (juce::Slider::trackColourId, juce::Colour (0xff263238));
    juce__slider_l_acc_y->setColour (juce::Slider::rotarySliderFillColourId, juce::Colour (0xff263238));
    juce__slider_l_acc_y->addListener (this);

    juce__slider_l_acc_z.reset (new juce::Slider ("L_Acc_z"));
    addAndMakeVisible (juce__slider_l_acc_z.get());
    juce__slider_l_acc_z->setRange (0, 1, 0);
    juce__slider_l_acc_z->setSliderStyle (juce::Slider::LinearHorizontal);
    juce__slider_l_acc_z->setTextBoxStyle (juce::Slider::TextBoxBelow, true, 80, 20);
    juce__slider_l_acc_z->setColour (juce::Slider::backgroundColourId, juce::Colour (0xff263238));
    juce__slider_l_acc_z->setColour (juce::Slider::trackColourId, juce::Colour (0xff263238));
    juce__slider_l_acc_z->setColour (juce::Slider::rotarySliderFillColourId, juce::Colour (0xff263238));
    juce__slider_l_acc_z->addListener (this);

    juce__label_Gyroscope.reset (new juce::Label ("Gyroscope",
                                                  TRANS ("Gyroscope")));
    addAndMakeVisible (juce__label_Gyroscope.get());
    juce__label_Gyroscope->setFont (juce::Font (10.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label_Gyroscope->setJustificationType (juce::Justification::centredTop);
    juce__label_Gyroscope->setEditable (false, false, false);
    juce__label_Gyroscope->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label_Gyroscope->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__slider_l_gyr_x.reset (new juce::Slider ("L_Gyr_x"));
    addAndMakeVisible (juce__slider_l_gyr_x.get());
    juce__slider_l_gyr_x->setRange (-500, 500, 0);
    juce__slider_l_gyr_x->setSliderStyle (juce::Slider::LinearHorizontal);
    juce__slider_l_gyr_x->setTextBoxStyle (juce::Slider::TextBoxBelow, true, 80, 20);
    juce__slider_l_gyr_x->setColour (juce::Slider::backgroundColourId, juce::Colour (0xff263238));
    juce__slider_l_gyr_x->setColour (juce::Slider::trackColourId, juce::Colour (0xff263238));
    juce__slider_l_gyr_x->setColour (juce::Slider::rotarySliderFillColourId, juce::Colour (0xff263238));
    juce__slider_l_gyr_x->addListener (this);

    juce__slider_l_gyr_y.reset (new juce::Slider ("L_Gyr_y"));
    addAndMakeVisible (juce__slider_l_gyr_y.get());
    juce__slider_l_gyr_y->setRange (-500, 500, 0);
    juce__slider_l_gyr_y->setSliderStyle (juce::Slider::LinearHorizontal);
    juce__slider_l_gyr_y->setTextBoxStyle (juce::Slider::TextBoxBelow, true, 80, 20);
    juce__slider_l_gyr_y->setColour (juce::Slider::backgroundColourId, juce::Colour (0xff263238));
    juce__slider_l_gyr_y->setColour (juce::Slider::trackColourId, juce::Colour (0xff263238));
    juce__slider_l_gyr_y->setColour (juce::Slider::rotarySliderFillColourId, juce::Colour (0xff263238));
    juce__slider_l_gyr_y->addListener (this);

    juce__slider_l_gyr_z.reset (new juce::Slider ("L_Gyr_z"));
    addAndMakeVisible (juce__slider_l_gyr_z.get());
    juce__slider_l_gyr_z->setRange (-500, 500, 0);
    juce__slider_l_gyr_z->setSliderStyle (juce::Slider::LinearHorizontal);
    juce__slider_l_gyr_z->setTextBoxStyle (juce::Slider::TextBoxBelow, true, 80, 20);
    juce__slider_l_gyr_z->setColour (juce::Slider::backgroundColourId, juce::Colour (0xff263238));
    juce__slider_l_gyr_z->setColour (juce::Slider::trackColourId, juce::Colour (0xff263238));
    juce__slider_l_gyr_z->setColour (juce::Slider::rotarySliderFillColourId, juce::Colour (0xff263238));
    juce__slider_l_gyr_z->addListener (this);

    juce__label_acc2.reset (new juce::Label ("accelerometer",
                                             TRANS ("Accelerometer")));
    addAndMakeVisible (juce__label_acc2.get());
    juce__label_acc2->setFont (juce::Font (10.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label_acc2->setJustificationType (juce::Justification::centredTop);
    juce__label_acc2->setEditable (false, false, false);
    juce__label_acc2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label_acc2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label_Gyroscope2.reset (new juce::Label ("Gyroscope",
                                                   TRANS ("Gyroscope")));
    addAndMakeVisible (juce__label_Gyroscope2.get());
    juce__label_Gyroscope2->setFont (juce::Font (10.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label_Gyroscope2->setJustificationType (juce::Justification::centredTop);
    juce__label_Gyroscope2->setEditable (false, false, false);
    juce__label_Gyroscope2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label_Gyroscope2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__slider_r_acc_x.reset (new juce::Slider ("R_Acc_x"));
    addAndMakeVisible (juce__slider_r_acc_x.get());
    juce__slider_r_acc_x->setRange (0, 1, 0);
    juce__slider_r_acc_x->setSliderStyle (juce::Slider::LinearHorizontal);
    juce__slider_r_acc_x->setTextBoxStyle (juce::Slider::TextBoxBelow, true, 80, 20);
    juce__slider_r_acc_x->setColour (juce::Slider::backgroundColourId, juce::Colour (0xff263238));
    juce__slider_r_acc_x->setColour (juce::Slider::trackColourId, juce::Colour (0xff263238));
    juce__slider_r_acc_x->setColour (juce::Slider::rotarySliderFillColourId, juce::Colour (0xff263238));
    juce__slider_r_acc_x->addListener (this);

    juce__slider_r_acc_y.reset (new juce::Slider ("R_Acc_y"));
    addAndMakeVisible (juce__slider_r_acc_y.get());
    juce__slider_r_acc_y->setRange (0, 1, 0);
    juce__slider_r_acc_y->setSliderStyle (juce::Slider::LinearHorizontal);
    juce__slider_r_acc_y->setTextBoxStyle (juce::Slider::TextBoxBelow, true, 80, 20);
    juce__slider_r_acc_y->setColour (juce::Slider::backgroundColourId, juce::Colour (0xff263238));
    juce__slider_r_acc_y->setColour (juce::Slider::trackColourId, juce::Colour (0xff263238));
    juce__slider_r_acc_y->setColour (juce::Slider::rotarySliderFillColourId, juce::Colour (0xff263238));
    juce__slider_r_acc_y->addListener (this);

    juce__slider_r_acc_z.reset (new juce::Slider ("R_Acc_z"));
    addAndMakeVisible (juce__slider_r_acc_z.get());
    juce__slider_r_acc_z->setRange (0, 1, 0);
    juce__slider_r_acc_z->setSliderStyle (juce::Slider::LinearHorizontal);
    juce__slider_r_acc_z->setTextBoxStyle (juce::Slider::TextBoxBelow, true, 80, 20);
    juce__slider_r_acc_z->setColour (juce::Slider::backgroundColourId, juce::Colour (0xff263238));
    juce__slider_r_acc_z->setColour (juce::Slider::trackColourId, juce::Colour (0xff263238));
    juce__slider_r_acc_z->setColour (juce::Slider::rotarySliderFillColourId, juce::Colour (0xff263238));
    juce__slider_r_acc_z->addListener (this);

    juce__slider_r_gyr_x.reset (new juce::Slider ("R_Gyr_x"));
    addAndMakeVisible (juce__slider_r_gyr_x.get());
    juce__slider_r_gyr_x->setRange (-500, 500, 0);
    juce__slider_r_gyr_x->setSliderStyle (juce::Slider::LinearHorizontal);
    juce__slider_r_gyr_x->setTextBoxStyle (juce::Slider::TextBoxBelow, true, 80, 20);
    juce__slider_r_gyr_x->setColour (juce::Slider::backgroundColourId, juce::Colour (0xff263238));
    juce__slider_r_gyr_x->setColour (juce::Slider::trackColourId, juce::Colour (0xff263238));
    juce__slider_r_gyr_x->setColour (juce::Slider::rotarySliderFillColourId, juce::Colour (0xff263238));
    juce__slider_r_gyr_x->addListener (this);

    juce__slider_r_gyr_y.reset (new juce::Slider ("R_Gyr_y"));
    addAndMakeVisible (juce__slider_r_gyr_y.get());
    juce__slider_r_gyr_y->setRange (-500, 500, 0);
    juce__slider_r_gyr_y->setSliderStyle (juce::Slider::LinearHorizontal);
    juce__slider_r_gyr_y->setTextBoxStyle (juce::Slider::TextBoxBelow, true, 80, 20);
    juce__slider_r_gyr_y->setColour (juce::Slider::backgroundColourId, juce::Colour (0xff263238));
    juce__slider_r_gyr_y->setColour (juce::Slider::trackColourId, juce::Colour (0xff263238));
    juce__slider_r_gyr_y->setColour (juce::Slider::rotarySliderFillColourId, juce::Colour (0xff263238));
    juce__slider_r_gyr_y->addListener (this);

    juce__slider_r_gyr_z.reset (new juce::Slider ("R_Gyr_z"));
    addAndMakeVisible (juce__slider_r_gyr_z.get());
    juce__slider_r_gyr_z->setRange (-500, 500, 0);
    juce__slider_r_gyr_z->setSliderStyle (juce::Slider::LinearHorizontal);
    juce__slider_r_gyr_z->setTextBoxStyle (juce::Slider::TextBoxBelow, true, 80, 20);
    juce__slider_r_gyr_z->setColour (juce::Slider::backgroundColourId, juce::Colour (0xff263238));
    juce__slider_r_gyr_z->setColour (juce::Slider::trackColourId, juce::Colour (0xff263238));
    juce__slider_r_gyr_z->setColour (juce::Slider::rotarySliderFillColourId, juce::Colour (0xff263238));
    juce__slider_r_gyr_z->addListener (this);

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
    juce__label_acc = nullptr;
    juce__slider_l_acc_x = nullptr;
    juce__slider_l_acc_y = nullptr;
    juce__slider_l_acc_z = nullptr;
    juce__label_Gyroscope = nullptr;
    juce__slider_l_gyr_x = nullptr;
    juce__slider_l_gyr_y = nullptr;
    juce__slider_l_gyr_z = nullptr;
    juce__label_acc2 = nullptr;
    juce__label_Gyroscope2 = nullptr;
    juce__slider_r_acc_x = nullptr;
    juce__slider_r_acc_y = nullptr;
    juce__slider_r_acc_z = nullptr;
    juce__slider_r_gyr_x = nullptr;
    juce__slider_r_gyr_y = nullptr;
    juce__slider_r_gyr_z = nullptr;
    juce__toggleButton_L_IMU = nullptr;
    juce__toggleButton_R_IMU = nullptr;
    juce__textButton_L_Virb = nullptr;
    juce__textButton_R_Virb = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    Left_Stick  = nullptr;
    Right_Stick = nullptr;
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
    juce__label_acc->setBounds (proportionOfWidth (0.0543f), proportionOfHeight (0.0200f), 75, 12);
    juce__slider_l_acc_x->setBounds (proportionOfWidth (0.0200f), proportionOfHeight (0.0825f), proportionOfWidth (0.2000f), proportionOfHeight (0.1000f));
    juce__slider_l_acc_y->setBounds (proportionOfWidth (0.0200f), proportionOfHeight (0.2125f), proportionOfWidth (0.2000f), proportionOfHeight (0.1000f));
    juce__slider_l_acc_z->setBounds (proportionOfWidth (0.0200f), proportionOfHeight (0.3400f), 120, 34);
    juce__label_Gyroscope->setBounds (proportionOfWidth (0.0543f), proportionOfHeight (0.5050f), 75, 12);
    juce__slider_l_gyr_x->setBounds (proportionOfWidth (0.0186f), proportionOfHeight (0.5500f), proportionOfWidth (0.2014f), proportionOfHeight (0.1000f));
    juce__slider_l_gyr_y->setBounds (proportionOfWidth (0.0186f), proportionOfHeight (0.6775f), proportionOfWidth (0.2014f), proportionOfHeight (0.1000f));
    juce__slider_l_gyr_z->setBounds (proportionOfWidth (0.0186f), proportionOfHeight (0.8025f), proportionOfWidth (0.2014f), proportionOfHeight (0.1000f));
    juce__label_acc2->setBounds (proportionOfWidth (0.8271f), proportionOfHeight (0.0200f), 75, 12);
    juce__label_Gyroscope2->setBounds (proportionOfWidth (0.8271f), proportionOfHeight (0.5050f), 75, 12);
    juce__slider_r_acc_x->setBounds (proportionOfWidth (0.7900f), proportionOfHeight (0.0825f), proportionOfWidth (0.2000f), proportionOfHeight (0.1000f));
    juce__slider_r_acc_y->setBounds (proportionOfWidth (0.7900f), proportionOfHeight (0.2125f), proportionOfWidth (0.2000f), proportionOfHeight (0.1000f));
    juce__slider_r_acc_z->setBounds (proportionOfWidth (0.7900f), proportionOfHeight (0.3400f), proportionOfWidth (0.2000f), proportionOfHeight (0.1000f));
    juce__slider_r_gyr_x->setBounds (proportionOfWidth (0.7900f), proportionOfHeight (0.5500f), proportionOfWidth (0.2000f), proportionOfHeight (0.1000f));
    juce__slider_r_gyr_y->setBounds (proportionOfWidth (0.7900f), proportionOfHeight (0.6775f), proportionOfWidth (0.2000f), proportionOfHeight (0.1000f));
    juce__slider_r_gyr_z->setBounds (proportionOfWidth (0.7900f), proportionOfHeight (0.8025f), proportionOfWidth (0.2000f), proportionOfHeight (0.1000f));
    juce__toggleButton_L_IMU->setBounds (proportionOfWidth (0.4400f), proportionOfHeight (0.3500f), 82, 24);
    juce__toggleButton_R_IMU->setBounds (proportionOfWidth (0.4400f), proportionOfHeight (0.5000f), 82, 24);
    juce__textButton_L_Virb->setBounds (proportionOfWidth (0.4171f), proportionOfHeight (0.8700f), proportionOfWidth (0.0600f), proportionOfHeight (0.0650f));
    juce__textButton_R_Virb->setBounds (proportionOfWidth (0.5329f), proportionOfHeight (0.8700f), proportionOfWidth (0.0614f), proportionOfHeight (0.0625f));
    internalPath1.clear();
    internalPath1.startNewSubPath (static_cast<float> (proportionOfWidth (0.4133f)), static_cast<float> (proportionOfHeight (0.8971f)));
    internalPath1.lineTo (static_cast<float> (proportionOfWidth (0.4133f)), static_cast<float> (proportionOfHeight (0.0265f)));
    internalPath1.quadraticTo (static_cast<float> (proportionOfWidth (0.2400f)), static_cast<float> (proportionOfHeight (0.0235f)), static_cast<float> (proportionOfWidth (0.2400f)), static_cast<float> (proportionOfHeight (0.1912f)));
    internalPath1.lineTo (static_cast<float> (proportionOfWidth (0.2400f)), static_cast<float> (proportionOfHeight (0.7324f)));
    internalPath1.quadraticTo (static_cast<float> (proportionOfWidth (0.2400f)), static_cast<float> (proportionOfHeight (0.9647f)), static_cast<float> (proportionOfWidth (0.4133f)), static_cast<float> (proportionOfHeight (0.9647f)));
    internalPath1.closeSubPath();

    internalPath2.clear();
    internalPath2.startNewSubPath (static_cast<float> (proportionOfWidth (0.6000f)), static_cast<float> (proportionOfHeight (0.9647f)));
    internalPath2.quadraticTo (static_cast<float> (proportionOfWidth (0.7733f)), static_cast<float> (proportionOfHeight (0.9882f)), static_cast<float> (proportionOfWidth (0.7733f)), static_cast<float> (proportionOfHeight (0.8000f)));
    internalPath2.lineTo (static_cast<float> (proportionOfWidth (0.7733f)), static_cast<float> (proportionOfHeight (0.2118f)));
    internalPath2.quadraticTo (static_cast<float> (proportionOfWidth (0.7733f)), static_cast<float> (proportionOfHeight (0.0000f)), static_cast<float> (proportionOfWidth (0.6000f)), static_cast<float> (proportionOfHeight (0.0235f)));
    internalPath2.closeSubPath();

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void JoyCon_UI::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == juce__textButton_zl.get())
    {
        //[UserButtonCode_juce__textButton_zl] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_zl]
    }
    else if (buttonThatWasClicked == juce__textButton_l.get())
    {
        //[UserButtonCode_juce__textButton_l] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_l]
    }
    else if (buttonThatWasClicked == juce__textButton_minus.get())
    {
        //[UserButtonCode_juce__textButton_minus] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_minus]
    }
    else if (buttonThatWasClicked == juce__textButton_capture.get())
    {
        //[UserButtonCode_juce__textButton_capture] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_capture]
    }
    else if (buttonThatWasClicked == juce__textButton_UP.get())
    {
        //[UserButtonCode_juce__textButton_UP] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_UP]
    }
    else if (buttonThatWasClicked == juce__textButton_Left.get())
    {
        //[UserButtonCode_juce__textButton_Left] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_Left]
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
    else if (buttonThatWasClicked == juce__textButton_sl_l.get())
    {
        //[UserButtonCode_juce__textButton_sl_l] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_sl_l]
    }
    else if (buttonThatWasClicked == juce__textButton_sr_l.get())
    {
        //[UserButtonCode_juce__textButton_sr_l] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_sr_l]
    }
    else if (buttonThatWasClicked == juce__textButton_zr.get())
    {
        //[UserButtonCode_juce__textButton_zr] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_zr]
    }
    else if (buttonThatWasClicked == juce__textButton_r.get())
    {
        //[UserButtonCode_juce__textButton_r] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_r]
    }
    else if (buttonThatWasClicked == juce__textButton_plus.get())
    {
        //[UserButtonCode_juce__textButton_plus] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_plus]
    }
    else if (buttonThatWasClicked == juce__textButton_sr_r.get())
    {
        //[UserButtonCode_juce__textButton_sr_r] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_sr_r]
    }
    else if (buttonThatWasClicked == juce__textButton_sl_r.get())
    {
        //[UserButtonCode_juce__textButton_sl_r] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_sl_r]
    }
    else if (buttonThatWasClicked == juce__textButton_x.get())
    {
        //[UserButtonCode_juce__textButton_x] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_x]
    }
    else if (buttonThatWasClicked == juce__textButton_y.get())
    {
        //[UserButtonCode_juce__textButton_y] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_y]
    }
    else if (buttonThatWasClicked == juce__textButton_a.get())
    {
        //[UserButtonCode_juce__textButton_a] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_a]
    }
    else if (buttonThatWasClicked == juce__textButton_b.get())
    {
        //[UserButtonCode_juce__textButton_b] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_b]
    }
    else if (buttonThatWasClicked == juce__textButton_home.get())
    {
        //[UserButtonCode_juce__textButton_home] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_home]
    }
    else if (buttonThatWasClicked == juce__toggleButton_L_IMU.get())
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

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void JoyCon_UI::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == juce__slider_l_acc_x.get())
    {
        //[UserSliderCode_juce__slider_l_acc_x] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider_l_acc_x]
    }
    else if (sliderThatWasMoved == juce__slider_l_acc_y.get())
    {
        //[UserSliderCode_juce__slider_l_acc_y] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider_l_acc_y]
    }
    else if (sliderThatWasMoved == juce__slider_l_acc_z.get())
    {
        //[UserSliderCode_juce__slider_l_acc_z] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider_l_acc_z]
    }
    else if (sliderThatWasMoved == juce__slider_l_gyr_x.get())
    {
        //[UserSliderCode_juce__slider_l_gyr_x] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider_l_gyr_x]
    }
    else if (sliderThatWasMoved == juce__slider_l_gyr_y.get())
    {
        //[UserSliderCode_juce__slider_l_gyr_y] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider_l_gyr_y]
    }
    else if (sliderThatWasMoved == juce__slider_l_gyr_z.get())
    {
        //[UserSliderCode_juce__slider_l_gyr_z] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider_l_gyr_z]
    }
    else if (sliderThatWasMoved == juce__slider_r_acc_x.get())
    {
        //[UserSliderCode_juce__slider_r_acc_x] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider_r_acc_x]
    }
    else if (sliderThatWasMoved == juce__slider_r_acc_y.get())
    {
        //[UserSliderCode_juce__slider_r_acc_y] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider_r_acc_y]
    }
    else if (sliderThatWasMoved == juce__slider_r_acc_z.get())
    {
        //[UserSliderCode_juce__slider_r_acc_z] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider_r_acc_z]
    }
    else if (sliderThatWasMoved == juce__slider_r_gyr_x.get())
    {
        //[UserSliderCode_juce__slider_r_gyr_x] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider_r_gyr_x]
    }
    else if (sliderThatWasMoved == juce__slider_r_gyr_y.get())
    {
        //[UserSliderCode_juce__slider_r_gyr_y] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider_r_gyr_y]
    }
    else if (sliderThatWasMoved == juce__slider_r_gyr_z.get())
    {
        //[UserSliderCode_juce__slider_r_gyr_z] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider_r_gyr_z]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
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

        juce__slider_l_acc_x->setValue(std::clamp(l_jc_input.accelerometer.x, .0f, 1.0f));
        juce__slider_l_acc_y->setValue(std::clamp(l_jc_input.accelerometer.y, .0f, 1.0f));
        juce__slider_l_acc_z->setValue(std::clamp(l_jc_input.accelerometer.z, .0f, 1.0f));

        juce__slider_l_gyr_x->setValue(std::clamp(l_jc_input.gyroscope.x, -500.0f, 500.0f));
        juce__slider_l_gyr_y->setValue(std::clamp(l_jc_input.gyroscope.y, -500.0f, 500.0f));
        juce__slider_l_gyr_z->setValue(std::clamp(l_jc_input.gyroscope.z, -500.0f, 500.0f));

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

        juce__slider_r_acc_x->setValue(std::clamp(r_jc_input.accelerometer.x, .0f, 1.0f));
        juce__slider_r_acc_y->setValue(std::clamp(r_jc_input.accelerometer.y, .0f, 1.0f));
        juce__slider_r_acc_z->setValue(std::clamp(r_jc_input.accelerometer.z, .0f, 1.0f));

        juce__slider_r_gyr_x->setValue(std::clamp(r_jc_input.gyroscope.x, -500.0f, 500.0f));
        juce__slider_r_gyr_y->setValue(std::clamp(r_jc_input.gyroscope.y, -500.0f, 500.0f));
        juce__slider_r_gyr_z->setValue(std::clamp(r_jc_input.gyroscope.z, -500.0f, 500.0f));

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
              virtualName="" explicitFocusOrder="0" pos="25% 3.529% 5.857% 4.706%"
              bgColOn="ff5f9ea0" buttonText="ZL" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="l_button" id="a20fe6afd4607943" memberName="juce__textButton_l"
              virtualName="" explicitFocusOrder="0" pos="33.857% 1.471% 5.857% 4.706%"
              bgColOn="ff5f9ea0" buttonText="L" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="minus_button" id="995bf07d41bd7cf2" memberName="juce__textButton_minus"
              virtualName="" explicitFocusOrder="0" pos="35.429% 9.118% 4.571% 3.824%"
              bgColOn="ff5f9ea0" buttonText="-" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="capture_button" id="dd3b2e191ddd1126" memberName="juce__textButton_capture"
              virtualName="" explicitFocusOrder="0" pos="34.143% 83.529% 6% 4.118%"
              bgColOn="ff5f9ea0" buttonText="Capture" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="up_button" id="60a341aecef994de" memberName="juce__textButton_UP"
              virtualName="" explicitFocusOrder="0" pos="30.286% 52.647% 5.143% 4.118%"
              bgColOn="ff5f9ea0" buttonText="Up" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="left_button" id="353c25528095ee94" memberName="juce__textButton_Left"
              virtualName="" explicitFocusOrder="0" pos="25.286% 60% 5.143% 4.118%"
              bgColOn="ff5f9ea0" buttonText="Left" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="right_button" id="643e5d0931220731" memberName="juce__textButton_right"
              virtualName="" explicitFocusOrder="0" pos="34.857% 60% 5.143% 4.118%"
              bgColOn="ff5f9ea0" buttonText="Right" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="down_button" id="96446f9ae02af8a5" memberName="juce__textButton_down"
              virtualName="" explicitFocusOrder="0" pos="30.286% 67.647% 5.143% 4.118%"
              bgColOn="ff5f9ea0" buttonText="Down" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="sl_button" id="5a6ddc9a283427fc" memberName="juce__textButton_sl_l"
              virtualName="" explicitFocusOrder="0" pos="42% 15.882% 5% 10%"
              bgColOn="ff5f9ea0" buttonText="SL" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="sr_button" id="55c7c15a26ad5788" memberName="juce__textButton_sr_l"
              virtualName="" explicitFocusOrder="0" pos="42% 65.882% 5% 10%"
              bgColOn="ff5f9ea0" buttonText="SR" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="zr_button" id="612844c53a7abbf0" memberName="juce__textButton_zr"
              virtualName="" explicitFocusOrder="0" pos="70% 3.529% 5.857% 4.706%"
              bgColOn="ff5f9ea0" buttonText="ZR" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="r_button" id="569fe346efcede6a" memberName="juce__textButton_r"
              virtualName="" explicitFocusOrder="0" pos="61.429% 1.471% 5.857% 4.706%"
              bgColOn="ff5f9ea0" buttonText="R" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="plus_button" id="e13f508f32787f45" memberName="juce__textButton_plus"
              virtualName="" explicitFocusOrder="0" pos="61.143% 9.118% 4.143% 4.706%"
              bgColOn="ff5f9ea0" buttonText="+" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="sr_button" id="82e6498f7ab5583b" memberName="juce__textButton_sr_r"
              virtualName="" explicitFocusOrder="0" pos="54% 15.882% 5% 10%"
              bgColOn="ff5f9ea0" buttonText="SR" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="sl_button" id="aef97be374c91d95" memberName="juce__textButton_sl_r"
              virtualName="" explicitFocusOrder="0" pos="54% 65.882% 5% 10%"
              bgColOn="ff5f9ea0" buttonText="SL" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="x_button" id="f392b142ac2be96d" memberName="juce__textButton_x"
              virtualName="" explicitFocusOrder="0" pos="66.714% 20.588% 5.143% 4.118%"
              bgColOn="ff5f9ea0" buttonText="X" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="y_button" id="e1327e3abe5f6601" memberName="juce__textButton_y"
              virtualName="" explicitFocusOrder="0" pos="62% 27.647% 5.143% 4.118%"
              bgColOn="ff5f9ea0" buttonText="Y" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="a_button" id="45678a3db2453320" memberName="juce__textButton_a"
              virtualName="" explicitFocusOrder="0" pos="71% 27.647% 5.143% 4.118%"
              bgColOn="ff5f9ea0" buttonText="A" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="b_button" id="b8895522617ca8c8" memberName="juce__textButton_b"
              virtualName="" explicitFocusOrder="0" pos="66.714% 34.706% 5.143% 4.118%"
              bgColOn="ff5f9ea0" buttonText="B" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="home_button" id="c339f80e78117710" memberName="juce__textButton_home"
              virtualName="" explicitFocusOrder="0" pos="61.143% 83.529% 6% 4.118%"
              bgColOn="ff5f9ea0" buttonText="Home" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <LABEL name="accelerometer" id="cc65c8b747b37e4d" memberName="juce__label_acc"
         virtualName="" explicitFocusOrder="0" pos="5.429% 2.059% 75 12"
         edTextCol="ff000000" edBkgCol="0" labelText="Accelerometer" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="10.0" kerning="0.0" bold="0" italic="0" justification="12"/>
  <SLIDER name="L_Acc_x" id="24cea3497d731f4b" memberName="juce__slider_l_acc_x"
          virtualName="" explicitFocusOrder="0" pos="2% 8.235% 20% 10%"
          bkgcol="ff263238" trackcol="ff263238" rotarysliderfill="ff263238"
          min="0.0" max="1.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="L_Acc_y" id="717726e15a10bdd6" memberName="juce__slider_l_acc_y"
          virtualName="" explicitFocusOrder="0" pos="2% 21.176% 20% 10%"
          bkgcol="ff263238" trackcol="ff263238" rotarysliderfill="ff263238"
          min="0.0" max="1.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="L_Acc_z" id="ea795dc0109fa991" memberName="juce__slider_l_acc_z"
          virtualName="" explicitFocusOrder="0" pos="2% 34.118% 120 34"
          bkgcol="ff263238" trackcol="ff263238" rotarysliderfill="ff263238"
          min="0.0" max="1.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="Gyroscope" id="be5bd99aa3d8564b" memberName="juce__label_Gyroscope"
         virtualName="" explicitFocusOrder="0" pos="5.429% 50.588% 75 12"
         edTextCol="ff000000" edBkgCol="0" labelText="Gyroscope" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="10.0" kerning="0.0" bold="0" italic="0" justification="12"/>
  <SLIDER name="L_Gyr_x" id="6162d626240ec822" memberName="juce__slider_l_gyr_x"
          virtualName="" explicitFocusOrder="0" pos="1.857% 55% 20.143% 10%"
          bkgcol="ff263238" trackcol="ff263238" rotarysliderfill="ff263238"
          min="-500.0" max="500.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="L_Gyr_y" id="726028bb5c101d79" memberName="juce__slider_l_gyr_y"
          virtualName="" explicitFocusOrder="0" pos="1.857% 67.647% 20.143% 10%"
          bkgcol="ff263238" trackcol="ff263238" rotarysliderfill="ff263238"
          min="-500.0" max="500.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="L_Gyr_z" id="8d6a53e81889b85a" memberName="juce__slider_l_gyr_z"
          virtualName="" explicitFocusOrder="0" pos="1.857% 80.294% 20.143% 10%"
          bkgcol="ff263238" trackcol="ff263238" rotarysliderfill="ff263238"
          min="-500.0" max="500.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="accelerometer" id="c0f4e151a3c29de9" memberName="juce__label_acc2"
         virtualName="" explicitFocusOrder="0" pos="82.714% 2.059% 75 12"
         edTextCol="ff000000" edBkgCol="0" labelText="Accelerometer" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="10.0" kerning="0.0" bold="0" italic="0" justification="12"/>
  <LABEL name="Gyroscope" id="e788889755d5ed8f" memberName="juce__label_Gyroscope2"
         virtualName="" explicitFocusOrder="0" pos="82.714% 50.588% 75 12"
         edTextCol="ff000000" edBkgCol="0" labelText="Gyroscope" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="10.0" kerning="0.0" bold="0" italic="0" justification="12"/>
  <SLIDER name="R_Acc_x" id="b0e42447b9d6a103" memberName="juce__slider_r_acc_x"
          virtualName="" explicitFocusOrder="0" pos="79% 8.235% 20% 10%"
          bkgcol="ff263238" trackcol="ff263238" rotarysliderfill="ff263238"
          min="0.0" max="1.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="R_Acc_y" id="a8efe4d342f4544" memberName="juce__slider_r_acc_y"
          virtualName="" explicitFocusOrder="0" pos="79% 21.176% 20% 10%"
          bkgcol="ff263238" trackcol="ff263238" rotarysliderfill="ff263238"
          min="0.0" max="1.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="R_Acc_z" id="77e31f283a59e0ac" memberName="juce__slider_r_acc_z"
          virtualName="" explicitFocusOrder="0" pos="79% 34.118% 20% 10%"
          bkgcol="ff263238" trackcol="ff263238" rotarysliderfill="ff263238"
          min="0.0" max="1.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="R_Gyr_x" id="ec407bcaab06cb9b" memberName="juce__slider_r_gyr_x"
          virtualName="" explicitFocusOrder="0" pos="79% 55% 20% 10%" bkgcol="ff263238"
          trackcol="ff263238" rotarysliderfill="ff263238" min="-500.0"
          max="500.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="R_Gyr_y" id="b857e28523eb6ea1" memberName="juce__slider_r_gyr_y"
          virtualName="" explicitFocusOrder="0" pos="79% 67.647% 20% 10%"
          bkgcol="ff263238" trackcol="ff263238" rotarysliderfill="ff263238"
          min="-500.0" max="500.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="R_Gyr_z" id="95df5889bdf0a2ba" memberName="juce__slider_r_gyr_z"
          virtualName="" explicitFocusOrder="0" pos="79% 80.294% 20% 10%"
          bkgcol="ff263238" trackcol="ff263238" rotarysliderfill="ff263238"
          min="-500.0" max="500.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <TOGGLEBUTTON name="Left_JC_IMU_toggle" id="9b99ae182d27bbd5" memberName="juce__toggleButton_L_IMU"
                virtualName="" explicitFocusOrder="0" pos="44% 35% 82 24" buttonText="Left IMU"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="Right_JC_IMU_toggle" id="c42986959dcca701" memberName="juce__toggleButton_R_IMU"
                virtualName="" explicitFocusOrder="0" pos="44% 50% 82 24" buttonText="Right IMU"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TEXTBUTTON name="L_Virb_button" id="ba471e8ab99c2e40" memberName="juce__textButton_L_Virb"
              virtualName="" explicitFocusOrder="0" pos="41.714% 87.059% 6% 6.471%"
              bgColOn="ff5f9ea0" buttonText="vib" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="R_Virb_button" id="85734151709505e4" memberName="juce__textButton_R_Virb"
              virtualName="" explicitFocusOrder="0" pos="53.286% 87.059% 6.143% 6.176%"
              bgColOn="ff5f9ea0" buttonText="vib" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

