/*
  ==============================================================================

    DualSense_Output.cpp
    Created: 6 Nov 2023 10:23:01am
    Author:  Hongshuo Fan

  ==============================================================================
*/

#include <JuceHeader.h>
#include "DualSense_Output.h"

//==============================================================================
DualSense_Output::DualSense_Output()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    //ds_crc32.InitializeTable(0xedb88320u);
}

DualSense_Output::~DualSense_Output()
{
}

void DualSense_Output::createDualSenseOutput() {
    
    _output[0] = 0x31;
    _output[1] = 0x02;
    int index_offset = usbOrBT == 1 ? 2 : 1;
   
    // Feature mask
    _output[0x00 + index_offset] = 0xFF;
    _output[0x01 + index_offset] = 0xF7;
    
    // Rumbel motors
    _output[0x02 + index_offset] = DS_output.leftRumble;
    _output[0x03 + index_offset] = DS_output.rightRumble;
    
    // Mic led
    _output[0x08 + index_offset] = (uint8_t)DS_output.microphoneLed;
    
    // Player led
    _output[0x2B + index_offset] = DS_output.playerLeds.bitmask;
    if (DS_output.playerLeds.playerLedFade) {
        _output[0x2B + index_offset] &= ~(0x20);
    }
    else {
        _output[0x2B + index_offset] |= 0x20;
    }
    // Player led brightness
    _output[0x26 + index_offset] = 0x03;
    _output[0x29 + index_offset] = DS_output.disableLeds ? 0x01 : 0x2;
    _output[0x2A + index_offset] = DS_output.playerLeds.brightness;
    
    // Lightbar
    _output[0x2C + index_offset] = DS_output.lightbar.r;
    _output[0x2D + index_offset] = DS_output.lightbar.g;
    _output[0x2E + index_offset] = DS_output.lightbar.b;
    
    // Adaptive Triggers
    processTrigger(&DS_output.leftTriggerEffect, &_output[0x15 + index_offset]);
    processTrigger(&DS_output.rightTriggerEffect, &_output[0x0A + index_offset]);
  
    
    uint32_t crc_Data = ds_crc32.compute(_output, 74);
    _output[0x4A] = (uint8_t)((crc_Data & 0x000000FF) >> 0UL);
    _output[0x4B] = (uint8_t)((crc_Data & 0x0000FF00) >> 8UL);
    _output[0x4C] = (uint8_t)((crc_Data & 0x00FF0000) >> 16UL);
    _output[0x4D] = (uint8_t)((crc_Data & 0xFF000000) >> 24UL);
    
}

void DualSense_Output::initialOuput(bool isBT) {
    usbOrBT = isBT;
    uint16_t lrmbl = 0.1;
    uint16_t rrmbl = 0.;
    int btMul = 10;
    
    lrmbl = fmax(lrmbl - 0x200 / btMul, 0);
    rrmbl = fmax(rrmbl - 0x100 / btMul, 0);
    
    DS_output.leftRumble = (lrmbl & 0xFF00)  >> 8UL;
    DS_output.rightRumble = (rrmbl & 0xFF00) >> 8UL;
    DS_output.microphoneLed = DualSense::MicLed::PULSE;
    //DS_output.disableLeds = true;
    DS_output.playerLeds.bitmask = DualSense_OSTATE_PLAYER_LED_MIDDLE;
    //DS_output.playerLeds.brightness = DualSense::LedBrightness::LOW;
    DS_output.lightbar = color_R8G8B8_UCHAR_A32_FLOAT(128, 0, 0, 0.5);
    
//    // Left trigger is clicky / section
//    DS_output.leftTriggerEffect.effectType = DualSense::TriggerEffectType::SectionResitance;
//    DS_output.leftTriggerEffect.Section.startPosition = 0x00;
//    DS_output.leftTriggerEffect.Section.endPosition = 0x60;
//
    // Right trigger is forcy
//    DS_output.rightTriggerEffect.effectType = DualSense::TriggerEffectType::ContinuousResitance;
//    DS_output.rightTriggerEffect.Continuous.force = 0x00;
//    DS_output.rightTriggerEffect.Continuous.startPosition = 0x00;
//    
//    DS_output.leftTriggerEffect.effectType = DualSense::TriggerEffectType::ContinuousResitance;
//    DS_output.leftTriggerEffect.Continuous.force = 0x00;
//    DS_output.leftTriggerEffect.Continuous.startPosition = 0x00;
    
    createDualSenseOutput();
}

