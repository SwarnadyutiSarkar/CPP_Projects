#include "TrafficManagementSystem.h"
#include <iostream>
#include <chrono>
#include <thread>

TrafficManagementSystem::TrafficManagementSystem() : incidentDetector() {
    signals.emplace_back("Signal 1");
    signals.emplace_back("Signal 2");
    signals.emplace_back("Signal 3");
}

void TrafficManagementSystem::manageTrafficSignals() {
    while (true) {
        std::lock_guard<std::mutex> lock(trafficMutex);
        for (auto &signal : signals) {
            signal.cycle();
        }
        std::this_thread::sleep_for(std::chrono::seconds(5)); // Cycle every 5 seconds
    }
}

void TrafficManagementSystem::monitorIncidents() {
    while (true) {
        std::lock_guard<std::mutex> lock(trafficMutex);
        if (incidentDetector.detectIncident()) {
            std::cout << "Incident detected! Adjusting traffic signals...\n";
            for (auto &signal : signals) {
                signal.setRed();
            }
        }
        std::this_thread::sleep_for(std::chrono::seconds(5)); // Check every 5 seconds
    }
}

void TrafficManagementSystem::displayTrafficStatus() {
    std::lock_guard<std::mutex> lock(trafficMutex);
    for (const auto &signal : signals) {
        std::cout << signal.getName() << " is " << signal.getState() << "\n";
    }
}

void TrafficManagementSystem::simulateIncident() {
    std::lock_guard<std::mutex> lock(trafficMutex);
    incidentDetector.simulateIncident();
}
