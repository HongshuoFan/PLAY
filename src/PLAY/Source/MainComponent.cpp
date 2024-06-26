#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    //initialize();
    setSize (700, 500);
    
    // Create HIDmenu compoent and add it to the MainComponent
    m_HIDMenu.reset(new HIDMenu());
    m_HIDMenu->onHIDMenuChanged = [this]{onHIDMenuChanged();};
    addAndMakeVisible(m_HIDMenu.get());
    
    osc_sender.reset(new OSC_Sender_UI);
    osc_sender->setBounds(10, proportionOfHeight (0.9f), 600, 40);
    
    osc_receiver.reset(new OSC_Receiver);
    osc_receiver->TriggerVibration = [this]{onDataReceived();};
    
    midi_sender.reset(new MIDI_Sender_UI);
    midi_sender->setBounds(10, proportionOfHeight (0.8f), 600, 40);
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
    if (getWidth() < 600 || getHeight() < 500){
        setSize(700, 500);
    }
    
    int controllerUI_Height = floor(getWidth())*0.55;
    
    if (controllerUI_Height > proportionOfWidth(0.8)){
        
        controllerUI_Height = proportionOfWidth(0.8);
        
    }
   
    if (m_HIDMenu){
        m_HIDMenu->setBounds(10, proportionOfHeight (0.f), proportionOfWidth(1.f), proportionOfHeight(0.5f));
    }
    if(osc_sender){
        osc_sender->setBounds(10, proportionOfHeight (0.9f), 600, 40);
    }
    if(midi_sender){
        midi_sender->setBounds(10, proportionOfHeight (0.8f), 600, 40);
    }
    if(AC_UI.isConnected){
        AC_UI.setBounds(1, proportionOfHeight (0.f), proportionOfWidth(1.f), controllerUI_Height);
    }
    if(DS_UI.isConnected){
        DS_UI.setBounds(1, proportionOfHeight (0.f), proportionOfWidth(1.f), controllerUI_Height);
    }
    if(xbxUI.isConnected){
        xbxUI.setBounds(1, proportionOfHeight (0.f), proportionOfWidth(1.f), controllerUI_Height);
    }
    if(JC_UI.isConnected){
        JC_UI.setBounds(1, proportionOfHeight (0.f), proportionOfWidth(1.f), controllerUI_Height);
    }
}

