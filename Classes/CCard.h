#ifndef POKER_CCARD_H
#define POKER_CCARD_H

#include <iostream>
#include "cardvalues.h"


class Card {
public:

    Card();
    Card(const cardvalue::face& face, const cardvalue::suit& suit);
    Card(const Card& other);
    Card& operator=(const Card& rhs);

    uint8_t GetValue() const;
    uint8_t GetValue();

    uint8_t GetFace() const;
    uint8_t GetFace();

    uint8_t GetSuit() const;
    uint8_t GetSuit();

    bool operator==(const Card& rhs);
    bool operator!=(const Card& rhs);

    bool operator<(const Card& rhs);
    bool operator>(const Card& rhs);

    bool operator<=(const Card& rhs);
    bool operator>=(const Card& rhs);

protected:
    void SetValue(uint8_t value);
    void SetSuit(cardvalue::suit suit);
    void SetFace(cardvalue::face face);
private:
    /// <summary> The value of a card stored in an 8-bit unsigned integer high nibble is the face, the low nibble is the suit.</summary>
    uint8_t _value;
};

#endif