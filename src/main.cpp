#include <Arduino.h>
#include <Bottle.h>
#include <DrinkRecipe.h>
#include <Config.h>
#include <StepperMotor.h>
#include <AccelStepper.h>
#include <EndStop.h>
#include <MultiStepper.h>
#include <Button.h>

StepperMotor* railwayMotor = new StepperMotor(RAILWAY_MOTOR_STEP_PIN,RAILWAY_MOTOR_DIR_PIN);
AccelStepper* pourMotor = new AccelStepper(AccelStepper::DRIVER,POUR_MOTOR_2_STEP_PIN,POUR_MOTOR_2_DIR_PIN);

EndStop* endStopHome;
EndStop* endStopEnd;
EndStop* endStopPourBottle;
EndStop* endStopPourBottleHome;

DrinkRecipe* ginTonic;
DrinkRecipe* vodkaTonic;
DrinkRecipe* americano;
DrinkRecipe* negroni;
DrinkRecipe* spritz;
DrinkRecipe* spritzCampari;


MultiStepper steppers;

Button* recipeButton1 = new Button(RECIPE_BUTTON_1_PIN); // Pin 30 for the button
Button* recipeButton2 = new Button(RECIPE_BUTTON_2_PIN); // Pin 31 for the button
Button* recipeButton3 = new Button(RECIPE_BUTTON_3_PIN); // Pin 32 for the button
Button* recipeButton4 = new Button(RECIPE_BUTTON_4_PIN); // Pin 33 for the button
Button* recipeButton5 = new Button(RECIPE_BUTTON_5_PIN); // Pin 34 for the button
Button* emergencyStopButton = new Button(EMERGENCY_BUTTON_PIN); // Pin 35 for the button

// se la macchina non sta preparando una ricetta isWaiting = true
bool isWaiting = true;

void setup() {
  Serial.begin(9600);

  railwayMotor -> setVelocityVariable(RAILWAY_MOTOR_SPEED, RAILWAY_MOTOR_MAX_SPEED, RAILWAY_MOTOR_ACCELERATION);
  
  pourMotor->setSpeed(POUR_MOTOR_SPEED);
  pourMotor->setMaxSpeed(POUR_MOTOR_MAX_SPEED);
  pourMotor->setAcceleration(POUR_MOTOR_ACCELERATION);


  endStopHome = new EndStop(ENDSTOP_HOME_PIN, railwayMotor);
  endStopEnd = new EndStop(ENDSTOP_END_PIN, railwayMotor);
  endStopPourBottle = new EndStop(ENDSTOP_POUR_BOTTLE_PIN, pourMotor);
  endStopPourBottleHome = new EndStop(ENDSTOP_POUR_BOTTLE_HOME_PIN, pourMotor);

  
// RUN TO HOME ON FIRST START
  railwayMotor->runToHome();
  while (!railwayMotor->isHome())
  {
    railwayMotor->run();
    yield();
  }
  
  delay(5000); 

  //BOTTLE
  Bottle* gin = new Bottle("Gin", POSITION_1, 1000);
  Bottle* vodka = new Bottle("Vodka", POSITION_2, 1000);
  Bottle* campari = new Bottle("name3",POSITION_3,1000);
  Bottle* vermout = new Bottle("name4",POSITION_4,1000);
  Bottle* tonic = new Bottle("Tonic", POSITION_5, 1000);
  Bottle* aperol = new Bottle("Aperol", POSITION_6, 1000);
  Bottle* prosecco = new Bottle("Prosecco",POSITION_7,1000);
  Bottle* eight = new Bottle("name8",POSITION_8,1000);

  // DRINK INGREDIENT
  DrinkIngredient* ginIngredient = new DrinkIngredient(gin, 1); // ta = false by default = pour 1 time
  DrinkIngredient* tonicIngredient = new DrinkIngredient(tonic, 5000, true); // ta true = pour for 5000 ms
  DrinkIngredient* tonicIngredientHalf = new DrinkIngredient(tonic, 2500, true);
  DrinkIngredient* vodkaIngredient = new DrinkIngredient(vodka, 1);
  DrinkIngredient* campariIngredient = new DrinkIngredient(campari,1);
  DrinkIngredient* campariIngredientDouble = new DrinkIngredient(campari, 2);
  DrinkIngredient* vermoutIngredient = new DrinkIngredient(vermout,1);
  DrinkIngredient* aperolIngredient = new DrinkIngredient(aperol,2);
  DrinkIngredient* proseccoIngredient = new DrinkIngredient(prosecco, 1);


  //GIN TONIC RECIPE
  ginTonic = new DrinkRecipe("Gin Tonic");
  ginTonic->addIngredient(ginIngredient); 
  ginTonic->addIngredient(tonicIngredient);

  // VODKA TONIC RECIPE
  vodkaTonic = new DrinkRecipe("Vodka Tonic");
  vodkaTonic->addIngredient(vodkaIngredient);
  vodkaTonic->addIngredient(tonicIngredient);

  // AMERICANO RECIPE
  americano = new DrinkRecipe("Americano");
  americano->addIngredient(campariIngredient);
  americano->addIngredient(vermoutIngredient);
  americano->addIngredient(tonicIngredient);

  // NEGRONI RECIPE
  negroni = new DrinkRecipe("Negroni");
  negroni->addIngredient(campariIngredient);
  negroni->addIngredient(vermoutIngredient);
  negroni->addIngredient(ginIngredient);


  // SPRITZ APEROL RECIPE
  spritz = new DrinkRecipe("Spritz Aperol");
  spritz->addIngredient(aperolIngredient);
  spritz->addIngredient(proseccoIngredient);
  spritz->addIngredient(tonicIngredientHalf);

  // SPRITZ CAMPARI RECIPE
  spritzCampari = new DrinkRecipe("Spritz Aperol");
  spritzCampari->addIngredient(campariIngredientDouble);
  spritzCampari->addIngredient(proseccoIngredient);
  spritzCampari->addIngredient(tonicIngredientHalf);

}

  


void loop() {

  if (recipeButton1->isPressed() && isWaiting) {
      Serial.println("Recipe Button 1 is Pressed");
      isWaiting = false;
      ginTonic->doRecipe();
  }

  if (recipeButton2->isPressed() && isWaiting) {
      Serial.println("Recipe Button 2 is Pressed!");
      isWaiting = false;
      vodkaTonic->doRecipe();
  }

  if (recipeButton3->isPressed() && isWaiting) {
    Serial.println("Recipe Button 3 is Pressed");
    isWaiting = false;
    americano->doRecipe();
  }

  if (recipeButton4->isPressed() && isWaiting) {
    Serial.println("Recipe Button 4 is Pressed");
    isWaiting = false;
    negroni->doRecipe();
  }

  if (recipeButton5->isPressed() && isWaiting) {
    isWaiting = false;
    Serial.println("Recipe Button 5 is Pressed");
  }
  
  if (emergencyStopButton->isPressed()) {
    isWaiting = false;
    Serial.println("EMERCENCY STOP is Pressed");
    railwayMotor->setHome();
    railwayMotor->moveTo(RAILWAY_MOTOR_HOME_POSITION);
    pourMotor->setCurrentPosition(0);
    pourMotor->moveTo(-1000);
  }
    
  }
