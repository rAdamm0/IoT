#ifndef ___CORE____
#define ___CORE____


/**
  Function to initialize the game when its supposed to start
*/
void initializeCore();

/**
  Code to run during the startPhase
*/
void startPhase();

/**
  Code to run for the game phase
*/
void gamePhase();

/**
  Code to run for the end phase
*/
void endPhase();

/**
  Returns true if the time in the round is over, false otherwise
*/
bool isEndTime();

/**
  Returns true if the number is being shown, false otherwise
*/
bool isNumberShown();
#endif