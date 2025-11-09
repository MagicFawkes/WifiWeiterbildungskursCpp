/*
Aufgabe 1
Schreiben Sie ein C-Programm, das aus einer Text datei Namen liest und diese dann einmal in
einem Array und einmal in einer mehrdimensionalen Matrix speichert (dynamische
Speicherallokierung). Der Inhalt der Text Datei sieht folgendermaßen aus:
Abdalla 65Manuel
Felix8983454Micheal
Se ba sti an
Bitte das Programm soll möglichst alle Fälle behandeln können, das heißt, das Programm soll
so geschrieben werden, dass möglichst viele Fälle abgedeckt werden (tun Sie so, als würden
Sie nicht wissen, was in der Textdatei drinnen ist.)

dynamisches Array von Strings (pointer auf Pointer) oder formal: dynamisches Array von Zeigern auf char.
char** namenListe = NULL; bezeichnet man als ein

Mehrdimensionales Matrix:
Matrix-Teil wäre später ein rechteckiges 2D-Array, z. B.:

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* ptrRead = fopen("aufgabe01.txt", "r");

	if (ptrRead == NULL)
	{
		printf("File konnte nicht geoeffnet werden.\n");
		return 1;
	}

	int zeilen = 0;

	// Dynamisches Array von Strings (Pointer auf Pointer auf char)
	char** namenListe = NULL;  // WICHTIG: initialisieren!

	int c = 0;
	int imWort = 0;
	int zaehler = 0;

	//Mehrdimensionales dynamische Matrix, 2D-Matrix (rechteckig, zusammenhängender Speicher
	const int spalten = 20;
	char (*matrix)[spalten] = (char (*)[spalten]) malloc(zeilen * sizeof * matrix);

	while ((c = fgetc(ptrRead)) != EOF)
	{
		if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
		{
			if(!imWort)
			{
				zaehler = 0;
				zeilen++;
				namenListe = (char**)realloc(namenListe, zeilen * sizeof(char*));
				namenListe[zeilen - 1] = NULL; // WICHTIG: initialisieren!
				imWort = 1;
			}

			zaehler++;
			matrix = (char (*)[spalten]) realloc(matrix, zeilen * sizeof * matrix);
			matrix[zeilen - 1][zaehler - 1] = (char)c;
			matrix[zeilen - 1][zaehler] = '\0'; // Nullterminierung

			namenListe[zeilen - 1] = (char*)realloc(namenListe[zeilen - 1], zaehler + 1);		// +1 fuer das Nullterminierungszeichen
			namenListe[zeilen - 1][zaehler - 1] = (char)c; // Zeichen speichern
			namenListe[zeilen - 1][zaehler] = '\0'; // Nullterminierung
		}
		else if (imWort)
		{
			imWort = 0;
		}
	}

	printf("Array:\n");
	for (int i = 0; i < zeilen; i++)
	{
		printf("Name %d: %s\n", i, namenListe[i]);
		free(namenListe[i]);
	}
	free(namenListe);

	printf("\nMatrix:\n");
	for (int i = 0; i < zeilen; i++)
	{
		int j = 0;

		printf("Name %d: ", i);

		while (matrix[i][j] != '\0') // Zeichen prüfen
		{
			printf("%c", matrix[i][j]);
			j++;
		}
		printf("\n");
	}

	free(matrix);

	fclose(ptrRead);

    return 0;
}