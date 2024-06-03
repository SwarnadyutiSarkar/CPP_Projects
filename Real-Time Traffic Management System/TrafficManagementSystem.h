#pragma once

#include <vector>
#include <mutex>
#include "TrafficSignal.h"
#include "IncidentDetector.h"

class TrafficManagementSystem {
public:
    TrafficManagementSystem();
    void manageTrafficSignals();
    void monitorIncidents();
    void displayTrafficStatus();
    void simulateIncident();

private:
    std::vector<TrafficSignal> signals;
    IncidentDetector incidentDetector;
    std::mutex trafficMutex;
};
