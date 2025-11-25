/*
QUEUE → FIFO
STACK → LIFO
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
