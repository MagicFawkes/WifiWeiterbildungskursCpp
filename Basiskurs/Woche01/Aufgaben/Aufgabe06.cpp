/*
Schreiben Sie ein C Programm, das überprüft, ob eine eigegebene Zahl, das quadrat einer
ganzen Zahl ist. Bsp 19.2 ist eine kommazahl
Das Programm soll folgendes besitzen:
• Eine Funktion zur Speicherung der Eingabe
• Eine Funktion zur Überprüfung, ist die Zahl das Quadrat einer ganzen Zahl, dann ist wird
eine entsprechende Meldung ausgegeben und umgekehrt
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdbool.h> // Für bool, true, false

float eingabe(const char* message);
bool istQuadratzahl(const float zahl);

int main()
{
    float eingabewert = eingabe("Bitte einen Wert eingeben: ");

    if (istQuadratzahl(eingabewert))
        printf("Die Zahl %f ist eine Quadratzahl.\n", eingabewert);
    else
        printf("Die Zahl %f ist keine Quadratzahl.\n", eingabewert);

    return 0;
}

float eingabe(const char* message)
{
    float wert;

    printf("%s", message);
    scanf("%f", &wert);

    return wert;
}

bool istQuadratzahl(const float zahl)
{
    if (zahl < 0) 
        return false;  // negative Zahlen haben keine reellen Quadratwurzeln

    double wurzel = sqrt((double)zahl);
    int gerundet = (int)(wurzel + 0.5); // auf nächste ganze Zahl runden

    return gerundet * gerundet == zahl;
}