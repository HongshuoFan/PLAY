/*
  ==============================================================================

    XboxControllerState.h
    Created: 7 Nov 2023 9:31:48am
    Author:  Hongshuo Fan

  ==============================================================================
*/

#pragma once

#define XBOX_A                0x0100
#define XBOX_B                0x0200

#define XBOX_X                0x0800
#define XBOX_Y                0x1000

#define XBOX_LB               0x4000
#define XBOX_RB               0x8000

#define XBOX_LeftStick        0x0020
#define XBOX_RightStick       0x0040

#define XBOX_MENU             0x0800
#define XBOX_VIEW             0x0400

namespace XboxCotroller {

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

    typedef struct _Buttons{
        
        bool x;
        bool y;
        bool a;
        bool b;
        bool menu;
        bool view;
        bool share;
        bool lb;
        bool rb;

    } Buttons;

    typedef struct _XboxCotrollerInputState{
        
        AnalogStick leftStick;
        AnalogStick rightStick;
        
        Dpad dpad;
        
        Buttons buttons;
        
        float leftTrigger;
        float rightTrigger;
        
    } XboxCotrollerInputState;

}
