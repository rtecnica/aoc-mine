#include <stdint.h>
typedef enum { RIGHT, LEFT } dir_t;

typedef struct {
  uint32_t position;
  uint32_t zero_count;
} dial_t;

void rot_dial(dial_t* dial, dir_t direction, uint32_t amount);
