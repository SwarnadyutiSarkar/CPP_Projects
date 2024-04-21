#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(0)); // Seed for random number generation

    int secretNumber = rand() % 100 + 1; // Random number between 1 and 100
    int guess;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;

    do {
        std::cout << "Enter your guess (1-100): ";
        std::cin >> guess;
        attempts++;

        if (guess < secretNumber) {
            std::cout << "Too low!" << std::endl;
        } else if (guess > secretNumber) {
            std::cout << "Too high!" << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number in " << attempts << " attempts." << std::endl;
        }
    } while (guess != secretNumber);

    return 0;
}
