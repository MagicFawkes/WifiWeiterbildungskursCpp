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
#include <random>

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
        std::string kartenFarbe;

	    switch (this->farbe)
	    {
            case ROT:
				kartenFarbe = "rot";
                break;
            case GRUEN:
                kartenFarbe = "gruen";
                break;
            case GELB:
                kartenFarbe = "gelb";
                break;
            case BLAU:
                kartenFarbe = "blau";
                break;
	    }

        std::cout << "\nNumberCard " << number
            << " in Farbe " << kartenFarbe << " benutzt!";
    }
};

class SpecialCards : public Base
{
public:

    SpecialCards(int number)
    {
        this->number = number;
    }
    void use() const override
    {
        std::cout << "\nNumberSpecialCard " << number << " benutzt!";
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
   

public:
    std::vector<std::unique_ptr<Deck>> deck;

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
            std::cout << "\n\n**********Kartendeck: " << i+1 << " ************";

            for (int u = 0; u < (int)deck[i]->karten.size(); ++u)
            {
                deck[i]->karten[u]->use();
            }
	    }
        
    }

    void mischen()
    {
        // Liefert einen zufälligen Seed vom System (wenn möglich echter Zufallswert)
        std::random_device rd;

        // Initialisiert den Mersenne-Twister-Zufallszahlengenerator mit dem Seed
        std::mt19937 gen(rd());

        int randomNumber;

        for (int i = 0; i < (int)deck.size(); ++i)
        {
            for (int u = 0; u < (int)deck[i]->karten.size(); ++u)
            {
                // Gleichverteilung für ganze Zahlen von 0 bis (Kartenzahl - 1)
                std::uniform_int_distribution<> dist(0, (int)deck[i]->karten.size() - 1);

                // Erzeugt eine zufällige Zahl im definierten Bereich
                randomNumber = dist(gen);

                std::unique_ptr<Base> karte = std::move(deck[i]->karten[u]);
                deck[i]->karten[u] = std::move(deck[i]->karten[randomNumber]);
                deck[i]->karten[randomNumber] = std::move(karte);
            }
        }
    }
};

int main()
{
    std::unique_ptr<Deck> kartenDeck = std::make_unique<Deck>();

    for (int a = 0; a < 4; ++a)
    {
        for (int i = 0; i < 10; ++i)
        {
            std::unique_ptr<NumberCards> numberCards = std::make_unique<NumberCards>(i, (Color)a);
            kartenDeck->AddCard(std::move(numberCards));
        }
    }

    std::unique_ptr<SpecialCards> numberCards = std::make_unique<SpecialCards>(5);
    kartenDeck->AddCard(std::move(numberCards));

    std::unique_ptr<Deck> kartenDeck1 = std::make_unique<Deck>();

    for (int a = 0; a < 4; ++a)
    {
        for (int i = 0; i < 10; ++i)
        {
            std::unique_ptr<NumberCards> numberCards1 = std::make_unique<NumberCards>(i, (Color)a);
            kartenDeck1->AddCard(std::move(numberCards1));
        }
    }

    Game game = std::move(kartenDeck);
    game.deck.push_back(std::move(kartenDeck1));

    game.print();
    game.mischen();
    game.print();

    return 0;
}

/* Lösung von Trainer:

#include <iostream>
#include <random>
#include <ctime>

using namespace std;

enum Color {
    Red,
    Green,
    Yellow,
    Blue
};

class Card
{
public:
    virtual void use() = 0;
    virtual void print() = 0;

    Card(Color clr) {
        color = colorTostring(clr);
    }

    string colorTostring(Color clr)
    {
        switch (clr) {
        case Red:
            return "Red";
        case Yellow:
            return "Yellow";
        case Green:
            return "Green";
        case Blue:
            return "Blue";
        default:
            return "Unknown";
        }
    }
protected:
    string color;
};


class Numbercard :public Card
{
private:
    int number;
public:
    Numbercard(int number, Color clr) :Card(clr)
    {
        this->number = number;
    }
    void use()
    {
        cout << "Card Number " << number << " with color" << "is used" << color << endl;
    }
    void print()
    {
        cout << "Card Number " << number << " with color" << color << endl;
    }


};

class Specialcard :public Card
{
public:
    Specialcard(string ability, Color clr) :Card(clr)
    {
        this->ability = ability;
    }
    void use()
    {
        cout << "Special Card " << ability << " with color" << color << "is used" << endl;
    }
    void print()
    {
        cout << "Special Card " << ability << " with color" << color << endl;
    }
private:
    string ability;

};


class Game {
private:
    static const int size_stapel = 43;
    Card* stapel[size_stapel];

public:
    Game()
    {
        int index = 0;

        for (int i = 0; i <= 9; i++)
        {
            stapel[index++] = new Numbercard(i, Red);
            stapel[index++] = new Numbercard(i, Green);
            stapel[index++] = new Numbercard(i, Blue);
            stapel[index++] = new Numbercard(i, Yellow);
        }
        stapel[index++] = new Specialcard("Reverse", Red);
        stapel[index++] = new Specialcard("+2", Red);
        stapel[index++] = new Specialcard("Skippen", Red);

    }
    ~Game()
    {
        for (int i = 0; i < size_stapel; i++)
        {
            delete stapel[i];
        }
    }

    void Mischen()
    {
        srand(time(NULL));

        Card* temp = NULL;
        int k = 0;

        for (int i = 0; i < size_stapel; i++)
        {
            k = rand() % (i + 1);
            temp = stapel[i];
            stapel[i] = stapel[k];
            stapel[k] = temp;
        }

    }
    void print() {
        for (int i = 0; i < size_stapel; i++)
        {
            stapel[i]->print();
        }
    }


};

int main()
{
    Game game;
    game.Mischen();
    game.print();

}

*/