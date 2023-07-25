
#pragma once

#include "ch32v30x_gpio.h"
#include <stdbool.h>

void setPinOutput(GPIO_TypeDef* port, uint16_t pad);
void setPinOutputOpenDrain(GPIO_TypeDef* port, uint16_t pad);
void setPinInput(GPIO_TypeDef* port, uint16_t pad);
void setPinInputHigh(GPIO_TypeDef* port, uint16_t pad);
void init_buttons(void);