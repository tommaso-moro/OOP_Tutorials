#ifndef DATASTORAGEARRAY_HPP
#define DATASTORAGEARRAY_HPP

#include<vector>
#include"storageDevice.hpp"
#include"helper.hpp"

class DataStorageArray {
    std::vector<StorageDevice*> storageDevices;
    float effectiveCapacity; //calculated differently based on whether RAID_1 or RAID_5
    float bandWidth;
    float latency; //given by maximum latency of any of its component storage devices
    DataStorageArrayConfig config;
    int nStorageDevices = 0; //useful to facilitate calculations

    public:
        //constructors
        DataStorageArray(DataStorageArrayConfig config);
        DataStorageArray(DataStorageArray const& dataStorageArray); //copy constructor;
        //assignment operator overload
        DataStorageArray& operator=(DataStorageArray &DataStorageArray);
        //destructor
        ~DataStorageArray();

        //methods 
        void addStorageDevice(StorageDevice &storageDevice);

        //members initializers (to be called in constructor)
        void calculateLatency();
        void calculateEffectiveCapacity(float sumOfCapacities);
        void calculateBandWidth(float sumOfBandwidths);

        //helper methods
        float getSumOfCapacities();
        float getSumOfBandwidths();

        //getters
        float getEffectiveCapacity() const;
        float getBandwidth() const;
        float getLatency() const;

};

#endif