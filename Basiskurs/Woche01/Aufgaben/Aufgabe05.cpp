/*
Schreiben Sie ein C Programm, das eine Zeichenkette einliest und die Anzahl der Wörter zählt.Das Programm soll folgendes besitzen:
• Eine Funktion zur Speicherung der Eingabe
• Eine Funktion, um die Anzahl der Wörter zu zählen
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_LEN 100

void eingabe(const char* message, int maxCount, char satz[]);
int zaehleWoerter(const char* text);

int main()
{
    char satz[MAX_LEN];
    eingabe("Bitte geben Sie einen Satz ein: ", MAX_LEN, satz);

	printf("Folgendes wurde eingegeben: %s", satz);
    printf("Der Satz hat %d Woerter", zaehleWoerter(satz));

    return 0;
}

void eingabe(const char* message, int maxCount, char satz[])
{
    printf("%s", message);
    fgets(satz, maxCount, stdin);
}

int zaehleWoerter(const char* text)
{
    int zaehler = 0;
    int imWort = 0;  // Zustand: 0 = außerhalb, 1 = innerhalb eines Wortes

    for (int i = 0; text[i] != '\0'; i++) 
    {
        if (text[i] == ' ') 
        {
            imWort = 0;
        }
        else if (!imWort) 
        {
            imWort = 1;
            zaehler++;
        }
    }

    return zaehler;
}