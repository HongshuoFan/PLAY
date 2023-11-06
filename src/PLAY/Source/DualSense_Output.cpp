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

}

DualSense_Output::~DualSense_Output()
{
}

void DualSense_Output::createDualSenseOutput() {
    // Feature mask
    DS_output[0x00] = 0xFF;
    DS_output[0x01] = 0xF7;
    // Rumbel motors
    DS_output[0x02] = 0x01;
    DS_output[0x03] = 0x01;

//    // Mic led
//    DS_output[0x08] = (unsigned char)ptrOutputState->microphoneLed;

}


