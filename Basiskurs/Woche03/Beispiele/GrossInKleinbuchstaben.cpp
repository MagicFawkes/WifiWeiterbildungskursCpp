/*

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void inKGrossbuchstabenUmwandeln(char eingabe[]);
void inKleinbuchstabenUmwandeln(char eingabe[]);

int main()
{
    char eingabe[20];

    do
    {
        printf("Bitte Wort eingeben: ");
        scanf("%19s", eingabe);     // \0 am Ende des Strings reservieren daher 19 statt 20

        printf("Grossbuchstaben - ");
        inKGrossbuchstabenUmwandeln(eingabe);
        printf("Wort: %s\n", eingabe);

        printf("Kleinbuchstaben - ");
        inKleinbuchstabenUmwandeln(eingabe);
        printf("Wort: %s\n", eingabe);

    } while (true);

    return 0;
}

void inKleinbuchstabenUmwandeln(char eingabe[])
{
    int i = 0;

    while (eingabe[i] != '\0')
    {
        if (eingabe[i] >= 65 && eingabe[i] <= 90)
            eingabe[i] += 32;
        i++;
    }
}

void inKGrossbuchstabenUmwandeln(char eingabe[])
{
    int i = 0;

    while (eingabe[i] != '\0')
    {
        if (eingabe[i] >= 97 && eingabe[i] <= 122)
            eingabe[i] -= 32;
        i++;
    }
}