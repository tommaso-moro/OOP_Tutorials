#include"excessChargeFine.hpp"

#include<iostream>

ExcessChargeFine::ExcessChargeFine(const std::string date, const std::string time, const std::string regNumber,
                                   int offenceCode, int overstayMinutes) : ParkingFine(date, time, regNumber, offenceCode) {
    this->overstayMinutes = overstayMinutes;
    float newAmount = excessChargeAmount + 5*(overstayMinutes);
    if (newAmount > fixedPenaltyAmount) { //input validation: exceed charge fine cannot exceed fixed penalty fine
        std::cerr << "Error: The value of the excess charge fine issued on date " << date << " at time " << time << " for vehicle with registration number " << regNumber \
        << " (offence code: " << offenceCode << ") cannot exceed " << fixedPenaltyAmount << " (i.e. the current fixed penalty amount). Setting the value of the excess charge fine to its max value " \
        << "(" << fixedPenaltyAmount << ")" " by default." << std::endl;
        this->amount = fixedPenaltyAmount;
    } else {
        this->amount = newAmount;
    }
};
