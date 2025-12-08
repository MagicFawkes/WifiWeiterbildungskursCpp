
/*

*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> a = { 4, -2, 7, 0, 10, 1, -5, 6, 2, 5 };

    int n = a.size();

    int temp = 0;

    for (int i = 0; i < n; i++)
    {
        for (int k = i; k < n-1; k++) 
        {
            if (a[i] > a[k + 1])
            {
                swap(a[i], a[k +1]);
            }
        }
    }

    cout << "\nSortiertes Array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }


    for (int i = 0; i < n; i++)
    {
        for (int k = i; k < n - 1; k++)
        {
            if (a[i] < a[k + 1])
            {
                swap(a[i], a[k + 1]);
            }
        }
    }

    cout << "\nSortiertes Array Rückwaerts:\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
    return 0;
}
