/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.12

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "AccessController_UI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
AccessController_UI::AccessController_UI ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    Stick_UI.reset(new StickGUI());
    addAndMakeVisible(Stick_UI.get());
    //[/Constructor_pre]

    juce__textButton_1.reset (new juce::TextButton ("button1"));
    addAndMakeVisible (juce__textButton_1.get());
    juce__textButton_1->setButtonText (TRANS ("B1"));
    juce__textButton_1->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_2.reset (new juce::TextButton ("button2"));
    addAndMakeVisible (juce__textButton_2.get());
    juce__textButton_2->setButtonText (TRANS ("B2"));
    juce__textButton_2->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_3.reset (new juce::TextButton ("button3"));
    addAndMakeVisible (juce__textButton_3.get());
    juce__textButton_3->setButtonText (TRANS ("B3"));
    juce__textButton_3->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_5.reset (new juce::TextButton ("button5"));
    addAndMakeVisible (juce__textButton_5.get());
    juce__textButton_5->setButtonText (TRANS ("B5"));
    juce__textButton_5->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_4.reset (new juce::TextButton ("button4"));
    addAndMakeVisible (juce__textButton_4.get());
    juce__textButton_4->setButtonText (TRANS ("B4"));
    juce__textButton_4->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_7.reset (new juce::TextButton ("button7"));
    addAndMakeVisible (juce__textButton_7.get());
    juce__textButton_7->setButtonText (TRANS ("B7"));
    juce__textButton_7->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_8.reset (new juce::TextButton ("button8"));
    addAndMakeVisible (juce__textButton_8.get());
    juce__textButton_8->setButtonText (TRANS ("B8"));
    juce__textButton_8->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_6.reset (new juce::TextButton ("button6"));
    addAndMakeVisible (juce__textButton_6.get());
    juce__textButton_6->setButtonText (TRANS ("B6"));
    juce__textButton_6->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_0.reset (new juce::TextButton ("button0"));
    addAndMakeVisible (juce__textButton_0.get());
    juce__textButton_0->setButtonText (TRANS ("B0"));
    juce__textButton_0->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_profile.reset (new juce::TextButton ("b_profile"));
    addAndMakeVisible (juce__textButton_profile.get());
    juce__textButton_profile->setButtonText (TRANS ("Profile"));
    juce__textButton_profile->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_PS.reset (new juce::TextButton ("button_PS"));
    addAndMakeVisible (juce__textButton_PS.get());
    juce__textButton_PS->setButtonText (TRANS ("PS"));
    juce__textButton_PS->setColour (juce::TextButton::buttonOnColourId, juce::Colours::cadetblue);

    juce__textButton_ChangeDevice.reset (new juce::TextButton ("ChangeDevice_button"));
    addAndMakeVisible (juce__textButton_ChangeDevice.get());
    juce__textButton_ChangeDevice->setButtonText (TRANS ("Change Device"));
    juce__textButton_ChangeDevice->addListener (this);
    juce__textButton_ChangeDevice->setColour (juce::TextButton::buttonColourId, juce::Colours::red);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (700, 400);


    //[Constructor] You can add your own custom stuff here..
    setFramesPerSecond(1);
    isConnected = false;
    //[/Constructor]
}

AccessController_UI::~AccessController_UI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    juce__textButton_1 = nullptr;
    juce__textButton_2 = nullptr;
    juce__textButton_3 = nullptr;
    juce__textButton_5 = nullptr;
    juce__textButton_4 = nullptr;
    juce__textButton_7 = nullptr;
    juce__textButton_8 = nullptr;
    juce__textButton_6 = nullptr;
    juce__textButton_0 = nullptr;
    juce__textButton_profile = nullptr;
    juce__textButton_PS = nullptr;
    juce__textButton_ChangeDevice = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    Stick_UI = nullptr;
    //[/Destructor]
}

