/*
	Dieses Programm implementiert eine doppelt verkettete Liste (Doubly Linked List) in C++.

	Eine doppelt verkettete Liste besteht aus Knoten (Nodes), bei denen jeder Knoten
	einen Verweis (Pointer) auf den vorherigen und den nächsten Knoten enthält.
	Dadurch kann man sowohl vorwärts als auch rückwärts durch die Liste laufen.

	Aufbau:
	- struct Node enthält:
		- data  : den gespeicherten Wert
		- next  : Zeiger auf den nächsten Knoten
		- prev  : Zeiger auf den vorherigen Knoten
		- counter: statische Variable, zählt die Anzahl erstellter Nodes
	- head zeigt immer auf den ersten Knoten der Liste.

	Unterstützte Funktionen:
	- GetNewNode(x): erzeugt einen neuen Knoten mit Wert x und erhöht den Zähler.
	- InsertAtFront(x): fügt ein neues Element vorne (am Anfang) der Liste ein.
	- InsertAtEnd(x): fügt ein neues Element am Ende der Liste ein.
	- Insert(x, value): fügt ein Element NACH dem Knoten ein, der 'value' enthält.
	- print(): gibt die Liste vom Anfang zum Ende aus.
	- printrueckwaerts(): gibt die Liste vom Ende zum Anfang aus.

	Allgemeine Info zur Queue:
	-----------------------------------------
	Eine Queue (Warteschlange) ist ein lineares Datenmodell nach dem FIFO-Prinzip:
		First In, First Out.
	Das erste eingefügte Element wird auch als erstes wieder entnommen.

	Typische Queue-Operationen:
		- enqueue(x): Element hinten einfügen
		- dequeue(): Element vorne entfernen
		- front(): vorderstes Element ansehen
		- isEmpty(): prüfen, ob leer

	Auch mit einer doppelt verketteten Liste könnte man sehr effizient eine Queue
	implementieren, da das Einfügen hinten und Entfernen vorne jeweils O(1) Zeit benötigt.
*/

#include <iostream>

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

void InsertAtfront(int x) {
	Node* newNode = GetNewNode(x);

	if (head == NULL) {
		head = newNode;
		return;
	}

	head->prev = newNode;
	newNode->next = head;
	head = newNode;

}

void InsertAtEnd(int x)
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

void Insert(int x, int value)
{
	Node* newNode = GetNewNode(x);
	Node* temp = head;

	while (temp != NULL && temp->data != value) {
		temp = temp->next;
	}

	if (temp == NULL) {
		return;
	}

	newNode->next = temp->next;
	newNode->prev = temp;

	if (temp->next != NULL) {
		temp->next->prev = newNode;
	}

	temp->next = newNode;

}

void print() {
	if (head == NULL) {
		return;
	}

	Node* temp = head;

	while (temp != NULL) {
		cout << temp->data << endl;
		temp = temp->next;
	}

	//while (temp->next != NULL) 
	//{
	//	cout << temp->data << endl;
	//	temp = temp->next;

	//}
	//temp->next->data;
	//temp->next->next->data;
	//temp->next->next->next->next->data;
	//cout << temp->data;

}

void printrueckwaerts()
{
	if (head == NULL)
	{
		return;
	}

	Node* temp = head;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->prev;
	}
}


int main()
{



}