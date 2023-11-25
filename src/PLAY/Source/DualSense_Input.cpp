/*
  ==============================================================================

    DualSense_Input.cpp
    Created: 3 Nov 2023 2:10:46pm
    Author:  Hongshuo Fan

  ==============================================================================
*/

#include <JuceHeader.h>
#include "DualSense_Input.h"

//==============================================================================
DualSense_Input::DualSense_Input()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

DualSense_Input::~DualSense_Input()
{
}

int16_t DualSense_Input::uint16_to_int16(uint16_t a)
{
    int16_t b;
    char* aPointer = (char*)&a, *bPointer = (char*)&b;
    memcpy(bPointer, aPointer, sizeof(a));
    return b;
}
void DualSense_Input::evaluateDualSenseHidInputBuffer(uint8_t *_reportData) { 
    // Convert sticks to signed range 0 4082
    DS_input.leftStick.x = _reportData[2] << 4;
    DS_input.leftStick.y = _reportData[3] << 4;
    DS_input.rightStick.x = _reportData[4] << 4;
    DS_input.rightStick.y = _reportData[5] << 4;
    
    // Buttons
    uint8_t buttonData = _reportData[9]; //[5] for BT
    DS_input.buttons.cross = (buttonData & DualSense_ISTATE_BTX_CROSS) != 0;
    DS_input.buttons.square = (buttonData & DualSense_ISTATE_BTX_SQUARE) != 0;
    DS_input.buttons.circle = (buttonData & DualSense_ISTATE_BTX_CIRCLE) != 0;
    DS_input.buttons.triangle = (buttonData & DualSense_ISTATE_BTX_TRIANGLE) != 0;

    // Dpad
    int dpadState = static_cast<int>(buttonData);
    switch (dpadState) {
            // Up
        case 8:
            DS_input.dpad.up = false;
            DS_input.dpad.down = false;
            DS_input.dpad.left = false;
            DS_input.dpad.right = false;
            break;
            
        case 0:
            DS_input.dpad.up = true;
            break;
        case 1:
            DS_input.dpad.up = true;
            DS_input.dpad.right = true;
            break;
        case 2:
            DS_input.dpad.right = true;
            break;
        case 3:
            DS_input.dpad.right = true;
            DS_input.dpad.down = true;
            break;
        case 4:
            DS_input.dpad.down = true;
            break;
        case 5:
            DS_input.dpad.down = true;
            DS_input.dpad.left = true;
            break;
        case 6:
            DS_input.dpad.left = true;
            break;
        case 7:
            DS_input.dpad.left = true;
            DS_input.dpad.up = true;
            break;
    }
    
    
    
    //Stick press BT 0x06
    DS_input.leftStick.stickPress = (_reportData[10] & DualSense_ISTATE_BTN_A_LEFT_STICK) != 0;
    DS_input.rightStick.stickPress = (_reportData[10] & DualSense_ISTATE_BTN_A_RIGHT_STICK) != 0;
    
    // other buttons BT 0x06
    DS_input.buttons.select = (_reportData[10] & DualSense_ISTATE_BTN_A_SELECT) != 0;
    DS_input.buttons.menu = (_reportData[10] & DualSense_ISTATE_BTN_A_MENU) != 0;
    DS_input.buttons.r1 = (_reportData[10] & DualSense_ISTATE_BTN_A_RIGHT_BUMPER) != 0;
    DS_input.buttons.l1 = (_reportData[10] & DualSense_ISTATE_BTN_A_LEFT_BUMPER) != 0;

    
    // Convert trigger to unsigned range, BT 0x09
    DS_input.leftTrigger = _reportData[6] << 4;
    DS_input.rightTrigger = _reportData[7] << 4;
    
//    //accelerometer
//    int test = (_reportData[17] << 4) | (_reportData[18] & 0xFF);
//    int test2 = (_reportData[19] << 4) | (_reportData[20] & 0xFF);
//    int test3 = (_reportData[21] << 4) | (_reportData[22] & 0xFF);
//    
//    //gyo
//    int test4 = _reportData[24] << 4;
//    int test5 = _reportData[26] << 4;
//    std::cout<<  test5 << "\n";
   
    
//    int test = (int)(_reportData[17] & 0xF0);
//    std::cout<< test << "\n";
}


