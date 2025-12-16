/*

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void summ(vector<int> v, function<void(int)>f)
{
    for (int x : v) {
        f(x);
    }

}

void addiere(int* summe, int wert) {
    *summe = *summe + wert;
}

int summ(vector<int> v, void(*ptr_func)(int*, int))
{
    int summe = 0;
    for (int x : v) {
        ptr_func(&summe, x);
    }

    return summe;
}

class vectorsumm {
private:
    int& summ;
public:
    vectorsumm(int& s) : summ(s) {}

    void operator()(int x) {
        summ = summ + x;
    }

    int getSumm() const {
        return summ;
    }
};


int main()
{
    vector<int> v = { 1,2,3,4,5 };

    int summe = 0;

    auto lambda = [&summe](int x) {
        summe += x;
        };

    summ(v, lambda);

    cout << summe << endl;

    summe = 0;
    //summe = summ(v, addiere);

    summe = summ(v, [](int* summe, int x) {
        *summe = *summe + x;
        });

    cout << summe << endl;

    int summe = 0;

    vectorsumm v1(summe);
    std::for_each(v.begin(), v.end(), v1);
    cout << v1.getSumm() << endl;
}