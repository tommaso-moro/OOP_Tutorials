#ifndef PARKINGFINE_HPP
#define PARKINGFINE_HPP

#include<string>

class ParkingFine {
    protected:
        std::string date;
        std::string time;
        std::string regNumber;
        int offenceCode;
        int amount;

    public:
        ParkingFine(std::string date, std::string time, std::string regNumber, int offenceCode);

        //getter
        int getAmount() const;

};

#endif