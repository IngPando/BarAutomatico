#include "DrinkRecipe.h"
#include "StepperMotor.h"

extern StepperMotor *railwayMotor;
extern StepperMotor *pourMotorOne;

// costruttore della ricetta
DrinkRecipe::DrinkRecipe(String name) {
    this->name = name;
}

// restituisce il nome della ricetta
String DrinkRecipe::getName() {
    return this->name;
}

// aggiunge un ingrediente alla ricetta
void DrinkRecipe::addIngredient(DrinkIngredient *ingredient) {
    // cerca la prima posizione libera e aggiunge l'ingrediente
    for (int i = 0; i < MAX_RECIPE_INGRIDIENTS; i++) {
        // se la quantità è 0 allora l'ingrediente non è stato ancora impostato
        if (recipe[i].amount == 0) {
            recipe[i] = *ingredient;
            break;
        }
    }
}

void DrinkRecipe::doRecipe() {
    // per ogni ingrediente della ricetta
    for (int i = 0; i < MAX_RECIPE_INGRIDIENTS; i++) {
        // se la quantità è 0 allora l'ingrediente non è stato ancora impostato
        if (recipe[i].amount == 0) {
            break;
        }
        //sposta il bicchiere sotto la bevanda giusta
        railwayMotor->moveTo(recipe[i].bottle.getPosition());
        railwayMotor->run();

        /*while(railwayMotor->isRunning()){
            delay(100);
        }*/

        
        // eroga la quantità necessaria
        for (int j = 0; j < recipe[i].amount; j++) {
            if(recipe[i].bottle.pour()){
                pourMotorOne->moveTo(POUR_BOTTLE_POSITION);
                delay(5000);
                pourMotorOne->moveTo(POUR_BOTTLE_HOME_POSITION);
            } else {
                //la bottiglia è finita
                pourMotorOne->emergencyStop();
                break;
            }
            
        }
    }
}
