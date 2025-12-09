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

int main()
{
    

    return 0;
}
