/*


 */

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

class Position
{
public:
    int x = 1;
    int y = 0;
};

void spielfeldAnzeigen(std::vector<std::vector<char>> summenmatrix, Position pos)
{
    system("cls");
    std::cout << '\n';
    summenmatrix[pos.y][pos.x] = 'O';

    for (auto row : summenmatrix)
    {
        for (auto value : row)
        {
            std::cout << value << "    ";
        }
        std::cout << std::endl;
    }
    std::cout << '\n';
}

int main()
{
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

    spielfeldAnzeigen(spielematrix, posEingabe);

    while (true)
    {
        char eingabe;
        std::cout << "Bitte nächsten Schritt eingeben (W->up, A->left, S->down, D->right): ";
        eingabe = _getch();

        switch (eingabe)
        {
        case 'w':
            posEingabe.y -= 1;
            break;

        case 's':
            posEingabe.y += 1;
            break;

        case 'a':
            posEingabe.x -= 1;
            break;

        case 'd':
            posEingabe.x += 1;
            break;

        default:
            std::cout << "Falsche Eingabe, bitte korrekt eingeben!" << std::endl;
            continue;
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

        spielfeldAnzeigen(spielematrix, posEingabe);
        std::cout << "Erfolgreichr Zug - " << "Zeile: " << posEingabe.y << " Spalte: " << posEingabe.x << std::endl;
        positionAkt = posEingabe;
    }

    return 0;
}