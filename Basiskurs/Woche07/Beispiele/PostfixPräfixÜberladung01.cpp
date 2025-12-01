/*
Postfix und präfix zu überladen
*/

#include <iostream>

using namespace std;

class TestClass
{
	//friend TestClass operator++(TestClass& obj, int);
	//friend TestClass operator--(TestClass & obj, int);
	//Merksatz --> friend ist nur notwendig, wenn eine freie Funktion auf private / protected Member zugreifen muss.

public:
	int i = 0;
};

TestClass operator++(TestClass& obj, int)		//kein const da das Objekt selbst verändert werden soll/darf
{
	//Ja — du kannst obj.i++ problemlos verwenden, auch wenn du gerade operator++ überlädst.
	//Deine Überladung betrifft nur TestClass, nicht den int - Typ.
	//obj.i++; //sollte auch gehen
	obj.i = obj.i + 1;
	return TestClass(obj);
}

TestClass operator--(TestClass& obj, int)
{
	//Ja — du kannst obj.i++ problemlos verwenden, auch wenn du gerade operator++ überlädst.
	//Deine Überladung betrifft nur TestClass, nicht den int - Typ.
	//obj.i--; //sollte auch gehen
	obj.i = obj.i - 1;
	return TestClass(obj);
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
