/* Copyright 2021 QMK
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once
#include "ch32v30x.h"

#define PAL_LINE(port, pad) port, pad

#define A0 PAL_LINE(GPIOA, GPIO_Pin_0)
#define A1 PAL_LINE(GPIOA, GPIO_Pin_1)
#define A2 PAL_LINE(GPIOA, GPIO_Pin_2)
#define A3 PAL_LINE(GPIOA, GPIO_Pin_3)
#define A4 PAL_LINE(GPIOA, GPIO_Pin_4)
#define A5 PAL_LINE(GPIOA, GPIO_Pin_5)
#define A6 PAL_LINE(GPIOA, GPIO_Pin_6)
#define A7 PAL_LINE(GPIOA, GPIO_Pin_7)
#define A8 PAL_LINE(GPIOA, GPIO_Pin_8)
#define A9 PAL_LINE(GPIOA, GPIO_Pin_9)
#define A10 PAL_LINE(GPIOA, GPIO_Pin_10)
#define A11 PAL_LINE(GPIOA, GPIO_Pin_11)
#define A12 PAL_LINE(GPIOA, GPIO_Pin_12)
#define A13 PAL_LINE(GPIOA, GPIO_Pin_13)
#define A14 PAL_LINE(GPIOA, GPIO_Pin_14)
#define A15 PAL_LINE(GPIOA, GPIO_Pin_15)

#define B0 PAL_LINE(GPIOB, GPIO_Pin_0)
#define B1 PAL_LINE(GPIOB, GPIO_Pin_1)
#define B2 PAL_LINE(GPIOB, GPIO_Pin_2)
#define B3 PAL_LINE(GPIOB, GPIO_Pin_3)
#define B4 PAL_LINE(GPIOB, GPIO_Pin_4)
#define B5 PAL_LINE(GPIOB, GPIO_Pin_5)
#define B6 PAL_LINE(GPIOB, GPIO_Pin_6)
#define B7 PAL_LINE(GPIOB, GPIO_Pin_7)
#define B8 PAL_LINE(GPIOB, GPIO_Pin_8)
#define B9 PAL_LINE(GPIOB, GPIO_Pin_9)
#define B10 PAL_LINE(GPIOB, GPIO_Pin_10)
#define B11 PAL_LINE(GPIOB, GPIO_Pin_11)
#define B12 PAL_LINE(GPIOB, GPIO_Pin_12)
#define B13 PAL_LINE(GPIOB, GPIO_Pin_13)
#define B14 PAL_LINE(GPIOB, GPIO_Pin_14)
#define B15 PAL_LINE(GPIOB, GPIO_Pin_15)

#define C0 PAL_LINE(GPIOC, GPIO_Pin_0)
#define C1 PAL_LINE(GPIOC, GPIO_Pin_1)
#define C2 PAL_LINE(GPIOC, GPIO_Pin_2)
#define C3 PAL_LINE(GPIOC, GPIO_Pin_3)
#define C4 PAL_LINE(GPIOC, GPIO_Pin_4)
#define C5 PAL_LINE(GPIOC, GPIO_Pin_5)
#define C6 PAL_LINE(GPIOC, GPIO_Pin_6)
#define C7 PAL_LINE(GPIOC, GPIO_Pin_7)
#define C8 PAL_LINE(GPIOC, GPIO_Pin_8)
#define C9 PAL_LINE(GPIOC, GPIO_Pin_9)
#define C10 PAL_LINE(GPIOC, GPIO_Pin_10)
#define C11 PAL_LINE(GPIOC, GPIO_Pin_11)
#define C12 PAL_LINE(GPIOC, GPIO_Pin_12)
#define C13 PAL_LINE(GPIOC, GPIO_Pin_13)
#define C14 PAL_LINE(GPIOC, GPIO_Pin_14)
#define C15 PAL_LINE(GPIOC, GPIO_Pin_15)

#define D0 PAL_LINE(GPIOD, GPIO_Pin_0)
#define D1 PAL_LINE(GPIOD, GPIO_Pin_1)
#define D2 PAL_LINE(GPIOD, GPIO_Pin_2)
#define D3 PAL_LINE(GPIOD, GPIO_Pin_3)
#define D4 PAL_LINE(GPIOD, GPIO_Pin_4)
#define D5 PAL_LINE(GPIOD, GPIO_Pin_5)
#define D6 PAL_LINE(GPIOD, GPIO_Pin_6)
#define D7 PAL_LINE(GPIOD, GPIO_Pin_7)
#define D8 PAL_LINE(GPIOD, GPIO_Pin_8)
#define D9 PAL_LINE(GPIOD, GPIO_Pin_9)
#define D10 PAL_LINE(GPIOD, GPIO_Pin_10)
#define D11 PAL_LINE(GPIOD, GPIO_Pin_11)
#define D12 PAL_LINE(GPIOD, GPIO_Pin_12)
#define D13 PAL_LINE(GPIOD, GPIO_Pin_13)
#define D14 PAL_LINE(GPIOD, GPIO_Pin_14)
#define D15 PAL_LINE(GPIOD, GPIO_Pin_15)
