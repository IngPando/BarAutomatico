#include <Arduino.h>
#include <Bottle.h>
#include <DrinkRecipe.h>
#include <Config.h>
#include <StepperMotor.h>
#include <AccelStepper.h>

//StepperMotor* railwayMotor;
//StepperMotor* pourMotorOne;

AccelStepper pourMotorOne(1,16,3);
AccelStepper  railwayMotor(1,9,8);

void setup() {
 /* railwayMotor = new StepperMotor(RAILWAY_MOTOR_STEP_PIN,RAILWAY_MOTOR_DIR_PIN);
  pourMotorOne = new StepperMotor(POUR_MOTOR_1_STEP_PIN,POUR_MOTOR_1_DIR_PIN);
  
  railwayMotor->init();
  pourMotorOne->init();

  
  Bottle* gin = new Bottle("Gin", POSITION_1, 1000);
  Bottle* tonic = new Bottle("Tonic", POSITION_2, 1000);
  DrinkIngredient* ginIngredient = new DrinkIngredient(gin, 1);
  DrinkIngredient* tonicIngredient = new DrinkIngredient(tonic, 3);
  DrinkRecipe* ginTonic = new DrinkRecipe("Gin Tonic");
  ginTonic->addIngredient(ginIngredient);
  ginTonic->addIngredient(tonicIngredient);
  ginTonic->doRecipe(); */



  
}

void loop() {
  if (railwayMotor.distanceToGo() == 0) {
    railwayMotor.moveTo(1000);
    railwayMotor.setMaxSpeed(1000);
    railwayMotor.setSpeed(500);
    railwayMotor.setAcceleration(200);
  }
  /*if (pourMotorOne.distanceToGo() == 0) {
    pourMotorOne.moveTo(50000);
    pourMotorOne.setMaxSpeed(2000);
    pourMotorOne.setSpeed(500);
    pourMotorOne.setAcceleration(1000);
  }*/
  railwayMotor.run();
  if (railwayMotor.distanceToGo() == 0)
  {
    railwayMotor.moveTo(-20000);
    railwayMotor.setMaxSpeed(1000);
    railwayMotor.setSpeed(500);
    railwayMotor.setAcceleration(200);
  }
  railwayMotor.run();
  

  //pourMotorOne.run();

  /*railwayMotor->moveTo(POSITION_1);
  delay(2000);
  railwayMotor->moveTo(POSITION_3);*/
}
