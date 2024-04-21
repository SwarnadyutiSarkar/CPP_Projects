#include <iostream>
#include <unordered_map>
#include <string>

std::unordered_map<std::string, std::string> users;

void registerUser() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    users[username] = password;
    std::cout << "Registration successful!" << std::endl;
}

void loginUser() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    if (users.find(username) != users.end() && users[username] == password) {
        std::cout << "Login successful!" << std::endl;
    } else {
        std::cout << "Invalid username or password!" << std::endl;
    }
}

int main() {
    int choice;
    do {
        std::cout << "1. Register\n2. Login\n3. Exit\n";
        std::cin >> choice;
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                std::cout << "Exiting...";
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
                break;
        }
    } while (choice != 3);

    return 0;
}
