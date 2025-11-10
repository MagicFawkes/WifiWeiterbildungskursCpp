/*
Das Programm erzeugt eine bestimmte Anzahl von Zufallszahlen innerhalb eines
vorgegebenen Zahlenbereichs. Dabei wird darauf geachtet, dass möglichst
keine Zahl doppelt vorkommt; wiederholte Werte werden erneut ausgelost,
bis eine neue Zahl gefunden wird oder ein Limit erreicht ist.
Am Ende werden alle erzeugten Zufallszahlen ausgegeben.
Es dient somit zur Erzeugung einer Liste zufälliger, möglichst einzigartiger Werte.


*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ZAHLEN 1000

int main()
{
    int zufallszahl[MAX_ZAHLEN];

    srand(time(NULL));
    int anzahl = 0;
    int minGrenze = 0;
	int maxGrenze = 0;

    printf("Bitte geben Sie an, wieviel Zufallszahlen generiert werdne sollen:");
    scanf("%d", &anzahl);

    if (MAX_ZAHLEN < anzahl)
        anzahl = MAX_ZAHLEN;

    printf("Min Grenze: ");
    scanf("%d", &minGrenze);

    printf("Max Grenze: ");
    scanf("%d", &maxGrenze);

    int generierteZahl = 0;
    bool repeat = false;
    int loopErkannt = 0;

    for (int i = 0; i < anzahl; i++)
    {
        do
        {
			repeat = false;
            generierteZahl = (rand() % (maxGrenze - minGrenze + 1)) + minGrenze;

            for (int j = i; j > 0; j--)
            {
                if (generierteZahl == zufallszahl[j-1])
                {
                    repeat = true;
                    loopErkannt++;
					printf("Wiederholung erkannt: %d\n", generierteZahl);
                }
            }
        } while (repeat && loopErkannt < 100);

    	zufallszahl[i] = generierteZahl;
    }

    for (int i = 0; i < anzahl; i++)
    {
        printf("Die Zufallszahl ist: %d\n", zufallszahl[i]);
    }

    return 0;
}