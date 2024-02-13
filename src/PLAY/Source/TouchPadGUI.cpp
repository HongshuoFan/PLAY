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

#include "TouchPadGUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TouchPadGUI::TouchPadGUI ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    juce__toggleButton_p1x.reset (new juce::ToggleButton ("P1_X_toggle"));
    addAndMakeVisible (juce__toggleButton_p1x.get());
    juce__toggleButton_p1x->setButtonText (TRANS ("P1_X"));
    juce__toggleButton_p1x->addListener (this);
    juce__toggleButton_p1x->setToggleState (true, juce::dontSendNotification);

    juce__toggleButton_p1y.reset (new juce::ToggleButton ("P1_Y_toggle"));
    addAndMakeVisible (juce__toggleButton_p1y.get());
    juce__toggleButton_p1y->setButtonText (TRANS ("P1_Y"));
    juce__toggleButton_p1y->addListener (this);
    juce__toggleButton_p1y->setToggleState (true, juce::dontSendNotification);

    juce__toggleButton_p2x.reset (new juce::ToggleButton ("P2_X_toggle"));
    addAndMakeVisible (juce__toggleButton_p2x.get());
    juce__toggleButton_p2x->setButtonText (TRANS ("P2_X"));
    juce__toggleButton_p2x->addListener (this);
    juce__toggleButton_p2x->setToggleState (true, juce::dontSendNotification);

    juce__toggleButton_p2y.reset (new juce::ToggleButton ("P2_Y_toggle"));
    addAndMakeVisible (juce__toggleButton_p2y.get());
    juce__toggleButton_p2y->setButtonText (TRANS ("P2_Y"));
    juce__toggleButton_p2y->addListener (this);
    juce__toggleButton_p2y->setToggleState (true, juce::dontSendNotification);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (208, 208);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

