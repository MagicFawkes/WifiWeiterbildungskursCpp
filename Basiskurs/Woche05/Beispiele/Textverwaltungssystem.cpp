/*

*/

#include <iostream>

using namespace std;

enum TextKategorie
{
	ROMAN,
	SACHBUCH,
	BIOGRAFIE,
	KIDNERBUCH,
	SCIENCE_FICTION,
	FANTASY
};

class Text
{
private:
	std::string titel;
	std::string autor;
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
};

int main()
{
  

	return 0;
}
