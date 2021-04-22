#include"juniorPA.hpp"

//constructor
JuniorPA::JuniorPA(std::string name, int badgeNumber) : ParkingAttendant(name, badgeNumber) {
    this->salary = calculateSalary();
};

//assignment operator overload
JuniorPA& JuniorPA::operator=(const JuniorPA &otherJuniorPA) {
    ParkingAttendant::operator=(otherJuniorPA);
}

//destructor
JuniorPA::~JuniorPA() {
};

float JuniorPA::calculateSalary() {
    this->salary = JUNIOR_PA_BASE_SALARY;
    float amountIssuedInFines = 0;
    for (int i = 0; i < finesIssued.size(); i++) {
        amountIssuedInFines += finesIssued[i]->getAmount();
    };
    float bonus = amountIssuedInFines*JUNIOR_PA_BONUS_IN_PERCENTAGE;
    this->salary += bonus;
    return this->salary;
}
