/*

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* name = (char*)malloc(sizeof(char));
    int c = 0;
    int i = 0;
    void* tmp;

    if (name == NULL)
    {
        printf("Fehler bei der Speicherallokation\n");
        return 1;
    }

    printf("Bitte geben Sie ihren Namen ein: ");

    while ((c = getchar()) != '\n')
    {
        tmp = realloc(name, i + 2); // +1 fuer das neue Zeichen, +1 fuer das '\0'

        if (tmp == NULL)
        {
            printf("Fehler bei der Speicherallokation\n");
            free(name);
            return 1;
        }

        name = (char*)tmp;
        name[i] = (char)c;
        i++;
    }
    name[i] = '\0';

    printf("Stringlaenge ist: %d\n", i);

    return 0;
}

