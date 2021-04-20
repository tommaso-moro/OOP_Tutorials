#ifndef JUNIORPA_HPP
#define JUNIORPA_HPP

#include"parkingAttendant.hpp"
#include"helper.hpp"


class JuniorPA : public ParkingAttendant {
    /* inherits:
        - std::string name;
        - int badgeNumber;
        - int salary;
        - std::vector<ParkingFine*> finesIssued;
    */

    public:
        JuniorPA(std::string name, int badgeNumber);
        float calculateSalary();

};

#endif