/*
Das Programm fragt wiederholt nach einer Lieblingsfrucht,
bis das eingegebene Wort „apple“ (Groß-/Kleinschreibung
beim ersten Buchstaben egal) erkannt wird.
Die Funktion compare prüft dazu Länge und Zeichen des Wortes.
Erst wenn das richtige Wort eingegeben wurde, endet die Eingabe und es erfolgt eine Bestätigung.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

bool compare(char eingabe[]);

int main()
{
    char eingabe[20];
    
    do
    {
		printf("Was ist Ihre Lieblingsfrucht?: ");
        scanf("%s", eingabe);

    } while (!compare(eingabe));

    printf("Wort richtig erkannt");

    return 0;
}

bool compare(char eingabe[])
{
    char compare[] = "apple";
    int i = 0;

    while (eingabe[i] != '\0')
    {
        i++;
    }

    if (i != 5)
    {
        return false;
    }

    if (eingabe[0] != 'a' && eingabe[0] != 'A')
        return false;

    i = 1;

    while (eingabe[i] != '\0')
    {
        if (eingabe[i] != compare[i])
        {
            return false;
        }

		i++;
    }

    return true;
}