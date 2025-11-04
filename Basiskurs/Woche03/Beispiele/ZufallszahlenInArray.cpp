/*

 free(namenListe[i])
→ gibt den einzelnen String frei, den du mit malloc(strlen(name)+1) allokiert hast.

free(namenListe)
→ gibt das Array von Zeigern frei, das du mit realloc() erstellt hast.

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