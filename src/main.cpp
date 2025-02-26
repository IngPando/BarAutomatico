#include <Arduino.h>
#include <Bottle.h>
#include <DrinkRecipe.h>
#include <Config.h>
#include <StepperMotor.h>
#include <AccelStepper.h>
#include <EndStop.h>

StepperMotor* railwayMotor;
//StepperMotor* pourMotorOne;

//AccelStepper pourMotorOne(1,POUR_MOTOR_1_STEP_PIN,POUR_MOTOR_1_DIR_PIN);
//AccelStepper  railwayMotor(1,RAILWAY_MOTOR_STEP_PIN,RAILWAY_MOTOR_DIR_PIN);

int endStopHomePin = 5;
int endStopEndPin = 6;

void setup() {
  Serial.begin(9600);
  //pourMotorOne = new StepperMotor(POUR_MOTOR_1_STEP_PIN,POUR_MOTOR_1_DIR_PIN);
  railwayMotor = new StepperMotor(RAILWAY_MOTOR_STEP_PIN,RAILWAY_MOTOR_DIR_PIN);
  railwayMotor -> setVelocityVariable(RAILWAY_MOTOR_SPEED, RAILWAY_MOTOR_MAX_SPEED, RAILWAY_MOTOR_ACCELERATION);


  pinMode(endStopHomePin, INPUT);
  pinMode(endStopEndPin, INPUT);
  /* 
  
  Bottle* gin = new Bottle("Gin", POSITION_1, 1000);
  Bottle* tonic = new Bottle("Tonic", POSITION_2, 1000);
  DrinkIngredient* ginIngredient = new DrinkIngredient(gin, 1);
  DrinkIngredient* tonicIngredient = new DrinkIngredient(tonic, 3);
  DrinkRecipe* ginTonic = new DrinkRecipe("Gin Tonic");
  ginTonic->addIngredient(ginIngredient);
  ginTonic->addIngredient(tonicIngredient);
  ginTonic->doRecipe(); */



/*

  if (pourMotorOne.distanceToGo() == 0) {
    pourMotorOne.moveTo(5000);
    pourMotorOne.setMaxSpeed(1000);
    pourMotorOne.setSpeed(200);
    pourMotorOne.setAcceleration(100);
  }
  
  */
/*
  if(railwayMotor.distanceToGo() == 0){
    railwayMotor.moveTo(POSITION_1);
    railwayMotor.setMaxSpeed(RAILWAY_MOTOR_MAX_SPEED);
    railwayMotor.setSpeed(RAILWAY_MOTOR_SPEED);
    railwayMotor.setAcceleration(RAILWAY_MOTOR_ACCELERATION);
  }*/

  railwayMotor->moveTo(POSITION_1);
}

  


void loop() {
  
  if (digitalRead(endStopHomePin) == HIGH && railwayMotor->isTurningAnticlockwise())
  { 
    Serial.println("Home pressed");
    railwayMotor->setHome();
    railwayMotor->moveTo(RAILWAY_MOTOR_HOME_POSITION + 100);
    //railwayMotor->emergencyStop();
  }

  if (digitalRead(endStopEndPin) == HIGH && railwayMotor->isTurningClockwise())
  {
    Serial.println("End pressed");
   // railwayMotor->emergencyStop();
    railwayMotor->moveTo(RAILWAY_MOTOR_HOME_POSITION);
  }
  
  
 /*
  railwayMotor.run();

  if (railwayMotor.distanceToGo() == 0 && railwayMotor.currentPosition() == POSITION_1) {
    Serial.println("Moving to position 2");
    railwayMotor.moveTo(POSITION_2);
  } else if (railwayMotor.distanceToGo() == 0 && railwayMotor.currentPosition() == POSITION_2)
  {
    Serial.println("Moving to position 3");
    railwayMotor.moveTo(POSITION_3);
  } else if (railwayMotor.distanceToGo() == 0 && railwayMotor.currentPosition() == POSITION_3)
  {
    Serial.println("Moving to position 4");
    railwayMotor.moveTo(POSITION_4);
  } else if (railwayMotor.distanceToGo() == 0 && railwayMotor.currentPosition() == POSITION_4)
  {
    Serial.println("Moving to position 5");
    railwayMotor.moveTo(POSITION_5);
  } else if (railwayMotor.distanceToGo() == 0 && railwayMotor.currentPosition() == POSITION_5)
  {
    Serial.println("Moving to position 6");
    railwayMotor.moveTo(POSITION_6);
  } else if (railwayMotor.distanceToGo() == 0 && railwayMotor.currentPosition() == POSITION_6)
  {
    Serial.println("Moving to position 7");
    railwayMotor.moveTo(POSITION_7);
  } else if (railwayMotor.distanceToGo() == 0 && railwayMotor.currentPosition() == POSITION_7)
  {
    Serial.println("Moving to position 8");
    railwayMotor.moveTo(POSITION_8);
  } else if (railwayMotor.distanceToGo() == 0 && railwayMotor.currentPosition() == POSITION_9)
  {
    Serial.println("Moving to position 1");
    railwayMotor.moveTo(POSITION_1);
  }
  */
  
  

  railwayMotor->run();
  railwayMotor->moveTo(POSITION_2);


}
