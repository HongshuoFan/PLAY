#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 400);
    
    // Create HIDmenu compoent and add it to the MainComponent
    addAndMakeVisible(m_HIDMenu);
    OSC_Sender.setBounds(0, proportionOfHeight (0.9f), 600, 40);
    addAndMakeVisible(OSC_Sender);
    
    // Add a listener to the m_HIDMenu
    m_HIDMenu.onHIDMenuChanged = [this]{onHIDMenuChanged();};
    hidIO.dataReceivedCallback = [this]{onDataReceived();};
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
    std::cout << m_HIDMenu.selectedKey << std::endl;
    char* charPointer = new char[m_HIDMenu.selectedKey.length() + 1];
    m_HIDMenu.selectedKey.copyToUTF8(charPointer, m_HIDMenu.selectedKey.length()+1);
    
    hidIO.device_name = charPointer;
    
    if(hidIO.connect()){
        
        m_HIDMenu.setVisible(false);
        
        if(strcmp("DualSense Wireless Controller", hidIO.device_name) == 0){
            std::cout << "connect to DualSense Wireless Controller" << std::endl;
            
            
            std::this_thread::sleep_for(std::chrono::seconds(1));
            
            uint8_t bufWrite[78];
                bufWrite[0] = 0x31;
                bufWrite[1] = 0x02;
                bufWrite[2] = 0x03; // 0xff, 0x03 rumble??
            
                bufWrite[3] = 0x54;// 0xff disable all LEDs - top LED, bottom LED, Mic LED (this just if bufWrite[63] == 0x02)// 0xf3 disable top LED// 0xf4 enable all LEDs - top LED, bottom LED, Mic LED (this just if buf[63] == 0x02)
            // Right motor power
                //bufWrite[4] = 0x20;  // Right motor power
//                bufWrite[5] = 0x85;  // Left motor power
                //bufWrite[10] = 0x00;  // off Mic LED (if buf[2] == f7)
//                /* ... */
//                bufWrite[44] = 0xc1; // LEDs from left to right -> 0xc1 0xa2 0xc4 0xc8 0xd0// 0x00 all OFF, 0xff all ON
//                bufWrite[45] =  0x80; // R
//                bufWrite[46] =  0x80; // G
//                bufWrite[47] = 0x80; // B
//                /* ... */
//                bufWrite[63] = 0x02; // Short Blink bottom led
//                /* ... */
               
//                bufWrite[66] = 0x02; // If both are set to 0xff it will turn OFF Motors and LEDs
//                bufWrite[67] = 0x02; // else if both are set 0x02 it will turn ON Motors and LEDs
           
            
            uint32_t crc_Data = ds_crc32.compute(bufWrite, 74);
            bufWrite[0x4A] = (unsigned char)((crc_Data & 0x000000FF) >> 0UL);
            bufWrite[0x4B] = (unsigned char)((crc_Data & 0x0000FF00) >> 8UL);
            bufWrite[0x4C] = (unsigned char)((crc_Data & 0x00FF0000) >> 16UL);
            bufWrite[0x4D] = (unsigned char)((crc_Data & 0xFF000000) >> 24UL);
            
            hidIO.writeRawData(bufWrite, 0xa2, 78);
            
            std::this_thread::sleep_for(std::chrono::seconds(1));
            
            hidIO.dataReceivedCallback = [this]{onDualSense_DataReceived();};
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
    hidIO.printReport();
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
    hidIO.stopReadingThread();
    OSC_Sender.disConnect();
}

void MainComponent::EnableXboxControllerVibration(){
    
    if(hidIO.isConneted){
        std::cout<<"EnableXboxControllerVibration \n";
        hidIO.writeRawData(xbxUI.VibrationData, 0x03, 9);
        
    }
    
}
