#include "IncidentDetector.h"

IncidentDetector::IncidentDetector() : incidentActive(false) {}

bool IncidentDetector::detectIncident() {
    return incidentActive;
}

void IncidentDetector::simulateIncident() {
    incidentActive = !incidentActive;
}
