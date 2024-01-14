// Library for implementing dynamically sized arrays
#include <inttypes.h>
#include <stdlib.h>

#undef VECTYPE
#undef VECNAME

#ifndef VECTYPE
#define VECTYPE sch_num_t
#endif  // !VECTYP
#ifndef VECNAME
#define VECNAME num
#endif  // !VECTYP

typedef struct sch_num {
  uint16_t value;
  size_t begin;
  size_t end;
} sch_num_t;

#include "../templates/vec.h"
