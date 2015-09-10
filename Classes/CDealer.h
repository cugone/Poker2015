/*******************************************************************************
* solution: Poker
* project:  Poker
* file:     Classes\CDealer.h
* author:   Casey Ugone
* summary:  Declares the dealer class
*           Copyright (c) 2015 Blisspoint Softworks. All rights reserved.
*
*******************************************************************************/
#ifndef POKER_CDEALER_H
#define POKER_CDEALER_H

#include <random>

#include "CDeck.h"

/**************************************************************************************************
 * <summary>A player.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 **************************************************************************************************/
class Player;

/**************************************************************************************************
 * <summary>A card.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 **************************************************************************************************/
class Card;

/**************************************************************************************************
 * <summary>A dealer.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 **************************************************************************************************/
class Dealer {

public:

    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     **************************************************************************************************/
    Dealer();

    /**************************************************************************************************
     * <summary>Shuffle deck.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="deck">[in,out] The deck.</param>
     **************************************************************************************************/
    void ShuffleDeck(Deck& deck);

    /**************************************************************************************************
     * <summary>Cut deck.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="deck">[in,out] The deck.</param>
     **************************************************************************************************/
    void CutDeck(Deck& deck);

    /**************************************************************************************************
     * <summary>Give card to player.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="player">[in,out] The player.</param>
     **************************************************************************************************/
    void GiveCardToPlayer(Player& player);

    /**************************************************************************************************
     * <summary>Take card from player.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="player">[in,out] The player.</param>
     * <param name="card">  The card.</param>
     **************************************************************************************************/
    void TakeCardFromPlayer(Player& player, const Card& card);

    /**************************************************************************************************
     * <summary>Combine decks.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="deck1">[in,out] The first deck.</param>
     * <param name="deck2">[in,out] The second deck.</param>
     **************************************************************************************************/
    void CombineDecks(Deck& deck1, Deck& deck2);

    /**************************************************************************************************
     * <summary>Gets the deck.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>The deck.</returns>
     **************************************************************************************************/
    Deck& GetDeck() const;

    /**************************************************************************************************
     * <summary>Gets the deck.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>The deck.</returns>
     **************************************************************************************************/
    Deck& GetDeck();

    /**************************************************************************************************
     * <summary>Gets discard deck.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>The discard deck.</returns>
     **************************************************************************************************/
    Deck& GetDiscardDeck() const;

    /**************************************************************************************************
     * <summary>Gets discard deck.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>The discard deck.</returns>
     **************************************************************************************************/
    Deck& GetDiscardDeck();

    /**************************************************************************************************
     * <summary>Deals.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="d">            [in,out] The Dealer to process.</param>
     * <param name="players">      [in,out] The players.</param>
     * <param name="max_hand_size">Size of the maximum hand.</param>
     **************************************************************************************************/
    static void Deal(Dealer& d, std::vector<Player>& players, unsigned int max_hand_size);

    /**************************************************************************************************
     * <summary>Take cards from players.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="d">      [in,out] The Dealer to process.</param>
     * <param name="players">[in,out] The players.</param>
     **************************************************************************************************/
    static void TakeCardsFromPlayers(Dealer& d, std::vector<Player>& players);
protected:

    /**************************************************************************************************
     * <summary>Adds a card to deck to 'card'.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="deck">[in,out] The deck.</param>
     * <param name="card">The card.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    bool AddCardToDeck(Deck& deck, const Card& card);

    /**************************************************************************************************
     * <summary>Removes the card from deck described by deck.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="deck">[in,out] The deck.</param>
     * <returns>A Card.</returns>
     **************************************************************************************************/
    Card RemoveCardFromDeck(Deck& deck);
private:
    /** <summary>The random device.</summary> */
    std::random_device _rd;
    /** <summary>The random number generator.</summary> */
    std::mt19937 _rng;
    /** <summary>The play deck.</summary> */
    Deck _play_deck;
    /** <summary>The discard deck.</summary> */
    Deck _discard_deck;

};


#endif