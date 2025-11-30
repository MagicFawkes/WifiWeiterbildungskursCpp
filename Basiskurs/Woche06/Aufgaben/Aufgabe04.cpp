/*
Aufgabe 4:
Implementiere eine Queue (FIFO) mit zwei Stacks.
Anforderungen:
1. Implementiere eine Klasse Stack
2. Die Queue KLASSE muss die Standardoperationen unterstützen:
• enqueue(x): fügt das Element x am Ende der Queue hinzu
• dequeue(): entfernt das erste Element der Queue und gibt es zurück
• front(): gibt das erste Element zurück, ohne es zu entfernen
• empty(): prüft, ob die Queue leer ist
Ziel:
• Die Operationen sollen so effizient wie möglich sein.
Hinweis:
• Ein Stack arbeitet nach dem LIFO-Prinzip (Last In, First Out).
• Eine Queue arbeitet nach dem FIFO-Prinzip (First In, First Out).
• Überlege, wie du durch das Verschieben von Elementen zwischen den beiden Stacks
das FIFO-Verhalten einer Queue nachbilden kannst.
Kleine Hilfe:
class Stack {
Code
};
Class Queue{
private:
Stack stack_in;
Stack stack_out;
public:
Code
};
*/

#include <iostream>
#include <stdio.h>

#define N 256

class Stack
{
	int stack[N] = { 0 };
	int top = -1;

public:
	void push(int x)
	{
		if (top == N - 1)
		{
			std::cout << "Stackoverflow" << std::endl;
		}
		else
		{
			stack[++top] = x;
		}
	}

	int pop()
	{
		if (top == -1)
		{
			std::cout << "Stack is empty, please push an element" << std::endl;
			return -1;
		}
		return stack[top--];
	}

	int peek() {
		if (top == -1)
		{
			std::cout << "Stack is empty, please push an element" << std::endl;
			return -1;
		}

		return stack[top];
	}
};

class Queue 
{
private:
    Stack stack_in;
    Stack stack_out;
public:
    void enqueue(int x)
    {
		stack_in.push(x);
    }
    void dequeue()
    {
		stack_out.pop();
    }
    void front()
    {
		stack_out.peek();
    }
    void empty()
    {
		if (stack_out.peek() == -1)
		{
			std::cout << "Queue ist leer";
		}
		else
			std::cout << "Queue ist nicht leer";
    }
};

int main()
{
    printf("Test");
    return 0;
}