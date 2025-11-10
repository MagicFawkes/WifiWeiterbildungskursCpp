/*
Für Strings ist eine Funktion char* repeat(int i, char c) zu implementieren.
Das Ergebnis soll ein String sein, der aus der i-fachen Wiederholung
des Buchstabens c gebildet wird. Beispiel: repeat(5, 'A') ergibt den String "AAAAA".
*/

#include <iostream>

char* repeat(int i, char c);

int main()
{
	using namespace std;

	int anzahl;

	char character;

	cout << "Bitte Anzahl und char eingeben eingeben: ";
	cin >> anzahl >> character;

	char* ergebnis = repeat(anzahl, character);

	cout << "Beinhaltet Grossbuchstaben: " << ergebnis;

	free(ergebnis);

	return 0;
}

char* repeat(int i, char c)
{
	char* array = (char*)malloc(sizeof(char) * i + 1);

	for (int u = 0; u < i; u++)
	{
		array[u] = c;
	}

	array[i] = '\0';

	return array;
}