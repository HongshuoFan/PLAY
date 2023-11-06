/*
  ==============================================================================

    DualSense_Input.h
    Created: 3 Nov 2023 2:10:46pm
    Author:  Hongshuo Fan

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "DualSenseState.h"

//==============================================================================
/*
*/
class DualSense_Input  : public juce::Component
{
public:
    DualSense_Input();
    ~DualSense_Input() override;
    
    DualSense::DualSenseInputState DS_input;
    
    void evaluateDualSenseHidInputBuffer(uint8_t* _reportData);
   
    
private:
    int16_t uint16_to_int16(uint16_t a);
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DualSense_Input)
};
