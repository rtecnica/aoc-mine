#include "../inc/lib.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint64_t get_max_joltage(char* bank, uint32_t num_batt) {
  char* cursor = bank;
  uint8_t joltage[num_batt];  // index = order of magnitud
  uint64_t max_joltage = 0;
  uint32_t length;
  uint32_t count = 0;
  for (length = 0; *cursor != '\0'; length++)
    cursor++;
  ;
  cursor = bank;
  for (int i = num_batt - 1; i >= 0; i--) {
    joltage[i] = 0;
  }
  for (cursor = bank; (cursor - bank) < (length); cursor++) {
    for (int i = (num_batt - 1); i >= 0; i--) {
      if (*cursor - '0' > joltage[i] && (length - (cursor - bank) > i)) {
        joltage[i] = *cursor - '0';
        for (int j = i - 1; j >= 0; j--) {
          joltage[j] = 0;
          count--;
        }
        count++;
        break;
      }
    }
  }
  for (int i = 0; i < num_batt; i++) {
    uint64_t pow = 1;
    for (int j = 0; j < i; j++) {
      pow *= 10;
    }
    max_joltage += (joltage[i] * pow);
  }
  return max_joltage;
}
