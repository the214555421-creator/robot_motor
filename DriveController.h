#pragma once
#include "Motor.h"

void setTrackSpeeds(
    Motor& left,
    Motor& right,
    double leftSpeed,
    double rightSpeed);

void turnInPlace(
    Motor& left,
    Motor& right,
    double speed);

void calculateTrackSpeeds(
    double v,
    double omega,
    double B,
    double& leftSpeed,
    double& rightSpeed);