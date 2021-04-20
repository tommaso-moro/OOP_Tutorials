#include"parkingFine.hpp"

ParkingFine::ParkingFine(std::string date, std::string time, std::string regNumber, int offenceCode) : \
date(date), time(time), regNumber(regNumber), offenceCode(offenceCode) {};

int ParkingFine::getAmount() const {
    return this->amount;
}