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

    //Eine Basisklasse mit virtuellen Funktionen → sollte fast immer einen virtuellen Destruktor haben
    //unbedingt virtual angeben, sonst wird er in der abgeleiteten klasse nicht aufgerufen, wenn du polymorph verhalten brauchst
    virtual ~Reis() {}      //keinen Body angibst, erzeugt der Compiler genau dieselbe Implementierung wie bei = default. ~Sushireis() override {}
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

    ~Wildreis() override {}   //keinen Body angibst, erzeugt der Compiler genau dieselbe Implementierung wie bei = default. ~Sushireis() override {}
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

	//~Sushireis() override; //keinen Body angibst, erzeugt der Compiler genau dieselbe Implementierung wie bei = default. ~Sushireis() override {}
	//~Sushireis() override {}
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



//Umsetzung von Trainer:
//#include <iostream>
//#include <iostream>
//using namespace std;
//
//enum WAHL {
//	WILDREIS = 1, SUSHIREIS
//};
//
//class Reis
//{
//protected:
//	int kochzeit = 5;
//public:
//
//	Reis(int kochzeit) {
//		this->kochzeit = kochzeit;
//	}
//
//	virtual void cook()
//	{
//		for (int i = kochzeit; i >= 1; i--) {
//			cout << "Still cooking for " << i << endl;
//		}
//
//	}
//	virtual ~Reis() {
//		cout << "Elternklasse Reis" << endl;
//	}
//
//};
//
//class Wildreis : public Reis
//{
//public:
//	Wildreis() :Reis(10)
//	{
//
//	}
//	void cook()
//	{
//		Reis::cook();
//		cout << "Wildreis fertig gekocht" << endl;
//
//	}
//
//	~Wildreis()
//	{
//		cout << "Kindklasse Wildreis" << endl;
//	}
//
//};
//
//class sushireis :public Reis
//{
//public:
//	sushireis() :Reis(5)
//	{
//
//	}
//	void cook()
//	{
//		int kuehlzeit;
//		Reis::cook();
//		cout << "How long should it cool" << endl;
//		cin >> kuehlzeit;
//		for (int i = kuehlzeit; i >= 1; i--) {
//			cout << "cooling for " << i << "Minutes" << endl;
//		}
//	}
//	~sushireis()
//	{
//		cout << "Kindklasse Suhsireis" << endl;
//	}
//
//};
//
//class Reiskocher
//{
//private:
//	Reis* rptr = NULL;
//public:
//	void chooserice() {
//		int wahl = 0;
//		cout << "waehle eine Sorte Reis" << endl;
//		cin >> wahl;
//
//		switch (wahl)
//		{
//		case WILDREIS:
//			rptr = new Wildreis();
//			cout << "Wildreis wurde ausgewaelt" << endl;
//			break;
//		case SUSHIREIS:
//			rptr = new sushireis();
//			cout << "Wildreis wurde ausgewaelt" << endl;
//			break;
//		default:
//			cout << "nichts wurde ausgewaelt" << endl;
//			break;
//		}
//	}
//
//	void coockRice() {
//		if (rptr == NULL) {
//			cout << "kein Reis ist vorhanden" << endl;
//		}
//		rptr->cook();
//	}
//
//	~Reiskocher()
//	{
//		delete rptr;
//	}
//
//
//};
//
//
//int main()
//{
//	Reiskocher rk;
//	rk.chooserice();
//	rk.coockRice();
//
//
//}
