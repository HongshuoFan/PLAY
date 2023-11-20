#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 400);
    
    // Create HIDmenu compoent and add it to the MainComponent
    addAndMakeVisible(m_HIDMenu);
    
    
    // Add a listener to the m_HIDMenu
    m_HIDMenu.onHIDMenuChanged = [this]{onHIDMenuChanged();};
    hidIO.dataReceivedCallback = [this]{onDataReceived();};
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
        
        m_HIDMenu.setVisible(false);
        
        if(strcmp("DualSense Wireless Controller", hidIO.device_name) == 0){
            std::cout << "connect to DualSense Wireless Controller" << std::endl;
            hidIO.dataReceivedCallback = [this]{onDualSense_DataReceived();};
            
//            DS_output.createDualSenseOutput();
//            hidIO.writeRawData(DS_output.DS_output, 0x01);
            
        }else if(strcmp("Xbox Wireless Controller", hidIO.device_name) == 0){
            std::cout << "connect to Xbox Wireless Controller" << std::endl;
            hidIO.dataReceivedCallback = [this]{onXboxController_DataReceived();};
            addAndMakeVisible(xbxUI);
        }
    }
    

};

void MainComponent::onDataReceived()
{
//        std::cout << std::endl;
}

void MainComponent::onDualSense_DataReceived()
{
//    std::cout<<  hidIO.reportData[1] << "\n";
    DS_input.evaluateDualSenseHidInputBuffer(hidIO.reportData);
    
}

void MainComponent::onXboxController_DataReceived() { 
    XC_input.evaluateXboxCotrollerHidInputBuffer(hidIO.reportData);
    xbxUI._input = XC_input.XC_input;
    xbxUI.isConnected = true;
    xbxUI.update();
}

