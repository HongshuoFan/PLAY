/*
  ==============================================================================

    OSC_Receiver.cpp
    Created: 25 Nov 2023 10:11:55pm
    Author:  Hongshuo Fan

  ==============================================================================
*/

#include <JuceHeader.h>
#include "OSC_Receiver.h"

//==============================================================================
OSC_Receiver::OSC_Receiver()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    // specify here on which UDP port number to receive incoming OSC messages
    if (! connect (port))                       // [3]
            showConnectionErrorMessage ("Error: could not connect to UDP port 9001.");
    // tell the component to listen for OSC messages matching this address:
    addListener (this, vib_address);     // [4]
}

OSC_Receiver::~OSC_Receiver()
{
    disconnect();
}


void OSC_Receiver::oscMessageReceived (const juce::OSCMessage& message)
{
    if (message.size() >= 1)
    {
        TriggerVibration();
    }
}

void OSC_Receiver::showConnectionErrorMessage (const juce::String& messageText)
{
    juce::AlertWindow::showMessageBoxAsync (juce::AlertWindow::WarningIcon,
                                            "Connection error",
                                            messageText,
                                            "OK");
}
