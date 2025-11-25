/*
QUEUE → FIFO
STACK → LIFO
*/

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    string text;
    cout << "Enter a word: ";
    cin >> text;

    int n = text.size();

    char* queue = new char[n];
    char* stack = new char[n];

    queue[n - 1] = '\0';
    stack[n - 1] = '\0';

    int qfront = -1, qrear = -1;
    int top = -1;

    bool palindrom = true;

    for (int i = 0; i < n; i++)
    {
        queue[++qrear] = text[i]; //enqueue
        stack[++top] = text[i]; //top
    }

    for (int i = 0; i < n; i++)
    {
        if (queue[++qfront] != stack[top--]) //pop
        {
            palindrom = false;
            break;
        }
    }

    if (palindrom)
        cout << "Palindrom" << endl;
    else
        cout << "Palindrom" << endl;

    delete[] queue;
    delete[] stack;
}
