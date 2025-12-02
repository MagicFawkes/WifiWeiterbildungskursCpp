
/*
 *vector und Iterinterator
 *Iteratoren sind Zeiger-ähnliche Objekte, mit denen man Elemente einer Datenstruktur Schritt für Schritt durchlaufen kann (z. B. vector, list, map).
Man benutzt sie, um unabhängig vom internen Aufbau einer Struktur auf ihre Elemente zuzugreifen.
Iteratoren sind wie Zeiger auf Elemente einer Container-Klasse.
Sie ermöglichen Durchlaufen, Lesen, Schreiben und Suchen in Containern Listen, Vectoren usw..
Sie machen Code generisch, weil Funktionen mit Iteratoren für viele Containertypen funktionieren.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> vect;

    vect.push_back(10);
    vect.push_back(20);
    vect.push_back(30);
    vect.push_back(40);
    vect.push_back(50);

    vector<int>::iterator it = vect.begin();

    cout << *it << endl;   // Ausgabe: 10
    cout << *(++it) << endl;   // Ausgabe: 20

    cout << "Ausgabe: " << endl;

    for (auto it1 = vect.begin(); it != vect.end(); it++)
    {
        cout << *it << endl;
    }

    vector<int> v = { 80, 90, 100 };

    // Range based for Schleife
    for (int x : v) 
    {
        cout << x << endl;
    }

    return 0;
}