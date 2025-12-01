#include <iostream>

template<int N>
class Fibonacci
{
public:
    static float value;

    void print()
    {
        std::cout << value << std::endl;
    }
};

// Definition der statischen Member
template<int N>
float Fibonacci<N>::value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;

// Spezialisierung für 0
template<>
class Fibonacci<0>
{
public:
    static float value;
};

float Fibonacci<0>::value = 1.0f;

// Spezialisierung für 1
template<>
class Fibonacci<1>
{
public:
    static float value;
};

float Fibonacci<1>::value = 1.0f;


int main()
{
    Fibonacci<10> a;
    a.print();   // Gibt 2 aus
    return 0;
}
