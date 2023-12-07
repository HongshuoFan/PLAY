/*
  ==============================================================================

    JoyCon_Output.h
    Created: 3 Dec 2023 1:42:39pm
    Author:  Hongshuo Fan

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "ir_sensor.h"
//==============================================================================
/*
*/
class JoyCon_Output  : public juce::Component
{
public:
    JoyCon_Output();
    ~JoyCon_Output() override;
    uint8_t _output[49];
    void trunIMU(bool on_off);
    void changeMode(uint8_t arg);
    void Vibration(double highFreq, double highAmp, double lowFreq, double lowAmp, bool isLeft);
    
    void enableMCU();
    void setMCUMode();
    
private:
    
    uint8_t mcu_crc8_calc(uint8_t *buf, uint8_t size);
    
    void initBasicOutput();
    
    uint8_t globalPacketNumber = 0x00;
    
    uint8_t __encodeFreq(double Freq);
    uint8_t __encodeAmp(double Amp);
    uint16_t __encodeLowAmp(double Amp);
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JoyCon_Output)
};
