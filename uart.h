#pragma once

#include <stdint.h>
#include "../STM8S103F3.h"


/// check if byte received via UART2
#define UART_available()   ( sfr_UART1.SR.RXNE )

/// read received byte from UART2
#define UART_read()        ( sfr_UART1.DR.byte )

/// send byte via UART2
#define UART_write(x)	     { while (!(sfr_UART1.SR.TXE)); sfr_UART1.DR.byte = x; }

/// flush UART2
#define UART_flush()	     { while (!(sfr_UART1.SR.TC)); }


/// initialize UART
void UART_begin(uint32_t BR);

