/*

*/

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int Generic_Function(vector<int>& values, function<int(int, int)> func) 
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

    // Erste Variante, mit variable - der Rückgabetyp wird automatisch abgeleitet:
    auto lambda = [](int x, int y)      // oder statt auto --> std::function<int(int, int)>
    {
        return x * y;
    };

    // Zweite Variante, mit variable und Rückgabetyp explizit angeben
    auto lambda1 = [](int x, int y) -> int      // oder statt auto --> std::function<int(int, int)>
    {
        return x * y;
    };

    int wert = Generic_Function(a, lambda);
    cout << wert << endl;

    // Dritte Variante, direkt einfügen ohne Zwischenvariable
	wert = Generic_Function(a, [](int x, int y)     //Der Rückgabetyp wird automatisch abgeleitet:
    {
        return x * y;
    });

    // Vierte Variante, direkt einfügen ohne Zwischenvariable und Rückgabetyp explizit angeben
    wert = Generic_Function(a, [](int x, int y) -> int    
    {
        return x * y;
    });

    cout << wert << endl;
}

