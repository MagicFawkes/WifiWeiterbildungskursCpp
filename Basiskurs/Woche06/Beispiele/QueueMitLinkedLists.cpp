/*
QUEUE → FIFO
STACK → LIFO
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