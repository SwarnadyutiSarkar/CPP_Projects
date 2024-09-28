#include <iostream>
#include <string>

class Patient {
public:
    std::string name;
    int age;
    float temperature;
    int heartRate;

    Patient(std::string patientName, int patientAge) 
        : name(patientName), age(patientAge), temperature(98.6), heartRate(70) {}

    void updateHealth(float temp, int hr) {
        temperature = temp;
        heartRate = hr;
        std::cout << "Health data updated for " << name << std::endl;
    }

    void displayHealth() {
        std::cout << "Patient: " << name << ", Age: " << age 
                  << ", Temperature: " << temperature 
                  << ", Heart Rate: " << heartRate << std::endl;
    }
};

int main() {
    Patient patient("John Doe", 30);
    patient.displayHealth();

    // Update health data
    patient.updateHealth(99.5, 75);
    patient.displayHealth();

    return 0;
}
