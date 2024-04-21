#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

class Book {
private:
    std::string bookID;
    std::string title;
    std::string author;
    bool available;

public:
    Book(const std::string& id, const std::string& t, const std::string& a)
        : bookID(id), title(t), author(a), available(true) {}

    const std::string& getBookID() const {
        return bookID;
    }

    const std::string& getTitle() const {
        return title;
    }

    const std::string& getAuthor() const {
        return author;
    }

    bool isAvailable() const {
        return available;
    }

    void borrowBook() {
        if (available) {
            available = false;
            std::cout << "Book borrowed successfully!" << std::endl;
        } else {
            std::cout << "Book is not available!" << std::endl;
        }
    }

    void returnBook() {
        available = true;
        std::cout << "Book returned successfully!" << std::endl;
    }

    void displayInfo() const {
        std::cout << "Book ID: " << bookID << "\nTitle: " << title << "\nAuthor: " << author
                  << "\nStatus: " << (available ? "Available" : "Not Available") << std::endl;
    }
};

std::unordered_map<std::string, Book> library;

void addBook() {
    std::string bookID, title, author;
    std::cout << "Enter book ID: ";
    std::cin >> bookID;
    std::cout << "Enter title: ";
    std::cin >> title;
    std::cout << "Enter author: ";
    std::cin >> author;

    if (library.find(bookID) == library.end()) {
        library[bookID] = Book(bookID, title, author);
        std::cout << "Book added successfully!" << std::endl;
    } else {
        std::cout << "Book ID already exists!" << std::endl;
    }
}

void manageBooks() {
    std::string bookID;
    std::cout << "Enter book ID: ";
    std::cin >> bookID;

    if (library.find(bookID) != library.end()) {
        int choice;
        std::cout << "1. Borrow Book\n2. Return Book\n3. Display Info\nEnter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                library[bookID].borrowBook();
                break;
            case 2:
                library[bookID].returnBook();
                break;
            case 3:
                library[bookID].displayInfo();
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
                break;
        }
    } else {
        std::cout << "Book not found!" << std::endl;
    }
}

int main() {
    int choice;
    do {
        std::cout << "\nLibrary Management System:\n"
                     "1. Add Book\n"
                     "2. Manage Books\n"
                     "3. Exit\n"
                     "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                manageBooks();
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
