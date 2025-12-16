/*
Aufgaben
Schreibe eine Lambda-Expression, die:
counter by value captured
bei jedem Aufruf den internen Counter erhöht
den aktuellen Wert zurückgibt

std::count_if
gegeben ist ein vektor
zähle alle Zahlen die größer sind als 10 mit Lambda und Funktor

Schreibe eine Lambda-Expression, die:
die Summe aller Werte eines Vektors berechnet
die Variable summe bei reference captured und die summe speichert

verwende für diese Aufgaben einen Funktionspointer


Implementiere einen Funktor Addierer, der:
zwei int-Werte erhält
deren Summe zurückgibt

Implementiere einen thematisierten Funktor Vergleicher<T>, der:
zwei Werte vom Typ T vergleicht
true zurückgibt, wenn der erste größer ist
 Verwende ihn mit int, double und std::string.

Implementiere einen Funktor Counter, der:
eine externe Variable speichert
bei jedem Aufruf diese Variable erhöht

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
    int counter = 0;

    std::function<void()> lambda1 = [&counter]()->void       
        {
            counter++;
        };

    lambda1();
    lambda1();
    lambda1();
    lambda1();
    std::cout << "Counter: " << counter << std::endl;


    std::vector<int> messwerte = { 2,1,10,5, 6 ,20,40,80 };

    int anzahl = std::count_if(messwerte.begin(), messwerte.end(), [](int x) ->bool
        {
            return x > 10;
        });

    std::cout << "Anzahl: " << anzahl << std::endl;

    std::function<bool(int x)> lambda2 = [](int x)->bool
        {
            return x > 10;
        };

    int anzahl1 = std::count_if(messwerte.begin(), messwerte.end(), lambda2);

    std::cout << "Anzahl1: " << anzahl1 << std::endl;
}