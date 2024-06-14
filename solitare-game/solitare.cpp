#include "Solitaire.h"
#include <iostream>

Solitaire::Solitaire() {
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j <= i; ++j) {
            tableau[i].push_back(deck.drawCard());
        }
    }
}

void Solitaire::play() {
    char choice;
    do {
        displayBoard();
        std::cout << "Choose an action: (d)raw from deck, (m)ove card, (q)uit: ";
        std::cin >> choice;
        switch (choice) {
            case 'd':
                drawFromDeck();
                break;
            case 'm':
                moveCard();
                break;
            case 'q':
                std::cout << "Quitting game.\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != 'q');
}

void Solitaire::displayBoard() {
    std::cout << "\nTableau:\n";
    for (int i = 0; i < 7; ++i) {
        std::cout << "Pile " << i + 1 << ": ";
        for (const Card &card : tableau[i]) {
            std::cout << card.toString() << ", ";
        }
        std::cout << "\n";
    }
    std::cout << "Draw Pile: " << (drawPile.empty() ? "Empty" : "Not Empty") << "\n";
}

void Solitaire::moveCard() {
    int fromPile, toPile;
    std::cout << "Enter source pile (1-7): ";
    std::cin >> fromPile;
    std::cout << "Enter destination pile (1-7): ";
    std::cin >> toPile;

    if (fromPile < 1 || fromPile > 7 || toPile < 1 || toPile > 7) {
        std::cout << "Invalid pile number.\n";
        return;
    }

    if (tableau[fromPile - 1].empty()) {
        std::cout << "Source pile is empty.\n";
        return;
    }

    Card movingCard = tableau[fromPile - 1].back();
    tableau[fromPile - 1].pop_back();
    tableau[toPile - 1].push_back(movingCard);
}

void Solitaire::drawFromDeck() {
    if (deck.isEmpty()) {
        std::cout << "Deck is empty.\n";
    } else {
        drawPile.push_back(deck.drawCard());
    }
}
