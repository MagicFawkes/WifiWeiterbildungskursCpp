/*
Schreibe ein CPP-Programm. Das Programm soll eingehende Nachrichten prüfen,
ob sie bestimmte verbotene Wörter enthalten. Zum Suchen verwendet sie
std::string::find. Wenn das Wort nicht gefunden wird, gibt find den speziellen
Wert std::string::npos zurück. Es soll am Anfang des Programms bestimmt werden,
wie viele Nachrichten gesendet werden und die zensierte Konversation ausgegeben.
Es soll die Anzahl der zensierten Wörter angegeben werden.
https://cplusplus.com/reference/string/string/find/
*/

#include <algorithm>
#include <iostream>
#include <string>

int main()
{
	using namespace std;

	string textnachricht;
	int zensiert = 0;

	cout << "Bitte Text eingeben:";
	getline(cin, textnachricht);

	std::string str2[] = { "scheisse", "doof", "dumm", "behindert" };

	int anzahl = std::size(str2);

	string buffer = textnachricht;
	std::transform(buffer.begin(), buffer.end(), buffer.begin(), ::tolower);

	for (int i = 0; i < anzahl; i++)
	{
		std::size_t found = buffer.find(str2[i]);

		if (found != string::npos)
		{
			zensiert++;

			int laenge = (int)str2[i].length();

			for (int u = 0; u < laenge - 1; u++)
			{
				textnachricht[u + found + 1] = '*';
			}
		}
	}

	cout << "Text: " << textnachricht;
	cout << "\nEs wurden " << zensiert << " Woerter zensiert!";

	return 0;
}
