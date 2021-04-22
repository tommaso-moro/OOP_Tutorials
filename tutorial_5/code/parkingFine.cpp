#include"parkingFine.hpp"

//constructor
ParkingFine::ParkingFine(std::string date, std::string time, std::string regNumber, int offenceCode) : \
date(date), time(time), regNumber(regNumber), offenceCode(offenceCode) {};

//destructor
ParkingFine::~ParkingFine() {

}

//copy constructor
ParkingFine::ParkingFine(ParkingFine const& otherParkingFine) {
    *this = otherParkingFine;
};

//assignment operator overload
ParkingFine& ParkingFine::operator=(ParkingFine const& otherParkingFine) {
    this->date = otherParkingFine.date;
    this->time = otherParkingFine.time;
    this->amount = otherParkingFine.amount;
    this->offenceCode = otherParkingFine.offenceCode;
    this->regNumber = otherParkingFine.regNumber;
    return *this;
}

int ParkingFine::getAmount() const {
    return this->amount;
}