/*

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int ermittlteGesamtzahlZeichen(int ascii[]);
int ermittlteHaufigkeitBuchstaben(int ascii[]);

int main()
{
    int ascii[128] = {0};
    int c = 0;

    printf("*************************************");
    printf("\nBitte geben Sie einen Satz oder Text ein (Beenden: Strg+Z danach Enter druecken):\n");

    while ((c = getchar()) != EOF)
    {
        ascii[c]++;
    }

	printf("Es wurden %d Leerzeichen eingegeben\n", ascii[32]);         //ASCII-Wert fuer Leerzeichen ist 32
	printf("Es wurden %d Tabulatoren eingegeben\n", ascii[9]);          //ASCII-Wert fuer Tabulator ist 9
	printf("Es wurden %d Zeilenumbrueche eingegeben\n", ascii[10]);     //ASCII-Wert fuer Zeilenumbruch ist 10
    printf("Gestamzahl aller eingelesenen Zeichen %d \n", ermittlteGesamtzahlZeichen(ascii));
    printf("Hauefigkeit aller Gross- und Kleinbuchstaben %d \n", ermittlteHaufigkeitBuchstaben(ascii));
    return 0;
}

int ermittlteGesamtzahlZeichen(int ascii[])
{
    int anzahl = 0;

    for (int i = 0; i < 256; i++)
    {
        anzahl += ascii[i];
    }
	return anzahl;
}

int ermittlteHaufigkeitBuchstaben(int ascii[])
{
    int anzahl = 0;

    for (int i = 0; i < 256; i++)
    {
        if ((i >= 65 && i <= 90) || (i >= 97 && i <= 122))
            anzahl += ascii[i];
    }

    return anzahl;
}