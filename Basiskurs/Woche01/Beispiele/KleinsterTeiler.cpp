
/*
Dieses Programm berechnet für jede ganze Zahl von 1 bis zu einem vom Benutzer eingegebenen Wert
den jeweils kleinsten Teiler größer als 1 und summiert diese Werte auf.

Ablauf:
1. Die Funktion 'eingabe()' fordert den Benutzer zur Eingabe eines Werts auf.
2. Die Funktion 'summeKleinstenTeilerBestimmen()' durchläuft alle Zahlen von 1 bis zur Eingabe
   und ruft für jede Zahl 'kleinstenTeilerBestimmen()' auf.
3. 'kleinstenTeilerBestimmen()' sucht den kleinsten Teiler einer Zahl, der größer als 1 ist.
4. Alle gefundenen kleinsten Teiler werden addiert und als Gesamtsumme ausgegeben.
5. Zusätzlich werden während der Berechnung die kleinsten Teiler jeder Zahl angezeigt.

Hinweis:
- '#define _CRT_SECURE_NO_WARNINGS' wird benötigt, um Compiler-Warnungen bei der Nutzung
  von scanf() in Visual Studio zu unterdrücken.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int kleinstenTeilerBestimmen(int wert);
int summeKleinstenTeilerBestimmen(int wert);
int eingabe(const char* message);

int main()
{
    int eingabewert;

	eingabewert = eingabe("Bitte gib einen Wert ein: ");

    printf("Der Summe ist %d\n", summeKleinstenTeilerBestimmen(eingabewert));

    return 0;
}

int kleinstenTeilerBestimmen(int wert)
{
    int kleinsterTeiler = 1;

    for (int i = 2; i <= wert; i++)
    {
	    if (wert % i == 0)
	    {
            kleinsterTeiler = i;
            break;
		}
    }

    return kleinsterTeiler;
}

int summeKleinstenTeilerBestimmen(int wert)
{
	int summe = 0;

    for (int i = 1; i <= wert; i++)
    {
        summe += kleinstenTeilerBestimmen(i);
        printf("Der kleinste Teiler von %d ist %d\n", i, kleinstenTeilerBestimmen(i));
    }

    return summe;
}

int eingabe(const char* message)
{
    int wert;
	printf("%s", message);
    scanf("%d", &wert);

	return wert;
}


