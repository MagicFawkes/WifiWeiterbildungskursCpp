/*
•	Entwickeln Sie ein C++-Programm zur Verwaltung von Benutzerdaten.
•	Die Daten sollen aus einer Datei eingelesen, validiert und gespeichert werden.
•	Fehler müssen über Exceptions behandelt werden.
________________________________________
Datenformat
•	Jede Zeile in der Datei repräsentiert einen Benutzer.
•	Format:
o	name;age;email
•	Beispiel:
o	Alice;30;alice@example.com
________________________________________
Klasse User
•	Attribute:
std::string name
o	int age
o	std::string email
•	Konstruktor zum initialisieren dieser Werte.
________________________________________
Klasse UserDatabase
•	Verwaltet eine Liste von Benutzern (std::vector<User>).
•	Methoden:
o	load(const std::string& filename)
	Datei öffnen.
	Zeilen einlesen und zerlegen.
	Validierungen:
	Alter ist eine gültige Zahl.
	E-Mail enthält ein „@“.
	Benutzer in Vektor aufnehmen.
	Exceptions werfen bei:
	Datei kann nicht geöffnet werden.
	Ungültiges Zeilenformat.
	Fehlerhafte Daten.
o	save(const std::string& filename)
	Benutzer in Datei zurückschreiben.
	Exception bei Schreibfehlern.
o	addUser(const User&)
	Benutzer hinzufügen.
o	find(const std::string& name)
	Benutzer anhand des Namens suchen.
	Exception, falls nicht gefunden.
________________________________________
Exception-Klasse
•	Eigene Klasse FileException, abgeleitet von std::runtime_error.
•	Wird verwendet für:
o	Datei-Öffnungsfehler
o	Formatfehler
o	Ungültige Daten
o	Benutzer nicht gefunden
________________________________________
Programmablauf
•	Beim Start:
o	Versuch users.db zu laden.
o	Falls Exception:
	Fehlermeldung ausgeben.
	Leere Datenbank verwenden.
•	Menü:
o	[1] Benutzer hinzufügen
o	[2] Benutzer suchen
o	[3] Datenbank speichern
o	[0] Programm beenden
•	Jede Aktion soll Exceptions korrekt abfangen und ausgeben.
*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

std::vector<std::string> split(const std::string& s, const std::string& delimiter);

class file_not_found_exception : public std::runtime_error
{
public:
	file_not_found_exception(const string& msg) : runtime_error(msg)
	{

	}

	const char* what() const noexcept
	{
		return "File not found";
	}
};

class User
{
public:
	std::string name;
	int age;
	std::string email;
};

class Userbase
{
public:
	std::vector<User> users;

	void load(const std::string& filename)
	{
		ifstream file(filename); // lesen

		if (!file.is_open()) // file.fail()
		{
			cout << "Could not open the file" << endl;
			throw file_not_found_exception("test");
		}

		User user;
		string line;

		while (getline(file, line))
		{
			cout << line << std::endl;;

			try
			{
				std::vector<string> parsed = split(line, ";");
				user.name = parsed.at(0);
				user.age = stoi(parsed.at(1));
				user.email = parsed.at(2);
				this->users.push_back(user);
			}
			catch (exception& e)
			{
				cout << "Exception aufgetreten: " << e.what();
			}
			catch (...)
			{
				cout << "allgemeiner Fehler";
			}
		}

		file.close();
	}
};

int main()
{
	Userbase userbase;
	userbase.load("Benutzerdaten.txt");
    return 0;
}

std::vector<std::string> split(const std::string& s, const std::string& delimiter)
{
	std::vector<std::string> tokens;

	size_t start = 0;
	size_t pos;

	while ((pos = s.find(delimiter, start)) != std::string::npos) {
		tokens.emplace_back(s.substr(start, pos - start));
		start = pos + delimiter.length();
	}

	tokens.emplace_back(s.substr(start));

	return tokens;
}