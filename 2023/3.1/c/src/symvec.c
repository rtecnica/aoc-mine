#include "symvec.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

#define VECNAME_DEF_LOWER_MARGIN (1.0f / 4)
#define VECNAME_DEF_UPPER_MARGIN (3.0f / 4)

MAKE_STRUCT_TYPE_NAME() * MAKE_FUNC_NAME(new_heap)(void) {
  MAKE_STRUCT_TYPE_NAME()* new = malloc(sizeof(MAKE_STRUCT_TYPE_NAME()));
  new->size = 0;
  new->capacity = 16;
  new->arr = (VECTYPE*)malloc(new->capacity * sizeof(VECTYPE));
  return new;
}

MAKE_STRUCT_TYPE_NAME() MAKE_FUNC_NAME(new_stack)(void) {
  MAKE_STRUCT_TYPE_NAME() new;
  new.size = 0;
  new.capacity = 128;
  new.arr = (VECTYPE*)malloc(new.capacity * sizeof(VECTYPE));
  return new;
}

size_t MAKE_FUNC_NAME(delete)(MAKE_STRUCT_TYPE_NAME() * vec) {
  int capacity = vec->capacity;
  free(vec->arr);
  free(vec);
  return ((capacity * sizeof(VECTYPE)) + (2 * sizeof(size_t)));
}

size_t MAKE_FUNC_NAME(resize_down)(MAKE_STRUCT_TYPE_NAME() * vec) {
  vec->capacity = vec->capacity / 2;
  VECTYPE* old_arr = vec->arr;
  VECTYPE* new_arr = (VECTYPE*)malloc(vec->capacity * sizeof(VECTYPE));
  memcpy(new_arr, old_arr, vec->size * sizeof(VECTYPE));
  vec->arr = new_arr;
  free(old_arr);
  return vec->capacity;
}

size_t MAKE_FUNC_NAME(resize_up)(MAKE_STRUCT_TYPE_NAME() * vec) {
  vec->capacity = vec->capacity * 2;
  VECTYPE* old_arr = vec->arr;
  VECTYPE* new_arr = (VECTYPE*)malloc(vec->capacity * sizeof(VECTYPE));
  memcpy(new_arr, old_arr, vec->size * sizeof(VECTYPE));
  vec->arr = new_arr;
  free(old_arr);
  return vec->capacity;
}

size_t MAKE_FUNC_NAME(resize_on_bounds)(MAKE_STRUCT_TYPE_NAME() * vec, size_t lower, size_t upper) {
  if (lower >= upper) {
    return 0;
  }
  if (vec->size < lower) {
    return MAKE_FUNC_NAME(resize_down)(vec);
  }
  if (vec->size > upper) {
    return MAKE_FUNC_NAME(resize_up)(vec);
  }
  return 0;
}

size_t MAKE_FUNC_NAME(size)(MAKE_STRUCT_TYPE_NAME() * vec) { return vec->size; }
size_t MAKE_FUNC_NAME(capacity)(MAKE_STRUCT_TYPE_NAME() * vec) { return vec->capacity; }
int MAKE_FUNC_NAME(is_empty)(MAKE_STRUCT_TYPE_NAME() * vec) { return (vec->capacity == 0); }

VECTYPE MAKE_FUNC_NAME(at)(MAKE_STRUCT_TYPE_NAME() * vec, size_t index) {
  if (index < vec->size)
    return *(vec->arr + index);
}

int MAKE_FUNC_NAME(find_with)(MAKE_STRUCT_TYPE_NAME() * vec, VECTYPE item, int (*comp)(VECTYPE, VECTYPE)) {
  VECTYPE* cursor = vec->arr;
  int counter = 0;
  while (!comp(*cursor, item)) {
    if (counter >= vec->size) {
      return -1;
    }
    cursor += 1;
    counter += 1;
  }
  return counter;
}

size_t MAKE_FUNC_NAME(push)(MAKE_STRUCT_TYPE_NAME() * vec, VECTYPE item) {
  if (vec->size < vec->capacity) {
    MAKE_FUNC_NAME(resize_on_bounds)
    (vec, vec->capacity * VECNAME_DEF_LOWER_MARGIN, vec->capacity * VECNAME_DEF_UPPER_MARGIN);
  } else {
    MAKE_FUNC_NAME(resize_up)(vec);
  }
  int offset = vec->size;
  *(vec->arr + offset) = item;
  vec->size++;
  return offset;
}

size_t MAKE_FUNC_NAME(insert)(MAKE_STRUCT_TYPE_NAME() * vec, size_t index, VECTYPE item) {
  // if index is greater than size, push to last place;
  if (index >= vec->size) {
    return MAKE_FUNC_NAME(push)(vec, item);
  } else {
    vec->size++;
    memmove(vec->arr + index + 1, vec->arr + index, (vec->size - index + 1) * sizeof(int));
    *(vec->arr + index) = item;
    MAKE_FUNC_NAME(resize_on_bounds)
    (vec, vec->capacity * VECNAME_DEF_LOWER_MARGIN, vec->capacity * VECNAME_DEF_UPPER_MARGIN);
    return index;
  }
}

size_t MAKE_FUNC_NAME(preappend)(MAKE_STRUCT_TYPE_NAME() * vec, VECTYPE item) {
  return MAKE_FUNC_NAME(insert)(vec, 0, item);
}

VECTYPE MAKE_FUNC_NAME(pop)(MAKE_STRUCT_TYPE_NAME() * vec) {
  vec->size--;
  VECTYPE item = *(vec->arr + vec->size);
  MAKE_FUNC_NAME(resize_on_bounds)
  (vec, vec->capacity * VECNAME_DEF_LOWER_MARGIN, vec->capacity * VECNAME_DEF_UPPER_MARGIN);
  return item;
}

VECTYPE MAKE_FUNC_NAME(deleete)(MAKE_STRUCT_TYPE_NAME() * vec, size_t index) {
  // if index is greater than size, push to last place;
  if (index >= vec->size) {
    return MAKE_FUNC_NAME(pop)(vec);
  } else {
    VECTYPE item = *(vec->arr + index);
    memmove(vec->arr + index, vec->arr + index + 1, (vec->size - index) * sizeof(int));
    vec->size--;
    MAKE_FUNC_NAME(resize_on_bounds)
    (vec, vec->capacity * VECNAME_DEF_LOWER_MARGIN, vec->capacity * VECNAME_DEF_UPPER_MARGIN);
    return item;
  }
}

#undef VECTYPE
#undef VECNAME
