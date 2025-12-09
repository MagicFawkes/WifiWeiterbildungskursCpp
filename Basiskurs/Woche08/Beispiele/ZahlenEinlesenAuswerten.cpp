/*
Schreibe ein C++-Programm, das die Datei zahlen.txt einliest.
In der Datei steht pro Zeile eine Zahl (Ganzzahl).
Einige Zeilen können ungültig sein (z. B. Text oder Dezimalzahlen).
Das Programm soll:
Die Datei öffnen
Falls die Datei nicht existiert oder nicht geöffnet werden kann → Exception werfen.
Jede Zeile einzeln lesen
Versuchen, die Zeile in eine int-Zahl umzuwandeln.
Wenn die Umwandlung fehlschlägt → Exception behandeln, Fehlermeldung ausgeben, aber weitermachen.
Alle gültigen Zahlen sammeln
Folgendes berechnen:
Summe
Durchschnitt
Minimum und Maximum
Ergebnis in Datei auswertung.txt speichern
*/
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class file_not_found_exception : public exception
{
public:
    const char* what() const noexcept
    {
        return "File not found";
    }
};

class istkeinezahl_exception : public exception
{
private:
	string i;
public:
	istkeinezahl_exception(const std::string& i)
		: i("Eingabewert ist keine Ganzzahl: " + i + "\n")
	{
	}

	const char* what() const noexcept override
	{
		return i.c_str();
	}
};

bool istZahl(const string& s);

int main()
{
    ifstream file("Zahlenwerte04.txt"); // lesen

    if (!file.is_open()) // file.fail()
    {
        cout << "Could not open the file" << endl;
        throw file_not_found_exception();
    }

    vector<int> zahlen;

    string word;

    while (file >> word)
    {
        cout << word << std::endl;

		try
		{
			if (istZahl(word))
			{
				zahlen.push_back(std::stoi(word));
			}
			else
			{
				throw istkeinezahl_exception(word);
			}
		}
		catch (istkeinezahl_exception& e)
		{
			cout << "Exception aufgetreten: " << e.what();
		}
		catch (exception& e)
		{
			cout << "Exception aufgetreten: " << e.what();
		}
		catch (...)
		{
			cout << "allgemeiner Fehler";
		}
    }

    file.close();

	int summe = 0, min = 0, max = 0;

	cout << "\n\nZahlenwerte:\n";
	
	for (int value : zahlen)
	{	
		summe += value;
		cout << value << "\n";
	}

	float average = (float)summe / (float)zahlen.size();

	ofstream fileOutput("auswertung.txt"); // Ausgabestream (output file stream, of) in C++.

	if (!fileOutput.is_open()) // file.fail()
	{
		cout << "Could not open the file" << endl;
		return 1;
	}

	fileOutput << "Summe: " << summe;
	fileOutput << "\nAnzahl der Werte: " << zahlen.size();
	fileOutput << "\nDurchschnitt: " << average;
	fileOutput.close();

    return 0;
}

bool istZahl(const string& s)
{
    if (s.empty())
        return false;

    for (size_t i = 0; i < s.length(); i++)
        if (!std::isdigit(s[i]))
            return false;

    return true;
}
