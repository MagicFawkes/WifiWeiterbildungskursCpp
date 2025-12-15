/*
 *
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(const vector<int>& v)
{
    cout << "------------------\n";
    for (int value : v) cout << value << "\n";
}

// ---------- Functors ----------
struct SquareFunctor {
    int operator()(int x) const { return x * x; }
};

struct IsEven {
    bool operator()(int x) const { return x % 2 == 0; }
};

struct Descending {
    bool operator()(int a, int b) const { return a > b; }
};

// Apply mit Template (besser als std::function, kein Overhead)
template <typename Op>
void Apply(vector<int>& v, Op op)
{
    transform(v.begin(), v.end(), v.begin(), op);
}

int main()
{
    vector<int> Values{ 1,2,3,4,5,6 };

    print(Values);

    // Functor statt Lambda: x*x
    Apply(Values, SquareFunctor{});
    print(Values);

    // Remove_if mit Functor statt Lambda: gerade Zahlen entfernen
    Values.erase(
        remove_if(Values.begin(), Values.end(), IsEven{}),
        Values.end()
    );
    print(Values);

    // Sort Descending mit Functor statt Lambda
    sort(Values.begin(), Values.end(), Descending{});
    print(Values);

    // Sort ascending (standard)
    sort(Values.begin(), Values.end());
    print(Values);
}
