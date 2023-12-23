#include "../inc/lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

game_t* parseGame(char* line) {
  game_t* newGame = malloc(sizeof(game_t));
  char* game_id = strtok(line, ":");
  // scanf("%ud", newGame->id);
  char* set = strtok(strtok(NULL, ":"), ";");
  while (set != NULL) {
    // parse set
    set = strtok(NULL, ";");
  }
  printf("\n");
  return newGame;
};

uint8_t isGamePosible(bag_t* b, game_t* g) { return 0; }

void freeGame(game_t* g) {
  free(g->sets);
  free(g);
}
