/*

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    vector<int> a = { 1,2,3,4,5 };

    int summ = 0;

    std::for_each(a.begin(), a.end(), [&summ](int x)
        {
            summ = summ + x;
        });

    cout << summ << endl;
}

