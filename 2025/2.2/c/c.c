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
  char range[256] = {0};
  while (fgets(line, sizeof(line), input))
    ;
  line[strlen(line)] = ',';
  char* start_c = line;
  char* end_c = find_char(line, ',');
  uint64_t btm, top, running_sum;
  running_sum = 0;
  while (end_c != NULL) {
    memcpy(range, start_c, (end_c - start_c));
    range[end_c - start_c] = '\0';
    sscanf(range, "%lu-%lu", &btm, &top);
    printf("%ld - %ld: \n", btm, top);
    for (uint64_t idx = btm; idx <= top; idx++) {
      if (has_repeat(idx)) {
        printf("%ld\n", idx);
        running_sum += idx;
      }
    }
    printf("\n");
    start_c = end_c + 1;
    end_c = find_char(start_c, ',');
  }
  printf("%ld\n", running_sum);
  return 0;
}
