#ifndef STEPPER_MOTOR_H
#define STEPPER_MOTOR_H

#include <Arduino.h>
#include <AccelStepper.h>


class StepperMotor {
    public:
        StepperMotor(int stepPin, int dirPin);
        void emergencyStop();
        void setLastPosition();
        int getLastPosition();
        void moveTo(int positionInSteps);
        bool isRunning();
        void setHome();
        long distanceToGo();
        bool run();
        long currentPosition();
        void setVelocityVariable(int speed, int maxSpeed, int acceleration);
        void setSpeed(int speed);
        void setMaxSpeed(int maxSpeed);
        void setAcceleration(int acceleration);
        bool isTurningClockwise();
        bool isTurningAnticlockwise();
    private:
        int lastPosition = 0;

};


#endif // STEPPER_MOTOR_H