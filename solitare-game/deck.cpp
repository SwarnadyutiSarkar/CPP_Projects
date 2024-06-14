#include "Deck.h"
#include <algorithm>
#include <random>
#include <ctime>

Deck::Deck() {
    initializeDeck();
    shuffle();
}

void Deck::initializeDeck() {
    cards.clear();
    for (int suit = HEARTS; suit <= SPADES; ++suit) {
        for (int rank = TWO; rank <= ACE; ++rank) {
            cards.push_back(Card(static_cast<Suit>(suit), static_cast<Rank>(rank)));
        }
    }
}

void Deck::shuffle() {
    static std::mt19937 rng(std::time(nullptr));
    std::shuffle(cards.begin(), cards.end(), rng);
}

Card Deck::drawCard() {
    Card topCard = cards.back();
    cards.pop_back();
    return topCard;
}

bool Deck::isEmpty() const {
    return cards.empty();
}
