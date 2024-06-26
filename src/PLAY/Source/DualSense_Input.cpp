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
void DualSense_Input::evaluateDualSenseHidInputBuffer(uint8_t *_reportData, bool enableIMU) {
    //0x31 BT
    int index_shift = _reportData[0] == 0x31 ? 0 : -1;
    usbOrBT = _reportData[0] == 0x31 ? true : false;
   
    // Convert sticks to signed range 0 4080
    ds_input.leftStick.x = (_reportData[2 + index_shift] << 4) / 4080.;
    ds_input.leftStick.y = 1. - (_reportData[3 + index_shift] << 4) / 4080.;
    ds_input.rightStick.x = (_reportData[4 + index_shift] << 4) / 4080.;
    ds_input.rightStick.y = 1. - (_reportData[5 + index_shift] << 4) / 4080.;
   
    // Buttons
    uint8_t buttonData = _reportData[9 + index_shift];
    ds_input.buttons.cross = (buttonData & DualSense_ISTATE_BTX_CROSS) != 0;
    ds_input.buttons.square = (buttonData & DualSense_ISTATE_BTX_SQUARE) != 0;
    ds_input.buttons.circle = (buttonData & DualSense_ISTATE_BTX_CIRCLE) != 0;
    ds_input.buttons.triangle = (buttonData & DualSense_ISTATE_BTX_TRIANGLE) != 0;
    
    // Dpad
    uint8_t dpadState = _reportData[9 + index_shift] & 0x0f;
    switch (dpadState) {
            // Up
        case 8:
            ds_input.dpad.up = false;
            ds_input.dpad.down = false;
            ds_input.dpad.left = false;
            ds_input.dpad.right = false;
            break;
            
        case 0:
            ds_input.dpad.up = true;
            break;
        case 1:
            ds_input.dpad.up = true;
            ds_input.dpad.right = true;
            break;
        case 2:
            ds_input.dpad.right = true;
            break;
        case 3:
            ds_input.dpad.right = true;
            ds_input.dpad.down = true;
            break;
        case 4:
            ds_input.dpad.down = true;
            break;
        case 5:
            ds_input.dpad.down = true;
            ds_input.dpad.left = true;
            break;
        case 6:
            ds_input.dpad.left = true;
            break;
        case 7:
            ds_input.dpad.left = true;
            ds_input.dpad.up = true;
            break;
    }
   
    
    //Stick press BT 0x06
    ds_input.leftStick.stickPress = (_reportData[10 + index_shift] & DualSense_ISTATE_BTN_A_LEFT_STICK) != 0;
    ds_input.rightStick.stickPress = (_reportData[10 + index_shift] & DualSense_ISTATE_BTN_A_RIGHT_STICK) != 0;
    

    // other buttons BT 0x06
    ds_input.buttons.select = (_reportData[10 + index_shift] & DualSense_ISTATE_BTN_A_SELECT) != 0;
    ds_input.buttons.menu = (_reportData[10 + index_shift] & DualSense_ISTATE_BTN_A_MENU) != 0;
    ds_input.buttons.r1 = (_reportData[10 + index_shift] & DualSense_ISTATE_BTN_A_RIGHT_BUMPER) != 0;
    ds_input.buttons.l1 = (_reportData[10 + index_shift] & DualSense_ISTATE_BTN_A_LEFT_BUMPER) != 0;
    ds_input.buttons.touchPad = (_reportData[11 + index_shift] & DualSense_ISTATE_BTN_B_PAD_BUTTON) != 0;
    
    // Convert trigger to unsigned range, BT 0x09
    ds_input.leftTrigger = (_reportData[6 + index_shift] << 4) / 4080.;
    ds_input.rightTrigger = (_reportData[7 + index_shift] << 4) / 4080.;
   
    //https://github.com/JibbSmart/JoyShockLibrary/blob/eba751b6bddf5edc783790af35b663dec7495dcc/JoyShockLibrary/InputHelpers.cpp
    //TouchPoint 2 points
    ds_input.touchPoint1.id = _reportData[34 + index_shift] & 0x7F;
    ds_input.touchPoint2.id = _reportData[38 + index_shift] & 0x7F;
    
    ds_input.touchPoint1.down = (_reportData[34 + index_shift]& 0x80) == 0;
    ds_input.touchPoint2.down = (_reportData[38 + index_shift]& 0x80) == 0;
    
    ds_input.touchPoint1.x = (_reportData[35 + index_shift] | (_reportData[36 + index_shift] & 0x0F) << 8) / 1920.0f;
    ds_input.touchPoint1.y = 1.f - ((_reportData[36 + index_shift] & 0xF0) >> 4 | _reportData[37 + index_shift] << 4) / 1079.0f;
   
    ds_input.touchPoint2.x = (_reportData[39 + index_shift] | (_reportData[40 + index_shift] & 0x0F) << 8) / 1920.0f;
    ds_input.touchPoint2.y = 1.f - ((_reportData[40 + index_shift] & 0xF0) >> 4 | _reportData[41 + index_shift] << 4) / 1079.0f;
    
    if (enableIMU){
        //gyo // Gyroscope data is relative (degrees/s)
        ds_input.gyroscope.x = (float)uint16_to_int16(_reportData[17 + index_shift] | ((_reportData[18 + index_shift] << 8) & 0xFF00)) * (2000.0f / 32767.0f);
        ds_input.gyroscope.y = (float)uint16_to_int16(_reportData[19 + index_shift] | ((_reportData[20 + index_shift] << 8) & 0xFF00)) * (2000.0f / 32767.0f);
        ds_input.gyroscope.z = (float)uint16_to_int16(_reportData[21 + index_shift] | ((_reportData[22 + index_shift] << 8) & 0xFF00)) * (2000.0f / 32767.0f);
        
        //accelerometer // convert to real units
        ds_input.accelerometer.x = (float)uint16_to_int16(_reportData[23 + index_shift] | ((_reportData[24 + index_shift] << 8) & 0xFF00)) / 8192.0f;
        ds_input.accelerometer.y = (float)uint16_to_int16(_reportData[25 + index_shift] | ((_reportData[26 + index_shift] << 8) & 0xFF00)) / 8192.0f;
        ds_input.accelerometer.z = (float)uint16_to_int16(_reportData[27 + index_shift] | ((_reportData[28 + index_shift] << 8) & 0xFF00)) / 8192.0f;
    }
    
    
    // Evaluate headphone input
    ds_input.headPhoneConnected = _reportData[0x37 + index_shift] & 0x01;
    
    // Trigger force feedback
    ds_input.leftTriggerFeedback = _reportData[0x2A + 2 + index_shift];
    ds_input.rightTriggerFeedback = _reportData[0x29 + 2 + index_shift];
    
    
    // Battery
    ds_input.battery.chargin = (_reportData[0x35 + 2 + index_shift] & 0x08);
    ds_input.battery.fullyCharged = (_reportData[0x36 + 2 + index_shift] & 0x20);
    ds_input.battery.level = (_reportData[0x36 + 2 + index_shift] & 0x0F);
    
}


