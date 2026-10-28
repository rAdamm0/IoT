#ifndef ___LEDS___
#define ___LEDS___
/**
  Fading leds for the pre-game phase
*/
void fading();

/**
  Turns on the winning led
*/
void roundWon(int winner);

/**
  Turns the red led of the player losing a score on for 2 seconds
*/
void scoreLost(int index);

/**
  Turns off all the leds
*/
void ledsOff();
#endif