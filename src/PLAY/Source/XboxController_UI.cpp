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

#include "XboxController_UI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
XboxController_UI::XboxController_UI ()
{
    //[Constructor_pre] You can add your own custom stuff here..

    Left_Stick.reset(new StickGUI());
    addAndMakeVisible(Left_Stick.get());

    Right_Stick.reset(new StickGUI());
    addAndMakeVisible(Right_Stick.get());
    //[/Constructor_pre]

    juce__textButtonX.reset (new juce::TextButton ("ButtonX"));
    addAndMakeVisible (juce__textButtonX.get());
    juce__textButtonX->setButtonText (TRANS ("X"));
    juce__textButtonX->setColour (juce::TextButton::buttonOnColourId, juce::Colour (0x5f7fffd4));

    juce__textButtonY.reset (new juce::TextButton ("ButtonY"));
    addAndMakeVisible (juce__textButtonY.get());
    juce__textButtonY->setButtonText (TRANS ("Y"));
    juce__textButtonY->setColour (juce::TextButton::buttonOnColourId, juce::Colour (0x5f7fffd4));

    juce__textButtonA.reset (new juce::TextButton ("ButtonA"));
    addAndMakeVisible (juce__textButtonA.get());
    juce__textButtonA->setButtonText (TRANS ("A"));
    juce__textButtonA->setColour (juce::TextButton::buttonOnColourId, juce::Colour (0x5f7fffd4));

    juce__textButtonB.reset (new juce::TextButton ("ButtonB"));
    addAndMakeVisible (juce__textButtonB.get());
    juce__textButtonB->setButtonText (TRANS ("B"));
    juce__textButtonB->setColour (juce::TextButton::buttonOnColourId, juce::Colour (0x5f7fffd4));

    juce__textButtonView.reset (new juce::TextButton ("ButtonView"));
    addAndMakeVisible (juce__textButtonView.get());
    juce__textButtonView->setButtonText (TRANS ("View"));
    juce__textButtonView->setColour (juce::TextButton::buttonOnColourId, juce::Colour (0x5f7fffd4));

    juce__textButtonLeft.reset (new juce::TextButton ("ButtonLeft"));
    addAndMakeVisible (juce__textButtonLeft.get());
    juce__textButtonLeft->setButtonText (TRANS ("L"));
    juce__textButtonLeft->setColour (juce::TextButton::buttonOnColourId, juce::Colour (0x5f7fffd4));

    juce__textButtonUp.reset (new juce::TextButton ("ButtonUp"));
    addAndMakeVisible (juce__textButtonUp.get());
    juce__textButtonUp->setButtonText (TRANS ("U"));
    juce__textButtonUp->setColour (juce::TextButton::buttonOnColourId, juce::Colour (0x5f7fffd4));

    juce__textButtonDown.reset (new juce::TextButton ("ButtonDown"));
    addAndMakeVisible (juce__textButtonDown.get());
    juce__textButtonDown->setButtonText (TRANS ("D"));
    juce__textButtonDown->setColour (juce::TextButton::buttonOnColourId, juce::Colour (0x5f7fffd4));

    juce__textButtonRight.reset (new juce::TextButton ("ButtonRight"));
    addAndMakeVisible (juce__textButtonRight.get());
    juce__textButtonRight->setButtonText (TRANS ("R"));
    juce__textButtonRight->setColour (juce::TextButton::buttonOnColourId, juce::Colour (0x5f7fffd4));

    juce__textButtonShare.reset (new juce::TextButton ("ButtonShare"));
    addAndMakeVisible (juce__textButtonShare.get());
    juce__textButtonShare->setButtonText (TRANS ("Share"));
    juce__textButtonShare->setColour (juce::TextButton::buttonOnColourId, juce::Colour (0x5f7fffd4));

    juce__textButtonMenu.reset (new juce::TextButton ("ButtonMenu"));
    addAndMakeVisible (juce__textButtonMenu.get());
    juce__textButtonMenu->setButtonText (TRANS ("Menu"));
    juce__textButtonMenu->setColour (juce::TextButton::buttonOnColourId, juce::Colour (0x5f7fffd4));

    juce__textButtonLB.reset (new juce::TextButton ("ButtonLB"));
    addAndMakeVisible (juce__textButtonLB.get());
    juce__textButtonLB->setButtonText (TRANS ("LB"));
    juce__textButtonLB->setColour (juce::TextButton::buttonOnColourId, juce::Colour (0x5f7fffd4));

    juce__textButtonRB.reset (new juce::TextButton ("ButtonRB"));
    addAndMakeVisible (juce__textButtonRB.get());
    juce__textButtonRB->setButtonText (TRANS ("RB"));
    juce__textButtonRB->setColour (juce::TextButton::buttonOnColourId, juce::Colour (0x5f7fffd4));

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

    juce__textButton_vibration.reset (new juce::TextButton ("vibration"));
    addAndMakeVisible (juce__textButton_vibration.get());
    juce__textButton_vibration->addListener (this);

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
    isConnected = false;
    setVibrationData();
    //[/Constructor]
}

