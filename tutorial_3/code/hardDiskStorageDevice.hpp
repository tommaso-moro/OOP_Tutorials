#ifndef HARDDISKSTORAGEDEVICE_HPP
#define HARDDISKSTORAGEDEVICE_HPP

#include"storageDevice.hpp"

class HardDiskStorageDevice : public StorageDevice {
    float averageRotationTime;
    float averageSeekTime;

    public:
        //constructors
        HardDiskStorageDevice(float storageCapacity, float dataTransferBandwidth, float averageRotationTime, float averageSeekTime);
        HardDiskStorageDevice(HardDiskStorageDevice const& hardDiskStorageDevice); //copy constructor;

        //assignment operator overload
        HardDiskStorageDevice& operator=(HardDiskStorageDevice const &hardDiskStorageDevice);

        //destructor
        ~HardDiskStorageDevice();

        //override methods
        void calculateLatency() override;

        //getters
        float getAverageRotationTime() const;
        float getAverageSeekTime() const;

};

#endif