#include "../inc/lib.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void fill_with_primes(uint32_t* array, uint32_t array_length) {
  array[0] = 2;
  for (int i = 1; i < array_length; i++) {
    uint32_t is_prime = 0;
    for (uint32_t last_prime = array[i - 1] + 1; is_prime == 0; last_prime++) {
      is_prime = 1;
      for (int j = 0; (j < i) && (((last_prime + 1) / 2) >= array[j]); j++) {
        if (last_prime % array[j] == 0) {
          is_prime = 0;
          break;
        }
      }
      if (is_prime) {
        array[i] = last_prime;
        break;
      }
    }
  }
}

void swap(uint32_t* xp, uint32_t* yp) {
  uint32_t temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void bubbleSort(uint32_t* array, uint32_t size) {
  if (size < 2) {
    return;
  }
  uint32_t i, j;
  uint8_t swapped;
  for (i = 0; i < (size - 1); i++) {
    swapped = 0;
    for (j = 0; j < (size - i - 1); j++) {
      if (array[j] > array[j + 1]) {
        swap(&array[j], &array[j + 1]);
        swapped = 1;
      }
    }
    if (swapped == 0)
      break;
  }
}

uint32_t find_divisors(uint32_t* div_array, uint32_t target) {
  uint32_t cnt = 0;
  uint32_t div, div2;
  for (int i = 2; i <= sqrt((float)target); i++) {
    if (target % i == 0) {
      div = i;
      div2 = target / i;
      if (div == div2) {
        div_array[cnt] = i;
        cnt += 1;
      } else {
        div_array[cnt] = i;
        div_array[cnt + 1] = target / i;
        cnt += 2;
      }
    }
  }
  bubbleSort(div_array, cnt);
  return cnt;
}

uint32_t has_repeat(uint64_t number) {
  uint32_t order = oom(number);
  uint32_t repeat_amount = 0;
  uint32_t divs[10] = {0};
  uint32_t div_c = find_divisors(divs, order);
  if (div_c == 0 && order > 1) {
    // it's a prime!
    uint32_t div = 1;
    for (int z = 1; z < order; z++) {
      div += pow(10, z);
    }
    if (number % div == 0) {
      return order;
    }
  }

  for (int i = 0; i < div_c; i++) {
    uint64_t divider = 1;
    uint32_t items = divs[i];
    uint32_t groups = order / divs[i];
    for (int j = 1; j < groups; j++) {
      divider += (uint64_t)pow(10, items * j);
    }
    if (number % divider == 0) {
      repeat_amount = groups;
    }
  }
  return repeat_amount;
}

uint32_t oom(uint64_t number) {
  uint32_t ret = 1;
  uint32_t rem = number / 10;
  while (rem != 0) {
    ret++;
    rem /= 10;
  }
  return ret;
}
