/*
  ==============================================================================

    JoyConState.h
    Created: 3 Dec 2023 10:33:29am
    Author:  Hongshuo Fan

  ==============================================================================
*/

#pragma once

namespace JoyCon {

    typedef struct _AnalogStick {
    
        float x = 0.f;
        float y = 0.f;
        bool stickPress = false;
        float x_max = -1000.f;
        float x_min = 1000.f;
        float y_max = -1000.f;
        float y_min = 1000.f;
    
    } AnalogStick;
    
    typedef struct _Dpad{
    
        bool up = false;
        bool down = false;
        bool left = false;
        bool right = false;

    } Dpad;

    typedef struct _Buttons_L{
            
            bool capture;
            bool minus;
            bool sr;
            bool sl;
            bool l;
            bool zl;

    } Buttons_L;

    typedef struct _Buttons_R{
        
        bool a = false;
        bool b = false;
        bool x = false;
        bool y = false;
        bool home;
        bool plus;
        bool sr;
        bool sl;
        bool r;
        bool zr;

    } Buttons_R;

    typedef struct _Vec3 {
        float x = 1000.f;
        float y = 1000.f;
        float z = 1000.f;
    } Vector3, Vec3;

    typedef struct _ir_image_config {
        uint8_t  ir_res_reg;
        uint16_t ir_exposure;
        uint8_t  ir_leds; // Leds to enable, Strobe/Flashlight modes
        uint16_t ir_leds_intensity; // MSByte: Leds 1/2, LSB: Leds 3/4
        uint8_t  ir_digital_gain;
        uint8_t  ir_ex_light_filter;
        uint32_t ir_custom_register; // MSByte: Enable/Disable, Middle Byte: Edge smoothing, LSB: Color interpolation
        uint16_t ir_buffer_update_time;
        uint8_t  ir_hand_analysis_mode;
        uint8_t  ir_hand_analysis_threshold;
        uint32_t ir_denoise; // MSByte: Enable/Disable, Middle Byte: Edge smoothing, LSB: Color interpolation
        uint8_t  ir_flip;
    } IR_image_config;

    typedef struct _JoyCon_L_InputState {
        
        AnalogStick stick;
        Buttons_L buttons;
        Dpad dpad;
        
        Vector3 accelerometer;
        Vector3 accelerometer_max;
        Vector3 accelerometer_min;
        
        Vector3 gyroscope;
        Vector3 gyroscope_max;
        Vector3 gyroscope_min;
        
    } L_JoyCon_InputState;

    typedef struct _JoyCon_R_InputState {
        
        AnalogStick stick;
        Buttons_R buttons;
        
        Vector3 accelerometer;
        Vector3 accelerometer_max;
        Vector3 accelerometer_min;
        
        Vector3 gyroscope;
        Vector3 gyroscope_max;
        Vector3 gyroscope_min;
        
    } R_JoyCon_InputState;

}
