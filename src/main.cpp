#include <Arduino.h>
#include <Bottle.h>
#include <DrinkRecipe.h>
#include <Config.h>
#include <StepperMotor.h>
#include <AccelStepper.h>
#include <EndStop.h>

StepperMotor* railwayMotor = new StepperMotor(RAILWAY_MOTOR_STEP_PIN,RAILWAY_MOTOR_DIR_PIN);
StepperMotor* pourMotorOne = new StepperMotor(POUR_MOTOR_1_STEP_PIN,POUR_MOTOR_1_DIR_PIN);
StepperMotor* pourMotorTwo = new StepperMotor(POUR_MOTOR_2_STEP_PIN,POUR_MOTOR_2_DIR_PIN);
EndStop* endStopHome;
EndStop* endStopEnd;

DrinkRecipe* ginTonic;


void setup() {
  Serial.begin(9600);

  //railwayMotor -> setVelocityVariable(RAILWAY_MOTOR_SPEED, RAILWAY_MOTOR_MAX_SPEED, RAILWAY_MOTOR_ACCELERATION);
  pourMotorOne -> setVelocityVariable(POUR_MOTOR_SPEED,POUR_MOTOR_MAX_SPEED,POUR_MOTOR_ACCELERATION);
  //pourMotorTwo -> setVelocityVariable(POUR_MOTOR_SPEED,POUR_MOTOR_MAX_SPEED,POUR_MOTOR_ACCELERATION);

  endStopHome = new EndStop(ENDSTOP_HOME_PIN, railwayMotor);
  endStopEnd = new EndStop(ENDSTOP_END_PIN, railwayMotor);

  
  /*
  Bottle* gin = new Bottle("Gin", POSITION_1, 1000);
  Bottle* tonic = new Bottle("Tonic", POSITION_2, 1000);
  DrinkIngredient* ginIngredient = new DrinkIngredient(gin, 1);
  DrinkIngredient* tonicIngredient = new DrinkIngredient(tonic, 3);
  ginTonic = new DrinkRecipe("Gin Tonic");
  ginTonic->addIngredient(ginIngredient);
  ginTonic->addIngredient(tonicIngredient);
  ginTonic->doRecipe(); */

  
 // railwayMotor->runToHome();
  
  pourMotorOne->moveTo(2000);
  //pourMotorTwo->moveTo(2000);
  
}

  


void loop() {

  
  /*if (railwayMotor->isHome())
  {
    delay(2000);
    railwayMotor->moveTo(POSITION_1);
  }*/
   
  
  //railwayMotor->run();
 pourMotorOne->run();
  //pourMotorTwo->run();

}
