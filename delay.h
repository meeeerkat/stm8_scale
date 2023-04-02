#pragma once

#include "my_STM8S103F3.h"
#include "stdio.h"

#define NB_INSTRUCTIONS_PER_LOOP 9
#define US_TO_S 1000000UL

inline void delay_us(uint64_t us) {
  const uint64_t wait = (US_TO_S*us*NB_INSTRUCTIONS_PER_LOOP) / F_CPU;
  for (uint64_t i = 0; i < wait; i++)
    __asm__("nop");
}
