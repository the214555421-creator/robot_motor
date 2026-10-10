#pragma once

double limitSpeed(double requested);

class Motor
{
private: 
    int id_;
    double speed_; 

public:
   Motor(int motorId);
   int getId() const;
   double getSpeed() const;
   void setSpeed(double requested);
   void stop();
};

