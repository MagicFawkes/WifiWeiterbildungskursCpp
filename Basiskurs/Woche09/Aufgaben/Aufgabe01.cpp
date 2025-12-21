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


#include <functional>
#include <iostream>
#include <vector>

template<typename T, typename FilterFunc, typename TransformFunc>
std::vector<T> filter_and_transform(const std::vector<T>& input, FilterFunc filter, TransformFunc transform)
{
    for (int x : v) {
        f(x);
    }

    return ;
}


int main()
{
    std::vector<int> werteListe = { 2,1,10,5, 6 };

    std::function<double(double, double)> lambdaFilter = [](double a, double b)->double
        {
            return a / b;
        };

    std::function<double(double, double)> lambdaTransform = [](double a, double b)->double
        {
            return a / b;
        };

    std::vector<int> filteredValues = filter_and_transform(werteListe, lambdaFilter, lambdaTransform);

    for (int werte : filteredValues)
    {
        std::cout << werte << std::endl;
    }

    return 0;
}