/*
Aufgabe 2
Erstellen Sie jeweils eine Klasse zur Berechnung von Fläche und Umfang von folgenden Figuren
(Dreieck, Rechteck und Kreis). Alle Funktionen sowie Variablen werden innerhalb der Klasse
definiert. Überlegen Sie, was unter private und public gehört und ob Sie ein Konstruktor
brauchen.
https://cplusplus.com/reference/cmath/sqrt/
*/

#include <cmath>
#include <iostream>

#define PI 3.14159

class dreieck
{
public:
    dreieck(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
	
    int berechneUmfang()
    {
        return this->a + this->b + this->c;
    }

    //mit Heron-Formel?
    float berechneFlaeche()
    {
        float s = ((float)this->a + this->b + this->c) / 2;
        return sqrt(s * (s - this->a) * (s - this->b) * (s - this->c));
    }

private:
    int a;
    int b;
    int c;
};

class rechteck
{
public:
    rechteck(int a, int b)
    {
        this->a = a;
        this->b = b;
    }

    int berechneUmfang()
    {
        return (this->a + this->b) * 2;
    }

    //mit Heron-Formel:
    int berechneFlaeche()
    {
        return this->a * this->b;
    }

private:
    int a;
    int b;
};

class kreis
{
public:
    kreis(int durchmesser)
    {
        this->durchmesser = durchmesser;
    }

    float berechneUmfang()
    {
        return this->durchmesser * PI;
    }

    float berechneFlaeche()
    {
        return PI * pow(this->durchmesser/2.0,2); //Cast nicht vergessen oder 2.0 schreiben
    }

private:
    int durchmesser;
};

int main()
{
    dreieck dreieck{ 4,5,6 };
    std::cout << "Dreieck Flaeche: " << dreieck.berechneFlaeche() << " Umfang: " << dreieck.berechneUmfang() << std::endl;

    rechteck rechteck{ 10,20 };
    std::cout << "Rechteck Flaeche: " << rechteck.berechneFlaeche() << " Umfang: " << rechteck.berechneUmfang() << std::endl;

    kreis kreis{ 50};
    std::cout << "Kreis Flaeche: " << kreis.berechneFlaeche() << " Umfang: " << kreis.berechneUmfang() << std::endl;

    return 0;
}