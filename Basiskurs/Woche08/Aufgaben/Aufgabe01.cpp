/*
Aufgabe 1
Schreibe eine Template-Funktion computeAverage<T>, die aus einer Datei Zahlen eines Typs T
(int, double, …) einliest und den Durchschnitt berechnet.
Anforderungen:
• Datei enthält eine Zahl pro Zeile.
• Wenn die Datei nicht existiert → wirf std::runtime_error.
• Wenn die Datei leer ist → wirf std::logic_error.
• Template unterstützt int, float, double

*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

template <typename T>
T computeAverage (T zahl)
{
	return 0;
}

int main()
{
	std::ifstream file("Zahlenwerte05.txt"); // lesen

	if (!file.is_open()) // file.fail()
	{
		throw std::runtime_error("File not found");
	}

	char c;

	if (!file.get(c))
	{
		throw std::logic_error("File empty");
	}

	file.clear();              // EOF-Flag löschen
	file.seekg(0, std::ios::beg);   // Dateizeiger auf Anfang setzen

	std::vector<int> zahlen;
	std::string word;

	while (file >> word)
	{
		std::cout << word << std::endl;

		try
		{
			// 2te Lösung: kann man auch als Rückgabewert von stoi auswerten
			size_t zeichen = 0;
			int value = std::stoi(word, &zeichen);

			if (zeichen != word.size())
				//throw istkeinezahl_exception(word);

			zahlen.push_back(value);
		}
		catch (std::exception& e)
		{
			std::cout << "Exception aufgetreten: " << e.what();
		}
		catch (...)
		{
			std::cout << "allgemeiner Fehler";
		}
	}

	file.close();

    return 0;
}