XboxController_UI::~XboxController_UI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    juce__textButtonX = nullptr;
    juce__textButtonY = nullptr;
    juce__textButtonA = nullptr;
    juce__textButtonB = nullptr;
    juce__textButtonView = nullptr;
    juce__textButtonLeft = nullptr;
    juce__textButtonUp = nullptr;
    juce__textButtonDown = nullptr;
    juce__textButtonRight = nullptr;
    juce__textButtonShare = nullptr;
    juce__textButtonMenu = nullptr;
    juce__textButtonLB = nullptr;
    juce__textButtonRB = nullptr;
    juce__slider_L_Trigger = nullptr;
    juce__slider_R_Trigger = nullptr;
    juce__textButton_vibration = nullptr;
    juce__textButton_ChangeDevice = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    Left_Stick = nullptr;
    Right_Stick = nullptr;
    //[/Destructor]
}

//==============================================================================
void XboxController_UI::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    {
        float x = 0, y = 0;
        juce::Colour strokeColour = juce::Colour (0xff232323);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.strokePath (internalPath1, juce::PathStrokeType (5.000f), juce::AffineTransform::translation (x, y));
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void XboxController_UI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    juce__textButtonX->setBounds (proportionOfWidth (0.6129f), proportionOfHeight (0.2700f), 25, 25);
    juce__textButtonY->setBounds (proportionOfWidth (0.6629f), proportionOfHeight (0.1850f), 25, 25);
    juce__textButtonA->setBounds (proportionOfWidth (0.6629f), proportionOfHeight (0.3550f), 25, 25);
    juce__textButtonB->setBounds (proportionOfWidth (0.7100f), proportionOfHeight (0.2700f), 25, 25);
    juce__textButtonView->setBounds (proportionOfWidth (0.4257f), proportionOfHeight (0.2800f), 30, 15);
    juce__textButtonLeft->setBounds (proportionOfWidth (0.3543f), proportionOfHeight (0.4800f), 20, 20);
    juce__textButtonUp->setBounds (proportionOfWidth (0.3900f), proportionOfHeight (0.4200f), 20, 20);
    juce__textButtonDown->setBounds (proportionOfWidth (0.3900f), proportionOfHeight (0.5400f), 20, 20);
    juce__textButtonRight->setBounds (proportionOfWidth (0.4257f), proportionOfHeight (0.4800f), 20, 20);
    juce__textButtonShare->setBounds (proportionOfWidth (0.4743f), proportionOfHeight (0.3525f), 30, 15);
    juce__textButtonMenu->setBounds (proportionOfWidth (0.5286f), proportionOfHeight (0.2800f), 30, 15);
    juce__textButtonLB->setBounds (proportionOfWidth (0.2900f), proportionOfHeight (0.0400f), 50, 20);
    juce__textButtonRB->setBounds (proportionOfWidth (0.6257f), proportionOfHeight (0.0400f), 50, 20);
    juce__slider_L_Trigger->setBounds (proportionOfWidth (0.0300f), proportionOfHeight (0.1000f), proportionOfWidth (0.1086f), proportionOfHeight (0.6000f));
    juce__slider_R_Trigger->setBounds (proportionOfWidth (0.8700f), proportionOfHeight (0.1000f), proportionOfWidth (0.1000f), proportionOfHeight (0.6000f));
    juce__textButton_vibration->setBounds (proportionOfWidth (0.3743f), proportionOfHeight (0.8000f), 150, 24);
    juce__textButton_ChangeDevice->setBounds (proportionOfWidth (0.8586f), proportionOfHeight (0.0275f), proportionOfWidth (0.1271f), proportionOfHeight (0.0475f));
    internalPath1.clear();
    internalPath1.startNewSubPath (static_cast<float> (proportionOfWidth (0.5067f)), static_cast<float> (proportionOfHeight (0.1177f)));
    internalPath1.lineTo (static_cast<float> (proportionOfWidth (0.7333f)), static_cast<float> (proportionOfHeight (0.1177f)));
    internalPath1.cubicTo (static_cast<float> (proportionOfWidth (0.7600f)), static_cast<float> (proportionOfHeight (0.2118f)), static_cast<float> (proportionOfWidth (0.9467f)), static_cast<float> (proportionOfHeight (0.8471f)), static_cast<float> (proportionOfWidth (0.8000f)), static_cast<float> (proportionOfHeight (0.9412f)));
    internalPath1.quadraticTo (static_cast<float> (proportionOfWidth (0.7600f)), static_cast<float> (proportionOfHeight (0.9412f)), static_cast<float> (proportionOfWidth (0.6667f)), static_cast<float> (proportionOfHeight (0.7059f)));
    internalPath1.lineTo (static_cast<float> (proportionOfWidth (0.3333f)), static_cast<float> (proportionOfHeight (0.7059f)));
    internalPath1.quadraticTo (static_cast<float> (proportionOfWidth (0.2533f)), static_cast<float> (proportionOfHeight (0.9176f)), static_cast<float> (proportionOfWidth (0.2133f)), static_cast<float> (proportionOfHeight (0.9412f)));
    internalPath1.cubicTo (static_cast<float> (proportionOfWidth (0.0800f)), static_cast<float> (proportionOfHeight (0.9176f)), static_cast<float> (proportionOfWidth (0.1867f)), static_cast<float> (proportionOfHeight (0.2823f)), static_cast<float> (proportionOfWidth (0.2667f)), static_cast<float> (proportionOfHeight (0.1177f)));
    internalPath1.closeSubPath();

    //[UserResized] Add your own custom resize handling here..
    Left_Stick->setBounds (proportionOfWidth (0.25), proportionOfHeight (0.17f), proportionOfWidth (0.15f), proportionOfHeight (0.23f));
    Right_Stick->setBounds (proportionOfWidth (0.52), proportionOfHeight (0.44f), proportionOfWidth (0.15f), proportionOfHeight (0.23f));
    //[/UserResized]
}

