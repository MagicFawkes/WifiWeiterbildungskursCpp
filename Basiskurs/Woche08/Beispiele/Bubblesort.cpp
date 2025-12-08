
/*
Bubble Sort ist ein einfacher Sortieralgorithmus, bei dem benachbarte Elemente ständig miteinander verglichen werden.
Wenn zwei nebeneinanderliegende Zahlen in der falschen Reihenfolge sind, werden sie vertauscht.
Dieser Vorgang wird so oft wiederholt, bis keine Vertauschung mehr nötig ist – die größten Werte „wandern“ dabei schrittweise nach rechts wie Luftblasen nach oben.
Bubble Sort ist leicht zu verstehen, aber sehr langsam bei großen Datenmengen(Zeitkomplexität: O(n²)).
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> a = { 4, -2, 7, 0, 10, 1, -5, 6, 2, 5 };

    // -----------------------------
    // Beispiel: Suche nach einem Wert
    // -----------------------------
    int value = 7;
    int index = -1;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == value)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        cout << "Gefunden bei Index: " << index << endl;
    }

    // -----------------------------
    // Bubble Sort
    // -----------------------------
    int n = a.size();   // = 10
    int temp = 0;

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n - 1 - i; k++)  // -i ist Optimiert, weil das letzte Element ja immer das größte ist, somit braucht man nicht immer alles durchgehen
        {
            if (a[k] > a[k + 1])
            {
                temp = a[k + 1];
                a[k + 1] = a[k];
                a[k] = temp;
                //swap(a[k], a[k +1]);
            }
        }
    }

    // -----------------------------
    // Ausgabe nach dem Sortieren
    // -----------------------------
    cout << "\nSortiertes Array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
    return 0;
}
