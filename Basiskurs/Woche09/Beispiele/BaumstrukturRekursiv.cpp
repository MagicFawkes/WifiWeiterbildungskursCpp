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

	Node(int value) {
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

int main()
{
	Node* root = nullptr;
	root = insert(root, 10); // 0 10
	insert(root, 5); //links
	insert(root, 4); //links
}
