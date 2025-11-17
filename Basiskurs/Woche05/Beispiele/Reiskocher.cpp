/*
´
*/

#include <iostream>
using namespace std;

class Reis
{
public:

    int kochzeit = 5;

    virtual void cook()
    {
	   do
       {
	   		cout << "Still cooking for " << kochzeit << " minutes" << endl;
	   		kochzeit--;
       } while(kochzeit > 0);
    }

    virtual ~Reis() {}
};

class Wildreis : public Reis
{
public:

    int kochzeit = 10;

	void cook() override
    {
        Reis::kochzeit = 5;
        Reis::cook();

        int abkuehlen = 0;

        cout << "Wie lange soll der Reis abkuehlen? ";
        cin >> abkuehlen;

        while (abkuehlen > 0)
        {
            cout << "Cooling for " << abkuehlen << " minutes" << endl;
            abkuehlen--;
        }
		cout << "Wildreis ist fertig gekocht" << endl;
    }

    virtual ~Wildreis() {}
};


class Sushireis : public Reis
{
public:

    int kochzeit = 5;

    void cook() override
    {
        Reis::kochzeit = 5;
        Reis::cook();
        cout << "Sushireis ist fertig gekocht" << endl;
    }

    virtual ~Sushireis() {}
};


Reis* chooseRice()
{
    int auswahl = 0;

    cout << "Bitte waehle den Reis (1 Sushireis, 2 Wildreis): ";
    cin >> auswahl;

    if (auswahl == 1)
    {
        return new Sushireis;
    }
	
	return new Wildreis;
}

int main()
{
    while (true)
    {
        Reis* w = chooseRice();
        w->cook();
        delete(w);
    }

    return 0;
}

