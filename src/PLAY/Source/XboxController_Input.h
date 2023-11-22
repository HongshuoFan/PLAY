/*
  ==============================================================================

    XboxController_Input.h
    Created: 7 Nov 2023 9:40:44am
    Author:  Hongshuo Fan

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "XboxControllerState.h"
//==============================================================================
/*
*/
class XboxController_Input  : public juce::Component
{
public:
    XboxController_Input();
    ~XboxController_Input() override;
    
    XboxCotroller::XboxCotrollerInputState xbox_input;
    void evaluateXboxCotrollerHidInputBuffer(uint8_t* _reportData);
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (XboxController_Input)
};
