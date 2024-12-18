#ifndef ENDSTOP_H
#define ENDSTOP_H

#include <Arduino.h>
#include <StepperMotor.h>

class EndStop {
public:
    EndStop(int pin);
    static void handleInterrupt(StepperMotor* stepperMotor);
    void begin();
    bool isPressed();

private:
    int pin;
    static EndStop* instance;
};

#endif // ENDSTOP_H