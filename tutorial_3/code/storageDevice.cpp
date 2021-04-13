#include "storageDevice.hpp"

StorageDevice::StorageDevice(float storageCapacity, float dataTransferBandwidth) : storageCapacity(storageCapacity), \
        dataTransferBandwidth(dataTransferBandwidth) {};

StorageDevice::StorageDevice(){};

float StorageDevice::getLatency() const {
    return this->latency;
};
float StorageDevice::getCapacity() const {
    return this->storageCapacity;
};
float StorageDevice::getDataTransferBandwidth() const {
    return this->dataTransferBandwidth;
};


StorageDevice::~StorageDevice(){}; 