void XboxController_UI::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == juce__textButton_vibration.get())
    {
        //[UserButtonCode_juce__textButton_vibration] -- add your button handler code here..

        XboxVibration();
        //[/UserButtonCode_juce__textButton_vibration]
    }
    else if (buttonThatWasClicked == juce__textButton_ChangeDevice.get())
    {
        //[UserButtonCode_juce__textButton_ChangeDevice] -- add your button handler code here..
        changeDevice();
        //[/UserButtonCode_juce__textButton_ChangeDevice]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void XboxController_UI::update()
{
//    setFramesPerSecond (20);
    if (isConnected){
        setFramesPerSecond (12);

        juce__textButtonA->setToggleState(_input.buttons.a,  juce::sendNotification);
        juce__textButtonB->setToggleState(_input.buttons.b,  juce::sendNotification);
        juce__textButtonX->setToggleState(_input.buttons.x,  juce::sendNotification);
        juce__textButtonY->setToggleState(_input.buttons.y,  juce::sendNotification);

        juce__textButtonRB->setToggleState(_input.buttons.rb,  juce::sendNotification);
        juce__textButtonLB->setToggleState(_input.buttons.lb,  juce::sendNotification);

        juce__textButtonView->setToggleState(_input.buttons.view,  juce::sendNotification);
        juce__textButtonShare->setToggleState(_input.buttons.share,  juce::sendNotification);
        juce__textButtonMenu->setToggleState(_input.buttons.menu,  juce::sendNotification);

        juce__textButtonUp->setToggleState(_input.dpad.up,  juce::sendNotification);
        juce__textButtonDown->setToggleState(_input.dpad.down,  juce::sendNotification);
        juce__textButtonLeft->setToggleState(_input.dpad.left,  juce::sendNotification);
        juce__textButtonRight->setToggleState(_input.dpad.right,  juce::sendNotification);

        Left_Stick->updatePoint(_input.leftStick.x, _input.leftStick.y, _input.leftStick.stickPress);
        Right_Stick->updatePoint(_input.rightStick.x, _input.rightStick.y, _input.rightStick.stickPress);

        juce__slider_L_Trigger->setValue(std::clamp(_input.leftTrigger, 0.f, 1.0f));
        juce__slider_R_Trigger->setValue(std::clamp(_input.rightTrigger, 0.f, 1.0f));

    }else{
        setFramesPerSecond (1);
    }


    //Left_Stick.updatePoint(0.2,0.1,1);
}
void XboxController_UI::setVibrationData()
{
    // https://github.com/quantus/xbox-one-controller-protocol
    VibrationData[0] = 0x07;
    VibrationData[1] = 0x0F; // Atleast one of 0x07 bits must be on
    VibrationData[2] = 0x00; // Dummy ?
    VibrationData[3] = 0x20; // L force
    VibrationData[4] = 0x20; // R force
    VibrationData[5] = 0x10; // length
    VibrationData[6] = 0x10; // period
    VibrationData[7] = 0x01; // Effect extra play count (0x02 means that effect is played 1+2 times)
    VibrationData[8] = 0x00; // Dummy ?

    return ;
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="XboxController_UI" componentName=""
                 parentClasses="public juce::AnimatedAppComponent" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="0" snapShown="0"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="700" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44">
    <PATH pos="0 0 100 100" fill="solid: 642aa5" hasStroke="1" stroke="5, mitered, butt"
          strokeColour="solid: ff232323" nonZeroWinding="1">s 50.667% 11.765% l 73.333% 11.765% c 76% 21.176% 94.667% 84.706%  80% 94.118% q 76% 94.118% 66.667% 70.588% l 33.333% 70.588% q 25.333% 91.765% 21.333% 94.118% c 8% 91.765% 18.667% 28.235%  26.667% 11.765% x</PATH>
  </BACKGROUND>
  <TEXTBUTTON name="ButtonX" id="dbbbdb024f1ff6a0" memberName="juce__textButtonX"
              virtualName="" explicitFocusOrder="0" pos="61.286% 27% 25 25"
              bgColOn="5f7fffd4" buttonText="X" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="ButtonY" id="4a5ce7bc3858ac8" memberName="juce__textButtonY"
              virtualName="" explicitFocusOrder="0" pos="66.286% 18.5% 25 25"
              posRelativeW="dbbbdb024f1ff6a0" posRelativeH="dbbbdb024f1ff6a0"
              bgColOn="5f7fffd4" buttonText="Y" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="ButtonA" id="4732bb47b4196ef4" memberName="juce__textButtonA"
              virtualName="" explicitFocusOrder="0" pos="66.286% 35.5% 25 25"
              bgColOn="5f7fffd4" buttonText="A" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="ButtonB" id="b2f40fb4daba0b" memberName="juce__textButtonB"
              virtualName="" explicitFocusOrder="0" pos="71% 27% 25 25" bgColOn="5f7fffd4"
              buttonText="B" connectedEdges="0" needsCallback="0" radioGroupId="0"/>
  <TEXTBUTTON name="ButtonView" id="2ec1cc9996d74cb6" memberName="juce__textButtonView"
              virtualName="" explicitFocusOrder="0" pos="42.571% 28% 30 15"
              bgColOn="5f7fffd4" buttonText="View" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="ButtonLeft" id="9d943df2d7e5a92c" memberName="juce__textButtonLeft"
              virtualName="" explicitFocusOrder="0" pos="35.429% 48% 20 20"
              bgColOn="5f7fffd4" buttonText="L" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="ButtonUp" id="8eb72bdfaab10e19" memberName="juce__textButtonUp"
              virtualName="" explicitFocusOrder="0" pos="39% 42% 20 20" posRelativeW="dbbbdb024f1ff6a0"
              posRelativeH="dbbbdb024f1ff6a0" bgColOn="5f7fffd4" buttonText="U"
              connectedEdges="0" needsCallback="0" radioGroupId="0"/>
  <TEXTBUTTON name="ButtonDown" id="1662ca70f842ff72" memberName="juce__textButtonDown"
              virtualName="" explicitFocusOrder="0" pos="39% 54% 20 20" bgColOn="5f7fffd4"
              buttonText="D" connectedEdges="0" needsCallback="0" radioGroupId="0"/>
  <TEXTBUTTON name="ButtonRight" id="37e4b6bd1ab69340" memberName="juce__textButtonRight"
              virtualName="" explicitFocusOrder="0" pos="42.571% 48% 20 20"
              bgColOn="5f7fffd4" buttonText="R" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="ButtonShare" id="2d216db01c9308fa" memberName="juce__textButtonShare"
              virtualName="" explicitFocusOrder="0" pos="47.429% 35.25% 30 15"
              bgColOn="5f7fffd4" buttonText="Share" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="ButtonMenu" id="544df2d3cd2b549e" memberName="juce__textButtonMenu"
              virtualName="" explicitFocusOrder="0" pos="52.857% 28% 30 15"
              bgColOn="5f7fffd4" buttonText="Menu" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="ButtonLB" id="14cf67a7e5cde685" memberName="juce__textButtonLB"
              virtualName="" explicitFocusOrder="0" pos="29% 4% 50 20" bgColOn="5f7fffd4"
              buttonText="LB" connectedEdges="0" needsCallback="0" radioGroupId="0"/>
  <TEXTBUTTON name="ButtonRB" id="5c36d320842a89c3" memberName="juce__textButtonRB"
              virtualName="" explicitFocusOrder="0" pos="62.571% 4% 50 20"
              bgColOn="5f7fffd4" buttonText="RB" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <SLIDER name="L_Trigger" id="108db3ed35a76737" memberName="juce__slider_L_Trigger"
          virtualName="" explicitFocusOrder="0" pos="3% 10% 10.857% 60%"
          min="0.0" max="1.0" int="0.01" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="60" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="R_Trigger" id="154ab14c02d0fc10" memberName="juce__slider_R_Trigger"
          virtualName="" explicitFocusOrder="0" pos="87% 10% 10% 60%" min="0.0"
          max="1.0" int="0.01" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="60" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <TEXTBUTTON name="vibration" id="feb507671c52498c" memberName="juce__textButton_vibration"
              virtualName="" explicitFocusOrder="0" pos="37.429% 80% 150 24"
              buttonText="vibration" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="ChangeDevice_button" id="22ebb74a08c1917" memberName="juce__textButton_ChangeDevice"
              virtualName="" explicitFocusOrder="0" pos="85.857% 2.75% 12.714% 4.75%"
              bgColOff="ffff0000" buttonText="Change Device" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

