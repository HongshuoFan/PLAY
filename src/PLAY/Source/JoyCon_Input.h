/*
  ==============================================================================

    JoyCon_Input.h
    Created: 3 Dec 2023 10:50:57am
    Author:  Hongshuo Fan

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "JoyConState.h"

//==============================================================================
/*
*/
class JoyCon_Input  : public juce::Component
{
public:
    JoyCon_Input();
    ~JoyCon_Input() override;
    
    JoyCon::L_JoyCon_InputState l_jc_input;
    JoyCon::R_JoyCon_InputState r_jc_input;
    
    void evaluate_L_JC_HidInputBuffer(uint8_t* _reportData);
    void evaluate_R_JC_HidInputBuffer(uint8_t* _reportData);
    

private:
    int16_t uint16_to_int16(uint16_t a);
    
    void CalcAnalogStickSub(JoyCon::AnalogStick* InputStick);
    
    void NormalizVec3(JoyCon::Vec3* InV3, JoyCon::Vec3* v3min, JoyCon::Vec3* v3max);
    
    float clamp(float a, float min, float max);
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JoyCon_Input)
};
