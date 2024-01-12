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
  size_t begin;
  size_t end;
} sch_sym_t;

#define E(str) str
#define paste(a, b) a##_##b

#define STRUCT_NAME(name) paste(name, vec)
#define MAKE_STRUCT_NAME() STRUCT_NAME(E(VECNAME))

#define STRUCT_TYPE_NAME(name) paste(name, vec_t)
#define MAKE_STRUCT_TYPE_NAME() STRUCT_TYPE_NAME(E(VECNAME))

#define FUNC_NAME(name, func) paste(name, func)
#define MAKE_FUNC_NAME(func) FUNC_NAME(E(VECNAME), func)

// Struct Typedef
typedef struct MAKE_STRUCT_NAME() {
  size_t size;
  size_t capacity;
  VECTYPE* arr;
} MAKE_STRUCT_TYPE_NAME();

MAKE_STRUCT_TYPE_NAME() * MAKE_FUNC_NAME(new_heap)(void);
MAKE_STRUCT_TYPE_NAME() MAKE_FUNC_NAME(new_stack)(void);

size_t MAKE_FUNC_NAME(delete)(MAKE_STRUCT_TYPE_NAME() * vec);

size_t MAKE_FUNC_NAME(resize)(MAKE_STRUCT_TYPE_NAME() * vec);

size_t MAKE_FUNC_NAME(size)(MAKE_STRUCT_TYPE_NAME() * vec);
size_t MAKE_FUNC_NAME(capacity)(MAKE_STRUCT_TYPE_NAME() * vec);

int MAKE_FUNC_NAME(is_empty)(MAKE_STRUCT_TYPE_NAME() * vec);
VECTYPE MAKE_FUNC_NAME(at)(MAKE_STRUCT_TYPE_NAME() * vec, size_t index);
int MAKE_FUNC_NAME(find_with)(MAKE_STRUCT_TYPE_NAME() * vec, VECTYPE item, int (*comp)(VECTYPE, VECTYPE));

size_t MAKE_FUNC_NAME(push)(MAKE_STRUCT_TYPE_NAME() * vec, VECTYPE item);
size_t MAKE_FUNC_NAME(insert)(MAKE_STRUCT_TYPE_NAME() * vec, size_t index, VECTYPE item);
size_t MAKE_FUNC_NAME(preappend)(MAKE_STRUCT_TYPE_NAME() * vec, VECTYPE item);

VECTYPE MAKE_FUNC_NAME(pop)(MAKE_STRUCT_TYPE_NAME() * vec);
VECTYPE MAKE_FUNC_NAME(deleete)(MAKE_STRUCT_TYPE_NAME() * vec, size_t index);
