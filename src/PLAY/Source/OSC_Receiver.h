/*
  ==============================================================================

    OSC_Receiver.h
    Created: 25 Nov 2023 9:37:09pm
    Author:  Hongshuo Fan

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class OSC_Receiver  : public juce::Component,
                      private juce::OSCReceiver,
                      private juce::OSCReceiver::ListenerWithOSCAddress<juce::OSCReceiver::MessageLoopCallback>
{
public:
    OSC_Receiver();
    ~OSC_Receiver() override;
    int port = 1111;
    
    juce::String vib_address = "/vibration";
   

private:
    void oscMessageReceived (const OSCMessage& message) override;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OSC_Receiver)
};
