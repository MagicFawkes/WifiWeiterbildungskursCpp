
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

template <typename T>
class Array
{
public:
    vector<T> arr;
};

int main()
{
    fstream file("Datei1.txt", ios::in | ios::out); // Ausgabestream (output file stream, of) in C++.

    if (!file.is_open()) // file.fail()
    {
        cout << "Could not open the file" << endl;
        return 1;
    }

    Array<string> test;

    string wert;

    while (file >> wert)
    {
        test.arr.push_back(wert);
    }

    file.clear();               // Flags zurücksetzen
    file.seekp(0, ios::end);    // Schreibpointer ans Ende

    for (string variable : test.arr)
    {
        std::cout << variable << std::endl;
        file << variable << " test";
    }

    return 0;
}
