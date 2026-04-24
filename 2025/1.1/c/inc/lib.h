#include <stdint.h>

typedef struct {
  uint16_t position;
  uint16_t zero_count;
} dial_t;

void rot_right(dial_t* dial, uint16_t amount);
void rot_left(dial_t* dial, uint16_t amount);
