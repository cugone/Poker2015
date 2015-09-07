#ifndef POKER_CPLAYER_H
#define POKER_CPLAYER_H

class Card;

#include "CHand.h"


class Player {
public:
    Player();

    const Hand& GetHand() const;
    Hand& GetHand();

    bool AddCardToHand(const Card& c);
    bool RemoveCardFromHand(const Card& c);
    void CalculateHandValue();

protected:
private:
    Hand _hand;
};

#endif