/*

 free(namenListe[i])
→ gibt den einzelnen String frei, den du mit malloc(strlen(name)+1) allokiert hast.

free(namenListe)
→ gibt das Array von Zeigern frei, das du mit realloc() erstellt hast.

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    int zufallszahl[100];

    srand(time(NULL));
    int anzahl = 0;
    int minGrenze = 0;
	int maxGrenze = 0;

    printf("Bitte geben Sie an, wieviel Zufallszahlen generiert werdne sollen:");
    scanf("%d", &anzahl);

    printf("Min Grenze: ");
    scanf("%d", &minGrenze);

    printf("Max Grenze: ");
    scanf("%d", &maxGrenze);

    for (int i = 0; i < anzahl; i++)
    {
        zufallszahl[i] = (rand() % (maxGrenze - minGrenze + 1)) + minGrenze;
    }

    for (int i = 0; i < anzahl; i++)
    {
        printf("Die Zufallszahl ist: %d\n", zufallszahl[i]);
    }


    return 0;
}