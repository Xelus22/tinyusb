/*
 * Copyright 2018 Jack Humbert <jack.humb@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
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

#include "encoder.h"
// for memcpy
#include <string.h>

#if !defined(ENCODER_RESOLUTIONS) && !defined(ENCODER_RESOLUTION)
#define ENCODER_RESOLUTION 4
#endif

#if !defined(ENCODERS_PAD_A) || !defined(ENCODERS_PAD_B)
#error "No encoder pads defined by ENCODERS_PAD_A and ENCODERS_PAD_B"
#endif

#ifdef ENCODER_RESOLUTIONS
static uint8_t encoder_resolutions[NUM_ENCODERS] = ENCODER_RESOLUTIONS;
#endif

#ifndef ENCODER_DIRECTION_FLIP
#define ENCODER_CLOCKWISE true
#define ENCODER_COUNTER_CLOCKWISE false
#else
#define ENCODER_CLOCKWISE false
#define ENCODER_COUNTER_CLOCKWISE true
#endif
static int8_t encoder_LUT[] = {0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0};

static uint8_t encoder_state[NUM_ENCODERS] = {0};
static int8_t encoder_pulses[NUM_ENCODERS] = {0};

// encoder counts
static uint8_t thisCount;
static uint8_t encoder_value[NUM_ENCODERS] = {0};

__attribute__((weak)) void encoder_wait_pullup_charge(void)
{
    // wait_us(100);
}

void encoder_init(void)
{
    thisCount = NUM_ENCODERS;

    setPinInputHigh(ENCODERS_PAD_A);
    setPinInputHigh(ENCODERS_PAD_B);
    encoder_wait_pullup_charge();
    encoder_state[0] = (GPIO_ReadInputDataBit(ENCODERS_PAD_A) << 0) | (GPIO_ReadInputDataBit(ENCODERS_PAD_B) << 1);
}

static bool encoder_update(uint8_t index, uint8_t state)
{
    bool changed = false;
    uint8_t i = index;

    const uint8_t resolution = ENCODER_RESOLUTION;

    encoder_pulses[i] += encoder_LUT[state & 0xF];

    if (encoder_pulses[i] >= resolution)
    {
        encoder_value[index]++;
        changed = true;
        // encoder_update_kb(index, ENCODER_COUNTER_CLOCKWISE);
    }

    if (encoder_pulses[i] <= -resolution)
    { // direction is arbitrary here, but this clockwise
        encoder_value[index]--;
        changed = true;
        // encoder_update_kb(index, ENCODER_CLOCKWISE);
    }
    encoder_pulses[i] %= resolution;
    return changed;
}

bool encoder_read(void)
{
    bool changed = false;
    uint8_t new_status = (GPIO_ReadInputDataBit(ENCODERS_PAD_A) << 0) | (GPIO_ReadInputDataBit(ENCODERS_PAD_B) << 1);
    if ((encoder_state[0] & 0x3) != new_status)
    {
        encoder_state[0] <<= 2;
        encoder_state[0] |= new_status;
        changed |= encoder_update(0, encoder_state[0]);
    }
    return changed;
}