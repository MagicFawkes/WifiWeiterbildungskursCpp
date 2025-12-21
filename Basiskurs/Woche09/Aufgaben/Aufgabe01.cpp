/*
Aufgabe 1
Implementiere eine templatisierte Funktion, die eine Liste von Werten
1. filtert (mittels Lambda-Ausdruck)
2. transformiert (ebenfalls mittels Lambda-Ausdruck)
Tipp:
template<typename T, typename FilterFunc, typename TransformFunc>
std::vector<T> filter_and_transform(
const std::vector<T>& input,
FilterFunc filter,
TransformFunc transform
);
*/

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

/*
 * Diese Funktion verarbeitet einen Vektor in zwei Schritten:
 *
 * 1. Filtern:
 *    Mit std::copy_if werden nur die Elemente aus dem Eingabe-Vektor übernommen,
 *    für die die übergebene Filter-Funktion true zurückgibt.
 *    std::back_inserter sorgt dafür, dass die gefilterten Werte per push_back
 *    an den Ergebnis-Vektor angehängt werden.
 *
 *    Hinweis zu std::back_inserter:
 *    std::back_inserter erzeugt einen speziellen Ausgabe-Iterator, der bei jeder
 *    Zuweisung intern push_back(...) auf dem Ziel-Vektor aufruft.
 *    Algorithmen wie std::copy_if oder std::transform vergrößern Container
 *    nicht selbst, sondern schreiben nur an die Positionen, auf die der
 *    übergebene Ausgabe-Iterator zeigt.
 *    Ist der Ziel-Vektor leer und man übergibt z. B. vector.begin(), existieren
 *    keine gültigen Schreibpositionen – der Vektor bleibt leer bzw. das Verhalten
 *    ist undefiniert.
 *
 * 2. Transformieren:
 *    Mit std::transform wird jedes gefilterte Element mithilfe der
 *    Transform-Funktion verändert. Der Ergebnis-Vektor dient dabei gleichzeitig
 *    als Quelle und Ziel.
 *
 * Rückgabewert:
 *    Ein Vektor mit gefilterten und anschließend transformierten Werten.
 */

template<typename T, typename FilterFunc, typename TransformFunc>
std::vector<T> filter_and_transform(const std::vector<T>& input, FilterFunc filter, TransformFunc transform)
{
    std::vector<T> valuesFilteredAndTransformed;
	std::copy_if(input.begin(), input.end(), std::back_inserter(valuesFilteredAndTransformed), filter);
    std::transform(valuesFilteredAndTransformed.begin(), valuesFilteredAndTransformed.end(), valuesFilteredAndTransformed.begin(), transform);

    return valuesFilteredAndTransformed;
}

int main()
{
    std::vector<int> werteListe = {2,1,10,5,6,24,1,53};

    std::function<bool(int)> lambdaFilter = [](int value)->bool
        {
            return value > 5;
        };

    std::function<int(int)> lambdaTransform = [](int x) ->int
    {
	    return x * x;
    };

    std::vector<int> filteredValues = filter_and_transform(werteListe, lambdaFilter, lambdaTransform);

    for (int werte : filteredValues)
    {
        std::cout << werte << std::endl;
    }

    return 0;
}