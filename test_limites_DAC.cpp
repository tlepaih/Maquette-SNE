/* mbed Microcontroller Library
 * Copyright (c) 2018 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

AnalogOut Aout(PA_4);

int main()
{
    float a = 0;

    while (true) {

        Aout = a;

        a += 0.2f;

        if(a > 1.0f)
            a = 0.0f; 
    }
}
