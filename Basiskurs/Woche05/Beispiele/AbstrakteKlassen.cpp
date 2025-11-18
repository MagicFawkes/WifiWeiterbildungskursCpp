/*


2. Polymorph ohne new → mit Referenz
dreieck d(4,5,6);  // konkretes Objekt
figur& f = d;      // polymorphe Referenz
f.zeichnen();      // ruft dreieck::zeichnen() auf

Empfehlung (modern C++)
Wenn du polymorph brauchst ohne delete-Krams:
std::unique_ptr<figur> f = std::make_unique<dreieck>(4,5,6);
*/

#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.14159

struct figur 
{
    virtual float berechneUmfang() = 0;
    virtual float berechneFlaeche() = 0;
    virtual ~figur() { }
};

class dreieck : public figur
{
public:
    dreieck(float a, float b, float c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    float berechneUmfang() override
    {
        return this->a + this->b + this->c;
    }

    //mit Heron-Formel?
    float berechneFlaeche() override
    {
        float s = ((float)this->a + this->b + this->c) / 2;
        return sqrt(s * (s - this->a) * (s - this->b) * (s - this->c));
    }

private:
    float a;
    float b;
    float c;
};

class rechteck : public figur
{
public:
    rechteck(int a, int b) 
    {
        this->a = a;
        this->b = b;
    }

    float berechneUmfang() override
    {
        return (this->a + this->b) * 2;
    }

    //mit Heron-Formel:
    float berechneFlaeche() override
    {
        return this->a * this->b;
    }

private:
    int a;
    int b;
};

class kreis : public figur
{
public:
    kreis(float durchmesser)
    {
        this->durchmesser = durchmesser;
    }

    float berechneUmfang() override
    {
        return this->durchmesser * (float)PI;
    }

    float berechneFlaeche() override
    {
        return PI * pow(this->durchmesser / 2.0, 2); //Cast nicht vergessen oder 2.0 schreiben
    }

private:
    float durchmesser;
};

int main()
{
    figur* dreieck1 = new dreieck( 4,5,6 );
    std::cout << "Dreieck Flaeche: " << dreieck1->berechneFlaeche() << " Umfang: " << dreieck1->berechneUmfang() << std::endl;

    figur* rechteck1 = new rechteck{ 10,20 };
    std::cout << "Rechteck Flaeche: " << rechteck1->berechneFlaeche() << " Umfang: " << rechteck1->berechneUmfang() << std::endl;

    figur* kreis1 = new kreis{ 50 };
    std::cout << "Kreis Flaeche: " << kreis1->berechneFlaeche() << " Umfang: " << kreis1->berechneUmfang() << std::endl;

    delete(dreieck1);
    delete(rechteck1);
    delete(kreis1);

    return 0;
}
