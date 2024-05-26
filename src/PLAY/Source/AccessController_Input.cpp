/*
  ==============================================================================

    AccessController_Input.cpp
    Created: 26 May 2024 7:06:01pm
    Author:  Hongshuo Fan

  ==============================================================================
*/

#include <JuceHeader.h>
#include "AccessController_Input.h"

//==============================================================================
AccessController_Input::AccessController_Input()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

AccessController_Input::~AccessController_Input()
{
}


void AccessController_Input::evaluateAccessControllerHidInputBuffer(uint8_t *_reportData, bool enableIMU) {
    //0x31 BT
    int index_shift = _reportData[0] == 0x31 ? 0 : -1;
    usbOrBT = _reportData[0] == 0x31 ? true : false;
    
    // Convert sticks to signed range 0 4080
    ac_input.stick.x = (_reportData[2 + index_shift] << 4) / 4080.;
    ac_input.stick.y = 1. - (_reportData[3 + index_shift] << 4) / 4080.;
    ac_input.stick.stickPress = (_reportData[10 + index_shift] & AccessController_ISTATE_BTN_A_STICK) != 0;
    
    uint8_t buttonData = _reportData[17 + index_shift];
    ac_input.buttons.b1 = (buttonData & AccessController_ISTATE_BTX_B1) != 0;
    ac_input.buttons.b2 = (buttonData & AccessController_ISTATE_BTX_B2) != 0;
    ac_input.buttons.b3 = (buttonData & AccessController_ISTATE_BTX_B3) != 0;
    ac_input.buttons.b4 = (buttonData & AccessController_ISTATE_BTX_B4) != 0;
    ac_input.buttons.b5 = (buttonData & AccessController_ISTATE_BTX_B5) != 0;
    ac_input.buttons.b6 = (buttonData & AccessController_ISTATE_BTX_B6) != 0;
    ac_input.buttons.b7 = (buttonData & AccessController_ISTATE_BTX_B7) != 0;
    ac_input.buttons.b8 = (buttonData & AccessController_ISTATE_BTX_B8) != 0;

    
    ac_input.buttons.b0 = (_reportData[18 + index_shift] & 0x01) != 0;
    ac_input.buttons.ps = (_reportData[18 + index_shift] & 0x04) != 0;
    ac_input.buttons.profile = (_reportData[18 + index_shift] & 0x08) != 0;
//    std::cout<< "b0: "<<ac_input.buttons.b0<<std::endl;
//    std::cout<< "profile: "<<ac_input.buttons.profile<<std::endl;
//    std::cout<< "ps: "<<ac_input.buttons.ps<<std::endl;
}
