/*
	Dieses Programm demonstriert die Implementierung einer doppelt verketteten Liste in C++.

	Eine doppelt verkettete Liste besteht aus Knoten (Nodes),
	die jeweils einen Datenwert sowie zwei Zeiger besitzen:
	- prev: zeigt auf das vorherige Element
	- next: zeigt auf das nächste Element

	Dadurch kann man sowohl vorwärts als auch rückwärts durch die Liste laufen.
	Diese Struktur ist dynamisch, d.h. Elemente können flexibel hinzugefügt oder entfernt werden,
	ohne dass – wie bei einem Array – Speicherblöcke verschoben werden müssen.

	Im Code wird:
	- Ein Node-Datentyp definiert, der Daten und zwei Zeiger enthält
	- Eine Funktion GetNewNode(x) erzeugt einen neuen Knoten im Heap
	- Die Funktion InsertAtEnd(...) fügt einen Wert am Ende der Liste an
	- Die Funktion print(...) läuft die Liste durch und gibt alle Werte aus
	- Ein statischer Zähler (Node::counter) zählt, wie viele Nodes erzeugt wurden

	Hinweise zur Queue (Warteschlange):
	Eine Queue ist eine Datenstruktur mit dem Prinzip FIFO (First In – First Out).
	- Elemente werden hinten eingefügt (enqueue)
	- Elemente werden vorne entnommen (dequeue)
	Doppelt verkettete Listen eignen sich gut zur Implementierung einer Queue,
	da das Einfügen am Ende und Entfernen am Anfang sehr effizient ist (O(1) Zeit).
*/

#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
	static int counter;
};

int Node::counter = 0;

struct Node* head = NULL;

Node* GetNewNode(int x)
{
	Node* newNode = new Node();
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	Node::counter++;
	return newNode;
}

void InsertAtEnd(Node* head, int x)
{
	Node* newNode = GetNewNode(x);
	if (head == NULL)
	{
		head = newNode;
		return;
	}

	Node* temp = head;

	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = newNode;
	newNode->prev = temp;

}

void print(Node* head) {
	if (head == NULL) {
		return;
	}

	Node* temp = head;

	while (temp != NULL) {
		cout << temp->data << endl;
		temp = temp->next;
	}
}


int main()
{
	struct Node* head = NULL;

}