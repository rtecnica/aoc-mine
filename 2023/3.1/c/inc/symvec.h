// Library for implementing dynamically sized arrays
#include <inttypes.h>
#include <stdlib.h>

#undef VECTYPE
#undef VECNAME

#ifndef VECTYPE
#define VECTYPE sch_sym_t
#endif  // !VECTYP
#ifndef VECNAME
#define VECNAME sym
#endif  // !VECTYP
        //
typedef struct sch_sym {
  char value;
  size_t pos;
} sch_sym_t;

#include "../templates/vec.h"
