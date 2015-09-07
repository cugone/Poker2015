#ifndef POKER_CDEALER_H
#define POKER_CDEALER_H

#include <random>

#include "CDeck.h"

class Player;
class Card;

class Dealer {

public:

    Dealer();
    void ShuffleDeck(Deck& deck);
    void CutDeck(Deck& deck);
    void GiveCardToPlayer(Player& player);
    void TakeCardFromPlayer(Player& player, const Card& card);
    void CombineDecks(Deck& deck1, Deck& deck2);

    Deck& GetDeck() const;
    Deck& GetDeck();

    Deck& GetDiscardDeck() const;
    Deck& GetDiscardDeck();

    static void Deal(Dealer& d, std::vector<Player>& players, unsigned int max_hand_size);
    static void TakeCardsFromPlayers(Dealer& d, std::vector<Player>& players);
protected:
    bool AddCardToDeck(Deck& deck, const Card& card);
    Card RemoveCardFromDeck(Deck& deck);
private:
    std::random_device _rd;
    std::mt19937 _rng;
    Deck _play_deck;
    Deck _discard_deck;
};


#endif