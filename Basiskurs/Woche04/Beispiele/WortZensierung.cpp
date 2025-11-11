/*
Schreibe ein CPP-Programm. Das Programm soll eingehende Nachrichten prüfen,
ob sie bestimmte verbotene Wörter enthalten. Zum Suchen verwendet sie
std::string::find. Wenn das Wort nicht gefunden wird, gibt find den speziellen
Wert std::string::npos zurück. Es soll am Anfang des Programms bestimmt werden,
wie viele Nachrichten gesendet werden und die zensierte Konversation ausgegeben.
Es soll die Anzahl der zensierten Wörter angegeben werden.
https://cplusplus.com/reference/string/string/find/
*/

#include <iostream>
#include <string>


int main()
{
	using namespace std;

	string textnachricht;

	cout << "Bitte Text eingeben:";
	getline(cin, textnachricht);

	std::string str2("scheisse");

	// different member versions of find in the same order as above:
	std::size_t found = textnachricht.find(str2);

	if (found != string::npos)
	{
		for (int i = 0; i < (int)str2.length() - 1; i++)
		{
			textnachricht[i + found+1] = '*';
		}
	}

	cout << "Text: " << textnachricht;

	return 0;
}
