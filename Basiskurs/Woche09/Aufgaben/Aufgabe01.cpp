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

    std::function<bool(int a)> lambdaFilter = [](int value)->bool
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