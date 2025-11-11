/*
Schreibe ein Programm, in dem man eine Struktur für einen Roboter definiert.
Der Roboter hat folgende Datentypen: name, greifer (struct), position (struct).
Außerdem besitzt der Roboter folgende Fähigkeiten:
• Bewegung und Greifer setzen (öffnen oder schließen und Greifkraft).
*/

#include <iostream>

struct greifer
{
	int x = 10;
	int y = 20;
};

struct position
{
	int x = 30;
	int y = 40;
};

struct Roboter
{
	std::string name = "Test";
	struct greifer greifer;
	struct position position;

	void Bewegung(int x, int y)
	{
		position.x = x;
		position.y = y;
	}

	void GreiferSetzen(int x, int y)
	{
		greifer.x = x;
		greifer.y = y;
	}
};

int main()
{
	struct Roboter roboter;

	std::cout << "Wert:\n"<< roboter.name << '\n' << roboter.greifer.x << '\n' << roboter.greifer.y << '\n' << roboter.position.x << '\n' << roboter.position.y;
	roboter.Bewegung(50, 60);
	roboter.GreiferSetzen(70, 80);
	std::cout << "\n\nWert:\n" << roboter.name << '\n' << roboter.greifer.x << '\n' << roboter.greifer.y << '\n' << roboter.position.x << '\n' << roboter.position.y;

	return 0;
}

