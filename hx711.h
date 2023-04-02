#pragma once

#include "port.h"

typedef struct hx711_s hx711_t;

hx711_t* hx711__init(port_t* dt, port_t* sck);
void hx711__take_mesure(hx711_t* this);
