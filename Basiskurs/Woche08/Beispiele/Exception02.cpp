/*
Eigene Exeption erstellen mit Division durch NUll

Division durch 0 in C++
In C++ wirft eine Ganzzahl-Division durch 0 keine Exception.
Stattdessen entsteht Undefined Behavior – das Programm kann abstürzen, hängen oder falsche Werte liefern.
try/catch greift nur bei throw, nicht bei CPU-Fehlern.
Deshalb muss man selbst prüfen (if (u == 0)) und eine eigene Exception werfen.
*/

#include <iostream>

using namespace std;

class custom_exception : public exception
{
public:
	const char* what() const noexcept
	{
		return "Division durch 0";
	}	
};

int main()
{
	int i = 2;
	int u = 0;

	try
	{
		if (u ==0)
		{
			throw custom_exception();
		}

		int ergebnis = i / u;
	}
	catch (custom_exception& e)	//fängt alles ab sowohl eigene Fehlerexception oder auch throw 23;
	{
		cout << "Exception aufgetreten: " << e.what();
	}
	catch (...)	//fängt alles ab sowohl eigene Fehlerexception oder auch throw 23;
	{
		cout << "allgemeiner Exception";
	}
}
