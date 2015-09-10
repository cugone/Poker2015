/*******************************************************************************
* solution: Poker
* project:  Poker
* file:     Classes\HandValues.h
* author:   Casey Ugone
* summary:  Declares the hand values class
*           Copyright (c) 2015 Blisspoint Softworks. All rights reserved.
*
*******************************************************************************/
#ifndef POKER_HANDVALUES_H
#define POKER_HANDVALUES_H

#include <cstdint>

#include <iostream>
#include <string>

namespace hand {

/**************************************************************************************************
 * <summary>Values that represent the types of Poker hands.</summary>
 * <remarks>Casey Ugone, 10/22/2012.</remarks>
 * <remarks>Royal Flush is not represented because it is a Straight Flush with Ace High.</remarks>
 **************************************************************************************************/
enum class type : uint8_t {
     /** <summary>b0000'0000.</summary> */
    highcard      = 0x00,
     /** <summary>b0000'0001.</summary> */
    onepair       = 0x01,
     /** <summary>b0000'0010.</summary> */
    twopair       = 0x02,
     /** <summary>b0000'0100.</summary> */
    threekind     = 0x04,
     /** <summary>b0000'1000.</summary> */
    straight      = 0x08,
     /** <summary>b0001'0000.</summary> */
    flush         = 0x10,
     /** <summary>b0010'0000.</summary> */
    fullhouse     = 0x20,
     /** <summary>b0100'0000.</summary> */
    fourkind      = 0x40,
     /** <summary>b1000'0000.</summary> */
    straightflush = 0x80,
};

/**************************************************************************************************
 * <summary>Type to string.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 * <param name="h">The hand::type to process.</param>
 * <returns>A std::string.</returns>
 **************************************************************************************************/
std::string TypeToString(const hand::type& h);

/**************************************************************************************************
 * <summary>Gets type from string.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 * <param name="type_value">The type value.</param>
 * <returns>The type from string.</returns>
 **************************************************************************************************/
hand::type GetTypeFromString(const std::string& type_value);

/**************************************************************************************************
 * <summary>Stream insertion operator.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 * <param name="out_stream">[in,out] Stream to write data to.</param>
 * <param name="h">         The hand::type to process.</param>
 * <returns>The shifted result.</returns>
 **************************************************************************************************/
std::ostream& operator<<(std::ostream& out_stream, const hand::type& h);

}

#endif