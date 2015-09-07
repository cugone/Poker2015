#ifndef POKER_HANDVALUES_H
#define POKER_HANDVALUES_H

#include <cstdint>

#include <iostream>
#include <string>

namespace hand {

/**************************************************************************************************
* <summary>Values that represent the types of Poker hands. </summary>
* <remarks>Casey Ugone, 10/22/2012.</remarks>
* <remarks>Royal Flush is not represented because it is a Straight Flush with Ace High.</remarks>
**************************************************************************************************/
enum class type : uint8_t {
    highcard      = 0x00, //b0000'0000
    onepair       = 0x01, //b0000'0001
    twopair       = 0x02, //b0000'0010
    threekind     = 0x04, //b0000'0100
    straight      = 0x08, //b0000'1000
    flush         = 0x10, //b0001'0000
    fullhouse     = 0x20, //b0010'0000
    fourkind      = 0x40, //b0100'0000
    straightflush = 0x80, //b1000'0000
};

std::string TypeToString(const hand::type& h);
hand::type GetTypeFromString(const std::string& type_value);
std::ostream& operator<<(std::ostream& out_stream, const hand::type& h);

}

#endif