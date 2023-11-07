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
    // Convert sticks to signed range
    XC_input.leftStick.x = (_reportData[2] << 8) | (_reportData[1] & 0xFF);
    XC_input.leftStick.y = (_reportData[4] << 8) | (_reportData[3] & 0xFF);
    XC_input.rightStick.x = (_reportData[6] << 8) | (_reportData[5] & 0xFF);
    XC_input.rightStick.y = (_reportData[8] << 8) | (_reportData[7] & 0xFF);
//    XC_input.leftStick.x = ((uint16_t)_reportData[2] << 8) | _reportData[1];
    std::cout<< XC_input.rightStick.y<<"\n";
}



