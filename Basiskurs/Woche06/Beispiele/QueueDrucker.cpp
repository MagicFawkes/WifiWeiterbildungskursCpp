/*
QUEUE → FIFO
STACK → LIFO
*/

#include <iostream>

using namespace std;

enum Farbe
{
    COLOR,
    SW,
};

class Aufgabe
{
public:
    string data;
    Farbe color;
    std::shared_ptr<Aufgabe> next;

    Aufgabe(string value, Farbe color) : data(value), color(color), next(nullptr)
    {
    }
};

class DruckerQueue
{
private:
    std::shared_ptr<Aufgabe> head = nullptr;   // erstes Element (front)
    std::shared_ptr<Aufgabe> tail = nullptr;   // letztes Element (rear)
    std::size_t count = 0;                  // optional: Anzahl der Elemente

public:
    void enqueue(string data, Farbe color)
    {
        std::shared_ptr<Aufgabe> newNode = std::make_shared<Aufgabe>(data, color);
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

    std::shared_ptr<Aufgabe> dequeue()
    {
        std::shared_ptr<Aufgabe> tmp = head;

        if (tmp == nullptr)
        {
            std::cout << "Empty queue" << endl;
            return 0;
        }
        count--;

        head = head->next;

        return tmp;
    }

    void display()
    {
        if (head == nullptr && tail == nullptr)
        {
            std::cout << "Empty queue" << endl;
            return;
        }

        std::shared_ptr<Aufgabe> tmp = head;

        while (tmp != nullptr)
        {
            std::cout << "Daten wert: " << tmp->data << endl;
            std::cout << "Farbe wert: " << tmp->color << endl;
            tmp = tmp->next;
        }
    }
};

int main()
{
    DruckerQueue queue;
    queue.enqueue("Text1", SW);
    queue.enqueue("Text2", COLOR);
    queue.display();
}
