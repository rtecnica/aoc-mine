#include "../inc/lib.h"

void rot_right(dial_t* dial, uint16_t amount) {
  uint16_t curr_position = dial->position;
  dial->position = (curr_position + (amount % 100)) % 100;
}

void rot_left(dial_t* dial, uint16_t amount) {
  uint16_t curr_position = dial->position;
  dial->position = ((curr_position + 100) - (amount % 100)) % 100;
}
