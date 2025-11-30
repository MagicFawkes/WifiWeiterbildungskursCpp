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

Tipp: Nur wenn stack_out leer ist, kippst du alle Elemente aus stack_in in stack_out, dadurch bleibt die Reihenfolge immer die richtige
*/

#include <iostream>

#define N 256

class Stack
{
	int stack[N] = { 0 };
	

public:
	int top = -1;

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
			//std::cout << "Stack is empty, please push an element" << std::endl;
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
		int value;

		if (stack_out.top == -1)
		{
			do
			{
				value = stack_in.pop();

				if (value != -1)
					stack_out.push(value);

			} while (value != -1);
		}

		value = stack_out.pop();

		if (value != -1)
			std::cout << "Wert vom Stack entfernt: " << value << std::endl;
		
    }
    void front()
    {
		std::cout << "Erste Element ist: " << stack_out.peek() << std::endl;
	}

    void empty()
    {
		if (stack_out.peek() == -1)
		{
			std::cout << "Queue ist leer" << std::endl;
		}
		else
			std::cout << "Queue ist nicht leer" << std::endl;
    }
};

int main()
{
	Queue queue;
	queue.enqueue(10);
	queue.enqueue(11);
	queue.enqueue(12);
	queue.enqueue(13);
	queue.enqueue(14);
	queue.enqueue(15);
	queue.dequeue();
	queue.dequeue();
	queue.dequeue();
	queue.enqueue(16);
	queue.enqueue(17);
	queue.enqueue(18);
	queue.enqueue(19);
	queue.dequeue();
	queue.dequeue();
	queue.dequeue();
	queue.front();
	queue.empty();

    return 0;
}