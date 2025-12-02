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
        int x = 1;
        int y = 0;
    };

    std::vector<std::vector<char>> spielematrix = 
    {
    {'x', ' ', 'x', 'x'},
    {'x', ' ', ' ', ' '},
    {'x', 'x', 'x', ' '},
	{'x', ' ', ' ', ' '},
    {'x', 'z', 'x', 'x'}
    };

    size_t zeilen = spielematrix.size();
    size_t spalten = spielematrix[0].size();

    Position positionAkt, posEingabe;
    posEingabe = positionAkt;

    while (true)
    {
        char eingabe;
        std::cout << "Bitte nächsten Schritt eingeben (W->up, A->left, S->down, D->right): ";
        std::cin >> eingabe;

        if (eingabe == 'w')
        {
            posEingabe.y -= 1;
        }
        else if (eingabe == 's')
        {
            posEingabe.y += 1;
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
            continue;;
        }

    	if (posEingabe.x >= spalten || posEingabe.x < 0 || posEingabe.y >= zeilen || posEingabe.y < 0)
    	{
			std::cout << "Ausserhalb Spielfeld" << std::endl;
			posEingabe = positionAkt;

			continue;
        }

        if (spielematrix[posEingabe.y][posEingabe.x] == 'x')
        {
            std::cout << "Hindernis Entdeckt, Nochmal versuchen" << std::endl;
            posEingabe = positionAkt;

            continue;
        }
        if (spielematrix[posEingabe.y][posEingabe.x] == 'z')
        {
            std::cout << "Ziel erreicht" << std::endl;
            break;
        }

    	std::cout << "Erfolgreichr Zug - " << "Zeile: " << posEingabe.y << " Spalte: " << posEingabe.x << std::endl;
        positionAkt = posEingabe;
    }

    return 0;
}