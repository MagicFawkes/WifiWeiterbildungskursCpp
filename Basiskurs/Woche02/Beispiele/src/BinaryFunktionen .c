#include <stdio.h>
#include "BinaryFunktionen.h"

void printf_binary(int value)
{
    printf("\n");
    for (int i = 7; i >= 0; i--) {
        putchar((value & (1 << i)) ? '1' : '0');
        if (i == 4) putchar(' '); // nach 4 Bit trennen
    }
}

void led_inverter(int value)
{
    printf("\n\nWert invertiert:");
    value = ~value;
    printf_binary(value);
}