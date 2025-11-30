/*
QUEUE → FIFO
STACK → LIFO

Dieses Programm implementiert eine einfache Queue (Warteschlange) mit Hilfe
einer einfach verketteten Liste. Eine Queue arbeitet nach dem FIFO-Prinzip
(First In, First Out): Das zuerst eingefügte Element wird auch als erstes
entfernt.

Funktionsweise:
- Einfügen (enqueue): Neues Element wird am Ende der Liste angehängt.
- Entfernen (dequeue): Das vorderste Element wird gelöscht, und der
  Zeiger "front" wandert zum nächsten Element.
- "front" zeigt immer auf das erste Element der Queue,
  "rear" zeigt immer auf das letzte Element.

Warum eine Queue?
Queues werden genutzt, wenn eine Reihenfolge wichtig ist – z.B. bei:
- Druckaufträgen
- Aufgabenplanung
- Puffern von Datenströmen
- Simulation von Warteschlangen oder Ereignisverarbeitung

Dieses Programm demonstriert:
1. Das Einfügen mehrerer Werte in eine Queue.
2. Das Entfernen des ersten Elements.
3. Das Ausgeben aller Elemente.
*/

#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enque(int x)
{
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;

    if (front == NULL && rear == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void deque1() //Die Funktion existiert, aber der Fehler "deque is ambiguous" kommt NICHT, weil sie fehlt – sondern weil der Name deque mit std::deque kollidiert.
{
    Node* temp;
    temp = front;

    if (temp == NULL && rear == NULL)
    {
        cout << "Empty queue" << endl;
        return;
    }

    front = front->next;
    delete temp;
}

void printqueue()
{
    if (front == NULL && rear == NULL)
    {
        cout << "Empty queue" << endl;
        return;
    }

    Node* temp = front;

    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{
    enque(5);
    enque(6);
    enque(7);
    enque(8);
    printqueue();

    std::cout << "\nNach Dequeue: " << std::endl;
    deque1();
    printqueue();

    return 0;
}
