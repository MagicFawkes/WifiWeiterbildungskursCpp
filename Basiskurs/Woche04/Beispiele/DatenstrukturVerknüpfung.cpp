/*
Erstelle folgende Datenstruktur und zwar eine, bei der jedes Element
auf das nächste zeigt. Man kann Elemente am Anfang und am Ende
hinzufügen sowie löschen. Jede Struktur beinhaltet einen Wert
und zeigt auf das nächste Element.
*/

#include <iostream>

int wert = 0;

void elementAmEndeHinzufügen(struct example* struktur);
void elementAmAnfangHinzufügen(struct example* struktur);

struct example
{
	int wert;
	struct example *weiter = NULL;
	struct example *vorher = NULL;
};

int main()
{
	struct example* struktur = new example{ ++wert };

	elementAmEndeHinzufügen(struktur);
	elementAmEndeHinzufügen(struktur);
	elementAmEndeHinzufügen(struktur);
	elementAmEndeHinzufügen(struktur);
	elementAmEndeHinzufügen(struktur);

	elementAmAnfangHinzufügen(struktur);
	elementAmAnfangHinzufügen(struktur);
	elementAmAnfangHinzufügen(struktur);
	elementAmAnfangHinzufügen(struktur);

	struct example* aktuelleElement = struktur;

	while (aktuelleElement->vorher != NULL)
	{
		//std::cout << '\n' << aktuelleElement->wert;
		aktuelleElement = aktuelleElement->vorher;
	}

	std::cout << '\n' << aktuelleElement->wert;

	while (aktuelleElement->weiter != NULL)
	{
		aktuelleElement = aktuelleElement->weiter;
		delete(aktuelleElement->vorher);
		std::cout << '\n' << aktuelleElement->wert;
	}

	delete(aktuelleElement);

	return 0;
}

void elementAmEndeHinzufügen(struct example* struktur)
{
	while (struktur->weiter != NULL)
	{
		struktur = struktur->weiter;
	}

	struktur->weiter = new example{ ++wert };
	struktur->weiter->vorher = struktur;
}

void elementAmAnfangHinzufügen(struct example* struktur)
{
	while (struktur->vorher != NULL)
	{
		struktur = struktur->vorher;
	}

	struktur->vorher = new example{ ++wert };
	struktur->vorher->weiter = struktur;
}
