#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

std::vector<std::string> words = {"apple", "banana", "cherry", "orange", "grape"};
const int MAX_TRIES = 6;

std::string chooseWord() {
    srand(time(0));
    int randomIndex = rand() % words.size();
    return words[randomIndex];
}

void displayWord(const std::string& word, const std::vector<bool>& guessed) {
    for (size_t i = 0; i < word.length(); ++i) {
        if (guessed[i]) {
            std::cout << word[i] << " ";
        } else {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}

bool checkGuess(const std::string& word, char guess, std::vector<bool>& guessed) {
    bool correct = false;
    for (size_t i = 0; i < word.length(); ++i) {
        if (word[i] == guess) {
            guessed[i] = true;
            correct = true;
        }
    }
    return correct;
}

int main() {
    std::string word = chooseWord();
    std::vector<bool> guessed(word.length(), false);
    int tries = 0;

    std::cout << "Welcome to Hangman!" << std::endl;

    while (tries < MAX_TRIES) {
        displayWord(word, guessed);
        std::cout << "Enter a letter guess: ";
        char guess;
        std::cin >> guess;

        if (checkGuess(word, guess, guessed)) {
            std::cout << "Correct guess!" << std::endl;
        } else {
            std::cout << "Incorrect guess!" << std::endl;
            ++tries;
        }

        bool allGuessed = true;
        for (bool g : guessed) {
            if (!g) {
                allGuessed = false;
                break;
            }
        }

        if (allGuessed) {
            std::cout << "Congratulations! You guessed the word." << std::endl;
            break;
        }
    }

    if (tries == MAX_TRIES) {
        std::cout << "Sorry, you ran out of tries. The word was: " << word << std::endl;
    }

    return 0;
}
