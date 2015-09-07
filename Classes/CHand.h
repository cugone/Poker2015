#ifndef POKER_CHAND_H
#define POKER_CHAND_H

#include "HandValues.h"
#include "CCard.h"

#include <vector>
#include <cstdint>

class Hand {
public:

    Hand();
    Hand(const Hand& other);

    Hand& operator=(const Hand& rhs);

    bool operator==(const Hand& rhs);
    bool operator!=(const Hand& rhs);
    bool operator<(const Hand& rhs);
    bool operator>=(const Hand& rhs);
    bool operator>(const Hand& rhs);
    bool operator<=(const Hand& rhs);

    uint32_t GetValue() const;
    uint32_t GetValue();

    hand::type GetHandType() const;
    hand::type GetHandType();

    bool AddCard(const Card& c);
    bool RemoveCard(const Card& c);

    bool IsPair() const;
    bool IsPair();

    bool IsTwoPair() const;
    bool IsTwoPair();

    bool IsThreeOfAKind() const;
    bool IsThreeOfAKind();

    bool IsStraight() const;
    bool IsStraight();

    bool IsFlush() const;
    bool IsFlush();

    bool IsFullHouse() const;
    bool IsFullHouse();

    bool IsFourOfAKind() const;
    bool IsFourOfAKind();

    bool IsStraightFlush() const;
    bool IsStraightFlush();

    std::size_t size() const;
    std::size_t size();

    bool empty() const;
    bool empty();

    std::vector<Card>::const_iterator begin() const;
    std::vector<Card>::iterator begin();

    std::vector<Card>::const_iterator end() const;
    std::vector<Card>::iterator end();

    const Card& GetCardAt(std::size_t index) const;
    Card& GetCardAt(std::size_t index);

    void CalculateValue();

protected:
    void CalculateFaceFrequency();
    void CalculateFaceDistribution();
    void CalculateSuitFrequency();
    Card CalculateHighCard();

    Card GetHighCard() const;
    Card GetHighCard();

    void SetValue(uint32_t v);
    void SetHighCard(const Card& c);

    void SortHand();

private:
    std::vector<Card> _cards;
    //_value is a 16-bit unsigned integer where left-to-right bits are: [31-24] hand type, [23-16] high card
    uint16_t _value;
    std::vector<uint8_t> _faceFrequency;
    std::vector<uint8_t> _suitFrequency;
    std::vector<uint8_t> _faceDistribution;
    
};

#endif