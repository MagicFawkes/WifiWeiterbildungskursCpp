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

    bool operator()(const Person& a, const Person& b) const
    {
        return a.alter < b.alter;
    }
};

template<typename T>
void bubblesort(std::vector<T>& arr, bool(*ptr)(T, T))
{
    for (int i = 0; i < arr.size(); i++) {
        for (int k = 0; k < arr.size() - 1 - i; k++) {
            if (ptr(arr[k], arr[k + 1]))
            {
                int temp = 0;
                arr[k] = arr[k + 1];
                arr[k + 1] = temp;
            }
        }
    }
}

int main()
{
    std::vector<Person> personen = {
        {"Anna",32,2550},
        {"bob",25,3500},
        {"Clara",40,2900}
    };

    bubblesort(personen, Person());

    // Mit Lambda Funktion alles durchlaufen
    std::for_each(personen.begin(), personen.end(), [](const Person& p)->void {
	    std::cout << p.gehalt << std::endl;
        });
}
