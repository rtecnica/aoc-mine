#include "inc/num.h"
#include "inc/sym.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE* input = fopen("../input.txt", "r+");
  char line[512];
  int read = 1;

  uint16_t lnnum;

  while (1) {
    read = fscanf(input, "%[^\n] ", line);
    if (read < 0)
      break;
    printf("%s", line);
    // Do stuff with line
    // Parse numbers and symbols
    // struct {
    //
    // }
  };
}
