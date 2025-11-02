/*
Aufgabe 7
Erstellen Sie ein Programm zum Lesen eines Strings. Das Programm gibt am Ende aus, wie
viele Zeichen, Zeilen und Worte gez‰hlt wurden. Das Programm l‰uft solange weiter bis der
Benutzer das Programm beendet.
Hinweise: Als Zeilenanzahl kann man die Anzahl der Ç\në verwenden. Um die Anzahl der Worte
festzustellen, muss man sich merken, ob man gerade in einem Wort oder auﬂerhalb eines
Wortes ist und dann, wenn man diesen Zustand von Ñim-Wortì auf Ñauﬂerhalb-Wortì wechselt,
die Anzahl der Worte erhˆhen.
Hilfe: inkludieren Sie ctype.h, um die Funktion isspace zu verwenden.
Verwenden Sie dazu
While ((c = getchar()) != EOF)
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

struct Auswertung
{
    int anzahlWoerter = 0;
    int anzahlZeilen = 0;
    int anzahlZeichen = 0;
};

#define MAX_LEN 256

void eingabe(const char* message, int maxCount, char satz[]);
struct Auswertung zaehleWoerter(const char* text);

int main()
{
    char satz[MAX_LEN];

    do
    {
        printf("*************************************");
        eingabe("\nBitte geben Sie einen Satz ein: ", MAX_LEN, satz);

        Auswertung auswertung = zaehleWoerter(satz);

        printf("Folgendes wurde eingegeben: %s", satz);
        printf("\nDer Satz hat %d Woerter", auswertung.anzahlWoerter);
        printf("\nDer Satz hat %d Zeilen", auswertung.anzahlZeilen);
        printf("\nDer Satz hat %d Zeichen\n", auswertung.anzahlZeichen);
    } while (true);
	
    return 0;
}

void eingabe(const char* message, int maxCount, char satz[])
{
    printf("%s", message);
    fgets(satz, maxCount, stdin);
}

struct Auswertung zaehleWoerter(const char* text)
{
	struct Auswertung auswertung;

    int imWort = 0;  // Zustand: 0 = auﬂerhalb, 1 = innerhalb eines Wortes

    for (int i = 0; text[i] != '\0'; i++)
    {
		auswertung.anzahlZeichen++;

        if (text[i] == ' ' || text[i] == '\n' || text[i] == '!')
        {
            imWort = 0;

            if (text[i] == '\n')
            {
                auswertung.anzahlZeilen++;
			}
        }
        else if (!imWort)
        {
            imWort = 1;
            auswertung.anzahlWoerter++;
        }
    }

    return auswertung;
}