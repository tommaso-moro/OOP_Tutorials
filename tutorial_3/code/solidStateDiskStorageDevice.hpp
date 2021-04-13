#ifndef SOLIDSTATEDISKSTORAGEDEVICE_HPP
#define SOLIDSTATEDISKSTORAGEDEVICE_HPP

#include"storageDevice.hpp"

class SolidStateDiskStorageDevice : public StorageDevice {
    float averageAccessTime; //in milliseconds
    //inherited from storageDevice base class -> float storageCapacity, float dataTransferBandwidth, float latency


    public:
        //constructors
        SolidStateDiskStorageDevice(float storageCapacity, float dataTransferBandwidth, float averageAccessTime);
        SolidStateDiskStorageDevice(SolidStateDiskStorageDevice const& solidStateDiskStorageDevice); //copy constructor;

        //assignment operator overload
        SolidStateDiskStorageDevice& operator=(SolidStateDiskStorageDevice const &otherSolidStateDiskStorageDevice);

        //destructor
        ~SolidStateDiskStorageDevice();

        //override methods
        void calculateLatency() override;

        //getters
        float getAverageAccessTime() const;

};

#endif