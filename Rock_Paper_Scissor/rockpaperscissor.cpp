#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(0)); // Seed for random number generation

    std::string choices[] = {"Rock", "Paper", "Scissors"};
    int computerChoice = rand() % 3; // Random number between 0 and 2

    std::cout << "Enter your choice (Rock, Paper, Scissors): ";
    std::string userChoice;
    std::cin >> userChoice;

    std::cout << "Computer chose: " << choices[computerChoice] << std::endl;

    if (userChoice == choices[computerChoice]) {
        std::cout << "It's a tie!" << std::endl;
    } else if ((userChoice == "Rock" && choices[computerChoice] == "Scissors") ||
               (userChoice == "Paper" && choices[computerChoice] == "Rock") ||
               (userChoice == "Scissors" && choices[computerChoice] == "Paper")) {
        std::cout << "You win!" << std::endl;
    } else {
        std::cout << "Computer wins!" << std::endl;
    }

    return 0;
}
