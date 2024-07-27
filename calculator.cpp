#include <iostream>
#include <cmath>

// Function to perform arithmetic operations
double calculate(double num1, double num2, char operation) {
    switch (operation) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 != 0)
                return num1 / num2;
            else
                throw std::runtime_error("Division by zero!");
        default:
            throw std::invalid_argument("Invalid operation!");
    }
}

// Function to perform trigonometric operations
double trigonometric(double num, char operation) {
    switch (operation) {
        case 's': // sine
            return sin(num);
        case 'c': // cosine
            return cos(num);
        case 't': // tangent
            return tan(num);
        default:
            throw std::invalid_argument("Invalid trigonometric operation!");
    }
}

// Function to perform exponential operations
double exponential(double num, char operation) {
    switch (operation) {
        case 'e': // exponential (e^x)
            return exp(num);
        case 'l': // natural logarithm (ln)
            return log(num);
        default:
            throw std::invalid_argument("Invalid exponential operation!");
    }
}

int main() {
    double num1, num2;
    char operation;

    std::cout << "Advanced Calculator" << std::endl;
    std::cout << "-----------------" << std::endl;

    while (true) {
        std::cout << "Enter the first number: ";
        std::cin >> num1;

        std::cout << "Enter the operation (+, -, *, /, s, c, t, e, l): ";
        std::cin >> operation;

        if (operation == '+' || operation == '-' || operation == '*' || operation == '/') {
            std::cout << "Enter the second number: ";
            std::cin >> num2;

            try {
                double result = calculate(num1, num2, operation);
                std::cout << "Result: " << result << std::endl;
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        } else if (operation == 's' || operation == 'c' || operation == 't') {
            try {
                double result = trigonometric(num1, operation);
                std::cout << "Result: " << result << std::endl;
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        } else if (operation == 'e' || operation == 'l') {
            try {
                double result = exponential(num1, operation);
                std::cout << "Result: " << result << std::endl;
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        } else {
            std::cerr << "Error: Invalid operation!" << std::endl;
        }

        std::cout << "Do you want to continue? (y/n): ";
        char response;
        std::cin >> response;

        if (response != 'y')
            break;
    }

    return 0;
}
