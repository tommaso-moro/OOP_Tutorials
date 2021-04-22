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
        //constructor
        JuniorPA(std::string name, int badgeNumber);

        //assignment operator overload
        JuniorPA& operator=(JuniorPA const& otherJuniorPA);

        //destructor
        ~JuniorPA() override;

        //methods
        float calculateSalary() override;

};

#endif