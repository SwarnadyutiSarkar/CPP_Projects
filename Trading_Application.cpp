#include <iostream>
#include <unordered_map>
#include <string>

class Stock {
private:
    std::string symbol;
    double price;

public:
    Stock(const std::string& s, double p) : symbol(s), price(p) {}

    double getPrice() const {
        return price;
    }

    void setPrice(double p) {
        price = p;
    }
};

std::unordered_map<std::string, Stock> stocks;

void addStock() {
    std::string symbol;
    double price;
    std::cout << "Enter stock symbol: ";
    std::cin >> symbol;
    std::cout << "Enter stock price: ";
    std::cin >> price;

    if (stocks.find(symbol) == stocks.end()) {
        stocks[symbol] = Stock(symbol, price);
        std::cout << "Stock added successfully!" << std::endl;
    } else {
        std::cout << "Stock symbol already exists!" << std::endl;
    }
}

void displayStockPrice() {
    std::string symbol;
    std::cout << "Enter stock symbol: ";
    std::cin >> symbol;

    if (stocks.find(symbol) != stocks.end()) {
        std::cout << "Price of " << symbol << ": $" << stocks[symbol].getPrice() << std::endl;
    } else {
        std::cout << "Stock not found!" << std::endl;
    }
}

int main() {
    int choice;
    do {
        std::cout << "\nTrading Application:\n"
                     "1. Add Stock\n"
                     "2. Display Stock Price\n"
                     "3. Exit\n"
                     "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStock();
                break;
            case 2:
                displayStockPrice();
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
