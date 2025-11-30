/*
Dieses Beispiel implementiert eine einfache Queue (Warteschlange) mit einem statischen Array
der Größe N = 10. Eine Queue ist eine FIFO-Datenstruktur (First In – First Out), bei der Elemente
hinten eingefügt (enqueue) und vorne entnommen (dequeue) werden.

Funktionsweise:
- 'front' zeigt auf das nächste Element, das entfernt wird.
- 'rear' zeigt auf das letzte eingefügte Element.
- Bei enqueue(x) wird das neue Element hinten angehängt.
- Bei dequeue() wird das Element vorne entfernt und zurückgegeben.

Problem dieser Implementierung:
Die Queue wächst im Array immer weiter nach rechts, da 'rear' nur erhöht wird.
Wenn vorne Elemente entfernt werden, entstehen zwar freie Plätze, aber diese werden
nicht wiederverwendet. Das Array kann daher "voll" werden, obwohl logisch gesehen noch
Platz wäre.

Die korrekte Lösung wäre ein Ringpuffer (circular queue), bei dem sich front und rear
zyklisch im Array bewegen.

Dieses Programm zeigt das Einfügen mehrerer Elemente, das Entfernen eines Elements
und das anschließende weitere Einfügen, wodurch das beschriebene Problem sichtbar wird.
*/


#include <iostream>

using namespace std;

#define N 10

class Queue
{
private:
    int queue[N] = {};
    int front = -1; // zeigt auf das nächst zu popende Element
    int rear = -1; // zeigt auf das letzte Element

public:
    void enque(int x)
    {
        if (rear == N - 1)
        {
            cout << "Overflow" << endl;
        }
        else if (front == -1 && rear == -1)
        {
            // Queue war leer, erstes Element
            front++;
            queue[++rear] = x; // rear von -1 -> 0, front von -1 -> 0
        }
        else
        {
            // normal hinten anhängen
            queue[++rear] = x;
        }
    }

    int dequeue()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Empty" << endl;
            return -1;
        }

        // Wert sichern, der entfernt wird
        int value = queue[front];

        if (front == rear)
        {
            // es war das letzte Element
            front = -1;
            rear = -1;
        }
        else
        {
            // es gibt noch weitere Elemente
            front++;
        }

        return value; // das entfernte Element zurückgeben
    }

    void display()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Empty" << endl;
            return;
        }

        for (int i = front; i <= rear; i++) // <= statt <
        {
            cout << queue[i] << endl;
        }
    }
};

int main()
{
    Queue queue;
    queue.enque(10);
    queue.enque(20);
    queue.enque(30);
    queue.enque(10);
    queue.enque(20);
    queue.enque(30);
    queue.enque(10);
    queue.enque(20);
    queue.enque(30);

    cout << "Inhalt der Queue:" << endl;
    queue.display();

    cout << "dequeue(): " << queue.dequeue() << endl;

    cout << "Nach dequeue():" << endl;
    queue.display();

    queue.enque(30);
    queue.enque(10);
    queue.enque(20);
    queue.enque(30);

    return 0;
}
