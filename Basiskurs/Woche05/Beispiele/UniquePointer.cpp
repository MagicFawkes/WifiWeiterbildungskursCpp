/*
RAII („Resource Acquisition Is Initialization“) bedeutet, dass eine Ressource genau dann erworben wird, wenn ein Objekt erzeugt wird – und automatisch wieder freigegeben wird, wenn das Objekt den Gültigkeitsbereich verlässt. Dadurch entstehen keine Speicherlecks, weil die Freigabe garantiert im Destruktor passiert.

Ein std::unique_ptr ist ein RAII-Smartpointer, der alleinigen Besitz eines Objekts hat.
Sobald der unique_ptr zerstört wird, wird automatisch auch das verwaltete Objekt gelöscht (delete).
Dadurch muss der Entwickler niemals selbst delete aufrufen, und die Ressource ist sicher an die Lebensdauer des Smartpointers gebunden.

Kurz:
RAII sorgt dafür, dass Ressourcen automatisch verwaltet werden, und unique_ptr ist ein praktisches Werkzeug, um dynamisch erzeugte Objekte sicher zu besitzen.



std::shared_ptr – kurze Erklärung

Ein std::shared_ptr ist ein Smartpointer, der gemeinsamen Besitz eines Objekts ermöglicht.
Mehrere shared_ptr können auf dasselbe Objekt zeigen. Intern wird ein Referenzzähler verwendet, der mitzählt, wie viele shared_ptr gerade auf das Objekt verweisen.

Sobald der letzte shared_ptr das Objekt nicht mehr braucht (d.h. der Referenzzähler auf 0 geht), wird das Objekt automatisch gelöscht.
So wird Speicher sicher freigegeben, selbst wenn viele Teile des Programms sich dieses Objekt teilen.

Kurz:
shared_ptr ermöglicht gemeinsames Eigentum und kümmert sich selbst darum, das Objekt erst dann zu löschen, wenn niemand es mehr benutzt.



std::weak_ptr – kurze Erklärung

Ein std::weak_ptr ist ein nicht-besitzender Smartpointer, der auf ein Objekt zeigt, das von einem std::shared_ptr verwaltet wird.
Wichtig: Ein weak_ptr erhöht den Referenzzähler nicht und besitzt das Objekt nicht.

Damit verhindert er Zyklische Referenzen (z. B. wenn zwei Objekte sich gegenseitig mit shared_ptr halten würden und niemals gelöscht werden könnten).

Ein weak_ptr kann jederzeit prüfen, ob das Objekt noch existiert (expired()), und es bei Bedarf temporär in einen shared_ptr umwandeln (lock()).

Kurz:
weak_ptr beobachtet ein Objekt, ohne es zu besitzen — ideal, um Speicherlecks durch shared_ptr-Zyklen zu vermeiden.

Ein weak_ptr verwendet man, um ein Objekt beobachten zu können, ohne dessen Lebensdauer zu verlängern, und damit Zyklische Referenzen bei shared_ptr zu verhindern.
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

    shared_ptr<test> shardePtr = make_shared<test>();
    shardePtr->print();

    {
        cout << "\n" << shardePtr.use_count();
        shared_ptr<test> shardePtr1 = shardePtr;
        cout << "\n" << shardePtr.use_count();
        cout << "\n" << shardePtr1.use_count();
    }

    cout << "\n" << shardePtr.use_count();

    weak_ptr<test> weakPtr = make_shared<test>();       //falsch
    cout << weakPtr.expired() << endl;   // sehr wahrscheinlich: 1 (true)
    /*
     *✅ Warum kompiliert das?

	make_shared<test>() gibt einen temporären shared_ptr<test> zurück.

	Für weak_ptr<T> gibt es einen Konstruktor, der einen shared_ptr<T> annimmt.
	→ Deshalb ist die Zuweisung sprachlich gültig und der Compiler meckert nicht.

	ABER:
	Der temporäre shared_ptr lebt nur in dieser Zeile.
	Direkt nach der Initialisierung von weakPtr wird der temporäre shared_ptr zerstört → das Objekt wird gelöscht → der weakPtr zeigt nur noch auf etwas, das nicht mehr existiert.
	*/

    shared_ptr<test> sharedPtr = make_shared<test>();
    weak_ptr<test> weakPtr2 = sharedPtr;  // korrekt

	return 0;
}
