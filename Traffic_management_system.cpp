#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

class TrafficLight {
private:
    std::string lightID;
    std::string status; // "Red", "Yellow", "Green"

public:
    TrafficLight(const std::string& id) : lightID(id), status("Red") {}

    const std::string& getLightID() const {
        return lightID;
    }

    const std::string& getStatus() const {
        return status;
    }

    void changeStatus(const std::string& newStatus) {
        status = newStatus;
        std::cout << "Traffic light " << lightID << " changed to " << status << " status." << std::endl;
    }
};

std::unordered_map<std::string, TrafficLight> trafficLights;

void addTrafficLight() {
    std::string lightID;
    std::cout << "Enter traffic light ID: ";
    std::cin >> lightID;

    if (trafficLights.find(lightID) == trafficLights.end()) {
        trafficLights[lightID] = TrafficLight(lightID);
        std::cout << "Traffic light added successfully!" << std::endl;
    } else {
        std::cout << "Traffic light ID already exists!" << std::endl;
    }
}

void manageTrafficLights() {
    std::string lightID;
    std::cout << "Enter traffic light ID: ";
    std::cin >> lightID;

    if (trafficLights.find(lightID) != trafficLights.end()) {
        std::string newStatus;
        std::cout << "Enter new status (Red, Yellow, Green): ";
        std::cin >> newStatus;

        if (newStatus == "Red" || newStatus == "Yellow" || newStatus == "Green") {
            trafficLights[lightID].changeStatus(newStatus);
        } else {
            std::cout << "Invalid status!" << std::endl;
        }
    } else {
        std::cout << "Traffic light not found!" << std::endl;
    }
}

int main() {
    int choice;
    do {
        std::cout << "\nTraffic Management System:\n"
                     "1. Add Traffic Light\n"
                     "2. Manage Traffic Lights\n"
                     "3. Exit\n"
                     "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addTrafficLight();
                break;
            case 2:
                manageTrafficLights();
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
