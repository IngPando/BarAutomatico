#include <Arduino.h>
#include <Bottle.h>
#include <DrinkRecipe.h>
#include <Config.h>

void setup() {
  Bottle gin("Gin", POSITION_1, 1000);
  Bottle tonic("Tonic", POSITION_2, 1000);
  DrinkIngredient ginIngredient(gin, 1);
  DrinkIngredient tonicIngredient(tonic, 3);
  DrinkRecipe ginTonic("Gin Tonic");
  ginTonic.addIngredient(ginIngredient);
  ginTonic.addIngredient(tonicIngredient);
  ginTonic.doRecipe();
}

void loop() {
}
