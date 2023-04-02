#include <stdint.h>
#include <stdio.h>
#include "print.h"
#include "uart.h"
#include "hx711.h"
#include "delay.h"


void main (void) {

  // switch to 16MHz (default is 2MHz)
  sfr_CLK.CKDIVR.byte = 0x00;
    
  // init UART for 19.2kBaud
  UART_begin(9600);
  

  port_t dt = {
    .port = &sfr_PORTD,
    .pin = 0
  };

  port_t sck = {
    .port = &sfr_PORTD,
    .pin = 1
  };

  hx711_t* hx711 = hx711__init(&dt, &sck);
    
  printf("start\n");

  uint8_t i=0;
  while(i < 120) {
    i++;
    delay_us(1000000);
  }

  printf("end\n");

}
