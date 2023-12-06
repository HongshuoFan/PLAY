/*
  ==============================================================================

    DualSenseState.h
    Created: 3 Nov 2023 2:01:33pm
    Author:  Hongshuo Fan

  ==============================================================================
*/

#pragma once

#define DualSense_ISTATE_BTX_SQUARE 0x10
#define DualSense_ISTATE_BTX_CROSS 0x20
#define DualSense_ISTATE_BTX_CIRCLE 0x40
#define DualSense_ISTATE_BTX_TRIANGLE 0x80
#define DualSense_ISTATE_DPAD_LEFT 0x01
#define DualSense_ISTATE_DPAD_DOWN 0x02
#define DualSense_ISTATE_DPAD_RIGHT 0x04
#define DualSense_ISTATE_DPAD_UP 0x08

#define DualSense_ISTATE_BTN_A_LEFT_BUMPER 0x01
#define DualSense_ISTATE_BTN_A_RIGHT_BUMPER 0x02
#define DualSense_ISTATE_BTN_A_LEFT_TRIGGER 0x04
#define DualSense_ISTATE_BTN_A_RIGHT_TRIGGER 0x08
#define DualSense_ISTATE_BTN_A_SELECT 0x10
#define DualSense_ISTATE_BTN_A_MENU 0x20
#define DualSense_ISTATE_BTN_A_LEFT_STICK 0x40
#define DualSense_ISTATE_BTN_A_RIGHT_STICK 0x80

#define DualSense_ISTATE_BTN_B_PLAYSTATION_LOGO 0x01
#define DualSense_ISTATE_BTN_B_PAD_BUTTON 0x02
#define DualSense_ISTATE_BTN_B_MIC_BUTTON 0x04

#define DualSense_OSTATE_PLAYER_LED_LEFT 0x01
#define DualSense_OSTATE_PLAYER_LED_MIDDLE_LEFT 0x02
#define DualSense_OSTATE_PLAYER_LED_MIDDLE 0x04
#define DualSense_OSTATE_PLAYER_LED_MIDDLE_RIGHT 0x08
#define DualSense_OSTATE_PLAYER_LED_RIGHT 0x10

namespace DualSense {

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

    /// <summary>
    /// 3 Component vector
    /// </summary>
    typedef struct _Vec3 {
        float x;
        float y;
        float z;
    } Vector3, Vec3;

    /// <summary>
    /// RGB Color
    /// </summary>
    typedef struct _Color {
        unsigned char r;
        unsigned char g;
        unsigned char b;
    } Color;
    
    typedef struct _Dpad{
        bool up;
        bool down;
        bool left;
        bool right;
    
    } Dpad;

    typedef struct _Buttons{
        
        bool cross;
        bool square;
        bool circle;
        bool triangle;
        bool select;
        bool menu;
        bool r1;
        bool l1;
        bool touchPad;

    } Buttons;
    /// <summary>
    /// Touchpad state
    /// </summary>
    typedef struct _Touch {
        /// <summary>
        /// X positon of finger (~ 0 - 2000)
        /// </summary>
        float x;

        /// <summary>
        /// Y position of finger (~ 0 - 2048)
        /// </summary>
        float y;

        /// <summary>
        /// Touch is down
        /// </summary>
        bool down;

        /// <summary>
        /// int ID for touch
        /// </summary>
        int id;
    } Touch;

    typedef struct _Battery {
        /// <summary>
        /// Charching state of the battery
        /// </summary>
        bool chargin;

        /// <summary>
        /// Indicates that the battery is fully charged
        /// </summary>
        bool fullyCharged;

        /// <summary>
        /// Battery charge level 0x0 to
        /// </summary>
        unsigned char level;
    }Battery;

    /// <summary>
    /// State of the mic led
    /// </summary>
    typedef enum class _MicLed : unsigned char{
        /// <summary>
        /// Lef is off
        /// </summary>
        OFF = 0x00,

        /// <summary>
        /// Led is on
        /// </summary>
        ON = 0x01,

        /// <summary>
        /// Led is pulsing
        /// </summary>
        PULSE = 0x02,
    } MicLed;

    /// <summary>
    /// Type of trigger effect
    /// </summary>
    typedef enum class _TriggerEffectType : unsigned char {
        /// <summary>
        /// No resistance is applied
        /// </summary>
        NoResitance = 0x00,

        /// <summary>
        /// Continuous Resitance is applied
        /// </summary>
        ContinuousResitance = 0x01,

        /// <summary>
        /// Seciton resistance is appleyed
        /// </summary>
        SectionResitance = 0x02,

        /// <summary>
        /// Extended trigger effect
        /// </summary>
        EffectEx = 0x26,

        /// <summary>
        /// Calibrate triggers
        /// </summary>
        Calibrate = 0xFC,
    } TriggerEffectType;

