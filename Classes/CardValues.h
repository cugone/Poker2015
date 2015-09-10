/*******************************************************************************
* solution: Poker
* project:  Poker
* file:     Classes\CardValues.h
* author:   Casey Ugone
* summary:  Declares the card values class
*           Copyright (c) 2015 Blisspoint Softworks. All rights reserved.
*
*******************************************************************************/
#ifndef POKER_CARDVALUES_H
#define POKER_CARDVALUES_H

#include <cctype>
#include <cstdint>
#include <algorithm>
#include <string>
#include <type_traits>

namespace cardvalue {

/**************************************************************************************************
 * <summary>Values that represent suits.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 **************************************************************************************************/
enum class suit : uint8_t {
     /** <summary>b0001.</summary> */
    club    = 0x01,
     /** <summary>b0010.</summary> */
    diamond = 0x02,
     /** <summary>b0100.</summary> */
    heart   = 0x04,
     /** <summary>b1000.</summary> */
    spade   = 0x08,
};

/**************************************************************************************************
 * <summary>Values that represent faces.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 **************************************************************************************************/
enum class face : uint8_t {
     /** <summary>b0010'0000.</summary> */
    two   = 0x20,
     /** <summary>b0011'0000.</summary> */
    three = 0x30,
     /** <summary>b0100'0000.</summary> */
    four  = 0x40,
     /** <summary>b0101'0000.</summary> */
    five  = 0x50,
     /** <summary>b0110'0000.</summary> */
    six   = 0x60,
     /** <summary>b0111'0000.</summary> */
    seven = 0x70,
     /** <summary>b1000'0000.</summary> */
    eight = 0x80,
     /** <summary>b1001'0000.</summary> */
    nine  = 0x90,
     /** <summary>b1010'0000.</summary> */
    ten   = 0xA0,
     /** <summary>b1011'0000.</summary> */
    jack  = 0xB0,
     /** <summary>b1100'0000.</summary> */
    queen = 0xC0,
     /** <summary>b1101'0000.</summary> */
    king  = 0xD0,
     /** <summary>b1110'0000.</summary> */
    ace   = 0xE0,
};

/**************************************************************************************************
 * <summary>Gets face from string.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 * <param name="face_value">The face value.</param>
 * <returns>The face from string.</returns>
 **************************************************************************************************/
face GetFaceFromString(const std::string& face_value);

/**************************************************************************************************
 * <summary>Gets suit from string.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 * <param name="suit_value">The suit value.</param>
 * <returns>The suit from string.</returns>
 **************************************************************************************************/
suit GetSuitFromString(const std::string& suit_value);

/**************************************************************************************************
 * <summary>Bitwise 'or' operator.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 * <param name="lhs">A bitfield to process.</param>
 * <param name="rhs">One or more bits to OR into the bitfield.</param>
 * <returns>The result of the operation.</returns>
 **************************************************************************************************/
uint8_t operator|(face lhs, suit rhs);

/**************************************************************************************************
 * <summary>Bitwise 'or' operator.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 * <param name="lhs">A bitfield to process.</param>
 * <param name="rhs">One or more bits to OR into the bitfield.</param>
 * <returns>The result of the operation.</returns>
 **************************************************************************************************/
uint8_t operator|(suit lhs, face rhs);

/**************************************************************************************************
 * <summary>Equality operator.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 * <param name="lhs">The first instance to compare.</param>
 * <param name="rhs">The second instance to compare.</param>
 * <returns>true if the parameters are considered equivalent.</returns>
 **************************************************************************************************/
bool operator==(face lhs, uint8_t rhs);

/**************************************************************************************************
 * <summary>Equality operator.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 * <param name="lhs">The first instance to compare.</param>
 * <param name="rhs">The second instance to compare.</param>
 * <returns>true if the parameters are considered equivalent.</returns>
 **************************************************************************************************/
bool operator==(suit lhs, uint8_t rhs);

/**************************************************************************************************
 * <summary>Equality operator.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 * <param name="lhs">The first instance to compare.</param>
 * <param name="rhs">The second instance to compare.</param>
 * <returns>true if the parameters are considered equivalent.</returns>
 **************************************************************************************************/
bool operator==(uint8_t lhs, suit rhs);

/**************************************************************************************************
 * <summary>Equality operator.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 * <param name="lhs">The first instance to compare.</param>
 * <param name="rhs">The second instance to compare.</param>
 * <returns>true if the parameters are considered equivalent.</returns>
 **************************************************************************************************/
bool operator==(uint8_t lhs, face rhs);

/**************************************************************************************************
 * <summary>Inequality operator.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 * <param name="lhs">The first instance to compare.</param>
 * <param name="rhs">The second instance to compare.</param>
 * <returns>true if the parameters are not considered equivalent.</returns>
 **************************************************************************************************/
bool operator!=(face lhs, uint8_t rhs);

/**************************************************************************************************
 * <summary>Inequality operator.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 * <param name="lhs">The first instance to compare.</param>
 * <param name="rhs">The second instance to compare.</param>
 * <returns>true if the parameters are not considered equivalent.</returns>
 **************************************************************************************************/
bool operator!=(suit lhs, uint8_t rhs);

/**************************************************************************************************
 * <summary>Inequality operator.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 * <param name="lhs">The first instance to compare.</param>
 * <param name="rhs">The second instance to compare.</param>
 * <returns>true if the parameters are not considered equivalent.</returns>
 **************************************************************************************************/
bool operator!=(uint8_t lhs, suit rhs);

/**************************************************************************************************
 * <summary>Inequality operator.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 * <param name="lhs">The first instance to compare.</param>
 * <param name="rhs">The second instance to compare.</param>
 * <returns>true if the parameters are not considered equivalent.</returns>
 **************************************************************************************************/
bool operator!=(uint8_t lhs, face rhs);

/**************************************************************************************************
 * <summary>Bitwise 'or' operator.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 * <param name="lhs">A bitfield to process.</param>
 * <param name="rhs">One or more bits to OR into the bitfield.</param>
 * <returns>The result of the operation.</returns>
 **************************************************************************************************/
uint8_t operator|(face lhs, uint8_t rhs);

/**************************************************************************************************
 * <summary>Bitwise 'or' operator.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 * <param name="lhs">A bitfield to process.</param>
 * <param name="rhs">One or more bits to OR into the bitfield.</param>
 * <returns>The result of the operation.</returns>
 **************************************************************************************************/
uint8_t operator|(suit lhs, uint8_t rhs);

/**************************************************************************************************
 * <summary>Bitwise 'or' operator.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 * <param name="lhs">A bitfield to process.</param>
 * <param name="rhs">One or more bits to OR into the bitfield.</param>
 * <returns>The result of the operation.</returns>
 **************************************************************************************************/
uint8_t operator|(uint8_t lhs, suit rhs);

/**************************************************************************************************
 * <summary>Bitwise 'or' operator.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 * <param name="lhs">A bitfield to process.</param>
 * <param name="rhs">One or more bits to OR into the bitfield.</param>
 * <returns>The result of the operation.</returns>
 **************************************************************************************************/
uint8_t operator|(uint8_t lhs, face rhs);

/**************************************************************************************************
 * <summary>Bitwise 'and' operator.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 * <param name="lhs">A bitfield to process.</param>
 * <param name="rhs">A mask of bits to apply to the bitfield.</param>
 * <returns>The result of the operation.</returns>
 **************************************************************************************************/
uint8_t operator&(face lhs, suit rhs);

/**************************************************************************************************
 * <summary>Bitwise 'and' operator.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 * <param name="lhs">A bitfield to process.</param>
 * <param name="rhs">A mask of bits to apply to the bitfield.</param>
 * <returns>The result of the operation.</returns>
 **************************************************************************************************/
uint8_t operator&(suit lhs, face rhs);

/**************************************************************************************************
 * <summary>Bitwise 'and' operator.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 * <param name="lhs">A bitfield to process.</param>
 * <param name="rhs">A mask of bits to apply to the bitfield.</param>
 * <returns>The result of the operation.</returns>
 **************************************************************************************************/
face operator&(face lhs, uint8_t rhs);

/**************************************************************************************************
 * <summary>Bitwise 'and' operator.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 * <param name="lhs">A bitfield to process.</param>
 * <param name="rhs">A mask of bits to apply to the bitfield.</param>
 * <returns>The result of the operation.</returns>
 **************************************************************************************************/
suit operator&(suit lhs, uint8_t rhs);

/**************************************************************************************************
 * <summary>Bitwise 'and' operator.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 * <param name="lhs">A bitfield to process.</param>
 * <param name="rhs">A mask of bits to apply to the bitfield.</param>
 * <returns>The result of the operation.</returns>
 **************************************************************************************************/
face operator&(uint8_t lhs, face rhs);

/**************************************************************************************************
 * <summary>Bitwise 'and' operator.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 * <param name="lhs">A bitfield to process.</param>
 * <param name="rhs">A mask of bits to apply to the bitfield.</param>
 * <returns>The result of the operation.</returns>
 **************************************************************************************************/
suit operator&(uint8_t lhs, suit rhs);

}


#endif