/*
  ==============================================================================

    AccessController_Input.h
    Created: 26 May 2024 7:06:01pm
    Author:  Hongshuo Fan

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "AccessController_State.h"

//==============================================================================
/*
*/
class AccessController_Input  : public juce::Component
{
public:
    AccessController_Input();
    ~AccessController_Input() override;
    AccessController::AccessControllerInputStates ac_input;
    bool usbOrBT;
    void evaluateAccessControllerHidInputBuffer(uint8_t* _reportData, bool enableIMU);
  

private:

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AccessController_Input)
};
