/*
Aufgabenstellung
1. Enumerationen

Erstellen Sie eine Enumeration TextKategorie mit folgenden Werten:

ROMAN
SACHBUCH
BIOGRAFIE
KINDERBUCH
SCIENCE_FICTION
FANTASY

2. Klasse "Text"

Implementieren Sie eine Klasse Text mit folgenden Eigenschaften:

Private Attribute:

std::string titel

std::string autor

TextKategorie kategorie

int seitenanzahl

Öffentliche Methoden:

Konstruktor mit Parametern für alle Attribute

Getter und Setter für alle Attribute

Eine Methode std::string getKategorieAlsString(), die die Enumeration als lesbaren String zurückgibt

3. Klasse "Buecherei"

Implementieren Sie eine Klasse Buecherei:

Private Attribute:

Text** textListe (ein Array von Zeigern auf Text-Objekte)

int anzahlTexte (aktuelle Anzahl der Texte)

int kapazitaet (maximale Kapazität des Arrays)

Öffentliche Methoden:

Konstruktor mit Parameter für die anfängliche Kapazität

Destruktor, der jeden Text-Zeiger und das Array selbst löscht

void textHinzufuegen(Text* neuerText) – fügt ein neues Text-Objekt hinzu

void textLoeschen(int index) – löscht einen Text anhand seines Index

Text* textFinden(const std::string& titel) – sucht einen Text anhand des Titels

4. Operatorüberladung

Überladen Sie folgende Operatoren:

<< für die Text-Klasse, um einen Text auf der Konsole auszugeben

== für die Text-Klasse, um zwei Texte zu überprüfen (zwei Texte sind gleich, wenn Titel und Autor identisch sind)

+ für die Buecherei-Klasse, um einen Text hinzuzufügen (Aufruf von textHinzufuegen)

5. Hauptprogramm

Schreiben Sie ein Hauptprogramm, das:

Eine Buecherei-Instanz mit einer Kapazität von 10 erstellt

Mindestens 5 verschiedene Text-Objekte auf dem Heap erzeugt und zur Bücherei hinzufügt

Nach einem bestimmten Text sucht und ihn ausgibt

Einen Text löscht

Die verbleibenden Texte ausgibt

Alle verbleibenden Texte einer bestimmten Kategorie ausgibt

Ordnungsgemäß den Speicher am Ende freigibt
*/

#include <iostream>

using namespace std;

enum TextKategorie
{
	ROMAN,
	SACHBUCH,
	BIOGRAFIE,
	KINDERBUCH,
	SCIENCE_FICTION,
	FANTASY
};

class Text
{
private:
	string titel;
	string autor;
	TextKategorie kategorie;
	int seitenanzahl;

public:
	Text(string titel, string autor, TextKategorie kategorie, int seitenanzahl)
	{
		this->titel = titel;
		this->autor = autor;
		this->kategorie = kategorie;
		this->seitenanzahl = seitenanzahl;
	}

	string getTitel() const
	{
		return this->titel;
	}

	void setTitel(string titel)
	{
		this->titel = titel;
	}

	string getAutor() const
	{
		return this->autor;
	}

	void setAutor(string titel)
	{
		this->autor = autor;
	}

	TextKategorie getKategorie() const
	{
		return this->kategorie;
	}

	void setKategorie(TextKategorie kategorie)
	{
		this->kategorie = kategorie;
	}

	int getSeitenanzahl() const
	{
		return this->seitenanzahl;
	}

	void setSeitenanzahl(int seitenanzahl)
	{
		this->seitenanzahl = seitenanzahl;
	}

	string getKategorieAlsString()
	{
		switch (kategorie)
		{
			case ROMAN:
				return "ROMAN";
			case SACHBUCH:
				return "SACHBUCH";
			case BIOGRAFIE:
				return "BIOGRAFIE";
			case KINDERBUCH:
				return "KINDERBUCH";
			case SCIENCE_FICTION:
				return "SCIENCE_FICTION";
			case FANTASY:
				return "FANTASY";
		}

		return "";
	}
};

class Buecherei
{
private:
	Text** ptrtext = NULL;
	int anzahlTexte = 0;
	int kapazitaet = 0;

public:
	Buecherei(int kapazitaet)
	{
		this->kapazitaet = kapazitaet;
		ptrtext = new Text * [kapazitaet];
	}

	~Buecherei()
	{
		for (int i = 0; i < kapazitaet; ++i)
		{
			delete(ptrtext[i]);
		}

		delete ptrtext;
	}

	void textHinzufuegen(Text* neuerText)
	{
		if (anzahlTexte < kapazitaet)
		{
			ptrtext[anzahlTexte++] = neuerText;
		}
		else
		{
			cout << "Kapazutaet ist nicht merh vorhanden!!";
		}
	}
};

int main()
{
  

	return 0;
}
