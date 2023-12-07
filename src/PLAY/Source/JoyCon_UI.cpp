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
    Right_Stick->setBounds(375, 180, 80, 80);
    Right_Stick->resized();
    //[/Constructor_pre]

    juce__textButton_zl.reset (new juce::TextButton ("zl_button"));
    addAndMakeVisible (juce__textButton_zl.get());
    juce__textButton_zl->setButtonText (TRANS ("ZL"));
    juce__textButton_zl->addListener (this);

    juce__textButton_l.reset (new juce::TextButton ("l_button"));
    addAndMakeVisible (juce__textButton_l.get());
    juce__textButton_l->setButtonText (TRANS ("L"));
    juce__textButton_l->addListener (this);

    juce__textButton_.reset (new juce::TextButton ("-_button"));
    addAndMakeVisible (juce__textButton_.get());
    juce__textButton_->setButtonText (TRANS ("-"));
    juce__textButton_->addListener (this);

    juce__textButton_capture.reset (new juce::TextButton ("capture_button"));
    addAndMakeVisible (juce__textButton_capture.get());
    juce__textButton_capture->setButtonText (TRANS ("Capture"));
    juce__textButton_capture->addListener (this);

    juce__textButton_UP.reset (new juce::TextButton ("up_button"));
    addAndMakeVisible (juce__textButton_UP.get());
    juce__textButton_UP->setButtonText (TRANS ("Up"));
    juce__textButton_UP->addListener (this);

    juce__textButton_Left.reset (new juce::TextButton ("left_button"));
    addAndMakeVisible (juce__textButton_Left.get());
    juce__textButton_Left->setButtonText (TRANS ("Left"));
    juce__textButton_Left->addListener (this);

    juce__textButton_right.reset (new juce::TextButton ("right_button"));
    addAndMakeVisible (juce__textButton_right.get());
    juce__textButton_right->setButtonText (TRANS ("Right"));
    juce__textButton_right->addListener (this);

    juce__textButton_down.reset (new juce::TextButton ("down_button"));
    addAndMakeVisible (juce__textButton_down.get());
    juce__textButton_down->setButtonText (TRANS ("Down"));
    juce__textButton_down->addListener (this);

    juce__textButton_sl.reset (new juce::TextButton ("sl_button"));
    addAndMakeVisible (juce__textButton_sl.get());
    juce__textButton_sl->setButtonText (TRANS ("SL"));
    juce__textButton_sl->addListener (this);

    juce__textButton_sr.reset (new juce::TextButton ("sr_button"));
    addAndMakeVisible (juce__textButton_sr.get());
    juce__textButton_sr->setButtonText (TRANS ("SR"));
    juce__textButton_sr->addListener (this);

    juce__textButton_zr.reset (new juce::TextButton ("zr_button"));
    addAndMakeVisible (juce__textButton_zr.get());
    juce__textButton_zr->setButtonText (TRANS ("ZR"));
    juce__textButton_zr->addListener (this);

    juce__textButton_r.reset (new juce::TextButton ("r_button"));
    addAndMakeVisible (juce__textButton_r.get());
    juce__textButton_r->setButtonText (TRANS ("R"));
    juce__textButton_r->addListener (this);

    juce__textButton_2.reset (new juce::TextButton ("+_button"));
    addAndMakeVisible (juce__textButton_2.get());
    juce__textButton_2->setButtonText (TRANS ("+"));
    juce__textButton_2->addListener (this);

    juce__textButton_sr2.reset (new juce::TextButton ("sr_button"));
    addAndMakeVisible (juce__textButton_sr2.get());
    juce__textButton_sr2->setButtonText (TRANS ("SR"));
    juce__textButton_sr2->addListener (this);

    juce__textButton_sl2.reset (new juce::TextButton ("sl_button"));
    addAndMakeVisible (juce__textButton_sl2.get());
    juce__textButton_sl2->setButtonText (TRANS ("SL"));
    juce__textButton_sl2->addListener (this);

    juce__textButton_x.reset (new juce::TextButton ("x_button"));
    addAndMakeVisible (juce__textButton_x.get());
    juce__textButton_x->setButtonText (TRANS ("X"));
    juce__textButton_x->addListener (this);

    juce__textButton_y.reset (new juce::TextButton ("y_button"));
    addAndMakeVisible (juce__textButton_y.get());
    juce__textButton_y->setButtonText (TRANS ("Y"));
    juce__textButton_y->addListener (this);

    juce__textButton_a.reset (new juce::TextButton ("a_button"));
    addAndMakeVisible (juce__textButton_a.get());
    juce__textButton_a->setButtonText (TRANS ("A"));
    juce__textButton_a->addListener (this);

    juce__textButton_b.reset (new juce::TextButton ("b_button"));
    addAndMakeVisible (juce__textButton_b.get());
    juce__textButton_b->setButtonText (TRANS ("B"));
    juce__textButton_b->addListener (this);

    juce__textButton_home.reset (new juce::TextButton ("home_button"));
    addAndMakeVisible (juce__textButton_home.get());
    juce__textButton_home->setButtonText (TRANS ("Home"));
    juce__textButton_home->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 340);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

