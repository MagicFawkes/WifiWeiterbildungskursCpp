/*

*/


#include <iostream>
#include <vector>

using namespace std;

// Mit Funktionspointer als Übergabe
int Generic_Function(vector<int>& values, int(*ptr_func)(int, int))
{
    int sum = 1;

    for (int value : values)
    {
        sum = ptr_func(sum, value);
    }
    return sum;
}

int quadrieren(int x, int y)
{
    return x * y;
};

int main()
{
    vector<int> a = { 1,2,3,4,5 };

    int wert = Generic_Function(a, quadrieren);

    cout << wert << endl;

    //Zweite Variante:
    int (*function)(int, int) = quadrieren;
    cout << Generic_Function(a, function) << endl;
}

