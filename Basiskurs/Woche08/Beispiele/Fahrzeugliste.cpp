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
private:
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
private:
	int sitzplaetze;

public:

	PKW(std::string marke, int baujahr, int sitzplaetze)
		: Fahrzeug(marke, baujahr),   // Basisklasse
		sitzplaetze(sitzplaetze)    // eigenes Member
	{

	}

	void anzeigen() const override
	{
		cout << "Marke: " << this->getMarke() << '\n';
		cout << "Baujahr: " << this->getbaujahr() << '\n';
		cout << "Sitzplaetze: " << this->sitzplaetze << '\n';
	}
};

class LKW : public Fahrzeug
{
private:
	int ladegewicht;
public:
	LKW(std::string marke, int baujahr, int ladegewicht)
		: Fahrzeug(marke, baujahr),   // Basisklasse
		ladegewicht(ladegewicht)    // eigenes Member
	{

	}

	void anzeigen() const override
	{
		cout << "Marke: " << this->getMarke() << '\n';
		cout << "Baujahr: " << this->getbaujahr() << '\n';
		cout << "Ladegewicht: " << this->ladegewicht << '\n';
	}
};

template<typename T>
class Garage
{
public:
	std::vector<std::shared_ptr<T>> fahrzeuge;

	void hinzufuegen(std::shared_ptr<T> f)
	{
		if (f->getMarke() == "")
		{
			throw std::invalid_argument("tesdt");
		}
		this->fahrzeuge.push_back(f);
	}

	void alleAnzeigen() const
	{
		for (const std::shared_ptr<T>& fahrzeug : fahrzeuge)
		{
			cout << "Marke: " << fahrzeug->getMarke() << '\n';
		}
	}
};

int main()
{
	/*PKW pkw1("PKW1", 95, 2);
	PKW pkw2("PKW2", 98, 4);

	pkw1.anzeigen();
	pkw2.anzeigen();

	LKW lkw1("LKW1", 77, 10000);
	LKW lkw2("LKW2", 89, 11000);

	lkw1.anzeigen();
	lkw2.anzeigen();
*/

	shared_ptr<PKW> pkw3 = make_shared<PKW>("PKW1", 95, 2);
	shared_ptr<PKW> pkw4 = make_shared<PKW>("PKW2", 96, 3);
	shared_ptr<PKW> pkw5 = make_shared<PKW>("PKW3", 97, 4);
	
	shared_ptr<LKW> lkw3 = make_shared<LKW>("LKW3", 95, 2000);
	shared_ptr<LKW> lkw4 = make_shared<LKW>("LKW4", 96, 3000);
	shared_ptr<LKW> lkw5 = make_shared<LKW>("LKW5", 97, 4000);

	Garage<Fahrzeug> garage;

	/*garage.fahrzeuge.push_back(pkw3);
	garage.fahrzeuge.push_back(pkw4);
	garage.fahrzeuge.push_back(pkw5);

	garage.fahrzeuge.push_back(lkw3);
	garage.fahrzeuge.push_back(lkw4);
	garage.fahrzeuge.push_back(lkw5);*/

	garage.hinzufuegen(pkw3);

	//garage.alleAnzeigen();

	for (const std::shared_ptr<Fahrzeug>& fahrzeug : garage.fahrzeuge)
	{
		fahrzeug->anzeigen();
	}

    return 0;
}
