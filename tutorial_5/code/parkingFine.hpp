#ifndef PARKINGFINE_HPP
#define PARKINGFINE_HPP

#include<string>

class ParkingFine {
    protected:
        std::string date;
        std::string time;
        std::string regNumber;
        int offenceCode;
        float amount;

    public:
        //constructor
        ParkingFine(std::string date, std::string time, std::string regNumber, int offenceCode);

        //copy constructor
        ParkingFine(ParkingFine const& otherParkingFine);

        //assignment operator overload
        ParkingFine& operator=(ParkingFine const& otherParkingFine);

        //destructor
        virtual ~ParkingFine();

        //getter
        int getAmount() const;

};

#endif