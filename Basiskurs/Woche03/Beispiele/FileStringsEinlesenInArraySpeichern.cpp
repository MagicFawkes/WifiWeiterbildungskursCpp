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
	FILE* ptrRead = fopen("namenliste.txt", "r");

    if (ptrRead == NULL)
    {
		printf("File konnte nicht geoeffnet werden.\n");
		return 1;
    }

	char name[100];

	while (fscanf(ptrRead, "%s", name) != EOF)
	{
		printf("Gelesener Name: %s\n", name);

	}

	fclose(ptrRead);

    return 0;
}
