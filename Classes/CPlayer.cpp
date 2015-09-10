/*******************************************************************************
* solution: Poker
* project:  Poker
* file:     Classes\CPlayer.cpp
* author:   Casey Ugone
* summary:  Implements the player class
*           Copyright (c) 2015 Blisspoint Softworks. All rights reserved.
*
*******************************************************************************/
#include "CPlayer.h"

#include "CCard.h"

#include <iomanip>

Player::Player() : _hand(Hand()) { }

const Hand& Player::GetHand() const {
    return _hand;
}

Hand& Player::GetHand() {
    return const_cast<Hand&>(static_cast<const Player&>(*this).GetHand());
}

bool Player::AddCardToHand(const Card& c) {
    if(_hand.size() == 5) return false;
    return _hand.AddCard(c);
}

bool Player::RemoveCardFromHand(const Card& c) {
    if(_hand.empty()) return false;
    return _hand.RemoveCard(c);
}

void Player::CalculateHandValue() {
    _hand.CalculateValue();
}

void Player::DisplayHand(std::ostream& os) const {

    std::string FaceValues[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
    char SuitValues[] = { 'C', 'D', 'H', 'S' };

    for(const auto& c : _hand) {
        os << std::setw(3) << FaceValues[((c.GetFace() >> 4) - 2)];
        os << SuitValues[static_cast<uint8_t>(std::log2(c.GetSuit()))];
    }
    os << '\n';
    os.flush();

}