void MainComponent::onHIDMenuChanged()
{
    //on HID menu changed copy the selected key to a char pointer
    std::cout << m_HIDMenu->selectedKey << std::endl;
    char* charPointer = new char[m_HIDMenu->selectedKey.length() + 1];
    m_HIDMenu->selectedKey.copyToUTF8(charPointer, m_HIDMenu->selectedKey.length()+1);
        
    //handle different controller
    if(strcmp("DualSense Wireless Controller", charPointer) == 0){
            
        initialConnection("DualSense Wireless Controller");
        hidIO_1->device_name = charPointer;
        if(hidIO_1->connect()){
            // initial duel sense
            DS_input.reset(new DualSense_Input());
            DS_output.reset(new DualSense_Output);
            
            std::this_thread::sleep_for(std::chrono::seconds(1));
            // add callback function and start reading thread
            hidIO_1->dataReceivedCallback = [this]{onDualSense_DataReceived();};
            DS_UI.UpdateTriggerForce = [this]{update_DualSense_TriggerForce();};
            DS_UI.UpdateVibration = [this]{update_DualSense_Vibration();};
            DS_UI.changeDevice = [this]{changeDevice();};
            std::this_thread::sleep_for(std::chrono::seconds(1));

            // enable dual sense controller
            DS_output->initialOuput(DS_input->usbOrBT);
            hidIO_1->writeRawData(DS_output->_output, 0x01, 78);
                        
            addAndMakeVisible(DS_UI);
            DS_UI.isConnected = true;

        }else{
            WarningWindow("Unable to connect DualSense Wireless Controller");
        }
        
    }else if(strcmp("Xbox Wireless Controller", charPointer) == 0){
            
        initialConnection("Xbox Wireless Controller");
        hidIO_1->device_name = charPointer;
        
        if(hidIO_1->connect()){
            //enable xbox controller
            XC_input.reset(new XboxController_Input());
            hidIO_1->dataReceivedCallback = [this]{onXboxController_DataReceived();};
            
            std::this_thread::sleep_for(std::chrono::seconds(1));
            //add callback function and start reading thread
            osc_receiver->TriggerVibration = [this]{EnableXboxControllerVibration();};
            xbxUI.isConnected = true;
            xbxUI.XboxVibration = [this]{EnableXboxControllerVibration();};
            xbxUI.changeDevice = [this]{changeDevice();};
            //enable the UI
            addAndMakeVisible(xbxUI);
            EnableXboxControllerVibration();
        }else{
            WarningWindow("Unable to connect Xbox Wireless Controller");
        }
            
        }else if(strcmp(L_JoyConName.toUTF8(), charPointer) == 0 || strcmp(R_JoyConName.toUTF8(), charPointer) == 0){
            int JC_connected = 0;
            for (const auto& entry : m_HIDMenu->devicesMap) {
                juce::String key = entry.first;
                
                if(L_JoyConName == key){
                    JC_connected += 1;
                }else if(R_JoyConName == key){
                    JC_connected += 1;
                }
                
            }
            
            if(JC_connected == 2){
                
                initialConnection("Joy-Con");
                hidIO_1->device_name = (char*) "Joy-Con (L)";
                // initialize second hidIO
                hidIO_2.reset(new HID_IO());
                hidIO_2->device_name = (char*) "Joy-Con (R)";
                hidIO_2->dataReceivedCallback = [this]{onDataReceived();};
                
                JC_input.reset(new JoyCon_Input());
                JC_output.reset(new JoyCon_Output());
                
                if(hidIO_1->connect() && hidIO_2->connect()){
                    
                    JC_output->changeMode(0x31);
                    hidIO_1->writeRawData(JC_output->_output, 0x01, 12);
                    hidIO_2->writeRawData(JC_output->_output, 0x01, 12);
                    
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    
                    JC_UI.onLeftIMUChanged = [this]{Left_JC_IMU();};
                    JC_UI.onRightIMUChanged = [this]{Right_JC_IMU();};
                    
                    JC_UI.onLeftVibration = [this]{Left_JC_Vib();};
                    JC_UI.onRightVibration = [this]{Right_JC_Vib();};
                    JC_UI.changeDevice = [this]{changeDevice();};
                    
                    hidIO_1->dataReceivedCallback = [this]{onJoyCon_L_DataReceived();};
                    hidIO_2->dataReceivedCallback = [this]{onJoyCon_R_DataReceived();};
                    
                    JC_UI.isConnected = true;
                    addAndMakeVisible(JC_UI);
                    
                }else{
                    WarningWindow("Unable to connect Joy-Con");
                    
                    m_HIDMenu.reset(new HIDMenu());
                    m_HIDMenu->onHIDMenuChanged = [this]{onHIDMenuChanged();};
                    addAndMakeVisible(m_HIDMenu.get());
                }
                
            }else{
                
                WarningWindow("Make sure connecting both Joy-Con");
                
            }
            
        }else if(strcmp("Access Controller", charPointer) == 0){
            initialConnection("Access Controller");
            hidIO_1->device_name = charPointer;
            if(hidIO_1->connect()){
                
                // initial duel sense
                AC_input.reset(new AccessController_Input());
                DS_output.reset(new DualSense_Output);
                
                std::this_thread::sleep_for(std::chrono::seconds(1));
                // add callback function and start reading thread
                hidIO_1->dataReceivedCallback = [this]{onAccessController_DataReceived();};
//                DS_UI.UpdateTriggerForce = [this]{update_DualSense_TriggerForce();};
//                DS_UI.UpdateVibration = [this]{update_DualSense_Vibration();};
                AC_UI.changeDevice = [this]{changeDevice();};
                std::this_thread::sleep_for(std::chrono::seconds(1));

                // enable dual sense controller
                DS_output->initialOuput(AC_input->usbOrBT);
                hidIO_1->writeRawData(DS_output->_output, 0x01, 78);
                            
                addAndMakeVisible(AC_UI);
                AC_UI.isConnected = true;
                
            }
                
            
        }else{
            if(isChangeDevice){
                
            }else{
                std::cout << "connect to unknown Controller" << std::endl;
                WarningWindow("Unsupported device");
            }
            
            
        }

};

