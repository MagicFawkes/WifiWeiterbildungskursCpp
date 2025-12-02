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

    //oder:
    /*std::vector<std::vector<int>> vect = 
    {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
    };*/

    for (auto it1 = vect.begin(); it1 != vect.end(); it1++)
    {
        for (auto it2 = it1->begin(); it2 != it1->end(); it2++)
        {
            std::cout << *it2 << std::endl;
        }
    }

    // Kurz & modern mit range - based for
    for (const auto& row: vect) 
    {
        for (int value : row) 
        {
	        std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}