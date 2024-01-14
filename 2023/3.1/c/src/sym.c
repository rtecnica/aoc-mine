#include "../inc/sym.h"
#include <stdio.h>
#include <string.h>

sym_vec_t* symvec_from_string(char* line) {
  sym_vec_t* new = sym_new_heap();
  size_t counter = 0;
  while (line[counter] != '\0') {
    if (!(line[counter] <= '9' && line[counter] >= '0') && line[counter] != '.') {
      sch_sym_t new_sym = {
          .value = line[counter],
          .pos = counter,
      };
      sym_push(new, new_sym);
    }
    counter++;
  }

  return new;
};

void symvec_print(sym_vec_t* vec) {
  for (int i = 0; i < vec->size; i++) {
    printf("%c:%lu ", vec->arr[i].value, vec->arr[i].pos);
  }
  printf("\n");
}
