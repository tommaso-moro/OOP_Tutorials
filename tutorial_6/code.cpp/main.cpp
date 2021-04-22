#include <iostream>
#include"zooAnimal.cpp"


int main() {
    ZooAnimal<std::string, int> myZooAnimal = ZooAnimal<std::string, int>("Tiger", 15, 12, "test");
    return 0;
};
