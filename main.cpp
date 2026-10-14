#include <iostream>
#include "Motor.h"
#include "DriveController.h"

int main()
{

  Motor leftMotor(1);
  Motor rightMotor(2);

  driveDifferential(
      leftMotor,
      rightMotor,
      0.2,
      0.0,
      0.2,
      100);
    std::cout << "Left Speed:" << leftMotor.getSpeed() << "\n";
    std::cout << "Right Speed:" << rightMotor.getSpeed() << "\n";

    stopAll(leftMotor,rightMotor);
    leftMotor.getSpeed();
    rightMotor.getSpeed();
    std::cout << "Left Speed:" << leftMotor.getSpeed() << "\n";
    std::cout << "Right Speed:" << rightMotor.getSpeed() << "\n";

  return 0;
}