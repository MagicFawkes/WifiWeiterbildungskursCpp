#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
private:
    float re;
    float im;

public:
    Complex(float re = 0.0f, float im = 0.0f) : re(re), im(im)
    {
    }

    float berechneBetrag() const
    {
        return sqrt(re * re + im * im);
    }

    // --- Operatoren innerhalb der Klasse überladen ---

    // Addition
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
    Complex complex1(10, 20);
    Complex complex2(30, 50);

    Complex complex3 = complex1 + complex2;
    complex3.printValues();

    complex3 = complex1 * complex2;
    complex3.printValues();

    complex3 = complex1 - complex2;
    complex3.printValues();

    return 0;
}
