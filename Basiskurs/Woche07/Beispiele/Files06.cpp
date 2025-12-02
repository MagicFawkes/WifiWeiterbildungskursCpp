
/*
 *file hast du zahlen, zahlen in queue linked list
 */

#include <fstream>
#include <iostream>
#include <string>

using namespace std;



int main()
{
    ifstream file("Zahlenwerte.txt"); // lesen

    if (!file.is_open()) // file.fail()
    {
        cout << "Could not open the file" << endl;
        return 1;
    }



    return 0;
}