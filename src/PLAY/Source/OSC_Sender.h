/*
  ==============================================================================

    OSC_Sender.h
    Created: 22 Nov 2023 11:42:12am
    Author:  Hongshuo Fan

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class OSC_Sender  : public juce::Component
{
public:
    OSC_Sender();
    ~OSC_Sender() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OSC_Sender)
};
