/*
 Für Strings ist eine Funktion:
 int containsUpperCaseChar(char* str)
 zu implementieren. Sie soll Wahr als Ergebnis liefern, wenn der übergebene String str einen Großbuchstaben enthält.
*/

#include <iostream>

int containsUpperCaseChar(const char* str);

int main()
{
	using namespace std;

	char text[50];

	cout << "Bitte String eingeben: ";
	cin >> text;

	cout << "Beinhaltet Grossbuchstaben: " << containsUpperCaseChar(text);

	return 0;
}

int containsUpperCaseChar(const char* str)
{
	for (int i = 0; i < (int)strlen(str); ++i)
	{
		if (isupper(str[i])) 
		{
			return 1;
		}
	}

	return 0;
}