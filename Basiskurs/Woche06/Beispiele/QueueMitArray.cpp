/*
    Dieses Programm implementiert eine einfache lineare Queue (Warteschlange)
    mithilfe eines statischen Arrays der Größe N. Eine Queue arbeitet nach dem
    FIFO-Prinzip ("First In, First Out"): Das zuerst eingefügte Element wird
    auch als erstes wieder entfernt.

    Wichtige Elemente der Implementierung:
    --------------------------------------
    - Das Array 'queue[N]' dient als Speicher für die Werte.
    - 'front' zeigt immer auf das nächste Element, das per dequeue() entfernt
      und ausgegeben wird.
    - 'rear' zeigt auf das zuletzt eingefügte Element.

    Funktionsweise:
    ---------------
    - enque(x): Fügt ein Element hinten in die Queue ein. Wenn 'rear' das Ende
      des Arrays erreicht hat, wird ein Overflow gemeldet.
    - dequeue(): Entfernt das Element an der Position 'front'. Wenn Queue leer
      ist, wird 'Empty' ausgegeben. Wenn nach dem Entfernen kein Element mehr
      vorhanden ist, werden 'front' und 'rear' wieder auf -1 gesetzt.
    - display(): Gibt alle Elemente zwischen 'front' und 'rear' aus.

    Hinweise:
    ---------
    - Diese Implementierung ist eine einfache lineare Queue, KEINE zirkuläre Queue.
    - Sie verschwendet Speicher, wenn Elemente vorne entfernt werden, da der
      freigewordene Platz nicht erneut genutzt wird.
    - Für produktive Anwendungen wäre eine Circular Queue sinnvoller.
*/


#include <iostream>

using namespace std;

#define N 10
int queue[N];
int front = -1; //zeigt auf das nächst zu popende Element
int rear = -1; //zeigt auf das letzte Element

void enque(int x)
{
    if (rear == N - 1) {
        cout << "Overflow" << endl;
    }
    else if (front == -1 && rear == -1)
    {
        front++;
        queue[++rear] = x; //als präfix

    }
    else
    {
        queue[++rear];
    }
}

int dequeue()
{
    if (front == -1 && rear == -1) {
        cout << "Empty" << endl;
        return -1;
    }
    else if (front == rear)
    {
        cout << queue[front] << endl;
        front = -1;
        rear = -1;
    }
    else
    {
        cout << queue[front] << endl;
        front++;
    }

    return queue[front];
}

void display()
{
    if (front == -1 && rear == -1) {
        cout << "Empty" << endl;
        return;
    }

    for (int i = front; i < rear; i++)
    {
        cout << queue[i] << endl;
    }

}


int main()
{

}