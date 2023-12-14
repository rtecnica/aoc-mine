#include "stm.h"
#include "wordetec.h"
#include <stdio.h>
#include <string.h>

int main(void) {
  FILE* input = fopen("../input.txt", "r+");

  resetSum();
  initGlobals();

  char line[100];
  int p = 1;
  init_lengths();

  while (1) {
    p = fscanf(input, "%s\n", line);
    if (p < 0)
      break;
    search_and_replace(line);
    line[strlen(line) + 1] = '\0';
    line[strlen(line)] = '\n';
    // printf("%s", line);

    char* cursor = line;
    while (*cursor != '\0') {
      runSM(*cursor);
      cursor++;
    }
  }

  printRunningSum();
  return 0;
}
