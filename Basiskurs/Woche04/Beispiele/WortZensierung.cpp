/*
Schreibe ein CPP-Programm. Das Programm soll eingehende Nachrichten prüfen,
ob sie bestimmte verbotene Wörter enthalten. Zum Suchen verwendet sie
std::string::find. Wenn das Wort nicht gefunden wird, gibt find den speziellen
Wert std::string::npos zurück. Es soll am Anfang des Programms bestimmt werden,
wie viele Nachrichten gesendet werden und die zensierte Konversation ausgegeben.
Es soll die Anzahl der zensierten Wörter angegeben werden.
*/

#include <iostream>


int main()
{
	using namespace std;

	string textnachricht;

	cout << "Bitte Text eingeben: ";
	cin >> textnachricht;

	return 0;
}