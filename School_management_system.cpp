#include <iostream>
#include <unordered_map>
#include <string>

class Student {
private:
    std::string studentID;
    std::string name;
    int grade;

public:
    Student(const std::string& id, const std::string& n, int g) : studentID(id), name(n), grade(g) {}

    void displayInfo() const {
        std::cout << "Student ID: " << studentID << "\nName: " << name << "\nGrade: " << grade << std::endl;
    }
};

class Teacher {
private:
    std::string teacherID;
    std::string name;
    std::string subject;

public:
    Teacher(const std::string& id, const std::string& n, const std::string& subj)
        : teacherID(id), name(n), subject(subj) {}

    void displayInfo() const {
        std::cout << "Teacher ID: " << teacherID << "\nName: " << name
                  << "\nSubject: " << subject << std::endl;
    }
};

std::unordered_map<std::string, Student> studentDB;
std::unordered_map<std::string, Teacher> teacherDB;

void addStudent() {
    std::string studentID, name;
    int grade;
    std::cout << "Enter student ID: ";
    std::cin >> studentID;
    std::cout << "Enter student name: ";
    std::cin >> name;
    std::cout << "Enter grade: ";
    std::cin >> grade;

    if (studentDB.find(studentID) == studentDB.end()) {
        studentDB[studentID] = Student(studentID, name, grade);
        std::cout << "Student added successfully!" << std::endl;
    } else {
        std::cout << "Student ID already exists!" << std::endl;
    }
}

void addTeacher() {
    std::string teacherID, name, subject;
    std::cout << "Enter teacher ID: ";
    std::cin >> teacherID;
    std::cout << "Enter teacher name: ";
    std::cin >> name;
    std::cout << "Enter subject: ";
    std::cin >> subject;

    if (teacherDB.find(teacherID) == teacherDB.end()) {
        teacherDB[teacherID] = Teacher(teacherID, name, subject);
        std::cout << "Teacher added successfully!" << std::endl;
    } else {
        std::cout << "Teacher ID already exists!" << std::endl;
    }
}

int main() {
    int choice;
    do {
        std::cout << "\nSchool Management System:\n"
                     "1. Add Student\n"
                     "2. Add Teacher\n"
                     "3. Exit\n"
                     "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                addTeacher();
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
