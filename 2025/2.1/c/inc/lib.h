#include <stdint.h>
#define IN(btm, top, item) ((item <= top) && (item >= btm) && (top >= btm))

uint32_t find_divisors(uint32_t* div_array, uint32_t target);
void bubbleSort(uint32_t* array, uint32_t size);
uint32_t has_repeat(uint32_t number);
uint32_t oom(uint64_t number);
