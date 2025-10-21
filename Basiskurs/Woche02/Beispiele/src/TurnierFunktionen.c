

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "TurnierFunktionen.h"

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