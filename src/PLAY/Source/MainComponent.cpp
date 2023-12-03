#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 400);
    
    // Create HIDmenu compoent and add it to the MainComponent
    m_HIDMenu.reset(new HIDMenu());
    m_HIDMenu->onHIDMenuChanged = [this]{onHIDMenuChanged();};
    addAndMakeVisible(m_HIDMenu.get());
    
    OSC_Sender.reset(new OSC_Sender_UI);
    OSC_Sender->setBounds(0, proportionOfHeight (0.9f), 600, 40);
    
    osc_receiver.reset(new OSC_Receiver);
    osc_receiver->TriggerVibration = [this]{onDataReceived();};
    // Add a listener to the m_HIDMenu
    
    //xbxUI.reset (new XboxController_UI);
}

MainComponent::~MainComponent()
{
    //OSC_Sender->_oscSender.disconnect();
    hidIO_1     = nullptr;
    hidIO_2     = nullptr;
    XC_input  = nullptr;
    m_HIDMenu = nullptr;
    DS_input  = nullptr;
    DS_output = nullptr;
    osc_receiver = nullptr;
    OSC_Sender = nullptr;
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
    if(OSC_Sender){
        OSC_Sender->setBounds(0, proportionOfHeight (0.9f), 600, 40);
    }
    
}

void MainComponent::onHIDMenuChanged()
{
    std::cout << m_HIDMenu->selectedKey << std::endl;
    char* charPointer = new char[m_HIDMenu->selectedKey.length() + 1];
    m_HIDMenu->selectedKey.copyToUTF8(charPointer, m_HIDMenu->selectedKey.length()+1);
    
    
    hidIO_1.reset(new HID_IO());
    hidIO_1->dataReceivedCallback = [this]{onDataReceived();};
    hidIO_1->device_name = charPointer;
    
    if(hidIO_1->connect()){
        
        
        
        if(strcmp("DualSense Wireless Controller", charPointer) == 0){
            
            initialConnection("DualSense Wireless Controller");
            
            // initial duel sense
            DS_input.reset(new DualSense_Input());
            DS_output.reset(new DualSense_Output);
            
            std::this_thread::sleep_for(std::chrono::seconds(1));
            
            DS_output->initialOuput();
            hidIO_1->writeRawData(DS_output->_output, 0x01, 78);
            
            std::this_thread::sleep_for(std::chrono::seconds(1));
            //
            hidIO_1->dataReceivedCallback = [this]{onDualSense_DataReceived();};
            addAndMakeVisible(DS_UI);
            DS_UI.isConnected = true;
            

        }else if(strcmp("Xbox Wireless Controller", charPointer) == 0){
            
            initialConnection("Xbox Wireless Controller");
            
            hidIO_1->dataReceivedCallback = [this]{onXboxController_DataReceived();};
            XC_input.reset(new XboxController_Input());
    
            std::this_thread::sleep_for(std::chrono::seconds(1));
            osc_receiver->TriggerVibration = [this]{EnableXboxControllerVibration();};
            addAndMakeVisible(xbxUI);
            xbxUI.isConnected = true;
            xbxUI.XboxVibration = [this]{EnableXboxControllerVibration();};
            EnableXboxControllerVibration();
            
        }else if(strcmp("Joy-Con (L)", charPointer) == 0 || strcmp("Joy-Con (R)", charPointer) == 0){
            
            initialConnection("Joy-Con");
            
            hidIO_2.reset(new HID_IO());
            
            hidIO_1->dataReceivedCallback = [this]{onJoyCon_L_DataReceived();};
            hidIO_2->dataReceivedCallback = [this]{onJoyCon_R_DataReceived();};
            
        }else{
            std::cout << "connect to unknown Controller" << std::endl;
            WarningWindow("Unsupported device");
            //hidIO_1->dataReceivedCallback = [this]{onDataReceived();};
            
        }
    }
    

};

void MainComponent::initialConnection(juce::String nameOfDevice)
{
    m_HIDMenu->setVisible(false);
    m_HIDMenu = nullptr;
    addAndMakeVisible(OSC_Sender.get());
    std::cout << "connect to " << nameOfDevice << std::endl;
}

void MainComponent::onDataReceived()
{
//        std::cout << std::endl;
    if(hidIO_1->isConneted){
        hidIO_1->printReport();
    }
}

void MainComponent::onDualSense_DataReceived()
{
//    std::cout<<  hidIO.reportData[1] << "\n";
    
    DS_input->evaluateDualSenseHidInputBuffer(hidIO_1->reportData);
    DS_UI.DS_UI_input = DS_input->DS_input;
    OSC_Sender->send_DualSense_OSC_message(DS_input->DS_input);
    //hidIO.printReport();
}

void MainComponent::onXboxController_DataReceived() { 
    XC_input->evaluateXboxCotrollerHidInputBuffer(hidIO_1->reportData);
    xbxUI._input = XC_input->xbox_input;
//    OSC_Sender._xboxInput = XC_input.xbox_input;
    OSC_Sender->send_Xbox_OSC_message(XC_input->xbox_input);
    
}


void MainComponent::onJoyCon_L_DataReceived() {

    
}

void MainComponent::onJoyCon_R_DataReceived() {

    
}

void MainComponent::userTriedToCloseWindow(){
//
    std::cout<<"User Tried To Close Window \n";
    if(DS_UI.isConnected){
        DS_output->disConnectOutput();
        hidIO_1->writeRawData(DS_output->_output, 0xa2, 78);
    }
    
    hidIO_1->stopReadingThread();
    hidIO_1 = nullptr;
    hidIO_2 = nullptr;
    OSC_Sender->disConnect();
}

void MainComponent::EnableXboxControllerVibration(){
    
    if(hidIO_1->isConneted){
        std::cout<<"EnableXboxControllerVibration \n";
        hidIO_1->writeRawData(xbxUI.VibrationData, 0x03, 9);
        
    }
    
}

void MainComponent::WarningWindow(juce::String WarningMessage)
{
    juce::AlertWindow::showMessageBoxAsync (juce::AlertWindow::WarningIcon,
                                            "Error",
                                            WarningMessage,
                                            "OK");
}
