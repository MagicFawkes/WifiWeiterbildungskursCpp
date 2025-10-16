/*
Schreiben Sie ein C Programm zur Berechnung der Temperatur in unterschiedlichen Einheiten
(Fahrenheit, Celsius, etc). Formeln finden Sie im Internet. Der Benutzer soll entscheiden, ob die
eingegebene Temperatur in Cel, Fahrenheit etc. und in welcher Einheit die Umrechung
stattfindet.
das Programm soll folgendes besitzen:
• Eine Funktion, welche dem Benutzer erklärt, was das Programm tut
• Eine Funktion zur Eingabe
• Eine Funktion zur Berechnung der Distanz
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int eingabe(const char* message);
void programmbeschreibung(const char* message);
float umrechner(int wert, int auswahl);

int main()
{
    programmbeschreibung("Umrechnung von Fahrenheit in Celsius und umgekehrt:");

    int auswahl = eingabe("Bitte Eingabe fuer Fahrenheit=1 und fuer Celsius=2: ");

	char prompt[64];
	snprintf(prompt, sizeof(prompt), "Bitte %s eingeben: ", (auswahl == 1) ? "Fahrenheit" : "Celsius");
    int wert = eingabe(prompt);

	printf("Der Wert betraegt: %.2f", umrechner(wert, auswahl));

    return 0;
}

float umrechner(int wert, int auswahl)
{
    return auswahl == 1 ? (wert - 32) / 1.8 : wert * 1.8 + 32;
}

int eingabe(const char* message)
{
    int wert;
    printf("%s", message);
    scanf("%d", &wert);

    return wert;
}

void programmbeschreibung(const char* message)
{
    printf("Funktionsbeschreibung: %s\n", message);
}

