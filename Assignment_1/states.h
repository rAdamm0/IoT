#ifndef ___STATES___
#define ___STATES___

/**
  Enum of the possible states of the system
*/
enum State {
  INITIAL,
  ROUND,
  END,
  SLEEP
};

/**
  Initializes the system for its initial phase
*/
void initializeStart();

/**
  Initializes the system for the game phase
*/
void initializeGame();

/**
  Starts the sleep timer for the initial phase
*/
void sleepTimer();

/**
  Starts the game over timer
*/
void gameOverTimer();

/**
  Starts the end game and reset timer
*/
void endTimer();
#endif