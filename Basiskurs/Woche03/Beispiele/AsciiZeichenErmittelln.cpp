/*

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAXCOUNT 128

int ermittlteGesamtzahlZeichen(int ascii[]);
int ermittlteAnzahlBuchstaben(int ascii[]);
void ermittlteHaeufigkeitBuchstaben(int ascii[]);
void ermittleHaeufigstesZeichen(int ascii[]);

int main()
{
	int ascii[MAXCOUNT] = { 0 }; //Initialisierung des Arrays für alle Werte mit 0 ist wichtig
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
    printf("Gesamtzahl aller eingelesenen Zeichen %d \n", ermittlteGesamtzahlZeichen(ascii));
    printf("Hauefigkeit aller Gross- und Kleinbuchstaben %d \n", ermittlteAnzahlBuchstaben(ascii));
    ermittlteHaeufigkeitBuchstaben(ascii);
    ermittleHaeufigstesZeichen(ascii);

    return 0;
}

int ermittlteGesamtzahlZeichen(int ascii[])
{
    int anzahl = 0;

    for (int i = 0; i < 128; i++)
    {
        anzahl += ascii[i];
    }
	return anzahl;
}

int ermittlteAnzahlBuchstaben(int ascii[])
{
    int anzahl = 0;

    for (int i = 65; i <= 122; i++)
    {
        if ((i >= 65 && i <= 90) || (i >= 97 && i <= 122))
            anzahl += ascii[i];
    }

    return anzahl;
}

void ermittlteHaeufigkeitBuchstaben(int ascii[])
{
    int anzahl = 0;

    for (int i = 65; i <= 90; i++)
    {
        if (ascii[i] > 0)
			printf("Grossbuchstabe %c ist %d vorgekommen\n", i, ascii[i]);
    }

    for (int i = 97; i <= 122; i++)
    {
        if (ascii[i] > 0)
			printf("Kleibuchstabe %c ist %d vorgekommen\n", i, ascii[i]);
    }
}

void ermittleHaeufigstesZeichen(int ascii[])
{
    int max = 0;
    int zeichen = 0;

    for (int i = 0; i < 128; i++)
    {
        if (max < ascii[i])
        {
	        max = ascii[i];
			zeichen = i;
        }
    }

    printf("Häufigigste Zeichen %c ist %d vorgekommen\n", zeichen, max);
}