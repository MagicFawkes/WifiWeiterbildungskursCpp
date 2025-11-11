/*
Schreibe ein c++ Programm, das eine eigenee realloc Funktion in C++ implementiert.
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
};

int main()
{
	struct Roboter roboter;

	std::cout << roboter.name << '\n' << roboter.greifer.x << '\n' << roboter.greifer.y << '\n' << roboter.position.x << '\n' << roboter.position.y;

	return 0;
}

