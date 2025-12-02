
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream file("Testfile01.txt"); // Ausgabestream (output file stream, of) in C++.

    if (!file.is_open()) // file.fail()
    {
        cout << "Could not open the file" << endl;
        return 1;
    }

    string words[] = { "Hello", "World", "Cpp", "Test" };

    // 1. Variante
    for (string variable : words)
    {
        file << variable << " ";
    }

    int size = sizeof(words) / sizeof(words[0]);
    // 2. Variante
    for (int i = 0; i < size; ++i)
    {
        file << words[i] << " ";
    }

    // 3. Variante
    for (int i = 0; i < size; ++i)
    {
	    for (char ch : words[i])
	    {
            file.put(ch);
	    }
    }

    file.close();

    return 0;
}
