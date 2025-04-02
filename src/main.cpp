#include <Arduino.h>
#include <Bottle.h>
#include <DrinkRecipe.h>
#include <Config.h>
#include <StepperMotor.h>
#include <AccelStepper.h>
#include <EndStop.h>
#include <MultiStepper.h>

StepperMotor* railwayMotor = new StepperMotor(RAILWAY_MOTOR_STEP_PIN,RAILWAY_MOTOR_DIR_PIN);
AccelStepper* pourMotor = new AccelStepper(AccelStepper::DRIVER,POUR_MOTOR_2_STEP_PIN,POUR_MOTOR_2_DIR_PIN);
//AccelStepper pourMotorOne (AccelStepper::DRIVER,POUR_MOTOR_1_STEP_PIN,POUR_MOTOR_1_DIR_PIN);
//AccelStepper pourMotorTwo (AccelStepper::DRIVER,POUR_MOTOR_2_STEP_PIN,POUR_MOTOR_2_DIR_PIN);
EndStop* endStopHome;
EndStop* endStopEnd;
EndStop* endStopPourBottle;
EndStop* endStopPourBottleHome;

DrinkRecipe* ginTonic;

MultiStepper steppers;


void setup() {
  Serial.begin(9600);

  railwayMotor -> setVelocityVariable(RAILWAY_MOTOR_SPEED, RAILWAY_MOTOR_MAX_SPEED, RAILWAY_MOTOR_ACCELERATION);

  
  pourMotor->setSpeed(POUR_MOTOR_SPEED);
  pourMotor->setMaxSpeed(POUR_MOTOR_MAX_SPEED);
  pourMotor->setAcceleration(POUR_MOTOR_ACCELERATION);
// if Accel Stepper
 /* pourMotorOne.setSpeed(POUR_MOTOR_SPEED);
  pourMotorTwo.setSpeed(POUR_MOTOR_SPEED);
  pourMotorOne.setMaxSpeed(POUR_MOTOR_MAX_SPEED);
  pourMotorTwo.setMaxSpeed(POUR_MOTOR_MAX_SPEED);
  pourMotorOne.setAcceleration(POUR_MOTOR_ACCELERATION);
  pourMotorTwo.setAcceleration(POUR_MOTOR_ACCELERATION);
*/

  endStopHome = new EndStop(ENDSTOP_HOME_PIN, railwayMotor);
  endStopEnd = new EndStop(ENDSTOP_END_PIN, railwayMotor);
  endStopPourBottle = new EndStop(ENDSTOP_POUR_BOTTLE_PIN, pourMotor);
  endStopPourBottleHome = new EndStop(ENDSTOP_POUR_BOTTLE_HOME_PIN, pourMotor);

  

  railwayMotor->runToHome();
  //.addStepper(pourMotorOne);
  //steppers.addStepper(pourMotorTwo);
  while (!railwayMotor->isHome())
  {
    railwayMotor->run();
    yield();
  }
  
  delay(5000);

  //TESTING RECIPE
  Bottle* gin = new Bottle("Gin", POSITION_1, 1000);
  Bottle* tonic = new Bottle("Tonic", POSITION_5, 1000);
  DrinkIngredient* ginIngredient = new DrinkIngredient(gin, 1);
  DrinkIngredient* tonicIngredient = new DrinkIngredient(tonic, 3);
  ginTonic = new DrinkRecipe("Gin Tonic");
  ginTonic->addIngredient(ginIngredient);
  ginTonic->addIngredient(tonicIngredient);
  ginTonic->doRecipe(); 


}

  


void loop() {
/*
  
  if (railwayMotor->isHome())
  {
    delay(2000);
    railwayMotor->moveTo(POSITION_1);
  }
   


  if (railwayMotor->currentPosition() == POSITION_1)
  {
    railwayMotor->moveTo(POSITION_7);
  }
  
  while (railwayMotor->isRunning())
  {
    railwayMotor->run();
    yield();
  } */


 /* steppers.moveTo(positions);
  steppers.runSpeedToPosition(); // Blocks until all are in position
  delay(5000);
  
  // Move to a different coordinate
  positions[0] = POUR_BOTTLE_POSITION;
  positions[1] = POUR_BOTTLE_POSITION;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition(); // Blocks until all are in position
  delay(1000); */



  // DEBUG - Controllo manuale dei motori

  /*long positions[2]; // Array of desired stepper positions
  
  positions[0] = 0;
  positions[1] = 0;

  long railwayPosition[8] = {POSITION_1,POSITION_2,POSITION_3,POSITION_4,POSITION_5,POSITION_6,POSITION_7,POSITION_8};
  static int i = 0;

    if (Serial.available() > 0) {
      char input = Serial.read();
  
      if (input == 0x1B) { // Carattere di escape (inizio sequenza)
        delay(10); // Piccolo ritardo per attendere i prossimi caratteri
        if (Serial.available() > 0 && Serial.read() == 0x5B) { // Secondo carattere '['
          delay(10);
          if (Serial.available() > 0) {
            char arrow = Serial.read(); // Terzo carattere (A, B, C, D)
            static long step;
            switch (arrow) {
              case 0x41: // Freccia su
              
                Serial.println("Freccia su premuta!");
                step += 100;
                positions[0] = step; // Adjust the step value as needed
                positions[1] = step;
                Serial.println(step);
                steppers.moveTo(positions);
                break;
              case 0x42: // Freccia giù
                Serial.println("Freccia giù premuta!");
                step -= 100;
                positions[0] = step; // Adjust the step value as needed
                positions[1] = step;
                Serial.println(step);
                steppers.moveTo(positions);
                break;
              case 0x43: // Freccia destra
                Serial.println("Freccia destra premuta!");
                i++;
                railwayMotor->moveTo(railwayPosition[i]);
              
                break;
              case 0x44: // Freccia sinistra
                Serial.println("Freccia sinistra premuta!");
                i--;
                railwayMotor->moveTo(railwayPosition[i]);
                break;
              default:
                Serial.println("Tasto freccia non riconosciuto.");
                break;
            }
          }
        }
      }
    }
    
    steppers.runSpeedToPosition(); // Blocks until all are in position
    railwayMotor->run();

    */
  }
