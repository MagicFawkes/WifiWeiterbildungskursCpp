/*
	Dieses Programm demonstriert zwei unterschiedliche Implementierungen eines Stacks
	(LIFO-Datenstruktur – Last In, First Out):

	1. Stack mit statischem Array:
	   - Es gibt ein globales Array 'stack' mit fixer Größe (N = 256).
	   - 'push(x)' legt ein Element oben auf den Stack.
	   - 'pop()' entfernt das oberste Element.
	   - 'peek()' gibt das oberste Element aus, ohne es zu entfernen.
	   - Diese Variante ist sehr schnell, aber in ihrer Größe begrenzt.

	2. Stack mit einfach verketteter Liste (dynamischer Stack):
	   - Jeder Eintrag besteht aus einem Node (data + next).
	   - 'Push(x)' erstellt einen neuen Node und setzt ihn an den Anfang der Liste.
	   - 'Pop()' entfernt den obersten Node und gibt seinen Wert zurück.
	   - 'Print()' gibt den kompletten Stack von oben nach unten aus.
	   - Diese Variante wächst dynamisch und ist nur durch den Hauptspeicher begrenzt.

	Im main()-Bereich:
	   - Es werden die Zahlen 1 bis 10 in den dynamischen Stack gepusht.
	   - Danach wird der gesamte Stack ausgegeben.
	   - Anschließend werden alle Elemente wieder heruntergepoppt.
	   - Abschließend wird der leere Stack erneut ausgegeben.

	Zusatzinfo zu Queues (Warteschlangen):
	   - Eine Queue arbeitet nach dem FIFO-Prinzip (First In, First Out).
	   - Das bedeutet: Das zuerst eingefügte Element wird als erstes wieder entfernt.
	   - Typische Operationen:
		 * enqueue(x): fügt ein Element hinten an
		 * dequeue(): entfernt das Element vorne
	   - Queues lassen sich ebenfalls per Array oder per verketteter Liste implementieren.
	   - Verwendung: Puffer, Aufgabenverwaltung, Prozesse im Betriebssystem, Datenströme usw.
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


struct Node
{
	int data;
	Node* next;
};

struct Node* Top = NULL;
int counter = 0;

void Push(int x)
{
	Node* newNode = new Node();
	newNode->data = x;
	newNode->next = Top;
	Top = newNode;
	counter++;
}

void Pop()
{
	Node* temp;
	temp = Top;
	if (temp == NULL) {
		//Fehlermeldung
		return;
	}
	else
	{
		cout << "Pop das element" << temp->data << endl;
		Top = Top->next;
		delete temp;
	}


}
void Print() {
	Node* temp;
	temp = Top;
	if (temp == NULL) {
		//Fehlermeldung
		return;
	}
	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
}


int main()
{
	for (int i = 1; i <= 10; i++) {
		Push(i);
	}
	Print();
	for (int i = 1; i <= counter; i++) {
		Pop();
	}
	Print();




}
