/*
Das Programm liest einen Namen ein, ohne vorher zu wissen,
wie lang er ist, und vergrößert dazu den Speicher während
der Eingabe dynamisch mit realloc. Zeichen für Zeichen wird
der Name aufgebaut, bis ein Zeilenumbruch eingegeben wird.
Anschließend wird der fertige Name ausgegeben.
Es dient also als Beispiel für dynamische Speicherverwaltung in C.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdlib>
#include <stdio.h>

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
    printf("%s", name);

    return 0;
}