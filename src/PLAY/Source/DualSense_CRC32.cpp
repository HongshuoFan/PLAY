/*
  ==============================================================================

    DualSense_CRC32.cpp
    Created: 26 Nov 2023 10:00:00am
    Author:  Hongshuo Fan

  ==============================================================================
*/


#include "DualSense_CRC32.h"
//__DS5W::CRC32::CRC32()
//{
//    InitializeTable(0xedb88320u);
//}

//https://github.com/Ohjurot/DualSense-Windows/blob/main/VS19_Solution/DualSenseWindows/src/DualSenseWindows/DS_CRC32.h
// Hash tabel
const uint32_t __DS5W::CRC32::hashTable[256] = {
    0xd202ef8d, 0xa505df1b, 0x3c0c8ea1, 0x4b0bbe37, 0xd56f2b94, 0xa2681b02, 0x3b614ab8, 0x4c667a2e,
    0xdcd967bf, 0xabde5729, 0x32d70693, 0x45d03605, 0xdbb4a3a6, 0xacb39330, 0x35bac28a, 0x42bdf21c,
    0xcfb5ffe9, 0xb8b2cf7f, 0x21bb9ec5, 0x56bcae53, 0xc8d83bf0, 0xbfdf0b66, 0x26d65adc, 0x51d16a4a,
    0xc16e77db, 0xb669474d, 0x2f6016f7, 0x58672661, 0xc603b3c2, 0xb1048354, 0x280dd2ee, 0x5f0ae278,
    0xe96ccf45, 0x9e6bffd3, 0x762ae69, 0x70659eff, 0xee010b5c, 0x99063bca, 0xf6a70, 0x77085ae6,
    0xe7b74777, 0x90b077e1, 0x9b9265b, 0x7ebe16cd, 0xe0da836e, 0x97ddb3f8, 0xed4e242, 0x79d3d2d4,
    0xf4dbdf21, 0x83dcefb7, 0x1ad5be0d, 0x6dd28e9b, 0xf3b61b38, 0x84b12bae, 0x1db87a14, 0x6abf4a82,
    0xfa005713, 0x8d076785, 0x140e363f, 0x630906a9, 0xfd6d930a, 0x8a6aa39c, 0x1363f226, 0x6464c2b0,
    0xa4deae1d, 0xd3d99e8b, 0x4ad0cf31, 0x3dd7ffa7, 0xa3b36a04, 0xd4b45a92, 0x4dbd0b28, 0x3aba3bbe,
    0xaa05262f, 0xdd0216b9, 0x440b4703, 0x330c7795, 0xad68e236, 0xda6fd2a0, 0x4366831a, 0x3461b38c,
    0xb969be79, 0xce6e8eef, 0x5767df55, 0x2060efc3, 0xbe047a60, 0xc9034af6, 0x500a1b4c, 0x270d2bda,
    0xb7b2364b, 0xc0b506dd, 0x59bc5767, 0x2ebb67f1, 0xb0dff252, 0xc7d8c2c4, 0x5ed1937e, 0x29d6a3e8,
    0x9fb08ed5, 0xe8b7be43, 0x71beeff9, 0x6b9df6f, 0x98dd4acc, 0xefda7a5a, 0x76d32be0, 0x1d41b76,
    0x916b06e7, 0xe66c3671, 0x7f6567cb, 0x862575d, 0x9606c2fe, 0xe101f268, 0x7808a3d2, 0xf0f9344,
    0x82079eb1, 0xf500ae27, 0x6c09ff9d, 0x1b0ecf0b, 0x856a5aa8, 0xf26d6a3e, 0x6b643b84, 0x1c630b12,
    0x8cdc1683, 0xfbdb2615, 0x62d277af, 0x15d54739, 0x8bb1d29a, 0xfcb6e20c, 0x65bfb3b6, 0x12b88320,
    0x3fba6cad, 0x48bd5c3b, 0xd1b40d81, 0xa6b33d17, 0x38d7a8b4, 0x4fd09822, 0xd6d9c998, 0xa1def90e,
    0x3161e49f, 0x4666d409, 0xdf6f85b3, 0xa868b525, 0x360c2086, 0x410b1010, 0xd80241aa, 0xaf05713c,
    0x220d7cc9, 0x550a4c5f, 0xcc031de5, 0xbb042d73, 0x2560b8d0, 0x52678846, 0xcb6ed9fc, 0xbc69e96a,
    0x2cd6f4fb, 0x5bd1c46d, 0xc2d895d7, 0xb5dfa541, 0x2bbb30e2, 0x5cbc0074, 0xc5b551ce, 0xb2b26158,
    0x4d44c65, 0x73d37cf3, 0xeada2d49, 0x9ddd1ddf, 0x3b9887c, 0x74beb8ea, 0xedb7e950, 0x9ab0d9c6,
    0xa0fc457, 0x7d08f4c1, 0xe401a57b, 0x930695ed, 0xd62004e, 0x7a6530d8, 0xe36c6162, 0x946b51f4,
    0x19635c01, 0x6e646c97, 0xf76d3d2d, 0x806a0dbb, 0x1e0e9818, 0x6909a88e, 0xf000f934, 0x8707c9a2,
    0x17b8d433, 0x60bfe4a5, 0xf9b6b51f, 0x8eb18589, 0x10d5102a, 0x67d220bc, 0xfedb7106, 0x89dc4190,
    0x49662d3d, 0x3e611dab, 0xa7684c11, 0xd06f7c87, 0x4e0be924, 0x390cd9b2, 0xa0058808, 0xd702b89e,
    0x47bda50f, 0x30ba9599, 0xa9b3c423, 0xdeb4f4b5, 0x40d06116, 0x37d75180, 0xaede003a, 0xd9d930ac,
    0x54d13d59, 0x23d60dcf, 0xbadf5c75, 0xcdd86ce3, 0x53bcf940, 0x24bbc9d6, 0xbdb2986c, 0xcab5a8fa,
    0x5a0ab56b, 0x2d0d85fd, 0xb404d447, 0xc303e4d1, 0x5d677172, 0x2a6041e4, 0xb369105e, 0xc46e20c8,
    0x72080df5, 0x50f3d63, 0x9c066cd9, 0xeb015c4f, 0x7565c9ec, 0x262f97a, 0x9b6ba8c0, 0xec6c9856,
    0x7cd385c7, 0xbd4b551, 0x92dde4eb, 0xe5dad47d, 0x7bbe41de, 0xcb97148, 0x95b020f2, 0xe2b71064,
    0x6fbf1d91, 0x18b82d07, 0x81b17cbd, 0xf6b64c2b, 0x68d2d988, 0x1fd5e91e, 0x86dcb8a4, 0xf1db8832,
    0x616495a3, 0x1663a535, 0x8f6af48f, 0xf86dc419, 0x660951ba, 0x110e612c, 0x88073096, 0xff000000
};

