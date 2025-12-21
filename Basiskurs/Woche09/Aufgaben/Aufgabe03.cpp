/*
Aufgabe 3
Aufgabe 2 aber mit Funktoren
----------------------------------------------
Aufgabe 2
Implementiere eine generische Datenanalyse-Funktion in C++, die eine Liste von Werten
1. filtert
2. transformiert(beispiel ist das quadrieren)
3. aggregiert(summiert)
Dabei müssen Templates, Lambda Expressions und STL-Algorithmen verwendet werden.
Explizite Schleifen sind nicht erlaubt.
Implementiere folgende Funktion:
template<
typename T,
typename Filter,
typename Transform,
typename Reduce
>
T analyze_data(
const std::vector<T>& data,
Filter filter,
Transform transform,
Reduce reduce,
T init
);
Anforderungen
1. Verwende keine Schleifen (for, while, do)
2. Verwende ausschließlich STL-Algorithmen
3. filter, transform und reduce müssen Lambda Expressions sein
4. Die Funktion muss voll generisch (templatisiert) sein
5. Gib das Ergebnis der Aggregation zurück6. Filtere alle Elemente, die die Filterbedingung erfüllen
7. Transformiere die gefilterten Elemente
8. Aggregiere (summiere) das Ergebnis zu einem einzelnen Wert
*/


#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

template<typename T>
struct LambdaFilterFunctor
{
    bool operator()(const T& a) const
    {
        return a > 5;
    }
};

template<typename T>
struct LambdaTransformFunctor
{
    T operator()(const T& x) const
    {
        return x * x;
    }
};

template<typename T>
struct LambdaReduceFunctor
{
    T operator()(const T& a, const T& b) const
    {
        return a + b;
    }
};

template<typename T, typename Filter, typename Transform, typename Reduce>
T analyze_data(const std::vector<T>& data, Filter filter, Transform transform, Reduce reduce, T init)
{
    std::vector<T> valuesFilteredAndTransformed;
    std::copy_if(data.begin(), data.end(), std::back_inserter(valuesFilteredAndTransformed), filter);
    std::transform(valuesFilteredAndTransformed.begin(), valuesFilteredAndTransformed.end(), valuesFilteredAndTransformed.begin(), transform);

    return std::accumulate(valuesFilteredAndTransformed.begin(), valuesFilteredAndTransformed.end(), init, reduce);
}

int main()
{
    std::vector<int> werteListe = { 2,1,10,5,6,24,1,53 };

    /*
    Funktionszeiger der Form bool(*)(int) können nur auf echte Funktionen zeigen
    (freie Funktionen oder static-Memberfunktionen).

    Funktoren (Objekte mit operator()) besitzen dagegen Zustand und sind keine
    Funktionen, daher können sie NICHT in einen Funktionszeiger umgewandelt werden.

    std::function ist ein Typeraser-Wrapper für "alles Aufrufbare" und kann
    Funktoren, Lambdas (mit oder ohne Captures) sowie Funktionszeiger speichern.
    Deshalb ist std::function hier die richtige Wahl.
	*/

    // Variante mit std::function-Wrapper für einen Funktor (indirekter Aufruf über operator()
    // Type-erased Callable: kapselt einen Funktor und erlaubt einen einheitlichen Aufruf

    /*
    Echter Funktionszeiger (z.B. bool(*)(int)):
    - enthält nur eine Adresse zu Maschinencode
    - kein Zustand, kein Besitz
    - direkter Aufruf über den Zeiger

    std::function:
    - ist ein Objekt, kein Zeiger
    - besitzt ein aufrufbares Objekt (Functor/Lambda/Funktion)
    - ermöglicht einen indirekten Aufruf über operator()
    - kann Zustand kapseln (z.B. Funktor oder Lambda mit Captures)
	*/

    std::function<bool(int)> LambdaFilterFunctorPointer = LambdaFilterFunctor<int>();
    std::function<int(int)> LambdaTransformFunctorPointer = LambdaTransformFunctor<int>();
    std::function<int(int,int)> LambdaReduceFunctorPointer = LambdaReduceFunctor<int>();
    
	int filteredValues = analyze_data(werteListe, LambdaFilterFunctorPointer, LambdaTransformFunctorPointer, LambdaReduceFunctorPointer, 0);

    // Zweite Variante (bevorzugt): Übergabe der Funktoren direkt an analyze_data (kein std::function, kein Funktionszeiger)
    //int filteredValues = analyze_data(werteListe, LambdaFilterFunctor<int>(), LambdaTransformFunctor<int>(), LambdaReduceFunctor<int>(), 0);

    std::cout << filteredValues << std::endl;

    return 0;
}