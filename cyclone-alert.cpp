#include <iostream>

using namespace std;

int main() {
    double windSpeed;

    // Input wind speed from the user
    cout << "Enter the current wind speed (in knots): ";
    cin >> windSpeed;

    // Cyclone alert threshold (e.g., 64 knots)
    const double cycloneThreshold = 64;

    // Check if the wind speed exceeds the cyclone threshold
    if (windSpeed >= cycloneThreshold) {
        cout << "Cyclone Alert! Wind speed is " << windSpeed << " knots." << endl;
        cout << "Take necessary precautions and stay safe!" << endl;
    } else {
        cout << "No cyclone alert. Wind speed is " << windSpeed << " knots." << endl;
    }

    return 0;
}
