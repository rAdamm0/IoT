#ifndef ___PLAYER___
#define ___PLAYER___

struct Player{
  int scorePoints;
  int roundPoints;
};

/**
  Sets a certain amount of round points to the player
  @param player index of the player to which add points
  @param points value that represent the amount of points to be given to the player
*/
void setPoints(int player, int points);


/**
  Remove a score point to the player and sets it as loser in @link{setLoser()}
  @param player player that loses the score
*/
void removeScore(int player);

/**
  Resets the round points for each player
*/
void startRound();

/**
  Ends the round and @return the pointer to the array of the score points and calls @link{addScore()} on the winner
*/
int* endPlayerRound();

/**
  Ends the game.
  @return -1 if it is a Tie
  @return 0 or 1 if the winner is Player 1 or Player 2 respectively
*/
int endGame();

#endif