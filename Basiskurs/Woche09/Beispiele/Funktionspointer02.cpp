/*
 Dieses Programm demonstriert die Verwendung von Funktionszeigern in C++.

 Der Benutzer wählt zur Laufzeit eine Rechenoperation (Addieren oder Multiplizieren)
 und gibt zwei Ganzzahlen ein. Abhängig von der Auswahl wird ein Funktionszeiger
 entweder auf die Funktion `add` oder `mult` gesetzt.

 Der Funktionszeiger wird anschließend verwendet, um die gewählte Funktion
 indirekt aufzurufen. Dadurch kann zur Laufzeit entschieden werden,
 welche Funktion ausgeführt wird, ohne den Funktionsaufruf fest zu kodieren.

 Ziel des Programms ist es zu zeigen:
 - wie Funktionszeiger deklariert werden
 - wie ihnen Funktionen zugewiesen werden
 - wie Funktionen über einen Funktionszeiger aufgerufen werden
*/

#include <iostream>
#include<fstream>

using namespace std;

int add(int a, int b) 
{
    return a + b;
}

int mult(int a, int b) 
{
    return a * b;
}

int main()
{
    int auswahl, a, b;

    cout << "Bitte Rechenoperation auswwaehlen Addieren (1), Multiplizieren (2): ";
    cin >> auswahl;
    cout << "Bitte erste Zahl eingeben: ";
    cin >> a;
    cout << "Bitte zweite Zahl eingeben: ";
    cin >> b;
    
	int (*ptr_func)(int, int) = nullptr;

    switch (auswahl)
    {
    case 1:
        ptr_func = add;
        //ptr_func = &add;      //mit Addressoperator & gleichwertig, kann man weg lassen
        break;
    case 2:
        ptr_func = mult;
        break;
	default: 
        ptr_func = add;
    }

    if (ptr_func == nullptr)
    {
        return 0;
    }

    cout << "Ergebnis: " << (*ptr_func)(a, b) << endl;
}


