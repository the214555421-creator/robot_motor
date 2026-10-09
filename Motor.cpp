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
