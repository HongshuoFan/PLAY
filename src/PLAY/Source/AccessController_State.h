/*
  ==============================================================================

    AccessController_State.h
    Created: 26 May 2024 7:07:28pm
    Author:  Hongshuo Fan

  ==============================================================================
*/

#pragma once

#define AccessController_ISTATE_BTN_A_STICK 0x40

#define AccessController_ISTATE_BTX_B1 0x01
#define AccessController_ISTATE_BTX_B2 0x02
#define AccessController_ISTATE_BTX_B3 0x04
#define AccessController_ISTATE_BTX_B4 0x08
#define AccessController_ISTATE_BTX_B5 0x10
#define AccessController_ISTATE_BTX_B6 0x20
#define AccessController_ISTATE_BTX_B7 0x40
#define AccessController_ISTATE_BTX_B8 0x80

namespace AccessController {

    /// <summary>
    /// Analog stick
    /// </summary>
    typedef struct _AnalogStick {
        /// <summary>
        /// X Position of stick (0 = Center)
        /// </summary>
        float x;
        
        /// <summary>
        /// Y Posistion of stick (0 = Center)
        /// </summary>
        float y;
        
        bool stickPress;
        
        
    } AnalogStick;

    typedef struct _Buttons{
        
        bool b0;
        bool b1;
        bool b2;
        bool b3;
        bool b4;
        bool b5;
        bool b6;
        bool b7;
        bool b8;
        bool ps;
        bool profile;

    } Buttons;

    typedef struct _EnableXY {
        
        bool x;
        bool y;

    } EnableXY;

    typedef struct _AccessControllerInputStates {
        
        AnalogStick stick;
        Buttons buttons;

    } AccessControllerInputStates;

    typedef struct _AccessControllerEnableStates {
        
        EnableXY StickStates;
        
    } AccessControllerEnableStates;

}
