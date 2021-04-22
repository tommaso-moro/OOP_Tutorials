#include"parkingAttendant.hpp"

//constructor
ParkingAttendant::ParkingAttendant(std::string name, int badgeNumber) : name(name), badgeNumber(badgeNumber) {
};


//copy constructor
ParkingAttendant::ParkingAttendant(const ParkingAttendant &otherParkingAttendant) {
    *this=otherParkingAttendant;
};

//assignment operator overload
ParkingAttendant& ParkingAttendant::operator=(ParkingAttendant const& otherParkingAttendant) {
    this->salary = otherParkingAttendant.salary;
    this->badgeNumber = otherParkingAttendant.badgeNumber;
    this->name = otherParkingAttendant.name;
    for (int i = 0; i < otherParkingAttendant.finesIssued.size(); i++) {
        ParkingFine* newFine = new ParkingFine(*(otherParkingAttendant.finesIssued[i]));
        finesIssued.push_back(newFine);
    }
    return *this;
};

void ParkingAttendant::issueFine(ParkingFine* const fine) {
    finesIssued.push_back(fine);
    this->salary = calculateSalary(); //update salary when a new fine is issues
}

std::string ParkingAttendant::getName() const {
    return this->name;
}

int ParkingAttendant::getBadgeNumber() const {
    return this->badgeNumber;
}

float ParkingAttendant::getSalary() const {
    return this->salary;
}

// destructor
ParkingAttendant::~ParkingAttendant() {
    for (int i = 0; i < finesIssued.size(); i++) {
        delete finesIssued[i];
    }
}



