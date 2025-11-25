/*
Die aktuelle Queue wächst nur nach rechts im Array, weil rear immer größer wird und beim Dequeue der Platz links niemals wieder benutzt wird.
Deshalb ist das Array nach spätestens 10 Enqueues voll, auch wenn du zwischendurch Elemente entfernt hast — der frei gewordene Speicher wird nie wiederverwendet.
Lösung wäre ein Ringbuffer
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
