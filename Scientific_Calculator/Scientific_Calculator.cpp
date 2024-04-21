#include <iostream>
#include <cmath>

int main() {
    double num1, num2;
    char op;

    std::cout << "Enter first number: ";
    std::cin >> num1;

    std::cout << "Enter operator (+, -, *, /, ^): ";
    std::cin >> op;

    if (op == '+' || op == '-' || op == '*' || op == '/') {
        std::cout << "Enter second number: ";
        std::cin >> num2;
    }

    switch (op) {
        case '+':
            std::cout << "Result: " << num1 + num2 << std::endl;
            break;
        case '-':
            std::cout << "Result: " << num1 - num2 << std::endl;
            break;
        case '*':
            std::cout << "Result: " << num1 * num2 << std::endl;
            break;
        case '/':
            if (num2 != 0) {
                std::cout << "Result: " << num1 / num2 << std::endl;
            } else {
                std::cout << "Error: Division by zero!" << std::endl;
            }
            break;
        case '^':
            std::cout << "Result: " << pow(num1, num2) << std::endl;
            break;
        default:
            std::cout << "Invalid operator!" << std::endl;
            break;
    }

    return 0;
}
#include <iostream>
#include <cmath>

int main() {
    double num1, num2;
    char op;

    std::cout << "Enter first number: ";
    std::cin >> num1;

    std::cout << "Enter operator (+, -, *, /, ^): ";
    std::cin >> op;

    if (op == '+' || op == '-' || op == '*' || op == '/') {
        std::cout << "Enter second number: ";
        std::cin >> num2;
    }

    switch (op) {
        case '+':
            std::cout << "Result: " << num1 + num2 << std::endl;
            break;
        case '-':
            std::cout << "Result: " << num1 - num2 << std::endl;
            break;
        case '*':
            std::cout << "Result: " << num1 * num2 << std::endl;
            break;
        case '/':
            if (num2 != 0) {
                std::cout << "Result: " << num1 / num2 << std::endl;
            } else {
                std::cout << "Error: Division by zero!" << std::endl;
            }
            break;
        case '^':
            std::cout << "Result: " << pow(num1, num2) << std::endl;
            break;
        default:
            std::cout << "Invalid operator!" << std::endl;
            break;
    }

    return 0;
}
