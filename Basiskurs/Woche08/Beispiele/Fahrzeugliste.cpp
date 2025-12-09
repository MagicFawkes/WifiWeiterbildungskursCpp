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

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Fahrzeug
{
protected:
	std::string marke;
	int baujahr;
public:

	Fahrzeug(std::string marke, int baujahr)
	{
		this->marke = marke;
		this->baujahr = baujahr;
	}

	virtual ~Fahrzeug()
	{
		
	}

	virtual void anzeigen() const = 0;

	std::string getMarke() const
	{
		return this->marke;
	}

	int getbaujahr() const
	{
		return this->baujahr;
	}
};

class PKW : public Fahrzeug
{
	int sitzplaetze;

public:

	PKW(std::string marke, int baujahr, int sitzplaetze)
		: Fahrzeug(marke, baujahr),   // Basisklasse
		sitzplaetze(sitzplaetze)    // eigenes Member
	{

	}

	void anzeigen() const override
	{
		cout << "Marke: " << this->marke << '\n';
		cout << "Baujahr: " << this->baujahr << '\n';
		cout << "Sitzplaetze: " << this->sitzplaetze << '\n';
	}
};

class LKW : public Fahrzeug
{
	int ladegewicht;
public:
	LKW(std::string marke, int baujahr, int ladegewicht)
		: Fahrzeug(marke, baujahr),   // Basisklasse
		ladegewicht(ladegewicht)    // eigenes Member
	{

	}

	void anzeigen() const override
	{
		cout << "Marke: " << this->marke << '\n';
		cout << "Baujahr: " << this->baujahr << '\n';
		cout << "Sitzplaetze: " << this->ladegewicht << '\n';
	}
};

template<typename T>
class Garage
{
public:
	std::vector<std::shared_ptr<T>> fahrzeuge;

	void hinzufuegen(std::shared_ptr<T> f)
	{
		this->fahrzeuge.push_back(f);
		throw std::invalid_argument("tesdt");
	}

	void alleAnzeigen() const
	{
		for (T fahrzeug : this->fahrzeuge)
		{
			cout << "Marke: " << fahrzeug->marke << '\n';
		}
	}
};

int main()
{
	PKW pkw("Test", 95, 2);
	PKW pkw1("Test1", 98, 4);

	pkw.anzeigen();
	pkw1.anzeigen();

    return 0;
}
