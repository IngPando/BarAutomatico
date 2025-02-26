#ifndef __CONFIG__
#define __CONFIG__

#define BAUDRATE 9600 
#define NUM_BOTTLES 8   // numero di bottiglie nel dispenser
#define MEASURING_CAP_CAPACITY 30 // ml del dosatore per la misurazione della capacità delle bottiglie
#define MAX_RECIPE_INGRIDIENTS 2 // numero massimo di ingredienti per ricetta

#define RAILWAY_MOTOR_STEP_PIN 9
#define RAILWAY_MOTOR_DIR_PIN 8
#define RAILWAY_MOTOR_SPEED 1000
#define RAILWAY_MOTOR_MAX_SPEED 100000
#define RAILWAY_MOTOR_ACCELERATION 10000


#define POUR_MOTOR_1_STEP_PIN 16 
#define POUR_MOTOR_1_DIR_PIN 3
#define POUR_MOTOR_2_STEP_PIN 17
#define POUR_MOTOR_2_DIR_PIN 4
#define POUR_MOTOR_SPEED 200
#define POUR_MOTOR_MAX_SPEED 1000
#define POUR_MOTOR_ACCELERATION 100

#define POUR_BOTTLE_POSITION 1000
#define POUR_BOTTLE_HOME_POSITION 0

// numero di step per la posizione delle bottiglie nel dispenser
#define RAILWAY_MOTOR_HOME_POSITION 0
#define POSITION_1 11725  
#define POSITION_2 21225
#define POSITION_3 30725
#define POSITION_4 40225
#define POSITION_5 49725
#define POSITION_6 59225
#define POSITION_7 68725
#define POSITION_8 78225
#define POSITION_9 87725

#endif