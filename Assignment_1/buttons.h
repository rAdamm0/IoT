#ifndef ___BUTTONS___
#define ___BUTTONS___

struct Button{
  volatile bool pressed;
  volatile long lastPressed;
  volatile int counts;
  int allowedCounts;
};

/**
  Disables the interrupts on every button
*/
void disableButtons();

/**
  Attaches to the buttons the interrupts to wake up from the sleep mode
*/
void attachWakeUp();

/**
  Attaches to the buttons the interrupts that allows to start the game
*/
void attachStartGame();

/**
  Attaches to the buttons the interrupts that count the in-game presses
*/
void attachGame();

/**
  Processes the buttons based on the state of the game
*/
void processButtons();

/**
  Sets the random round value 
*/
void setRoundValue(int inValue);

/**
  Ends the round adding the round points for each player with @link{setPoints()}
  @return true if no button was pressed, false otherwise
*/
bool endRound();

#endif