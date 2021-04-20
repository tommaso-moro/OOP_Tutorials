#include"juniorPA.hpp"

#include<iostream>

JuniorPA::JuniorPA(std::string name, int badgeNumber) : ParkingAttendant(name, badgeNumber) {
    this->salary = JUNIOR_PA_BASE_SALARY;
};

float JuniorPA::calculateSalary() {
    float amountIssuedInFines = 0;
    for (int i = 0; i < finesIssued.size(); i++) {
        amountIssuedInFines += finesIssued[i]->getAmount();
    };
    std::cout << "here: " << finesIssued[0]->getAmount() << std::endl;
    float bonus = amountIssuedInFines*JUNIOR_PA_BONUS_IN_PERCENTAGE;
    salary += bonus;
    return salary;

};