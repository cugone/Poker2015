/*******************************************************************************
* solution: Poker
* project:  Poker
* file:     Classes\CDeck.cpp
* author:   Casey Ugone
* summary:  Implements the deck class
*           Copyright (c) 2015 Blisspoint Softworks. All rights reserved.
*
*******************************************************************************/
#include "CDeck.h"

Deck::Deck() : _cards() { }

Deck::Deck(unsigned int size) : _cards(size) { }

Deck::Deck(std::vector<Card> cards) : _cards(cards) { }

Deck::Deck(const Deck& other) : _cards(other._cards) { }

Deck& Deck::operator=(const Deck& rhs) {
    if(this == &rhs) return *this;
    this->_cards = rhs._cards;
    return *this;
}

bool Deck::AddCard(const Card& card) {
    try {
        _cards.push_back(card);
    } catch(...) {
        return false;
    }
    return true;
}

Card Deck::RemoveCard() {
    Card last(_cards.back());
    _cards.pop_back();
    return last;
}

Deck::CardContainerConstIterator Deck::begin() const {
    return std::begin(_cards);
}

Deck::CardContainerConstIterator Deck::end() const {
    return std::end(_cards);
}

Deck::CardContainerIterator Deck::begin() {
    return std::begin(_cards);
}

Deck::CardContainerIterator Deck::end() {
    return std::end(_cards);
}

std::size_t Deck::Size() const {
    return _cards.size();
}

std::size_t Deck::Size() {
    return static_cast<const Deck&>(*this).Size();
}

bool Deck::InitializeStandardDeck() {

    _cards.clear();
    for(int s = 0; s < 4; ++s) {
        cardvalue::suit curSuit = static_cast<cardvalue::suit>(static_cast<uint8_t>(std::exp2(s)));
        for(int f = 2; f <= 14; ++f) {
            cardvalue::face curFace = static_cast<cardvalue::face>(f << 4);
            this->AddCard(Card(curFace, curSuit));
        }
    }
    return true;
}

bool Deck::Empty() const {
    return _cards.empty();
}

bool Deck::Empty() {
    return static_cast<const Deck&>(*this).Empty();
}

bool AddCard(Deck& deck, const Card& card) {
    return deck.AddCard(card);
}

Card RemoveCard(Deck& deck) {
    return deck.RemoveCard();
}