JoyCon_UI::~JoyCon_UI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    juce__textButton_zl = nullptr;
    juce__textButton_l = nullptr;
    juce__textButton_ = nullptr;
    juce__textButton_capture = nullptr;
    juce__textButton_UP = nullptr;
    juce__textButton_Left = nullptr;
    juce__textButton_right = nullptr;
    juce__textButton_down = nullptr;
    juce__textButton_sl = nullptr;
    juce__textButton_sr = nullptr;
    juce__textButton_zr = nullptr;
    juce__textButton_r = nullptr;
    juce__textButton_2 = nullptr;
    juce__textButton_sr2 = nullptr;
    juce__textButton_sl2 = nullptr;
    juce__textButton_x = nullptr;
    juce__textButton_y = nullptr;
    juce__textButton_a = nullptr;
    juce__textButton_b = nullptr;
    juce__textButton_home = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
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

    juce__textButton_zl->setBounds (proportionOfWidth (0.2500f), proportionOfHeight (0.0353f), proportionOfWidth (0.0583f), proportionOfHeight (0.0471f));
    juce__textButton_l->setBounds (proportionOfWidth (0.3383f), proportionOfHeight (0.0147f), proportionOfWidth (0.0583f), proportionOfHeight (0.0471f));
    juce__textButton_->setBounds (proportionOfWidth (0.3550f), proportionOfHeight (0.0912f), proportionOfWidth (0.0450f), proportionOfHeight (0.0382f));
    juce__textButton_capture->setBounds (proportionOfWidth (0.3417f), proportionOfHeight (0.8353f), proportionOfWidth (0.0600f), proportionOfHeight (0.0412f));
    juce__textButton_UP->setBounds (proportionOfWidth (0.3033f), proportionOfHeight (0.5265f), proportionOfWidth (0.0517f), proportionOfHeight (0.0412f));
    juce__textButton_Left->setBounds (proportionOfWidth (0.2533f), proportionOfHeight (0.6000f), proportionOfWidth (0.0517f), proportionOfHeight (0.0412f));
    juce__textButton_right->setBounds (proportionOfWidth (0.3483f), proportionOfHeight (0.6000f), proportionOfWidth (0.0517f), proportionOfHeight (0.0412f));
    juce__textButton_down->setBounds (proportionOfWidth (0.3033f), proportionOfHeight (0.6765f), proportionOfWidth (0.0517f), proportionOfHeight (0.0412f));
    juce__textButton_sl->setBounds (proportionOfWidth (0.4200f), proportionOfHeight (0.1588f), proportionOfWidth (0.0500f), proportionOfHeight (0.1000f));
    juce__textButton_sr->setBounds (proportionOfWidth (0.4200f), proportionOfHeight (0.6588f), proportionOfWidth (0.0500f), proportionOfHeight (0.1000f));
    juce__textButton_zr->setBounds (proportionOfWidth (0.7000f), proportionOfHeight (0.0353f), proportionOfWidth (0.0583f), proportionOfHeight (0.0471f));
    juce__textButton_r->setBounds (proportionOfWidth (0.6150f), proportionOfHeight (0.0147f), proportionOfWidth (0.0583f), proportionOfHeight (0.0471f));
    juce__textButton_2->setBounds (proportionOfWidth (0.6117f), proportionOfHeight (0.0912f), proportionOfWidth (0.0417f), proportionOfHeight (0.0471f));
    juce__textButton_sr2->setBounds (proportionOfWidth (0.5400f), proportionOfHeight (0.1588f), proportionOfWidth (0.0500f), proportionOfHeight (0.1000f));
    juce__textButton_sl2->setBounds (proportionOfWidth (0.5400f), proportionOfHeight (0.6588f), proportionOfWidth (0.0500f), proportionOfHeight (0.1000f));
    juce__textButton_x->setBounds (proportionOfWidth (0.6667f), proportionOfHeight (0.2059f), proportionOfWidth (0.0517f), proportionOfHeight (0.0412f));
    juce__textButton_y->setBounds (proportionOfWidth (0.6200f), proportionOfHeight (0.2765f), proportionOfWidth (0.0517f), proportionOfHeight (0.0412f));
    juce__textButton_a->setBounds (proportionOfWidth (0.7100f), proportionOfHeight (0.2765f), proportionOfWidth (0.0517f), proportionOfHeight (0.0412f));
    juce__textButton_b->setBounds (proportionOfWidth (0.6667f), proportionOfHeight (0.3471f), proportionOfWidth (0.0517f), proportionOfHeight (0.0412f));
    juce__textButton_home->setBounds (proportionOfWidth (0.6100f), proportionOfHeight (0.8353f), proportionOfWidth (0.0600f), proportionOfHeight (0.0412f));
    internalPath1.clear();
    internalPath1.startNewSubPath (static_cast<float> (proportionOfWidth (0.4133f)), static_cast<float> (proportionOfHeight (0.8971f)));
    internalPath1.lineTo (static_cast<float> (proportionOfWidth (0.4133f)), static_cast<float> (proportionOfHeight (0.0265f)));
    internalPath1.quadraticTo (144.0f, 8.0f, 144.0f, 65.0f);
    internalPath1.lineTo (144.0f, 249.0f);
    internalPath1.quadraticTo (static_cast<float> (proportionOfWidth (0.2400f)), static_cast<float> (proportionOfHeight (0.9647f)), static_cast<float> (proportionOfWidth (0.4133f)), static_cast<float> (proportionOfHeight (0.9647f)));
    internalPath1.closeSubPath();

    internalPath2.clear();
    internalPath2.startNewSubPath (static_cast<float> (proportionOfWidth (0.6000f)), static_cast<float> (proportionOfHeight (0.9647f)));
    internalPath2.quadraticTo (464.0f, 336.0f, 464.0f, 272.0f);
    internalPath2.lineTo (464.0f, 72.0f);
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
    else if (buttonThatWasClicked == juce__textButton_.get())
    {
        //[UserButtonCode_juce__textButton_] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_]
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
    else if (buttonThatWasClicked == juce__textButton_sl.get())
    {
        //[UserButtonCode_juce__textButton_sl] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_sl]
    }
    else if (buttonThatWasClicked == juce__textButton_sr.get())
    {
        //[UserButtonCode_juce__textButton_sr] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_sr]
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
    else if (buttonThatWasClicked == juce__textButton_2.get())
    {
        //[UserButtonCode_juce__textButton_2] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_2]
    }
    else if (buttonThatWasClicked == juce__textButton_sr2.get())
    {
        //[UserButtonCode_juce__textButton_sr2] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_sr2]
    }
    else if (buttonThatWasClicked == juce__textButton_sl2.get())
    {
        //[UserButtonCode_juce__textButton_sl2] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton_sl2]
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

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void JoyCon_UI::update()
{

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
                 variableInitialisers="" snapPixels="2" snapActive="0" snapShown="0"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="600" initialHeight="340">
  <BACKGROUND backgroundColour="ff323e44">
    <PATH pos="0 0 100 100" fill="solid: a52a5f" hasStroke="1" stroke="2, mitered, butt"
          strokeColour="solid: ffdc143c" nonZeroWinding="1">s 41.334% 89.706% l 41.334% 2.647% q 144 8 144 65 l 144 249 q 24% 96.471% 41.334% 96.471% x</PATH>
    <PATH pos="0 0 100 100" fill="solid: a5392a" hasStroke="1" stroke="2, mitered, butt"
          strokeColour="solid: ff6495ed" nonZeroWinding="1">s 60% 96.471% q 464 336 464 272 l 464 72 q 77.334% 0% 60% 2.353% x</PATH>
  </BACKGROUND>
  <TEXTBUTTON name="zl_button" id="1cc67156ee26efac" memberName="juce__textButton_zl"
              virtualName="" explicitFocusOrder="0" pos="25% 3.529% 5.833% 4.706%"
              buttonText="ZL" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="l_button" id="a20fe6afd4607943" memberName="juce__textButton_l"
              virtualName="" explicitFocusOrder="0" pos="33.833% 1.471% 5.833% 4.706%"
              buttonText="L" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="-_button" id="995bf07d41bd7cf2" memberName="juce__textButton_"
              virtualName="" explicitFocusOrder="0" pos="35.5% 9.118% 4.5% 3.824%"
              buttonText="-" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="capture_button" id="dd3b2e191ddd1126" memberName="juce__textButton_capture"
              virtualName="" explicitFocusOrder="0" pos="34.167% 83.529% 6% 4.118%"
              buttonText="Capture" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="up_button" id="60a341aecef994de" memberName="juce__textButton_UP"
              virtualName="" explicitFocusOrder="0" pos="30.333% 52.647% 5.167% 4.118%"
              buttonText="Up" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="left_button" id="353c25528095ee94" memberName="juce__textButton_Left"
              virtualName="" explicitFocusOrder="0" pos="25.333% 60% 5.167% 4.118%"
              buttonText="Left" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="right_button" id="643e5d0931220731" memberName="juce__textButton_right"
              virtualName="" explicitFocusOrder="0" pos="34.833% 60% 5.167% 4.118%"
              buttonText="Right" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="down_button" id="96446f9ae02af8a5" memberName="juce__textButton_down"
              virtualName="" explicitFocusOrder="0" pos="30.333% 67.647% 5.167% 4.118%"
              buttonText="Down" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="sl_button" id="5a6ddc9a283427fc" memberName="juce__textButton_sl"
              virtualName="" explicitFocusOrder="0" pos="42% 15.882% 5% 10%"
              buttonText="SL" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="sr_button" id="55c7c15a26ad5788" memberName="juce__textButton_sr"
              virtualName="" explicitFocusOrder="0" pos="42% 65.882% 5% 10%"
              buttonText="SR" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="zr_button" id="612844c53a7abbf0" memberName="juce__textButton_zr"
              virtualName="" explicitFocusOrder="0" pos="70% 3.529% 5.833% 4.706%"
              buttonText="ZR" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="r_button" id="569fe346efcede6a" memberName="juce__textButton_r"
              virtualName="" explicitFocusOrder="0" pos="61.5% 1.471% 5.833% 4.706%"
              buttonText="R" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="+_button" id="e13f508f32787f45" memberName="juce__textButton_2"
              virtualName="" explicitFocusOrder="0" pos="61.167% 9.118% 4.167% 4.706%"
              buttonText="+" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="sr_button" id="82e6498f7ab5583b" memberName="juce__textButton_sr2"
              virtualName="" explicitFocusOrder="0" pos="54% 15.882% 5% 10%"
              buttonText="SR" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="sl_button" id="aef97be374c91d95" memberName="juce__textButton_sl2"
              virtualName="" explicitFocusOrder="0" pos="54% 65.882% 5% 10%"
              buttonText="SL" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="x_button" id="f392b142ac2be96d" memberName="juce__textButton_x"
              virtualName="" explicitFocusOrder="0" pos="66.667% 20.588% 5.167% 4.118%"
              buttonText="X" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="y_button" id="e1327e3abe5f6601" memberName="juce__textButton_y"
              virtualName="" explicitFocusOrder="0" pos="62% 27.647% 5.167% 4.118%"
              buttonText="Y" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="a_button" id="45678a3db2453320" memberName="juce__textButton_a"
              virtualName="" explicitFocusOrder="0" pos="71% 27.647% 5.167% 4.118%"
              buttonText="A" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="b_button" id="b8895522617ca8c8" memberName="juce__textButton_b"
              virtualName="" explicitFocusOrder="0" pos="66.667% 34.706% 5.167% 4.118%"
              buttonText="B" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="home_button" id="c339f80e78117710" memberName="juce__textButton_home"
              virtualName="" explicitFocusOrder="0" pos="61% 83.529% 6% 4.118%"
              buttonText="Home" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

