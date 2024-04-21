#include <iostream>
#include <unordered_map>
#include <string>

class Product {
private:
    std::string productName;
    int quantity;

public:
    Product(const std::string& name, int qty) : productName(name), quantity(qty) {}

    void addStock(int qty) {
        quantity += qty;
    }

    void sellStock(int qty) {
        if (qty <= quantity) {
            quantity -= qty;
        } else {
            std::cout << "Insufficient stock!" << std::endl;
        }
    }

    void displayInfo() const {
        std::cout << "Product: " << productName << "\nQuantity: " << quantity << std::endl;
    }
};

std::unordered_map<std::string, Product> productDB;

void addProduct() {
    std::string productName;
    int quantity;
    std::cout << "Enter product name: ";
    std::cin >> productName;
    std::cout << "Enter initial quantity: ";
    std::cin >> quantity;

    if (productDB.find(productName) == productDB.end()) {
        productDB[productName] = Product(productName, quantity);
        std::cout << "Product added successfully!" << std::endl;
    } else {
        std::cout << "Product already exists!" << std::endl;
    }
}

void manageStock() {
    std::string productName;
    int qty;
    std::cout << "Enter product name: ";
    std::cin >> productName;

    if (productDB.find(productName) != productDB.end()) {
        std::cout << "1. Add Stock\n2. Sell Stock\nEnter choice: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter quantity to add: ";
                std::cin >> qty;
                productDB[productName].addStock(qty);
                std::cout << "Stock added successfully!" << std::endl;
                break;
            case 2:
                std::cout << "Enter quantity to sell: ";
                std::cin >> qty;
                productDB[productName].sellStock(qty);
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
                break;
        }
    } else {
        std::cout << "Product not found!" << std::endl;
    }
}

int main() {
    int choice;
    do {
        std::cout << "\nStock Management System:\n"
                     "1. Add Product\n"
                     "2. Manage Stock\n"
                     "3. Exit\n"
                     "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                manageStock();
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
