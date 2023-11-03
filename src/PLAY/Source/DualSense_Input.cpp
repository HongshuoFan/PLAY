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
    DS_input.buttonsAndDpad = _reportData[0x05] & 0xF0;
    
    std::cout << DS_input.buttonsAndDpad << std::endl;
}


