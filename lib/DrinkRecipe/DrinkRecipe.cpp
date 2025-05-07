#include "DrinkRecipe.h"
#include "StepperMotor.h"
#include "MultiStepper.h"
#include "Config.h"

extern StepperMotor *railwayMotor;
extern AccelStepper *pourMotor;
extern bool isWaiting;

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

    railwayMotor->runToHome();
    while (!railwayMotor->isHome())
    {
        railwayMotor->run();
        yield();
    }
    delay(5000);
    // per ogni ingrediente della ricetta
    Serial.println("Ricetta: ");
    Serial.println(this->name);
    for (int i = 0; i < MAX_RECIPE_INGRIDIENTS; i++) {
        Serial.println("Erogo: ");
        Serial.println(recipe[i].bottle.getName());
        // se la quantità è 0 allora l'ingrediente non è stato ancora impostato
        if (recipe[i].amount == 0) {
            break;
        }
        //sposta il bicchiere sotto la bevanda giusta
        railwayMotor->moveTo(recipe[i].bottle.getPosition());
        Serial.println("Sposto bicchiere sotto la bevanda");
        Serial.println(recipe[i].bottle.getPosition());
        // aspetta che il motore sia fermo
        while (railwayMotor->isRunning() && railwayMotor->currentPosition() != recipe[i].bottle.getPosition()) {
            railwayMotor->run();
            yield();
        }

        // eroga la quantità necessaria
        Serial.println("Erogo la quantità necessaria");
        // se l'ingrediente è una bottiglia non alcolica allora eroga la quantità specificata per il tempo specificato
        if (recipe[i].isTimeAmount) {
            // la quantità è espressa in ms, eroga per il tempo specificato
            long pourBottlePosition = POUR_BOTTLE_POSITION;
            pourMotor->moveTo(pourBottlePosition);
            
                pourMotor->runToPosition();
            
            delay(recipe[i].amount); // aspetta il tempo specificato in ms
            
            Serial.println("Posizione: Casa");
            long pourBottleHomePosition = POUR_BOTTLE_HOME_POSITION;
            pourMotor->moveTo(pourBottleHomePosition);
            
                pourMotor->runToPosition();
            
        } else
        {
            for (int j = 0; j < recipe[i].amount; j++) {
                if(recipe[i].bottle.pour()){
                    Serial.println("posizione: Erogazione");
                    long pourBottlePosition = POUR_BOTTLE_POSITION;
                    pourMotor->moveTo(pourBottlePosition);
                    
                        pourMotor->runToPosition();
                    
                    delay(5000);
                    Serial.println("Posizione: Casa");
                    long pourBottleHomePosition = POUR_BOTTLE_HOME_POSITION;
                    pourMotor->moveTo(pourBottleHomePosition);
                    
                        pourMotor->runToPosition();
                    
                } else {
                    //la bottiglia è finita
                    //steppers.emergencyStop();
                    break;
                }
                
            }
        }
    }

    railwayMotor->runToHome();
    while (!railwayMotor->isHome())
    {
      railwayMotor->run();
      yield();
    }

    //la macchina torna nello stato di "sto aspettando"
    isWaiting = true;
}
