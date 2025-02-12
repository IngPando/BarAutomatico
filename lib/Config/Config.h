#ifndef __CONFIG__
#define __CONFIG__

#define BAUDRATE 9600 
#define NUM_BOTTLES 8   // numero di bottiglie nel dispenser
#define MEASURING_CAP_CAPACITY 30 // ml del dosatore per la misurazione della capacità delle bottiglie
#define MAX_RECIPE_INGRIDIENTS 2 // numero massimo di ingredienti per ricetta

#define RAILWAY_MOTOR_STEP_PIN 9
#define RAILWAY_MOTOR_DIR_PIN 8
#define POUR_MOTOR_1_STEP_PIN 16 
#define POUR_MOTOR_1_DIR_PIN 3

#define POUR_BOTTLE_POSITION 1000
#define POUR_BOTTLE_HOME_POSITION 0

// numero di step per la posizione delle bottiglie nel dispenser
#define POSITION_1 4000  
#define POSITION_2 1500
#define POSITION_3 3
#define POSITION_4 4
#define POSITION_5 5
#define POSITION_6 6
#define POSITION_7 7
#define POSITION_8 8

#endif