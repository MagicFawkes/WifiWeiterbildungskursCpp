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
    eingabe, vergleich, strcmp(eingabe, vergleich) == 0 ? "ident" : "nicht ident!");

    return 0;
}


/*
 *
Standard-strcmp gibt 0 zurück, wenn gleich.
< 0, wenn str1 lexikografisch kleiner als str2 ist.
> 0, wenn str1 lexikografisch größer ist.
*/
int strcmp(char* str1, char* str2)
{
    int str1LaengeStr1 = 0;
    int str1LaengeStr2 = 0;
    int maxLength = 1000;

    int i = 0;

    if (str1 == NULL || str2 == NULL)
        return -2;

    while (str1[i] != '\0')
    {
        str1LaengeStr1++;
        i++;

        if (i > maxLength)
            return -2;
    }

    i = 0;
    while (str2[i] != '\0')
    {
        str1LaengeStr2++;
        i++;

        if (i > maxLength)
            return -2;
    }

    if (str1LaengeStr1 != str1LaengeStr2)
    {
        if (str1LaengeStr1 > str1LaengeStr2)
            return 1;
        return -1;
    }

    for (i = 0; i < str1LaengeStr1; i++)
    {
        if (str1[i] != str2[i])
            return 1;
    }

    return 0;
}