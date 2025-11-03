/*

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void inKGrossbuchstabenUmwandeln(char palidrom[]);
void inKleinbuchstabenUmwandeln(char palidrom[]);

int main()
{
    char eingabe[20];

    do
    {
        printf("Bitte Wort eingeben: ");
        scanf("%19s", eingabe);     // \0 am Ende des Strings reservieren daher 19 statt 20

        inKGrossbuchstabenUmwandeln(eingabe);
        printf("Wort: %s\n", eingabe);

        inKleinbuchstabenUmwandeln(eingabe);
        printf("Wort: %s\n", eingabe);

    } while (true);

    return 0;
}

void inKleinbuchstabenUmwandeln(char palidrom[])
{
    int i = 0;

    while (palidrom[i] != '\0')
    {
        if (palidrom[i] >= 65 && palidrom[i] <= 90)
			palidrom[i] += 32;
        i++;
    }
}

void inKGrossbuchstabenUmwandeln(char palidrom[])
{
    int i = 0;

    while (palidrom[i] != '\0')
    {
        if (palidrom[i] >= 97 && palidrom[i] <= 122)
            palidrom[i] -= 32;
        i++;
    }
}