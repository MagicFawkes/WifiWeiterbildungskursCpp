#include <iostream>

template<int N>
class Fibonacci
{
public:
    static constexpr float value =
        Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;

    void print() const
    {
        std::cout << value << std::endl;
    }
};

// Spezialisierung für 0
template<>
class Fibonacci<0>
{
public:
    static constexpr float value = 1.0f;
};

// Spezialisierung für 1
template<>
class Fibonacci<1>
{
public:
    static constexpr float value = 1.0f;
};

int main()
{
    Fibonacci<10> a;
    a.print();   // gibt 89 aus (mit Startwerten 1,1)
    return 0;
}
