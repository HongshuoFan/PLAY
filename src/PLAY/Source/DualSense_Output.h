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
//==============================================================================
/*
*/
class DualSense_Output  : public juce::Component
{
public:
    DualSense_Output();
    ~DualSense_Output() override;
    
    //DualSense::DualSenseOutputState DS_output;
    uint8_t DS_output[50];
    void createDualSenseOutput();

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DualSense_Output)
};
