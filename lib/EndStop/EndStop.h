#ifndef ENDSTOP_H
#define ENDSTOP_H

#include <Arduino.h>
#include <StepperMotor.h>

class EndStop {
public:
    EndStop(int pin, StepperMotor* stepperMotor);
    static void handleInterrupt();
    bool isPressed();

private:
    int pin;
    StepperMotor* stepperMotor;
    //static EndStop* instance;
};

#endif // ENDSTOP_H