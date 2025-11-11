/*
Erstelle folgende Datenstruktur und zwar eine, bei der jedes Element
auf das nächste zeigt. Man kann Elemente am Anfang und am Ende
hinzufügen sowie löschen. Jede Struktur beinhaltet einen Wert
und zeigt auf das nächste Element.
*/

#include <iostream>

void elementAmEndeHinzufügen(struct example* struktur);

struct example
{
	int wert;
	struct example *weiter = NULL;
	struct example *vorher = NULL;
};

int main()
{
	struct example* struktur = new example{ 50 };
	struktur->weiter = new example{10};
	struktur->weiter->vorher = struktur;

	struct example* aktuelleElement = struktur->weiter;
	std::cout << '\n' << aktuelleElement->wert;
	aktuelleElement = aktuelleElement->vorher;
	std::cout << '\n' << aktuelleElement->wert;


	return 0;
}

void elementAmEndeHinzufügen(struct example* struktur)
{
	
}
