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

int led_inverter(int value)
{
    printf("\n\nWert invertiert:");
    value = ~value;
    printf_binary(value);

	return value;
}

void led_an_aus_ausgabe(int value, int anzahl)
{
	for (int i = 0; i < anzahl; i++)
	{
        if (value & (1 << i))
        {
            printf("\nLED %d: AN", i);
        }
        else
        {
            printf("\nLED %d: AUS", i);
		}
	}
}