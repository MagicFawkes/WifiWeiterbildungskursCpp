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
    std::vector<std::vector<int>> summenmatrix = 
    {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
    };

   /* for (auto itZeile = vect.begin(); itZeile != vect.end(); itZeile++)
    {
        for (auto itSpalte = itZeile->begin(); itSpalte != itZeile->end(); itSpalte++)
        {
            std::cout << "Zahl: " << *itSpalte << std::endl;
        }
    }*/

    for (int zeile = 0; zeile < vect.size(); ++zeile)
    {
        for (int spalte = 0; spalte < vect[zeile].size(); ++spalte)
        {
            std::cout << "Zahl: " << vect[zeile][spalte] << std::endl;

            int summe = 0;

            if (zeile > 0)
            {
                summe += vect[zeile - 1][spalte];
            }

            if (zeile < vect.size() - 1)
            {
                summe += vect[zeile + 1][spalte];
            }

            if (spalte > 0)
            {
                summe += vect[zeile][spalte-1];
            }

            if (spalte < vect[zeile].size() - 1)
            {
                summe += vect[zeile][spalte + 1];
            }
            
        	summenmatrix[zeile][spalte];

            std::cout << "Summe: " << summe << std::endl;
        }
    }

    // Mit range - based for
    //for (std::vector<int> row: vect)
    //{
    //    for (int value : row) 
    //    {
	   //     std::cout << value << " ";
    //    }
    //    std::cout << std::endl;
    //}

    //// oder ohe Kopie mit Referenz
    //for (const auto& row : vect)
    //{
    //    for (int value : row)
    //        std::cout << value << " ";
    //}

    return 0;
}