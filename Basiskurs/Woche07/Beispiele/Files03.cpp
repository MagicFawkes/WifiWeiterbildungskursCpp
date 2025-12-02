
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream file("Testfile01.txt"); // lesen

    if (!file.is_open()) // file.fail()
    {
        cout << "Could not open the file" << endl;
        return 1;
    }

    string words[] = {"Hello", "World", "Cpp", "Test"};

    for (string variable : words) 
    {
        file << variable << " ";
    }

    file.close();

    return 0;
}
