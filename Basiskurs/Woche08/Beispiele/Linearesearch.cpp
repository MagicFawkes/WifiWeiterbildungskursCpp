/*
 *Lineare Suche (Linear Search) ist die einfachste Suchmethode. Dabei wird jedes Element einer Liste 
 *der Reihe nach von vorne bis hinten mit dem gesuchten Wert verglichen. Sobald der Wert gefunden wird, 
 *bricht die Suche ab und der Index wird zurückgegeben. Wird der Wert nicht gefunden, liefert die Funktion meist -1 zurück.
Die lineare Suche funktioniert auch bei unsortierten Daten, ist aber bei großen Datenmengen relativ langsam (Zeitkomplexität: O(n)).
 */

#include <iostream>
#include <vector>

using namespace std;

// -----------------------------
// Lineare Suche
// -----------------------------
int linearsearch(const vector<int>& a, int value)
{
    int i = 0;

    for (vector<int>::const_iterator it = a.begin(); it != a.end(); ++it)
    {
        if (value == *it)
        {
            return i;
        }
        i++;
    }

    return -1;
}

// -----------------------------
// Binäre Suche (Array MUSS sortiert sein!)
// -----------------------------
int binarysearch(const vector<int>& a, int value)
{
    int low = 0;
    int high = a.size() - 1;
    int mitte = 0;

    while (low <= high)
    {
        mitte = low + (high - low) / 2;

        if (a[mitte] == value)
        {
            return mitte;
        }
        else if (a[mitte] < value)
        {
            low = mitte + 1;
        }
        else
        {
            high = mitte - 1;
        }
    }

    return -1;
}

// -----------------------------
// Hauptprogramm
// -----------------------------
int main()
{
    vector<int> a = { -5, -2, 0, 1, 2, 4, 5, 6, 7, 10 };

    int value = 7;

    // Lineare Suche
    int indexLinear = linearsearch(a, value);

    if (indexLinear != -1)
        cout << "Linear Search: Wert gefunden bei Index " << indexLinear << endl;
    else
        cout << "Linear Search: Wert nicht gefunden" << endl;

    // Binäre Suche
    int indexBinary = binarysearch(a, value);

    if (indexBinary != -1)
        cout << "Binary Search: Wert gefunden bei Index " << indexBinary << endl;
    else
        cout << "Binary Search: Wert nicht gefunden" << endl;

    return 0;
}
