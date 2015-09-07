#ifndef POKER_CDECK_H
#define POKER_CDECK_H

#include <vector>
#include <cstdint>
#include "CCard.h"

class Deck {
public:

    typedef std::vector<Card> CardContainer;
    typedef CardContainer::iterator CardContainerIterator;
    typedef CardContainer::const_iterator CardContainerConstIterator;

    Deck();
    Deck(unsigned int size);
    Deck(std::vector<Card> cards);
    Deck(const Deck& other);

    Deck& operator=(const Deck& rhs);

    CardContainerConstIterator begin() const;
    CardContainerConstIterator end() const;
    CardContainerIterator begin();
    CardContainerIterator end();

    bool AddCard(const Card& card);
    Card RemoveCard();
    std::size_t Size() const;
    std::size_t Size();
    bool Empty() const;
    bool Empty();

    bool InitializeStandardDeck();
    
protected:

private:
    CardContainer _cards;

};

bool AddCard(Deck& deck, const Card& card);
Card RemoveCard(Deck& deck);

#endif