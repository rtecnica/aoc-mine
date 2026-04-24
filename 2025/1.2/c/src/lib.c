#include "../inc/lib.h"
#include <stdint.h>

void rot_dial(dial_t* dial, dir_t direction, uint32_t amount) {
  int32_t preposition = dial->position;
  dial->zero_count += (amount / 100);
  switch (direction) {
  case RIGHT:
    dial->position = (dial->position + (amount % 100)) % 100;
    dial->zero_count += ((preposition > dial->position) || (dial->position == 0)) && preposition != 0 ? 1 : 0;
    break;
  case LEFT:
    dial->position = ((dial->position + 100) - (amount % 100)) % 100;
    dial->zero_count += ((preposition < dial->position) || (dial->position == 0)) && preposition != 0 ? 1 : 0;
    break;
  default:
    break;
  }
}
