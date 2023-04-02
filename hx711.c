#include "hx711.h"
#include "my_STM8S103F3.h"
#include "delay.h"
#include "port.h"
#include "string.h"
#include "stdlib.h"

struct hx711_s {
  port_t dt_pin;
  port_t sck_pin;
};

hx711_t* hx711__init(port_t* dt, port_t* sck) {
  hx711_t* this = malloc(sizeof(hx711_t));

  memcpy(&this->dt_pin, dt, sizeof(port_t));
  memcpy(&this->sck_pin, sck, sizeof(port_t));

  return this;
}

void hx711__take_mesure(hx711_t* this) {
  (*this);
}
