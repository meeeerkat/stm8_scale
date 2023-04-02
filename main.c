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
    .port = &sfr_PORTC,
    .pin = 6
  };

  port_t sck = {
    .port = &sfr_PORTC,
    .pin = 7
  };

  hx711_t* hx711 = hx711__init(&dt, &sck);

    
  printf("start\n");
  while (1) {
    //sck.port->ODR.byte ^= 1 << sck.pin;
    uint32_t mesure = hx711__take_mesure(hx711);
    printf("%lu\n", mesure);
    delay_us(1000000);
  }

}
