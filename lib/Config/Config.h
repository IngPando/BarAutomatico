#ifndef __CONFIG__
#define __CONFIG__

#define ENDSTOP_HOME_PIN 18 //20
#define ENDSTOP_END_PIN 19  //21
#define ENDSTOP_POUR_BOTTLE_PIN 3
#define ENDSTOP_POUR_BOTTLE_HOME_PIN 2

#define BAUDRATE 9600 
#define NUM_BOTTLES 8   // numero di bottiglie nel dispenser
#define MEASURING_CAP_CAPACITY 30 // ml del dosatore per la misurazione della capacità delle bottiglie
#define MAX_RECIPE_INGRIDIENTS 2 // numero massimo di ingredienti per ricetta

#define RAILWAY_MOTOR_STEP_PIN 9
#define RAILWAY_MOTOR_DIR_PIN 8
#define RAILWAY_MOTOR_SPEED 1000
#define RAILWAY_MOTOR_MAX_SPEED 1000000
#define RAILWAY_MOTOR_ACCELERATION 2000 //2000 tested good acceleration


#define POUR_MOTOR_1_STEP_PIN 16 
#define POUR_MOTOR_1_DIR_PIN 3 
#define POUR_MOTOR_2_STEP_PIN 17
#define POUR_MOTOR_2_DIR_PIN 4
#define POUR_MOTOR_SPEED 2000
#define POUR_MOTOR_MAX_SPEED 2000
#define POUR_MOTOR_ACCELERATION 2000

#define POUR_BOTTLE_POSITION 2000
#define POUR_BOTTLE_HOME_POSITION -2000

// numero di step per la posizione delle bottiglie nel dispenser
#define RAILWAY_MOTOR_HOME_POSITION 100
#define POSITION_1 11725  
#define POSITION_2 21225
#define POSITION_3 30725
#define POSITION_4 40225
#define POSITION_5 49725
#define POSITION_6 59225
#define POSITION_7 68725
#define POSITION_8 78225
#define POSITION_9 87725

//bottoni per eseguire le ricette
#define RECIPE_BUTTON_1_PIN 30
#define RECIPE_BUTTON_2_PIN 31
#define RECIPE_BUTTON_3_PIN 32
#define RECIPE_BUTTON_4_PIN 33
#define RECIPE_BUTTON_5_PIN 34
#define RECIPE_BUTTON_6_PIN 35



#endif