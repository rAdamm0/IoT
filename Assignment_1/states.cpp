#include "config.h"
#include "sleep.h"
#include "buttons.h"
#include "leds.h"
#include "lcd.h"

#include <Arduino.h>

/**
  Initializes the system for its initial phase
*/
void initializeStart(){
  Serial.println("Initializing Timer");
  initializeTimer();
  Serial.println("Initializing Start");
  attachGameStart();
  Serial.println("Changing message");
  changeMessage(WELCOME, true);
}

/**
  Initializes the system for the game phase
*/
void initializeGame(){
  changeMessage("", false);
  timerStop();
  attachCounter();
  off();
}

/**
  Starts the game over timer
*/
void gameOverTimer();

/**
  Starts the end game and reset timer
*/
void endTimer(){
  initializeTimer();
}