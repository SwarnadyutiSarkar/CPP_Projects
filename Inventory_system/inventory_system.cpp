#include <iostream>
#include <unordered_map>
#include <string>

struct Item {
    std::string name;
    int quantity;
    float price;
};

std::unordered_map<std::string, Item> inventory;

void addItem() {
    Item newItem;
    std::string itemName;
    std::cout << "Enter item name: ";
    std::cin >> itemName;
    std::cout << "Enter quantity: ";
    std::cin >> newItem.quantity;
    std::cout << "Enter price: ";
    std::cin >> newItem.price;
    newItem.name = itemName;
    inventory[itemName] = newItem;
    std::cout << "Item added successfully!" << std::endl;
}

void displayInventory() {
    std::cout << "Inventory:\n";
    for (const auto& pair : inventory) {
        const Item& item = pair.second;
        std::cout << "Name: " << item.name << "\nQuantity: " << item.quantity
                  << "\nPrice: " << item.price << std::endl;
    }
}

int main() {
    int choice;
    do {
        std::cout << "1. Add Item\n2. Display Inventory\n3. Exit\n";
        std::cin >> choice;
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                displayInventory();
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
