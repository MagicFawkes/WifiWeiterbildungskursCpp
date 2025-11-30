/*
QUEUE → FIFO
STACK → LIFO
    Dieses Programm implementiert eine einfache Queue (Warteschlange) als
    verkettete Liste unter Verwendung von std::shared_ptr für die Speicherverwaltung.

    --- Was ist eine Queue? ---
    Eine Queue ist eine FIFO-Datenstruktur (First In – First Out).
    Das bedeutet: Das Element, das zuerst eingefügt wird, wird auch zuerst wieder entfernt.
    Typische Beispiele: Druckerwarteschlangen, Tasks in Betriebssystemen, Event-Verarbeitung.

    --- Wie funktioniert diese Implementierung? ---
    • Die Queue besteht aus verketteten Knoten (Node), die jeweils einen Wert
      (data) sowie einen Zeiger auf den nächsten Knoten enthalten.
    • Die Queue speichert zwei Zeiger:
          head → zeigt auf das erste Element (Front)
          tail → zeigt auf das letzte Element (Rear)
    • enqueue(x):
          - erzeugt einen neuen Knoten
          - hängt ihn hinten (am tail) an
          - aktualisiert tail auf das neue Element
    • dequeue():
          - entfernt das erste Element (head)
          - gibt dessen Wert zurück
          - verschiebt head auf das nächste Element
          - bei leerer Queue wird eine Meldung ausgegeben
    • display():
          - iteriert über alle Elemente der Queue
          - gibt die gespeicherten Werte aus

    Durch die Verwendung von std::shared_ptr übernimmt C++ die Speicherverwaltung
    automatisch, sodass keine Gefahr von Speicherlecks besteht.
*/

#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    std::shared_ptr<Node> next;

    Node(int value) : data(value), next(nullptr)
    { }
};

class Queue
{
private:
    std::shared_ptr<Node> head = nullptr;   // erstes Element (front)
    std::shared_ptr<Node> tail = nullptr;   // letztes Element (rear)
    std::size_t count = 0;                  // optional: Anzahl der Elemente

public:
    void enqueue(int x)
    {
        std::shared_ptr<Node> newNode = std::make_shared<Node>(x);
        newNode->next = nullptr; //optional wird beim Initialiseren bereits null gesetzt
        count++;

        if (head == nullptr && tail == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int dequeue()
    {
        std::shared_ptr<Node> tmp = head;

        if (tmp == nullptr)
        {
            std::cout << "Empty queue" << endl;
            return 0;
        }

        count--;

        int wert = tmp->data;

        head = head->next;
        tmp = nullptr;

        return wert;
    }

    void display()
    {
	    if (head  == nullptr && tail == nullptr)
	    {
            std::cout << "Empty queue" << endl;
            return;
	    }

        std::shared_ptr<Node> tmp = head;

	    while (tmp != nullptr)
	    {
            std::cout << "Queue wert: " << tmp->data << endl;
            tmp = tmp->next;
	    } 
    }
};

int main()
{
    Queue queue;
    queue.enqueue(5);
    queue.enqueue(6);
    queue.enqueue(7);
    queue.enqueue(8);
    queue.display();
    std::cout << "Dequeue Wert: " << queue.dequeue() << std::endl; 
    std::cout << "Dequeue Wert: " << queue.dequeue() << std::endl;
    queue.display();
}