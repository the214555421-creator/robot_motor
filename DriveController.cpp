#include "DriveController.h"

void setTrackSpeeds(
    Motor& left,
    Motor& right,
    double leftSpeed,
    double rightSpeed)
{
    
    left.setSpeed (leftSpeed);
    right.setSpeed(rightSpeed);

}

void turnInPlace(
    Motor& left,
    Motor& right,
    double speed)
    {
        setTrackSpeeds(left,right,-speed,speed);

    }

void calculateTrackSpeeds(
    double v,
    double omega,
    double B,
    double& leftSpeed,
    double& rightSpeed)
    {
        
        leftSpeed = v - (omega * B) / 2;
        rightSpeed = v + (omega * B) / 2;
    
    }