/*
  ==============================================================================

    DualSense_CRC32.h
    Created: 26 Nov 2023 10:00:00am
    Author:  Hongshuo Fan

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
namespace __DS5W {
    /// <summary>
    /// Pre gennerated CRC hashing for DS5
    /// </summary>
    class CRC32 {
    private:
        /// <summary>
        /// Fast lookup precalculated byte crc hashes
        /// </summary>
        const static uint32_t hashTable[256];
        const static uint32_t defaultTable[256];
        /// <summary>
        /// Start seed for crc hash
        /// </summary>
        const static uint32_t crcSeed;
        
        const static uint32_t DefaultPolynomial;
        const static uint32_t DefaultSeed;
        
        uint32_t testLook[256];
        
        bool secondTablePop = false;
        
        
    public:
        CRC32();
        /// <summary>
        /// Compute the CRC32 Hash
        /// </summary>
        /// <param name="buffer">Input buffer</param>
        /// <param name="len">Length of buffer</param>
        /// <returns>Computed crc value</returns>
        static uint32_t compute(unsigned char* buffer, size_t len);
        uint32_t CalculateBasicHash(unsigned char* buffer, int offset, int size);
        void InitializeTable(uint32_t polynomial);
    };
}

