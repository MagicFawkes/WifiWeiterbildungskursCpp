/*
    Dieses Programm demonstriert den Einsatz moderner C++-Sprachmittel
    in Kombination mit STL-Algorithmen.

    Behandelte Konzepte:
    ------------------------------------------------
    1. std::vector als Container für Ganzzahlen
    2. Ausgabe von Container-Inhalten mit Range-for
    3. std::transform zur elementweisen Verarbeitung
    4. Vergleich:
       - Lambda-Ausdrücke
       - Klassische Funktionszeiger
    5. Entfernen von Elementen mit remove_if + erase (Erase-Remove-Idiom)
    6. Sortieren mit:
       - Lambda-Vergleichsfunktion (absteigend)
       - Standard-Sortierung (aufsteigend)

    Einsatz von Lambdas:
    ------------------------------------------------
    Lambdas werden verwendet, wenn:
    - keine separate Funktion nötig ist
    - die Logik kurz und lokal bleibt
    - eine Funktion "inline" an einen Algorithmus übergeben wird

    Vorteile von Lambdas:
    - Kein zusätzlicher Funktionsname nötig
    - Direkte Lesbarkeit
    - Können Variablen aus dem Kontext erfassen (hier nicht genutzt)

	std::transform wendet eine Funktion (oder einen Functor / Lambda) auf jedes Element eines Bereichs an
	und schreibt das Ergebnis in einen Zielbereich.
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

void print(std::vector<int> v) 
{
	std::cout << "------------------\n";
    for (auto value : v)
    {
	    std::cout << value << "\n";
    }
    //cout << "------------------\n";
}

//Lambda
void Apply(std::vector<int>& v, const std::function<int(int)>& op) 
{
    std::transform(v.begin(), v.end(), v.begin(), op); //Er nimmt Werte aus einem Bereich, wendet eine Funktion darauf an und schreibt das Ergebnis in einen Zielbereich
}

//Funktions Pointer
int Square(int x) 
{
    return x * x;
}

void ApplyWithPointer(std::vector<int>& v, int (*op)(int)) {
    std::transform(v.begin(), v.end(), v.begin(), op);
}

int main() 
{
	std::vector<int> Values{ 1,2,3,4,5,6 };

    print(Values);

    //Lambda
    Apply(Values, [](int x) {
        return x * x;
        });

    print(Values);

    //Funktion Pointer
    ApplyWithPointer(Values, &Square);

    print(Values);

    //Remove_if
    Values.erase(
        remove_if(
            Values.begin(),
            Values.end(),
            [](int x) {return x % 2 == 0; }
        ),
        Values.end()
    );

    print(Values);

    //Sort Descending
    std::sort(
        Values.begin(),
        Values.end(),
        [](int a, int b) {
            return a > b;
        }
    );
    print(Values);

    //Sort ascending
    std::sort(Values.begin(), Values.end());
    print(Values);
}