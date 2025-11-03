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
        scanf("%20s", eingabe);

        printf("\nWort \"%s\" ist %s Palidrom!\n", eingabe, istPalidrom(eingabe) ? "ein" : "kein");
    } while (true);

    return 0;
}

bool istPalidrom (char palidrom[])
{
    int laenge = strlen(palidrom);

    for (int i = 0; i < laenge; i++)
    {
	    if (palidrom[i] != palidrom[laenge - i - 1])
	    {
            return false;
	    }
    }

    return true;
}