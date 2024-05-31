#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate monthly payment
double calculateMonthlyPayment(double loanAmount, double annualInterestRate, int loanTerm) {
    double monthlyInterestRate = annualInterestRate / 12 / 100;
    int numberOfPayments = loanTerm * 12;
    
    // Monthly payment formula: P = [r * PV] / [1 - (1 + r)^-n]
    double monthlyPayment = (monthlyInterestRate * loanAmount) / (1 - pow(1 + monthlyInterestRate, -numberOfPayments));
    
    return monthlyPayment;
}

// Function to calculate total repayment amount
double calculateTotalRepayment(double monthlyPayment, int loanTerm) {
    return monthlyPayment * loanTerm * 12;
}

int main() {
    double loanAmount, annualInterestRate;
    int loanTerm;

    // Input loan parameters from the user
    cout << "Enter the loan amount: ";
    cin >> loanAmount;

    cout << "Enter the annual interest rate (in percentage): ";
    cin >> annualInterestRate;

    cout << "Enter the loan term (in years): ";
    cin >> loanTerm;

    // Calculate monthly payment
    double monthlyPayment = calculateMonthlyPayment(loanAmount, annualInterestRate, loanTerm);

    // Calculate total repayment amount
    double totalRepayment = calculateTotalRepayment(monthlyPayment, loanTerm);

    // Output results
    cout << "Monthly Payment: $" << monthlyPayment << endl;
    cout << "Total Repayment Amount: $" << totalRepayment << endl;

    return 0;
}