void MainComponent::initialConnection(juce::String nameOfDevice)
{
    //initialize hidIO
    hidIO_1.reset(new HID_IO());
    hidIO_1->dataReceivedCallback = [this]{onDataReceived();};
    //kill the HIDMenu
    m_HIDMenu->setVisible(false);
    //m_HIDMenu = nullptr;
    //add OSC_SenderUI
    addAndMakeVisible(osc_sender.get());
    //add MIDI_SenderUI
    addAndMakeVisible(midi_sender.get());
    std::cout << "connect to " << nameOfDevice << std::endl;
    isChangeDevice = false;
}

void MainComponent::onDataReceived()
{
//    debug and placeholder function
    if(hidIO_1->isConneted){
//        hidIO_1->printReport();
    }else{
        std::cout << "unable to connect to "<< hidIO_1->device_name << std::endl;
    }
}

void MainComponent::onDualSense_DataReceived()
{
    if(hidIO_1){
        //handle the DualSense input data
        DS_input->evaluateDualSenseHidInputBuffer(hidIO_1->reportData, DS_UI.enableIMU);
        DS_UI.DS_UI_input = DS_input->ds_input;
        
        //send DualSense data via OSC
        osc_sender->send_DualSense_OSC_message(DS_UI.DS_UI_input, DS_UI.DS_EnableStats);
        
        //send DualSense Controller data via MIDI
        midi_sender->send_DualSense_MIDI_message(DS_UI.DS_UI_input, DS_UI.DS_EnableStats);

    }
}

void MainComponent::onAccessController_DataReceived()
{
    if(hidIO_1){
        //handle the DualSense input data
        AC_input->evaluateAccessControllerHidInputBuffer(hidIO_1->reportData, DS_UI.enableIMU);
        AC_UI.AC_input = AC_input->ac_input;
        
        //send Access controller data via OSC
        osc_sender->send_AccessController_OSC_message(AC_UI.AC_input, AC_UI.AC_EnableStats);

        //send DualSense Controller data via MIDI
        midi_sender->send_AccessController_MIDI_message(AC_UI.AC_input, AC_UI.AC_EnableStats);
//        hidIO_1->printReport();
    }
}


void MainComponent::onXboxController_DataReceived() {
    //handle the Xbox Controller input data 
    XC_input->evaluateXboxCotrollerHidInputBuffer(hidIO_1->reportData);
    xbxUI._input = XC_input->xbox_input;
    //send Xbox Controller data via OSC
    osc_sender->send_Xbox_OSC_message(xbxUI._input, xbxUI.xbox_enableStates);
    //send Xbox Controller data via MIDI
    midi_sender->send_Xbox_MIDI_message(xbxUI._input, xbxUI.xbox_enableStates);
}


void MainComponent::onJoyCon_L_DataReceived() 
{
    //hidIO_1->printReport();
    if(hidIO_1)
    {
        JC_input->evaluate_L_JC_HidInputBuffer(hidIO_1->reportData);
        JC_UI.l_jc_input = JC_input->l_jc_input;
        osc_sender->send_L_JoyCon_OSC_message(JC_input->l_jc_input, JC_UI.left_EnableStates);
        midi_sender->send_L_JoyCon_MIDI_message(JC_input->l_jc_input, JC_UI.left_EnableStates);
    }
    
}

