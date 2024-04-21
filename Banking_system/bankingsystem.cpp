#include <iostream>
#include <unordered_map>
#include <string>

class Account {
private:
    std::string accountNumber;
    std::string accountHolderName;
    float balance;

public:
    Account(const std::string& accNumber, const std::string& accHolderName)
        : accountNumber(accNumber), accountHolderName(accHolderName), balance(0.0) {}

    const std::string& getAccountNumber() const {
        return accountNumber;
    }

    const std::string& getAccountHolderName() const {
        return accountHolderName;
    }

    float getBalance() const {
        return balance;
    }

    void deposit(float amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposit successful! Current balance: $" << balance << std::endl;
        } else {
            std::cout << "Invalid amount!" << std::endl;
        }
    }

    void withdraw(float amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawal successful! Current balance: $" << balance << std::endl;
        } else {
            std::cout << "Insufficient funds or invalid amount!" << std::endl;
        }
    }
};

std::unordered_map<std::string, Account> accounts;

void createAccount() {
    std::string accountNumber, accountHolderName;
    std::cout << "Enter account number: ";
    std::cin >> accountNumber;
    std::cout << "Enter account holder name: ";
    std::cin >> accountHolderName;

    if (accounts.find(accountNumber) == accounts.end()) {
        accounts[accountNumber] = Account(accountNumber, accountHolderName);
        std::cout << "Account created successfully!" << std::endl;
    } else {
        std::cout << "Account number already exists!" << std::endl;
    }
}

void deposit() {
    std::string accountNumber;
    float amount;
    std::cout << "Enter account number: ";
    std::cin >> accountNumber;

    if (accounts.find(accountNumber) != accounts.end()) {
        std::cout << "Enter deposit amount: ";
        std::cin >> amount;
        accounts[accountNumber].deposit(amount);
    } else {
        std::cout << "Account not found!" << std::endl;
    }
}

void withdraw() {
    std::string accountNumber;
    float amount;
    std::cout << "Enter account number: ";
    std::cin >> accountNumber;

    if (accounts.find(accountNumber) != accounts.end()) {
        std::cout << "Enter withdrawal amount: ";
        std::cin >> amount;
        accounts[accountNumber].withdraw(amount);
    } else {
        std::cout << "Account not found!" << std::endl;
    }
}

void checkBalance() {
    std::string accountNumber;
    std::cout << "Enter account number: ";
    std::cin >> accountNumber;

    if (accounts.find(accountNumber) != accounts.end()) {
        std::cout << "Current balance: $" << accounts[accountNumber].getBalance() << std::endl;
    } else {
        std::cout << "Account not found!" << std::endl;
    }
}

int main() {
    int choice;
    do {
        std::cout << "\nBanking System Menu:\n"
                     "1. Create Account\n"
                     "2. Deposit\n"
                     "3. Withdraw\n"
                     "4. Check Balance\n"
                     "5. Exit\n"
                     "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                std::cout << "Exiting...";
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
                break;
        }

    } while (choice != 5);

    return 0;
}
