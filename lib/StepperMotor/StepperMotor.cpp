#include "StepperMotor.h"

FastAccelStepperEngine stepperEngine = FastAccelStepperEngine();
FastAccelStepper *motor = NULL;


// Initialize the stepper motor ENGINE only to do it once before using the stepper motor
void StepperMotor::init() {
    stepperEngine.init();
}

StepperMotor::StepperMotor(int stepPin, int dirPin){
    motor = stepperEngine.stepperConnectToPin(stepPin);
    motor->setDirectionPin(dirPin);
    motor->setSpeedInHz(10000);
}

/*
Abruptly stop the running stepper without deceleration.
This can be called from an interrupt !

The stepper command queue will be processed, but no further commands are
added. This means, that the stepper can be expected to stop within approx.
20ms
*/
void StepperMotor::emergencyStop(){
    motor->forceStop();
}

/*
Set the last position of the stepper motor default to 0
USE ONLY IN STANDSTILL
*/
void StepperMotor::setLastPosition(){
    lastPosition = motor->getCurrentPosition();
}

/*
Get the last position of the stepper motor
USE ONLY IN STANDSTILL
*/
int StepperMotor::getLastPosition(){
    return lastPosition;
}

/* move the stepper motor to the desired position in steps */
void StepperMotor::moveTo(int positionInSteps){
    motor->runForward();
}

/* check if the stepper motor is running */
bool StepperMotor::isRunning(){
    return motor->isRunning();
}

