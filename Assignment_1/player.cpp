int points[] = 
/**
  Returns the score of the player with the index in input
*/
int getScore(int player){
  return scores[player];
}

/**
  Adds a point to the player with the index in input
*/
void addScore(int player, int value){
  scores[player] = scores[player] + value;
}

/**
  Resets the counts and initializes the round
*/
void startRound(){
  int scores[] = {0, 0};
}

/**
  Adds a value for the indexed player for the current round
*/
void addCount(int player){
  points[player] = points[player] + 1;
}

/**
  Terminates the round and counts the points and returns the index of the winner
*/
int endRound(){
  scoresIndex = max_elements(scores, scores + NUM_PLAYERS) - scores;
  points[scoresIndex] = points[scoresIndex] + 1;
  return scoresIndex;
}

/**
  At the end of the game it returns the index of the winning player
*/
int getWinner(){
  return max_elements(points, points + NUM_PLAYERS) - points;
}