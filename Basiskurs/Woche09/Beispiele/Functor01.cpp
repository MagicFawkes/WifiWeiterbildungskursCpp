/*

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Number {
private:
    int n;
public:
    int operator()(int input)
    {
        n = input;
        return n;
    }
    int operator()(int input1, int input2)
    {
        return n + input1 + input2;
    }
};

struct Person {
    std::string name;
    int alter;
    float gehalt;

    bool operator<(const Person& a) const {
        return alter < a.alter;
    }

    bool operator()(const Person& a, const Person& b) const {
        return a.alter < b.alter;
    }


};

struct VergleicheGehalt {
    bool operator()(const Person& a, const Person& b) const {
        return a.gehalt < b.gehalt;
    }
};

int main()
{
    Number n;
    n(10);

    n(10, 20);

    std::vector<Person> personen = {
        {"Anna",32,2550},
        {"bob",25,3500},
        {"Clara",40,2900}
    };

    std::sort(personen.begin(), personen.end(), VergleicheGehalt());

    std::for_each(personen.begin(), personen.end(), [](Person p) {
        cout << p.gehalt << endl;
        });
}
