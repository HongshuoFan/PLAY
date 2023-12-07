#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    //initialize();
    setSize (600, 400);
    
    // Create HIDmenu compoent and add it to the MainComponent
    m_HIDMenu.reset(new HIDMenu());
    m_HIDMenu->onHIDMenuChanged = [this]{onHIDMenuChanged();};
    addAndMakeVisible(m_HIDMenu.get());
    
    osc_sender.reset(new OSC_Sender_UI);
    osc_sender->setBounds(0, proportionOfHeight (0.9f), 600, 40);
    
    osc_receiver.reset(new OSC_Receiver);
    osc_receiver->TriggerVibration = [this]{onDataReceived();};
    // Add a listener to the m_HIDMenu
    
    //xbxUI.reset (new XboxController_UI);
}

MainComponent::~MainComponent()
{
    //OSC_Sender->_oscSender.disconnect();
    //kill all the components 
    hidIO_1     = nullptr;
    hidIO_2     = nullptr;
    XC_input  = nullptr;
    m_HIDMenu = nullptr;
    DS_input  = nullptr;
    DS_output = nullptr;
    osc_receiver = nullptr;
    osc_sender = nullptr;
    JC_output = nullptr;
    JC_input = nullptr;

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
    if(osc_sender){
        osc_sender->setBounds(0, proportionOfHeight (0.9f), 600, 40);
    }
    
}

void MainComponent::onHIDMenuChanged()
{
    //on HID menu changed copy the selected key to a char pointer
    std::cout << m_HIDMenu->selectedKey << std::endl;
    char* charPointer = new char[m_HIDMenu->selectedKey.length() + 1];
    m_HIDMenu->selectedKey.copyToUTF8(charPointer, m_HIDMenu->selectedKey.length()+1);
    
    //initialize hidIO
    hidIO_1.reset(new HID_IO());
    hidIO_1->dataReceivedCallback = [this]{onDataReceived();};
    hidIO_1->device_name = charPointer;
    
    if(hidIO_1->connect()){
        
        
        //handle different controller
        if(strcmp("DualSense Wireless Controller", charPointer) == 0){
            
            initialConnection("DualSense Wireless Controller");
            
            // initial duel sense
            DS_input.reset(new DualSense_Input());
            DS_output.reset(new DualSense_Output);
            
            std::this_thread::sleep_for(std::chrono::seconds(1));
            // enable dual sense controller
            DS_output->initialOuput();
            hidIO_1->writeRawData(DS_output->_output, 0x01, 78);
            
            std::this_thread::sleep_for(std::chrono::seconds(1));
            // add callback function and start reading thread
            hidIO_1->dataReceivedCallback = [this]{onDualSense_DataReceived();};
            addAndMakeVisible(DS_UI);
            DS_UI.isConnected = true;
            

        }else if(strcmp("Xbox Wireless Controller", charPointer) == 0){
            
            initialConnection("Xbox Wireless Controller");
            
            //enable xbox controller
            XC_input.reset(new XboxController_Input());
            hidIO_1->dataReceivedCallback = [this]{onXboxController_DataReceived();};

            std::this_thread::sleep_for(std::chrono::seconds(1));
            //add callback function and start reading thread
            osc_receiver->TriggerVibration = [this]{EnableXboxControllerVibration();};
            xbxUI.isConnected = true;
            xbxUI.XboxVibration = [this]{EnableXboxControllerVibration();};
            //enable the UI
            addAndMakeVisible(xbxUI);
            EnableXboxControllerVibration();
            
        }else if(strcmp("Joy-Con (L)", charPointer) == 0 || strcmp("Joy-Con (R)", charPointer) == 0){
            
            initialConnection("Joy-Con");
            
            
//            hidIO_1->device_name = (char*)"Joy-Con (L)";
            
//            std::this_thread::sleep_for(std::chrono::seconds(1));
            hidIO_2.reset(new HID_IO());
            hidIO_2->device_name = (char*) "Joy-Con (R)";
            
            JC_input.reset(new JoyCon_Input());
            JC_output.reset(new JoyCon_Output());
            JC_output->changeMode(0x31);
            hidIO_1->writeRawData(JC_output->_output, 0x01, 12);
            
            std::this_thread::sleep_for(std::chrono::seconds(1));
            JC_output->trunIMU(true);
            hidIO_1->writeRawData(JC_output->_output, 0x01, 12);
            
            hidIO_1->dataReceivedCallback = [this]{onJoyCon_L_DataReceived();};
            
            if(hidIO_2->connect()){
                hidIO_2->dataReceivedCallback = [this]{onJoyCon_R_DataReceived();};
               
                //JC_output->Vibration(200, 0.5, 100, 0.2, false);
               
                JC_output->changeMode(0x31);
                hidIO_2->writeRawData(JC_output->_output, 0x01, 12);
                
                std::this_thread::sleep_for(std::chrono::seconds(1));
                
                JC_output->trunIMU(true);
                hidIO_2->writeRawData(JC_output->_output, 0x01, 12);
//                JC_output->enableMCU();
//                hidIO_2->writeRawData(JC_output->_output, 0x01, 12);
//                std::this_thread::sleep_for(std::chrono::seconds(1));
//                JC_output->setMCUMode();
//                hidIO_2->writeRawData(JC_output->_output, 0x01, 49);
               
            }
            
            addAndMakeVisible(JC_UI);
            
        }else{
            std::cout << "connect to unknown Controller" << std::endl;
            WarningWindow("Unsupported device");
            
        }
    }
    

};

