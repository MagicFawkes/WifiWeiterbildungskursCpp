/*

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

bool istPalidrom(char palidrom[]);

int main()
{
    char eingabe[20];
    
    do
    {
		printf("Bitte Wort eingeben: ");
		scanf("%19s", eingabe);     // \0 am Ende des Strings reservieren daher 19 statt 20

        printf("\nWort \"%s\" ist %s Palidrom!\n", eingabe, istPalidrom(eingabe) ? "ein" : "kein");
    } while (true);

    return 0;
}

bool istPalidrom (char palidrom[])
{
    int laenge = strlen(palidrom);

	for (int i = 0; i < laenge; i++) // laenge/2 wuerde auch gehen
    {
	    if (palidrom[i] != palidrom[laenge - i - 1])
	    {
            return false;
	    }
    }

    return true;
}