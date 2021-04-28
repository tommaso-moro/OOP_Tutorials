#include<iostream>
#include<math.h>

const double X_BASKET = 7.5;
const double Y_BASKET = 1.575;
const double a = 0.62;
const double b = 6.84;
const int POINTS_SUCCESSFUL_SHOT_INSIDE_THREE_POINT_LINE = 2;
const int POINTS_SUCCESSFUL_SHOT_OUTSIDE_THREE_POINT_LINE = 3;
const int POINTS_UNSUCCESSFUL_SHOT = 0;

enum playerShootingPos { INSIDE_THREE_POINT_LINE, OUTSIDE_THREE_POINT_LINE };

double getEuclideanDistanceBetweenTwoPoints(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x1-x2), 2) + pow((y1-y2), 2));
}


playerShootingPos getPlayerPosWithRespectToThreePointLine(double playerX, double playerY) {
    double distanceBetweenPlayerAndBasket = getEuclideanDistanceBetweenTwoPoints(playerX, playerY, X_BASKET, Y_BASKET);
    if (distanceBetweenPlayerAndBasket < 3.0) {
        return INSIDE_THREE_POINT_LINE;
    } else {
        return OUTSIDE_THREE_POINT_LINE;
    }
}

class Player {
private:
    double xCoordinate;
    double yCoordinate;
    double skillFactor; //from 0 to 1
    bool hasTheBall = false;
    int latestShotPoints = 0;

public:
    Player(double skillFactor, double xCoordinate, double yCoordinate, bool hasTheBall = false) : skillFactor(skillFactor), xCoordinate(xCoordinate), \
    yCoordinate(yCoordinate), hasTheBall(hasTheBall) {};

    void moveToCoordinates(double targetX, double targetY) {
        xCoordinate = targetX;
        yCoordinate = targetY;
    }

    void hasBall() {
        hasTheBall = true;
    }

    void passBallTo(Player &player) {
        if (this->hasTheBall) {
            player.hasBall();
            this->hasTheBall = false;
        } else {
            std::cerr << "A player cannot pass the ball if they haven't got it!" << std::endl;
        }
    }

    void shoot() {
        double distancePlayerBasket = sqrt(pow((xCoordinate-X_BASKET), 2) + pow((yCoordinate-Y_BASKET), 2));
        double successProbability = 1 - (1/(1 + exp((distancePlayerBasket-b*skillFactor)*(-1 * a))));
        double randomNum = drand48(); //rand number between 0 and 1
        if (successProbability > randomNum) { //the shot was successful
            if (getPlayerPosWithRespectToThreePointLine(xCoordinate, yCoordinate) == INSIDE_THREE_POINT_LINE) {
                latestShotPoints = 3;
            } else {
                latestShotPoints = 2;
            }
        } else {
            latestShotPoints = 0;
        }
    };

    int getLatestShotPoints() {
        return latestShotPoints;
    }
};

int main() {
    Player larry = Player(0.9, 4.5, 3.25);
    Player michael = Player(0.95, 10.5, 5.1, true);

    larry.moveToCoordinates(0.25, 2.2);
    michael.passBallTo(larry);
    larry.shoot();
    std::cout << larry.getLatestShotPoints() << std::endl;
}