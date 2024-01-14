#include "inc/num.h"
#include "inc/sym.h"
#include <stdio.h>
#include <stdlib.h>

#define INPUT_LINES 140
#define INPUT_LENGTH 140
int is_part_number(sym_vec_t* symtable[], unsigned int linenum, sch_num_t num);
void print_sch(sym_vec_t* symtable[], num_vec_t* numtable[]);

int main(void) {
  FILE* input = fopen("../input.txt", "r+");
  char line[512];
  int read = 1;

  sym_vec_t* syms[INPUT_LINES];
  num_vec_t* nums[INPUT_LINES];

  uint16_t lnnum = 0;
  while (lnnum < INPUT_LINES) {
    read = fscanf(input, "%[^\n] ", line);
    if (read < 0)
      break;
    syms[lnnum] = symvec_from_string(line);
    nums[lnnum] = numvec_from_string(line);
    // printf("%s\n", line);
    // symvec_print(syms[lnnum]);
    // numvec_print(nums[lnnum]);

    lnnum++;
  };

  int running_sum = 0;

  for (int i = 0; i < INPUT_LINES; i++) {
    for (int j = 0; j < nums[i]->size; j++) {
      if (is_part_number(syms, i, nums[i]->arr[j])) {
        running_sum += nums[i]->arr[j].value;
      }
    }
  }
  printf("%d\n", running_sum);
  // print_sch(syms, nums);
}

int is_part_number(sym_vec_t* symtable[], unsigned int linenum, sch_num_t num) {
  /* Check Sides of number */
  for (int i = 0; i < symtable[linenum]->size; i++) {
    size_t pos = symtable[linenum]->arr[i].pos;
    if ((pos <= (num.end + (num.end < INPUT_LENGTH - 1))) && (pos >= (num.begin - (num.begin > 0)))) {
      // printf("%d inline %c\t", num.value, symtable[linenum]->arr[i].value);
      return 1;
    }
  }

  /* Check Above */
  if (linenum > 0) {
    for (int i = 0; i < symtable[linenum - 1]->size; i++) {
      size_t pos = symtable[linenum - 1]->arr[i].pos;
      if ((pos <= (num.end + (num.end < INPUT_LENGTH - 1))) && (pos >= (num.begin - (num.begin > 0)))) {
        // printf("%d below %c\t", num.value, symtable[linenum - 1]->arr[i].value);
        return 1;
      }
    }
  }

  /* Check Below */
  if (linenum < (INPUT_LINES - 1)) {
    for (int i = 0; i < symtable[linenum + 1]->size; i++) {
      size_t pos = symtable[linenum + 1]->arr[i].pos;
      if ((pos <= (num.end + (num.end < INPUT_LENGTH - 1))) && (pos >= (num.begin - (num.begin > 0)))) {
        // printf("%d above %c \t", num.value, symtable[linenum + 1]->arr[i].value);
        return 1;
      }
    }
  }
  return 0;
}

void print_sch(sym_vec_t* symtable[], num_vec_t* numtable[]) {

  for (int i = 0; i < INPUT_LINES; i++) {
    int num_cntr = 0;
    int sym_cntr = 0;
    num_vec_t* numv = numtable[i];
    sym_vec_t* symv = symtable[i];
    for (int j = 0; j < INPUT_LENGTH; j++) {
      if (numv->arr[num_cntr].begin == j && num_cntr < numv->size) {
        if (is_part_number(symtable, i, numv->arr[num_cntr])) {
          printf("\e[0;32m%d\e[0m", numv->arr[num_cntr].value);
        } else {
          printf("\e[0;31m%d\e[0m", numv->arr[num_cntr].value);
        }
        j = numv->arr[num_cntr].end;
        num_cntr++;
      } else if (symv->arr[sym_cntr].pos == j && sym_cntr < symv->size) {
        printf("%c", symv->arr[sym_cntr].value);
        sym_cntr++;
      } else {
        printf("%c", '.');
      }
    }
    printf("\n");
  }
}
