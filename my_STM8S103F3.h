#pragma once

#include "STM8S103F3.h"

#define F_CPU (16000000UL / (1 << sfr_CLK.CKDIVR.HSIDIV))
