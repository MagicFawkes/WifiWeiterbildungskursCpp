/*

 free(namenListe[i])
→ gibt den einzelnen String frei, den du mit malloc(strlen(name)+1) allokiert hast.

free(namenListe)
→ gibt das Array von Zeigern frei, das du mit realloc() erstellt hast.

Das Programm liest eine Liste von Namen aus einer Datei
ein und speichert jeden Namen dynamisch in einem wachsenden
Array von Zeichenketten. Für jeden eingelesenen Namen wird
Speicher reserviert und der Name dort abgelegt. Anschließend
werden alle Namen ausgegeben und am Ende der belegte Speicher
vollständig freigegeben.
Es demonstriert damit dynamische Speicherverwaltung mit malloc, realloc und free.
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
		namenListe[zeilen - 1] = (char*)malloc(strlen(name) + 1);		// +1 fuer das Nullterminierungszeichen
		strcpy(namenListe[zeilen - 1], name);	//strcopy kopiert den namen in den allokierten Speicher mit \0 am Ende
	}

	for (int i = 0; i < zeilen; i++)
	{
		printf("Name %d: %s\n", i, namenListe[i]);
		free(namenListe[i]);
	}

	free(namenListe);
	fclose(ptrRead);

    return 0;
}