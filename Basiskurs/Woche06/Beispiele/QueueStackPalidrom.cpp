/*
QUEUE → FIFO
STACK → LIFO
    Dieses Programm prüft, ob ein eingegebenes Wort ein Palindrom ist.
    Ein Palindrom ist ein Wort, das vorwärts und rückwärts gelesen gleich ist
    (z. B. "otto", "racecar").

    Funktionsweise:
    ----------------
    Das Programm verwendet zwei Datenstrukturen:
    - QUEUE  (First In – First Out / FIFO)
    - STACK  (Last In – First Out / LIFO)

    Ablauf:
    1. Der Benutzer gibt ein Wort ein.
    2. Jeder Buchstabe wird nacheinander sowohl in eine Queue als auch auf einen Stack eingefügt.
       - In der Queue kommt der erste Buchstabe auch als erster wieder heraus.
       - Im Stack kommt der letzte eingefügte Buchstabe als erster wieder heraus.
    3. Danach werden die Elemente der Queue und des Stacks verglichen.
       - Da die Queue die Zeichen in Eingabereihenfolge zurückgibt
       - und der Stack sie in umgekehrter Reihenfolge ausgibt,
         kann man so feststellen, ob das Wort ein Palindrom ist.
    4. Stimmen alle Zeichen überein → es ist ein Palindrom.

    Informationen zur Queue:
    -------------------------
    Eine Queue ist eine Datenstruktur nach dem FIFO-Prinzip.
    Das bedeutet:
        - enqueue(x): fügt ein Element hinten an
        - dequeue(): entfernt das vorderste Element
    Man benutzt sie, wenn Elemente in der Reihenfolge verarbeitet werden sollen,
    in der sie ankommen (z. B. Warteschlangen, Aufgabenverwaltung, Druckerspooler).

    Hinweis:
    --------
    Im else-Zweig wird fälschlicherweise auch "Palindrom" ausgegeben.
    Dort müsste "Kein Palindrom" stehen.
*/

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    string text;
    cout << "Enter a word: ";
    cin >> text;

    int n = text.size();

    char* queue = new char[n];
    char* stack = new char[n];

    queue[n - 1] = '\0';
    stack[n - 1] = '\0';

    int qfront = -1, qrear = -1;
    int top = -1;

    bool palindrom = true;

    for (int i = 0; i < n; i++)
    {
        queue[++qrear] = text[i]; //enqueue
        stack[++top] = text[i]; //top
    }

    for (int i = 0; i < n; i++)
    {
        if (queue[++qfront] != stack[top--]) //pop
        {
            palindrom = false;
            break;
        }
    }

    if (palindrom)
        cout << "Palindrom" << endl;
    else
        cout << "kein Palindrom" << endl;

    delete[] queue;
    delete[] stack;
}
