#ifndef ENDSTOP_H
#define ENDSTOP_H

#include <Arduino.h>
#include <StepperMotor.h>
#include "Config.h"

class EndStop {
public:
    EndStop(int pin, StepperMotor* stepperMotor);
    bool isPressed();
private:
   
    

};

#endif // ENDSTOP_H