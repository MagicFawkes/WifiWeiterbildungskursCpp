/*
Aufgabe 4
Kontoverwaltung mit Klassen in C++ – Erstelle ein C++-Programm zur Verwaltung eines
einfachen Bankkontos. Das Programm soll eine Klasse Konto enthalten, die grundlegende
Kontofunktionen bereitstellt.
Anforderungen: Die Klasse Konto besitzt die Attribute string inhaber, int kontonummer und
double kontostand. Sie hat einen Konstruktor. Methoden: void einzahlen(double betrag) (erhöht
den Kontostand um den Betrag, falls dieser positiv ist), bool abheben(double betrag) (verringert
den Kontostand um den Betrag, wenn genug Guthaben vorhanden ist, und gibt true zurück,
sonst false) sowie void anzeigen() (gibt alle Kontoinformationen auf der Konsole aus).
In der main()-Funktion soll ein Konto-Objekt erstellt werden, es sollen mehrere Einzahlungen
und Abhebungen durchgeführt werden, und nach jeder Aktion sollen die aktuellen
Kontoinformationen angezeigt werden.
Teste auch eine Abhebung, die fehlschlägt, weil das Guthaben nicht ausreicht.
Überlege was zu private und was zu public gehört und was Sie mit dem Konstruktor machen
sollen. Es sollen 2 Konstruktoren verwendet werden. Einer davon ist der Standardkonstruktor,
der soll nicht verloren werden.
*/


#include <iostream>
#include <string>

class konto
{
private:
    std::string inhaber;
    int kontonummer = 0;
    double kontostand = 0;

public:
    konto()
    {
        this->inhaber = "Unbekannt";
    }

    konto(std::string inhaber, int kontonummer)
    {
        this->inhaber = inhaber;
        this->kontonummer = kontonummer;
    }

    //auch möglich - Initialisierungsliste
    /*konto() : inhaber("unbekannt"), kontonummer(0), kontostand(0.0)
    {
    }

    konto(std::string inhaber, int kontonummer)
        : inhaber(inhaber), kontonummer(kontonummer), kontostand(0.0)
    {
    }*/

    void einzahlen(double betrag)
    {
        if (betrag > 0)
            this->kontostand += betrag;
    }

    bool abheben(double betrag)
    {
        if (betrag <= this->kontostand)
        {
            this->kontostand -= betrag;
            return true;
        }
        
    	return false;
    }

    void anzeigen() const
    {
        std::cout << "Inhaber: " << this->inhaber << std::endl;
        std::cout << "Kontonummer: " << this->kontonummer << std::endl;
        std::cout << "Kontostand: " << this->kontostand << std::endl;
    }
};

int main()
{
    konto konto{ "Max Mustermann", 50456 };
    konto.einzahlen(100);
    konto.anzeigen();
    konto.abheben(80);
    konto.anzeigen();
    konto.abheben(100);
    konto.anzeigen();

    return 0;
}