#include "../inc/num.h"
#include <stdio.h>
#include <string.h>

num_vec_t* numvec_from_string(char* line) {
  num_vec_t* new = num_new_heap();
  size_t counter = 0;
  int begin = -1;
  int end = -1;
  // states
  //    begin, end < 0 -> searching
  //    begin > 0, end < 0 -> in number
  //    begin, end > 0 -> returning number
  //    begin < 0, end > 0 -> invalid
  //
  while (1) {
    if (line[counter] <= '9' && line[counter] >= '0') {
      // Is Digit
      if (begin < 0)
        begin = counter;
      else {
        end = counter;
      }
    } else {
      if (begin >= 0) {
        if (end < 0) {
          end = begin;
        }
        int buffer_len = (end - begin + 2);
        char buffer[buffer_len];
        memcpy(buffer, (line + begin), (buffer_len - 1));
        buffer[buffer_len - 1] = '\0';
        int value;
        sscanf(buffer, "%d", &value);
        sch_num_t new_num = {
            .value = value,
            .begin = begin,
            .end = end,
        };

        num_push(new, new_num);
        begin = -1;
        end = -1;
      }
    }

    if (line[counter] == '\0')
      break;

    counter++;
  }

  return new;
};

void numvec_print(num_vec_t* vec) {
  for (int i = 0; i < vec->size; i++) {
    printf("%d:%lu-%lu ", vec->arr[i].value, vec->arr[i].begin, vec->arr[i].end);
  }
  printf("\n");
}
