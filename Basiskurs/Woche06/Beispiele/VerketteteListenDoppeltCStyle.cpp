/*
	Doppelt verkettete Listen in C
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