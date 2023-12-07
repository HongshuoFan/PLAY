/*
  ==============================================================================

    DualSense_Output.h
    Created: 6 Nov 2023 10:23:01am
    Author:  Hongshuo Fan

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "DualSenseState.h"
#include "DualSense_CRC32.h"
//==============================================================================
/*
*/
class DualSense_Output  : public juce::Component
{
public:
    DualSense_Output();
    ~DualSense_Output() override;
    
    //DualSense::DualSenseOutputState DS_output;
    uint8_t _output[78];
    void createDualSenseOutput();
    void initialOuput();
    void disConnectOutput();
    void processTrigger(DualSense::TriggerEffect* ptrEffect, unsigned char* buffer);
    DualSense::Color color_R8G8B8_UCHAR_A32_FLOAT(unsigned char r, unsigned char g, unsigned char b, float a);
    
    DualSense::DualSenseOutputState DS_output;
    
private:
    __DS5W::CRC32 ds_crc32;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DualSense_Output)
};
