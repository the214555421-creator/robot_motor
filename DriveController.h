#pragma once
#include "Motor.h"


//设置左右 Motor 对象的指令值
void setTrackSpeeds(
    Motor& left,
    Motor& right,
    double leftSpeed,
    double rightSpeed);


void turnInPlace(
    Motor& left,
    Motor& right,
    double speed);

//根据机器人线速度、角速度计算左右履带速度
void calculateTrackSpeeds(
    double v,
    double omega,
    double B,
    double& leftSpeed,
    double& rightSpeed);

// 将履带线速度(m/s)转换为电机指令值
// scale 为软件测试比例系数，尚未经过真实电机标定
double trackSpeedToCommand(
    double trackSpeed,
    double scale);

//调用已经完成的三个函数
void driveDifferential(
    Motor& left,
    Motor& right,
    double v,
    double omega,
    double B,
    double scale);

    // 对左右电机指令进行等比例限幅
// maxCommand: 允许的最大指令绝对值，要求大于0
void limitTrackCommands(
    double& leftCommand,
    double& rightCommand,
    double maxCommand);
