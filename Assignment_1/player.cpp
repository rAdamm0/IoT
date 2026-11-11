#include <Arduino.h>

#include "player.h"
#include "config.h"
#include "states.h"
#include "leds.h"

Player p1;
Player p2;

Player players[] = {p1, p2};

void setPoints(int player, int points){
  players[player].roundPoints = points;
}

void addScore(int player){
  /*TODO*/
  // Must change the state to SHOW_SCORE
  setWinner(player);
  players[player].scorePoints = players[player].scorePoints + 1;
}

void removeScore(int player){
  /*TODO*/
  // Must change the state to SCORE_LOST
  setLoser(player);
  players[player].scorePoints = players[player].scorePoints - 1;
  errorPress = true;
}

void startRound(){
  for (int i = 0; i < NUM_PLAYERS; i++){
    players[i].roundPoints = 0;
  }
}

int* endPlayerRound(){
  int winner = p1.roundPoints > p2.roundPoints ? 0 : 1;
  addScore(winner);
  int* scores = (int*)malloc(NUM_PLAYERS*sizeof(int));
  for(int i = 0; i < NUM_PLAYERS; i++){
    scores[i] = players[i].roundPoints;
  }
  return scores;
}

int endGame(){
  if(p1.scorePoints == p2.scorePoints){
    return -1;
  } else{
    return p1.scorePoints > p2.scorePoints ? 0 : 1;
  }
}