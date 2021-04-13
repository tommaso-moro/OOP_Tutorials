main: main.o dataStorageArray.o hardDiskStorageDevice.o solidStateDiskStorageDevice.o storageDevice.o
	g++ -g main.o dataStorageArray.o hardDiskStorageDevice.o solidStateDiskStorageDevice.o storageDevice.o  -o main

main.o: main.cpp
	g++ -Wall -g -c main.cpp

dataStorageArray.o: dataStorageArray.hpp dataStorageArray.cpp
	g++ -Wall -g -c dataStorageArray.cpp

hardDiskStorageDevice.o: hardDiskStorageDevice.cpp hardDiskStorageDevice.hpp
	g++ -Wall -g -c hardDiskStorageDevice.cpp

solidStateDiskStorageDevice.o: solidStateDiskStorageDevice.cpp solidStateDiskStorageDevice.hpp
	g++ -Wall -g -c solidStateDiskStorageDevice.cpp

storageDevice.o: storageDevice.hpp storageDevice.cpp
	g++ -Wall -g -c storageDevice.cpp

clean:
	rm -f *.o clean