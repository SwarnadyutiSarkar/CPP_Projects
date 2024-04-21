#include <iostream>
#include <unordered_map>
#include <string>

class Patient {
private:
    std::string patientID;
    std::string name;
    std::string diagnosis;

public:
    Patient(const std::string& id, const std::string& n) : patientID(id), name(n), diagnosis("N/A") {}

    void setDiagnosis(const std::string& d) {
        diagnosis = d;
    }

    void displayInfo() const {
        std::cout << "Patient ID: " << patientID << "\nName: " << name << "\nDiagnosis: " << diagnosis << std::endl;
    }
};

std::unordered_map<std::string, Patient> patientDB;

void addPatient() {
    std::string patientID, name;
    std::cout << "Enter patient ID: ";
    std::cin >> patientID;
    std::cout << "Enter patient name: ";
    std::cin >> name;

    if (patientDB.find(patientID) == patientDB.end()) {
        patientDB[patientID] = Patient(patientID, name);
        std::cout << "Patient added successfully!" << std::endl;
    } else {
        std::cout << "Patient ID already exists!" << std::endl;
    }
}

void diagnosePatient() {
    std::string patientID, diagnosis;
    std::cout << "Enter patient ID: ";
    std::cin >> patientID;
    
    if (patientDB.find(patientID) != patientDB.end()) {
        std::cout << "Enter diagnosis: ";
        std::cin >> diagnosis;
        patientDB[patientID].setDiagnosis(diagnosis);
        std::cout << "Diagnosis added successfully!" << std::endl;
    } else {
        std::cout << "Patient not found!" << std::endl;
    }
}

int main() {
    int choice;
    do {
        std::cout << "\nMedical Information System:\n"
                     "1. Add Patient\n"
                     "2. Diagnose Patient\n"
                     "3. Exit\n"
                     "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                diagnosePatient();
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
