#ifndef SENIORPA_HPP
#define SENIORPA_HPP

#include<string>

#include"parkingAttendant.hpp"
#include "helper.hpp"

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

        //assignment operator overload
        SeniorPA& operator=(SeniorPA const& otherSeniorPA);

        //destructor
        ~SeniorPA() override;

        //methods
        float calculateSalary() override;

};

#endif