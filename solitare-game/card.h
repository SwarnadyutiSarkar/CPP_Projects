#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

enum Suit {
    HEARTS,
    DIAMONDS,
    CLUBS,
    SPADES
};

enum Rank {
    TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
};

class Card {
public:
    Card(Suit suit, Rank rank);
    std::string toString() const;
    Suit getSuit() const;
    Rank getRank() const;

private:
    Suit suit;
    Rank rank;
};

#endif // CARD_H
