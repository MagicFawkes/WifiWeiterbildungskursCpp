#include <stdbool.h>
#include <stdio.h>
#include "BinaryFunktionen.h"

void printf_binary(int value, int anzahl)
{
    printf("\n0b");
    for (int i = anzahl; i >= 0; i--) {
        putchar((value & (1 << i)) ? '1' : '0');
        //if (i == 4) putchar(' '); // nach 4 Bit trennen
    }
}

int led_inverter(int value)
{
    printf("\n\nWert invertiert:");
    value = ~value;

	return value;
}

int led_inverter_v2(int value, int *counter)
{
    int mask = 0;
    int temp = value;
    bool condition = true;
    *counter = 0;

    while (condition) {
        mask = (mask << 1) | 1; //0000 | 0001 = 0001, 0010 | 0001 = 0011, 0110 | 0001 = 0111 
        temp >>= 1;             //0101 -> 0010 -> 0001 -> 0000
        *counter = *counter+1;
        if (temp == 0) {
            break;
            //condition = false;
        }
    }

    printf("\n\nWert vorher:");
    printf_binary(value, *counter);

	value = value ^ mask; //XOR(0101,0111) = 0010 

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