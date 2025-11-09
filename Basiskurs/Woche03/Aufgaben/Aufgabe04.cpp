/*
Aufgabe 4
Schreiben Sie ihre eigene strcmp, strcp sowie atoi Funktionen. Behandeln Sie hier die Fälle, die
wir in der Vorlesung besprochen haben (Bufferoverflow etc.).
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int strcmp(char* str1, char* str2);

int main()
{
    char eingabe[100];
    char vergleich[] = {"Test"};
    printf("Bitte einen Begriff ein: ");
    scanf("%s", eingabe);
    printf("Der Vergleich von Eingabewort %s zum Vergleichswort %s ergab %s\n", 
        eingabe, vergleich, strcmp(eingabe, vergleich)? "ident" : "nicht ident");

    return 0;
}

int strcmp(char* str1, char* str2)
{
    int str1LaengeStr1 = 0;
    int str1LaengeStr2 = 0;

    int i = 0;

    while (str1[i] != '\0')
    {
        str1LaengeStr1++;
        i++;
    }

    i = 0;
    while (str2[i] != '\0')
    {
        str1LaengeStr2++;
        i++;
    }

    if (str1LaengeStr1 != str1LaengeStr2)
        return 0;

    for (i = 0; i < str1LaengeStr1; i++)
    {
        if (str1[i] != str2[i])
            return 0;
    }

    return 1;
}