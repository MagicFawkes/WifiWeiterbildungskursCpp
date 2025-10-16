/*
Dieses Programm berechnet die Quersumme einer vom Benutzer eingegebenen ganzen Zahl.
Der Ablauf ist folgender:
1. Der Benutzer wird aufgefordert, eine Zahl einzugeben.
2. Das Programm liest die Eingabe und ruft die Funktion 'berechneQuersumme' auf.
3. In dieser Funktion wird die Zahl Ziffer für Ziffer zerlegt und die Summe der Ziffern berechnet.
4. Die berechnete Quersumme wird anschließend auf der Konsole ausgegeben.

Beispiel:
Eingabe: 1234
Berechnung: 1 + 2 + 3 + 4 = 10
Ausgabe: Quersumme: 10
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int berechneQuersumme(int eingabe);

int main()
{
    int eingabe = 0;

    printf("Bitte gib eine Zahl ein: ");
    scanf("%d", &eingabe);

    printf("Quersumme: %d\n", berechneQuersumme(eingabe));

    return 0;
}

int berechneQuersumme(int eingabe)
{
    int quersumme = 0;

    while (eingabe != 0)
    {
        quersumme += eingabe % 10;
        eingabe /= 10;
    }
    return quersumme;
}
