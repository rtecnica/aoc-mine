#include "inc/lib.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE* input = fopen("../input.txt", "r+");
  char line[512];
  int p = 1;

  uint16_t sum_games_id = 0;
  uint32_t sum_power_minbag = 0;

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

    bag_t temp_bag = {
        .red = 1,
        .blue = 1,
        .green = 1,
    };

    for (int i = 0; i < game.num; i++) {
      if (game.sets[i].red > temp_bag.red)
        temp_bag.red = game.sets[i].red;
      if (game.sets[i].blue > temp_bag.blue)
        temp_bag.blue = game.sets[i].blue;
      if (game.sets[i].green > temp_bag.green)
        temp_bag.green = game.sets[i].green;
    }

    uint32_t pwerbag = (temp_bag.red * temp_bag.green * temp_bag.blue);
    sum_power_minbag += pwerbag;

    if (isGamePosible(&bag, &game)) {
      sum_games_id += game.id;
    }
  }
  printf("%d\n", sum_games_id);
  printf("%d\n", sum_power_minbag);
  return 0;
}
