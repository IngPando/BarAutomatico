#include <Bottle.h>
#include <Config.h>

Bottle::Bottle(const String name, int position, int bottleCapacity) {
    this->name = name;
    this->position = position;
    this->bottleCapacity = bottleCapacity;
    this->usedCounter = 0;
    setMaxUse();
}

// restituisce il nome della bevanda contenuta nella bottiglia
const String Bottle::getName() const {
    return this->name;
}

// restituisce la posizione della bottiglia nel dispenser
int Bottle::getPosition() const {
    return this->position;
}

// restituisce il numero di volte che la bottiglia è stata usata
int Bottle::getUsedCounter() {
    return this->usedCounter;
}

// imposta il numero massimo di volte che la bottiglia può essere usata
void Bottle::setMaxUse() {
    this->maxUse = bottleCapacity / MEASURING_CAP_CAPACITY;
}

// controlla se la bottiglia può essere ancora usata
boolean Bottle::checkBottleUsage() {
    if (this->usedCounter < this->maxUse) {
        return true;
    } else {
        return false;
    }
}

// erogazione delle bevanda
void Bottle::pour() {
    if (checkBottleUsage()) {
        this->usedCounter++;
        printf("Pouring %s from bottle %d\n", this->name.c_str(), this->position);
        // eroga la bevanda
    } else {
        // messaggio di errore
    }
}