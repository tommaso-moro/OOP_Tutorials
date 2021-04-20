#include"fixedPenaltyFine.hpp"

FixedPenaltyFine::FixedPenaltyFine(std::string date, std::string time, std::string regNumber, int offenceCode) \
 : ParkingFine(date, time, regNumber, offenceCode) {
    this->amount = fixedPenaltyAmount;
};