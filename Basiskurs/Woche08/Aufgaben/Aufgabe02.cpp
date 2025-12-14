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

template <typename T>
float computeAverage(const std::string& path)
{
	std::ifstream file(path); // lesen

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

	std::vector<T> zahlen;
	std::string word;

	while (file >> word)
	{
		std::cout << word << std::endl;

		try
		{
			size_t zeichen = 0;
			T value = (T)std::stod(word, &zeichen);

			if (zeichen != word.size())
				throw istkeinezahl_exception(word);

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

	T summe = 0;

	for (size_t i = 0; i < zahlen.size(); ++i)
	{
		summe += zahlen[i];
	}

	file.close();

	return ((float)summe / (float)zahlen.size());
}


int main()
{
	float berechneAverage = computeAverage<int>("Zahlenwerte06.txt");

	std::cout << berechneAverage;
	return 0;
}