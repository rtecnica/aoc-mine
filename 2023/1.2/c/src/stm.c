#include "stm.h"
#include <inttypes.h>

/****************************************************/
/*                Global variables                  */
/****************************************************/
struct global_t {
  state_t curr_state;
  char digits[2];
} globals;

uint32_t running_sum;

/****************************************************/
/*                  Functions                       */
/****************************************************/

void initGlobals(void) {
  globals.curr_state = FIRST_DIGIT;
  globals.digits[FIRST_DIGIT] = 'X';
  globals.digits[SECOND_DIGIT] = 'X';
}

inline uint8_t isNum(char in) { return ((in >= '0') && (in <= '9')); }
inline void resetSum(void) { running_sum = 0; }
inline void printRunningSum(void) { printf("RS: %d\n", running_sum); }

void sumDigits(void) {
  globals.digits[SECOND_DIGIT] =
      isNum(globals.digits[SECOND_DIGIT]) ? globals.digits[SECOND_DIGIT] : globals.digits[FIRST_DIGIT];
  uint32_t tens = ((uint32_t)(globals.digits[FIRST_DIGIT] - '0')) * 10;
  uint32_t ones = ((uint32_t)(globals.digits[SECOND_DIGIT] - '0'));
  printf("%d\n", tens + ones);
  running_sum += (tens + ones);
}

state_t state_machine(char input) {
  switch (globals.curr_state) {
  case FIRST_DIGIT:
    if (isNum(input) && !(isNum(globals.digits[FIRST_DIGIT]))) {
      globals.digits[FIRST_DIGIT] = input;
      return SECOND_DIGIT;
    }

    if ((input == '\n') && isNum(globals.digits[FIRST_DIGIT])) {
      sumDigits();
      initGlobals();
    }

    break;
  case SECOND_DIGIT:
    if (isNum(input)) {
      globals.digits[SECOND_DIGIT] = input;
      return SECOND_DIGIT;
    }

    if (input == '\n') {
      sumDigits();
      initGlobals();
    }
    break;
  }
  return globals.curr_state;
}

void runSM(char input) { globals.curr_state = state_machine(input); }
