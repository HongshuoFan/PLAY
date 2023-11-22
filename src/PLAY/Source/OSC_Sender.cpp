/*
  ==============================================================================

    OSC_Sender.cpp
    Created: 22 Nov 2023 11:42:12am
    Author:  Hongshuo Fan

  ==============================================================================
*/

#include <JuceHeader.h>
#include "OSC_Sender.h"

//==============================================================================
OSC_Sender::OSC_Sender()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

OSC_Sender::~OSC_Sender()
{
}

void OSC_Sender::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
    g.drawText ("OSC_Sender", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text
}

void OSC_Sender::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
