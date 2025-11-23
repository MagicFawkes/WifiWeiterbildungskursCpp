/*
Aufgabe 1:
Medienverwaltung mit Smart Pointern
Erstellen Sie eine Enumeration Medienart mit folgenden Werten:
• BUCH
• ZEITSCHRIFT
• VIDEO
Implementieren Sie eine abstrakte Basisklasse Medium mit folgenden privaten Attributen:
• std::string titel
• std::string autor
• int jahr
• Medienart art
Öffetnliche Methoden:
• Konstruktor für alle Attribute
• Getter und Setter
• virtual void anzeigen() const = 0
• virtual ~Medium()
Implementieren Sie drei Klassen:
Buch:
Zusätzliches Attribut:
• int seiten (privat)
Zeitschrift:
Zusätzliches Attribut:
• int ausgabe (privat)
Video:
Zusätzliches Attribut:
• int dauerMinuten (privat)
Jede Klasse überschreibt anzeigen() und gibt alle Informationen aus.
Implementieren Sie eine Klasse Mediathek:
Die Klasse soll folgende privaten Attribute besitzen:
• std::unique_ptr<std::unique_ptr<Medium>[]> liste;
• int kapazitaet;
• int anzahl;
Öffentliche Methoden:
Konstruktor:
Erzeugt ein dynamisches Array unique_ptr<Medium>[]
void mediumHinzufuegen(std::unique_ptr<Medium> m):
Fügt ein Medium hinzu, wenn Platz vorhanden ist.
void mediumLoeschen(int index):
• Löscht das Medium am angegebenen Index
• Verschiebt die nachfolgenden Einträge nach links
Medium* mediumFinden(const std::string& titel):
• Durchsucht die Liste nach dem Titel
• Gibt einen rohen Pointer zurück (kein Besitzübertrag!)
void alleAusgeben() const:
• Gibt alle gespeicherten Medien aus
void nachTypAusgeben(Medienart art) const:
• Gibt alle Medien einer bestimmten Medienart aus
Schreiben Sie ein main(), das:
1. Eine Mediathek mit Kapazität 10 erzeugt
2. Mindestens 5 Medien dynamisch erstellt und hinzufügt
3. Nach einem Medium anhand des Titels sucht
4. Ein Medium löscht
5. Alle verbleibenden Medien ausgibt
6. Alle Medien einer bestimmten Medienart ausgibt
7. Die Speicherverwaltung vollständig durch Smart Pointer übernimmt
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <string>

enum Medienart
{
	BUCH,
    ZEITSCHRIFT,
    VIDEO
};

class Medium
{
public:
    Medium(std::string titel, std::string  autor, int jahr, Medienart art) : titel(titel), autor(autor), jahr(jahr), art(art)
    {
	    
    }
	
    virtual void anzeigen() const = 0;
    virtual ~Medium();

    std::string getTitel() const
    {
        return this->titel;
    }

    std::string getAutor() const
    {
        return this->autor;
    }

    int getJahr() const
    {
        return this->jahr;
    }

    Medienart getArt() const
    {
        return this->art;
    }

    void setTItel(std::string titel)
    {
        this->titel = titel;
    }

    void setAutor(std::string autor)
    {
        this->autor = autor;
    }

    void setJahr(int jahr)
    {
        this->jahr = jahr;
    }

    void setArt(Medienart art)
    {
        this->art = art;
    }

private:
    std::string titel;
    std::string autor;
    int jahr;
    Medienart art;
};

class Buch : public Medium
{
private:
    int seiten;
public:

    Buch(std::string titel, std::string  autor, int jahr, Medienart art, int seiten) : Medium(titel, autor, jahr, art), seiten(seiten)
    {
	    
    }

    int getSeiten() const
    {
        return this->seiten;
    }

    void setSeiten(int seiten)
    {
        this->seiten = seiten;
    }

    void anzeigen() const override
    {
        std::cout <<
            "Titel: " << this->getTitel() <<
            "\nAutor: " << this->getAutor() <<
            "\nJahr: " << this->getJahr() <<
            "\n Art: " << this->getArt() <<
            "\nSeiten: " << this->getSeiten();
    }
};

class Zeitschrift : public Medium
{
private:
    int ausgabe;
public:

    Zeitschrift(std::string titel, std::string  autor, int jahr, Medienart art, int ausgabe) : Medium(titel, autor, jahr, art), ausgabe(ausgabe)
    {

    }

    int getAusgabe() const
    {
        return this->ausgabe;
    }

    void setAusgabe(int ausgabe)
    {
        this->ausgabe = ausgabe;
    }

    void anzeigen() const override
    {
        std::cout <<
            "Titel: " << this->getTitel() <<
            "\nAutor: " << this->getAutor() <<
            "\nJahr: " << this->getJahr() <<
            "\n Art: " << this->getArt() <<
            "\nAusgabe: " << this->getAusgabe();
    }
};

class Video : public Medium
{
private:
    int dauerMinuten;
public:

    Video(std::string titel, std::string  autor, int jahr, Medienart art, int dauerMinuten) : Medium(titel, autor, jahr, art), dauerMinuten(dauerMinuten)
    {

    }

    int getDauerMinuten() const
    {
        return this->dauerMinuten;
    }

    void setDauerMinuten(int dauerMinuten)
    {
        this->dauerMinuten = dauerMinuten;
    }

    void anzeigen() const override
    {
        std::cout << 
            "Titel: " << this->getTitel() << 
            "\nAutor: " << this->getAutor() << 
            "\nJahr: " << this->getJahr() << 
            "\n Art: " << this->getArt() << 
            "\nDauer Minuten: " << this->getDauerMinuten();
    }
};

int main()
{
    printf("Test");
    return 0;
}