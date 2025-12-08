
/*

*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> a = { 4, -2, 7, 0, 10, 1, -5, 6, 2, 5 };

    int n = a.size();

    for (int i = 0; i < n; i++)
    {
        int tempIndex = i;

        for (int k = i+1; k < n; k++) 
        {
            if (a[k] < a[tempIndex])
            {
                tempIndex = k;
            }
        }

        swap(a[i], a[tempIndex]);
    }

    cout << "\nSortiertes Array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
    return 0;
}
