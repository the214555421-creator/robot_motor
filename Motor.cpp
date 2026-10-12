#include "Motor.h"

// 速度保护，防止溢出
double limitSpeed(double requested)
{
    if (requested > 33.5)
    {
        return 33.5;
    }
    else if(requested < -33.5){
        return -33.5;
    }
    else{
        return requested;
    }

   
}

// 定义Motor类，得到id和速度
     Motor::Motor(int motorId)
        : id_(motorId),speed_(0.0){
        
        }

        int Motor::getId() const
        {
            return id_;
        }

        double Motor::getSpeed() const
        {
            return speed_;
        }

        //设置速度，防止溢出
        void Motor::setSpeed(double requested)
        {
            speed_ = limitSpeed(requested);
        }

        //停止，速度归0
        void Motor::stop()
        {
            speed_ = 0;
        }