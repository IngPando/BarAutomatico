#ifndef __DRINKRECIPE__
#define __DRINKRECIPE__

#include <arduino.h>
#include "Config.h"
#include "Bottle.h"

// oggetto che contiene un singolo ingrediente di una ricetta e la quantità necessaria
// la quantità è espressa in utilizzi della bottiglia quindi (1,2,3,....)
class DrinkIngredient {
public:
    DrinkIngredient(){
        bottle = Bottle("", 0, 0);
        amount = 0;
    }
    
    DrinkIngredient(Bottle *b, int a) {
        bottle = *b;
        amount = a;
    }
    
    Bottle bottle = Bottle("", 0, 0);
    int amount = 0;
};


class DrinkRecipe {
public:
    DrinkRecipe(String name); 
    void addIngredient(DrinkIngredient *ingredient); // aggiunge un ingrediente alla ricetta
    String getName(); // restituisce il nome della ricetta
    void doRecipe(); // esegue la ricetta
    
private:
    String name; // nome della ricetta es. "Gin Tonic"
    DrinkIngredient recipe[MAX_RECIPE_INGRIDIENTS]; // vettore di ingredienti della ricetta es. {gin, 1}, {tonic, 2}
};

#endif // DRINKRECIPE_H
