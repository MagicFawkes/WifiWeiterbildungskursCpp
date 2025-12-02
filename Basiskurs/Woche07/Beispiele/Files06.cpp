
/*
 *file hast du zahlen, Zahlen einlesen, zahlen in queue linked list speichern und danach ausgebenS
 */

#include <fstream>
#include <iostream>
#include <string>

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
    ifstream file("Zahlenwerte.txt"); // lesen

    if (!file.is_open()) // file.fail()
    {
        cout << "Could not open the file" << endl;
        return 1;
    }

    int wert;

    while (file >> wert)
    {
        enque(wert);
    }

    printqueue();

    return 0;
}