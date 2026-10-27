#ifndef ___CORE____
#define ___CORE____

enum RoundState {
  INITIAL,
  ROUND,
  END,
  SLEEP
};

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
  Returns true if the number is being shown, false otherwise
*/
bool isNumberShown();
#endif