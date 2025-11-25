/*

*/

#include <iostream>

using namespace std;

#define N 10

class Stack
{
private:
    int queue[N];
    int front = -1; //zeigt auf das nächst zu popende Element
    int rear = -1; //zeigt auf das letzte Element

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