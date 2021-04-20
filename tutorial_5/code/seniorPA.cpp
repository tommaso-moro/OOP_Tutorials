#include"seniorPA.hpp"

SeniorPA::SeniorPA(std::string name, int badgeNumber) : ParkingAttendant(name, badgeNumber) {};

float SeniorPA::calculateSalary() {
    return 4.0;
}