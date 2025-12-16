/*

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

struct Node 
{
	int data;
	struct Node* links;
	struct Node* rechts;

	Node(int value) 
	{
		data = value;
		links = nullptr;
		rechts = nullptr;
	}
};

Node* insert(Node* root, int value) //2000 5
{
	if (root == nullptr)
	{
		return new Node(value);
	}
	if (value <= root->data)
	{
		root->links = insert(root->links, value); //1000
	}
	else
	{
		root->rechts = insert(root->rechts, value);
	}
	return root;
}

void printlistLeft(Node* head) {
	if (head == NULL) 
	{
		std::cout << "Liste leer" << std::endl;
		return;
	}

	Node* temp = head;

	while (temp != NULL)
	{
		std::cout << temp->data << " -> ";
		temp = temp->links;
	}
	std::cout << "\n";
}

void printlistRight(Node* head) {
	if (head == NULL)
	{
		std::cout << "Liste leer" << std::endl;
		return;
	}

	Node* temp = head;

	while (temp != NULL)
	{
		std::cout << temp->data << " -> ";
		temp = temp->rechts;
	}
	std::cout << "\n";
}

int main()
{
	Node* root = nullptr;
	root = insert(root, 10); // 0 10

	int values[] = { 10, 5, 20, 3, 7, 20 };

	for (int v : values)
		root = insert(root, v);

	printlistRight(root);
	printlistLeft(root);
}
