#include <iostream>

using namespace std;

template<typename T>
class ComplexNumber
{
    friend ComplexNumber<T> operator+<>(const ComplexNumber<T> z1, const ComplexNumber<T> z2);

private:
    T real;
    T img;

public:
    ComplexNumber(T real, T img) : real(real), img(img)
    {
    }

    void print()
    {
        cout << real << endl;
        cout << img << endl;
    }
};

template<typename T>
ComplexNumber<T> operator+(const ComplexNumber<T> z1, const ComplexNumber<T> z2)
{
    return ComplexNumber<T>(z1.real + z2.real, z1.img + z2.img);
}

int main()
{
    ComplexNumber<float> z1(1, 2);
    ComplexNumber<float> z2(3, 2);
    ComplexNumber<float> z3 = z1 + z2;

    z3.print();
}
