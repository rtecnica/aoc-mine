#include "../inc/lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GAME_LEN sizeof("Game")
#define NUM_COLORS 3
char* COLORS[] = {"red", "blue", "green"};

game_t parseGame(char* line) {
  game_t newGame;

  char* game_id_ctx;
  char* game_id = strtok_r(line, ":", &game_id_ctx);
  newGame.id = atoi(game_id + GAME_LEN);

  uint8_t num_games = 0;

  char* set_ctx;
  char* set = strtok_r(strtok_r(NULL, ":", &game_id_ctx), ";", &set_ctx);
  for (set = strtok_r(set, ";", &line); set; set = strtok_r(NULL, ";", &set_ctx)) {
    bag_t curr_set = {
        .red = 0,
        .blue = 0,
        .green = 0,
    };

    char* game_ctx;
    char* game;
    for (game = strtok_r(set, ",", &game_ctx); game; game = strtok_r(NULL, ",", &game_ctx)) {
      // parse game
      for (uint8_t i = 0; i < NUM_COLORS; i++) {
        char* p = strstr(game, COLORS[i]);
        if (p != NULL)
          switch (i) {
          case 0:
            curr_set.red = atoi(game);
            break;

          case 1:
            curr_set.blue = atoi(game);
            break;

          case 2:
            curr_set.green = atoi(game);
            break;
          }
      }
    }
    newGame.sets[newGame.num] = curr_set;
    newGame.num++;
  }
  return newGame;
};

uint8_t isGamePosible(bag_t* b, game_t* g) {
  uint8_t ret = 1;
  for (uint8_t i = 0; i < g->num; i++) {
    bag_t c = g->sets[i];
    if (c.red > b->red || c.blue > b->blue || c.green > b->green) {
      ret = 0;
    }
  }
  return ret;
}
