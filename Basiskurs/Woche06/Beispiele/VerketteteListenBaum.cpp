/*
	Doppelt verkettete Listen in C
*/

#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node* links;
	struct Node* rechts;
	static int counter;
};

int Node::counter = 0;

struct Node* head = NULL;

Node* GetNewNode(int x)
{
	Node* newNode = new Node();
	newNode->data = x;
	newNode->links = NULL;
	newNode->rechts = NULL;
	Node::counter++;
	return newNode;
}

enum direction
{
	rechts,
	links
};

int main()
{
	if (head == nullptr)
	{
		head = GetNewNode(10);
	}
	head->rechts = GetNewNode(20);
	head->links = GetNewNode(20);
	head->rechts->links = GetNewNode(10);
	head->links->links = GetNewNode(10);
}