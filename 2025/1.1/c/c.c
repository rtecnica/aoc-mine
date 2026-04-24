#include "inc/lib.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE* input = fopen("../input.txt", "r+");
  char line[10] = {0};
  int p = 1;

  dial_t dial = {.position = 50, .zero_count = 0};
  int64_t potato2 = dial.position;
  while (1) {
    uint8_t potato = dial.position;
    p = fscanf(input, "%[^\n] ", line);
    if (p < 0)
      break;
    uint16_t amount = atoi(&line[1]);
    switch (line[0]) {
    case 'R':
      potato2 += amount;
      rot_right(&dial, amount);
      break;
    case 'L':
      potato2 -= amount;
      rot_left(&dial, amount);
      break;
    default:
      break;
    }
    printf("%d\t%s\t%d\t%ld\n", potato, line, dial.position, potato2 % 100);
    if (dial.position == 0) {
      dial.zero_count += 1;
    }
  }
  printf("Zero Position Count: %d\n", dial.zero_count);
  return 0;
}
