/*

*/

#include <iostream>
#include <vector>

using namespace std;

int summArray(vector<int> a, int n)
{
    if (n <= 0)
    {
        return 0;
    }

    return a[n - 1] + summArray(a, n - 1);
}

// summe(a, 0)

//summe(a,1)
//a[0] + summe(a,0)
//summe(a,2)
//a[1] + summe(a,1)
//summe(a,13
//a[2] + summe(a,2)
//summe(a,4)
//a[3] + summe(a,3)
//summe(a,5)
//a[4] + summe(a,4)
//summe(a,6)
//a[5] + summe(a,5)

int main()
{
    vector<int> a = { 4, -2, 7, 0, 10, 1, -5, 6, 2, 5 };

    int n = a.size();

    cout << summArray(a, n);

    cout << endl;
    return 0;
}