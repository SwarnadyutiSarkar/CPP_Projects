#include "TrafficSignal.h"

TrafficSignal::TrafficSignal(const std::string &name) : name(name), state("Red") {}

void TrafficSignal::cycle() {
    if (state == "Red") {
        state = "Green";
    } else if (state == "Green") {
        state = "Yellow";
    } else if (state == "Yellow") {
        state = "Red";
    }
}

void TrafficSignal::setRed() {
    state = "Red";
}

std::string TrafficSignal::getState() const {
    return state;
}

std::string TrafficSignal::getName() const {
    return name;
}
