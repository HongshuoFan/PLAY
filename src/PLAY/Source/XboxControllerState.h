/*
  ==============================================================================

    XboxControllerState.h
    Created: 7 Nov 2023 9:31:48am
    Author:  Hongshuo Fan

  ==============================================================================
*/

#pragma once

namespace XboxCotroller {

    typedef struct _AnalogStick {
        
        int x;
        int y;
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
        bool select;
        bool menu;
        bool lb;
        bool rb;

    } Buttons;

    typedef struct _XboxCotrollerInputState{
        
        AnalogStick leftStick;
        AnalogStick rightStick;
        
        Dpad dpad;
        
        Buttons buttons;
        
        unsigned int leftTrigger;
        unsigned int rightTrigger;
        
    } XboxCotrollerInputState;

}
