/*
Aufgabe 1
Erstellen Sie eine dynamische und statische Bibliothek für die Berechnung von Fläche und
Umfang folgender Figuren (Rechteck, Quadrat, Kreis, Dreieck). Deaktivieren Sie die
vorkompilierten Header!
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "dynlib/include/geometrie.h"

void ausgabeAuswahl(const char* message);
float eingabe(const char* message);

int main()
{
    int figur;
    float umfang = 0, fläche = 0;

    do
    {
        figur = (int)eingabe("1=Kreis, \n2=Rechteck, \n3=Dreieck, \n4=Quadraht \n0=Beenden \nBitte Figur auswaehlen:  ");

        if (figur == 1)
        {
            ausgabeAuswahl("\nKreis ausgewaehlt:");
            float durchmesser = eingabe("\nBitte Durchmesser eingeben: ");
            kreisBerechnung(&umfang, &fläche, durchmesser);
        }
        else if (figur == 2)
        {
            ausgabeAuswahl("\nRechteck rechtwinkelig ausgewaehlt:");
            float a = eingabe("\nBitte Laenge A eingeben: ");
            float b = eingabe("Bitte Laenge B eingeben: ");
            rechteckBerechnung(&umfang, &fläche, a, b);
        }
        else if (figur == 3)
        {
            ausgabeAuswahl("\nDreieck ausgewaehlt:");
            float a = eingabe("\nBitte Laenge A eingeben: ");
            float b = eingabe("Bitte Laenge B eingeben: ");
            float c = eingabe("Bitte Laenge C eingeben: ");
            dreieckBerechnung(&umfang, &fläche, a, b, c);
        }
        else if (figur == 4)
        {
            ausgabeAuswahl("\nQuadrat ausgewaehlt:");
            float a = eingabe("\nBitte Laenge A eingeben: ");
            quadratBerechnung(&umfang, &fläche, a);
        }
        else if (figur == 0)
        {
            ausgabeAuswahl("Programm Beenden\n");
        }

        if (figur == 1 || figur == 2 || figur == 3 || figur == 4)
        {
            printf("Umfang: %.2f\n", umfang);
            printf("Flaeche: %.2f\n\n", fläche);
        }

    } while (figur != 0);

    return 0;
}

void ausgabeAuswahl(const char* message)
{
    printf("%s", message);
}

float eingabe(const char* message)
{
    float wert;
    printf("%s", message);
    scanf("%f", &wert);

    return wert;
}
