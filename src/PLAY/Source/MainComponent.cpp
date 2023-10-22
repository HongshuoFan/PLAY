#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 400);
    
    // Create HIDmenu compoent and add it to the MainComponent
    addAndMakeVisible(m_HIDMenu);
    // Add a listener to the m_HIDMenu
    m_HIDMenu.onHIDMenuChanged = [this]{onHIDMenuChanged();};
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

//    g.setFont (juce::Font (16.0f));
//    g.setColour (juce::Colours::white);
//    g.drawText ("Hello World!", getLocalBounds(), juce::Justification::centred, true);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}

void MainComponent::onHIDMenuChanged()
{
    std::cout << m_HIDMenu.selectedKey << std::endl;
    char* charPointer = new char[m_HIDMenu.selectedKey.length() + 1];
    m_HIDMenu.selectedKey.copyToUTF8(charPointer, m_HIDMenu.selectedKey.length()+1);
    hidIO.device_name = charPointer;
    
    if(hidIO.connect()){
        std::cout << "connect success" << std::endl;
    }
   
};

void MainComponent::onDataReceived(const std::vector<unsigned char>& data)
{
    for (unsigned char byte : data) {
            std::cout << std::hex << (int)byte << " ";
        }
        std::cout << std::endl;
}
