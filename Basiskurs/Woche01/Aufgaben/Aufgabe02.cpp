/*
Schreiben Sie ein C Programm, welches zur Berechnung des Gehaltes verwendet wird.
Eingegeben werden Gehalt und Anzhal der Kinder. bei einem Kind eine Zulage von 125, ab 2 von
110 pro kind, ab mehr als 2 100 pro Kind, ab mehr als sechs keine weitere Zulage.
Das Programm soll folgendes besitzen:
• Eine Funktion zur Speicherung der Eingaben
• Eine Funktion zur des Gehaltes
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int eingabe(const char* message);
float berechnungGehaltmitZulage(float gehalt, int anzahlKinder);

int main()
{
    int anzahlKinder;
    float gehalt;

    anzahlKinder = eingabe("Bitte Anzahl der Kinder eingeben: ");
    gehalt = eingabe("Bitte Gehalt eingeben: ");


    printf("Der Gehalt mit Zulagen betraegt: %.2f", berechnungGehaltmitZulage(gehalt, anzahlKinder));

    return 0;
}

float berechnungGehaltmitZulage(float gehalt, int anzahlKinder)
{
    float zulage = 0;

    if (anzahlKinder == 1)
    {
        zulage = 125;
    }
    else if (anzahlKinder == 2)
    {
		zulage = 110 * 2;
    }
    else if (anzahlKinder > 2 && anzahlKinder <= 6)
    {
        zulage = 100 * anzahlKinder;
    }
    else if (anzahlKinder > 6)
    {
        zulage = 100 * 6;
    }

	return gehalt + zulage;
}

int eingabe(const char* message)
{
    int wert;
    printf("%s", message);
    scanf("%d", &wert);

    return wert;
}
