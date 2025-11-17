/*
 Aufgabe 3 – Kopierkonstruktor und dynamische Speicherverwaltung

Erstelle eine Klasse Point mit folgenden öffentlichen Attributen:
int* x
int* y

Aufgaben:
Implementiere einen Parameterkonstruktor.
Implementiere einen Kopierkonstruktor, der eine Ausgabe mit cout macht („Copy constructor called“).
Die Parameter sollen dynamisch alloziert werden.

https://learn.microsoft.com/de-de/cpp/cpp/copy-constructors-and-copy-assignment-operators-cpp?view=msvc-170

*/


#include <iostream>

using namespace std;

class Point
{
public:
	int *x;
	int *y;

	Point(int x, int y) 
	{
		this->x = new int(x);
		this->y = new int(y);
	}

	Point(const Point& copy)            // Declare copy constructor.
	{
		this->x = new int(*copy.x);		// Es wird zwar referenz con Point übergeben aber Derefernezierung von x,y nciht vergessen
		this->y = new int(*copy.y);
	}

	Point& operator=(const Point& copy)		 // Declare copy assignment.
	{
		*this->x = *copy.x;			//auch hier dereferenzieren von x, copy ist eine Referenz, daher hier nicht dereferenzieren.
		*this->y = *copy.y;			//this-x und y muss auch dereferenziert werdne, da ich ja den Wert zuweisen will(vorausgesetzt objekt existiert schon).

		return *this;
	}

	~Point() 
	{
		if (x != nullptr)
			delete x;

		if (y != nullptr)
			delete y;
	}
};

int main()
{
	
	return 0;
}

