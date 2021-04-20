#include"excessChargeFine.hpp"

ExcessChargeFine::ExcessChargeFine(const std::string date, const std::string time, const std::string regNumber,
                                   int offenceCode, int overstayMinutes) : ParkingFine(date, time, regNumber, offenceCode) {
    this->overstayMinutes = overstayMinutes;
    this->amount = excessChargeAmount + 5*(overstayMinutes); //include input validator here -> fine must not excess fixedPenaltyFine (see helper.hpp)
};
