/*

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "src/BinaryFunktionen.h"

int eingabe(const char* message);

int main()
{
	int ledStatus = eingabe("Geben Sie einen Wert fuer die LEDs ein: ");
    printf_binary(ledStatus);
    led_an_aus_ausgabe(ledStatus, 10);

    ledStatus = led_inverter(ledStatus);
    led_an_aus_ausgabe(ledStatus, 10);
   
    return 0;
}

int eingabe(const char* message)
{
    int wert;

    printf("%s", message);
    scanf("%d", &wert);

    return wert;
}
