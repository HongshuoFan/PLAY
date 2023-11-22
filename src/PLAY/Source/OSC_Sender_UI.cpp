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

#include "OSC_Sender_UI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
OSC_Sender_UI::OSC_Sender_UI ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    juce__textButton_update.reset (new juce::TextButton ("OSC_update_button"));
    addAndMakeVisible (juce__textButton_update.get());
    juce__textButton_update->setButtonText (TRANS ("Update"));
    juce__textButton_update->addListener (this);

    juce__textEditor_IP.reset (new juce::TextEditor ("IP_Editor"));
    addAndMakeVisible (juce__textEditor_IP.get());
    juce__textEditor_IP->setMultiLine (false);
    juce__textEditor_IP->setReturnKeyStartsNewLine (false);
    juce__textEditor_IP->setReadOnly (false);
    juce__textEditor_IP->setScrollbarsShown (false);
    juce__textEditor_IP->setCaretVisible (true);
    juce__textEditor_IP->setPopupMenuEnabled (true);
    juce__textEditor_IP->setText (juce::String());

    juce__textEditor_IP->setBounds (100, 10, 150, 24);

    juce__textEditor_port.reset (new juce::TextEditor ("Port_Editor"));
    addAndMakeVisible (juce__textEditor_port.get());
    juce__textEditor_port->setMultiLine (false);
    juce__textEditor_port->setReturnKeyStartsNewLine (false);
    juce__textEditor_port->setReadOnly (false);
    juce__textEditor_port->setScrollbarsShown (false);
    juce__textEditor_port->setCaretVisible (true);
    juce__textEditor_port->setPopupMenuEnabled (true);
    juce__textEditor_port->setText (juce::String());

    juce__textEditor_port->setBounds (320, 10, 150, 24);

    juce__toggleButton_OSC.reset (new juce::ToggleButton ("OSC_activeButton"));
    addAndMakeVisible (juce__toggleButton_OSC.get());
    juce__toggleButton_OSC->setButtonText (TRANS ("OSC"));
    juce__toggleButton_OSC->addListener (this);

    juce__toggleButton_OSC->setBounds (2, 5, 70, 30);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 40);


    //[Constructor] You can add your own custom stuff here..
    juce__textEditor_IP->setText(ip);
    juce__textEditor_port->setText("9001");
    //[/Constructor]
}

OSC_Sender_UI::~OSC_Sender_UI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    juce__textButton_update = nullptr;
    juce__textEditor_IP = nullptr;
    juce__textEditor_port = nullptr;
    juce__toggleButton_OSC = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    _oscSender.disconnect();
    //[/Destructor]
}

//==============================================================================
void OSC_Sender_UI::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    {
        int x = 70, y = 10, width = 20, height = 20;
        juce::String text (TRANS ("IP"));
        juce::Colour fillColour = juce::Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 270, y = 12, width = 30, height = 20;
        juce::String text (TRANS ("Port"));
        juce::Colour fillColour = juce::Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void OSC_Sender_UI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    juce__textButton_update->setBounds (490, 10, proportionOfWidth (0.1300f), proportionOfHeight (0.6000f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void OSC_Sender_UI::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == juce__textButton_update.get())
    {
        //[UserButtonCode_juce__textButton_update] -- add your button handler code here..

        juce::String newIP = juce__textEditor_IP->getText();
        if(isValidIPAddress(newIP)){
            ip = newIP;
        }else{
            std::cout<<"Not Valid IP " << newIP << "\n";
            juce__textEditor_IP->setText(ip);
        }

        juce::String newPort = juce__textEditor_port->getText();
        if(isValidPort(newPort)){
            port = newPort.getIntValue();
        }else{
            juce__textEditor_port->setText("9001");
            std::cout<<"Not Valid port " << newPort << "\n";
        }
        // reconnect
        if(_oscSender.disconnect() && juce__toggleButton_OSC->getToggleState()){
            if(_oscSender.connect(ip, port)){
                std::cout<<"OSC connect \n";
            }else{
                std::cout<<"OSC not connect \n";
            }
        }
        //[/UserButtonCode_juce__textButton_update]
    }
    else if (buttonThatWasClicked == juce__toggleButton_OSC.get())
    {
        //[UserButtonCode_juce__toggleButton_OSC] -- add your button handler code here..
        if(juce__toggleButton_OSC->getToggleState()){
            if(_oscSender.connect(ip, port)){
                std::cout<<"OSC connect \n";
                _oscSender.send("/test", 1);
            }else{
                std::cout<<"OSC not connect \n";
            }
        }else{
            if(_oscSender.disconnect()){
                std::cout<<"OSC disconnect \n";
            }
        }
        //[/UserButtonCode_juce__toggleButton_OSC]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
bool OSC_Sender_UI::isValidIPAddress(juce::String new_ip)
{
    juce::StringArray parts;
    parts.addTokens(new_ip, ".", "");

    if (parts.size() != 4) {
            return false;
        }

    for (const auto& part : parts) {
        // Check if the string contains only digits
            if (part.isEmpty() || part.length() > 3 || !part.containsOnly("0123456789")) {
                return false;
            }

            int num = part.getIntValue();
            if (num < 0 || num > 255) {
                return false;
            }
        }

        return true;
}

bool OSC_Sender_UI::isValidPort(juce::String portString)
{
    // Check if the string contains only digits
        if (!portString.containsOnly("0123456789")) {
            return false;
        }
    // Convert to integer and check the range
        int port = portString.getIntValue();
        return port >= 0 && port <= 65535;
}

void OSC_Sender_UI::disConnect(){
    juce__toggleButton_OSC->setToggleState(false, juce::sendNotification);
}

void OSC_Sender_UI::sendXbox_OSC_message()
{
    if(juce__toggleButton_OSC->getToggleState()){
        
   
    if (_xboxInput.leftStick.x != last_xboxInput.leftStick.x){
        
        if( _oscSender.send("/leftStick/x", _xboxInput.leftStick.x)){
            last_xboxInput.leftStick.x = _xboxInput.leftStick.x;
            //std::cout<<"_xboxInput.leftStick.x";
        }
        
    }
    }
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="OSC_Sender_UI" componentName=""
                 parentClasses="public juce::Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="0" snapShown="0" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="600" initialHeight="40">
  <BACKGROUND backgroundColour="ff323e44">
    <TEXT pos="70 10 20 20" fill="solid: fff0ffff" hasStroke="0" text="IP"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="270 12 30 20" fill="solid: fff0ffff" hasStroke="0" text="Port"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
  </BACKGROUND>
  <TEXTBUTTON name="OSC_update_button" id="b8439ee890c80617" memberName="juce__textButton_update"
              virtualName="" explicitFocusOrder="0" pos="490 10 13% 60%" buttonText="Update"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="IP_Editor" id="cb666364e6e180c6" memberName="juce__textEditor_IP"
              virtualName="" explicitFocusOrder="0" pos="100 10 150 24" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="0"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="Port_Editor" id="f7c38c045e142531" memberName="juce__textEditor_port"
              virtualName="" explicitFocusOrder="0" pos="320 10 150 24" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="0"
              caret="1" popupmenu="1"/>
  <TOGGLEBUTTON name="OSC_activeButton" id="dc04b5e769d393aa" memberName="juce__toggleButton_OSC"
                virtualName="" explicitFocusOrder="0" pos="2 5 70 30" buttonText="OSC"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