//==============================================================================
void AccessController_UI::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    {
        float x = static_cast<float> (proportionOfWidth (0.6900f) - (proportionOfWidth (0.3971f) / 2)), y = static_cast<float> (proportionOfHeight (0.4525f) - (proportionOfHeight (0.6950f) / 2)), width = static_cast<float> (proportionOfWidth (0.3971f)), height = static_cast<float> (proportionOfHeight (0.6950f));
        juce::Colour strokeColour = juce::Colour (0xff6493ed);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.drawEllipse (x, y, width, height, 8.000f);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void AccessController_UI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    Stick_UI->setBounds (proportionOfWidth (0.1f), proportionOfHeight (0.22f), proportionOfWidth (0.26f), proportionOfHeight (0.44f));
    //[/UserPreResize]

    juce__textButton_1->setBounds (proportionOfWidth (0.4397f), proportionOfHeight (0.4045f), proportionOfWidth (0.1102f), proportionOfHeight (0.1098f));
    juce__textButton_2->setBounds (proportionOfWidth (0.4730f), proportionOfHeight (0.6146f), proportionOfWidth (0.1102f), proportionOfHeight (0.1098f));
    juce__textButton_3->setBounds (proportionOfWidth (0.6362f), proportionOfHeight (0.7470f), proportionOfWidth (0.1102f), proportionOfHeight (0.1098f));
    juce__textButton_5->setBounds (proportionOfWidth (0.8326f), proportionOfHeight (0.4045f), proportionOfWidth (0.1102f), proportionOfHeight (0.1098f));
    juce__textButton_4->setBounds (proportionOfWidth (0.7911f), proportionOfHeight (0.6146f), proportionOfWidth (0.1102f), proportionOfHeight (0.1098f));
    juce__textButton_7->setBounds (proportionOfWidth (0.6362f), proportionOfHeight (0.0525f), proportionOfWidth (0.1102f), proportionOfHeight (0.1098f));
    juce__textButton_8->setBounds (proportionOfWidth (0.4730f), proportionOfHeight (0.2100f), proportionOfWidth (0.1102f), proportionOfHeight (0.1098f));
    juce__textButton_6->setBounds (proportionOfWidth (0.7911f), proportionOfHeight (0.2100f), proportionOfWidth (0.1102f), proportionOfHeight (0.1098f));
    juce__textButton_0->setBounds (proportionOfWidth (0.6289f), proportionOfHeight (0.3604f), proportionOfWidth (0.1299f), proportionOfHeight (0.2005f));
    juce__textButton_profile->setBounds (proportionOfWidth (0.1902f), proportionOfHeight (0.7673f), proportionOfWidth (0.0811f), proportionOfHeight (0.0644f));
    juce__textButton_PS->setBounds (proportionOfWidth (0.0146f), proportionOfHeight (0.4224f), proportionOfWidth (0.0509f), proportionOfHeight (0.0549f));
    juce__textButton_ChangeDevice->setBounds (proportionOfWidth (0.8700f), proportionOfHeight (0.0095f), 89, 19);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void AccessController_UI::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == juce__textButton_ChangeDevice.get())
    {
        //[UserButtonCode_juce__textButton_ChangeDevice] -- add your button handler code here..
        changeDevice();
        //[/UserButtonCode_juce__textButton_ChangeDevice]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void AccessController_UI::update()
{
    if(isConnected){
        setFramesPerSecond(12);
        Stick_UI->updatePoint(AC_input.stick.x, AC_input.stick.y, AC_input.stick.stickPress);
        juce__textButton_0->setToggleState(AC_input.buttons.b0, juce::sendNotification);
        juce__textButton_1->setToggleState(AC_input.buttons.b1, juce::sendNotification);
        juce__textButton_2->setToggleState(AC_input.buttons.b2, juce::sendNotification);
        juce__textButton_3->setToggleState(AC_input.buttons.b3, juce::sendNotification);
        juce__textButton_4->setToggleState(AC_input.buttons.b4, juce::sendNotification);
        juce__textButton_5->setToggleState(AC_input.buttons.b5, juce::sendNotification);
        juce__textButton_6->setToggleState(AC_input.buttons.b6, juce::sendNotification);
        juce__textButton_7->setToggleState(AC_input.buttons.b7, juce::sendNotification);
        juce__textButton_8->setToggleState(AC_input.buttons.b8, juce::sendNotification);
        juce__textButton_profile->setToggleState(AC_input.buttons.profile, juce::sendNotification);
        juce__textButton_PS->setToggleState(AC_input.buttons.ps, juce::sendNotification);

        AC_EnableStats.StickStates.x = Stick_UI->enableX;
        AC_EnableStats.StickStates.y = Stick_UI->enableY;
    }
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="AccessController_UI" componentName=""
                 parentClasses="public juce::AnimatedAppComponent" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="0" snapShown="0"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="700" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44">
    <ELLIPSE pos="69%c 45.25%c 39.714% 69.5%" fill="solid: a52a5a" hasStroke="1"
             stroke="8, mitered, butt" strokeColour="solid: ff6493ed"/>
  </BACKGROUND>
  <TEXTBUTTON name="button1" id="664054e5b09e5f11" memberName="juce__textButton_1"
              virtualName="" explicitFocusOrder="0" pos="43.971% 40.453% 11.019% 10.979%"
              bgColOn="ff5f9ea0" buttonText="B1" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="button2" id="fd10f6d139823ceb" memberName="juce__textButton_2"
              virtualName="" explicitFocusOrder="0" pos="47.297% 61.456% 11.019% 10.979%"
              bgColOn="ff5f9ea0" buttonText="B2" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="button3" id="daae4dbfb98a0c96" memberName="juce__textButton_3"
              virtualName="" explicitFocusOrder="0" pos="63.617% 74.702% 11.019% 10.979%"
              bgColOn="ff5f9ea0" buttonText="B3" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="button5" id="a0482edfcd56ec25" memberName="juce__textButton_5"
              virtualName="" explicitFocusOrder="0" pos="83.264% 40.453% 11.019% 10.979%"
              bgColOn="ff5f9ea0" buttonText="B5" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="button4" id="647f17aeb78668da" memberName="juce__textButton_4"
              virtualName="" explicitFocusOrder="0" pos="79.106% 61.456% 11.019% 10.979%"
              bgColOn="ff5f9ea0" buttonText="B4" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="button7" id="d60dcd27addc1e8d" memberName="juce__textButton_7"
              virtualName="" explicitFocusOrder="0" pos="63.617% 5.251% 11.019% 10.979%"
              bgColOn="ff5f9ea0" buttonText="B7" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="button8" id="8fdd74b193eb094" memberName="juce__textButton_8"
              virtualName="" explicitFocusOrder="0" pos="47.297% 21.002% 11.019% 10.979%"
              bgColOn="ff5f9ea0" buttonText="B8" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="button6" id="acd8a54b23929c2" memberName="juce__textButton_6"
              virtualName="" explicitFocusOrder="0" pos="79.106% 21.002% 11.019% 10.979%"
              bgColOn="ff5f9ea0" buttonText="B6" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="button0" id="9ae34858d2104cba" memberName="juce__textButton_0"
              virtualName="" explicitFocusOrder="0" pos="62.89% 36.038% 12.994% 20.048%"
              bgColOn="ff5f9ea0" buttonText="B0" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="b_profile" id="2e9ff81fc46d23b1" memberName="juce__textButton_profile"
              virtualName="" explicitFocusOrder="0" pos="19.023% 76.73% 8.108% 6.444%"
              bgColOn="ff5f9ea0" buttonText="Profile" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="button_PS" id="2371879eb5f17bdd" memberName="juce__textButton_PS"
              virtualName="" explicitFocusOrder="0" pos="1.455% 42.243% 5.094% 5.489%"
              bgColOn="ff5f9ea0" buttonText="PS" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="ChangeDevice_button" id="22ebb74a08c1917" memberName="juce__textButton_ChangeDevice"
              virtualName="" explicitFocusOrder="0" pos="87.006% 0.955% 89 19"
              bgColOff="ffff0000" buttonText="Change Device" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

