/*
  ==============================================================================

    JoyCon_Input.cpp
    Created: 3 Dec 2023 10:50:57am
    Author:  Hongshuo Fan

  ==============================================================================
*/

#include <JuceHeader.h>
#include "JoyCon_Input.h"

//==============================================================================
JoyCon_Input::JoyCon_Input()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    //l_jc_input = new JoyCon::L_JoyCon_InputState;
}

JoyCon_Input::~JoyCon_Input()
{
}

int16_t JoyCon_Input::uint16_to_int16(uint16_t a)
{
    int16_t b;
    char* aPointer = (char*)&a, *bPointer = (char*)&b;
    memcpy(bPointer, aPointer, sizeof(a));
    return b;
}

void JoyCon_Input::evaluate_L_JC_HidInputBuffer(uint8_t* _reportData)
{
    // 0x21 is just states, 0x30 includes gyro, 0x31 includes NFC (large packet size)
    if(_reportData){
        if (_reportData[0] == 0x21 || _reportData[0] == 0x30)
        {
            uint8_t *btn_data = _reportData + 3;
            uint16_t states = 0;
            states = (btn_data[1] << 8) | (btn_data[2] & 0xFF);
            
//            l_jc_input.dpad.down = (states & (1 << 0)) ? true : false;
//            l_jc_input.dpad.up = (states & (1 << 1)) ? 1 : 0;
//            l_jc_input.dpad.right = (states & (1 << 2)) ? 1 : 0;
//            l_jc_input.dpad.left = (states & (1 << 3)) ? 1 : 0;
//            l_jc_input.buttons.sr = (states & (1 << 4)) ? 1 : 0;
//            l_jc_input.buttons.sl = (states & (1 << 5)) ? 1 : 0;
//            l_jc_input.buttons.l = (states & (1 << 6)) ? 1 : 0;
//            l_jc_input.buttons.zl = (states & (1 << 7)) ? 1 : 0;
//            l_jc_input.buttons.minus = (states & (1 << 8)) ? 1 : 0;
//            l_jc_input.stick.stickPress = (states & (1 << 11)) ? 1 : 0;
//            l_jc_input.buttons.capture = (states & (1 << 13)) ? 1 : 0;
//
//            uint8_t *stick_data = _reportData + 6;
//            l_jc_input.stick.x = stick_data[0] | ((stick_data[1] & 0xF) << 8);
//            l_jc_input.stick.y = (stick_data[1] >> 4) | (stick_data[2] << 4);
//
//            std::cout<<l_jc_input.stick.x<< "\n";
//            std::cout<<l_jc_input.stick.y<< "\n";
        }
    }
}

void JoyCon_Input::evaluate_R_JC_HidInputBuffer(uint8_t* _reportData)
{
    
}
