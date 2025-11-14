/*
Aufgabe 1
Schreiben Sie eine Klasse, welche 2 private variablen mittels eines Konstruktors initialisert,
überlegen Sie sich, wie Sie den Wert dieser variablen weiterhin im weiteren Verlauf des
Programmes setzen und in anderen Variablen in der main() speichern können. Außerdem soll
this verwedent werden.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

class testklasse
{
public:

    //Geht auch so: Initializer-List im Konstruktor bevorzugt:
    //testklasse(int a, int b) : a(a), b(b) {}

    testklasse(int a, int b)
    {
        this->a = a;
        this->b = b;
    }

    void variablen_setzen(int a, int b)
    {
        this->a = a;
        this->b = b;
    }

    int variableA_abrufen()
    {
        return this->a;
    }

    int variableB_abrufen()
    {
        return this->b;
    }

private:
    int a;
    int b;
};

int main()
{

    testklasse testklasse = { 10, 20 };
    std::cout << "Variable A: " << testklasse.variableA_abrufen() << ", Variable B: " << testklasse.variableB_abrufen() << std::endl;

    testklasse.variablen_setzen(40, 50);

    std::cout << "Variable A: " << testklasse.variableA_abrufen() << ", Variable B: " << testklasse.variableB_abrufen();

    return 0;
}

