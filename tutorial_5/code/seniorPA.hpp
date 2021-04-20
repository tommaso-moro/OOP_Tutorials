#ifndef SENIORPA_HPP
#define SENIORPA_HPP

#include<string>

#include"parkingAttendant.hpp"

class SeniorPA : public ParkingAttendant {
    /* inherits:
        - std::string name;
        - int badgeNumber;
        - int salary;
        - std::vector<ParkingFine*> finesIssued;
    */

    public:
        //constructor
        SeniorPA(std::string name, int badgeNumber);

        //override calculateSalary()
        float calculateSalary();

};

#endif