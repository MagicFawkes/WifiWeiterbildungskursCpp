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
		this->x = new int(*copy.x);		//Derefernezierung nciht vergessen
		this->y = new int(*copy.y);
	}

	Point& operator=(const Point& copy)		 // Declare copy assignment.
	{
		*this->x = *copy.x;
		*this->y = *copy.y;

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

