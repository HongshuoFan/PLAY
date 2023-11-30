#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 400);
    
    // Create HIDmenu compoent and add it to the MainComponent
    m_HIDMenu.reset(new HIDMenu());
    addAndMakeVisible(m_HIDMenu.get());
    
    OSC_Sender.setBounds(0, proportionOfHeight (0.9f), 600, 40);
    addAndMakeVisible(OSC_Sender);
    
    // Add a listener to the m_HIDMenu
    m_HIDMenu->onHIDMenuChanged = [this]{onHIDMenuChanged();};
    hidIO.dataReceivedCallback = [this]{onDataReceived();};
    
    //xbxUI.reset (new XboxController_UI);
}

MainComponent::~MainComponent()
{
    OSC_Sender._oscSender.disconnect();
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
    OSC_Sender.setBounds(0, proportionOfHeight (0.9f), 600, 40);
}

void MainComponent::onHIDMenuChanged()
{
    std::cout << m_HIDMenu->selectedKey << std::endl;
    char* charPointer = new char[m_HIDMenu->selectedKey.length() + 1];
    m_HIDMenu->selectedKey.copyToUTF8(charPointer, m_HIDMenu->selectedKey.length()+1);
    
    hidIO.device_name = charPointer;
    
    if(hidIO.connect()){
        
        m_HIDMenu->setVisible(false);
        m_HIDMenu = nullptr;
        
        if(strcmp("DualSense Wireless Controller", hidIO.device_name) == 0){
            std::cout << "connect to DualSense Wireless Controller" << std::endl;
            
            
            std::this_thread::sleep_for(std::chrono::seconds(1));
            
            // initial duel sense
            DS_output.initialOuput();
            hidIO.writeRawData(DS_output._output, 0x01, 78);
            
            std::this_thread::sleep_for(std::chrono::seconds(1));
            
            hidIO.dataReceivedCallback = [this]{onDualSense_DataReceived();};
            addAndMakeVisible(DS_UI);
            DS_UI.isConnected = true;
            //DS_output.createDualSenseOutput();
            //hidIO.writeRawData(DS_output.DS_output, 0x01);
            
        }else if(strcmp("Xbox Wireless Controller", hidIO.device_name) == 0){
            std::cout << "connect to Xbox Wireless Controller" << std::endl;
            hidIO.dataReceivedCallback = [this]{onXboxController_DataReceived();};
            
           
            addAndMakeVisible(xbxUI);
            xbxUI.isConnected = true;
            xbxUI.XboxVibration = [this]{EnableXboxControllerVibration();};
            
            osc_receiver.TriggerVibration = [this]{EnableXboxControllerVibration();};
            std::this_thread::sleep_for(std::chrono::seconds(1));
//
            EnableXboxControllerVibration();
        }else{
            std::cout << "connect to unknown Controller" << std::endl;
            hidIO.dataReceivedCallback = [this]{onDataReceived();};
            
        }
    }
    

};

void MainComponent::onDataReceived()
{
//        std::cout << std::endl;
    if(hidIO.isConneted){
        //hidIO.printReport();
    }
}

void MainComponent::onDualSense_DataReceived()
{
//    std::cout<<  hidIO.reportData[1] << "\n";
    
    DS_input.evaluateDualSenseHidInputBuffer(hidIO.reportData);
    DS_UI.DS_UI_input = DS_input.DS_input;
    //hidIO.printReport();
}

void MainComponent::onXboxController_DataReceived() { 
    XC_input.evaluateXboxCotrollerHidInputBuffer(hidIO.reportData);
    xbxUI._input = XC_input.xbox_input;
//    OSC_Sender._xboxInput = XC_input.xbox_input;
    OSC_Sender.send_Xbox_OSC_message(XC_input.xbox_input);
    
}

void MainComponent::userTriedToCloseWindow(){
//
    std::cout<<"User Tried To Close Window \n";
    if(DS_UI.isConnected){
        DS_output.disConnectOutput();
        hidIO.writeRawData(DS_output._output, 0xa2, 78);
    }
    hidIO.stopReadingThread();
    OSC_Sender.disConnect();
}

void MainComponent::EnableXboxControllerVibration(){
    
    if(hidIO.isConneted){
        std::cout<<"EnableXboxControllerVibration \n";
        hidIO.writeRawData(xbxUI.VibrationData, 0x03, 9);
        
    }
    
}
