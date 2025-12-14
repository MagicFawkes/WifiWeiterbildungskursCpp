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
#include <sstream>

enum TYPE
{
	t_int,
	t_double,
	t_float
};

enum PLUGIN
{
	average,
	summe,
	sub
};

std::vector<std::string> split(const std::string& s, const std::string& delimiter);

template <typename T>
T berechneSumme(std::vector<T> zahlen)
{
	T summe = 0;

	for (size_t i = 0; i < zahlen.size(); ++i)
	{
		summe += zahlen[i];
	}

	return summe;
}

template <typename T>
T berechneAvg(std::vector<T> zahlen)
{
	T summe = 0;

	for (size_t i = 0; i < zahlen.size(); ++i)
	{
		summe += zahlen[i];
	}

	return (T)summe / (T)zahlen.size();
}

template <typename T>
T readFile(const std::string& path)
{
	std::ifstream file(path); // lesen

	if (!file.is_open()) // file.fail()
	{
		throw std::runtime_error("File not found");
	}

	std::string line;
	getline(file, line);

	TYPE type;
	PLUGIN plugin;

	std::vector<std::string> parsed = split(line, ";");

	if (parsed[0].find("double") != std::string::npos)
	{
		type = t_double;
	}
	else if (parsed[0].find("float") != std::string::npos)
	{
		type = t_float;
	}
	else
	{
		type = t_int;
	}

	if (parsed[1].find("avg") != std::string::npos)
	{
		plugin = average;
	}
	else if (parsed[1].find("sub") != std::string::npos)
	{
		plugin = sub;
	}
	else
	{
		plugin = summe;
	}

	std::cout << "Type: " << type << "\nPlugin: " << plugin << std::endl;

	std::vector<T> zahlen;
	std::string word;

	while (file >> word)
	{
		// std::stringstream behandelt den String wie einen Eingabestream (ähnlich std::cin):
		// Er liest Zeichen von links nach rechts, überspringt führende Leerzeichen,
		// konvertiert so viele Zeichen wie möglich in den Zieltyp und stoppt beim
		// ersten ungültigen Zeichen, ohne sofort einen Fehler auszulösen.
		std::stringstream ss(word);
		T value;
		if (ss >> value)              // nur speichern, wenn Parsing geklappt hat
			zahlen.push_back(value);
	}

	file.close();

	switch (plugin)
	{
	case average:
		return berechneAvg<T>(zahlen);
	case summe:
		return berechneSumme<T>(zahlen);
	case sub:
		break;
	}
}

int main()
{
	float wert = readFile<float>("Zahlenwerte06.txt");
	std::cout << "Summe: " << wert << std::endl;

	float average = readFile<float>("Zahlenwerte07.txt");
	std::cout << "Average: " << average << std::endl;

	return 0;
}

std::vector<std::string> split(const std::string& s, const std::string& delimiter)
{
	std::vector<std::string> tokens;

	size_t start = 0;
	size_t pos;

	while ((pos = s.find(delimiter, start)) != std::string::npos)
	{
		tokens.emplace_back(s.substr(start, pos - start));
		start = pos + delimiter.length();
	}

	tokens.emplace_back(s.substr(start));

	return tokens;
}