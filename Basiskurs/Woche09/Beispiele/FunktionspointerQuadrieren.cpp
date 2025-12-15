/*

*/


#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Mit Funktionspointer als Übergabe,  Funktionspouinter kann beides also auch function<int(int, int)> func) aus #include <functional> 
// geht auch: int Generic_Function(vector<int>& values, function<int(int, int)> ptr_func) 
int Generic_Function(vector<int>& values, int(*ptr_func)(int, int))     //bei Funktionspointern kannst du den Rückgabetyp NICHT weglassen. Er muss immer explizit angegeben werden.
{
    int sum = 1;

    for (int value : values)
    {
        sum = ptr_func(sum, value);
    }
    return sum;
}

void Generic_FunctionV2(vector<int>& values, void(*ptr_func)(int))
{
    std::for_each(values.begin(), values.end(), ptr_func);
};

int quadrieren(int x, int y)
{
    return x * y;
};

void quadrierenV2(int x)
{
    cout << x * x << std::endl;
};

//Mit Functor
struct Quadrieren 
{
    void operator()(int x)
	{
        x = x * x;
        cout << x << std::endl;
    }
};


//Mit Functor
struct QuadrierenClass
{
public:
    void operator()(int x)
    {
        x = x * x;
        cout << x << std::endl;
    }
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

    //Mit Funktionspointer:
    cout << "Mit Funktionspointer:" << std::endl;
    Generic_FunctionV2(a, quadrierenV2);

    //Direkt mit Funktion
    cout << "Mit Funktion:" << std::endl;
    for_each(a.begin(), a.end(), quadrierenV2);

    //Variante mit Lambda:
    cout << "Mit Lambda:" << std::endl;
    for_each(a.begin(), a.end(), [](int& x) {
        x *= x;
        cout << x << std::endl;
        });

    //Direkt mit Structor Strcut
    cout << "Mit StructorS Struct: " << std::endl;
    std::for_each(a.begin(), a.end(), Quadrieren());

    //Direkt mit Structor Class
    cout << "Mit Structor Class: " << std::endl;
    std::for_each(a.begin(), a.end(), QuadrierenClass());

    
}

