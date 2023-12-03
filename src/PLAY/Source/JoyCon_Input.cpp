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
        
        uint8_t *btn_data = _reportData + 3;
        uint16_t states = 0;
        states = (btn_data[1] << 8) | (btn_data[2] & 0xFF);
           
        l_jc_input.dpad.down = (states & (1 << 0)) ? 1 : 0;
        l_jc_input.dpad.up = (states & (1 << 1)) ? 1 : 0;
        l_jc_input.dpad.right = (states & (1 << 2)) ? 1 : 0;
        l_jc_input.dpad.left = (states & (1 << 3)) ? 1 : 0;
        l_jc_input.buttons.sr = (states & (1 << 4)) ? 1 : 0;
        l_jc_input.buttons.sl = (states & (1 << 5)) ? 1 : 0;
        l_jc_input.buttons.l = (states & (1 << 6)) ? 1 : 0;
        l_jc_input.buttons.zl = (states & (1 << 7)) ? 1 : 0;
        l_jc_input.buttons.minus = (states & (1 << 8)) ? 1 : 0;
        l_jc_input.stick.stickPress = (states & (1 << 11)) ? 1 : 0;
        l_jc_input.buttons.capture = (states & (1 << 13)) ? 1 : 0;

        uint8_t *stick_data = _reportData + 6;
        l_jc_input.stick.x = stick_data[0] | ((stick_data[1] & 0xF) << 8);
        l_jc_input.stick.y = (stick_data[1] >> 4) | (stick_data[2] << 4);
        CalcAnalogStickSub(&l_jc_input.stick);
    
        
        if(_reportData[0] == 0x30 || _reportData[0] == 0x31)
        {
            // Accelerometer:
            // Accelerometer data is absolute (m/s^2)
            l_jc_input.accelerometer.x = (float)(uint16_to_int16(_reportData[13] | ((_reportData[14] << 8) & 0xFF00)));
            l_jc_input.accelerometer.y = (float)(uint16_to_int16(_reportData[15] | ((_reportData[16] << 8) & 0xFF00)));
            l_jc_input.accelerometer.z = (float)(uint16_to_int16(_reportData[17] | ((_reportData[18] << 8) & 0xFF00)));
            
            NormalizVec3(&l_jc_input.accelerometer, &l_jc_input.accelerometer_min, &l_jc_input.accelerometer_max);
            
            l_jc_input.gyroscope.x = (float)(uint16_to_int16(_reportData[19] | ((_reportData[20] << 8) & 0xFF00)))
                                    * (2000.0f / 32767.0f);
            l_jc_input.gyroscope.y = (float)(uint16_to_int16(_reportData[21] | ((_reportData[22] << 8) & 0xFF00)))
                                    * (2000.0f / 32767.0f);
            l_jc_input.gyroscope.z = (float)(uint16_to_int16(_reportData[23] | ((_reportData[24] << 8) & 0xFF00)))
                                    * (2000.0f / 32767.0f);
            
            //NormalizVec3(&l_jc_input.gyroscope, &l_jc_input.gyroscope_min, &l_jc_input.gyroscope_max);
            
            std::cout<<l_jc_input.gyroscope.x << "\n";
            std::cout<<l_jc_input.gyroscope.y << "\n";
            std::cout<<l_jc_input.gyroscope.z << "\n";
        }
    }
}

void JoyCon_Input::evaluate_R_JC_HidInputBuffer(uint8_t* _reportData)
{
    
}

void JoyCon_Input::CalcAnalogStickSub(JoyCon::AnalogStick* InputStick)
{
    float x = InputStick->x;
    float y = InputStick->y;
    
    InputStick->x_max = fmax(InputStick->x_max, x);
    InputStick->x_min = fmin(InputStick->x_min, x);
    InputStick->y_max = fmax(InputStick->y_max, y);
    InputStick->y_min = fmin(InputStick->y_min, y);
    
    x = (x - InputStick->x_min) / (InputStick->x_max - InputStick->x_min);
    y = (y - InputStick->y_min) / (InputStick->y_max - InputStick->y_min);
    
    InputStick->x = clamp(x, 0.f, 1.f);
    InputStick->y = clamp(y, 0.f, 1.f);
}

float JoyCon_Input::clamp(float a, float min, float max) {
    return fmax(min, fmin(a, max));
}

void JoyCon_Input::NormalizVec3(JoyCon::Vec3* InV3, JoyCon::Vec3* v3min, JoyCon::Vec3* v3max)
{
    float x = InV3->x;
    float y = InV3->y;
    float z = InV3->z;

    v3max->x = fmax(v3max->x, x);
    v3min->x = fmin(v3min->x, x);
    
    v3max->y = fmax(v3max->y, y);
    v3min->y = fmin(v3min->y, y);
    
    v3max->z = fmax(v3max->z, z);
    v3min->z = fmin(v3min->z, z);
    
    x = (x - v3min->x) / (v3max->x - v3min->x);
    y = (y - v3min->y) / (v3max->y - v3min->y);
    z = (z - v3min->z) / (v3max->z - v3min->z);
    
    InV3->x = clamp(x, 0.f, 1.f);
    InV3->y = clamp(y, 0.f, 1.f);
    InV3->z = clamp(z, 0.f, 1.f);
}
