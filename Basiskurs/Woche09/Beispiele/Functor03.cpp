#include <iostream>
#include <vector>
#include <algorithm>

// std::sort hat zwei Modi:
//
// 1) Ohne Comparator:
//    std::sort(begin, end)
//    → verwendet operator< des Typs (a < b)
//
// 2) Mit Comparator:
//    std::sort(begin, end, comp)
//    → verwendet ausschließlich comp(a, b)
//    → dafür muss comp operator() besitzen
//
// Direkte Vergleichsoperatoren (<, >, ==) werden von std::sort
// NUR im ersten Fall benutzt. operator> wird von std::sort nie verwendet.
// std::sort(v.begin(), v.end());        // → benutzt operator<
// std::sort(v.begin(), v.end(), comp);  // → benutzt operator()
// std::sort mit Comparator (3. Parameter):
// std::sort(begin, end, comp)
// → verwendet IMMER comp(a, b)
// → hier also Person::operator()(const Person&, const Person&)
// → operator< wird in diesem Fall NICHT benutzt
// operator< wird nur verwendet bei:
// std::sort(begin, end)  // ohne Comparator
// Wenn du operator< nicht definierst, dann funktioniert std::sort ohne 3. Parameter nicht.

struct Person {
    std::string name;
    int alter;
    float gehalt;

    bool operator<(const Person& a) const 
	{
        return alter < a.alter;
    }

    // Der Comparator vergleicht nur (liefert true/false).
	// Übergabe per Wert oder Referenz betrifft NUR den Vergleich.
	// std::sort selbst vertauscht immer die echten Elemente im Container.
    // Referenz hat nur den Vorteil, dass keine Kopien gemacht werden müssen, wirkt sich aber nciht auf das sortieren aus.
    // Referenzen vermeiden Kopien beim Vergleichen.
	// Das eigentliche Sortieren der Elemente beeinflusst das nicht.
    bool operator()(const Person& a, const Person& b) const 
	{
        return a.alter < b.alter;
    }
};

int main()
{
    std::vector<Person> personen = {
        {"Anna",32,2550},
        {"bob",25,3500},
        {"Clara",40,2900}
    };

    std::sort(personen.begin(), personen.end(), Person());

    for (Person value : personen)
        std::cout << value.name << "\n";
}
