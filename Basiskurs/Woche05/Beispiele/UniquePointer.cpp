/*
RAII („Resource Acquisition Is Initialization“) bedeutet, dass eine Ressource genau dann erworben wird, wenn ein Objekt erzeugt wird – und automatisch wieder freigegeben wird, wenn das Objekt den Gültigkeitsbereich verlässt. Dadurch entstehen keine Speicherlecks, weil die Freigabe garantiert im Destruktor passiert.

Ein std::unique_ptr ist ein RAII-Smartpointer, der alleinigen Besitz eines Objekts hat.
Sobald der unique_ptr zerstört wird, wird automatisch auch das verwaltete Objekt gelöscht (delete).
Dadurch muss der Entwickler niemals selbst delete aufrufen, und die Ressource ist sicher an die Lebensdauer des Smartpointers gebunden.

Kurz:
RAII sorgt dafür, dass Ressourcen automatisch verwaltet werden, und unique_ptr ist ein praktisches Werkzeug, um dynamisch erzeugte Objekte sicher zu besitzen.


*/

#include <iostream>

using namespace std;

class test
{
public:
    void print()
    {
        cout << "\nPrint Methode";
    }

    test()
    {
        cout << "\nKonsturktor";
    }

    ~test()
    {
        cout << "\nDestruktor";
    }
};

int main()
{
    unique_ptr<test> ptr = make_unique<test>();

    // unique_ptr<test> ptr1 = ptr;     geht nicht bei unique pointer, weil unique
    unique_ptr<test> ptr1 = move(ptr);      //Ptr übergeben mit move geht

    ptr->print();
    ptr1->print();

    return 0;
}
