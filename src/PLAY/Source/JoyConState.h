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
    
        float x;
        float y;
        bool stickPress;
    
    } AnalogStick;
    
    typedef struct _Dpad{
    
        bool up;
        bool down;
        bool left;
        bool right;

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
        
        bool a;
        bool b;
        bool x;
        bool y;
        bool home;
        bool plus;
        bool sr;
        bool sl;
        bool r;
        bool zr;

    } Buttons_R;

    typedef struct _Vec3 {
        float x;
        float y;
        float z;
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
