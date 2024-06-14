#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

class Deck {
public:
    Deck();
    void shuffle();
    Card drawCard();
    bool isEmpty() const;

private:
    std::vector<Card> cards;
    void initializeDeck();
};

#endif // DECK_H
