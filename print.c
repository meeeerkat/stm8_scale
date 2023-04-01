#include "print.h"
#include "uart.h"

int putchar(int data) {
  UART_write(data);
  return data;
}
