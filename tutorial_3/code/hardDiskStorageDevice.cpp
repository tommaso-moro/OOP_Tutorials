#include"hardDiskStorageDevice.hpp"
#include<iostream>

HardDiskStorageDevice::HardDiskStorageDevice(float storageCapacity, float dataTransferBandwidth, float averageRotationTime, float averageSeekTime) \
: StorageDevice(storageCapacity, dataTransferBandwidth) {
     this->averageRotationTime = averageRotationTime;
     this->averageSeekTime = averageSeekTime;
     calculateLatency(); //sets latency
 };


HardDiskStorageDevice& HardDiskStorageDevice::operator=(HardDiskStorageDevice const &hardDiskStorageDevice) {
    this->averageRotationTime = hardDiskStorageDevice.getAverageRotationTime();
    this->averageSeekTime = hardDiskStorageDevice.getAverageSeekTime();
    this->dataTransferBandwidth = hardDiskStorageDevice.getDataTransferBandwidth();
    this->latency = hardDiskStorageDevice.getLatency();
    this->storageCapacity = hardDiskStorageDevice.getCapacity();
    return *this;
}; 

HardDiskStorageDevice::HardDiskStorageDevice(HardDiskStorageDevice const& hardDiskStorageDevice) { //copy constructor (which delegates to assignment operator)
    *this = hardDiskStorageDevice;
};

HardDiskStorageDevice::~HardDiskStorageDevice(){};

void HardDiskStorageDevice::calculateLatency() {
    this->latency = (averageRotationTime+averageSeekTime);
};

float HardDiskStorageDevice::getAverageRotationTime() const {
    return this->averageRotationTime;
}

float HardDiskStorageDevice::getAverageSeekTime() const {
    return this->averageSeekTime;
}

