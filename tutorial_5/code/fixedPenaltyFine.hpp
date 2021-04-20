#ifndef FIXEDPENALTYFINE_HPP
#define FIXEDPENALTYFINE_HPP

#include"parkingFine.hpp"
#include"helper.hpp"

class FixedPenaltyFine : public ParkingFine {
    /*inherits from parking fine: 
        - std::string date;
        - std::string time;
        - std::string regNumber;
        - int offenceCode;
        - int amount;
    */

   public:
    FixedPenaltyFine(std::string date, std::string time, std::string regNumber, int offenceCode);
   
};

#endif