void DualSense_Output::disConnectOutput() {
    
//    _output[0] = 0x31;
//    _output[1] = 0x02;
//    _output[2] = 0x00;
//    _output[3] = 0xff;
    DS_output.leftRumble = 0x00;
    DS_output.rightRumble = 0x00;
    DS_output.microphoneLed = DualSense::MicLed::OFF;
    DS_output.disableLeds = true;
    DS_output.playerLeds.bitmask = 0;
    DS_output.playerLeds.brightness = DualSense::LedBrightness::LOW;
    
    // Left trigger is clicky / section
    DS_output.leftTriggerEffect.effectType = DualSense::TriggerEffectType::NoResitance;
    
    // Right trigger is forcy
    DS_output.rightTriggerEffect.effectType = DualSense::TriggerEffectType::NoResitance;
;
    
    createDualSenseOutput();
}

DualSense::Color DualSense_Output::color_R8G8B8_UCHAR_A32_FLOAT(unsigned char r, unsigned char g, unsigned char b, float a)
{
    return { (unsigned char)(r * a), (unsigned char)(g * a), (unsigned char)(b * a) };
}


void DualSense_Output::processTrigger(DualSense::TriggerEffect* ptrEffect, unsigned char* buffer)
{
    // Switch on effect
        switch (ptrEffect->effectType) {
            // Continious
            case DualSense::TriggerEffectType::ContinuousResitance:
                // Mode
                buffer[0x00] = 0x01;
                // Parameters
                buffer[0x01] = ptrEffect->Continuous.startPosition;
                buffer[0x02] = ptrEffect->Continuous.force;

                break;

            // Section
            case DualSense::TriggerEffectType::SectionResitance:
                // Mode
                buffer[0x00] = 0x02;
                // Parameters
                buffer[0x01] = ptrEffect->Continuous.startPosition;
                buffer[0x02] = ptrEffect->Continuous.force;

                break;

            // EffectEx
            case DualSense::TriggerEffectType::EffectEx:
                // Mode
                buffer[0x00] = 0x02 | 0x20 | 0x04;
                // Parameters
                buffer[0x01] = 0xFF - ptrEffect->EffectEx.startPosition;
                // Keep flag
                if (ptrEffect->EffectEx.keepEffect) {
                    buffer[0x02] = 0x02;
                }
                // Forces
                buffer[0x04] = ptrEffect->EffectEx.beginForce;
                buffer[0x05] = ptrEffect->EffectEx.middleForce;
                buffer[0x06] = ptrEffect->EffectEx.endForce;
                // Frequency
                buffer[0x09] = fmax(1, ptrEffect->EffectEx.frequency / 2);

                break;

            // Calibrate
            case DualSense::TriggerEffectType::Calibrate:
                // Mode
                buffer[0x00] = 0xFC;

                break;

            // No resistance / default
            case DualSense::TriggerEffectType::NoResitance:
                
            default:
                // All zero
                buffer[0x00] = 0x00;
                buffer[0x01] = 0x00;
                buffer[0x02] = 0x00;

                break;
        }
}

void DualSense_Output::updateTrigger(float triggerForce)
{
    float tf = triggerForce * 255.;
    
    unsigned char force = (unsigned char)tf;
    DS_output.microphoneLed = DualSense::MicLed::PULSE;
    //DS_output.disableLeds = true;
    DS_output.playerLeds.bitmask = DualSense_OSTATE_PLAYER_LED_MIDDLE;
    //DS_output.playerLeds.brightness = DualSense::LedBrightness::LOW;
    DS_output.lightbar = color_R8G8B8_UCHAR_A32_FLOAT(255., 0, 0, triggerForce);
    // Right trigger is forcy
    DS_output.rightTriggerEffect.effectType = DualSense::TriggerEffectType::ContinuousResitance;
    DS_output.rightTriggerEffect.Continuous.force = force;
//    DS_output.rightTriggerEffect.Continuous.startPosition = 0x00;
    
    DS_output.leftTriggerEffect.effectType = DualSense::TriggerEffectType::ContinuousResitance;
    DS_output.leftTriggerEffect.Continuous.force = force;
//    DS_output.leftTriggerEffect.Continuous.startPosition = 0x00;
    
    createDualSenseOutput();
}

void DualSense_Output::rumble(float force)
{
    unsigned char rf = (unsigned char)(force * 128.);
    DS_output.leftRumble = rf;
    DS_output.rightRumble = rf;
    createDualSenseOutput();
}
