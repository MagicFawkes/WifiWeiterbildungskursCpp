/*
-----------------------------------------------------------------------------------------
Beschreibung:
Dieses Programm ermittelt alle Primzahlen von 0 bis zu einer vom Benutzer eingegebenen Zahl
und speichert sie in einem Array. Anschlie�end werden alle gefundenen Primzahlen in der
Konsole ausgegeben.

Ablauf des Programms:
1. Der Benutzer wird aufgefordert, eine ganze Zahl (Grenzwert) einzugeben.
2. Das Programm �berpr�ft alle Zahlen von 0 bis zu diesem Grenzwert:
   - F�r jede Zahl wird gepr�ft, ob sie eine Primzahl ist.
   - Falls ja, wird sie in einem Array gespeichert und ausgegeben.
3. Nach der �berpr�fung werden alle gespeicherten Primzahlen nochmals in einer Liste
   ausgegeben.

Funktionen:
- int eingabe(const char* message):
  Fordert den Benutzer zur Eingabe einer Zahl auf und gibt den eingegebenen Wert zur�ck.

- void primZahlenSpeichern(int wert, int primzahlen[]):
  Durchl�uft alle Zahlen von 0 bis "wert" und pr�ft mit der Funktion istPrimZahl(),
  ob es sich um eine Primzahl handelt. Gefundene Primzahlen werden im Array gespeichert.

- bool istPrimZahl(int zahl):
  Pr�ft, ob eine �bergebene Zahl eine Primzahl ist, indem sie durch alle kleineren Zahlen
  (ab 2) geteilt wird. Liefert true zur�ck, wenn die Zahl nur durch 1 und sich selbst teilbar ist.

Globale Variable:
- int zaehler:
  H�lt die Anzahl der gefundenen Primzahlen fest, um den Index im Array zu steuern.

Hinweis:
- Das Array f�r Primzahlen (primzahlenMax) ist auf 100 Elemente begrenzt.
  Wird ein gr��erer Grenzwert eingegeben, kann das Array �berlaufen.
- Die Pr�fung auf Primzahlen ist nicht optimiert (keine Wurzelpr�fung).
-----------------------------------------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int eingabe(const char* message);
void primZahlenSpeichern(int wert, int primzahlen[]);
bool istPrimZahl(int zahl);

int zaehler = 0;

int main()
{
    int primzahlenMax[100];
    int eingabewert;

    eingabewert = eingabe("Bitte gib einen Wert ein: ");

    primZahlenSpeichern(eingabewert, primzahlenMax);

    for (int i = 0; i < zaehler; i++)
    {
        printf("Primzahl Liste: %d \n", primzahlenMax[i]);
    }

    return 0;
}

void primZahlenSpeichern(int wert, int primzahlen[])
{
	for (int i=0; i<=wert; i++)
	{
		if (istPrimZahl(i))
		{
            zaehler++;
            printf("Der Zahl %d ist eine Primzahl\n", i);
			primzahlen[zaehler - 1] = i;
		}
        else
            printf("Der Zahl %d ist keine Primzahl\n", i);
	}
}

bool istPrimZahl(int zahl)
{
    if (zahl < 2)
        return false; 

    for (int i = 2; i < zahl; i++)  
    {
        if (zahl % i == 0)               
            return false;
    }

    return true;
}

int eingabe(const char* message)
{
    int wert;
    printf("%s", message);
    scanf("%d", &wert);

    return wert;
}
