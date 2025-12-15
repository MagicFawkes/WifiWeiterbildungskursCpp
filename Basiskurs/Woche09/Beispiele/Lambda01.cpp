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
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

//void function(int x) {

//    cout << x << endl;

//}

//function<void(int)> func

// void ist rückgabetyp

// int parameterliste

// es kann sein:

// lambda

//Funktionszeiger

//funktion

//funktor

void For_each(vector<int> values, function<void(int)> func) {

    for (int value : values) {

        func(value);

    }

}

//void For_each(vector<int> values, void(*func)(int)) {

//    for (int value : values) {

//        func(value);

//    }

//

//}

int main()

{

    vector<int> a = { 1,2,3,4,5 };

    int num = 10;

    //    [&] : capture all external variables by reference.

    //    [=] : capture all external variables by value.

    //    [a, &b] : capture 'a' by value and 'b' by reference.

    auto lambda = [num](int x) mutable

        {

            num = 10;

            cout << num << endl;

        };

    auto lambda1 = [](int x) mutable

        {

            x = x + 10;

            cout << x << endl;

        };

    For_each(a, lambda1);

    cout << "----------" << endl;

    int summ = 0;

    std::for_each(a.begin(), a.end(), [&summ](int x)

        {

            summ = summ + x;

        });

    cout << summ << endl;

    //    template<class InputIterator, class Function>

    //Function for_each(InputIterator first, InputIterator last, Function fn)

    //{

    //    while (first != last) {

    //        fn(*first);

    //        ++first;

    //    }

    //    return fn;      // or, since C++11: return move(fn);

    //}


    //template<class InputIterator, class UnaryPredicate>

    //InputIterator find_if(InputIterator first, InputIterator last, UnaryPredicate pred)

    //{

    //    while (first != last) {

    //        if (pred(*first)) return first;

    //        ++first;

    //    }

    //    return last;

    //}

    //Ein Prädikat ist:

    //Ein Funktionsobjekt(Funktion, Lambda, Funktor), welches ein oder mehrere Werte entgegenimmt und ein bool zurückgibt

    // Rückgabwerte: true oder false

    // UnaryPredicate = ein parameter BinaryPredicate = 2 Parameter

    auto lambda2 = [](int x) {

        return x;

        };

    int result = lambda2(2);

    auto it = std::find_if(a.begin(), a.end(), [](int x)

        {

            return x > 3;

        });

    cout << *it << endl;

}

