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

void DualSense_Input::evaluateDualSenseHidInputBuffer(uint8_t *_reportData) { 
    // Convert sticks to signed range
    DS_input.leftStick.x = (int)(_reportData[0x01] - 128);
    DS_input.leftStick.y = (int)((_reportData[0x02] - 128) * -1);
    DS_input.rightStick.x = (int)(_reportData[0x03] - 128);
    DS_input.rightStick.y = (int)((_reportData[0x04] - 128) * -1);
    
    // Convert trigger to unsigned range
    DS_input.leftTrigger = (int)(_reportData[0x08] & 0xF0);
    DS_input.rightTrigger = (int)(_reportData[0x09] & 0xF0);
    
    // Buttons
    uint8_t buttonData = _reportData[0x05];
    DS_input.buttons.cross = (buttonData & DualSense_ISTATE_BTX_CROSS) != 0;
    DS_input.buttons.square = (buttonData & DualSense_ISTATE_BTX_SQUARE) != 0;
    DS_input.buttons.circle = (buttonData & DualSense_ISTATE_BTX_CIRCLE) != 0;
    DS_input.buttons.triangle = (buttonData & DualSense_ISTATE_BTX_TRIANGLE) != 0;
    
    //Dpad
    DS_input.dpad.left = (buttonData & DualSense_ISTATE_DPAD_LEFT) != 0;
    
//    uint16_t states = (_reportData[5] << 8) | (_reportData[0] & 0xFF);
//    int x1 = (states & (1 << 0)) ? 1 : 0;
    std::cout<<  DS_input.dpad.left << "\n";
    // Buttons
//    DS_input.buttonsAndDpad = _reportData[0x05] & 0xF0;
//    switch (_reportData[0x05] & 0x0F) {
//            // Up
//        case 0x0:
//            DS_input.buttonsAndDpad  |= DualSense_ISTATE_DPAD_UP;
//            std::cout<<  "DPAD_UP" << "\n";
//            break;
//            // Down
//        case 0x4:
//            DS_input.buttonsAndDpad |= DualSense_ISTATE_DPAD_DOWN;
//            std::cout<<  DS_input.buttonsAndDpad << "\n";
//            break;
//    }
}


