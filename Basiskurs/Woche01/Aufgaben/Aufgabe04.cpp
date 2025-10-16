/*
Schreiben Sie ein C Programm, das beliebig viele ganze Zahlen (integers) speichert. Das
Programm soll beendet werden, sobald der Benutzer die Zahl -1 eingibt, werden negative Zahlen
eingegeben, muss die Fehlermeldung kommen, dass nur positive Zahlen eingegeben werden
dürfen. Das Programm soll am Ende (nachdem -1 eingegeben wurde) die Summe, den
Durchschnitt, die größte sowie die kleinste Zahl ausgeben.
Das Programm soll folgendes besitzen:
• Eine Funktion zur Speicherung der Eingabe
• Eine Funktion zur Ermittlung von min und max
• Eine Funktion um den Durchschnitt zur Berechnung des Durchschnitt
Für die Berechnung des Durchschnittes denken sie an die Typumwanldung
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int eingabe(const char* message);
int ermittleMinWert(int liste[], int anzahl);;
int ermittleMaxWert(int liste[], int anzahl);
float ermittleDurchschnitt(int liste[], int anzahl);

int main()
{
	const int maxEingabe = 10;

    int werteListe[maxEingabe] = {0};
    int zaehler = 0;
    int eingabewert = 0;

    do
    {
        eingabewert = eingabe("Bitte positiven Wert eingeben (mit -1 Abbruch): ");

        if (eingabewert < -1 || eingabewert == 0)
			printf("Fehler, bitte positiven Wert eingeben\n");
        else if (eingabewert != -1)
        {
            zaehler++;
            werteListe[zaehler -1] = eingabewert;
        }

        if ((zaehler) >= maxEingabe)
        {
            printf("Info, maximale Anzahl an Eingaben erreicht\n");
            break;
        }

    } while (eingabewert != -1);

    printf("Der min Wert ist %d ", ermittleMinWert(werteListe, zaehler));
    printf("\nDer max Wert ist %d ", ermittleMaxWert(werteListe, zaehler));
    printf("\nDer Durchschnitt ist %.2f ", ermittleDurchschnitt(werteListe, zaehler));

    return 0;
}

int eingabe(const char* message)
{
    int wert;
    printf("%s", message);
    scanf("%d", &wert);

    return wert;
}

float ermittleDurchschnitt(int liste[], int anzahl)
{
    int summe = 0;

    for (int i = 0; i < anzahl; i++)
    {
        summe += liste[i];
    }

	return summe / (float)anzahl;
}

int ermittleMinWert(int liste[], int anzahl)
{
    int minWert = liste[0];

	for (int i = 0; i < anzahl; i++)
	{
		if (liste[i] < minWert)
			minWert = liste[i];
	}

    return minWert;
}

int ermittleMaxWert(int liste[], int anzahl)
{
    int maxWert = liste[0];

    for (int i = 0; i < anzahl; i++)
    {
        if (liste[i] > maxWert)
            maxWert = liste[i];
    }

    return maxWert;
}
