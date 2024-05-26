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


    //[UserPreSize]
    //[/UserPreSize]

    setSize (700, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

AccessController_UI::~AccessController_UI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



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
        float x = static_cast<float> (proportionOfWidth (0.6857f) - (proportionOfWidth (0.3971f) / 2)), y = static_cast<float> (proportionOfHeight (0.4800f) - (proportionOfHeight (0.6950f) / 2)), width = static_cast<float> (proportionOfWidth (0.3971f)), height = static_cast<float> (proportionOfHeight (0.6950f));
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
    Stick_UI->setBounds (proportionOfWidth (0.1f), proportionOfHeight (0.25f), proportionOfWidth (0.26f), proportionOfHeight (0.44f));
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="AccessController_UI" componentName=""
                 parentClasses="public juce::Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="700" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44">
    <ELLIPSE pos="68.571%c 48%c 39.714% 69.5%" fill="solid: a52a5a" hasStroke="1"
             stroke="8, mitered, butt" strokeColour="solid: ff6493ed"/>
  </BACKGROUND>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

