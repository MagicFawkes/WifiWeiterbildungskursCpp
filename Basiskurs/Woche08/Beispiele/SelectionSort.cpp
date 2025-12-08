
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


/* Umsetzung von Trainer

int main()
{
    vector<int> a = { 5,1,8,2 };


    int n = a.size(); // 10

    int temp = 0;
    int minimum = 0;
    int index = 0;


    for (int i = 0; i < n; i++)
    {
        minimum = a[i];

        for (int k = i + 1; k < n; k++)
        {
            if (a[k] < minimum)
            {
                minimum = a[k];
                index = k;
            }
        }

        temp = a[i];
        a[i] = a[index];
        a[index] = temp;
    }


    for (int x : a) {
        cout << x << endl;
    }
}

*/