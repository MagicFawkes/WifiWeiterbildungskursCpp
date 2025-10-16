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

int eingabe(const char* message);
bool istQuadratzahl(int zahl);

int main()
{
    int eingabewert = eingabe("Bitte einen Wert eingeben: ");

    if (istQuadratzahl(eingabewert))
		printf("Wert ist quadrat der eingegeben Zahl");
    else
        printf("Wert ist nicht quadrat der eingegeben Zahl");

    return 0;
}

int eingabe(const char* message)
{
    int wert;

    printf("%s", message);
    scanf("%d", &wert);

    return wert;
}

bool istQuadratzahl(int zahl)
{
    if (zahl < 0) 
        return false;  // negative Zahlen haben keine reellen Quadratwurzeln

    double wurzel = sqrt((double)zahl);
    int gerundet = (int)(wurzel + 0.5); // auf nächste ganze Zahl runden

    return gerundet * gerundet == zahl;
}