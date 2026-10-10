#include <iostream>
#include "Motor.h"

int main() {
   

    Motor leftMotor(1);
    leftMotor.setSpeed(50.0);
    std::cout << "\nObject ID:" << leftMotor.getId() << "\n";
    std::cout << "Object Speed:" << leftMotor.getSpeed() << "\n";
    leftMotor.stop();
    std::cout << "After speed:" << leftMotor.getSpeed() << "\n";

    return 0;
}