/*
==============================================================
    Programm: Potenzberechnung mit Schleife
    Beschreibung:
        Dieses Programm berechnet die Potenz einer Basiszahl
        mit einem ganzzahligen Exponenten. Der Benutzer gibt
        sowohl die Basis als auch den Exponenten ein, woraufhin
        das Programm die Potenz berechnet und ausgibt.

    Funktionsweise:
        1. Der Benutzer wird aufgefordert, eine Basis und
           einen Exponenten einzugeben.
        2. Eine for-Schleife multipliziert die Basis so oft
           mit sich selbst, wie es der Exponent angibt.
        3. Das Ergebnis wird anschlieﬂend auf der Konsole ausgegeben.

    Beispiel:
        Eingabe:
            Basis = 2
            Exponent = 4
        Ausgabe:
            Die Potenz der Basis 2 und des Exponenten 4 ergibt 16
==============================================================
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int potenzBerechnen(int basis, int exponent);

int main()
{
    int basis = 1, exponent = 0;

    printf("Bitte gib die Basiszahl ein: ");
    scanf("%d", &basis);

    printf("Bitte gib den Exponenten ein: ");
    scanf("%d", &exponent);

    printf("Die Potenz der Basis %d und des Exponenten %d ergibt %d\n", basis, exponent, potenzBerechnen(basis, exponent));

    return 0;
}

int potenzBerechnen (int basis, int exponent)
{
	int potenz = 1;

    for (int i = 0; i < exponent; i++)
    {
        potenz *= basis;
    }

    return potenz;
}