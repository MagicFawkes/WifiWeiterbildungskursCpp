
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
        for (int k = i+1; k < n; k++) 
        {
            if (a[i] > a[k])
            {
	            for (int x = k; x > i; --x)
	            {
                    swap(a[x], a[x-1]);
	            }
                break;
            }
        }
    }

    cout << "\nInsertion Sort: Sortiertes Array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
    return 0;
}