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

#include "TouchPadGUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TouchPadGUI::TouchPadGUI ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]


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



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TouchPadGUI::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    {
        int x = 1, y = 1, width = proportionOfWidth (0.9904f), height = proportionOfHeight (0.9904f);
        juce::Colour strokeColour = juce::Colours::cadetblue;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        if(pressTouchPad){
            strokeColour = juce::Colours::blue;
        }
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 2);

    }

    //[UserPaint] Add your own custom painting code here..
    if(touchPoint1.down){

        g.setColour (onColour);
        g.fillEllipse (touchPoint1.x, touchPoint1.y, pointSize, pointSize);
    }

    if(touchPoint2.down){
        g.setColour (onColour);
        g.fillEllipse (touchPoint2.x, touchPoint2.x, pointSize, pointSize);
    }
    //[/UserPaint]
}

void TouchPadGUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void TouchPadGUI::updateTouchPad_1(DualSense::Touch Point1)
{
    if(Point1.down){
        touchPoint1.down = true;
        touchPoint1.x = Point1.x * proportionOfWidth (0.9f);
        touchPoint1.x = fmax(1, fmin(touchPoint1.x, getWidth()));

        touchPoint1.y = proportionOfHeight (0.9f) - (Point1.y * proportionOfHeight (0.9f));
        touchPoint1.y = fmax(1, fmin(touchPoint1.y, getHeight()));
    }else{
        touchPoint1.down = false;
    }

}

void TouchPadGUI::updateTouchPad_2(DualSense::Touch Point2)
{
    if(Point2.down){
        touchPoint2.down = true;
        touchPoint2.x = Point2.x * proportionOfWidth (0.9f);
        touchPoint2.x = fmax(1, fmin(touchPoint2.x, getWidth()));

        touchPoint2.y = proportionOfHeight (0.9f) - (Point2.y * proportionOfHeight (0.9f));
        touchPoint2.y = fmax(1, fmin(touchPoint2.y, getHeight()));
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
  <BACKGROUND backgroundColour="323e44">
    <RECT pos="1 1 99.038% 99.038%" fill="solid: 34a52a" hasStroke="1"
          stroke="2, mitered, butt" strokeColour="solid: ff5f9ea0"/>
  </BACKGROUND>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

