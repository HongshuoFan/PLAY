/*
  ==============================================================================

    XboxController_Input.cpp
    Created: 7 Nov 2023 9:40:44am
    Author:  Hongshuo Fan

  ==============================================================================
*/

#include <JuceHeader.h>
#include "XboxController_Input.h"

//==============================================================================
XboxController_Input::XboxController_Input()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

XboxController_Input::~XboxController_Input()
{
}

void XboxController_Input::evaluateXboxCotrollerHidInputBuffer(uint8_t *_reportData) {
    
    // Convert sticks bit to int
    XC_input.leftStick.x = (_reportData[2] << 4) | (_reportData[1] & 0xFF);
    XC_input.leftStick.x = XC_input.leftStick.x / 4095.;
    XC_input.leftStick.y = (_reportData[4] << 4) | (_reportData[3] & 0xFF);
    XC_input.leftStick.y = 1. - XC_input.leftStick.y / 4095.;
    
    XC_input.rightStick.x = (_reportData[6] << 4) | (_reportData[5] & 0xFF);
    XC_input.rightStick.x = XC_input.rightStick.x /4095.;
    XC_input.rightStick.y = (_reportData[8] << 4) | (_reportData[7] & 0xFF);
    XC_input.rightStick.y = 1. - XC_input.rightStick.y / 4095.;
   
    // Convert trigger to bit to int
    XC_input.leftTrigger = (_reportData[10] << 8) | (_reportData[9] & 0xFF);
    XC_input.leftTrigger = XC_input.leftTrigger / 1023;
    XC_input.rightTrigger = (_reportData[12] << 8) | (_reportData[11] & 0xFF);
    XC_input.rightTrigger = XC_input.rightTrigger / 1023;
//    std::cout<<XC_input.leftTrigger<<"\n";
    // Dpad
   
    int dpadState = static_cast<int>(_reportData[13]);
    switch (dpadState){
        case 0:
            XC_input.dpad.up = false;
            XC_input.dpad.down = false;
            XC_input.dpad.right = false;
            XC_input.dpad.left = false;
            break;
        case 1:
            XC_input.dpad.up = true;
            break;
        case 2:
            XC_input.dpad.up = true;
            XC_input.dpad.right = true;
            break;
        case 3:
            XC_input.dpad.right = true;
            break;
        case 4:
            XC_input.dpad.right = true;
            XC_input.dpad.down = true;
            break;
        case 5:
            XC_input.dpad.down = true;
            break;
        case 6:
            XC_input.dpad.left = true;
            XC_input.dpad.down = true;
            break;
        case 7:
            XC_input.dpad.left = true;
            break;
        case 8:
            XC_input.dpad.left = true;
            XC_input.dpad.up = true;
            break;
    }
    
    //buttons
    
    uint16_t buttonState = (_reportData[14] << 8) | _reportData[15];
   
    XC_input.buttons.a = (buttonState & XBOX_A) != 0;
    XC_input.buttons.b = (buttonState & XBOX_B) != 0;
    XC_input.buttons.y = (buttonState & XBOX_Y) != 0;
    XC_input.buttons.x = (buttonState & XBOX_X) != 0;
    
    XC_input.buttons.rb = (buttonState & XBOX_RB) != 0;
    XC_input.buttons.lb = (buttonState & XBOX_LB) != 0;
    
    XC_input.leftStick.stickPress =(buttonState & XBOX_LeftStick) != 0;
    XC_input.rightStick.stickPress =(buttonState & XBOX_RightStick) != 0;
    
    uint16_t oButtons = (_reportData[15] << 8) | _reportData[16];
    XC_input.buttons.view =(oButtons & XBOX_VIEW) != 0;
    XC_input.buttons.menu =(oButtons & XBOX_MENU) != 0;
    XC_input.buttons.share =(_reportData[16] & 0x00f) != 0;

//    std::cout<< "rightStick" <<XC_input.rightStick.stickPress << std::endl;
    
  
}



