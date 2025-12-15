/*
    Demonstration von Functors (Funktionsobjekten) in C++

    Functors sind Objekte, die sich wie Funktionen verhalten.
    Das erreichen sie, indem sie den Operator operator() überladen.

    Vorteile von Functors:
    - Kein Runtime-Overhead wie bei std::function (Compile-Time-Bindung)
    - Können Zustand besitzen (hier zwar nicht genutzt, aber möglich)
    - Sehr gut geeignet für STL-Algorithmen (transform, remove_if, sort)

    In diesem Beispiel:
    - SquareFunctor:
        Berechnet das Quadrat einer Zahl (x * x)
        Wird mit std::transform über die Funktion Apply() auf alle Elemente angewendet.

    - IsEven:
        Prüft, ob eine Zahl gerade ist
        Wird mit std::remove_if verwendet, um gerade Zahlen aus dem Vektor zu entfernen.

    - Descending:
        Vergleichs-Functor für std::sort
        Sortiert Zahlen in absteigender Reihenfolge.

    Die Template-Funktion Apply():
    - Akzeptiert einen beliebigen Functor (oder Lambda)
    - Wendet diesen mit std::transform auf jedes Element des Vektors an
    - Durch Templates entsteht kein zusätzlicher Overhead

    Ziel:
    - Zeigen, dass Functors eine saubere, performante Alternative zu Lambdas sind
    - Besonders nützlich bei komplexeren oder wiederverwendbaren Operationen
*/


#include <iostream>
#include <vector>
#include <algorithm>


void print(const std::vector<int>& v)
{
	std::cout << "------------------\n";
    for (int value : v) std::cout << value << "\n";
}

// ---------- Functors ----------
struct SquareFunctor {
    int operator()(int x) const { return x * x; }
};

struct IsEven {
    bool operator()(int x) const { return x % 2 == 0; }
};

struct Descending {
    bool operator()(int a, int b) const { return a > b; }
};

// Apply mit Template (besser als std::function, kein Overhead)
template <typename Op>
void Apply(std::vector<int>& v, Op op)
{
    transform(v.begin(), v.end(), v.begin(), op);
}

int main()
{
	std::vector<int> Values{ 1,2,3,4,5,6 };

    print(Values);

    // Functor statt Lambda: x*x
    Apply(Values, SquareFunctor{});
    print(Values);

    // Remove_if mit Functor statt Lambda: gerade Zahlen entfernen
    Values.erase(
        remove_if(Values.begin(), Values.end(), IsEven{}),
        Values.end()
    );
    print(Values);

    // Sort Descending mit Functor statt Lambda
    sort(Values.begin(), Values.end(), Descending{});
    print(Values);

    // Sort ascending (standard)
    sort(Values.begin(), Values.end());
    print(Values);
}
