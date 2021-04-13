#include "dataStorageArray.hpp"

DataStorageArray::DataStorageArray(DataStorageArrayConfig config) {
    this->config = config;
};

DataStorageArray::~DataStorageArray(){
    //implement destructor here
};

void DataStorageArray::addStorageDevice(StorageDevice &storageDevice) {
    StorageDevice* ptrToStorageDevice = &storageDevice;
    storageDevices.push_back(ptrToStorageDevice);

    nStorageDevices++;

    calculateLatency(); //sets latency

    float sumOfCapacities = getSumOfCapacities();
    float sumOfBandwidths = getSumOfBandwidths();

    calculateEffectiveCapacity(sumOfCapacities); //sets effectve capacity
    calculateBandWidth(sumOfBandwidths); //sets bandwidth
};

void DataStorageArray::calculateLatency() {
    float maxLatency = 0;
    for (int i = 0; i < nStorageDevices; i++) {
        StorageDevice* storageDevice = storageDevices[i];
        float storageDeviceLatency = storageDevice->getLatency();
        if (maxLatency < storageDeviceLatency) {
            maxLatency = storageDeviceLatency;
        }
    }
    this->latency = maxLatency;
};

void DataStorageArray::calculateEffectiveCapacity(float sumOfCapacities) {
    if (this->config == RAID_5) { //if RAID_5
        this->effectiveCapacity = ((float(nStorageDevices) - 1) / float(nStorageDevices)) * sumOfCapacities;
    } else if (this->config == RAID_1) { //if RAID_1
        this->effectiveCapacity = sumOfCapacities/2;
    }
};

void DataStorageArray::calculateBandWidth(float sumOfBandwidths) {
    if (this->config == RAID_5) { //if RAID_5
        this->bandWidth = ((float(nStorageDevices) - 1) / float(nStorageDevices)) * sumOfBandwidths;
    } else if (this->config == RAID_1) { //if RAID_1
        this->bandWidth = sumOfBandwidths/2;
    }
}

float DataStorageArray::getSumOfCapacities() {
    float sumOfCapacities = 0;
    for (int i = 0; i < nStorageDevices; i++) {
        StorageDevice* storageDevice = storageDevices[i];
        float storageDeviceCapacity = storageDevice->getCapacity();
        sumOfCapacities = sumOfCapacities + storageDeviceCapacity;
    }
    return sumOfCapacities;
};

float DataStorageArray::getSumOfBandwidths() {
    float sumOfBandwidths = 0;
    for (int i = 0; i < nStorageDevices; i++) {
        StorageDevice* storageDevice = storageDevices[i];
        float storageDeviceBandwidth = storageDevice->getDataTransferBandwidth();
        sumOfBandwidths = sumOfBandwidths + storageDeviceBandwidth;
    }
    return sumOfBandwidths;
};

float DataStorageArray::getEffectiveCapacity() const {
    return this->effectiveCapacity;
};

float DataStorageArray::getBandwidth() const {
    return this->bandWidth;
};

float DataStorageArray::getLatency() const {
    return this->latency;
};