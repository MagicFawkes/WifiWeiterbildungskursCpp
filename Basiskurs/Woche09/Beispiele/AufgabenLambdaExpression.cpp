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


struct Functor 
{
    bool operator()(const int& a) const 
	{
        return a > 10;
    }
};

// Für Funktionspointer
void berechneSumme(const std::vector<int>& v, int& summe)
{
    summe = 0;
    for (int x : v)
        summe += x;
}

int main()
{
    //****************************************************************
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

    //****************************************************************
    std::vector<int> messwerte = { 2,1,10,5, 6 ,20,40,80 };

    int anzahl = std::count_if(messwerte.begin(), messwerte.end(), [](int x) ->bool
        {
            return x > 10;
        });

    std::cout << "Anzahl: " << anzahl << std::endl;

    //****************************************************************
    std::function<bool(int x)> lambda2 = [](int x)->bool
        {
            return x > 10;
        };

    int anzahl1 = std::count_if(messwerte.begin(), messwerte.end(), lambda2);

    std::cout << "Anzahl1: " << anzahl1 << std::endl;

    //****************************************************************
    int anzahl2 = std::count_if(messwerte.begin(), messwerte.end(), Functor());

    std::cout << "Anzahl2: " << anzahl2 << std::endl;

    //**************************************************************** Ohne Funktionspointer, direkt lambda in for_each

    int summe = 0;
    std::vector<int> messwerte3 = { 2,1,10,5, 6};

    std::for_each(messwerte3.begin(), messwerte3.end(), [&summe](int x)->void         
        {
            summe+=x;
        });

    std::cout << "Summe: " << summe << std::endl;

    //**************************************************************** Mit Funktionspointer 

    int summe1 = 0;

    std::vector<int> messwerte4 = { 2,1,10,5, 6 };

    std::function<void(const std::vector<int>& v, int& summe)> functo = berechneSumme;      //function Schreibweise

    berechneSumme(messwerte4, summe1);

    std::cout << "Summe1: " << summe1 << std::endl;
}