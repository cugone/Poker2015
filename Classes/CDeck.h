/*******************************************************************************
* solution: Poker
* project:  Poker
* file:     Classes\CDeck.h
* author:   Casey Ugone
* summary:  Declares the deck class
*           Copyright (c) 2015 Blisspoint Softworks. All rights reserved.
*
*******************************************************************************/
#ifndef POKER_CDECK_H
#define POKER_CDECK_H

#include <vector>
#include <cstdint>
#include "CCard.h"

/**************************************************************************************************
 * <summary>A deck.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 **************************************************************************************************/
class Deck {
public:

    /**************************************************************************************************
     * <summary>Defines an alias representing the card container.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     **************************************************************************************************/
    typedef std::vector<Card> CardContainer;

    /**************************************************************************************************
     * <summary>Defines an alias representing the card container iterator.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     **************************************************************************************************/
    typedef CardContainer::iterator CardContainerIterator;

    /**************************************************************************************************
     * <summary>Defines an alias representing the card container constant iterator.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     **************************************************************************************************/
    typedef CardContainer::const_iterator CardContainerConstIterator;

    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     **************************************************************************************************/
    Deck();

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="size">The size.</param>
     **************************************************************************************************/
    Deck(unsigned int size);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="cards">The cards.</param>
     **************************************************************************************************/
    Deck(std::vector<Card> cards);

    /**************************************************************************************************
     * <summary>Copy constructor.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="other">The other.</param>
     **************************************************************************************************/
    Deck(const Deck& other);

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A shallow copy of this Deck.</returns>
     **************************************************************************************************/
    Deck& operator=(const Deck& rhs);

    /**************************************************************************************************
     * <summary>Gets the beginning iterator.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>A CardContainerConstIterator.</returns>
     **************************************************************************************************/
    CardContainerConstIterator begin() const;

    /**************************************************************************************************
     * <summary>Gets the iterator one past the end.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>A CardContainerConstIterator.</returns>
     **************************************************************************************************/
    CardContainerConstIterator end() const;

    /**************************************************************************************************
     * <summary>Gets the beginning iterator.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>A CardContainerIterator.</returns>
     **************************************************************************************************/
    CardContainerIterator begin();

    /**************************************************************************************************
     * <summary>Gets the iterator one past the end.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>A CardContainerIterator.</returns>
     **************************************************************************************************/
    CardContainerIterator end();

    /**************************************************************************************************
     * <summary>Adds a card.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="card">The card.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    bool AddCard(const Card& card);

    /**************************************************************************************************
     * <summary>Removes a card.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>The card that was removed.</returns>
     **************************************************************************************************/
    Card RemoveCard();

    /**************************************************************************************************
     * <summary>Gets the size.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>A std::size_t.</returns>
     **************************************************************************************************/
    std::size_t Size() const;

    /**************************************************************************************************
     * <summary>Gets the size.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>A std::size_t.</returns>
     **************************************************************************************************/
    std::size_t Size();

    /**************************************************************************************************
     * <summary>Query if this Deck is empty.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>true if it is, false if not.</returns>
     **************************************************************************************************/
    bool Empty() const;

    /**************************************************************************************************
     * <summary>Query if this Deck is empty.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>true if it is, false if not.</returns>
     **************************************************************************************************/
    bool Empty();

    /**************************************************************************************************
     * <summary>Initializes the standard deck.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    bool InitializeStandardDeck();
    
protected:

private:
    /** <summary>The cards.</summary> */
    CardContainer _cards;

};

/**************************************************************************************************
 * <summary>Adds a card to 'card'.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 * <param name="deck">[in,out] The deck.</param>
 * <param name="card">The card.</param>
 * <returns>true if it succeeds, false if it fails.</returns>
 **************************************************************************************************/
bool AddCard(Deck& deck, const Card& card);

/**************************************************************************************************
 * <summary>Removes the card described by deck.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 * <param name="deck">[in,out] The deck.</param>
 * <returns>A Card.</returns>
 **************************************************************************************************/
Card RemoveCard(Deck& deck);

#endif