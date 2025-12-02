
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream file("Testfile.txt"); // lesen

    if (!file.is_open()) // file.fail()
    {
        cout << "Could not open the file" << endl;
        return 1;
    }

    char c = 'a';
    // Char schreiben in file
    file.put(c);
    
	//in File SChreiben
    file << "Hello World";
    file.close();

    return 0;
}
