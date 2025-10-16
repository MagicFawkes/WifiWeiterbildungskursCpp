#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int eingabe = 0, neueSumme = 0, zahl = 0;

    printf("Bitte gib eine Zahl ein: ");
    scanf("%d", &eingabe);

    while (eingabe % 10 != 0)
    {
        zahl = eingabe % 10;
        neueSumme = zahl + (neueSumme * 10);
        eingabe = eingabe / 10;
    }

    printf("Neue Zahl: %d\n", neueSumme);

    return 0;
}
