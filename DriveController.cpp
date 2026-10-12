#include "DriveController.h"

//把给的速度限制后给到对应电机
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

//根据机器人线速度、角速度计算左右履带线速度
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


// 将履带线速度(m/s)转换为电机指令值
// scale 为软件测试比例系数，尚未经过真实电机标定
double trackSpeedToCommand(
    double trackSpeed,
    double scale)
    {
        return  trackSpeed * scale;

    }



// 根据机器人线速度和角速度计算左右履带速度，转换指令后更新电机对象
// v: m/s, omega: rad/s, B: m, scale: 测试转换系数
void driveDifferential(
    Motor& left,
    Motor& right,
    double v,
    double omega,
    double B,
    double scale)
    {
        double leftSpeed;
        double rightSpeed;
        calculateTrackSpeeds(v,omega,B,leftSpeed,rightSpeed);
        double leftCommand = trackSpeedToCommand(leftSpeed, scale);
        double rightCommand = trackSpeedToCommand(rightSpeed, scale);
        setTrackSpeeds(left, right, leftCommand, rightCommand);
    }

