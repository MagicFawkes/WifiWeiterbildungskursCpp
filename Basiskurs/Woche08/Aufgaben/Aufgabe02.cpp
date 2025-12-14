/*
Aufgabe 2
Entwickeln Sie ein C++-Programm, das anhand einer Datei automatisch das passende Daten-
Plugin auswählt, Daten einliest, verarbeitet und ein Ergebnis zurückgibt.
Das System muss vollständig template-basiert, generisch und exception-sicher sein.
Beispiel:
TYPE=int;PLUGIN=sum
TYPE=double;PLUGIN=avg
TYPE=float;PLUGIN=sub
Beispiel für die Textdatei:
TYPE=int
1
2
3
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class istkeinezahl_exception : public std::exception
{
private:
	std::string i;
public:
	istkeinezahl_exception(const std::string& i)
		: i("Eingabewert ist keine Zahl: " + i + "\n")
	{
	}

	const char* what() const noexcept override
	{
		return i.c_str();
	}
};

int main()
{
	std::ifstream file("Zahlenwerte06.txt"); // lesen

	if (!file.is_open()) // file.fail()
	{
		throw std::runtime_error("File not found");
	}

	std::string line;

	while (getline(file, line))
	{
		std::cout << line << std::endl;
	}

	file.close();

	return 0;
}