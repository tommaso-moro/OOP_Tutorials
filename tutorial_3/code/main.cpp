#include<iostream>
#include"solidStateDiskStorageDevice.hpp"
#include"hardDiskStorageDevice.hpp"
#include"dataStorageArray.hpp"

using namespace std;

int main() {
    HardDiskStorageDevice hd1 = HardDiskStorageDevice(500, 100, 4, 8);
    HardDiskStorageDevice hd2 = hd1;
    HardDiskStorageDevice hd3 = hd1;
    HardDiskStorageDevice hd4 = hd1;


    SolidStateDiskStorageDevice ssd1 = SolidStateDiskStorageDevice(30, 300, 0.01);
    SolidStateDiskStorageDevice ssd2 = ssd1;
    SolidStateDiskStorageDevice ssd3 = ssd1;
    SolidStateDiskStorageDevice ssd4 = ssd1;

    DataStorageArray dsa1 = DataStorageArray(RAID_1);
    DataStorageArray dsa2 = DataStorageArray(RAID_5);

    dsa1.addStorageDevice(hd1);
    dsa1.addStorageDevice(hd2);
    dsa1.addStorageDevice(hd3);
    dsa1.addStorageDevice(hd4);

    dsa2.addStorageDevice(ssd1);
    dsa2.addStorageDevice(ssd2);
    dsa2.addStorageDevice(ssd3);
    dsa2.addStorageDevice(ssd4);

    cout << "dsa1's bandwidth: " << dsa1.getBandwidth() << endl;
    cout << "dsa1's latency: " << dsa1.getLatency() << endl;
    cout << "dsa2's effective capacity: " << dsa2.getEffectiveCapacity() << endl;
};