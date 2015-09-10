/*******************************************************************************
* solution: Poker
* project:  Poker
* file:     Classes\CCard.h
* author:   Casey Ugone
* summary:  Declares the card class
*           Copyright (c) 2015 Blisspoint Softworks. All rights reserved.
*
*******************************************************************************/
#ifndef POKER_CCARD_H
#define POKER_CCARD_H

#include <iostream>
#include "cardvalues.h"

/**************************************************************************************************
 * <summary>A card.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 **************************************************************************************************/
class Card {
public:

    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     **************************************************************************************************/
    Card();

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="face">The face.</param>
     * <param name="suit">The suit.</param>
     **************************************************************************************************/
    Card(const cardvalue::face& face, const cardvalue::suit& suit);

    /**************************************************************************************************
     * <summary>Copy constructor.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="other">The other.</param>
     **************************************************************************************************/
    Card(const Card& other);

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A shallow copy of this Card.</returns>
     **************************************************************************************************/
    Card& operator=(const Card& rhs);

    /**************************************************************************************************
     * <summary>Gets the value.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>The value.</returns>
     **************************************************************************************************/
    uint8_t GetValue() const;

    /**************************************************************************************************
     * <summary>Gets the value.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>The value.</returns>
     **************************************************************************************************/
    uint8_t GetValue();

    /**************************************************************************************************
     * <summary>Gets the face.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>The face.</returns>
     **************************************************************************************************/
    uint8_t GetFace() const;

    /**************************************************************************************************
     * <summary>Gets the face.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>The face.</returns>
     **************************************************************************************************/
    uint8_t GetFace();

    /**************************************************************************************************
     * <summary>Gets the suit.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>The suit.</returns>
     **************************************************************************************************/
    uint8_t GetSuit() const;

    /**************************************************************************************************
     * <summary>Gets the suit.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>The suit.</returns>
     **************************************************************************************************/
    uint8_t GetSuit();

    /**************************************************************************************************
     * <summary>Equality operator.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the parameters are considered equivalent.</returns>
     **************************************************************************************************/
    bool operator==(const Card& rhs);

    /**************************************************************************************************
     * <summary>Inequality operator.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the parameters are not considered equivalent.</returns>
     **************************************************************************************************/
    bool operator!=(const Card& rhs);

    /**************************************************************************************************
     * <summary>Less-than comparison operator.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the first parameter is less than the second.</returns>
     **************************************************************************************************/
    bool operator<(const Card& rhs);

    /**************************************************************************************************
     * <summary>Greater-than comparison operator.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the first parameter is greater than to the second.</returns>
     **************************************************************************************************/
    bool operator>(const Card& rhs);

    /**************************************************************************************************
     * <summary>Less-than-or-equal comparison operator.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the first parameter is less than or equal to the second.</returns>
     **************************************************************************************************/
    bool operator<=(const Card& rhs);

    /**************************************************************************************************
     * <summary>Greater-than-or-equal comparison operator.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the first parameter is greater than or equal to the second.</returns>
     **************************************************************************************************/
    bool operator>=(const Card& rhs);

protected:

    /**************************************************************************************************
     * <summary>Sets a value.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="value">The value.</param>
     **************************************************************************************************/
    void SetValue(uint8_t value);

    /**************************************************************************************************
     * <summary>Sets a suit.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="suit">The suit.</param>
     **************************************************************************************************/
    void SetSuit(cardvalue::suit suit);

    /**************************************************************************************************
     * <summary>Sets a face.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="face">The face.</param>
     **************************************************************************************************/
    void SetFace(cardvalue::face face);
private:
    /** <summary>The value of a card stored in an 8-bit unsigned integer high nibble is the face, the low nibble is the suit.</summary> */
    uint8_t _value;
};

#endif