#include <iostream>

using namespace std;

template<typename T>
class TemplateNumber;

template<typename T>
TemplateNumber<T> operator+(TemplateNumber<T>obj1, TemplateNumber<T>obj2);

template<typename T>
class TemplateNumber 
{
	friend TemplateNumber operator+ <T>(TemplateNumber<T>obj1, TemplateNumber<T>obj2);
private:
	T real;
	T img;
public:
	TemplateNumber(T real, T img) : real(real), img(img) 
	{

	}

	T getReal() const
	{
		return real;
	}

	T getImg() const
	{
		return img;
	}

};

template<typename T>
TemplateNumber<T> operator+(TemplateNumber<T>obj1, TemplateNumber<T>obj2)
{
	T real = obj1.getReal() + obj2.getReal();
	T img = obj1.getImg() + obj2.getImg();
	TemplateNumber<T> ob(real, img);
	return ob;
}

int main()
{
	TemplateNumber<float>z1(1, 2);
	TemplateNumber<float>z2(2, 3);
	TemplateNumber<float>z3 = z1 + z2;
}