#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Cab {
    std::string id;
    double latitude;
    double longitude;
};

class CabFinder {
public:
    CabFinder() {
        // Simulate some available cabs with their coordinates
        availableCabs = {
            {"Cab1", 40.7128, -74.0060}, // New York
            {"Cab2", 34.0522, -118.2437}, // Los Angeles
            {"Cab3", 51.5074, -0.1278}, // London
            {"Cab4", 48.8566, 2.3522} // Paris
        };
    }

    void findNearbyCabs(double userLat, double userLon) {
        std::cout << "Available Cabs Near You:\n";
        for (const auto& cab : availableCabs) {
            double distance = calculateDistance(userLat, userLon, cab.latitude, cab.longitude);
            if (distance < 5.0) { // 5 km radius
                std::cout << cab.id << " is approximately " << distance << " km away.\n";
            }
        }
    }

private:
    std::vector<Cab> availableCabs;

    double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
        // Simple Euclidean distance approximation (not accurate for real-world use)
        return sqrt(pow(lat2 - lat1, 2) + pow(lon2 - lon1, 2)) * 111; // Convert degrees to km
    }
};

int main() {
    CabFinder cabFinder;
    double userLat, userLon;

    std::cout << "Enter your latitude: ";
    std::cin >> userLat;
    std::cout << "Enter your longitude: ";
    std::cin >> userLon;

    cabFinder.findNearbyCabs(userLat, userLon);

    return 0;
}
