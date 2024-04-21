#include <iostream>
#include <map>
#include <string>

std::map<std::string, std::string> phonebook;

void addContact() {
    std::string name, number;
    std::cout << "Enter contact name: ";
    std::cin >> name;
    std::cout << "Enter contact number: ";
    std::cin >> number;
    phonebook[name] = number;
    std::cout << "Contact added successfully!" << std::endl;
}

void searchContact() {
    std::string name;
    std::cout << "Enter contact name to search: ";
    std::cin >> name;
    auto it = phonebook.find(name);
    if (it != phonebook.end()) {
        std::cout << "Contact found - " << it->first << ": " << it->second << std::endl;
    } else {
        std::cout << "Contact not found." << std::endl;
    }
}

void displayPhonebook() {
    if (phonebook.empty()) {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }
    std::cout << "Phonebook:" << std::endl;
    for (const auto& contact : phonebook) {
        std::cout << contact.first << ": " << contact.second << std::endl;
    }
}

int main() {
    int choice;
    do {
        std::cout << "\nPhonebook App:" << std::endl;
        std::cout << "1. Add Contact" << std::endl;
        std::cout << "2. Search Contact" << std::endl;
        std::cout << "3. Display Phonebook" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                displayPhonebook();
                break;
            case 4:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
