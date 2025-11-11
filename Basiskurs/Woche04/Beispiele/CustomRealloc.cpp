/*
Schreibe ein c++ Programm, das eine eigenee realloc Funktion in C++ implementiert.
*/

#include <iostream>

void* realloc(void* pointer, int groesse);

int main()
{
	int* p = new int(5);

	//p[8] = 39; //nicht erlaubt
	//std::cout << p[8]; //müll wert

	int* q = (int*)realloc(p, sizeof(int)*10);

	q[8] = 30;

	std::cout << '\n' << q[8];

	delete(q);

	return 0;
}

int* realloc(int* pointer, int groesse)
{
	delete(pointer);

	return new int(groesse);
}