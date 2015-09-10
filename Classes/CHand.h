/*******************************************************************************
* solution: Poker
* project:  Poker
* file:     Classes\CHand.h
* author:   Casey Ugone
* summary:  Declares the hand class
*           Copyright (c) 2015 Blisspoint Softworks. All rights reserved.
*
*******************************************************************************/
#ifndef POKER_CHAND_H
#define POKER_CHAND_H

#include "HandValues.h"
#include "CCard.h"

#include <vector>
#include <cstdint>

/**************************************************************************************************
 * <summary>A hand.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 **************************************************************************************************/
class Hand {
public:

    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     **************************************************************************************************/
    Hand();

    /**************************************************************************************************
     * <summary>Copy constructor.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="other">The other.</param>
     **************************************************************************************************/
    Hand(const Hand& other);

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A shallow copy of this Hand.</returns>
     **************************************************************************************************/
    Hand& operator=(const Hand& rhs);

    /**************************************************************************************************
     * <summary>Equality operator.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the parameters are considered equivalent.</returns>
     **************************************************************************************************/
    bool operator==(const Hand& rhs);

    /**************************************************************************************************
     * <summary>Inequality operator.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the parameters are not considered equivalent.</returns>
     **************************************************************************************************/
    bool operator!=(const Hand& rhs);

    /**************************************************************************************************
     * <summary>Less-than comparison operator.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the first parameter is less than the second.</returns>
     **************************************************************************************************/
    bool operator<(const Hand& rhs);

    /**************************************************************************************************
     * <summary>Greater-than-or-equal comparison operator.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the first parameter is greater than or equal to the second.</returns>
     **************************************************************************************************/
    bool operator>=(const Hand& rhs);

    /**************************************************************************************************
     * <summary>Greater-than comparison operator.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the first parameter is greater than to the second.</returns>
     **************************************************************************************************/
    bool operator>(const Hand& rhs);

    /**************************************************************************************************
     * <summary>Less-than-or-equal comparison operator.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the first parameter is less than or equal to the second.</returns>
     **************************************************************************************************/
    bool operator<=(const Hand& rhs);

    /**************************************************************************************************
     * <summary>Gets the value.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>The value.</returns>
     **************************************************************************************************/
    uint32_t GetValue() const;

    /**************************************************************************************************
     * <summary>Gets the value.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>The value.</returns>
     **************************************************************************************************/
    uint32_t GetValue();

    /**************************************************************************************************
     * <summary>Gets hand type.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>The hand type.</returns>
     **************************************************************************************************/
    hand::type GetHandType() const;

    /**************************************************************************************************
     * <summary>Gets hand type.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>The hand type.</returns>
     **************************************************************************************************/
    hand::type GetHandType();

    /**************************************************************************************************
     * <summary>Adds a card.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="c">The Card to process.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    bool AddCard(const Card& c);

    /**************************************************************************************************
     * <summary>Removes the card described by c.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="c">The Card to process.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    bool RemoveCard(const Card& c);

    /**************************************************************************************************
     * <summary>Query if this Hand is pair.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>true if pair, false if not.</returns>
     **************************************************************************************************/
    bool IsPair() const;

    /**************************************************************************************************
     * <summary>Query if this Hand is pair.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>true if pair, false if not.</returns>
     **************************************************************************************************/
    bool IsPair();

    /**************************************************************************************************
     * <summary>Query if this Hand is two pair.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>true if two pair, false if not.</returns>
     **************************************************************************************************/
    bool IsTwoPair() const;

    /**************************************************************************************************
     * <summary>Query if this Hand is two pair.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>true if two pair, false if not.</returns>
     **************************************************************************************************/
    bool IsTwoPair();

    /**************************************************************************************************
     * <summary>Query if this Hand is three of a kind.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>true if three of a kind, false if not.</returns>
     **************************************************************************************************/
    bool IsThreeOfAKind() const;

    /**************************************************************************************************
     * <summary>Query if this Hand is three of a kind.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>true if three of a kind, false if not.</returns>
     **************************************************************************************************/
    bool IsThreeOfAKind();

    /**************************************************************************************************
     * <summary>Query if this Hand is straight.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>true if straight, false if not.</returns>
     **************************************************************************************************/
    bool IsStraight() const;

    /**************************************************************************************************
     * <summary>Query if this Hand is straight.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>true if straight, false if not.</returns>
     **************************************************************************************************/
    bool IsStraight();

    /**************************************************************************************************
     * <summary>Query if this Hand is flush.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>true if flush, false if not.</returns>
     **************************************************************************************************/
    bool IsFlush() const;

    /**************************************************************************************************
     * <summary>Query if this Hand is flush.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>true if flush, false if not.</returns>
     **************************************************************************************************/
    bool IsFlush();

    /**************************************************************************************************
     * <summary>Query if this Hand is full house.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>true if full house, false if not.</returns>
     **************************************************************************************************/
    bool IsFullHouse() const;

