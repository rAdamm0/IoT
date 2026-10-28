#include "config.h"
#include "sleep.h"
#include "buttons.h"
#include "leds.h"
#include "lcd.h"
#include "core.h"

#include <Arduino.h>

/**
  Initializes the system for its initial phase
*/
void initializeStart(){
  initializeTimer();
  attachGameStart();
  changeMessage(WELCOME, true);
}

/**
  Initializes the system for the game phase
*/
void initializeGame(){
  changeMessage(START, false);
  timerStop();
  ledsOff();
  initializeCore();
  delay(500);
  startPhase();
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