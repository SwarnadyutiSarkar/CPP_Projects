#include <iostream>
#include <thread>
#include <vector>
#include "TrafficManagementSystem.h"

void displayMenu(TrafficManagementSystem &system) {
    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Display Traffic Status\n";
        std::cout << "2. Simulate Traffic Incident\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                system.displayTrafficStatus();
                break;
            case 2:
                system.simulateIncident();
                break;
            case 3:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);
}

int main() {
    TrafficManagementSystem system;
    std::thread signalThread(&TrafficManagementSystem::manageTrafficSignals, &system);
    std::thread incidentThread(&TrafficManagementSystem::monitorIncidents, &system);

    displayMenu(system);

    signalThread.join();
    incidentThread.join();

    return 0;
}
