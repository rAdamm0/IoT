#ifndef __STATES__
#define __STATES__

extern bool errorPress;
extern bool startGame;
extern bool endRoundBool;

enum State{
  INITIAL,
  SLEEP,
  WAITING,
  GAME,
  SCORE_LOST,
  SHOW_SCORE,
  GAME_OVER
};

/**
  Returns the actual state
*/
State getState();

/**
  Changes the state to the input and intializes it
*/
void changeState(State input);

/**
  Checks the variables and changes the state accordingly
*/
void checkStates();


#endif