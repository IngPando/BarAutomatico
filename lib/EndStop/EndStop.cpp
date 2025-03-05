#include "EndStop.h"

StepperMotor* stepperMotor;
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

EndStop::EndStop(int pin, StepperMotor* stepper) {
    _pin = pin;
    pinMode(_pin, INPUT);
    if (_pin == ENDSTOP_HOME_PIN)
    {
        attachInterrupt(digitalPinToInterrupt(_pin), handleInterrupt, RISING);
        Serial.println("Home endstop attached");
    } else {
        if (_pin == ENDSTOP_END_PIN)
        {
            attachInterrupt(digitalPinToInterrupt(_pin), handleInterruptEnd, RISING);
            Serial.println("End endstop attached"); 
        }
        
    }
   
    stepperMotor = stepper;
    
}







bool EndStop::isPressed() {
    return digitalRead(_pin) == HIGH;
}





