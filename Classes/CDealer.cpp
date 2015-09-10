/*******************************************************************************
* solution: Poker
* project:  Poker
* file:     Classes\CDealer.cpp
* author:   Casey Ugone
* summary:  Implements the dealer class
*           Copyright (c) 2015 Blisspoint Softworks. All rights reserved.
*
*******************************************************************************/
#include "CDealer.h"

#include "CPlayer.h"
#include "CCard.h"

#include <algorithm>

Dealer::Dealer() : _rd(), _rng(_rd()), _play_deck(), _discard_deck() {
    _play_deck.InitializeStandardDeck();
}


void Dealer::ShuffleDeck(Deck& deck) {
    //Only 7 shuffles needed to consider "true" randomness.
    std::shuffle(std::begin(deck), std::end(deck), _rng);
    std::shuffle(std::begin(deck), std::end(deck), _rng);
    std::shuffle(std::begin(deck), std::end(deck), _rng);
    std::shuffle(std::begin(deck), std::end(deck), _rng);
    std::shuffle(std::begin(deck), std::end(deck), _rng);
    std::shuffle(std::begin(deck), std::end(deck), _rng);
    std::shuffle(std::begin(deck), std::end(deck), _rng);
}

bool Dealer::AddCardToDeck(Deck& deck, const Card& card) {
    return AddCard(deck, card);
}

Card Dealer::RemoveCardFromDeck(Deck& deck) {
    return RemoveCard(deck);
}

void Dealer::GiveCardToPlayer(Player& player) {
    Card c = RemoveCardFromDeck(_play_deck);
    player.AddCardToHand(c);
}

void Dealer::Deal(Dealer& d, std::vector<Player>& players, unsigned int max_hand_size) {
    for(decltype(max_hand_size) i = 0; i < max_hand_size; ++i) {
        for(auto& p : players) {
            d.GiveCardToPlayer(p);
        }
    }
}

void Dealer::TakeCardsFromPlayers(Dealer& d, std::vector<Player>& players) {
    for(auto& p : players) {
        auto& cur_hand = p.GetHand();
        while(cur_hand.empty() == false) {
            auto i = cur_hand.size() - 1;
            d.TakeCardFromPlayer(p, cur_hand.GetCardAt(i));
        }
    }
}

void Dealer::TakeCardFromPlayer(Player& player, const Card& card) {
    if(player.RemoveCardFromHand(card)) AddCardToDeck(_discard_deck, card);
}

void Dealer::CombineDecks(Deck& deck1, Deck& deck2) {
    while(deck2.Size() > 0) {
        deck1.AddCard(deck2.RemoveCard());
    }
}

void Dealer::CutDeck(Deck& deck) {
    /* DO NOTHING */
}

Deck& Dealer::GetDeck() const {
    return const_cast<Deck&>(_play_deck);
}

Deck& Dealer::GetDeck() {
    return static_cast<const Dealer&>(*this).GetDeck();
}

Deck& Dealer::GetDiscardDeck() const {
    return const_cast<Deck&>(_discard_deck);
}

Deck& Dealer::GetDiscardDeck() {
    return static_cast<const Dealer&>(*this).GetDiscardDeck();
}
