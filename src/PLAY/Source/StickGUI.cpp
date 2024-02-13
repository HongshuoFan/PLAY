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

#include "StickGUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
StickGUI::StickGUI ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    px = getWidth()/2.f;
    py = getHeight()/2.f;
    //[/Constructor_pre]

    juce__toggleButton_stick_x.reset (new juce::ToggleButton ("Toggle_Stick_X"));
    addAndMakeVisible (juce__toggleButton_stick_x.get());
    juce__toggleButton_stick_x->setButtonText (TRANS ("X"));
    juce__toggleButton_stick_x->setConnectedEdges (juce::Button::ConnectedOnLeft | juce::Button::ConnectedOnBottom);
    juce__toggleButton_stick_x->addListener (this);
    juce__toggleButton_stick_x->setToggleState (true, juce::dontSendNotification);
    juce__toggleButton_stick_x->setColour (juce::ToggleButton::textColourId, juce::Colour (0x50ffffff));

    juce__toggleButton_stick_y.reset (new juce::ToggleButton ("toggle_Stick_Y"));
    addAndMakeVisible (juce__toggleButton_stick_y.get());
    juce__toggleButton_stick_y->setButtonText (TRANS ("Y"));
    juce__toggleButton_stick_y->setConnectedEdges (juce::Button::ConnectedOnRight | juce::Button::ConnectedOnTop);
    juce__toggleButton_stick_y->addListener (this);
    juce__toggleButton_stick_y->setToggleState (true, juce::dontSendNotification);
    juce__toggleButton_stick_y->setColour (juce::ToggleButton::textColourId, juce::Colour (0x50ffffff));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (104, 104);


    //[Constructor] You can add your own custom stuff here..
    enableX = true;
    enableY = true;
    //setSize (Stickheight*2, Stickheight*2);

    //[/Constructor]
}

StickGUI::~StickGUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    juce__toggleButton_stick_x = nullptr;
    juce__toggleButton_stick_y = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void StickGUI::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    {
        float x = static_cast<float> (proportionOfWidth (0.5000f) - (proportionOfWidth (0.9615f) / 2)), y = static_cast<float> (proportionOfHeight (0.5000f) - (proportionOfHeight (0.9615f) / 2)), width = static_cast<float> (proportionOfWidth (0.9615f)), height = static_cast<float> (proportionOfHeight (0.9615f));
        juce::Colour strokeColour = juce::Colour (0xff2aa582);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.drawRoundedRectangle (x, y, width, height, 10.000f, 2.000f);
    }

    //[UserPaint] Add your own custom painting code here..
    float width = 10.0f, height = 10.0f;
    g.setColour (pointColour);
    if(isnan(px) || isnan(py))
    {
        g.fillEllipse (10.f, 10.f, width, height);
    }else{
        g.fillEllipse (px, py, width, height);
    }

    //[/UserPaint]
}

void StickGUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    juce__toggleButton_stick_x->setBounds (proportionOfWidth (0.0577f), proportionOfHeight (0.7885f), proportionOfWidth (0.3269f), proportionOfHeight (0.1731f));
    juce__toggleButton_stick_y->setBounds (proportionOfWidth (0.6154f), proportionOfHeight (0.0577f), proportionOfWidth (0.3269f), proportionOfHeight (0.1731f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void StickGUI::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == juce__toggleButton_stick_x.get())
    {
        //[UserButtonCode_juce__toggleButton_stick_x] -- add your button handler code here..
        enableX = juce__toggleButton_stick_x->getToggleState();
        //[/UserButtonCode_juce__toggleButton_stick_x]
    }
    else if (buttonThatWasClicked == juce__toggleButton_stick_y.get())
    {
        //[UserButtonCode_juce__toggleButton_stick_y] -- add your button handler code here..
        enableY = juce__toggleButton_stick_y->getToggleState();
        //[/UserButtonCode_juce__toggleButton_stick_y]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void StickGUI::mouseDrag (const juce::MouseEvent& e)
{
    //[UserCode_mouseDrag] -- Add your code here...
//
//    float mouseOffsetX = e.getOffsetFromDragStart().getX();
//    float mouseOffsetY = e.getOffsetFromDragStart().getY();
//    float X_diff = previousMouseX - mouseOffsetX;
//    float Y_diff = previousMouseY - mouseOffsetY;
//    px += X_diff;
//    py += Y_diff;
//
////    std::cout<< nX<<"\n";
//    updatePoint(px,py,0);
    //[/UserCode_mouseDrag]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void StickGUI::updatePoint(float x, float y, bool button)
{

    px = x * proportionOfWidth (0.9f);
    //px = fmax(1, fmin(px, getWidth()));
    float w = getWidth();
    px = std::clamp(px, 1.0f, w);

    py = proportionOfHeight (0.9f) - (y * proportionOfHeight (0.9f));
    float h = getHeight();
    py = std::clamp(py, 1.0f, h);

    if (button){
        pointColour = onColour;
    }else{
        pointColour = offColour;
    }

}

void StickGUI::changeStates(bool new_states)
{
    juce__toggleButton_stick_x->setToggleState (new_states, juce::sendNotification);
    juce__toggleButton_stick_y->setToggleState (new_states, juce::sendNotification);
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="StickGUI" componentName=""
                 parentClasses="public juce::Component" constructorParams="" variableInitialisers=""
                 snapPixels="2" snapActive="0" snapShown="0" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="104" initialHeight="104">
  <METHODS>
    <METHOD name="mouseDrag (const juce::MouseEvent&amp; e)"/>
  </METHODS>
  <BACKGROUND backgroundColour="323e44">
    <ROUNDRECT pos="50%c 50%c 96.154% 96.154%" cornerSize="10.0" fill="solid: a5852a"
               hasStroke="1" stroke="2, mitered, butt" strokeColour="solid: ff2aa582"/>
  </BACKGROUND>
  <TOGGLEBUTTON name="Toggle_Stick_X" id="ce6f09ac788bf2b9" memberName="juce__toggleButton_stick_x"
                virtualName="" explicitFocusOrder="0" pos="5.769% 78.846% 32.692% 17.308%"
                txtcol="50ffffff" buttonText="X" connectedEdges="9" needsCallback="1"
                radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="toggle_Stick_Y" id="56b937c86828f442" memberName="juce__toggleButton_stick_y"
                virtualName="" explicitFocusOrder="0" pos="61.538% 5.769% 32.692% 17.308%"
                txtcol="50ffffff" buttonText="Y" connectedEdges="6" needsCallback="1"
                radioGroupId="0" state="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

