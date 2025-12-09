/*
1. Basisklasse Fahrzeug
Attribute:
std::string marke
int baujahr
Methoden:
Reine virtuelle Methode: void anzeigen() const
Getter für marke und baujahr
Konstruktor und virtueller Destruktor
2. Abgeleitete Klassen
PKW
Zusätzliches Attribut: int sitzplaetze
Implementierung der Methode anzeigen(), die alle Informationen des PKWs ausgibt
LKW
Zusätzliches Attribut: double ladegewicht (in Tonnen)
Implementierung der Methode anzeigen(), die alle Informationen des LKWs ausgibt
3. Template-Klasse Garage<T>
Enthält eine std::vector<std::shared_ptr<T>> fahrzeuge
Methoden:
void hinzufuegen(std::shared_ptr<T> f)
Fügt ein Fahrzeug hinzu
Wirft eine Ausnahme (std::invalid_argument), wenn die Marke leer ist
void anzeigenAlle() const
Gibt alle Fahrzeuge aus
void entfernenVorBaujahr(int jahr)
Entfernt alle Fahrzeuge, deren Baujahr kleiner als jahr ist
4. Hauptprogramm (main)
Erstellen Sie mindestens zwei PKWs und einen LKW
Fügen Sie diese der Garage hinzu
Zeigen Sie alle Fahrzeuge an
Entfernen Sie Fahrzeuge vor einem bestimmten Baujahr
Zeigen Sie die aktualisierte Fahrzeugliste an
Behandeln Sie dabei alle Ausnahmen sinnvoll
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
