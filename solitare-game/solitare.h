#ifndef SOLITAIRE_H
#define SOLITAIRE_H

#include "Deck.h"
#include <vector>

class Solitaire {
public:
    Solitaire();
    void play();
    void displayBoard();
    void moveCard();
    void drawFromDeck();

private:
    Deck deck;
    std::vector<Card> tableau[7]; // Simplified for a basic example
    std::vector<Card> foundation[4]; // Simplified for a basic example
    std::vector<Card> drawPile;
};

#endif // SOLITAIRE_H
