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
        float x = 0;
        float y = 0;
        float z = 0;
    } Vector3, Vec3;

    typedef struct _JoyCon_L_InputState {
        
        AnalogStick stick;
        Buttons_L buttons;
        Dpad dpad;
        Vector3 accelerometer;
        Vector3 gyroscope;
        
    } L_JoyCon_InputState;

    typedef struct _JoyCon_R_InputState {
        
        AnalogStick stick;
        Buttons_R buttons;
        Vector3 accelerometer;
        Vector3 gyroscope;
        
    } R_JoyCon_InputState;
}