    /// <summary>
    /// Trigger effect
    /// </summary>
    typedef struct _TriggerEffect {
        /// <summary>
        /// Trigger effect type
        /// </summary>
        TriggerEffectType effectType;

        /// <summary>
        /// Union for effect parameters
        /// </summary>
        union {
            /// <summary>
            /// Union one raw data
            /// </summary>
            unsigned char _u1_raw[6];

            /// <summary>
            /// For type == ContinuousResitance
            /// </summary>
            struct {
                /// <summary>
                /// Start position of resistance
                /// </summary>
                unsigned char startPosition;

                /// <summary>
                /// Force of resistance
                /// </summary>
                unsigned char force;

                /// <summary>
                /// PAD / UNUSED
                /// </summary>
                unsigned char _pad[4];
            } Continuous;

            /// <summary>
            /// For type == SectionResitance
            /// </summary>
            struct {
                /// <summary>
                /// Start position of resistance
                /// </summary>
                unsigned char startPosition;

                /// <summary>
                /// End position of resistance (>= start)
                /// </summary>
                unsigned char endPosition;
                
                /// <summary>
                /// PAD / UNUSED
                /// </summary>
                unsigned char _pad[4];
            } Section;

            /// <summary>
            /// For type == EffectEx
            /// </summary>
            struct {
                /// <summary>
                /// Position at witch the effect starts
                /// </summary>
                unsigned char startPosition;

                /// <summary>
                /// Wher the effect should keep playing when trigger goes beyond 255
                /// </summary>
                bool keepEffect;

                /// <summary>
                /// Force applied when trigger >= (255 / 2)
                /// </summary>
                unsigned char beginForce;

                /// <summary>
                /// Force applied when trigger <= (255 / 2)
                /// </summary>
                unsigned char middleForce;

                /// <summary>
                /// Force applied when trigger is beyond 255
                /// </summary>
                unsigned char endForce;

                /// <summary>
                /// Vibration frequency of the trigger
                /// </summary>
                unsigned char frequency;
            } EffectEx;
        };
    } TriggerEffect;

    /// <summary>
    /// Led brightness
    /// </summary>
    typedef enum _LedBrightness : unsigned char {
        /// <summary>
        /// Low led brightness
        /// </summary>
        LOW = 0x02,

        /// <summary>
        /// Medium led brightness
        /// </summary>
        MEDIUM = 0x01,

        /// <summary>
        /// High led brightness
        /// </summary>
        HIGH = 0x00,
    } LedBrightness;

    /// <summary>
    /// Player leds values
    /// </summary>
    typedef struct _PlayerLeds {
        /// <summary>
        /// Player indication leds bitflag (You may used them for other features) DualSense_OSTATE_PLAYER_LED_???
        /// </summary>
        unsigned char bitmask;

        /// <summary>
        /// Indicates weather the player leds should fade in
        /// </summary>
        bool playerLedFade;

        /// <summary>
        /// Brightness of the player leds
        /// </summary>
        LedBrightness brightness;
    } PlayerLeds;

    /// <summary>
    /// Input state of the controler
    /// </summary>
    typedef struct _DualSenseInputState {
        /// <summary>
        /// Position of left stick
        /// </summary>
        AnalogStick leftStick;
        
        /// <summary>
        /// Posisiton of right stick
        /// </summary>
        AnalogStick rightStick;

        /// <summary>
        /// Left trigger position
        /// </summary>
        float leftTrigger;

        /// <summary>
        /// Right trigger position
        /// </summary>
        float rightTrigger;

        Dpad dpad;
        
        Buttons buttons;
        /// <summary>
        /// Buttons and dpad bitmask DualSense_ISTATE_BTX_?? and DualSense_ISTATE_DPAD_?? indices check with if(buttonsAndDpad & DualSense_ISTATE_DPAD_??)...
        /// </summary>
        unsigned char buttonsAndDpad;

        /// <summary>
        /// Button bitmask A (DualSense_ISTATE_BTN_A_??)
        /// </summary>
        unsigned char buttonsA;

        /// <summary>
        /// Button bitmask B (DualSense_ISTATE_BTN_B_??)
        /// </summary>
        unsigned char buttonsB;

        /// <summary>
        /// Accelerometer
        /// </summary>
        Vector3 accelerometer;

        /// <summary>
        /// Gyroscope  (Currently only raw values will be dispayed! Probably needs calibration (Will be done within the lib in the future))
        /// </summary>
        Vector3 gyroscope;

        /// <summary>
        /// First touch point
        /// </summary>
        Touch touchPoint1;

        /// <summary>
        /// Second touch point
        /// </summary>
        Touch touchPoint2;

        /// <summary>
        /// Battery information
        /// </summary>
        Battery battery;

        /// <summary>
        /// Indicates the connection of headphone
        /// </summary>
        bool headPhoneConnected;

        /// <summary>
        /// EXPERIMAENTAL: Feedback of the left adaptive trigger (only when trigger effect is active)
        /// </summary>
        unsigned char leftTriggerFeedback;

        /// <summary>
        /// EXPERIMAENTAL: Feedback of the right adaptive trigger (only when trigger effect is active)
        /// </summary>
        unsigned char rightTriggerFeedback;
    } DualSenseInputState;

    typedef struct _DualSenseOutputState {
        /// <summary>
        /// Left / Hard rumbel motor
        /// </summary>
        unsigned char leftRumble;

        /// <summary>
        /// Right / Soft rumbel motor
        /// </summary>
        unsigned char rightRumble;

        /// <summary>
        /// State of the microphone led
        /// </summary>
        MicLed microphoneLed;

        /// <summary>
        /// Diables all leds
        /// </summary>
        bool disableLeds;

        /// <summary>
        /// Player leds
        /// </summary>
        PlayerLeds playerLeds;

        /// <summary>
        /// Color of the lightbar
        /// </summary>
        Color lightbar;

        /// <summary>
        /// Effect of left trigger
        /// </summary>
        TriggerEffect leftTriggerEffect;

        /// <summary>
        /// Effect of right trigger
        /// </summary>
        TriggerEffect rightTriggerEffect;

    } DualSenseOutputState;
}
