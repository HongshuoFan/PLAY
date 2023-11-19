/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.8

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
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (Stickheight*2, Stickheight*2);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

StickGUI::~StickGUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



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

    {
        px = static_cast<float> (proportionOfWidth (0.5000f) - (10 / 2));
        py = static_cast<float> (proportionOfHeight (0.5000f) - (10 / 2));
        float width = 10.0f, height = 10.0f;
        juce::Colour fillColour = juce::Colour (0xffa5302a);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillEllipse (px, py, width, height);
    }

    //[UserPaint] Add your own custom painting code here..
    
    //[/UserPaint]
}

void StickGUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]
    Stickwidth = getWidth();
    Stickheight = getHeight();
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void StickGUI::mouseDrag (const juce::MouseEvent& e)
{
    //[UserCode_mouseDrag] -- Add your code here...
    
    float mouseOffsetX = e.getOffsetFromDragStart().getX();
    float mouseOffsetY = e.getOffsetFromDragStart().getY();
    float X_diff = previousMouseX - mouseOffsetX;
    float Y_diff = previousMouseY - mouseOffsetY;
    px += X_diff;
    py += Y_diff;
    
//    std::cout<< nX<<"\n";
    updatePoint(px,py,0);
    //[/UserCode_mouseDrag]
    previousMouseX = mouseOffsetX;
    previousMouseY = mouseOffsetY;
}

void StickGUI::updatePoint(float x, float y, bool button) {
    
    px = x * Stickwidth;
    px = fmax(2, fmin(px, getWidth()));
    std::cout<< px <<"\n";
    py = Stickheight - (y * Stickheight);
    py = fmax(2, fmin(py, getHeight()));
    
    if (button){
        pointColour = onColour;
    }else{
        pointColour = offColour;
    }
    
}




//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="StickGUI" componentName=""
                 parentClasses="public juce::Component" constructorParams="" variableInitialisers=""
                 snapPixels="2" snapActive="0" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="104" initialHeight="104">
  <METHODS>
    <METHOD name="mouseDrag (const juce::MouseEvent&amp; e)"/>
  </METHODS>
  <BACKGROUND backgroundColour="323e44">
    <ROUNDRECT pos="50%c 50%c 96.154% 96.154%" cornerSize="10.0" fill="solid: a5852a"
               hasStroke="1" stroke="2, mitered, butt" strokeColour="solid: ff2aa582"/>
    <ELLIPSE pos="50%c 50%c 10 10" fill="solid: ffa5302a" hasStroke="0"/>
  </BACKGROUND>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

