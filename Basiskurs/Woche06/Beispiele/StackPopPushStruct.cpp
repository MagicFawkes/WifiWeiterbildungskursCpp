/*

*/

#include <iostream>

using namespace std;

struct Stack
{
	int data;
	std::shared_ptr<Stack> next;
};

std::shared_ptr<Stack> top = NULL;;


void push(int x)
{
	std::shared_ptr<Stack> newNode = std::make_shared<Stack>();
	newNode->data = x;
	newNode->next = top;
	top = newNode;
}

void pop()
{
	std::shared_ptr<Stack> temp;
	temp = top;

	if (temp == nullptr)
		return;

	top = top->next;
	temp = nullptr;
}

int peek() 
{
	return 0;
}

int main()
{
	push(10);
	pop();
}
