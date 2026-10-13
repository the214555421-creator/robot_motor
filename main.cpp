#include <iostream>
#include "Motor.h"
#include "DriveController.h"



int main() {
   

  Motor leftMotor(1);
  Motor rightMotor(2);
  
 setTrackSpeeds(leftMotor, rightMotor, 20, 30);

setTrackSpeedsSafe(
    leftMotor,
    rightMotor,
    10,
    15,
    false
);

std::cout << "Left Speed:" << leftMotor.getSpeed() << "\n";
std::cout << "Right Speed:" << rightMotor.getSpeed() << "\n";



}