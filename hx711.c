#include "hx711.h"
#include "my_STM8S103F3.h"
#include "delay.h"
#include "port.h"
#include "string.h"
#include "stdlib.h"

struct hx711_s {
  port_t dt;
  port_t sck;
};

hx711_t* hx711__init(port_t* dt, port_t* sck) {
  hx711_t* this = malloc(sizeof(hx711_t));

  memcpy(&(this->dt), dt, sizeof(port_t));
  memcpy(&(this->sck), sck, sizeof(port_t));


  // dt is input floating, all at 0
  // not configured for now, just assuming it's still the default values in DDR, CR1 & CR2
  this->dt.port->DDR.byte &= 0 << this->dt.pin; // input
  this->dt.port->CR1.byte &= 0 << this->dt.pin;
  this->dt.port->CR2.byte &= 0 << this->dt.pin;

  // sck
  this->sck.port->DDR.byte |= 1 << this->sck.pin; // output
  this->sck.port->CR1.byte |= 1 << this->sck.pin;
  this->sck.port->CR2.byte &= 0 << this->sck.pin;
  this->sck.port->ODR.byte &= 0 << this->sck.pin;

  return this;
}

uint32_t hx711__take_mesure(hx711_t* this) {

  // wait for dt to go back to LOW to start the new mesure
  while (this->dt.port->IDR.byte & (1 << this->dt.pin));

  uint32_t out=0;
  for (uint8_t i=0; i < 24; i++) {
    // clk high
    this->sck.port->ODR.byte |= 1 << this->sck.pin;
    // clk low
    this->sck.port->ODR.byte &= 0 << this->sck.pin;
    // Read
    if (this->dt.port->IDR.byte & (1 << this->dt.pin))
      out |= ((uint32_t) 1) << (23-i);
  }

  return out;
}
