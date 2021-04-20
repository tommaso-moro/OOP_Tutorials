#ifndef EXCESSCHARGEFINE_HPP
#define EXCESSCHARGEFINE_HPP

#include"parkingFine.hpp"
#include"helper.hpp"

class ExcessChargeFine : public ParkingFine {
    /*inherits from parking fine: 
        - std::string date;
        - std::string time;
        - std::string regNumber;
        - int offenceCode;
        - int amount;
    */
    private:
    int overstayMinutes;

public:
    ExcessChargeFine(const std::string date, const std::string time, const std::string regNumber, int offenceCode,
                     int overstayMinutes);
};

#endif