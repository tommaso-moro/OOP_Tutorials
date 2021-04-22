#include"seniorPA.hpp"

SeniorPA::SeniorPA(std::string name, int badgeNumber) : ParkingAttendant(name, badgeNumber) {
    this->salary = calculateSalary();
};

float SeniorPA::calculateSalary() {
    this->salary = SENIOR_PA_BASE_SALARY;
    float amountIssuedInFines = 0;
    for (int i = 0; i < finesIssued.size(); i++) {
        amountIssuedInFines += finesIssued[i]->getAmount();
    };
    float bonus = amountIssuedInFines*SENIOR_PA_BONUS_IN_PERCENTAGE;
    this->salary += bonus;
    return this->salary;
};

SeniorPA::~SeniorPA() {
};

SeniorPA& SeniorPA::operator=(const SeniorPA &otherSeniorPA) {
    ParkingAttendant::operator=(otherSeniorPA);
};
