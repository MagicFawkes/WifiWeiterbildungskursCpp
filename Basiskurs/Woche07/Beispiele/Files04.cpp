
#include <iostream>
#include <fstream>

using namespace std;

template <typename T, int N>
class Array
{
public:
    T words[N];
    int anzahl = 0;
};

int main()
{
    fstream file("Datei1.txt", ios::in | ios::out); // Ausgabestream (output file stream, of) in C++.

    if (!file.is_open()) // file.fail()
    {
        cout << "Could not open the file" << endl;
        return 1;
    }

    constexpr int m = 100;

    Array<string, m> test;

    while (file >> test.words[test.anzahl])
    {
        if (test.anzahl == 99)
            break;
        test.anzahl++;
    }

	//for (each) gibt das gesamte Array aus, auch wenn nichts sinnvoles mehr darin steht, es sind 100 Plätze reserviert
    /*for (string variable : test.words)
    {
        std::cout << variable << std::endl;
        file << variable << " ";
    }*/

    for (int i = 0; i < test.anzahl; ++i)
    {
        std::cout << test.words[i] << std::endl;
        file << test.words[i] << " ";
    }

    return 0;
}
