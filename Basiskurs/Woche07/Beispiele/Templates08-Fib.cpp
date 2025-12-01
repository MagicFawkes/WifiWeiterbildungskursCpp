#include <iostream>
using namespace std;

// ----------------------------------------------------------
// Allgemeine (primäre) Template-Definition der Fibonacci-Klasse
// ----------------------------------------------------------
// T = Datentyp (z.B. int, float)
// N = Fibonacci-Index
//
// Für N >= 2 wird diese Version verwendet.
// Sie berechnet den Wert rekursiv zur Compilezeit:
//   Fib(N) = Fib(N-1) + Fib(N-2)
// ----------------------------------------------------------
template<typename T, int N>
class Fibonacci
{
public:
    // rekursive Berechnung während der Kompilierung
    static constexpr T value =
        Fibonacci<T, N - 1>::value + Fibonacci<T, N - 2>::value;

    void print() {
        cout << value << endl;
    }
};


// ----------------------------------------------------------
// Spezialisierung für N = 0
// ----------------------------------------------------------
// Ohne diese Spezialisierung würde die Rekursion nie enden!
//
// Diese Spezialisierung überschreibt die generelle Version,
// sodass bei N = 0 **nicht mehr rekursiv gerechnet wird**,
// sondern direkt der Wert der Fibonacci-Zahl definiert ist.
// ----------------------------------------------------------
template<typename T>
class Fibonacci<T, 0> {
public:
    static constexpr T value = 0;
};


// ----------------------------------------------------------
// Spezialisierung für N = 1
// ----------------------------------------------------------
// Genau wie bei N = 0 stoppen wir die Rekursion,
// da Fib(1) ein bekannter Basiswert ist.
// ----------------------------------------------------------
template<typename T>
class Fibonacci<T, 1>
{
public:
    static constexpr T value = 1;
};


int main()
{
    // Berechnet Fibonacci(6) zur Compilezeit:
    // Fib(6) = 8
    Fibonacci<float, 6> a;
    a.print();
}
