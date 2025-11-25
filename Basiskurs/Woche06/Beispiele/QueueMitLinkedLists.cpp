/*

*/

#include <iostream>

using namespace std;

#define N 10


class Node
{
public:
    int data;

    Node(int value) : data(value)
    {

    }
};

class Stack
{
private:
    std::shared_ptr<Node> queue[N];
    std::shared_ptr<Node> front = NULL; //zeigt auf das nächst zu popende Element
    std::shared_ptr<Node> rear = NULL; //zeigt auf das letzte Element

public:
    void enque(int x)
    {
        if (rear == N - 1) 
        {
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
        if (front == -1 && rear == -1) 
        {
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
        if (front == -1 && rear == -1) 
        {
            cout << "Empty" << endl;
            return;
        }

        for (int i = front; i < rear; i++)
        {
            cout << queue[i] << endl;
        }
    }
};

int main()
{
    Stack stack;
    stack.enque(10);
    stack.display();
}