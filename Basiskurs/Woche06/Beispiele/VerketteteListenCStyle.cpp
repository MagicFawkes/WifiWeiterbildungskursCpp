/*
	Dieses Programm demonstriert eine einfach verkettete Liste (Singly Linked List)
	und die grundlegenden Operationen darauf. Eine verkettete Liste besteht aus
	einzelnen Knoten (Nodes), wobei jeder Knoten einen Wert (data) und einen Zeiger
	auf den nächsten Knoten (next) enthält. Der letzte Knoten zeigt auf NULL.

	Implementierte Funktionen:
	- getNewnode(x): Erzeugt einen neuen Listenknoten mit dem Wert x.
	- insertFront(head, value): Fügt einen neuen Knoten am Listenanfang ein.
	  Dies entspricht einer Stack-ähnlichen Operation (push vorne).
	- InsertBack(head, value): Fügt einen neuen Knoten am Listenende ein.
	- insert(head, value, target): Fügt ein Element nach einem bestimmten Wert ein.
	- search(head, value): Sucht nach einem Element in der Liste.
	- remove(head, value): Entfernt einen Knoten mit bestimmtem Wert.
	- printlist(head): Gibt die gesamte Liste aus.
	- deleteList(head): Löscht die gesamte Liste aus dem Speicher.

	Der main()-Teil erstellt eine Liste mit den Werten 1 bis 10 über insertFront()
	(dadurch erscheint die Reihenfolge in der Ausgabe invertiert),
	gibt die Liste aus und löscht anschließend alle Knoten.

	Info zur Queue:
	Eine Queue (Warteschlange) ist eine FIFO-Datenstruktur ("First In – First Out").
	Typische Operationen sind:
	  * enqueue(x): Hinten einfügen
	  * dequeue(): Vorn entfernen
	Mit einer verketteten Liste lässt sich eine Queue leicht umsetzen, indem man:
	  - am Ende einfügt (enqueue → InsertBack),
	  - am Anfang entfernt (dequeue → remove first).
	Dieses Programm implementiert zwar eine generelle verkettete Liste,
	kann aber leicht zur Queue erweitert werden.
*/

#include <iostream>

using namespace std;

//int counter() {
//	static int counter = 0;
//	counter++;
//	return counter;
//}

struct Node
{
	int data;
	Node* next;
	//static int counter;
};

//int Node::counter = 0;

Node* getNewnode(int x) {
	Node* newNode = new Node();
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

Node* insertFront(Node* head, int value)
{
	Node* newNode = getNewnode(value);
	newNode->next = head;
	return newNode;
}

Node* InsertBack(Node* head, int value)
{
	Node* newNode = getNewnode(value);
	newNode->next = head;

	if (head == NULL) {
		return newNode;
	}

	Node* temp = head;

	while (temp->next != NULL) // nicht temp != NULL ist falsch
	{
		temp = temp->next;
	}

	temp->next = newNode;
	newNode->next = NULL;

	return head;

}

Node* insert(Node* head, int value, int target)
{
	if (head == NULL) {
		cout << "Liste ist leer" << endl;
		return head;
	}


	Node* temp = head;

	while (temp != NULL && temp->data != target) // w und w = w
	{
		temp = temp->next;
	}

	if (temp == NULL)
	{
		cout << "Target wurde nicht gefunden" << endl;
	}

	Node* newNode = getNewnode(value);
	newNode->next = temp->next;
	temp->next = newNode;
	return head;

}

bool search(Node* head, int value) {
	Node* temp = head;

	while (temp != NULL) {
		if (temp->data == value) {
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}


Node* remove(Node* head, int value)
{
	if (head == NULL) {
		cout << "Liste leer" << endl;
		return head;
	}

	Node* temp = head;

	while (temp->next != NULL && temp->next->data != value) {}
	{
		temp = temp->next;
	}
	if (temp->next == NULL) {
		cout << "Element nicht gefunden" << endl;
	}

	Node* temp2 = temp->next;
	temp->next = temp2->next;
	free(temp2);

	return head;

}

void printlist(Node* head) {
	if (head == NULL) {
		cout << "Liste leer" << endl;
		return;
	}

	Node* temp = head;

	while (temp != NULL)
	{
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << "\n";

}

void deleteList(Node* head)
{
	Node* temp1 = head;
	Node* temp2 = NULL;
	while (temp1 != NULL)
	{
		temp2 = temp1->next;
		delete temp1;
		temp1 = temp2;
	}
}


//void deleteList(Node* head) 
// {
//	Node* temp1 = NULL;
//
//
//	while (head != NULL)
//	{
//		temp1 = head;
//		head = head->next;
//		delete temp1;
//
//
//	}
//
//}


//void insertFront(Node** head, int value) 
//{
//		Node* newNode = getNewnode(value);
//		newNode->next = *head;
//		*head = newNode;
//		
//
//}

int main()
{
	Node* head = NULL;
	for (int i = 0; i < 10; i++) {
		head = insertFront(head, i + 1);
	}

	printlist(head);

	deleteList(head);
}
