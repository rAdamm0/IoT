
/**
  Attaches to the buttons the function to wake up the system after it goes to sleep
*/
void attachWakeUp();
/**
  Attachest to the buttons the function to start the game, changing its state.
*/
void attachGameStart();
/**
  Attaches to the buttons the function to count the button presses.
*/
void attachCounter();
/**
  Returns 1 if the buttons is pressed (or has been in a certain interval), 0 otherwise.
*/
bool isButtonPressed(int numButton);
/**
  Counter function that determines if a button press is to be counted and do so if needed.
  One function for each player.
*/
void pressCountP1();
void pressCountP2();

/**
  Function that starts the game changing the State of the system
*/
void startGame();