#include <iostream>
#include <unordered_map>
#include <string>

struct Student {
    std::string name;
    int age;
    std::string department;
};

std::unordered_map<int, Student> studentDB;

void addStudent() {
    int id;
    Student newStudent;
    std::cout << "Enter student ID: ";
    std::cin >> id;
    std::cout << "Enter name: ";
    std::cin >> newStudent.name;
    std::cout << "Enter age: ";
    std::cin >> newStudent.age;
    std::cout << "Enter department: ";
    std::cin >> newStudent.department;
    studentDB[id] = newStudent;
    std::cout << "Student added successfully!" << std::endl;
}

void displayStudent() {
    int id;
    std::cout << "Enter student ID: ";
    std::cin >> id;
    if (studentDB.find(id) != studentDB.end()) {
        Student& student = studentDB[id];
        std::cout << "Name: " << student.name << "\nAge: " << student.age
                  << "\nDepartment: " << student.department << std::endl;
    } else {
        std::cout << "Student not found!" << std::endl;
    }
}

int main() {
    int choice;
    do {
        std::cout << "1. Add Student\n2. Display Student\n3. Exit\n";
        std::cin >> choice;
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudent();
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
