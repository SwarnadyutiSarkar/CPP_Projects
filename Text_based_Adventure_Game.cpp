#include <iostream>
#include <string>

void forest() {
    std::cout << "You are in a dark forest." << std::endl;
    std::cout << "There are two paths ahead. Left or Right?" << std::endl;

    std::string choice;
    std::cin >> choice;

    if (choice == "left") {
        std::cout << "You encountered a troll. Game Over!" << std::endl;
    } else if (choice == "right") {
        std::cout << "You found a treasure chest. You win!" << std::endl;
    } else {
        std::cout << "Invalid choice!" << std::endl;
    }
}

int main() {
    std::cout << "Welcome to the Text-based Adventure Game!" << std::endl;
    forest();

    return 0;
}
