#include "inc/lib.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

char* find_char(char* start, char to_find) {
  char* cursor = start;
  while (*cursor != to_find) {
    if (*cursor == '\0')
      return NULL;
    cursor++;
  }
  return cursor;
}

int main(void) {
  FILE* input = fopen("../input.txt", "r+");
  char line[1024] = {0};
  uint64_t joltage = 0;
  int32_t p = 0;
  while (1) {
    p = fscanf(input, "%[^\n] ", line);
    if (p < 0)
      break;
    uint64_t line_joltage = get_max_joltage(line, 2);
    printf("%s %lu\n", line, line_joltage);
    joltage += line_joltage;
  }
  printf("%lu\n", joltage);
}
