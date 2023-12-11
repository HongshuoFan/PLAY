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
        _oscSender.send("/play", 0);
        if(_oscSender.disconnect() && juce__toggleButton_OSC->getToggleState()){
            if(_oscSender.connect(ip, port)){
                std::cout<<"OSC connect \n";
                _oscSender.send("/play", 1);
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
                _oscSender.send("/play", 1);
            }else{
                std::cout<<"OSC not connect \n";
            }
        }else{
            _oscSender.send("/play", 0);
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
bool OSC_Sender_UI::isValidIPAddress(const juce::String new_ip)
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

bool OSC_Sender_UI::isValidPort(const juce::String portString)
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

void OSC_Sender_UI::send_Xbox_OSC_message(XboxCotroller::XboxCotrollerInputState _xboxInput)
{
    if(juce__toggleButton_OSC->getToggleState()){
        float stickFliter = 0.01;
        ConvertAndSend_float(_xboxInput.leftStick.x, last_xboxInput.leftStick.x,
                             "/leftStick/x", last_xboxInput.leftStick.x, stickFliter);
        ConvertAndSend_float(_xboxInput.leftStick.y, last_xboxInput.leftStick.y,
                             "/leftStick/y", last_xboxInput.leftStick.y, stickFliter);
        ConvertAndSend_float(_xboxInput.rightStick.x, last_xboxInput.rightStick.x,
                             "/rightStick/x", last_xboxInput.leftStick.x, stickFliter);
        ConvertAndSend_float(_xboxInput.rightStick.y, last_xboxInput.rightStick.y,
                             "/rightStick/y", last_xboxInput.leftStick.y, stickFliter);
        ConvertAndSend_float(_xboxInput.leftTrigger, last_xboxInput.leftTrigger,
                             "/leftTrigger", last_xboxInput.leftTrigger, stickFliter);
        ConvertAndSend_float(_xboxInput.rightTrigger, last_xboxInput.rightTrigger,
                             "/rightTrigger", last_xboxInput.rightTrigger, stickFliter);

        ConvertAndSend_bool(_xboxInput.buttons.a, last_xboxInput.buttons.a,
                            "/buttons/a", last_xboxInput.buttons.a);
        ConvertAndSend_bool(_xboxInput.buttons.b, last_xboxInput.buttons.b,
                            "/buttons/b", last_xboxInput.buttons.b);
        ConvertAndSend_bool(_xboxInput.buttons.x, last_xboxInput.buttons.x,
                            "/buttons/x", last_xboxInput.buttons.x);
        ConvertAndSend_bool(_xboxInput.buttons.y, last_xboxInput.buttons.y,
                            "/buttons/y", last_xboxInput.buttons.y);

        ConvertAndSend_bool(_xboxInput.buttons.view, last_xboxInput.buttons.view,
                            "/buttons/view", last_xboxInput.buttons.view);
        ConvertAndSend_bool(_xboxInput.buttons.share, last_xboxInput.buttons.share,
                            "/buttons/share", last_xboxInput.buttons.share);
        ConvertAndSend_bool(_xboxInput.buttons.menu, last_xboxInput.buttons.menu,
                            "/buttons/menu", last_xboxInput.buttons.menu);

        ConvertAndSend_bool(_xboxInput.buttons.lb, last_xboxInput.buttons.lb,
                            "/buttons/lb", last_xboxInput.buttons.lb);
        ConvertAndSend_bool(_xboxInput.buttons.rb, last_xboxInput.buttons.rb,
                            "/buttons/rb", last_xboxInput.buttons.rb);


        ConvertAndSend_bool(_xboxInput.dpad.up, last_xboxInput.dpad.up,
                            "/dpad/up", last_xboxInput.dpad.up);
        ConvertAndSend_bool(_xboxInput.dpad.down, last_xboxInput.dpad.down,
                            "/dpad/down", last_xboxInput.dpad.down);
        ConvertAndSend_bool(_xboxInput.dpad.left, last_xboxInput.dpad.left,
                            "/dpad/left", last_xboxInput.dpad.left);
        ConvertAndSend_bool(_xboxInput.dpad.right, last_xboxInput.dpad.right,
                            "/dpad/right", last_xboxInput.dpad.right);

    }
}

void OSC_Sender_UI::send_DualSense_OSC_message(DualSense::DualSenseInputState _dualSenseInput)
{
    if(juce__toggleButton_OSC->getToggleState()){
        float stickFliter = 0.01;
        ConvertAndSend_float(_dualSenseInput.leftStick.x, last_dualSenseInput.leftStick.x,
                             "/leftStick/x", last_dualSenseInput.leftStick.x, stickFliter);
        ConvertAndSend_float(_dualSenseInput.leftStick.y, last_dualSenseInput.leftStick.y,
                             "/leftStick/y", last_dualSenseInput.leftStick.y, stickFliter);
        ConvertAndSend_float(_dualSenseInput.rightStick.x, last_xboxInput.rightStick.x,
                             "/rightStick/x", last_xboxInput.leftStick.x, stickFliter);
        ConvertAndSend_float(_dualSenseInput.rightStick.y, last_xboxInput.rightStick.y,
                             "/rightStick/y", last_xboxInput.leftStick.y, stickFliter);
        ConvertAndSend_float(_dualSenseInput.leftTrigger, last_xboxInput.leftTrigger,
                             "/leftTrigger", last_xboxInput.leftTrigger, stickFliter);
        ConvertAndSend_float(_dualSenseInput.rightTrigger, last_xboxInput.rightTrigger,
                             "/rightTrigger", last_xboxInput.rightTrigger, stickFliter);

        ConvertAndSend_bool(_dualSenseInput.buttons.square, last_dualSenseInput.buttons.square,
                            "/buttons/square", last_dualSenseInput.buttons.square);
        ConvertAndSend_bool(_dualSenseInput.buttons.cross, last_dualSenseInput.buttons.cross,
                            "/buttons/cross", last_dualSenseInput.buttons.cross);
        ConvertAndSend_bool(_dualSenseInput.buttons.circle, last_dualSenseInput.buttons.circle,
                            "/buttons/circle", last_dualSenseInput.buttons.circle);
        ConvertAndSend_bool(_dualSenseInput.buttons.triangle, last_dualSenseInput.buttons.triangle,
                            "/buttons/triangle", last_dualSenseInput.buttons.triangle);

        ConvertAndSend_bool(_dualSenseInput.buttons.select, last_dualSenseInput.buttons.select,
                            "/buttons/select", last_dualSenseInput.buttons.select);
        ConvertAndSend_bool(_dualSenseInput.buttons.menu, last_dualSenseInput.buttons.menu,
                            "/buttons/menu", last_dualSenseInput.buttons.menu);

        ConvertAndSend_bool(_dualSenseInput.buttons.l1, last_dualSenseInput.buttons.l1,
                            "/buttons/l1", last_dualSenseInput.buttons.l1);
        ConvertAndSend_bool(_dualSenseInput.buttons.r1, last_dualSenseInput.buttons.r1,
                            "/buttons/r1", last_dualSenseInput.buttons.r1);

        ConvertAndSend_bool(_dualSenseInput.dpad.up, last_dualSenseInput.dpad.up,
                            "/dpad/up", last_dualSenseInput.dpad.up);
        ConvertAndSend_bool(_dualSenseInput.dpad.down, last_dualSenseInput.dpad.down,
                            "/dpad/down", last_dualSenseInput.dpad.down);
        ConvertAndSend_bool(_dualSenseInput.dpad.left, last_dualSenseInput.dpad.left,
                            "/dpad/left", last_dualSenseInput.dpad.left);
        ConvertAndSend_bool(_dualSenseInput.dpad.right, last_dualSenseInput.dpad.right,
                            "/dpad/right", last_dualSenseInput.dpad.right);
        
        ConvertAndSend_bool(_dualSenseInput.buttons.touchPad, last_dualSenseInput.buttons.touchPad,
                            "/buttons/touchPad", last_dualSenseInput.buttons.touchPad);
        ConvertAndSend_int(_dualSenseInput.touchPoint1.id, last_dualSenseInput.touchPoint1.id,
                            "/touchPoint1/id", last_dualSenseInput.touchPoint1.id);
        ConvertAndSend_bool(_dualSenseInput.touchPoint1.down, last_dualSenseInput.touchPoint1.down,
                            "/touchPoint1/down", last_dualSenseInput.touchPoint1.down);
        ConvertAndSend_float(_dualSenseInput.touchPoint1.x, last_dualSenseInput.touchPoint1.x,
                            "/touchPoint1/x", last_dualSenseInput.touchPoint1.x, stickFliter);
        ConvertAndSend_float(_dualSenseInput.touchPoint1.y, last_dualSenseInput.touchPoint1.y,
                            "/touchPoint1/y", last_dualSenseInput.touchPoint1.y, stickFliter);
        
        ConvertAndSend_int(_dualSenseInput.touchPoint2.id, last_dualSenseInput.touchPoint2.id,
                            "/touchPoint2/id", last_dualSenseInput.touchPoint2.id);
        ConvertAndSend_bool(_dualSenseInput.touchPoint2.down, last_dualSenseInput.touchPoint2.down,
                            "/touchPoint2/down", last_dualSenseInput.touchPoint2.down);
        ConvertAndSend_float(_dualSenseInput.touchPoint2.x, last_dualSenseInput.touchPoint2.x,
                            "/touchPoint2/x", last_dualSenseInput.touchPoint2.x, stickFliter);
        ConvertAndSend_float(_dualSenseInput.touchPoint2.y, last_dualSenseInput.touchPoint2.y,
                            "/touchPoint2/y", last_dualSenseInput.touchPoint2.y, stickFliter);
        
        ConvertAndSend_float(_dualSenseInput.accelerometer.x, last_dualSenseInput.accelerometer.x,
                            "/accelerometer/x", last_dualSenseInput.accelerometer.x, stickFliter);
        ConvertAndSend_float(_dualSenseInput.accelerometer.y, last_dualSenseInput.accelerometer.y,
                            "/accelerometer/y", last_dualSenseInput.accelerometer.y, stickFliter);
        ConvertAndSend_float(_dualSenseInput.accelerometer.z, last_dualSenseInput.accelerometer.z,
                            "/accelerometer/z", last_dualSenseInput.accelerometer.z, stickFliter);
        
        ConvertAndSend_float(_dualSenseInput.gyroscope.x, last_dualSenseInput.gyroscope.x,
                            "/gyroscope/x", last_dualSenseInput.gyroscope.x, stickFliter);
        ConvertAndSend_float(_dualSenseInput.gyroscope.y, last_dualSenseInput.gyroscope.y,
                            "/gyroscope/y", last_dualSenseInput.gyroscope.y, stickFliter);
        ConvertAndSend_float(_dualSenseInput.gyroscope.z, last_dualSenseInput.gyroscope.z,
                            "/gyroscope/z", last_dualSenseInput.gyroscope.z, stickFliter);
        
    }
    
}


void OSC_Sender_UI::send_L_JoyCon_OSC_message(JoyCon::L_JoyCon_InputState _l_JC_Input)
{
    if(juce__toggleButton_OSC->getToggleState()){
        float stickFliter = 0.01;
        ConvertAndSend_float(_l_JC_Input.stick.x, last_l_JC_Input.stick.x,
                             "/leftStick/x", last_l_JC_Input.stick.x, stickFliter);
        ConvertAndSend_float(_l_JC_Input.stick.y, last_l_JC_Input.stick.y,
                             "/leftStick/y", last_l_JC_Input.stick.y, stickFliter);
        ConvertAndSend_bool(_l_JC_Input.stick.stickPress, last_l_JC_Input.stick.stickPress,
                            "/leftStick/press", last_l_JC_Input.stick.stickPress);
        
        ConvertAndSend_bool(_l_JC_Input.buttons.l, last_l_JC_Input.buttons.l,
                            "/buttons/l", last_l_JC_Input.buttons.l);
        ConvertAndSend_bool(_l_JC_Input.buttons.zl, last_l_JC_Input.buttons.zl,
                            "/buttons/zl", last_l_JC_Input.buttons.zl);
        ConvertAndSend_bool(_l_JC_Input.buttons.capture, last_l_JC_Input.buttons.capture,
                            "/buttons/capture", last_l_JC_Input.buttons.capture);
        ConvertAndSend_bool(_l_JC_Input.buttons.minus, last_l_JC_Input.buttons.minus,
                            "/buttons/minus", last_l_JC_Input.buttons.minus);
        ConvertAndSend_bool(_l_JC_Input.buttons.sl, last_l_JC_Input.buttons.sl,
                            "/buttons/l_sl", last_l_JC_Input.buttons.sl);
        ConvertAndSend_bool(_l_JC_Input.buttons.sr, last_l_JC_Input.buttons.sr,
                            "/buttons/l_sr", last_l_JC_Input.buttons.sr);

        ConvertAndSend_bool(_l_JC_Input.dpad.up, last_l_JC_Input.dpad.up,
                            "/dpad/up", last_l_JC_Input.dpad.up);
        ConvertAndSend_bool(_l_JC_Input.dpad.down, last_l_JC_Input.dpad.down,
                            "/dpad/down", last_l_JC_Input.dpad.down);
        ConvertAndSend_bool(_l_JC_Input.dpad.left, last_l_JC_Input.dpad.left,
                            "/dpad/left", last_l_JC_Input.dpad.left);
        ConvertAndSend_bool(_l_JC_Input.dpad.right, last_l_JC_Input.dpad.right,
                            "/dpad/right", last_l_JC_Input.dpad.right);

        float acc_filter = 0.01;
        ConvertAndSend_float(_l_JC_Input.accelerometer.x, last_l_JC_Input.accelerometer.x,
                            "/left/accelerometer/x", last_l_JC_Input.accelerometer.x, acc_filter);
        ConvertAndSend_float(_l_JC_Input.accelerometer.y, last_l_JC_Input.accelerometer.y,
                            "/left/accelerometer/y", last_l_JC_Input.accelerometer.y, acc_filter);
        ConvertAndSend_float(_l_JC_Input.accelerometer.z, last_l_JC_Input.accelerometer.z,
                            "/left/accelerometer/z", last_l_JC_Input.accelerometer.z, acc_filter);
        float gyo_filter = 0.5;
        ConvertAndSend_float(_l_JC_Input.gyroscope.x, last_l_JC_Input.gyroscope.x,
                            "/left/gyroscope/x", last_l_JC_Input.gyroscope.x, gyo_filter);
        ConvertAndSend_float(_l_JC_Input.gyroscope.y, last_l_JC_Input.gyroscope.y,
                            "/left/gyroscope/y", last_l_JC_Input.gyroscope.y, gyo_filter);
        ConvertAndSend_float(_l_JC_Input.gyroscope.z, last_l_JC_Input.gyroscope.z,
                            "/left/gyroscope/z", last_l_JC_Input.gyroscope.z, gyo_filter);
        
    }
    
}

void OSC_Sender_UI::send_R_JoyCon_OSC_message(JoyCon::R_JoyCon_InputState _r_JC_Input)
{
    if(juce__toggleButton_OSC->getToggleState()){
        float stickFliter = 0.01;
        ConvertAndSend_float(_r_JC_Input.stick.x, last_r_JC_Input.stick.x,
                             "/rightStick/x", last_r_JC_Input.stick.x, stickFliter);
        ConvertAndSend_float(_r_JC_Input.stick.y, last_r_JC_Input.stick.y,
                             "/rightStick/y", last_r_JC_Input.stick.y, stickFliter);
        ConvertAndSend_bool(_r_JC_Input.stick.stickPress, last_r_JC_Input.stick.stickPress,
                            "/rightStick/press", last_r_JC_Input.stick.stickPress);
        
        ConvertAndSend_bool(_r_JC_Input.buttons.r, last_r_JC_Input.buttons.r,
                            "/buttons/r", last_r_JC_Input.buttons.r);
        ConvertAndSend_bool(_r_JC_Input.buttons.zr, last_r_JC_Input.buttons.zr,
                            "/buttons/zr", last_r_JC_Input.buttons.zr);
        ConvertAndSend_bool(_r_JC_Input.buttons.home, last_r_JC_Input.buttons.home,
                            "/buttons/home", last_r_JC_Input.buttons.home);
        ConvertAndSend_bool(_r_JC_Input.buttons.plus, last_r_JC_Input.buttons.plus,
                            "/buttons/plus", last_r_JC_Input.buttons.plus);
        ConvertAndSend_bool(_r_JC_Input.buttons.sl, last_r_JC_Input.buttons.sl,
                            "/buttons/r_sl", last_r_JC_Input.buttons.sl);
        ConvertAndSend_bool(_r_JC_Input.buttons.sr, last_r_JC_Input.buttons.sr,
                            "/buttons/r_sr", last_r_JC_Input.buttons.sr);
        
        ConvertAndSend_bool(_r_JC_Input.buttons.x, last_r_JC_Input.buttons.x,
                            "/buttons/x", last_r_JC_Input.buttons.x);
        ConvertAndSend_bool(_r_JC_Input.buttons.y, last_r_JC_Input.buttons.y,
                            "/buttons/y", last_r_JC_Input.buttons.y);
        ConvertAndSend_bool(_r_JC_Input.buttons.a, last_r_JC_Input.buttons.a,
                            "/buttons/a", last_r_JC_Input.buttons.a);
        ConvertAndSend_bool(_r_JC_Input.buttons.b, last_r_JC_Input.buttons.b,
                            "/buttons/b", last_r_JC_Input.buttons.b);

        float acc_filter = 0.01;
        ConvertAndSend_float(_r_JC_Input.accelerometer.x, last_r_JC_Input.accelerometer.x,
                            "/right/accelerometer/x", last_r_JC_Input.accelerometer.x, acc_filter);
        ConvertAndSend_float(_r_JC_Input.accelerometer.y, last_r_JC_Input.accelerometer.y,
                            "/right/accelerometer/y", last_r_JC_Input.accelerometer.y, acc_filter);
        ConvertAndSend_float(_r_JC_Input.accelerometer.z, last_r_JC_Input.accelerometer.z,
                            "/right/accelerometer/z", last_r_JC_Input.accelerometer.z, acc_filter);
        float gyo_filter = 0.5;
        ConvertAndSend_float(_r_JC_Input.gyroscope.x, last_r_JC_Input.gyroscope.x,
                            "/right/gyroscope/x", last_r_JC_Input.gyroscope.x, gyo_filter);
        ConvertAndSend_float(_r_JC_Input.gyroscope.y, last_r_JC_Input.gyroscope.y,
                            "/right/gyroscope/y", last_r_JC_Input.gyroscope.y, gyo_filter);
        ConvertAndSend_float(_r_JC_Input.gyroscope.z, last_r_JC_Input.gyroscope.z,
                            "/right/gyroscope/z", last_r_JC_Input.gyroscope.z, gyo_filter);
        
    }
    
}

void OSC_Sender_UI::ConvertAndSend_float(const float val, const float pre_val, const juce::String address, float& pre_val_p, float filter)
{
    if(val != pre_val && abs(val - pre_val) >= filter){
        if(_oscSender.send(address, val)){
            pre_val_p = val;
        }
    }
}

void OSC_Sender_UI::ConvertAndSend_int(const int val, const int pre_val, const juce::String address, int& pre_val_p)
{
    if(val != pre_val){
        if(_oscSender.send(address, val)){
            pre_val_p = val;
        }
    }
}

void OSC_Sender_UI::ConvertAndSend_bool(const bool buttonState, const bool pre_buttonStat, const juce::String address, bool& pre_buttonStat_p)
{
    if(buttonState != pre_buttonStat){
        if(buttonState){
            if(_oscSender.send(address, 1)){
                pre_buttonStat_p = buttonState;
            }
        }else{
            if(_oscSender.send(address, 0)){
                pre_buttonStat_p = buttonState;
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

