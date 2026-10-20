#include "config.h"
#include "sleep.h"
#include "buttons.h"
#include "leds.h"
#include "lcd.h"

/**
  Initializes the system for its initial phase
*/
void initializeStart(){
  initializeTimer();
  attachGameStart();
  fading();
  changeMessage(WELCOME);
}

/**
  Initializes the system for the game phase
*/
void initializeGame(){
  changeMessage("");
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