#include "inc/lib.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE* input = fopen("../input.txt", "r+");
  char line[512];
  int p = 1;

  uint16_t sum_games_id = 0;
  bag_t bag = {
      .red = 12,
      .green = 13,
      .blue = 14,
  };

  while (1) {
    p = fscanf(input, "%[^\n] ", line);
    if (p < 0)
      break;
    game_t game = parseGame(line);
    if (isGamePosible(&bag, &game)) {
      sum_games_id += game.id;
    }
  }
  printf("%d\n", sum_games_id);
  return 0;
}
