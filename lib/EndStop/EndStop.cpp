#include "EndStop.h"


EndStop::EndStop(int pin) {
    pinMode(pin, INPUT);
    attachInterrupt(digitalPinToInterrupt(pin), EndStop::handleInterrupt, RISING);
    instance = this;
}

bool EndStop::isPressed() {
    return digitalRead(pin) == HIGH;
}

// Handle the interrupt when the endstop is pressed Stopping instantly the stepper motor
void EndStop::handleInterrupt(StepperMotor* stepperMotor) {
    if (instance->isPressed()) {
        stepperMotor->stop();
    }
}

