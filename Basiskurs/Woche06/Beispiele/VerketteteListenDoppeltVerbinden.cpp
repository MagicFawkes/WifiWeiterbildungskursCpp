/*
	Doppelt verkettete Listen in C
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