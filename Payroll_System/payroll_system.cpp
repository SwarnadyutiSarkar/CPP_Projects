#include <iostream>
#include <unordered_map>
#include <string>

struct Employee {
    std::string name;
    float salary;
};

std::unordered_map<int, Employee> payroll;

void addEmployee() {
    int id;
    Employee newEmployee;
    std::cout << "Enter employee ID: ";
    std::cin >> id;
    std::cout << "Enter name: ";
    std::cin >> newEmployee.name;
    std::cout << "Enter salary: ";
    std::cin >> newEmployee.salary;
    payroll[id] = newEmployee;
    std::cout << "Employee added successfully!" << std::endl;
}

void displayEmployee() {
    int id;
    std::cout << "Enter employee ID: ";
    std::cin >> id;
    if (payroll.find(id) != payroll.end()) {
        Employee& employee = payroll[id];
        std::cout << "Name: " << employee.name << "\nSalary: $" << employee.salary << std::endl;
    } else {
        std::cout << "Employee not found!" << std::endl;
    }
}

int main() {
    int choice;
    do {
        std::cout << "1. Add Employee\n2. Display Employee\n3. Exit\n";
        std::cin >> choice;
        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployee();
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
