/*
Aufgabe 1 – Einfache Klasse mit Konstruktor
Erstelle eine Klasse Student, die folgende privaten Attribute hat:
string name
int matrikelnummer
Aufgaben:
Schreibe einen Konstruktor, der beide Werte setzt.
Schreibe Getter für beide Attribute.
Teste die Klasse im main().

Narrowing bedeutet:
Konstruktor mit () aufrufen oder mit {}
Kurzfassung: Fast kein Unterschied im Ergebnis – nur unterschiedliche Schreibweise.
Ein größerer oder genau passender Datentyp wird in einen kleineren oder unpassenden Datentyp konvertiert, sodass Information verloren gehen kann.
C++ lässt solche Umwandlungen normalerweise zu – aber Uniform Initialization { } verhindert genau diese gefährlichen Fälle.
*/

#include <iostream>

using namespace std;

class Student
{
private:
	string name;
	int matrikelnummer;

public:
	Student(string name, int matrikelnummer) : name(name), matrikelnummer(matrikelnummer) {}

	string getName() const
	{
		return this->name;
	}

	int getMatrikelnummer() const
	{
		return this->matrikelnummer;
	}
};


int main()
{
	Student student{ "Thomas", 2356 };		// {} Verhindert Narrowing
	//Student student( "Thomas", 2356 );

	cout << "Name: " << student.getName() << std::endl;
	cout << "Matrikelnummer: " << student.getMatrikelnummer() << std::endl;

	return 0;
}

