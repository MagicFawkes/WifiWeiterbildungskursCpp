/*
Aufgabe 3
Programmiere in einer eigenen Bibliothek „binaryIO“ folgende Funktionen:
Eine Funktion, welche eine binäre Zahl einliest und angibt, ob die angegebene Zahl eine binäre
Zahl ist oder nicht. Beispiel:
Bei Eingabe 11011 wird true zurückgegeben. Bei Eingabe von abc110hugo11x ist der
Rückgabewert false. Es soll außerdem die Zahl in Dezimalform zurückgegeben werden.
Eine void Funktion, welche einen int-Parameter hat. Die Ausgabe soll „binär erfolgen“. Wenn
also im Parameter der Wert 27 steht, dann soll 11011 ausgegeben werden.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "src/binaryIO.h"

void eingabe(char input[], const char* message);

int main()
{
    char input[100];  // Puffer mit Platz für 99 Zeichen + '\0'
    int dezimal = 0;

    eingabe(input, "Gib eine Binaere Zahl ein: ");

	if (istBinary(input, &dezimal))
    {
        printf("Ist Binaer\n");
        printf("Dezimal: %d \n", dezimal);
		print_binary(dezimal);
    }
    else
    {
        printf("Ist nicht Binaer\n");
    }

    return 0;
}

void eingabe(char input[], const char* message)
{
    printf("%s", message);

    if (fgets(input, sizeof(input), stdin) != NULL)
    {
        printf("Du hast eingegeben: %s", input);
    }
    else
    {
        printf("Fehler beim Einlesen!\n");
    }
}
