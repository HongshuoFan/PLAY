/*
  ==============================================================================

    JoyCon_Input.cpp
    Created: 3 Dec 2023 10:50:57am
    Author:  Hongshuo Fan

  ==============================================================================
*/

#include <JuceHeader.h>
#include "JoyCon_Input.h"

//==============================================================================
JoyCon_Input::JoyCon_Input()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

JoyCon_Input::~JoyCon_Input()
{
}

int16_t JoyCon_Input::uint16_to_int16(uint16_t a)
{
    int16_t b;
    char* aPointer = (char*)&a, *bPointer = (char*)&b;
    memcpy(bPointer, aPointer, sizeof(a));
    return b;
}

void JoyCon_Input::evaluate_L_JC_HidInputBuffer(uint8_t* _reportData)
{
    
}

void JoyCon_Input::evaluate_R_JC_HidInputBuffer(uint8_t* _reportData)
{
    
}
