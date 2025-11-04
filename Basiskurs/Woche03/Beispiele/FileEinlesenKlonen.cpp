/*

Datei.txt Inhalt:
x 8 y  45 test100
Hallo 55 Welt -23
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main()
{
    int array[100];
    int i = 0;

	FILE* ptrRead = fopen("Datei.txt", "r");
    FILE* ptrWrite = fopen("Datei1.txt", "w");

    if (ptrRead == NULL || ptrWrite == NULL)
    {
		printf("File konnte nicht geoeffnet werden.\n");
		return 1;
    }

	int c = 0;

	while ((c = fgetc(ptrRead)) != EOF)
	{
		fputc(c, ptrWrite);
	}

	fclose(ptrRead);
	fclose(ptrWrite);

    return 0;
}
