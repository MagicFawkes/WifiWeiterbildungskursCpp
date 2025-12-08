/*
================================================================================
ERKLÄRUNG DES QUICKSORT-ALGORITHMUS (MIT DIESEM CODE)

Dieser Code implementiert den Sortieralgorithmus "QuickSort".
QuickSort ist ein sehr schneller, rekursiver Sortieralgorithmus mit einer
durchschnittlichen Laufzeit von O(n log n).

--------------------------------------------------------------------------------
GRUNDIDEE VON QUICKSORT

1. Es wird ein sogenanntes Pivot-Element gewählt.
   → In diesem Code ist das immer das letzte Element des aktuellen Bereichs.

2. Das Array wird so aufgeteilt (partitioniert), dass:
   - Alle Werte kleiner als das Pivot links davon stehen
   - Alle Werte größer oder gleich rechts davon stehen

3. Danach wird Quicksort rekursiv auf beide Teilbereiche angewendet:
   - den linken Bereich
   - den rechten Bereich

Dieser Vorgang wiederholt sich, bis alle Teilbereiche nur noch aus einem
Element bestehen → dann ist das gesamte Array sortiert.

--------------------------------------------------------------------------------
ABLAUF IM DETAIL (BEISPIEL MIT: {1, 2, 5, 4, 9, 8})

Start:
quicksort(a, 0, 5)

1) partition(a, 0, 5)
   Pivot = 8
   → Alle Zahlen kleiner als 8 werden nach links geschoben:
   Ergebnis nach dieser Phase:
   {1, 2, 5, 4, 8, 9}
   Pivot landet an seiner endgültigen Position (Index 4)

2) Rekursion:
   - quicksort(a, 0, 3)   // linker Teil
   - quicksort(a, 5, 5)   // rechter Teil → endet sofort

3) Der gleiche Vorgang läuft weiter für:
   - {1, 2, 5, 4}
   - dann für kleinere Teilstücke
   → bis alles sortiert ist

--------------------------------------------------------------------------------
ERKLÄRUNG DER WICHTIGEN VARIABLEN

partition():
- pivot      → Das Vergleichselement (letztes Element)
- counter    → Position für das nächste kleinere Element
- j          → Durchläuft den aktuellen Bereich

Wenn a[j] < pivot:
→ counter wird erhöht
→ Werte werden getauscht
→ kleinere Werte sammeln sich links

Am Ende:
→ Pivot wird an Position (counter + 1) getauscht
→ Diese Position ist die endgültige, korrekte Position des Pivot

--------------------------------------------------------------------------------
WICHTIGE ANMERKUNG ZUM CODE (FEHLER!)

In deiner aktuellen partition-Funktion steht:

for (int j = 0; j < n; j++)

Das ist LOGISCH FALSCH, denn:
→ Du ignorierst den "start"-Index
→ Beim Rekursionsaufruf werden dadurch falsche Bereiche durchlaufen

KORREKT wäre:

for (int j = start; j < n; j++)

Ohne diese Korrektur kann der Algorithmus falsche Ergebnisse liefern!

--------------------------------------------------------------------------------
WARUM QUICKSORT SCHNELL IST

- Teilt das Problem in kleinere Teile (Divide & Conquer)
- Arbeitet direkt im Array (kein zusätzlicher Speicher nötig)
- Sehr effizient für große Datenmengen

--------------------------------------------------------------------------------
ZUSAMMENFASSUNG

- quicksort() steuert die Rekursion
- partition() sorgt für die richtige Aufteilung
- Das Pivot landet bei jedem Durchlauf an seiner endgültigen Position
- Danach werden nur noch kleinere Teilbereiche sortiert
- Dadurch entsteht das vollständig sortierte Array

================================================================================
*/

#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& a, int start, int n) {
	int pivot = a[n];
	int counter = start - 1;

	for (int j = 0; j < n; j++)
	{
		if (a[j] < pivot) {
			counter++;
			swap(a[counter], a[j]);
		}
	}

	swap(a[counter + 1], a[n]);

	return counter + 1;
}


void quicksort(vector<int>& a, int start, int n)
{
	if (start < n)
	{
		int pivot = partition(a, start, n);
		quicksort(a, start, pivot - 1);
		quicksort(a, pivot + 1, n);
	}
}


int main()
{
	vector<int> a = { 1,2,5,4,9,8 };
	quicksort(a, 0, a.size() - 1);

	for (int x : a)
	{
		cout << x << endl;
	}
};