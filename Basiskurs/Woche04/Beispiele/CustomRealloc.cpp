/*
Schreibe ein c++ Programm, das eine eigenee realloc Funktion in C++ implementiert.
*/

#include <iostream>

int* reallocNew(int* a, int old_size, int new_size);

int Eingabe()
{
	int n;
	std::cout << "Bestimme die Grosse vom Array: ";
	std::cin >> n;
	return n;
}
int main()
{
	int anzahl = Eingabe();
	int* a = new int[anzahl];

	a = reallocNew(a, anzahl,10);

	delete[](a);

	return 0;
}

int* reallocNew(int* a, int old_size, int new_size)
{
	if (a == nullptr)
	{
		return new int[new_size];
	}

	int* ptr = new int[new_size];

	if (new_size > old_size)
	{
		for (int i = 0; i < new_size; i++)
		{
			ptr[i] = 0;
		}

		for (int i = 0; i < old_size; i++)
		{
			ptr[i] = a[i];
		}
	}
	else
	{
		for (int i = 0; i < new_size; i++)
		{
			ptr[i] = a[i];
		}
	}

	delete[](a);

	return ptr;
}