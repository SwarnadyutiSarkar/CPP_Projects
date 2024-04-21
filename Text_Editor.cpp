#include <iostream>
#include <fstream>
#include <string>

void displayMenu() {
    std::cout << "Text Editor Menu:" << std::endl;
    std::cout << "1. Create a new file" << std::endl;
    std::cout << "2. Open an existing file" << std::endl;
    std::cout << "3. Save current file" << std::endl;
    std::cout << "4. Exit" << std::endl;
}

void createFile() {
    std::string fileName;
    std::cout << "Enter the name of the new file: ";
    std::cin >> fileName;
    std::ofstream file(fileName);
    if (file.is_open()) {
        std::cout << "File created successfully!" << std::endl;
        file.close();
    } else {
        std::cout << "Error creating file." << std::endl;
    }
}

void openFile() {
    std::string fileName, line;
    std::cout << "Enter the name of the file to open: ";
    std::cin >> fileName;
    std::ifstream file(fileName);
    if (file.is_open()) {
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cout << "Error opening file." << std::endl;
    }
}

void saveFile() {
    std::string fileName, content;
    std::cout << "Enter the name of the file to save: ";
    std::cin >> fileName;
    std::ofstream file(fileName);
    if (file.is_open()) {
        std::cout << "Enter the content to save (end with 'exit'): " << std::endl;
        while (true) {
            getline(std::cin, content);
            if (content == "exit") {
                break;
            }
            file << content << std::endl;
        }
        file.close();
    } else {
        std::cout << "Error saving file." << std::endl;
    }
}

int main() {
    int choice;
    do {
        displayMenu();
        std::cin >> choice;
        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                openFile();
                break;
            case 3:
                saveFile();
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
