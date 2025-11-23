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
    virtual ~Medium()       //oder  virtual ~Medium() = default;
    {
	    
    }

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
            "\nTitel: " << this->getTitel() <<
            "\nAutor: " << this->getAutor() <<
            "\nJahr: " << this->getJahr() <<
            "\nArt: " << this->getArt() <<
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
            "\nTitel: " << this->getTitel() <<
            "\nAutor: " << this->getAutor() <<
            "\nJahr: " << this->getJahr() <<
            "\nArt: " << this->getArt() <<
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
            "\nTitel: " << this->getTitel() << 
            "\nAutor: " << this->getAutor() << 
            "\nJahr: " << this->getJahr() << 
            "\nArt: " << this->getArt() << 
            "\nDauer Minuten: " << this->getDauerMinuten();
    }
};

class Mediathek
{
private:
    std::unique_ptr<std::unique_ptr<Medium>[]> liste;
    int kapazitaet;
    int anzahl = 0;

public:
    Mediathek(int kapazitaet)
        : kapazitaet(kapazitaet),
        liste(std::make_unique<std::unique_ptr<Medium>[]>(kapazitaet))
    {
    }

    void mediumHinzufuegen(std::unique_ptr<Medium> m)
    {
        if (this->kapazitaet < (anzahl + 1))
	    {
            return;
	    }

        liste[this->anzahl] = std::move(m);
        anzahl++;
    }

    void mediumLoeschen(int index)
    {
        if (this->anzahl <= 0 || index > this->anzahl || index < 0)
            return;
    }

    Medium* mediumFinden(const std::string& titel)
    {
        for (int i = 0; i < anzahl; ++i)
        {
        	// Vergleich funktioniert direkt, weil std::string den Operator == überlädt
        	// und dabei den Textinhalt beider Strings vergleicht.
	        if (liste[i]->getTitel() == titel)
	        {
                return liste[i].get();
                // Gibt nur den rohen Pointer zurück, ohne Besitz zu übertragen.
				// Der unique_ptr in liste[i] bleibt weiterhin alleiniger Besitzer
	        	// und löscht das Objekt am Ende seiner Lebenszeit.
	        }
        }

        return NULL;
    }

    void alleAusgeben() const
    {
	    for (int i = 0; i < anzahl; ++i)
	    {
            liste[i]->anzeigen();
	    }
    }

    void nachTypAusgeben(Medienart art) const
    {
        std::cout << "\n\nMedieanart ausgeben: " << art << "\n";
        for (int i = 0; i < anzahl; ++i)
        {
	        if (art == liste[i]->getArt())
	        {
                liste[i]->anzeigen();
	        }
        }
    }
};

int main()
{

    /*
    Mediathek mediathek(5);
	Mediathek mediathek{5};
    () (runde Klammern) rufen den normalen Konstruktor direkt auf.
	{} (geschweifte Klammern) verwenden die moderne „uniform initialization“, die strenger ist (verhindert z. B. Verluste durch Typumwandlung) und – falls vorhanden – bevorzugt einen std::initializer_list-Konstruktor.
	Wenn die Klasse keinen initializer_list-Konstruktor besitzt, funktionieren beide Varianten gleich.
	*/

    Mediathek mediathek{10};
    std::unique_ptr<Medium> buch = std::make_unique<Buch>("Buch1", "Autor1", 2001, BUCH, 201);
    std::unique_ptr<Medium> buch1 = std::make_unique<Buch>("Buch2", "Autor2", 2002, BUCH, 202);
    std::unique_ptr<Medium> buch2 = std::make_unique<Buch>("Buch3", "Autor3", 2003, BUCH, 203);

    std::unique_ptr<Medium> zeitschrift1 = std::make_unique<Zeitschrift>("zeitschrift1", "AutorZ1", 1001, ZEITSCHRIFT, 205);
    std::unique_ptr<Medium> zeitschrift2 = std::make_unique<Zeitschrift>("zeitschrift2", "AutorZ2", 1002, ZEITSCHRIFT, 206);
    std::unique_ptr<Medium> zeitschrift3 = std::make_unique<Zeitschrift>("zeitschrift3", "AutorZ3", 1003, ZEITSCHRIFT, 207);

    std::unique_ptr<Medium> video1 = std::make_unique<Video>("video1", "AutorV1", 2034, VIDEO, 401);
    std::unique_ptr<Medium> video2 = std::make_unique<Video>("video2", "AutorV2", 2035, VIDEO, 202);
    std::unique_ptr<Medium> video3 = std::make_unique<Video>("video3", "AutorV3", 2036, VIDEO, 203);

    mediathek.mediumHinzufuegen(std::move(buch));
    mediathek.mediumHinzufuegen(std::move(buch1));
    mediathek.mediumHinzufuegen(std::move(buch2));

    mediathek.mediumHinzufuegen(std::move(zeitschrift1));
    mediathek.mediumHinzufuegen(std::move(zeitschrift2));
    mediathek.mediumHinzufuegen(std::move(zeitschrift3));

    mediathek.mediumHinzufuegen(std::move(video1));
    mediathek.mediumHinzufuegen(std::move(video2));
    mediathek.mediumHinzufuegen(std::move(video3));

    mediathek.alleAusgeben();
    mediathek.nachTypAusgeben(ZEITSCHRIFT);

    Medium* buchNeu = mediathek.mediumFinden("Buch2");
    
	if (buchNeu != nullptr)
    {
        std::cout << "\n\nBuch2 gefunden:\n";
        buchNeu->anzeigen();
    }

    return 0;
}