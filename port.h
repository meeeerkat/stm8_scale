#pragma once

#include "STM8S103F3.h"


typedef struct {
  PORT_t* port;
  uint8_t pin;
} port_t;
