#include <stdint.h>
#define IN(btm, top, item) ((item <= top) && (item >= btm) && (top >= btm))

void bubbleSort(uint8_t* array, uint8_t size);
void bump_insert(uint8_t* array, uint8_t size, uint8_t value, int index);
uint64_t get_max_joltage(char* bank, uint32_t num_batt);
