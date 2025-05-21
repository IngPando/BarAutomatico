#include "EndStop.h"

StepperMotor* stepperMotor;
AccelStepper* accelStepper;
int _pin;

//When endstop is pressed Stop instantly the stepper motor
void handleInterrupt() {
    if (stepperMotor->isTurningAnticlockwise())
    {
        //noInterrupts();
        Serial.println("Home pressed");
        stepperMotor->setHome();
        stepperMotor->moveTo(RAILWAY_MOTOR_HOME_POSITION);
        
        //interrupts();
    } 
    
}

void handleInterruptEnd(){
    if (stepperMotor->isTurningClockwise()) {
        //noInterrupts();
        Serial.println("End pressed");
        stepperMotor->setHome();
        stepperMotor->moveTo(-1000);
        //interrupts();
    }
}

void handleInterruptPourBottle(){
    if (accelStepper->speed() > 0) { // platform is rising
        //noInterrupts();
        Serial.println("POUR position reached");
        accelStepper->setCurrentPosition(0);
        accelStepper->moveTo(0);
        //interrupts();
    }
}

void handleInterruptPourBottleHome(){
    if (accelStepper->speed() < 0) { // platform is lowering
        //noInterrupts();
        Serial.println("POUR HOME position reached");
        accelStepper->setCurrentPosition(0);
        accelStepper->moveTo(0);
        //interrupts();
    }
}

EndStop::EndStop(int pin, StepperMotor* stepper) {
    _pin = pin;
    pinMode(_pin, INPUT);
    switch (_pin)
    {
    case ENDSTOP_HOME_PIN:
        attachInterrupt(digitalPinToInterrupt(_pin), handleInterrupt, RISING);
        Serial.println("Home endstop attached");
        break;

    case ENDSTOP_END_PIN:
        attachInterrupt(digitalPinToInterrupt(_pin), handleInterruptEnd, RISING);
        Serial.println("End endstop attached"); 
        break;
    }
    
    stepperMotor = stepper;
    
}


EndStop::EndStop(int pin, AccelStepper* stepper) {
    _pin = pin;
    pinMode(_pin, INPUT);
    switch (_pin)
    {
    
    case ENDSTOP_POUR_BOTTLE_PIN:
        attachInterrupt(digitalPinToInterrupt(_pin), handleInterruptPourBottle, RISING);
        Serial.println("pour endstop attached");
        break;
    case ENDSTOP_POUR_BOTTLE_HOME_PIN:
        attachInterrupt(digitalPinToInterrupt(_pin), handleInterruptPourBottleHome, RISING);
        Serial.println("pour home endstop attached");
        break;
    }
    /*if (_pin == ENDSTOP_HOME_PIN)
    {
        attachInterrupt(digitalPinToInterrupt(_pin), handleInterrupt, RISING);
        Serial.println("Home endstop attached");
    } else {
        if (_pin == ENDSTOP_END_PIN)
        {
            attachInterrupt(digitalPinToInterrupt(_pin), handleInterruptEnd, RISING);
            Serial.println("End endstop attached"); 
        }
        
    }*/
   
    accelStepper = stepper;

}




bool EndStop::isPressed() {
    return digitalRead(_pin) == HIGH;
}