//https://github.com/Ryochan7/DS4Windows/blob/jay/DS4Windows/DS4Library/Crc32.cs
//const uint32_t __DS5W::CRC32::defaultTable[256] =
//{
//                0x00000000, 0x77073096, 0xEE0E612C, 0x990951BA,
//                0x076DC419, 0x706AF48F, 0xE963A535, 0x9E6495A3,
//                0x0EDB8832, 0x79DCB8A4, 0xE0D5E91E, 0x97D2D988,
//                0x09B64C2B, 0x7EB17CBD, 0xE7B82D07, 0x90BF1D91,
//                0x1DB71064, 0x6AB020F2, 0xF3B97148, 0x84BE41DE,
//                0x1ADAD47D, 0x6DDDE4EB, 0xF4D4B551, 0x83D385C7,
//                0x136C9856, 0x646BA8C0, 0xFD62F97A, 0x8A65C9EC,
//                0x14015C4F, 0x63066CD9, 0xFA0F3D63, 0x8D080DF5,
//                0x3B6E20C8, 0x4C69105E, 0xD56041E4, 0xA2677172,
//                0x3C03E4D1, 0x4B04D447, 0xD20D85FD, 0xA50AB56B,
//                0x35B5A8FA, 0x42B2986C, 0xDBBBC9D6, 0xACBCF940,
//                0x32D86CE3, 0x45DF5C75, 0xDCD60DCF, 0xABD13D59,
//                0x26D930AC, 0x51DE003A, 0xC8D75180, 0xBFD06116,
//                0x21B4F4B5, 0x56B3C423, 0xCFBA9599, 0xB8BDA50F,
//                0x2802B89E, 0x5F058808, 0xC60CD9B2, 0xB10BE924,
//                0x2F6F7C87, 0x58684C11, 0xC1611DAB, 0xB6662D3D,
//                0x76DC4190, 0x01DB7106, 0x98D220BC, 0xEFD5102A,
//                0x71B18589, 0x06B6B51F, 0x9FBFE4A5, 0xE8B8D433,
//                0x7807C9A2, 0x0F00F934, 0x9609A88E, 0xE10E9818,
//                0x7F6A0DBB, 0x086D3D2D, 0x91646C97, 0xE6635C01,
//                0x6B6B51F4, 0x1C6C6162, 0x856530D8, 0xF262004E,
//                0x6C0695ED, 0x1B01A57B, 0x8208F4C1, 0xF50FC457,
//                0x65B0D9C6, 0x12B7E950, 0x8BBEB8EA, 0xFCB9887C,
//                0x62DD1DDF, 0x15DA2D49, 0x8CD37CF3, 0xFBD44C65,
//                0x4DB26158, 0x3AB551CE, 0xA3BC0074, 0xD4BB30E2,
//                0x4ADFA541, 0x3DD895D7, 0xA4D1C46D, 0xD3D6F4FB,
//                0x4369E96A, 0x346ED9FC, 0xAD678846, 0xDA60B8D0,
//                0x44042D73, 0x33031DE5, 0xAA0A4C5F, 0xDD0D7CC9,
//                0x5005713C, 0x270241AA, 0xBE0B1010, 0xC90C2086,
//                0x5768B525, 0x206F85B3, 0xB966D409, 0xCE61E49F,
//                0x5EDEF90E, 0x29D9C998, 0xB0D09822, 0xC7D7A8B4,
//                0x59B33D17, 0x2EB40D81, 0xB7BD5C3B, 0xC0BA6CAD,
//                0xEDB88320, 0x9ABFB3B6, 0x03B6E20C, 0x74B1D29A,
//                0xEAD54739, 0x9DD277AF, 0x04DB2615, 0x73DC1683,
//                0xE3630B12, 0x94643B84, 0x0D6D6A3E, 0x7A6A5AA8,
//                0xE40ECF0B, 0x9309FF9D, 0x0A00AE27, 0x7D079EB1,
//                0xF00F9344, 0x8708A3D2, 0x1E01F268, 0x6906C2FE,
//                0xF762575D, 0x806567CB, 0x196C3671, 0x6E6B06E7,
//                0xFED41B76, 0x89D32BE0, 0x10DA7A5A, 0x67DD4ACC,
//                0xF9B9DF6F, 0x8EBEEFF9, 0x17B7BE43, 0x60B08ED5,
//                0xD6D6A3E8, 0xA1D1937E, 0x38D8C2C4, 0x4FDFF252,
//                0xD1BB67F1, 0xA6BC5767, 0x3FB506DD, 0x48B2364B,
//                0xD80D2BDA, 0xAF0A1B4C, 0x36034AF6, 0x41047A60,
//                0xDF60EFC3, 0xA867DF55, 0x316E8EEF, 0x4669BE79,
//                0xCB61B38C, 0xBC66831A, 0x256FD2A0, 0x5268E236,
//                0xCC0C7795, 0xBB0B4703, 0x220216B9, 0x5505262F,
//                0xC5BA3BBE, 0xB2BD0B28, 0x2BB45A92, 0x5CB36A04,
//                0xC2D7FFA7, 0xB5D0CF31, 0x2CD99E8B, 0x5BDEAE1D,
//                0x9B64C2B0, 0xEC63F226, 0x756AA39C, 0x026D930A,
//                0x9C0906A9, 0xEB0E363F, 0x72076785, 0x05005713,
//                0x95BF4A82, 0xE2B87A14, 0x7BB12BAE, 0x0CB61B38,
//                0x92D28E9B, 0xE5D5BE0D, 0x7CDCEFB7, 0x0BDBDF21,
//                0x86D3D2D4, 0xF1D4E242, 0x68DDB3F8, 0x1FDA836E,
//                0x81BE16CD, 0xF6B9265B, 0x6FB077E1, 0x18B74777,
//                0x88085AE6, 0xFF0F6A70, 0x66063BCA, 0x11010B5C,
//                0x8F659EFF, 0xF862AE69, 0x616BFFD3, 0x166CCF45,
//                0xA00AE278, 0xD70DD2EE, 0x4E048354, 0x3903B3C2,
//                0xA7672661, 0xD06016F7, 0x4969474D, 0x3E6E77DB,
//                0xAED16A4A, 0xD9D65ADC, 0x40DF0B66, 0x37D83BF0,
//                0xA9BCAE53, 0xDEBB9EC5, 0x47B2CF7F, 0x30B5FFE9,
//                0xBDBDF21C, 0xCABAC28A, 0x53B39330, 0x24B4A3A6,
//                0xBAD03605, 0xCDD70693, 0x54DE5729, 0x23D967BF,
//                0xB3667A2E, 0xC4614AB8, 0x5D681B02, 0x2A6F2B94,
//                0xB40BBE37, 0xC30C8EA1, 0x5A05DF1B, 0x2D02EF8D
//};

