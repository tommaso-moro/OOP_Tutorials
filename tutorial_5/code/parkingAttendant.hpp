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
        //constructor
        ParkingAttendant(std::string name, int badgeNumber);

        //copy constructor
        ParkingAttendant(ParkingAttendant const& otherParkingAttendant);

        //assignment operator overload
        ParkingAttendant& operator=(ParkingAttendant const& otherParkingAttendant);

        //destructor
        virtual ~ParkingAttendant();

        //methods
        void issueFine(ParkingFine* const parkingFine);
        virtual float calculateSalary() = 0;

        //getters
        std::string getName() const;
        int getBadgeNumber() const;
        float getSalary() const;
};

#endif