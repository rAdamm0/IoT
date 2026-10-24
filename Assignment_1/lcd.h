#ifndef ___LCD___
#define ___LCD___
/**
  Functions to change the message to be displayed on the LCD
*/
void changeMessage(const char* message);

/**
  Function to update the screen every loop
*/
void updateScreen();

/**
  Sets the message to scroll over the LCD
*/
void scrolling( );
#endif