void MainComponent::onJoyCon_R_DataReceived()
{
    //hidIO_2->printReport();
    if(hidIO_2)
    {
        JC_input->evaluate_R_JC_HidInputBuffer(hidIO_2->reportData);
        JC_UI.r_jc_input = JC_input->r_jc_input;
        osc_sender->send_R_JoyCon_OSC_message(JC_input->r_jc_input, JC_UI.right_EnableStates);
        midi_sender->send_R_JoyCon_MIDI_message(JC_input->r_jc_input, JC_UI.right_EnableStates);
    }
}

void MainComponent::userTriedToCloseWindow()
{
    //if the user tried to close the window
    std::cout<<"User Tried To Close Window \n";

    if(DS_UI.isConnected){
        DS_UI.setVisible(false);
        DS_UI.isConnected = false;
        //disable dual sense controller
        DS_output->disConnectOutput();
        hidIO_1->writeRawData(DS_output->_output, 0xa2, 78);
    }
    
    if(JC_UI.isConnected){
        JC_UI.setVisible(false);
        JC_UI.isConnected = false;
        //disable dual sense controller
        JC_output->trunIMU(false);
        hidIO_1->writeRawData(JC_output->_output, 0x01, 12);
        hidIO_2->writeRawData(JC_output->_output, 0x01, 12);
        // JC_output->changeMode(0x3F);
        // hidIO_1->writeRawData(JC_output->_output, 0x01, 12);
        // hidIO_2->writeRawData(JC_output->_output, 0x01, 12);
    }
    
    if(xbxUI.isConnected){
        xbxUI.setVisible(false);
        xbxUI.isConnected = false;
    }
    
    if(AC_UI.isConnected){
        AC_UI.setVisible(false);
        AC_UI.isConnected = false;
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
    if(osc_sender)
    {
        osc_sender->disConnect();
        osc_sender->setVisible(false);
    }
    //disconnect MIDI
    if(midi_sender)
    {
        midi_sender->closeConnection();
        midi_sender->setVisible(false);
    }
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

void MainComponent::Left_JC_IMU()
{
    JC_output->trunIMU(JC_UI.left_imu);
    hidIO_1->writeRawData(JC_output->_output, 0x01, 12);
}

void MainComponent::Right_JC_IMU()
{
    JC_output->trunIMU(JC_UI.right_imu);
    hidIO_2->writeRawData(JC_output->_output, 0x01, 12);
}

void MainComponent::Left_JC_Vib(){
    JC_output->vibration(true, 0.5, true);
    hidIO_1->writeRawData(JC_output->_output, 0x01, 12);
    JC_output->rumbleSend(200, 0.2, 50, 0.0, true);
    hidIO_1->writeRawData(JC_output->_output, 0x10, 12);
    
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    
//    JC_output->vibration(false, 0.5, true);
//    hidIO_1->writeRawData(JC_output->_output, 0x01, 12);
}

void MainComponent::Right_JC_Vib(){
    JC_output->vibration(true, 0.5, false);
    hidIO_2->writeRawData(JC_output->_output, 0x01, 12);
    JC_output->rumbleSend(200, 0.2, 50, 0.0, false);
    hidIO_2->writeRawData(JC_output->_output, 0x10, 12);
}

void MainComponent::update_DualSense_TriggerForce()
{
    DS_output->usbOrBT = DS_input->usbOrBT;
    DS_output->updateTrigger(DS_UI.triggerForce);
    hidIO_1->writeRawData(DS_output->_output, 0x01, 78);

}

void MainComponent::update_DualSense_Vibration()
{
    DS_output->usbOrBT = DS_input->usbOrBT;
    DS_output->rumble(DS_UI.virbration ? 0.1 : 0.);
    hidIO_1->writeRawData(DS_output->_output, 0x01, 78);
}

void MainComponent::changeDevice()
{
    isChangeDevice = true;
    userTriedToCloseWindow();
    m_HIDMenu->ClickRefresh__textButton();
    m_HIDMenu->setVisible(true);
}


