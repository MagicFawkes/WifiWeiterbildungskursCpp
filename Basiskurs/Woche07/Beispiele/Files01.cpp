
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream file("Aufgabe01.txt"); // lesen

    if (!file.is_open()) // file.fail()
    {
        cout << "Could not open the file" << endl;
        return 1;
    }

    char c;

    while (file.get(c))
    {
        cout << c;
    }

    file.close();

    return 0;
}
