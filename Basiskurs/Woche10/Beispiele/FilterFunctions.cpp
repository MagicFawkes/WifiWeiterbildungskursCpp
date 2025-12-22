/*

*/

#include <functional>
#include <iostream>
#include <vector>
#include "staticlib/include/FilterFunction.h"

int main()
{
    std::vector<int> werteListe = { 2,1,10,5,6,24,1,53 };

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


