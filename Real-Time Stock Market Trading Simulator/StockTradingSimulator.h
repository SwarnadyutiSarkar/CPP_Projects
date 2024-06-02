#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <thread>
#include <mutex>
#include <random>
#include <ctime>

// Forward declarations
void fetchStockData();
void processTradeOrders();
void displayMenu();
void displayPortfolio();
void buyStock(const std::string& stockSymbol, int quantity);
void sellStock(const std::string& stockSymbol, int quantity);

class User {
public:
    std::string username;
    double balance;
    std::map<std::string, int> portfolio;
    
    User(const std::string& name, double initial_balance) : username(name), balance(initial_balance) {}
};

class TradingEngine {
public:
    void processOrder(User& user, const std::string& orderType, const std::string& stockSymbol, int quantity);
};

extern std::map<std::string, double> stockPrices;
extern User currentUser;
extern TradingEngine tradingEngine;
extern std::mutex dataMutex;
