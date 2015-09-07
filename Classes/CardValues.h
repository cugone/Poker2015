#ifndef POKER_CARDVALUES_H
#define POKER_CARDVALUES_H

#include <cctype>
#include <cstdint>
#include <algorithm>
#include <string>
#include <type_traits>

namespace cardvalue {

enum class suit : uint8_t {
    club    = 0x01, //b0001
    diamond = 0x02, //b0010
    heart   = 0x04, //b0100
    spade   = 0x08, //b1000
};

enum class face : uint8_t {
    two   = 0x20, //b0010'0000
    three = 0x30, //b0011'0000
    four  = 0x40, //b0100'0000
    five  = 0x50, //b0101'0000
    six   = 0x60, //b0110'0000
    seven = 0x70, //b0111'0000
    eight = 0x80, //b1000'0000
    nine  = 0x90, //b1001'0000
    ten   = 0xA0, //b1010'0000
    jack  = 0xB0, //b1011'0000
    queen = 0xC0, //b1100'0000
    king  = 0xD0, //b1101'0000
    ace   = 0xE0, //b1110'0000
};

face GetFaceFromString(const std::string& face_value);
suit GetSuitFromString(const std::string& suit_value);
uint8_t operator|(face lhs, suit rhs);
uint8_t operator|(suit lhs, face rhs);
bool operator==(face lhs, uint8_t rhs);
bool operator==(suit lhs, uint8_t rhs);
bool operator==(uint8_t lhs, suit rhs);
bool operator==(uint8_t lhs, face rhs);
bool operator!=(face lhs, uint8_t rhs);
bool operator!=(suit lhs, uint8_t rhs);
bool operator!=(uint8_t lhs, suit rhs);
bool operator!=(uint8_t lhs, face rhs);
uint8_t operator|(face lhs, uint8_t rhs);
uint8_t operator|(suit lhs, uint8_t rhs);
uint8_t operator|(uint8_t lhs, suit rhs);
uint8_t operator|(uint8_t lhs, face rhs);
uint8_t operator&(face lhs, suit rhs);
uint8_t operator&(suit lhs, face rhs);
face operator&(face lhs, uint8_t rhs);
suit operator&(suit lhs, uint8_t rhs);
face operator&(uint8_t lhs, face rhs);
suit operator&(uint8_t lhs, suit rhs);

}


#endif