/*
´
*/

#include <iostream>

using namespace std;

class Reis
{
protected:
	int kochzeit = 7;

public:
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
protected:
    int kochzeit = 12;

public:

	void cook() override
    {
        Reis::kochzeit = this->kochzeit;
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

    ~Wildreis() override = default;
};


class Sushireis : public Reis
{
protected:
    int kochzeit = 9;

public:

    void cook() override
    {
        Reis::kochzeit = this->kochzeit;
        Reis::cook();
        cout << "Sushireis ist fertig gekocht" << endl;
    }

	 ~Sushireis() override = default;
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

class Cooker
{
    Reis* reis = NULL;

public:
    void chooseRice()
    {
        if (reis == NULL)
        {
            int auswahl = 0;

            cout << "Bitte waehle den Reis (1 Sushireis, 2 Wildreis, 3 Reis): " << endl;
            cin >> auswahl;

            if (auswahl == 1)
            {
                this->reis = new Sushireis;
            }
            else if (auswahl ==2)
            {
                this->reis = new Wildreis;
            }
            else
            {
                this->reis = new Reis;
            }
        }
        else
        {
            cout << "Reis wurde bereits ausgewaehlt" << endl;
        }
    }

    void cookRice()
    {
        if (reis == NULL)
        {
            cout << "Es wurde kein Reis ausgewaehlt" << endl;
        }
        else
        {
            reis->cook();
        }
    }

    ~Cooker()
    {
        delete reis;
    }
}; 

int main()
{
    Cooker cooker;
    cooker.cookRice();
    cooker.chooseRice();
    cooker.chooseRice();
    cooker.cookRice();

    return 0;
}

