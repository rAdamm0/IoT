#include "config.h"

#include <Arduino.h>

int points[] = {0, 0};
int scores[] = {0, 0};

/**
  Helper function to find the index of the element with max value in an array
*/
int max_element(int arr[], int size) {
    if (size <= 0) return -1;
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

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
  int scoresIndex = max_element(scores, NUM_PLAYERS);
  points[scoresIndex] = points[scoresIndex] + 1;
  return scoresIndex;
}

/**
  At the end of the game it returns the index of the winning player
*/
int getWinner(){
  return max_element(points,NUM_PLAYERS);
}