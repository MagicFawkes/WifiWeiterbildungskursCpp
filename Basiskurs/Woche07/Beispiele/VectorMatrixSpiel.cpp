/*


 */

#include <iostream>
#include <string>
#include <vector>

int main()
{
    class Position
    {
    public:
        int x = 0;
        int y = 0;
    };

    std::vector<std::vector<char>> spielematrix = 
    {
    {'x', 'x', 'x'},
    {'x', 'x', 'x'},
    {'x', 'x', 'x'}
    };

    size_t zeilen = spielematrix.size();
    size_t spalten = spielematrix[0].size();

    Position positionAkt, posEingabe;
    posEingabe = positionAkt;

    while (true)
    {
        char eingabe;
        std::cout << "Bitte nächsten Schritt eingeben (W->Up, A->left, S->down, D->reicht): ";
        std::cin >> eingabe;

        if (eingabe == 'w')
        {
            posEingabe.y += 1;
        }
        else if (eingabe == 's')
        {
            posEingabe.y -= 1;
        }
        else if (eingabe == 'a')
        {
            posEingabe.x -= 1;
        }
        else if (eingabe == 'd')
        {
            posEingabe.x += 1;
        }
        else
        {
            std::cout << "Falsche Eingabe, bitte korrekt eingeben!" << std::endl;
        }
    }


    return 0;
}