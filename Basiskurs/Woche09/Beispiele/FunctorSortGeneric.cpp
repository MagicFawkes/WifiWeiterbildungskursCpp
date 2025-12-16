#include <iostream>
#include <vector>
#include <algorithm>



struct Person 
{
    std::string name;
    int alter;
    float gehalt;

    bool operator<(const Person& a) const
    {
        return alter < a.alter;
    }

    bool operator>(const Person& a) const
    {
        return alter > a.alter;
    }

    bool operator()(const Person& a, const Person& b) const
    {
        return a.alter < b.alter;
    }
};

/*
 *dann passiert Folgendes:

T ist Person
T comp; erzeugt ein Person-Objekt
comp(a, b) ruft Person::operator() auf
➡️ operator< kommt hier NIE zum Einsatz, weil du ihn gar nicht verwendest.
// operator() wird aufgerufen, weil ein Person-Objekt als Funktionsobjekt (comp(a,b)) verwendet wird und nicht der <-Operator (a < b).
*/

template<typename T, typename Compare>
void bubblesort(std::vector<T>& v, Compare comp)
{
    for (size_t i = 0; i < v.size(); ++i)
        for (size_t j = 0; j + 1 < v.size() - i; ++j)
            if (comp(v[j + 1], v[j]))       //es wird wie eine Funktion aufgerufen comp(a,b) daher wird Operator () verwendet
                std::swap(v[j], v[j + 1]);
}

//Funktion überladen damit der < oder > operator inder Klasse Person auch verwendet werden kann
template<typename T>
void bubblesort(std::vector<T>& v)
{
    for (size_t i = 0; i < v.size(); ++i)
        for (size_t j = 0; j + 1 < v.size() - i; ++j)
            if (v[j + 1] < v[j])       //es wird wie eine Funktion aufgerufen comp(a,b) daher wird Operator <()> verwendet
                std::swap(v[j], v[j + 1]);
}

int main()
{
    std::vector<Person> personen = {
        {"Anna",32,2550},
        {"bob",25,3500},
        {"Clara",40,2900}
    };

    // Operator () wird verwendet, da intern in Bubble Sort das Objekt als Funktion aufgerufen wird also comp()
    bubblesort(personen, Person());
    
    // Operator < oder > wird verwendet, Template überladen
	bubblesort(personen);

    // Mit Lambda Funktion alles durchlaufen
    std::for_each(personen.begin(), personen.end(), [](const Person& p)->void {
	    std::cout << p.alter << std::endl;
        });
}
