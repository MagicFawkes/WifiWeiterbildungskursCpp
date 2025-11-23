/*
Aufgabe 1:
Starten Sie ein Projekt und implementieren Sie die normalen
Zahlenkarten (NumberCards). Es soll möglich sein einen
Spielkartenstapel mit Zahlen (Number) von 0-9 und in den
Farben (Color) Rot, Grün, Gelb und Blau zu erstellen.
Bonus:
Implementieren Sie für die Color eine eigene Enum Class.
Testen Sie Ihren Stapel, indem Sie die Karten auf die Konsole
ausgeben.

Aufgabe 2:
Implementieren Sie zusätzlich zu den Zahlenkarten auch die
Spezialkarten (SpecialCards). Es würde sich anbieten eine
Abstrakte Elternklasse Cards zu implementieren, welche von
den beiden Kindklassen (NumberCards & SpecialCards)
erweitert/implementiert wird. Eine Methode namens use()
könnte von Cards als pure virtual function deklariert werden.

Aufgabe 3:
Erstellen Sie eine Klasse Game, welche ein Deck von Karten
(cards) in sich hält - die Karten können in einem Array
gespeichert werden.
Im Konstruktor der Game Klasse soll ein neues Kartendeck
erstellt und im Destruktor gelöscht werden.
Des Weiteren sollte die Game Klasse eine Methode zum
Mischen der Karten besitzen und eine Print Methode, welche
den Kartenstapel ausgibt
*/

#include <iostream>
#include <memory>
#include <vector>

enum Color
{
	ROT,
    GRUEN,
    GELB,
    BLAU
};

class Base
{
public:
    int number;
    
    virtual void use() const = 0;

    virtual ~Base()       //oder  virtual ~Base() = default;
    {

    }
};

class NumberCards : public Base
{
public:
    Color farbe;

    NumberCards(int number, Color farbe)
    {
        this->number = number;
        this->farbe = farbe;
    }

    void use() const override
    {
        std::cout << "\nNumberCard " << number
            << " in Farbe " << farbe << " benutzt!\n";
    }
};

class SpecialCards : public Base
{
public:
    void use() const override
    {
        std::cout << "NumberCard ";
    }
};

class Deck
{
public:
    std::vector<std::unique_ptr<Base>> karten;

    void AddCard(std::unique_ptr<Base> base)
    {
        karten.push_back(std::move(base));
    }
};

class Game
{
    std::vector<std::unique_ptr<Deck>> deck;

public:
    Game(std::unique_ptr<Deck> deck)
    {
        this->deck.push_back(std::move(deck));
    }

    ~Game()
    {
        this->deck.clear();
    }

    void print()
    {
	    for (int i = 0; i < (int)deck.size(); ++i)
	    {
            for (int u = 0; u < (int)deck[i]->karten.size(); ++u)
            {
                std::cout << "\nKarte: " << deck[i]->karten[u]->number;
            }
	    }
        
    }
};

int main()
{
    Deck kartenDeck;

	for (int i = 0; i < 10; ++i)
	{
        std::unique_ptr<NumberCards> numberCards = std::make_unique<NumberCards>(i, GELB);
        kartenDeck.AddCard(std::move(numberCards));
	}

    for (int u = 0; u < (int)kartenDeck.karten.size(); ++u)
    {
        std::cout << "\nKarte: " << kartenDeck.karten[u]->number;
       kartenDeck.karten[u]->use();
    }

    return 0;
}