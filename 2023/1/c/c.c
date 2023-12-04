#include "inc/lib.h"

int main(void) {
  FILE* input = fopen("../input.txt", "r+");
  char cursor = getc(input);
  resetSum();
  initGlobals();
  while (cursor != EOF) {
    runSM(cursor);
    cursor = getc(input);
  }
  printRunningSum();
}
