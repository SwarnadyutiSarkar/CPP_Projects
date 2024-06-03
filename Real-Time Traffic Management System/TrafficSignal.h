#pragma once

#include <string>

class TrafficSignal {
public:
    TrafficSignal(const std::string &name);
    void cycle();
    void setRed();
    std::string getState() const;
    std::string getName() const;

private:
    std::string name;
    std::string state;
};
