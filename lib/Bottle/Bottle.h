#ifndef __BOTTLE__
#define __BOTTLE__

#include <Arduino.h>


class Bottle {
public:

    Bottle(const String name, int position, int bottleCapacity);

    const String getName() const;
    int getPosition() const;    // restituisce la posizione della bottiglia nel dispenser
    int getUsedCounter(); // restituisce il numero di volte che la bottiglia è stata usata

    void setMaxUse();        // imposta il numero massimo di volte che la bottiglia può essere usata

    boolean checkBottleUsage();       // controlla se la bottiglia può essere ancora usata

    void pour(); // erogazione delle bevanda

private:
    String name;    // il nome della bevanda contenuta nella bottiglia
    int position; // la posizione della bottiglia nel dispenser
    int maxUse; // il numero massimo di volte che la bottiglia può essere usata
    int usedCounter = 0; // il numero di volte che la bottiglia è stata usata
    int bottleCapacity; // la capacità della bottiglia in ml
};

#endif // BOTTLE_H