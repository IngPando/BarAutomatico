#ifndef STEPPER_MOTOR_H
#define STEPPER_MOTOR_H

#include <Arduino.h>
#include <FastAccelStepper.h>


class StepperMotor {
    public:
        StepperMotor(int stepPin, int dirPin);
        static void init();
        void emergencyStop();
        void setLastPosition();
        int getLastPosition();
        void moveTo(int positionInSteps);
        bool isRunning();
    private:
        int lastPosition = 0;

};


#endif // STEPPER_MOTOR_H