

#include <stdio.h>
#include <stdbool.h>
#include "binaryIO.h"

void print_binary(int value)
{
    int anzahl = 0;
    int mask = 0;
    int temp = value;
    bool condition = true;

    while (condition)
    {
        mask = (mask << 1) | 1; //0000 | 0001 = 0001, 0010 | 0001 = 0011, 0110 | 0001 = 0111 
        temp >>= 1;             //0101 -> 0010 -> 0001 -> 0000
        anzahl = anzahl + 1;
        if (temp == 0)
        {
            break;
            //condition = false;
        }
    }

    printf("0b");

    for (int i = anzahl - 1; i >= 0; i--)
    {
        putchar((value & (1 << i)) ? '1' : '0');
        if (i % 4 == 0) putchar(' '); // nach 4 Bit trennen
    }
}

bool istBinary(char input[], int* dezimal)
{
    int position = 0;

    while (input[position] != '\0')
    {
        if ((input[position] != '0') && (input[position] != '1') && (input[position] != '\n'))
            return false;

        position++;
    }

    *dezimal = 0;

    for (int i = position - 2; i >= 0; i--)
    {
        *dezimal |= (input[i] == '1' ? (1 << (position - 2 - i)) : 0x00);
    }

    return true;
}
