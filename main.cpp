#include <iostream>

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

int main() {
    int motor_id = 1;
    double speed = 50.0;
    double inputs[4] = {50.0, -40.0, 20.0, 0.0};
    double expected[4] = {33.5, -33.5, 20.0, 0.0};

    for (int i = 0; i < 4; i++)
    {
      speed = limitSpeed(inputs[i]);
      if (speed == expected[i] )
      {
        std::cout << "PASS" <<"\n";
      }
      else{
        std::cout <<"FAIL" << "\n";
      }

    }
    
    

    std::cout << "Motor ID:" << motor_id <<"\n";
    std::cout << "Speed:" <<speed ;
    return 0;
}