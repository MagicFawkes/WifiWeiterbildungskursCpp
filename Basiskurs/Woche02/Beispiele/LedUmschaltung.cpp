/*

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "src/BinaryFunktionen.h"

int eingabe(const char* message);

int main()
{
	int ledStatus = eingabe("Geben Sie einen Wert fuer die LEDs ein: ");
    //printf_binary(ledStatus, 10);
    //led_an_aus_ausgabe(ledStatus, 10);

    //edStatus = led_inverter(ledStatus);
    //led_an_aus_ausgabe(ledStatus, 10);

    int counter;
    ledStatus = led_inverter_v2(ledStatus, &counter);
    led_an_aus_ausgabe(ledStatus, counter);
    printf_binary(ledStatus, counter);

    return 0;
}

int eingabe(const char* message)
{
    int wert;
    int result;

    printf("%s", message);
    result = scanf("%d", &wert);

	if (result != 1) 
    {
        // Handle input error, e.g., set default value or print error
        printf("Ungueltige Eingabe. Standardwert 0 wird verwendet.\n");
        wert = 0;
    }

    return wert;
}
