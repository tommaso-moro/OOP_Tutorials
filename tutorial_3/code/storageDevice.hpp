#ifndef STORAGEDEVICE_HPP
#define STORAGEDEVICE_HPP



class StorageDevice {
    protected:
        float storageCapacity; //in GB
        float dataTransferBandwidth; //in MB/s
        float latency; //in milliseconds

    StorageDevice();

    public:
        //constructor
        StorageDevice(float storageCapacity, float dataTransferBandwidth);

        //destructor
        virtual ~StorageDevice();

        virtual void calculateLatency() = 0;

        //getters
        float getLatency() const ; //getter for latency
        float getCapacity() const ; //getter for capacity
        float getDataTransferBandwidth() const ; //getter for bandwidth
};

#endif