#include "DrinkRecipe.h"

// costruttore della ricetta
DrinkRecipe::DrinkRecipe(String name) {
    this->name = name;
}

// restituisce il nome della ricetta
String DrinkRecipe::getName() {
    return this->name;
}

// aggiunge un ingrediente alla ricetta
void DrinkRecipe::addIngredient(DrinkIngredient ingredient) {
    // cerca la prima posizione libera e aggiunge l'ingrediente
    for (int i = 0; i < MAX_RECIPE_INGRIDIENTS; i++) {
        // se la quantità è 0 allora l'ingrediente non è stato ancora impostato
        if (recipe[i].amount == 0) {
            recipe[i] = ingredient;
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
        // eroga la quantità necessaria
        for (int j = 0; j < recipe[i].amount; j++) {
            recipe[i].bottle.pour();
        }
    }
}
