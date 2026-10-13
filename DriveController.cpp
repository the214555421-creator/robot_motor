#include "DriveController.h"
#include <cmath>
#include <algorithm>

//将指令速度写入左右 Motor 对象
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
        limitTrackCommands(leftCommand,rightCommand,33.5);
        setTrackSpeeds(left, right, leftCommand, rightCommand);
    }

//实现限幅逻辑，速度最大等比缩小
    void limitTrackCommands(
    double& leftCommand,
    double& rightCommand,
    double maxCommand)
{
    double maxAbs = std::max(
        std::abs(leftCommand),
        std::abs(rightCommand)
    );

    // 异常速度指令提前退出
    if (maxCommand <= 0)
    {
        leftCommand = 0;
        rightCommand = 0;
        return ;
    }

     if (maxAbs > maxCommand)
    {
       double k = maxCommand / maxAbs;
       
       leftCommand *= k;
       rightCommand *=k;  
    }
}

// 同时清零左右履带电机的速度指令
void stopAll(Motor& left, Motor& right){
   left.stop();
   right.stop();
}

// 根据紧急停止状态决定清零电机指令或执行运动指令
void setTrackSpeedsSafe(
    Motor& left,
    Motor& right,
    double leftSpeed,
    double rightSpeed,
    bool emergencyStopActive)
{
    if (emergencyStopActive)
    {
         stopAll(left,right);
    }
    else
    {
       setTrackSpeeds(left,right,leftSpeed,rightSpeed);
    }
}