void MainComponent::initialConnection(juce::String nameOfDevice)
{   
    //initial Connection, kill the HIDMenu
    m_HIDMenu->setVisible(false);
    m_HIDMenu = nullptr;
    //add OSC_SenderUI
    addAndMakeVisible(osc_sender.get());
    std::cout << "connect to " << nameOfDevice << std::endl;
}

void MainComponent::onDataReceived()
{
    //debug and placeholder function
    if(hidIO_1->isConneted){
        //hidIO_1->printReport();
    }
}

void MainComponent::onDualSense_DataReceived()
{
    //handle the DualSense input data
    DS_input->evaluateDualSenseHidInputBuffer(hidIO_1->reportData);
    DS_UI.DS_UI_input = DS_input->DS_input;
    //send DualSense data via OSC
    osc_sender->send_DualSense_OSC_message(DS_input->DS_input);
   
}

void MainComponent::onXboxController_DataReceived() {
    //handle the Xbox Controller input data 
    XC_input->evaluateXboxCotrollerHidInputBuffer(hidIO_1->reportData);
    xbxUI._input = XC_input->xbox_input;
    //send Xbox Controller data via OSC
    osc_sender->send_Xbox_OSC_message(XC_input->xbox_input);
    
}


void MainComponent::onJoyCon_L_DataReceived() 
{
    //hidIO_1->printReport();
    
    JC_input->evaluate_L_JC_HidInputBuffer(hidIO_1->reportData);
    
}

void MainComponent::onJoyCon_R_DataReceived()
{
    //hidIO_2->printReport();
    
    //hidIO_2->printReport();
    
    JC_input->evaluate_R_JC_HidInputBuffer(hidIO_2->reportData);
    
}

void MainComponent::userTriedToCloseWindow()
{
    //if the user tried to close the window
    std::cout<<"User Tried To Close Window \n";

    if(DS_UI.isConnected){
        //disable dual sense controller
        DS_output->disConnectOutput();
        hidIO_1->writeRawData(DS_output->_output, 0xa2, 78);
    }
    //kill hidIO threads
    if(hidIO_1){
        hidIO_1->stopReadingThread();
        hidIO_1 = nullptr;
    }
    if(hidIO_2){
        hidIO_2->stopReadingThread();
        hidIO_2 = nullptr;
    }
    //disconnect OSC
    osc_sender->disConnect();
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
