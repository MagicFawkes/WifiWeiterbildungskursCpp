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

int main()
{
	FILE* ptrRead = fopen("namenliste.txt", "r");

    if (ptrRead == NULL)
    {
		printf("File konnte nicht geoeffnet werden.\n");
		return 1;
    }

	int zeilen = 0;

	char** namenListe = NULL;

	char name[100];

	while (fscanf(ptrRead, "%s", name) != EOF)
	{
		printf("Gelesener Name: %s\n", name);

		zeilen++;
		namenListe = (char**)realloc(namenListe, zeilen * sizeof(char*));
		namenListe[zeilen - 1] = (char*)malloc(strlen(name) + 1);
		strcpy(namenListe[zeilen - 1], name);
	}

	for (int i = 1; i < zeilen; i++)
	{
		printf("Name %d: %s\n", i, namenListe[i]);
		free(namenListe[i]);
	}

	free(namenListe);

	fclose(ptrRead);

    return 0;
}