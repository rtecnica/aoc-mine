#include <stdio.h>

typedef enum state {
  FIRST_DIGIT,
  SECOND_DIGIT,
} state_t;

void initGlobals(void);
void runSM(char input);
void resetSum(void);
void printRunningSum(void);
