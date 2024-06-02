#include "StockTradingSimulator.h"

// Global variables
std::map<std::string, double> stockPrices;
User currentUser("default_user", 10000.0); // Example user
TradingEngine tradingEngine;
std::mutex dataMutex;

// Function to simulate fetching stock data
void fetchStockData() {
    std::vector<std::string> stocks = {"AAPL", "GOOGL", "MSFT", "AMZN"};
    std::default_random_engine generator(static_cast<long unsigned int>(time(0)));
    std::uniform_real_distribution<double> distribution(100.0, 1500.0);

    while (true) {
        {
            std::lock_guard<std::mutex> lock(dataMutex);
            for (const auto& stock : stocks) {
                stockPrices[stock] = distribution(generator);
            }
        }
        std::this_thread::sleep_for(std::chrono::seconds(5)); // Update every 5 seconds
    }
}

void displayPortfolio() {
    std::lock_guard<std::mutex> lock(dataMutex);
    std::cout << "\nPortfolio for " << currentUser.username << ":\n";
    for (const auto& stock : currentUser.portfolio) {
        std::cout << stock.first << ": " << stock.second << " shares\n";
    }
    std::cout << "Balance: $" << currentUser.balance << "\n";
}

void buyStock(const std::string& stockSymbol, int quantity) {
    std::lock_guard<std::mutex> lock(dataMutex);
    if (stockPrices.find(stockSymbol) == stockPrices.end()) {
        std::cout << "Invalid stock symbol.\n";
        return;
    }
    double cost = stockPrices[stockSymbol] * quantity;
    if (currentUser.balance >= cost) {
        currentUser.balance -= cost;
        currentUser.portfolio[stockSymbol] += quantity;
        std::cout << "Bought " << quantity << " shares of " << stockSymbol << ".\n";
    } else {
        std::cout << "Insufficient balance.\n";
    }
}

void sellStock(const std::string& stockSymbol, int quantity) {
    std::lock_guard<std::mutex> lock(dataMutex);
    if (currentUser.portfolio[stockSymbol] >= quantity) {
        double earnings = stockPrices[stockSymbol] * quantity;
        currentUser.balance += earnings;
        currentUser.portfolio[stockSymbol] -= quantity;
        if (currentUser.portfolio[stockSymbol] == 0) {
            currentUser.portfolio.erase(stockSymbol);
        }
        std::cout << "Sold " << quantity << " shares of " << stockSymbol << ".\n";
    } else {
        std::cout << "Insufficient shares.\n";
    }
}

void displayMenu() {
    int choice;
    std::string stockSymbol;
    int quantity;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Display Portfolio\n";
        std::cout << "2. Buy Stock\n";
        std::cout << "3. Sell Stock\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                displayPortfolio();
                break;
            case 2:
                std::cout << "Enter stock symbol to buy: ";
                std::cin >> stockSymbol;
                std::cout << "Enter quantity: ";
                std::cin >> quantity;
                buyStock(stockSymbol, quantity);
                break;
            case 3:
                std::cout << "Enter stock symbol to sell: ";
                std::cin >> stockSymbol;
                std::cout << "Enter quantity: ";
                std::cin >> quantity;
                sellStock(stockSymbol, quantity);
                break;
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
}

int main() {
    std::thread dataThread(fetchStockData);
    displayMenu();
    dataThread.join();
    return 0;
}
