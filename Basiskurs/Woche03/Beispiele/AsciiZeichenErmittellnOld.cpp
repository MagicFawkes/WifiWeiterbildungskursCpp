/*
Das Programm liest einen eingegebenen Text ein und zählt
dabei verschiedene Elemente wie Wörter, Zeilen, Zeichen,
Leerzeichen und Tabulatoren. Die Funktion eingabe()
führt die Analyse durch, indem sie den Text Zeichen für
Zeichen auswertet und anhand von Leer- und Trennzeichen
Wortgrenzen erkennt. Die Ergebnisse werden anschließend
im Hauptprogramm ausgegeben. Es dient zur grundlegenden Textstatistik.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>

struct Auswertung
{
    int anzahlWoerter = 0;
    int anzahlZeilen = 0;
    int anzahlZeichen = 0;
    int anzahlLeerzeichen = 0;
    int anzahlTabulator = 0;
    int anzahlGroßbuchstaben = 0;
    int anzahlKleinbuchstaben = 0;
};

struct Auswertung eingabe();

int main()
{
    do
    {
        printf("*************************************");
        printf("\nBitte geben Sie einen Satz oder Text ein (Beenden: Strg+Z danach Enter druecken):\n");

        Auswertung auswertung = eingabe();

        printf("\nDer Text hat %d Woerter", auswertung.anzahlWoerter);
        printf("\nDer Text hat %d Zeilen", auswertung.anzahlZeilen);
        printf("\nDer Text hat %d Zeichen\n", auswertung.anzahlZeichen);
        printf("\nDer Text hat %d Leerzeichen\n", auswertung.anzahlLeerzeichen);
        printf("\nDer Text hat %d Tabulator\n", auswertung.anzahlTabulator);
    } while (true);

    return 0;
}

struct Auswertung eingabe()
{
    struct Auswertung auswertung;

    int imWort = 0;  // Zustand: 0 = außerhalb, 1 = innerhalb eines Wortes

    int c = 0;

    while ((c = getchar()) != EOF)
    {
        auswertung.anzahlZeichen++;

        if (isspace(c) || c == '\n' || c == '!')
        {
            imWort = 0;

            if (c == '\n')
            {
                auswertung.anzahlZeilen++;
            }

            if (isspace(c))
            {
                auswertung.anzahlLeerzeichen++;
            }

            if (c == '\t')
            {
                auswertung.anzahlTabulator++;
            }
        }
        else if (!imWort)
        {
            imWort = 1;
            auswertung.anzahlWoerter++;
        }
    }

    return auswertung;
}