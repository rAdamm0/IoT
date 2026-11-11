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
  Function that returns the actual state
*/
State getState();

/**
  Function that changes the state
*/
void changeState(State newState);
#endif