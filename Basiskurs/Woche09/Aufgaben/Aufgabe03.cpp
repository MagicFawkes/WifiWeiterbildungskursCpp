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

    int filteredValues = analyze_data(werteListe, LambdaFilterFunctor<int>(), LambdaTransformFunctor<int>(), LambdaReduceFunctor<int>(), 0);

    std::cout << filteredValues << std::endl;

    return 0;
}