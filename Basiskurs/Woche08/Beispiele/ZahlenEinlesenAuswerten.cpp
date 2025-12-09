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

using namespace std;


class file_not_found_exception : public exception
{
public:
    const char* what() const noexcept
    {
        return "File not found";
    }
};


int main()
{

    ifstream file("Zahlenwerte04.txt"); // lesen

    if (!file.is_open()) // file.fail()
    {
        cout << "Could not open the file" << endl;
        throw file_not_found_exception();
    }

    string word;

    while (file >> word)
    {
        cout << word << std::endl;
    }
        

    file.close();

    return 0;
}