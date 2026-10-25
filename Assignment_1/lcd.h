#ifndef ___LCD___
#define ___LCD___
/**
  Functions to change the message to be displayed on the LCD
*/
void changeMessage(const char* message, bool scrolling);

/**
  Function to update the screen every loop
*/
void updateScreen();

/**
  Turns off the screen
*/
void lcdOff();
#endif