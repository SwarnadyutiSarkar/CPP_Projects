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

class Doctor {
private:
    std::string doctorID;
    std::string name;
    std::string specialization;

public:
    Doctor(const std::string& id, const std::string& n, const std::string& spec)
        : doctorID(id), name(n), specialization(spec) {}

    void displayInfo() const {
        std::cout << "Doctor ID: " << doctorID << "\nName: " << name
                  << "\nSpecialization: " << specialization << std::endl;
    }
};

std::unordered_map<std::string, Patient> patientDB;
std::unordered_map<std::string, Doctor> doctorDB;

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

void addDoctor() {
    std::string doctorID, name, specialization;
    std::cout << "Enter doctor ID: ";
    std::cin >> doctorID;
    std::cout << "Enter doctor name: ";
    std::cin >> name;
    std::cout << "Enter specialization: ";
    std::cin >> specialization;

    if (doctorDB.find(doctorID) == doctorDB.end()) {
        doctorDB[doctorID] = Doctor(doctorID, name, specialization);
        std::cout << "Doctor added successfully!" << std::endl;
    } else {
        std::cout << "Doctor ID already exists!" << std::endl;
    }
}

int main() {
    int choice;
    do {
        std::cout << "\nHospital Management System:\n"
                     "1. Add Patient\n"
                     "2. Add Doctor\n"
                     "3. Exit\n"
                     "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                addDoctor();
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
