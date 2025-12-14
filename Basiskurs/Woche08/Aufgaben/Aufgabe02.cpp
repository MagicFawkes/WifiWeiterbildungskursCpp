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

	while (getline(file, line))
	{
		std::cout << line << std::endl;
	}

	file.close();

	return 0;
}


int main()
{
	int wert = readFile<int>("Zahlenwerte06.txt");

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