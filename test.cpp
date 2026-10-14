#include <cassert>
#include "Motor.h"
#include "DriveController.h"

int main()
{
    Motor leftMotor(1);
    Motor rightMotor(2);

    //测试速度是否是否赋给Motor
    setTrackSpeeds(leftMotor,rightMotor,20,30);
    assert(leftMotor.getSpeed() == 20);
    assert(rightMotor.getSpeed() == 30);

    // 测试差速运动控制及等比例限幅
    driveDifferential(leftMotor, rightMotor, 0.3, 1.0, 0.2, 100);
    assert(leftMotor.getSpeed() == 16.75);
    assert(rightMotor.getSpeed() == 33.5);

    // 测试3：双履带停止
    stopAll(leftMotor, rightMotor);
    // 检查左电机是否停止
    assert(leftMotor.getSpeed() == 0);
    // 检查右电机是否停止
    assert(rightMotor.getSpeed() == 0);

    // 测试4：非法限幅参数
    double leftCommand = 20;
    double rightCommand = -40;
    limitTrackCommands(leftCommand, rightCommand, -10);
    assert(leftCommand == 0);
    assert(rightCommand == 0);


    return 0;
}