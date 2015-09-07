#include "CPlayer.h"

#include "CCard.h"

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