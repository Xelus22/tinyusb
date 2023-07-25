#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "gpio.h"
#include "../config.h"
#include "pin_defs.h"

void encoder_init(void);
bool encoder_read(void);

#define NUM_ENCODERS 1