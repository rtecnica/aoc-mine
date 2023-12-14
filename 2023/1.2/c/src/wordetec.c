#include "wordetec.h"

#include <stdio.h>
#include <string.h>

char* num_list[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
unsigned long num_lens[9];

void init_lengths(void) {
  for (int i = 0; i < 9; i++) {
    num_lens[i] = strlen(num_list[i]);
  }
}
void search_and_replace(char* content) {
  int cursor = 0;
  while (*(content + cursor) != '\0') {
    for (int i = 0; i < 9; i++) {
      if (strcmp_lax(num_list[i], content + cursor)) {
        *(content + cursor) = (char)(i + 0x31);
      }
    }
    cursor++;
  }
}

int strcmp_lax(const char* ref, const char* str) {
  if (strlen(ref) > strlen(str))
    return 0;
  int p = 0;
  do {
    if (ref[p] != str[p]) {
      return 0;
    }
    p++;
  } while (ref[p] != '\0');
  return 1;
}
