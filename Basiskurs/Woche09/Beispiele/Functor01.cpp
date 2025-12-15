/*
    Was ist ein Functor (Function Object)?
    --------------------------------------
    Ein Functor ist ein Objekt (also eine Instanz einer Klasse/struct), das sich wie eine Funktion
    aufrufen lässt. Das funktioniert in C++ dadurch, dass die Klasse/struct den Operator operator()
    überlädt. Danach kann man ein Objekt dieser Klasse schreiben wie: obj(...), als wäre obj eine Funktion.

    Warum ist das nützlich?
    - Ein Functor kann Zustand (Membervariablen) speichern und beim "Funktionsaufruf" nutzen.
    - Er ist ein ganz normales Objekt und kann daher Daten behalten, konfiguriert werden, etc.
    - In der STL (Standard Library) werden Functors oft als "Callback" benutzt, z.B. als Vergleichsfunktion
      bei std::sort oder als Aktion bei std::for_each.

    Wie wird der Functor hier eingesetzt?
    -------------------------------------

    1) class Number ist ein Functor (sogar mit *zwei* operator()-Überladungen):
       - Number::operator()(int input)
            -> speichert den Wert in der Membervariable n und gibt ihn zurück.
            -> Das ist wichtig: n ist Zustand, der im Objekt erhalten bleibt (zwischen Aufrufen).

       - Number::operator()(int input1, int input2)
            -> verwendet den gespeicherten Zustand n und addiert: n + input1 + input2
            -> Dadurch sieht man den typischen Vorteil eines Functors: Er kann "merken", was vorher
               passiert ist (hier: n wurde vorher gesetzt).

       Im main():
         Number n;
         n(10);       // ruft operator()(int) auf und setzt internen Zustand n=10
         n(10, 20);   // ruft operator()(int,int) auf und nutzt n (also 10) => 10+10+20 = 40 (wird hier nur nicht ausgegeben)

    2) struct VergleicheGehalt ist ein Functor, der als Vergleichsfunktion für std::sort dient:
         bool operator()(const Person& a, const Person& b) const {
             return a.gehalt < b.gehalt;
         }

       std::sort erwartet als dritten Parameter etwas, das man wie comp(a,b) aufrufen kann und das
       true liefert, wenn a "vor" b einsortiert werden soll.
       Genau das liefert VergleicheGehalt(): es sortiert nach gehalt aufsteigend.

       Im main():
         std::sort(personen.begin(), personen.end(), VergleicheGehalt());
         -> hier wird ein temporäres Functor-Objekt erzeugt und von sort immer wieder aufgerufen,
            um zwei Personen zu vergleichen.

    3) Zusätzlich wird am Ende ein Lambda verwendet:
         [](Person p) { cout << p.gehalt << endl; }

       Ein Lambda ist praktisch auch ein Functor: Der Compiler erzeugt intern ein Objekt mit operator().
       std::for_each ruft dieses Objekt für jedes Element auf.

    Hinweis zu struct Person:
    -------------------------
    Person enthält ebenfalls operator< (Vergleich "dieses Person-Objekt < anderes Person-Objekt" nach alter)
    und sogar operator()(a,b) als Vergleich (auch nach alter). Beides *könnte* man für sort verwenden,
    aber in deinem Code wird tatsächlich nach gehalt sortiert (VergleicheGehalt).
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Number {
private:
    int n;
public:
    int operator()(int input)
    {
        n = input;
        return n;
    }
    int operator()(int input1, int input2)
    {
        return n + input1 + input2;
    }
};

struct Person {
    std::string name;
    int alter;
    float gehalt;

    bool operator<(const Person& a) const {
        return alter < a.alter;
    }

    bool operator()(const Person& a, const Person& b) const {
        return a.alter < b.alter;
    }
};

struct VergleicheGehalt {
    bool operator()(const Person& a, const Person& b) const {
        return a.gehalt < b.gehalt;
    }
};

int main()
{
    Number n;
    n(10);

    n(10, 20);

    std::vector<Person> personen = {
        {"Anna",32,2550},
        {"bob",25,3500},
        {"Clara",40,2900}
    };

    std::sort(personen.begin(), personen.end(), VergleicheGehalt());

    std::for_each(personen.begin(), personen.end(), [](Person p) {
        cout << p.gehalt << endl;
        });
}
