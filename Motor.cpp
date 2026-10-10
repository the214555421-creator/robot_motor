#include "Motor.h"
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

        void Motor::setSpeed(double requested)
        {
            speed_ = limitSpeed(requested);
        }

        void Motor::stop()
        {
            speed_ = 0;
        }