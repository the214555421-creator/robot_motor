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