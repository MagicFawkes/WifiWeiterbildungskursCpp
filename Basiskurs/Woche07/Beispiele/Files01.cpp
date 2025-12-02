
#include <iostream>
#include <fstream>
#include <string>

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

    file.clear();              // EOF-Flag löschen
    file.seekg(0, ios::beg);   // Dateizeiger auf Anfang setzen

    string word;
    
    while (file >> word)
        cout << word << std::endl;;

    file.clear();              // EOF-Flag löschen
    file.seekg(0, ios::beg);   // Dateizeiger auf Anfang setzen

    string line;

    while (getline(file, line))
    {
        cout << line << std::endl;;
    }

    file.close();

    return 0;
}
