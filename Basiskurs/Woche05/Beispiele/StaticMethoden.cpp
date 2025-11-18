/*
⭐ Erklärung: static Variablen und static Methoden
Static Variablen (in Klassen)

Eine static Variable gehört nicht zu einem einzelnen Objekt, sondern zur Klasse selbst.

Es existiert nur eine einzige Kopie, egal wie viele Objekte du erzeugst.

Wird häufig verwendet für Zähler, globale Zustände, gemeinsame Daten.

Static Methoden

Eine static Methode gehört auch zur Klasse, nicht zum Objekt.

Sie kann ohne Objekt aufgerufen werden: Klassenname::Methode().

Sie kann nur auf static Variablen zugreifen (weil sie kein this hat).
*/

#include <iostream>
using namespace std;

class Test {
private:
    static int counter;   // static Klassenvariable

public:
    Test() {
        counter++;        // jedes neue Objekt erhöht den Zähler
    }

    static void printCounter() {   // static Methode
        cout << "Anzahl Test-Objekte: " << counter << endl;
    }
};

// Definition der static Variable (Pflicht!) Notwendig weil C++ Klassen nur beschreiben, aber keinen Speicher für statische Mitglieder anlegen.
int Test::counter = 0;

int main() {
    Test t1;
    Test t2;
    Test t3;

    Test::printCounter();  // Aufruf ohne Objekt!
    return 0;
}
