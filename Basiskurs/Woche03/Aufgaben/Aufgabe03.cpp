/*
Aufgabe 3
Schreiben Sie ein C-Programm, das chars in ints umwandelt. Beispeil wird A eingegeben, soll
es nicht in einer int variable gespeichert werden, sondern wird dies mit der von ihnen
programmierten Funktion gemacht.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int charToInt(char c);

int main()
{
    char eingabe;

    printf("Bitte einen Buchstaben eingeben: ");
    scanf("%c", &eingabe);
    printf("\nIhre Eingabe ist %c", eingabe);
    printf("\nDer ASCII Wert ist: %d", charToInt(eingabe));

    return 0;
}

int charToInt(char c)
{
    return (int)c;
}