#include"parkingAttendant.hpp"

ParkingAttendant::ParkingAttendant(std::string name, int badgeNumber) : name(name), badgeNumber(badgeNumber) {};

void ParkingAttendant::issueFine(ParkingFine* const fine) {
    finesIssued.push_back(fine);
};

