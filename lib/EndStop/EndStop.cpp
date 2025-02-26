#include "EndStop.h"



EndStop::EndStop(int pin, StepperMotor* stepper) {
    pinMode(pin, INPUT);
    //attachInterrupt(digitalPinToInterrupt(pin), EndStop::handleInterrupt, RISING);
    stepperMotor = stepper;
   // instance = this;
}

//When endstop is pressed Stop instantly the stepper motor
void EndStop::handleInterrupt() {
    /*if (instance->isPressed()) {
        instance->stepperMotor->emergencyStop();
        instance->stepperMotor->setLastPosition();
    }*/
}

bool EndStop::isPressed() {
    return digitalRead(pin) == HIGH;
}





