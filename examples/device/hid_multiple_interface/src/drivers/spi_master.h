#pragma once

#include "ch32v30x_spi.h"
#include "ch32v30x_gpio.h"

void spi_init(void);
void DMA_Tx_Init(DMA_Channel_TypeDef* DMA_CHx, u32 ppadr, u32 memadr, u16 bufsize);
void DMA_Rx_Init(DMA_Channel_TypeDef* DMA_CHx, u32 ppadr, u32 memadr, u16 bufsize);