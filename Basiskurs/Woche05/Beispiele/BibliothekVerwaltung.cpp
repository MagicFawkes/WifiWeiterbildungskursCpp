/*
Übungsbeispiel: Bibliotheks-Verwaltungssystem in C++
Aufgabenstellung

Erstellen Sie ein einfaches Bibliotheks-Verwaltungssystem mit zwei Klassen: Buch und Bibliothek.

Teil 1: Die Klasse Buch

Erstellen Sie eine Klasse Buch mit:

Private Attribute:

Katalognummer (int)

Erscheinungsjahr (int)

Seitenanzahl (int)

Ausgeliehen (bool)

Öffentliche Methoden:

Einen Konstruktor, der alle Attribute initialisiert

Getter und Setter für alle Attribute

Eine Methode ausleihen(), die den Ausleihstatus auf true setzt

Eine Methode zurueckgeben(), die den Ausleihstatus auf false setzt

Eine Methode zeigeDaten(), die alle Informationen zum Buch ausgibt

Teil 2: Die Klasse Bibliothek

Erstellen Sie eine Klasse Bibliothek mit:

Private Attribute:

Ein festes Array von Buch-Objekten (maximale Größe 10)

Anzahl der Bücher in der Bibliothek (int)

Öffentliche Methoden:

Einen Konstruktor, der eine leere Bibliothek initialisiert

Eine Methode buchHinzufuegen(Buch neuesBuch), die ein Buch zur Bibliothek hinzufügt

Eine Methode zeigeBibliothek(), die alle Informationen zu allen Büchern ausgibt

Eine Methode durchschnittsAlter(), die das Durchschnittsalter der Bücher berechnet

Eine Methode sucheBuchNachNummer(int katalogNr), die ein Buch nach seiner Katalognummer sucht

Teil 3: Main-Funktion

Schreiben Sie eine main()-Funktion, die:

Mindestens drei verschiedene Buch-Objekte erstellt

Eine Bibliothek erstellt und die Bücher hinzufügt

Ein Buch ausleiht

Die gesamte Bibliothek anzeigt

Das Durchschnittsalter der Bücher berechnet und ausgibt

Nach einem Buch mit einer bestimmten Katalognummer sucht

Hinweise zur Aufgabe

Diese Aufgabe verwendet ausschließlich Stack-Speicher (kein new oder delete)

Verwenden Sie ein festes Array anstelle eines dynamischen Arrays

Achten Sie auf die richtige Kapselung (public vs. private)

Implementieren Sie alle Konstruktoren und Methoden vollständig

Denken Sie an Fehlerbehandlung (z.B. wenn die Bibliothek voll ist)

Lernziele

Klassen und Objekte: Erstellen und Verwenden von eigenen Klassen

Konstruktoren: Definition von neuen Konstruktoren

Kapselung: Verwendung von private Attributen und public Methoden

Getter und Setter: Implementierung von Zugriffsmethoden

Statische Arrays: Arbeit mit Arrays fester Größe

Rückgabewerte: Nutzung von Rückgabewerten zur Fehlerbehandlung

Objekt-Komposition: Aufbau komplexerer Strukturen durch Verwendung von Objekten in anderen Klassen

Erweiterungsmöglichkeiten

Implementierung einer buchEntfernen-Methode zum Löschen von Büchern aus der Bibliothek

Hinzufügen einer Validierung, um doppelte Katalognummern zu vermeiden

Erweiterung der Klasse Buch um zusätzliche Attribute wie Genre/Kategorie

Implementierung einer Methode zum Sortieren der Bücher nach Erscheinungsjahr oder Seitenanzahl

Diese Übung ist für eine Bearbeitungszeit von etwa 30 Minuten konzipiert und vermittelt grundlegende Konzepte der objektorientierten Programmierung in C++.
*/

#include <iostream>

using namespace std;

class Buch
{
private:
    int Katalognummer = 0;
    int Erscheinungsjahr = 0;
    int Seitenanzahl = 0;
    bool Ausgeliehen = false;

public:

    Buch()
    {
	    
    }

    Buch(int katalognummer, int erscheinungsjahr, int seitenanzahl, bool ausgeliehen)
    {
        this->Katalognummer = katalognummer;
        this->Erscheinungsjahr = erscheinungsjahr;
        this->Seitenanzahl = seitenanzahl;
        this->Ausgeliehen = ausgeliehen;
    }

    int getKatalognummer() const
    {
        return this->Katalognummer;
    }

    int getErscheinungsjahr() const
    {
        return this->Erscheinungsjahr;
    }

    int getSeitenanzahl() const
    {
        return this->Seitenanzahl;
    }

    bool getAusgeliehen() const
    {
        return this->Ausgeliehen;
    }

    void setKatalognummer(int katalognummer)
    {
        this->Katalognummer = katalognummer;
    }

    void setErscheinungsjahr(int erscheinungsjahr)
    {
        this->Erscheinungsjahr = erscheinungsjahr;
    }

    void setSeitenanzahl(int seitenanzahl)
    {
        this->Seitenanzahl = seitenanzahl;
    }

    void setAusgeliehen(bool ausgeliehen)
    {
        this->Ausgeliehen = ausgeliehen;
    }

    void ausleihen()
    {
        Ausgeliehen = true;
    }

    void zurückgeben()
    {
        Ausgeliehen = false;
    }

    void zeigeDaten()
    {
        cout << "Katalognummer: " << this->Katalognummer;
        cout << "\nErscheinungsjahr: " << this->Erscheinungsjahr;
        cout << "\nSeitenanzahl: " << this->Seitenanzahl;
        cout << "\nAusgeliehen: " << this->Ausgeliehen;
    }
};

class Bibliothek
{
private:
    Buch Bücher[10];
    int anzahlBuecher = 0;

public:
    Bibliothek()
    {
	    
    }  

    void buchHinzufuegen(Buch neuesBuch)
    {
        Bücher[anzahlBuecher].setKatalognummer(neuesBuch.getKatalognummer());
        Bücher[anzahlBuecher].setErscheinungsjahr(neuesBuch.getErscheinungsjahr());
        Bücher[anzahlBuecher].setSeitenanzahl(neuesBuch.getSeitenanzahl());
        Bücher[anzahlBuecher].setAusgeliehen(neuesBuch.getAusgeliehen());
        anzahlBuecher++;
    }

    void zeigeBibliothek()
    {
	    for (int i = 0; i < anzahlBuecher; ++i)
	    {
            Bücher[i].zeigeDaten();
	    }
    }

    void zeigdurchschnittsAlter()
    {
        int summe = 0;

        for (int i = 0; i < anzahlBuecher; ++i)
        {
            summe += Bücher[i].getErscheinungsjahr();
        }

        cout << "Durchschnittsalter: " << summe / anzahlBuecher;
    }

    void sucheBuchNachNummer(int katalogNr)
    {
        for (int i = 0; i < anzahlBuecher; ++i)
        {
	        if (Bücher[i].getKatalognummer() == katalogNr)
	        {
                Bücher[i].zeigeDaten();
	        }
        }
    }
};

int main() 
{

    Bibliothek bibliothek;

    Buch buch1 (5, 6, 7, false);

    bibliothek.buchHinzufuegen(buch1);
    bibliothek.zeigeBibliothek();

    return 0;
}
