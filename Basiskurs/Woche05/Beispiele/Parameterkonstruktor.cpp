/*
Aufgabe 2 – Default- und Parameterkonstruktor
Erstelle eine Klasse Car mit:
string brand
int year
Aufgaben:
Implementiere einen Default-Konstruktor (markiere im Code, wenn er aufgerufen wird).
Implementiere einen Parameterkonstruktor.
Gib im Konstruktor eine Ausgabe mit cout aus, damit sichtbar ist, welcher Konstruktor aufgerufen wurde.
*/

#include <iostream>

using namespace std;

class Car
{
	string brand;
	int year = 0;

public:	
	Car() 
	{
		cout << "Basiskonstruktor" << endl;
	}

	Car(string brand, int year) : brand(brand), year(year)
	{
		cout << "Parameterkonstruktor" << endl;
	}
};

int main()
{
	Car car1;
	Car car2("brand", 23);

	return 0;
}

