#include<iostream>

class Pizza {
private:
    double weight;
    bool isCooked = false;

public:
    Pizza(double weight) : weight(weight) {};
    ~Pizza(){};

    void cook() {
        isCooked = true;
    }

};

class Drone {
    private:
        float initialLat;
        float initialLon;
        float initialAlt;
        float currentLat;
        float currentLon;
        float currentAlt;
        float *targetLat = nullptr;
        float *targetLon = nullptr;
        float *targetAlt = nullptr;
        double cruisingAltitude = 100;
        int maxPizzaWeight = 500;
        Pizza* pizza = nullptr;
        bool droneIsAtTargetLatAndLon = false;

    public:
        Drone(float lat, float lon, float alt) : initialLat(lat), initialLon(lon), initialAlt(alt) {
            currentLat = this->initialLat;
            currentAlt = this->initialAlt;
            currentLon = this->initialLon;
        };
        ~Drone(){};

        void loadPizza(Pizza& pizza) {
            //std::cout << "Loading pizza onto drone." << std::endl;
            this->pizza = &pizza;
        };

        void ascend() {
            //std::cout << "Ascending..." << std::endl;
            currentAlt = cruisingAltitude;
        }

        void moveLaterallyToTargetLocation() {
            if (((targetAlt == nullptr) || (targetLon == nullptr)) || (targetLon == nullptr)) {
                std::cerr << "Error: cannot bring pizza to unspecified target location." << std::endl;
            } else {
                //std::cout << "Moving to target location..." << std::endl;
                currentLon = *targetLon;
                currentLat = *targetLat;
                droneIsAtTargetLatAndLon = true; // if drone is going back, target lat and lon are initial lat and initial lon
            }
        }

        void descend() {
            if (!droneIsAtTargetLatAndLon) {
                std::cerr << "Error: attempting to descend to location that is not target location" << std::endl;
            } else {
                //std::cout << "Descending..." << std::endl;
                currentAlt = *targetAlt;
            }
        }

        void releasePizza() {
            //std::cout << "Dropping off pizza..." << std::endl;
            pizza = nullptr;
        }

        void bringPizzaToLocation(float &targetLat, float &targetLon, float &targetAlt) {
            //std::cout << "About to take off for delivery..." << std::endl;
            this->targetLat = &targetLat;
            this->targetAlt = &targetAlt;
            this->targetLon = &targetLon;

            ascend();
            moveLaterallyToTargetLocation();
            descend();
            releasePizza();
        }

        void setCruisingAltitude(double newCruisingAltitude) {
            cruisingAltitude = newCruisingAltitude;
        };

        void returnToInitialLocation() {
            //std::cout << "About to take off to return to initial location..." << std::endl;
            targetLon = &initialLon;
            targetAlt = &initialAlt;
            targetLat = &initialLat;
            ascend();
            moveLaterallyToTargetLocation();
            descend();
            currentAlt = initialAlt;
        }

        void print() {
            std::cout << std::endl;

            std::cout << "Drone details: " << std::endl;

            std::cout << "\tInitial Latitude: " << initialLat << std::endl;
            std::cout << "\tInitial Longitude: " << initialLon << std::endl;
            std::cout << "\tInitial Altitude: " << initialAlt << std::endl;

            std::cout << std::endl;

            std::cout << "\tTarget Latitude: ";
            if (targetLat != nullptr) {
                std::cout << *targetLat << std::endl;
            } else {
                std::cout << "Target latitude not yet specified" << std::endl;
            }

            std::cout << "\tTarget Longitude: ";
            if (targetLon != nullptr) {
                std::cout << *targetLon << std::endl;
            } else {
                std::cout << "Target longitude not yet specified" << std::endl;
            }

            std::cout << "\tTarget Altitude: ";
            if (targetAlt != nullptr) {
                std::cout << *targetAlt << std::endl;
            } else {
                std::cout << "Target altitude not yet specified" << std::endl;
            }

            std::cout << std::endl;

            std::cout << "\tCurrent Latitude: " << currentLat << std::endl;
            std::cout << "\tCurrent Longitude: " << currentLon << std::endl;
            std::cout << "\tCurrent Altitude: " << currentAlt << std::endl;

        }

};


int main() {
    Drone myDrone = Drone(51.4988, -0.1749, 0);
    Pizza myPizza = Pizza(512);
    myPizza.cook();

    myDrone.loadPizza(myPizza);
    float targetLat = 51.5010;
    float targetLon = -0.1919;
    float targetAlt = 31.5;
    myDrone.bringPizzaToLocation(targetLat, targetLon, targetAlt);
    myDrone.returnToInitialLocation();
};