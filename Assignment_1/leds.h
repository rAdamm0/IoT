#ifndef ___LEDS___
#define ___LEDS___

/**
  Processes the behavior of the leds based on the state and the possible boolean checks
*/
void processLeds();

/**
  Sets the loser of the round as the player in input
  @param player of the losing player
*/
void setLoser(int player);

/**
  Sets the winner of the round as the player in input
  @param player of the winning player
*/
void setWinner(int player);

#endif