/*

*/

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int Generic_Function(vector<int> values, function<int(int, int)> func) 
{
    int sum = 1;

    for (int value : values) 
    {
        sum = func(sum, value);
    }
    return sum;
}

int main()
{
    vector<int> a = { 1,2,3,4,5 };

    int summ = 0;

    auto lambda = [](int x, int y)
    {
        return x * y;
    };

    int wert = Generic_Function(a, lambda);

    cout << wert << endl;
}

