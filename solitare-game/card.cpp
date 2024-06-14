#include "Card.h"

Card::Card(Suit suit, Rank rank) : suit(suit), rank(rank) {}

std::string Card::toString() const {
    const std::string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const std::string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

    return ranks[rank] + " of " + suits[suit];
}

Suit Card::getSuit() const {
    return suit;
}

Rank Card::getRank() const {
    return rank;
}