TouchPadGUI::~TouchPadGUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    juce__toggleButton_p1x = nullptr;
    juce__toggleButton_p1y = nullptr;
    juce__toggleButton_p2x = nullptr;
    juce__toggleButton_p2y = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TouchPadGUI::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    {
        int x = proportionOfWidth (0.0050f), y = proportionOfHeight (0.0050f), width = proportionOfWidth (0.9904f), height = proportionOfHeight (0.9904f);
        juce::Colour strokeColour = juce::Colours::cadetblue;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        if(pressTouchPad){
            strokeColour = juce::Colours::blue;
        }
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 2);

    }

    {
        int x = proportionOfWidth (1.0336f), y = proportionOfHeight (1.4327f), width = proportionOfWidth (0.1827f), height = proportionOfHeight (0.1827f);
        juce::String text (TRANS ("P2"));
        juce::Colour fillColour = juce::Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    //[UserPaint] Add your own custom painting code here..
    {
        g.setFont (juce::Font (10.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        if(touchPoint1.down){
            g.setColour (onColour);
            g.fillEllipse (touchPoint1.x, touchPoint1.y, pointSize, pointSize);

            juce::String text_1 (TRANS ("1"));
            g.setColour (juce::Colours::black);
            //g.setFont (juce::Font (10.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
            g.drawText (text_1, touchPoint1.x, touchPoint1.y, pointSize, pointSize,
                        juce::Justification::centred, true);
        }
    }

    {
        if(touchPoint2.down){
            g.setColour (onColour);
            g.fillEllipse (touchPoint2.x, touchPoint2.y, pointSize, pointSize);

            juce::String text_2 (TRANS ("2"));
            g.setColour (juce::Colours::black);
            //g.setFont (juce::Font (10.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
            g.drawText (text_2, touchPoint2.x, touchPoint2.y, pointSize, pointSize,
                        juce::Justification::centred, true);
        }
    }
    //[/UserPaint]
}

void TouchPadGUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    juce__toggleButton_p1x->setBounds (proportionOfWidth (0.0144f), proportionOfHeight (0.6586f), proportionOfWidth (0.4471f), proportionOfHeight (0.1587f));
    juce__toggleButton_p1y->setBounds (proportionOfWidth (0.7260f), proportionOfHeight (0.0336f), proportionOfWidth (0.3365f), proportionOfHeight (0.1538f));
    juce__toggleButton_p2x->setBounds (proportionOfWidth (0.0144f), proportionOfHeight (0.8173f), proportionOfWidth (0.4471f), proportionOfHeight (0.1587f));
    juce__toggleButton_p2y->setBounds (proportionOfWidth (0.7260f), proportionOfHeight (0.2067f), proportionOfWidth (0.3365f), proportionOfHeight (0.1538f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void TouchPadGUI::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == juce__toggleButton_p1x.get())
    {
        //[UserButtonCode_juce__toggleButton_p1x] -- add your button handler code here..
        isP1Enable_x = juce__toggleButton_p1x->getToggleState();
        //[/UserButtonCode_juce__toggleButton_p1x]
    }
    else if (buttonThatWasClicked == juce__toggleButton_p1y.get())
    {
        //[UserButtonCode_juce__toggleButton_p1y] -- add your button handler code here..
        isP1Enable_y = juce__toggleButton_p1y->getToggleState();
        //[/UserButtonCode_juce__toggleButton_p1y]
    }
    else if (buttonThatWasClicked == juce__toggleButton_p2x.get())
    {
        //[UserButtonCode_juce__toggleButton_p2x] -- add your button handler code here..
        isP2Enable_x = juce__toggleButton_p2x->getToggleState();
        //[/UserButtonCode_juce__toggleButton_p2x]
    }
    else if (buttonThatWasClicked == juce__toggleButton_p2y.get())
    {
        //[UserButtonCode_juce__toggleButton_p2y] -- add your button handler code here..
        isP2Enable_y = juce__toggleButton_p2y->getToggleState();
        //[/UserButtonCode_juce__toggleButton_p2y]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void TouchPadGUI::updateTouchPad_1(DualSense::Touch Point1)
{
    if(Point1.down){
        float w = getWidth();
        float h = getHeight();

        touchPoint1.down = true;
        touchPoint1.x = Point1.x * proportionOfWidth (0.9f);
        touchPoint1.x = std::clamp( touchPoint1.x, 1.0f, w);

        touchPoint1.y = proportionOfHeight (0.9f) - (Point1.y * proportionOfHeight (0.9f));
        touchPoint1.y = std::clamp(touchPoint1.y, 1.0f, h);
        //std::cout<<"1:"<< touchPoint1.x << " "<<  touchPoint1.y<<"\n";
    }else{
        touchPoint1.down = false;

    }

}

void TouchPadGUI::updateTouchPad_2(DualSense::Touch Point2)
{
    if(Point2.down){
        float w = getWidth();
        float h = getHeight();

        touchPoint2.down = true;
        touchPoint2.x = Point2.x * proportionOfWidth (0.9f);
        touchPoint2.x = std::clamp( touchPoint2.x, 1.0f, w);

        touchPoint2.y = proportionOfHeight (0.9f) - (Point2.y * proportionOfHeight (0.9f));
        touchPoint2.y = std::clamp(touchPoint2.y, 1.0f, h);

    }else{
        touchPoint2.down = false;

    }

}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TouchPadGUI" componentName=""
                 parentClasses="public juce::Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="0" snapShown="0" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="208" initialHeight="208">
  <BACKGROUND backgroundColour="1076ce">
    <RECT pos="0.5% 0.5% 99.038% 99.038%" fill="solid: 34a52a" hasStroke="1"
          stroke="2, mitered, butt" strokeColour="solid: ff5f9ea0"/>
    <TEXT pos="103.365% 143.269% 18.269% 18.269%" fill="solid: ff000000"
          hasStroke="0" text="P2" fontname="Default font" fontsize="15.0"
          kerning="0.0" bold="0" italic="0" justification="36"/>
  </BACKGROUND>
  <TOGGLEBUTTON name="P1_X_toggle" id="67ea0a7ced2abfd5" memberName="juce__toggleButton_p1x"
                virtualName="" explicitFocusOrder="0" pos="1.442% 65.865% 44.712% 15.865%"
                buttonText="P1_X" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="1"/>
  <TOGGLEBUTTON name="P1_Y_toggle" id="f2c204a00d69bfc3" memberName="juce__toggleButton_p1y"
                virtualName="" explicitFocusOrder="0" pos="72.596% 3.365% 33.654% 15.385%"
                buttonText="P1_Y" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="1"/>
  <TOGGLEBUTTON name="P2_X_toggle" id="536b1f9c05cb482d" memberName="juce__toggleButton_p2x"
                virtualName="" explicitFocusOrder="0" pos="1.442% 81.731% 44.712% 15.865%"
                buttonText="P2_X" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="1"/>
  <TOGGLEBUTTON name="P2_Y_toggle" id="d392cfcd82c69278" memberName="juce__toggleButton_p2y"
                virtualName="" explicitFocusOrder="0" pos="72.596% 20.673% 33.654% 15.385%"
                buttonText="P2_Y" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

