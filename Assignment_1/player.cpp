
/**
  Returns the score of the player with the index in input
*/
int getScore(int player);

/**
  Adds a point to the player with the index in input
*/
void addScore(int player);

/**
  Resets the counts and initializes the round
*/
void startRound();

/**
  Adds a value for the indexed player for the current round
*/
void addCount(int player);

/**
  Terminates the round and counts the points and returns the index of the winner
*/
int endRound();