/*
  ==============================================================================

    JoyCon_Output.cpp
    Created: 3 Dec 2023 1:42:39pm
    Author:  Hongshuo Fan

  ==============================================================================
*/

#include <JuceHeader.h>
#include "JoyCon_Output.h"

//==============================================================================
JoyCon_Output::JoyCon_Output()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

JoyCon_Output::~JoyCon_Output()
{
}

void JoyCon_Output::initBasicOutput()
{
    _output[0] = 0x01;
    _output[1] = globalPacketNumber;
    globalPacketNumber += 1;
    if (globalPacketNumber > 0xF){
        globalPacketNumber = 0x0;
    }
    _output[2] = 0x00;
    _output[3] = 0x01;
    _output[4] = 0x40;
    _output[5] = 0x40;
    _output[6] = 0x00;
    _output[7] = 0x01;
    _output[8] = 0x40;
    _output[9] = 0x40;
    //above are rumble data to control vibration . Set to default to not use it
    _output[10] = 0x00;
    _output[11] = 0x00;
    _output[12] = 0x00;
    _output[13] = 0x00;
    _output[14] = 0x00;
    
}

void JoyCon_Output::trunIMU(bool on_off)
{
    initBasicOutput();
    _output[10] = 0x40;
    _output[11] = on_off ? 0x01 : 0x00;
}

void JoyCon_Output::changeMode(int ModeIndex)
{
    initBasicOutput();
    _output[10] = 0x03;
    // x3F    Simple HID mode. Pushes updates with every button press
    // x30    Standard full mode. Pushes current state @60Hz
    // x31    NFC/IR mode. Pushes large packets @60Hz
    switch (ModeIndex) {
        case 0:
            _output[11] = 0x3F;
            break;
            
        case 1:
            _output[11] = 0x30;
            break;
            
        case 2:
            _output[11] = 0x31;
            break;
        case 3:
            _output[11] = 0x00;
            break;
    }
}

void JoyCon_Output::Vibration(double highFreq, double highAmp, double lowFreq, double lowAmp, bool isLeft)
{
    initBasicOutput();
    uint16_t encodeByte = uint16_t(__encodeFreq(highFreq));
    uint16_t hfT = 0;
    uint8_t hf = 0;
    uint8_t hfA = 0;
    hfT = (encodeByte - 0x60) << 2;
    if (hfT >= 256) {
        hfA = uint8_t(hfT >> 8);
        hf = uint8_t(hfT & 0xff);
    }
    else {
        hf = uint8_t(hfT);
    }
    uint8_t hAMPByte = __encodeAmp(highAmp);
    hfA += hAMPByte;
    double lfcast = lowFreq;
    uint8_t lf = 0;
    if (lfcast > 626.0) {
         lfcast = 626.0;
    }
    encodeByte = uint16_t(__encodeFreq(lfcast));
    lf = uint8_t(encodeByte - 0x40);
    
    uint16_t lAMP2Byte = __encodeLowAmp(lowAmp);
    lf += uint8_t(lAMP2Byte >> 8);
    uint8_t lfA = uint8_t(lAMP2Byte & 0xff);
    
    int Base =  isLeft ? 2 : 6;
    _output[Base] = hf;
    _output[Base + 1] = hfA;
    _output[Base + 2] = lf;
    _output[Base + 3] = lfA;
   
}

uint8_t JoyCon_Output::__encodeFreq(double Freq){
    double freq = Freq;
    if (freq < 41.0) {
        freq = 41.0;
    }
    else if (freq > 1252.0) {
        freq = 1252.0;
    }
    uint8_t encoded_hex_freq = uint8_t(round(log2(freq/10.0)*32.0));
    return encoded_hex_freq;
}

uint8_t JoyCon_Output::__encodeAmp(double Amp){
    double amp = Amp;
    if (amp <= 0) {
        amp = 0.0;
        return 0;
    }
    if (amp > 1) {
        amp = 1.0;
    }
    if (amp < 0.117) {return uint8_t(double(uint8_t(log2(amp * 1000) * 32) - 0x60) / (5 - (pow(2.0, amp))) - 1);}
    if (amp >= 0.117 && amp < 0.23) {return (uint8_t(log2(amp * 1000) * 32) - 0x60) - 0x5c;}
    if (amp >= 0.23) {return uint8_t(((uint8_t(log2(amp * 1000) * 32) - 0x60) * 2) - 0xf6);}
    return 0;
}

uint16_t JoyCon_Output::__encodeLowAmp(double Amp){
    uint8_t encoded = uint8_t(__encodeAmp(Amp) / 2);
    uint8_t evenOrOdd = encoded % 2;
    uint8_t bytes1 = 0;
    uint8_t bytes2 = 0;
        if (evenOrOdd > 0) {
            // odd
            bytes1 = 0x80;
            encoded = encoded - 1;
        }
        
    encoded = encoded / 2;
        
   bytes2 = 0x40 + encoded;
        
        // if you wanted to combine them:
    uint16_t byte = (uint16_t(bytes1) << 8) | uint16_t(bytes2);
    return byte;
}
