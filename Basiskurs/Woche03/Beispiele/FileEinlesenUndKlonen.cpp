/*

Datei.txt Inhalt:
x 8 y  45 test100
Hallo 55 Welt -23

Das Programm öffnet eine Textdatei zum Lesen und
eine zweite zum Schreiben. Es liest die erste Datei
Zeichen für Zeichen ein und schreibt jedes Zeichen
direkt in die zweite Datei. Dadurch entsteht eine g
enaue Kopie der ursprünglichen Datei.
Es zeigt den einfachen Umgang mit Datei-Ein- und Ausgabe in C.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main()
{
	FILE* ptrRead = fopen("input.txt", "r");
    FILE* ptrWrite = fopen("copy.txt", "w");

    if (ptrRead == NULL || ptrWrite == NULL)
    {
		printf("File konnte nicht geoeffnet werden.\n");
		return 1;
    }

	int c = 0;

	while ((c = fgetc(ptrRead)) != EOF)
	{
		int result = fputc(c, ptrWrite);

		if (result == EOF)
			printf("Fehler beim Schreiben!\n");
	}

	fclose(ptrRead);
	fclose(ptrWrite);

    return 0;
}