// Hash seed
const uint32_t __DS5W::CRC32::crcSeed = 0xeada2d49;

//const uint32_t __DS5W::CRC32::DefaultPolynomial = 0xedb88320u;
//const uint32_t __DS5W::CRC32::DefaultSeed = 0xffffffffu;


uint32_t __DS5W::CRC32::compute(unsigned char* buffer, size_t len) {
    // Start point
    uint32_t result = crcSeed;
    //uint32_t result = DefaultSeed;
    // Foreach element in arrray
    for (size_t i = 0; i < len; i++) {
        // Compute crc
        result = hashTable[((unsigned char)result) ^ ((unsigned char)buffer[i])] ^ (result >> 8);
        //result = (result >> 8) ^ hashTable[buffer[i] ^ (result & 0xff)];
    }

    // Return result
    return result;
}

//void __DS5W::CRC32::InitializeTable(uint32_t polynomial)
//{
//    if (polynomial == DefaultPolynomial)
//    {
////        if (!secondTablePop)
////        {
//            for (int i = 0; i <= 0xFF; i++)
//            {
//                testLook[0 + i] = defaultTable[i];
//                testLook[256+i] = (defaultTable[i] >> 8) ^ defaultTable[defaultTable[i] & 0xFF];
//                testLook[512 + i] = (testLook[256 + i] >> 8) ^ defaultTable[testLook[256 + i] & 0xFF];
//                testLook[768 + i] = (testLook[512 + i] >> 8) ^ defaultTable[testLook[512 + i] & 0xFF];
//
//                testLook[1024 + i] = (testLook[768 + i] >> 8) ^ defaultTable[testLook[768 + i] & 0xFF];
//                testLook[1280 + i] = (testLook[1024 + i] >> 8) ^ defaultTable[testLook[1024 + i] & 0xFF];
//                testLook[1536 + i] = (testLook[1280 + i] >> 8) ^ defaultTable[testLook[1280 + i] & 0xFF];
//                testLook[1792 + i] = (testLook[1536 + i] >> 8) ^ defaultTable[testLook[1536 + i] & 0xFF];
//
//                testLook[2048 + i] = (testLook[1792 + i] >> 8) ^ defaultTable[testLook[1792 + i] & 0xFF];
//                testLook[2304 + i] = (testLook[2048 + i] >> 8) ^ defaultTable[testLook[2048 + i] & 0xFF];
//                testLook[2560 + i] = (testLook[2304 + i] >> 8) ^ defaultTable[testLook[2304 + i] & 0xFF];
//                testLook[2816 + i] = (testLook[2560 + i] >> 8) ^ defaultTable[testLook[2560 + i] & 0xFF];
//
//                testLook[3072 + i] = (testLook[2816 + i] >> 8) ^ defaultTable[testLook[2816 + i] & 0xFF];
//                testLook[3328 + i] = (testLook[3072 + i] >> 8) ^ defaultTable[testLook[3072 + i] & 0xFF];
//                testLook[3584 + i] = (testLook[3328 + i] >> 8) ^ defaultTable[testLook[3328 + i] & 0xFF];
//                testLook[3840 + i] = (testLook[3584 + i] >> 8) ^ defaultTable[testLook[3584 + i] & 0xFF];
//
////            }
////            secondTablePop = true;
//
//        }
////        return defaultTable;
//
//    }
//
////    uint32_t createTable[256];
////    for (int i = 0; i < 256; i++)
////    {
////        int entry = i;
////        for (int j = 0; j < 8; j++)
////        {
////            entry = ((entry & 1) == 1) ? (entry >> 1) ^ polynomial : (entry >> 1);
////            createTable[i] = entry;
////
////        }
////    }
////
////    return createTable;
//
//}
//
//uint32_t __DS5W::CRC32::CalculateBasicHash(unsigned char* buffer, int offset, int size)
//{
//    uint32_t crc = DefaultSeed;
//    int i = offset;
//
//    while (size >= 16) {
//        uint32_t one = (buffer[i] |
//                        (uint32_t)(buffer[i+1] << 8) |
//                        (uint32_t)(buffer[i+2] << 16) |
//                        (uint32_t)(buffer[i+3] << 24)) ^ crc;
//        uint32_t two = (buffer[i+4] |
//                        (uint32_t)(buffer[i+5] << 8) |
//                        (uint32_t)(buffer[i+6] << 16) |
//                        (uint32_t)(buffer[i+7] << 24));
//        uint32_t three = (buffer[i+8] |
//                        (uint32_t)(buffer[i+9] << 8) |
//                        (uint32_t)(buffer[i+10] << 16) |
//                        (uint32_t)(buffer[i+11] << 24));
//        uint32_t four = (buffer[i+12] |
//                        (uint32_t)(buffer[i+13] << 8) |
//                        (uint32_t)(buffer[i+14] << 16) |
//                        (uint32_t)(buffer[i+15] << 24));
//        crc = testLook[3840 + (one & 0xFF)] ^
//        testLook[3584 + ((one >> 8) & 0xFF)] ^
//        testLook[3328 + ((one >> 16) & 0xFF)] ^
//        testLook[3072 + ((one >> 24) & 0xFF)] ^
//        testLook[2816 + (two & 0xFF)] ^
//        testLook[2560 + ((two >> 8) & 0xFF)] ^
//        testLook[2304 + ((two >> 16) & 0xFF)] ^
//        testLook[2048 + ((two >> 24) & 0xFF)] ^
//        testLook[1792 + (three & 0xFF)] ^
//        testLook[1536 + ((three >> 8) & 0xFF)] ^
//        testLook[1280 + ((three >> 16) & 0xFF)] ^
//        testLook[1024 + ((three >> 24) & 0xFF)] ^
//        testLook[768 + (four & 0xFF)] ^
//        testLook[512 + ((four >> 8) & 0xFF)] ^
//        testLook[256 + ((four >> 16) & 0xFF)] ^
//        testLook[(four >> 24) & 0xFF];
//        i += 16;
//        size -= 16;
//    }
//
//    while (size >= 8)
//                   {
//                       uint32_t one8 = (buffer[i] |
//                                   (uint32_t)(buffer[i+1] << 8) |
//                                   (uint32_t)(buffer[i+2] << 16) |
//                                   (uint32_t)(buffer[i+3] << 24)) ^ crc;
//                       uint32_t two8 = buffer[i+4] |
//                                   (uint32_t)(buffer[i+5] << 8) |
//                                   (uint32_t)(buffer[i+6] << 16) |
//                                   (uint32_t)(buffer[i+7] << 24);
//                       crc = testLook[1792 + (one8 & 0xFF)] ^
//                        testLook[1536 + ((one8 >> 8) & 0xFF)] ^
//                        testLook[1280 + ((one8 >> 16) & 0xFF)] ^
//                        testLook[1024 + (one8 >> 24)] ^
//                        testLook[768 + (two8 & 0xFF)] ^
//                        testLook[512 + ((two8 >> 8) & 0xFF)] ^
//                        testLook[256 + ((two8 >> 16) & 0xFF)] ^
//                        testLook[two8 >> 24];
//                       i += 8;
//                       size -= 8;
//                   }
//
//    while (size >= 0)
//    {
//
//        crc = (crc >> 8) ^ testLook[(crc & 0xFF) ^ buffer[i+1]];// i++;
//        i += 1;
//    }
//
//    return crc;
//}
