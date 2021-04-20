#ifndef PARKINGATTENDANT_HPP
#define PARKINGATTENDANT_HPP

#include<string>
#include<vector>
#include"parkingFine.hpp"

class ParkingAttendant {
    protected:
        std::string name;
        int badgeNumber;
        float salary;
        std::vector<ParkingFine*> finesIssued;

    public:
        ParkingAttendant(std::string name, int badgeNumber);
        void issueFine(ParkingFine* const parkingFine);
        virtual float calculateSalary() = 0;
};

#endif