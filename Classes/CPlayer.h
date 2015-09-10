/*******************************************************************************
* solution: Poker
* project:  Poker
* file:     Classes\CPlayer.h
* author:   Casey Ugone
* summary:  Declares the player class
*           Copyright (c) 2015 Blisspoint Softworks. All rights reserved.
*
*******************************************************************************/
#ifndef POKER_CPLAYER_H
#define POKER_CPLAYER_H

/**************************************************************************************************
 * <summary>A card.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 **************************************************************************************************/
class Card;

#include "CHand.h"

#include <ostream>

/**************************************************************************************************
 * <summary>A player.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 **************************************************************************************************/
class Player {
public:

    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     **************************************************************************************************/
    Player();

    /**************************************************************************************************
     * <summary>Gets the hand.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>The hand.</returns>
     **************************************************************************************************/
    const Hand& GetHand() const;

    /**************************************************************************************************
     * <summary>Gets the hand.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>The hand.</returns>
     **************************************************************************************************/
    Hand& GetHand();

    /**************************************************************************************************
     * <summary>Adds a card to hand.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="c">The Card to process.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    bool AddCardToHand(const Card& c);

    /**************************************************************************************************
     * <summary>Removes the card from hand described by c.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="c">The Card to process.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    bool RemoveCardFromHand(const Card& c);

    /**************************************************************************************************
     * <summary>Calculates the hand value.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     **************************************************************************************************/
    void CalculateHandValue();

    /**************************************************************************************************
     * <summary>Displays a hand to stream described by OS.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="os">[in,out] (Optional) the operating system.</param>
     **************************************************************************************************/
    void DisplayHand(std::ostream& os = std::cout) const;

protected:
private:
    /** <summary>The hand.</summary> */
    Hand _hand;
 /** <summary>.</summary> */
};

#endif