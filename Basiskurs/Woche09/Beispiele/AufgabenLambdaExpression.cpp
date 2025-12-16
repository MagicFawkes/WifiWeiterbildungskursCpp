/*
Aufgabe 1
Schreibe eine Lambda-Expression, die:
counter by value captured
bei jedem Aufruf den internen Counter erhöht
den aktuellen Wert zurückgibt

Aufgabe 2
std::count_if
gegeben ist ein vektor
zähle alle Zahlen die größer sind als 10 mit Lambda und Funktor

Aufgabe 3
Schreibe eine Lambda-Expression, die:
die Summe aller Werte eines Vektors berechnet
die Variable summe bei reference captured und die summe speichert

verwende für diese Aufgaben einen Funktionspointer

Aufgabe 4
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
    // const beim Parameter: der übergebene Wert wird nicht verändert
	// const am Methodenende: der Objektzustand (this) wird nicht verändert,
	// d. h. Membervariablen dürfen in dieser Funktion nicht geändert werden
    bool operator()(const int& a) const
	{
        return a > 10;
    }
};

//Functor Addierer
struct Addierer
{
    int operator()(const int& a, const int& b) const
    {
        return a + b;
    }
};

// Für Funktionspointer benutzt
void berechneSumme(const std::vector<int>& v, int& summe)
{
    //summe = 0;
    for (int x : v)
        summe += x;
}

int main()
{
    //***************************Aufgabe 1*************************************
    int counter = 0;

    std::function<void()> lambda1 = [&counter]()->void       
        {
            counter++;
        };

    lambda1();
    lambda1();
    lambda1();
    lambda1();
    std::cout << "Aufgabe1 Counter: " << counter << std::endl;

    //***************************Aufgabe 2*************************************
    std::vector<int> messwerte = { 2,1,10,5, 6 ,20,40,80 };

    int anzahl = std::count_if(messwerte.begin(), messwerte.end(), [](int x) ->bool
        {
            return x > 10;
        });

    std::cout << "Aufgabe 2 Anzahl: " << anzahl << std::endl;

    //**************************Aufgabe 2**************************************
    std::function<bool(int x)> lambda2 = [](int x)->bool
        {
            return x > 10;
        };

    int anzahl1 = std::count_if(messwerte.begin(), messwerte.end(), lambda2);

    std::cout << "Aufgabe2 Anzahl1: " << anzahl1 << std::endl;

    //*******************************Aufgabe 2*********************************
    int anzahl2 = std::count_if(messwerte.begin(), messwerte.end(), Functor());

    std::cout << "Aufgabe2 Anzahl2: " << anzahl2 << std::endl;

    //*****************************Aufgabe 3*********************************** Ohne Funktionspointer, direkt lambda in for_each

    int summe = 0;
    std::vector<int> messwerte3 = { 2,1,10,5, 6};

    std::for_each(messwerte3.begin(), messwerte3.end(), [&summe](int x)->void         
        {
            summe+=x;
        });

    std::cout << "Aufgabe 3 Summe: " << summe << std::endl;

    //******************************Aufgabe 3********************************** Mit Funktionspointer 

    int summe1 = 0;

    std::vector<int> messwerte4 = { 2,1,10,5, 6 };

    std::function<void(const std::vector<int>& v, int& summe)> functo = berechneSumme;      //function Schreibweise
    void (*sumFunc)(const std::vector<int>&, int&) = berechneSumme;      //Funktionspointer Schreibweise (alt)

    berechneSumme(messwerte4, summe1);
    std::cout << "Aufgabe 3 Summe1: " << summe1 << std::endl;
    sumFunc(messwerte4, summe1);
    std::cout << "Aufgabe 3 Summe1: " << summe1 << std::endl;

    //***************************Aufgabe 4************************************* 

    int a = 4;
    int b = 3;

    Addierer addierer;

    std::cout << "Aufgabe 4 Wert: " << addierer(a, b) << std::endl;
}