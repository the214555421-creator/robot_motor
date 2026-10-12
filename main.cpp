#include <iostream>
#include "Motor.h"
#include "DriveController.h"



int main() {
   

  Motor leftMotor(1);
  Motor rightMotor(2);
 // setTrackSpeeds(leftMotor,rightMotor,20.0,30.0);

 

  //std::cout << "Left Motor Speed:" << leftMotor.getSpeed() << "\n";
    
  
  //std::cout << "Right Motor Speed:" << rightMotor.getSpeed() << "\n";
  
  //turnInPlace(leftMotor,rightMotor,20);
  //std::cout << "Left Motor Speed:" << leftMotor.getSpeed() << "\n";
  //std::cout << "Right Motor Speed:" << rightMotor.getSpeed() << "\n";
  double leftSpeed;
  double rightSpeed;
  calculateTrackSpeeds(0.2,1.0,0.2,leftSpeed,rightSpeed);
  std::cout << "Left Speed:" << leftSpeed << "\n";
  std::cout << "Right Speed:" << rightSpeed << "\n";


    return 0;
}