/*
	Dieses Programm implementiert einen einfachen Stack (Stapelspeicher) in C++
	mithilfe eines statischen Arrays der Größe N. Ein Stack arbeitet nach dem
	LIFO-Prinzip (Last In – First Out): Das zuletzt eingefügte Element wird
	als erstes wieder entnommen.

	Funktionsübersicht:
	  - push(x):  Legt ein neues Element x oben auf den Stack.
				   Wenn der Stack voll ist, wird eine Fehlermeldung ausgegeben.
	  - pop():     Entfernt das oberste Element vom Stack und gibt es zurück.
				   Falls der Stack leer ist, erfolgt ebenfalls eine Meldung.
	  - peek():    Gibt das oberste Element zurück, ohne es zu entfernen.

	Verwendete globale Variablen:
	  - int stack[N]:  Speicherbereich für die Stack-Elemente.
	  - int top:       Index des obersten Elements; beginnt bei -1, wenn leer.

	Unterschied Stack vs. Queue:
	  - Stack:  LIFO (Last In, First Out): Das zuletzt abgelegte Element
				 wird zuerst wieder entnommen.
	  - Queue:  FIFO (First In, First Out): Das zuerst abgelegte Element
				 wird zuerst entnommen – ähnlich einer Warteschlange.
				 Statt push/pop würde man hier oft enqueue/dequeue verwenden.

	Ablauf im main():
	  - push(10):  Fügt die Zahl 10 auf den Stack.
	  - pop():     Entfernt das Element (10) wieder und gibt es zurück.
*/

#include <iostream>

using namespace std;

#define N 256

int stack[N] = { 0 };
int top = -1;

void push(int x)
{
	if (top == N - 1)
	{
		cout << "Stackoverflow" << endl;
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
		cout << "Stack is empty, please push an element" << endl;
		return -1;
	}
	return stack[top--];
}

int peek() {
	if (top == -1)
	{
		cout << "Stack is empty, please push an element" << endl;
		return -1;
	}

	return stack[top];

}


int main()
{
	push(10);
	pop();
}
