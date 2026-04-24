#include "inc/lib.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE* input = fopen("../input.txt", "r+");
  char line[10] = {0};
  int p = 1;

  dial_t dial = {.position = 50, .zero_count = 0};
  while (1) {
    p = fscanf(input, "%[^\n] ", line);
    if (p < 0)
      break;
    uint16_t amount = atoi(&line[1]);
    switch (line[0]) {
    case 'R':
      rot_dial(&dial, RIGHT, amount);
      break;
    case 'L':
      rot_dial(&dial, LEFT, amount);
      break;
    default:
      break;
    }
    printf("%s\t%d\t%d\n", line, dial.position, dial.zero_count);
  }
  printf("Zero Position Count: %d\n", dial.zero_count);
  return 0;
}
