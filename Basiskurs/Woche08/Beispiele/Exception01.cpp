/*
Eigene Exeption erstellen mit Division durch NUll

Division durch 0 in C++
In C++ wirft eine Ganzzahl-Division durch 0 keine Exception.
Stattdessen entsteht Undefined Behavior – das Programm kann abstürzen, hängen oder falsche Werte liefern.
try/catch greift nur bei throw, nicht bei CPU-Fehlern.
Deshalb muss man selbst prüfen (if (u == 0)) und eine eigene Exception werfen.

const char* → Rückgabetyp
Das bedeutet:
Die Funktion gibt einen C-String zurück
Also einen Zeiger auf ein konstantes Zeichenarray
Du darfst den Text lesen, aber nicht verändern

const:
Bedeutet:
Die Funktion verändert das Exception-Objekt nicht
Sie darf keine Membervariablen ändern (außer mutable)
Das ist wichtig, weil Exceptions oft als const& gefangen werden:

noexcept → Garantie: wirft keine weitere Exception
Diese Funktion darf niemals selbst eine Exception werfen
Falls sie es doch tut → std::terminate() wird aufgerufen

Wenn eine Funktion als noexcept deklariert ist, darf sie niemals eine Exception nach außen lassen.
Passiert es trotzdem, ruft das Programm sofort std::terminate() auf.
Dabei wird das Programm ohne catch, ohne Aufräumen, sofort beendet.

Unterschied zwischen noexcept(true) und noexcept(false)
noexcept(true) (oder nur noexcept) bedeutet: Die Funktion wird garantiert keine Exception werfen.
→ Tut sie es doch, wird sofort std::terminate() aufgerufen.
noexcept(false) bedeutet: Die Funktion darf Exceptions werfen.
→ Das ist Standard, wenn noexcept gar nicht angegeben ist.

Mini-Merksatz
noexcept(true) = verboten zu werfen → sonst Programmabbruch
noexcept(false) = werfen erlaubt → normaler try/catch möglich ✅
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
