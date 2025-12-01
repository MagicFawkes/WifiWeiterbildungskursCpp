/*
Postfix und präfix zu überladen
*/

#include <iostream>
using namespace std;

class Complex
{
	friend Complex operator+(const Complex& obj1, const Complex& obj2);
	friend Complex operator-(const Complex& obj1, const Complex& obj2);
	friend Complex operator*(const Complex& obj1, const Complex& obj2);
	friend void printValues(const Complex complex);
	float re;
	float im;
	
public:
	Complex(float re = 0.0f, float im = 0.0f) : re(re), im(im)
	{
		
	}

	float berechneBetrag()
	{
		return sqrt(re * re + im * im);
	}
};

Complex operator+(const Complex& obj1, const Complex& obj2)
{
	return Complex(obj1.re + obj2.re, obj1.im + obj2.im);
}

Complex operator-(const Complex& obj1, const Complex& obj2)
{
	return Complex(obj1.re - obj2.re, obj1.im - obj2.im);
}

Complex operator*(const Complex& obj1, const Complex& obj2)
{
	return Complex(obj1.re * obj2.re, obj1.im * obj2.im);
}

void printValues(const Complex complex)
{
	std::cout << "Realteil: " << complex.re << ", Imaginaer: " << complex.im << std::endl;
}

int main()
{
	Complex complex1(10, 20);
	Complex complex2(30, 50);

	Complex complex3 = complex1 + complex2;
	printValues(complex3);

	complex3 = complex1 * complex2;
	printValues(complex3);

	complex3 = complex1 - complex2;
	printValues(complex3);

    return 0;
}



