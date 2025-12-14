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
float computeAverage (const std::string& path)
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
			std::string buffer;
			T value;

			if (isdigit(word[0]))
				value = (T)std::stod(word, &zeichen);

			if (zeichen != word.size())
			{
				for (unsigned char ch : word)
				{
					if (std::isdigit(ch))
					{
						buffer += ch;
					}
					else
					{
						if (!buffer.empty())
						{
							zahlen.push_back((T)std::stod(buffer));
							buffer.clear();
						}
					}
				}
				if (!buffer.empty())
				{
					zahlen.push_back((T)std::stod(buffer));
					buffer.clear();
				}
			}
			else
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
	float berechneAverage = computeAverage<int>("Zahlenwerte05.txt");

	std::cout << "\nAverage: " << berechneAverage;
    return 0;
}