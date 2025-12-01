/*
Postfix und präfix zu überladen
*/

#include <iostream>

using namespace std;

class TestClass
{
	friend void operator++(TestClass& obj, int); //mit Postfix
	friend void operator--(TestClass& obj, int); //mit Postfix
	friend void operator++(TestClass& obj); //mit Präfix
	friend void operator--(TestClass& obj); //mit Präfix
	friend void GebeWertAus(TestClass& t);
	//Merksatz --> friend ist nur notwendig, wenn eine freie Funktion (hier operator) auf private / protected Member zugreifen muss.

private:
	int i = 10;
};

//mit Postfix
void operator++(TestClass& obj, int)		//kein const da das Objekt selbst verändert werden soll/darf
{
	obj.i = obj.i + 1;
}

//mit Postfix
void operator--(TestClass& obj, int)		//kein const da das Objekt selbst verändert werden soll/darf
{
	obj.i = obj.i - 1;
}

//mit Präfix
void operator++(TestClass& obj)		//kein const da das Objekt selbst verändert werden soll/darf
{
	obj.i = obj.i + 1;
}

//mit Präfix
void operator--(TestClass& obj)		//kein const da das Objekt selbst verändert werden soll/darf
{
	obj.i = obj.i - 1;
}

void GebeWertAus(TestClass& t)
{
	std::cout << t.i << std::endl; //kann zugegriffen werden, da die FUnktion friendly ist und die erlaubnis hat
}

int main()
{
	TestClass t;
	t++;
	t++;
	t++;
	++t;
	++t;
	//std::cout << t.i << std::endl; //Private member kann nicht direkt zugegriffen werden
	GebeWertAus(t);
	t--;
	t--;
	--t;
	--t;
	//std::cout << t.i << std::endl; //Private member kann nicht direkt zugegriffen werden
	GebeWertAus(t);
}
