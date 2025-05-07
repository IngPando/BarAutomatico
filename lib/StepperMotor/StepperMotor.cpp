#include "StepperMotor.h"

AccelStepper* motor;

StepperMotor::StepperMotor(int stepPin, int dirPin){
   motor = new AccelStepper(1, stepPin, dirPin);

}


bool StepperMotor::isTurningClockwise() {
    return motor->speed() > 0;
}

bool StepperMotor::isTurningAnticlockwise() {
    return motor->speed() < 0;
}

void StepperMotor::setVelocityVariable(int speed, int maxSpeed, int acceleration){
    motor->setSpeed(speed);
    motor->setMaxSpeed(maxSpeed);
    motor->setAcceleration(acceleration);
}

void StepperMotor::setSpeed(int speed){
    motor->setSpeed(speed);
}

void StepperMotor::setMaxSpeed(int maxSpeed){
    motor->setMaxSpeed(maxSpeed);
}

void StepperMotor::setAcceleration(int acceleration){
    motor->setAcceleration(acceleration);
}

long StepperMotor::distanceToGo(){
    return motor->distanceToGo();
}

bool StepperMotor::run(){
    return motor->run();
}

/*
Abruptly stop the running stepper without deceleration.
This can be called from an interrupt !

The stepper command queue will be processed, but no further commands are
added. This means, that the stepper can be expected to stop within approx.
20ms
*/
void StepperMotor::emergencyStop(){
    motor->stop();
   
}

/*
Set the last position of the stepper motor default to 0
USE ONLY IN STANDSTILL
*/
void StepperMotor::setLastPosition(){
    lastPosition = motor->currentPosition();
}

void StepperMotor::setHome(){
    motor->setCurrentPosition(0);
}

/*
Get the last position of the stepper motor
USE ONLY IN STANDSTILL
*/
int StepperMotor::getLastPosition(){
    return lastPosition;
}

/* move the stepper motor to the desired position in steps */
void StepperMotor::moveTo(long positionInSteps){
        motor->moveTo(positionInSteps);
        Serial.print("Moving to position: ");
        Serial.println(positionInSteps);
}

void StepperMotor::runToHome() {
   motor->moveTo(-10000000);
   Serial.println("Moving to home position...");
}

bool StepperMotor::isHome(){
    return motor->currentPosition() == RAILWAY_MOTOR_HOME_POSITION;
}


/* check if the stepper motor is running */
bool StepperMotor::isRunning(){
    return motor->isRunning();
}

long StepperMotor::currentPosition(){
    return motor->currentPosition();
}
