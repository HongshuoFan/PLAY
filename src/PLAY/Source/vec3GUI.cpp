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

#include "vec3GUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
vec3GUI::vec3GUI ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    juce__slider_x.reset (new juce::Slider ("slider_x"));
    addAndMakeVisible (juce__slider_x.get());
    juce__slider_x->setRange (-1, 1, 0.01);
    juce__slider_x->setSliderStyle (juce::Slider::LinearHorizontal);
    juce__slider_x->setTextBoxStyle (juce::Slider::TextBoxBelow, true, 80, 20);

    juce__toggleButton_x.reset (new juce::ToggleButton ("toggle_x"));
    addAndMakeVisible (juce__toggleButton_x.get());
    juce__toggleButton_x->setButtonText (juce::String());
    juce__toggleButton_x->addListener (this);
    juce__toggleButton_x->setToggleState (true, juce::dontSendNotification);

    juce__slider_y.reset (new juce::Slider ("slider_y"));
    addAndMakeVisible (juce__slider_y.get());
    juce__slider_y->setRange (-1, 1, 0.01);
    juce__slider_y->setSliderStyle (juce::Slider::LinearHorizontal);
    juce__slider_y->setTextBoxStyle (juce::Slider::TextBoxBelow, true, 80, 20);

    juce__slider_z.reset (new juce::Slider ("slider_z"));
    addAndMakeVisible (juce__slider_z.get());
    juce__slider_z->setRange (-1, 1, 0.01);
    juce__slider_z->setSliderStyle (juce::Slider::LinearHorizontal);
    juce__slider_z->setTextBoxStyle (juce::Slider::TextBoxBelow, true, 80, 20);

    juce__toggleButton_y.reset (new juce::ToggleButton ("toggle_y"));
    addAndMakeVisible (juce__toggleButton_y.get());
    juce__toggleButton_y->setButtonText (juce::String());
    juce__toggleButton_y->addListener (this);
    juce__toggleButton_y->setToggleState (true, juce::dontSendNotification);

    juce__toggleButton_z.reset (new juce::ToggleButton ("toggle_z"));
    addAndMakeVisible (juce__toggleButton_z.get());
    juce__toggleButton_z->setButtonText (juce::String());
    juce__toggleButton_z->addListener (this);
    juce__toggleButton_z->setToggleState (true, juce::dontSendNotification);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (120, 120);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

vec3GUI::~vec3GUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    juce__slider_x = nullptr;
    juce__toggleButton_x = nullptr;
    juce__slider_y = nullptr;
    juce__slider_z = nullptr;
    juce__toggleButton_y = nullptr;
    juce__toggleButton_z = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void vec3GUI::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    {
        int x = proportionOfWidth (0.0500f), y = proportionOfHeight (0.0100f), width = proportionOfWidth (1.0000f), height = proportionOfHeight (0.1500f);
        juce::String text (TRANS (title));
        juce::Colour fillColour = juce::Colour (0x707fffd4);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }
    //[/UserPaint]
}

void vec3GUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    juce__slider_x->setBounds (proportionOfWidth (0.2250f), proportionOfHeight (0.1500f), proportionOfWidth (0.8000f), proportionOfHeight (0.2000f));
    juce__toggleButton_x->setBounds (proportionOfWidth (0.0750f), proportionOfHeight (0.1500f), proportionOfWidth (0.2000f), proportionOfHeight (0.2000f));
    juce__slider_y->setBounds (proportionOfWidth (0.2250f), proportionOfHeight (0.4333f), proportionOfWidth (0.8000f), proportionOfHeight (0.2000f));
    juce__slider_z->setBounds (proportionOfWidth (0.2250f), proportionOfHeight (0.7083f), proportionOfWidth (0.8000f), proportionOfHeight (0.2000f));
    juce__toggleButton_y->setBounds (proportionOfWidth (0.0750f), proportionOfHeight (0.4333f), proportionOfWidth (0.2000f), proportionOfHeight (0.2000f));
    juce__toggleButton_z->setBounds (proportionOfWidth (0.0750f), proportionOfHeight (0.7083f), proportionOfWidth (0.2000f), proportionOfHeight (0.2000f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void vec3GUI::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == juce__toggleButton_x.get())
    {
        //[UserButtonCode_juce__toggleButton_x] -- add your button handler code here..
        is_x_enable = juce__toggleButton_x->getToggleState();
        //[/UserButtonCode_juce__toggleButton_x]
    }
    else if (buttonThatWasClicked == juce__toggleButton_y.get())
    {
        //[UserButtonCode_juce__toggleButton_y] -- add your button handler code here..
        is_y_enable = juce__toggleButton_y->getToggleState();
        //[/UserButtonCode_juce__toggleButton_y]
    }
    else if (buttonThatWasClicked == juce__toggleButton_z.get())
    {
        //[UserButtonCode_juce__toggleButton_z] -- add your button handler code here..
        is_z_enable = juce__toggleButton_z->getToggleState();
        //[/UserButtonCode_juce__toggleButton_z]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void vec3GUI::updateSliders(float x, float y, float z)
{
    juce__slider_x->setValue(std::clamp(x, slider_min, slider_max));
    juce__slider_y->setValue(std::clamp(y, slider_min, slider_max));
    juce__slider_z->setValue(std::clamp(z, slider_min, slider_max));
}

void vec3GUI::setRange(double min, double max)
{
    slider_max = max;
    slider_min = min;
    juce__slider_x->setRange(min, max, 0.01);
    juce__slider_y->setRange(min, max, 0.01);
    juce__slider_z->setRange(min, max, 0.01);
}

void vec3GUI::changeStates(bool new_state)
{
    juce__toggleButton_x->setToggleState(new_state, juce::sendNotification);
    juce__toggleButton_y->setToggleState(new_state, juce::sendNotification);
    juce__toggleButton_z->setToggleState(new_state, juce::sendNotification);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="vec3GUI" componentName=""
                 parentClasses="public juce::Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="0" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="120" initialHeight="120">
  <BACKGROUND backgroundColour="323e44"/>
  <SLIDER name="slider_x" id="491d57e6c6b5a018" memberName="juce__slider_x"
          virtualName="" explicitFocusOrder="0" pos="22.5% 15% 80% 20%"
          min="-1.0" max="1.0" int="0.01" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <TOGGLEBUTTON name="toggle_x" id="434f1cf4a254cda5" memberName="juce__toggleButton_x"
                virtualName="" explicitFocusOrder="0" pos="7.5% 15% 20% 20%"
                buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="1"/>
  <SLIDER name="slider_y" id="565b1d42be642459" memberName="juce__slider_y"
          virtualName="" explicitFocusOrder="0" pos="22.5% 43.333% 80% 20%"
          min="-1.0" max="1.0" int="0.01" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="slider_z" id="42b14e7cadadc2fa" memberName="juce__slider_z"
          virtualName="" explicitFocusOrder="0" pos="22.5% 70.833% 80% 20%"
          min="-1.0" max="1.0" int="0.01" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <TOGGLEBUTTON name="toggle_y" id="6da396debcc7cdc1" memberName="juce__toggleButton_y"
                virtualName="" explicitFocusOrder="0" pos="7.5% 43.333% 20% 20%"
                buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="1"/>
  <TOGGLEBUTTON name="toggle_z" id="53b51fe9d9fd6bee" memberName="juce__toggleButton_z"
                virtualName="" explicitFocusOrder="0" pos="7.5% 70.833% 20% 20%"
                buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

