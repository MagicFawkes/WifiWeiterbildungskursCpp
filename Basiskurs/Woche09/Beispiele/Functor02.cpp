/*
 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Number
{
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


class funktor {
public:
    virtual void operator()(int& x) = 0;
    virtual bool operator()(int x, int y) = 0;

};

class stl :public funktor
{
public:
    void operator()(int& x) {
        x = x * x;
        return;
    } //remove
    bool operator()(int x, int y) {
        return x < y;
    }
};


int main()
{
    vector<int> a = { 2,1,10,5, 6 };

    /*std::remove_if(a.begin(), a.end(), stl());*/

    std::for_each(a.begin(), a.end(), stl());


    std::sort(a.begin(), a.end(), stl());

    std::for_each(a.begin(), a.end(), [](int x) {
        cout << x << endl;
        });
}