    /**************************************************************************************************
     * <summary>Query if this Hand is full house.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>true if full house, false if not.</returns>
     **************************************************************************************************/
    bool IsFullHouse();

    /**************************************************************************************************
     * <summary>Query if this Hand is four of a kind.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>true if four of a kind, false if not.</returns>
     **************************************************************************************************/
    bool IsFourOfAKind() const;

    /**************************************************************************************************
     * <summary>Query if this Hand is four of a kind.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>true if four of a kind, false if not.</returns>
     **************************************************************************************************/
    bool IsFourOfAKind();

    /**************************************************************************************************
     * <summary>Query if this Hand is straight flush.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>true if straight flush, false if not.</returns>
     **************************************************************************************************/
    bool IsStraightFlush() const;

    /**************************************************************************************************
     * <summary>Query if this Hand is straight flush.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>true if straight flush, false if not.</returns>
     **************************************************************************************************/
    bool IsStraightFlush();

    /**************************************************************************************************
     * <summary>Gets the size.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>A std::size_t.</returns>
     **************************************************************************************************/
    std::size_t size() const;

    /**************************************************************************************************
     * <summary>Gets the size.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>A std::size_t.</returns>
     **************************************************************************************************/
    std::size_t size();

    /**************************************************************************************************
     * <summary>Query if this Hand is empty.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>true if it is, false if not.</returns>
     **************************************************************************************************/
    bool empty() const;

    /**************************************************************************************************
     * <summary>Query if this Hand is empty.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>true if it is, false if not.</returns>
     **************************************************************************************************/
    bool empty();

    /**************************************************************************************************
     * <summary>Gets the beginning iterator.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>A std::vector&lt;Card&gt;::const_iterator.</returns>
     **************************************************************************************************/
    std::vector<Card>::const_iterator begin() const;

    /**************************************************************************************************
     * <summary>Gets the beginning iterator.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>A std::vector&lt;Card&gt;::iterator.</returns>
     **************************************************************************************************/
    std::vector<Card>::iterator begin();

    /**************************************************************************************************
     * <summary>Gets the iterator one past the end.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>A std::vector&lt;Card&gt;::const_iterator.</returns>
     **************************************************************************************************/
    std::vector<Card>::const_iterator end() const;

    /**************************************************************************************************
     * <summary>Gets the iterator one past the end.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>A std::vector&lt;Card&gt;::iterator.</returns>
     **************************************************************************************************/
    std::vector<Card>::iterator end();

    /**************************************************************************************************
     * <summary>Gets card at the specified position.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="index">Zero-based index of the card to get.</param>
     * <returns>The card at the given index.</returns>
     **************************************************************************************************/
    const Card& GetCardAt(std::size_t index) const;

    /**************************************************************************************************
     * <summary>Gets card at the specified position.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="index">Zero-based index of the card to get.</param>
     * <returns>The card at the given index.</returns>
     **************************************************************************************************/
    Card& GetCardAt(std::size_t index);

    /**************************************************************************************************
     * <summary>Calculates the value.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     **************************************************************************************************/
    void CalculateValue();

protected:

    /**************************************************************************************************
     * <summary>Calculates the face frequency.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     **************************************************************************************************/
    void CalculateFaceFrequency();

    /**************************************************************************************************
     * <summary>Calculates the face distribution.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     **************************************************************************************************/
    void CalculateFaceDistribution();

    /**************************************************************************************************
     * <summary>Calculates the suit frequency.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     **************************************************************************************************/
    void CalculateSuitFrequency();

    /**************************************************************************************************
     * <summary>Calculates the high card.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>The calculated high card.</returns>
     **************************************************************************************************/
    Card CalculateHighCard();

    /**************************************************************************************************
     * <summary>Gets high card.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>The high card.</returns>
     **************************************************************************************************/
    Card GetHighCard() const;

    /**************************************************************************************************
     * <summary>Gets high card.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <returns>The high card.</returns>
     **************************************************************************************************/
    Card GetHighCard();

    /**************************************************************************************************
     * <summary>Sets the hand value.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="v">The uint32_t to process.</param>
     **************************************************************************************************/
    void SetValue(uint32_t v);

    /**************************************************************************************************
     * <summary>Sets high card.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="c">The Card to process.</param>
     **************************************************************************************************/
    void SetHighCard(const Card& c);

    /**************************************************************************************************
     * <summary>Sort hand.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     **************************************************************************************************/
    void SortHand();

private:
    /** <summary>The cards.</summary> */
    std::vector<Card> _cards;
    /** <summary>The value is a 16-bit unsigned integer where left-to-right bits are: [15-9] hand type, [8-0] high card.</summary> */
    uint16_t _value;
    /** <summary>The face frequency.</summary> */
    std::vector<uint8_t> _faceFrequency;
    /** <summary>The suit frequency.</summary> */
    std::vector<uint8_t> _suitFrequency;
    /** <summary>The face distribution.</summary> */
    std::vector<uint8_t> _faceDistribution;
    
 /** <summary>.</summary> */
};

#endif