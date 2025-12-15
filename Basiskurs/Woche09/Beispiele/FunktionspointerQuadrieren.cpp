/*

*/


#include <iostream>
#include <vector>

using namespace std;

// Mit Funktionspointer als Übergabe
int Generic_Function(vector<int>& values, int(*ptr_func)(int, int))     //bei Funktionspointern kannst du den Rückgabetyp NICHT weglassen. Er muss immer explizit angegeben werden.
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

    //Erste Variante - Funktion direkt übergeben
    int wert = Generic_Function(a, quadrieren);
    cout << wert << endl;

    //Zweite Variante mit Funktionspointer übergeben:
    int (*function)(int, int) = quadrieren;             //bei Funktionspointern kannst du den Rückgabetyp NICHT weglassen. Er muss immer explizit angegeben werden
    //int (*function)(int, int) = &quadrieren;      //gleichwertig
    cout << Generic_Function(a, function) << endl;
}

