/*
Postfix und präfix zu überladen
*/

#include <iostream>

using namespace std;

class TestClass
{
	//friend TestClass operator++(TestClass& obj;
	//Merksatz --> friend ist nur notwendig, wenn eine freie Funktion auf private / protected Member zugreifen muss.

public:
	int i = 10;
};

//mit Postfix ist ein int notwendig bzw. muss angebeen werden void operator++(TestClass& obj, int)
void operator++(TestClass& obj, int)		//kein const da das Objekt selbst verändert werden soll/darf
{
	obj.i = obj.i + 1;
}

//mit Postfix ist ein int notwendig bzw. muss angebeen werden void operator++(TestClass& obj, int)
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
