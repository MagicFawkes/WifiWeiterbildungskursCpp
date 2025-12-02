
/*


 */

#include <iostream>
#include <string>
#include <vector>



int main()
{
    std::vector<std::vector<int>> vect;

    std::vector<int> vect1 = { 1, 2, 3 };
    std::vector<int> vect2 = { 4, 5, 6 };
    std::vector<int> vect3 = { 7, 8, 9 };

    vect.push_back(vect1);
    vect.push_back(vect2);
    vect.push_back(vect3);


    for (auto it1 = vect.begin(); it1 != vect.end(); it1++)
    {
        cout << *it << endl;
    }

    return 0;
}