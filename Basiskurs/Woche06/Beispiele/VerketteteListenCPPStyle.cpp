/*
Verkette Listen CPP Style
*/

#include <iostream>

using namespace std;

//int counter() {
//	static int counter = 0;
//	counter++;
//	return counter;
//}

class Node
{
public:
	int data;
	std::shared_ptr<Node> next;
	static int counter;

	Node(int value) : data(value)
	{
		
	}   
};

int Node::counter = 0;

std::shared_ptr<Node> getNewnode(int x) {
	std::shared_ptr<Node> newNode = std::make_shared<Node>(x);
	//newNode->data = x;
	newNode->next = NULL;
	Node::counter++;
	return newNode;
}

std::shared_ptr<Node> insertFront(std::shared_ptr<Node> head, int value)
{
	std::shared_ptr<Node> newNode = std::make_shared<Node>(value);
	newNode->next = head;
	Node::counter++;
	return newNode;
}

std::shared_ptr<Node> InsertBack(std::shared_ptr<Node> head, int value)
{
	std::shared_ptr<Node> newNode = getNewnode(value);
	newNode->next = head;

	if (head == NULL) {
		return newNode;
	}

	std::shared_ptr<Node> temp = head;

	while (temp->next != NULL) // nicht temp != NULL ist falsch
	{
		temp = temp->next;
	}

	temp->next = newNode;
	newNode->next = NULL;

	return head;

}

std::shared_ptr<Node> insert(std::shared_ptr<Node> head, int value, int target)
{
	if (head == NULL) {
		cout << "Liste ist leer" << endl;
		return head;
	}

	std::shared_ptr<Node> temp = head;

	while (temp != NULL && temp->data != target) // w und w = w
	{
		temp = temp->next;
	}

	if (temp == NULL)
	{
		cout << "Target wurde nicht gefunden" << endl;
	}

	std::shared_ptr<Node> newNode = getNewnode(value);
	newNode->next = temp->next;
	temp->next = newNode;
	return head;

}

bool search(std::shared_ptr<Node> head, int value) {
	std::shared_ptr<Node> temp = head;

	while (temp != NULL) {
		if (temp->data == value) {
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}


std::shared_ptr<Node> remove(std::shared_ptr<Node> head, int value)
{
	if (head == NULL) {
		cout << "Liste leer" << endl;
		return head;
	}

	std::shared_ptr<Node> temp = head;

	while (temp->next != NULL && temp->next->data != value) {}
	{
		temp = temp->next;
	}
	if (temp->next == NULL) {
		cout << "Element nicht gefunden" << endl;
	}

	std::shared_ptr<Node> temp2 = temp->next;
	temp->next = temp2->next;
	temp2 = NULL;

	return head;

}

void printlist(std::shared_ptr<Node> head) {
	if (head == NULL) {
		cout << "Liste leer" << endl;
		return;
	}

	std::shared_ptr<Node> temp = head;

	while (temp != NULL)
	{
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << "\n";

}

void deleteList(std::shared_ptr<Node> head)
{
	std::shared_ptr<Node> temp1 = head;
	std::shared_ptr<Node> temp2 = NULL;
	while (temp1 != NULL)
	{
		temp2 = temp1->next;
		temp1 = nullptr;
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
	std::shared_ptr<Node> head = NULL;
	for (int i = 0; i < 10; i++) {
		head = insertFront(head, i + 1);
	}

	printlist(head);

	deleteList(head);

	cout << "Counter: " << Node::counter;
}
