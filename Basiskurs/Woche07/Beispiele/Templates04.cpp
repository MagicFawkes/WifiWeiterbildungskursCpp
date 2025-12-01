#include <iostream>
#include <cmath>

using namespace std;

template<typename T, typename U>
class Complex
{
private:
    T re;
    U im;

public:
    Complex(T re, U im) : re(re), im(im)
    {
    }

    float berechneBetrag() const
    {
        return sqrt(re * re + im * im);
    }

    Complex operator+(const Complex& other) const
    {
        return Complex(this->re + other.re, this->im + other.im);
    }

    Complex operator-(const Complex& other) const
    {
        return Complex(this->re - other.re, this->im - other.im);
    }

    Complex operator*(const Complex& other) const
    {
        return Complex(this->re * other.re, this->im * other.im);
    }

    void printValues() const
    {
        cout << "Realteil: " << re
            << ", Imaginaer: " << im
            << endl;
    }
};

int main()
{
    Complex<float, float> complex1(10, 20);
    Complex<float, float> complex2(30, 50);

    Complex<float,float> complex3 = complex1 + complex2;
    complex3.printValues();

    complex3 = complex1 * complex2;
    complex3.printValues();

    complex3 = complex1 - complex2;
    complex3.printValues();

    return 0;
}
