/*
	Funktionspointer Beispiel
*/

#include <iostream>
#include<fstream>

using namespace std;

int add(int a, int b) {
    return a + b;
}

int mult(int a, int b) {
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


