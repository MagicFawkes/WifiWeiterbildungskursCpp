/*
Aufgabe 2
Schreiben Sie ein C-Programm, das aus einer Text Datei die Anzahl der Wörter, leerzeichen,
tabs, zeilenumbrüche sowie Zahlen. Die Datei sieht folgendermaßen aus:
Ich gehe8932 nach Hause
Ich h8ab87e mich
Schlecht gefühlt
Außerdem es soll der Text ohne Zahlen ausgegeben werden an der Konsole (dynamische
Speicherallokierung).
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAXCOUNT 128

int main()
{
	{
		FILE* ptrRead = fopen("aufgabe02.txt", "r");

		if (ptrRead == NULL)
		{
			printf("File konnte nicht geoeffnet werden.\n");
			return 1;
		}

		int ascii[MAXCOUNT] = { 0 };
		int zeilen = 0;

		// Dynamisches Array von Strings (Pointer auf Pointer auf char)
		char** namenListe = NULL;  // WICHTIG: initialisieren!

		int c = 0;
		int imWort = 0;
		int zaehler = 0;
		int anzahlZahlen = 0;

		while ((c = fgetc(ptrRead)) != EOF)
		{
			if (c < 128)
				ascii[c]++;

			if (c >= '0' && c <= '9')
			{
				anzahlZahlen++;
			}

			if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
			{
				if (!imWort)
				{
					zaehler = 0;
					zeilen++;
					namenListe = (char**)realloc(namenListe, zeilen * sizeof(char*));
					namenListe[zeilen - 1] = NULL; // WICHTIG: initialisieren!
					imWort = 1;
				}

				zaehler++;
				namenListe[zeilen - 1] = (char*)realloc(namenListe[zeilen - 1], zaehler + 1);		// +1 fuer das Nullterminierungszeichen
				namenListe[zeilen - 1][zaehler - 1] = (char)c; // Zeichen speichern
				namenListe[zeilen - 1][zaehler] = '\0'; // Nullterminierung
			}
			else if (c == ' ' || c == '\n')
			{
				imWort = 0;
			}
		}

		printf("Text: ");
		for (int i = 0; i < zeilen; i++)
		{
			printf("%s ", namenListe[i]);
			free(namenListe[i]);
		}

		free(namenListe);

		printf("\nEs wurden %d Woerter gezaehlt: ", zeilen);
		printf("\nEs wurden %d Leerzeichen gezaehlt: ", ascii[32]);
		printf("\nEs wurden %d Tabs gezaehlt: ", ascii[9]);
		printf("\nEs wurden %d Zeilenumbrueche gezaehlt: ", ascii[10]);
		printf("\nEs wurden %d Zahlen gezaehlt: \n", anzahlZahlen);
	}
}