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

class file_not_found_exception : public std::exception
{
public:
	const char* what() const noexcept
	{
		return "File not found";
	}
};

class istkeinezahl_exception : public std::exception
{
private:
	std::string i;
public:
	istkeinezahl_exception(const std::string& i)
		: i("Eingabewert ist keine Ganzzahl: " + i + "\n")
	{
	}

	const char* what() const noexcept override
	{
		return i.c_str();
	}
};

template <typename T>
void computeAverage (T zahl)
{

}

int main()
{
	std::ifstream file("Zahlenwerte05.txt"); // lesen

	if (!file.is_open()) // file.fail()
	{
		throw std::runtime_error("File not found");
	}

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
				throw istkeinezahl_exception(word);

			zahlen.push_back(value);
		}
		catch (istkeinezahl_exception& e)
		{
			std::cout << "Exception aufgetreten: " << e.what();
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