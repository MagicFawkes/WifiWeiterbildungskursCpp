/*
Aufgabe 4
Schreiben Sie ihre eigene strcmp, strcp sowie atoi Funktionen. Behandeln Sie hier die Fälle, die
wir in der Vorlesung besprochen haben (Bufferoverflow etc.).
*/

#define _CRT_SECURE_NO_WARNINGS

#include <climits>
#include <stdio.h>

int strcmp(const char* str1, const char* str2);

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

int strcmp(const char* str1, const char* str2)
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
        return -1;
    }

    for (i = 0; i < str1LaengeStr1; i++)
    {
        if (str1[i] != str2[i])
            return -1;
    }

    return 0;
}

/*
	int strcmp_safe(const char* s1, const char* s2, size_t maxlen)
	{
	    if (s1 == NULL || s2 == NULL || maxlen == 0)
	        return INT_MIN; // Fehler 

	    size_t i = 0;

	    while (i < maxlen)
	    {
	        unsigned char c1 = (unsigned char)s1[i];
	        unsigned char c2 = (unsigned char)s2[i];

	        if (c1 != c2)
	            return (int)c1 - (int)c2; // negatives / positives Ergebnis wie std strcmp 

	        // wenn beide '\0' sind, sind die Strings gleich
	        if (c1 == '\0')
	            return 0;

	        i++;
	    }

	    // Wenn hier angekommen: wir haben maxlen erreicht, ohne Terminator zu sehen.
		//Das deutet auf potentiell nicht-terminierten String (kein '\0' innerhalb maxlen).
		// Das ist ein Sicherheitsereignis -> Fehler zurückgeben, statt falsches Ergebnis.
	    return INT_MIN;
	}
*/

