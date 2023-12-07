/*
  ==============================================================================

    DualSense_Output.cpp
    Created: 6 Nov 2023 10:23:01am
    Author:  Hongshuo Fan

  ==============================================================================
*/

#include <JuceHeader.h>
#include "DualSense_Output.h"

//==============================================================================
DualSense_Output::DualSense_Output()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    //ds_crc32.InitializeTable(0xedb88320u);
}

DualSense_Output::~DualSense_Output()
{
}

void DualSense_Output::createDualSenseOutput() {
  

    uint32_t crc_Data = ds_crc32.compute(_output, 74);
    _output[0x4A] = (uint8_t)((crc_Data & 0x000000FF) >> 0UL);
    _output[0x4B] = (uint8_t)((crc_Data & 0x0000FF00) >> 8UL);
    _output[0x4C] = (uint8_t)((crc_Data & 0x00FF0000) >> 16UL);
    _output[0x4D] = (uint8_t)((crc_Data & 0xFF000000) >> 24UL);
    
}

void DualSense_Output::initialOuput() {
    
    _output[0] = 0x31;
    _output[1] = 0x02;
    //_output[2] = 0x15;
    
    _output[2] = 0xFF;
    _output[3] = 0xF7;
    
    uint16_t lrmbl = 0.;
    uint16_t rrmbl = 0.;
    int btMul = 10;
    
    lrmbl = fmax(lrmbl - 0x200 / btMul, 0);
    rrmbl = fmax(rrmbl - 0x100 / btMul, 0);
    
    unsigned char leftRumble = (lrmbl & 0xFF00)  >> 8UL;
    unsigned char rightRumble = (rrmbl & 0xFF00) >> 8UL;
    
    std::cout<<lrmbl<<"\n";
    printf("%u", leftRumble);
    
    std::cout<<rrmbl<<"\n";
    printf("%u", rightRumble);
    
    //std::cout<<lrmbl<<"\n";
    
    //std::cout<<rrmbl<<"\n";
    
    _output[4] = 0x01;
    _output[5] = 0x01;
    
    _output[6] = 0x00;
    _output[7] = 0x00;
    _output[8] = 0x00;
        // Mic led
    _output[10] = 0x02;
    
    // 0xff, 0x03 rumble??
//
//    _output[3] = 0xF7; // 0xff disable all LEDs - top LED, bottom LED, Mic LED (this just if bufWrite[63] == 0x02)// 0xf3 disable top LED// 0xf4 enable all LEDs - top LED, bottom LED, Mic LED (this just if buf[63] == 0x02) // 0x54 all led without mic led
//// Right motor power
//    _output[4] = 0x01;  // Right motor power
//    _output[5] = 0x01;
//    _output[6] = 0x00;
//    _output[9] = 0x01;
////    _output[8] = 0x40;// Left motor power
////    _output[9] = 0x40;
////    _output[10] = 0x00;
////    _output[11] = 0x40;
//    //bufWrite[10] = 0x00;  // off Mic LED (if buf[2] == f7)
////                /* ... */
////                bufWrite[44] = 0xc1; // LEDs from left to right -> 0xc1 0xa2 0xc4 0xc8 0xd0// 0x00 all OFF, 0xff all ON
////                bufWrite[45] =  0x80; // R
////                bufWrite[46] =  0x80; // G
////                bufWrite[47] = 0x80; // B
////                /* ... */
////                bufWrite[63] = 0x02; // Short Blink bottom led
////                /* ... */
//    _output[66] = 0x01; // If both are set to 0xff it will turn OFF Motors and LEDs
//    _output[67] = 0x01; // else if both are set 0x02 it will turn ON Motors and LEDs
//    
    createDualSenseOutput();
}

void DualSense_Output::disConnectOutput() {
    
    _output[0] = 0x31;
    _output[1] = 0x02;
    _output[2] = 0x00;
    _output[3] = 0xff;
    
    createDualSenseOutput();
}




