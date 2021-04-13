#include"solidStateDiskStorageDevice.hpp"

SolidStateDiskStorageDevice::SolidStateDiskStorageDevice(float storageCapacity, float dataTransferBandwidth, float averageAccessTime) : \
    StorageDevice(storageCapacity, dataTransferBandwidth) { 
        this->averageAccessTime = averageAccessTime;
        calculateLatency();
    };

SolidStateDiskStorageDevice::~SolidStateDiskStorageDevice(){};

void SolidStateDiskStorageDevice::calculateLatency() {
    latency = averageAccessTime;
};

float SolidStateDiskStorageDevice::getAverageAccessTime() const {
    return this->averageAccessTime;
};

SolidStateDiskStorageDevice& SolidStateDiskStorageDevice::operator=(SolidStateDiskStorageDevice const &otherSolidStateDiskStorageDevice) {
    this->dataTransferBandwidth = otherSolidStateDiskStorageDevice.getDataTransferBandwidth();
    this->latency = otherSolidStateDiskStorageDevice.getLatency();
    this->storageCapacity = otherSolidStateDiskStorageDevice.getCapacity();
    this->averageAccessTime = otherSolidStateDiskStorageDevice.getAverageAccessTime();
    return *this;
};

SolidStateDiskStorageDevice::SolidStateDiskStorageDevice(SolidStateDiskStorageDevice const& otherSolidStateDiskStorageDevice) { //copy constructor (which delegates to assignment operator)
    *this = otherSolidStateDiskStorageDevice;
};
