/*
Aufgabe 4
Schreiben Sie ihre eigene strcmp, strcp sowie atoi Funktionen. Behandeln Sie hier die Fälle, die
wir in der Vorlesung besprochen haben (Bufferoverflow etc.).
*/

#define _CRT_SECURE_NO_WARNINGS

#include <climits>
#include <stdio.h>

int strcmp(const char* str1, const char* str2);
int strcopy(const char* str1, char* str2);
int atoi(const char* str1, int* wert);

int main()
{
    char eingabe[100];
    char vergleich[] = {"Test"};
    printf("Bitte einen Begriff ein: ");
    scanf("%s", eingabe);
    printf("Der Vergleich von Eingabewort \"%s\" zum Vergleichswort \"%s\" ergab %s\n", 
    eingabe, vergleich, strcmp(eingabe, vergleich) == 0 ? "ident" : "nicht ident!");

    char copy[20];
    int erfolgreich = strcopy(eingabe, copy);
    printf("Der Vergleich von Eingabewort: \"%s\" zum kopierten Wort: \"%s\"\n", eingabe, copy);

    int integerWert = 0;
    atoi(eingabe, &integerWert);
    printf("Der Vergleich von Eingabewort: \"%s\" ergibt nach atoi: %d\n", eingabe, integerWert);


    return 0;
}

int atoi(const char* str1, int *wert)
{
    int i = 0;
    *wert = 0;

	while (str1[i] != '\0')
    {
        if (str1[i] >= '0' && str1[i] <= '9')
        {
            *wert *= 10;
            *wert += str1[i] - 48;
        }
        else
        {
            return -1;
        }

        i++;
    }

    return 0;
}

int strcopy(const char* str1, char* str2)
{
    int i = 0;

    while (str1[i] != '\0')
    {
        str2[i] = str1[i];
        i++;
    }
    str2[i] = '\0';

    return 1;
}

/*
int safe_strcpy(char *dest, size_t dest_size, const char *src) 
{
    if (!dest || !src) 
        return -1;

    if (dest_size == 0) 
        return -2;

    size_t i = 0;
    // Kopiere maximal dest_size - 1 Zeichen, damit Platz für '\0' bleibt 
	while (i + 1 < dest_size && src[i] != '\0') 
    {
	    dest[i] = src[i];
	    i++;
	}

	// Terminieren
	dest[i] = '\0';

	// Wenn src noch nicht am Ende, dann war dest zu klein 
	if (src[i] != '\0') 
        return -2; // abgeschnitten 

	return 0;
}
*/

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

/*
int safe_atoi(const char* s, int* out) {
    if (!s || !out) return -1;

    const char* p = s;
    while (isspace((unsigned char)*p)) p++; // führende Whitespaces überspringen 

    int sign = 1;
    if (*p == '+' || *p == '-') {
        if (*p == '-') sign = -1;
        p++;
    }

    if (!isdigit((unsigned char)*p)) return -1; // keine Ziffern => Fehler 

    long long acc = 0;
    while (isdigit((unsigned char)*p)) {
        int digit = *p - '0';

        // overflow check vor dem Multiplizieren/Addieren:
         //  acc > (INT_MAX - digit) / 10  -> overflow für positive Zahlen
         //  für negative Zahlen prüfen wir gegen -(long long)INT_MIN 
        if (sign == 1) {
            if (acc > ((long long)INT_MAX - digit) / 10) {
                return -2; // Overflow 
            }
        }
        else {
            // Zielbereich ist INT_MIN..INT_MAX, für negative Wert prüfen wir mit -acc*10 - digit >= INT_MIN 
            if (-acc < ((long long)INT_MIN + digit) / 10) {
                return -2; // Underflow
            }
        }

        acc = acc * 10 + digit;
        p++;
    }

    long long final = sign == 1 ? acc : -acc;
    if (final > INT_MAX || final < INT_MIN) return -2; // zusätzlich absichern 
    *out = (int)final;

    // optional: falls nach den Ziffern noch nicht-space/terminator folgt, könnte man das als Fehler sehen
    return 0;
}
*/

