/*
================================================================================
Programm: Min-, Max-, Medianwert und Sortierung mit Selection Sort
--------------------------------------------------------------------------------
Beschreibung:
Dieses Programm liest eine festgelegte Anzahl (hier 11) von Ganzzahlen
vom Benutzer ein und speichert sie in einem Array. Anschließend werden
folgende Aufgaben ausgeführt:

1. **Maximum und Minimum bestimmen**
   Die Funktionen `maxWertErmitteln()` und `minWertErmitteln()` durchlaufen
   das Array vollständig und vergleichen jedes Element, um den größten
   bzw. kleinsten Wert zu finden.

2. **Sortierung mit dem Selection-Sort-Algorithmus**
   Die Funktion `selection()` sortiert das Array aufsteigend.
   Dabei wird in jedem Durchlauf das kleinste noch unsortierte Element
   gesucht und an den Anfang des unsortierten Bereichs getauscht.
   Dadurch wird das Array schrittweise sortiert.

3. **Median berechnen**
   Nachdem das Array sortiert ist, wird der Median bestimmt:
   - Wenn die Anzahl der Elemente ungerade ist, wird das mittlere Element
     genommen.
   - Wenn sie gerade ist, wird der Mittelwert der beiden mittleren
     Elemente berechnet.

4. **Ausgabe**
   Das Programm gibt den größten, kleinsten und den Medianwert aus.
   Außerdem werden alle sortierten Werte in der richtigen Reihenfolge
   ausgegeben.

--------------------------------------------------------------------------------
Funktionsübersicht:
- `int eingabe(const char* message)`
  Liest einen ganzzahligen Wert von der Konsole ein und gibt ihn zurück.

- `int maxWertErmitteln(int wert[], int maxAnzahl)`
  Bestimmt den größten Wert im Array.

- `int minWertErmitteln(int wert[], int maxAnzahl)`
  Bestimmt den kleinsten Wert im Array.

- `void selection(int* array, int elemente)`
  Sortiert das Array mithilfe des Selection-Sort-Algorithmus.

--------------------------------------------------------------------------------
Technische Hinweise:
- `sizeof(eingabewerte) / sizeof(int)` wird verwendet, um die Anzahl der
  Arrayelemente zu bestimmen.
- Innerhalb der Funktionen wird die Länge des Arrays übergeben, da Arrays
  in Funktionen als Zeiger behandelt werden und `sizeof` dort nicht
  die ursprüngliche Länge liefert.
- `_CRT_SECURE_NO_WARNINGS` verhindert Warnungen bei der Verwendung von
  `scanf()` in Microsoft-Compilern.

--------------------------------------------------------------------------------
Beispielausgabe:
Bitte gib einen Wert ein: 3
Bitte gib einen Wert ein: 8
...
Maxwert ist 97
Minwert ist 3
Sortiertes Array: 3 8 14 25 37 42 54 68 73 81 97
Medianwert ist 42.0
================================================================================
*/


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int eingabe(const char* message);
int maxWertErmitteln(int wert[], int maxAnzahl);
int minWertErmitteln(int wert[], int maxAnzahl);
void selection(int* array, int elemente);

int main()
{
    int eingabewerte[15] = { 0 };

    int maxAnzahl = sizeof(eingabewerte) / sizeof(int);

    for (int i = 0; i < maxAnzahl; i++)
    {
        eingabewerte[i] = eingabe("Bitte gib einen Wert ein: ");
    }

    printf("Minwert ist %d\n", minWertErmitteln(eingabewerte, maxAnzahl));
    printf("Maxwert ist %d\n", maxWertErmitteln(eingabewerte, maxAnzahl));

    selection(eingabewerte, maxAnzahl - 1);

	for (int i = 0; i < maxAnzahl; i++)
    {
        printf("%d ", eingabewerte[i]);
    }
    
    printf("Medianwert ist %.1f\n", (maxAnzahl %2) == 0 ? ((eingabewerte[maxAnzahl / 2 - 1] + eingabewerte[maxAnzahl / 2]) / 2.0) : (eingabewerte[(maxAnzahl-1) /2]));

    return 0;
}

int minWertErmitteln(int wert[], int maxAnzahl)
{
    int min = wert[0];

    //int maxAnzahl = sizeof(wert) / sizeof(int); !! FUNKTIONIERT NICHT, da es ein Zeiger ist und kein echtes Array Lösung: Länge mitführen und übergeben:

    for (int i = 1; i < maxAnzahl; i++)
    {
        if (wert[i] < min)
        {
            min = wert[i];
        }
    }

    return min;
}

int maxWertErmitteln(int wert[],int maxAnzahl)
{
	int max = wert[0];

    //int maxAnzahl = sizeof(wert) / sizeof(int); !! FUNKTIONIERT NICHT, da es ein Zeiger ist und kein echtes Array Lösung: Länge mitführen und übergeben:

    for (int i = 1; i < maxAnzahl; i++)
    {
        if (wert[i] > max)
        {
            max = wert[i];
        }
    }

	return max;
}

int eingabe(const char* message)
{
    int wert;
    printf("%s", message);
    scanf("%d", &wert);

    return wert;
}


/* Sortieralgorithmus ist Selection Sort. Dieser Algorithmus sucht sich als Erstes das kleinste Element in der Liste,
 *merkt es sich und tauscht es gegen das Element am Anfang aus,
 *sodass sich dann das kleinste Element ganz am Anfang befindet.
 *Als Nächstes wird das zweitkleinste Element in der Liste gesucht
 *und wird gegen das an zweiter Stelle platzierte Element der Liste ausgetauscht usw.
 *https://openbook.rheinwerk-verlag.de/c_von_a_bis_z/022_c_algorithmen_003.htm
 */

void selection(int* array, int elemente)
{
    int index, index_klein,
        wert, wert_klein;

    /* Schleife wird von links nach rechts durchlaufen. */
    for (index = 0; index < elemente; index++) {
        /* aktuelle Position */
        wert = index;
        /* Schleife läuft durch bis ein kleineres Element als
         * die aktuelle Position gefunden wurde oder bis zum Ende,
         * was bedeutet, die aktuelle Position ist schon
         * das kleinste Element. */
        for (index_klein = index + 1; index_klein <= elemente;
            index_klein++) { /* Ein kleineres Element gefunden? */
            if (array[index_klein] < array[wert])
                /* Neues kleinstes Element */
                wert = index_klein;
        }
        /* kleinstes Element an die aktuelle
         * Position falls nötig */
        if (wert != index) {
            wert_klein = array[wert];
            array[wert] = array[index];
            array[index] = wert_klein;
        }
    }
}
