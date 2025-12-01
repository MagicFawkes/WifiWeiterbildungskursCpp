/*
Postfix und präfix zu überladen
*/

#include <iostream>

using namespace std;

class TestClass
{
	//friend TestClass operator++(TestClass& obj, int);
	//Merksatz --> friend ist nur notwendig, wenn eine freie Funktion auf private / protected Member zugreifen muss.

public:
	int i = 10;
};

void operator++(TestClass& obj, int)		//kein const da das Objekt selbst verändert werden soll/darf
{
	obj.i = obj.i + 1;
}

void operator--(TestClass& obj, int)	//kein const da das Objekt selbst verändert werden soll/darf
{
	obj.i = obj.i - 1;
}

int main()
{
	TestClass t;
	t++;
	t++;
	t++;
	std::cout << t.i << std::endl;
	t--;
	t--;
	std::cout << t.i << std::endl;
}
