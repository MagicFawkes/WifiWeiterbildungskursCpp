/*

*/

#include <iostream>

using namespace std;
#define N 256

int stack[N] = { 0 };
int top = -1;

void push(int x)
{
	if (top == N - 1)
	{
		cout << "Stackoverflow" << endl;
	}
	else
	{
		stack[++top] = x;
	}
}

int pop()
{
	if (top == -1)
	{
		cout << "Stack is empty, please push an element" << endl;
		return -1;
	}
	return stack[top--];
}

int peek() {
	if (top == -1)
	{
		cout << "Stack is empty, please push an element" << endl;
		return -1;
	}

	return stack[top];

}


struct Node
{
	int data;
	Node* next;
};

struct Node* Top = NULL;
int counter = 0;

void Push(int x)
{
	Node* newNode = new Node();
	newNode->data = x;
	newNode->next = Top;
	Top = newNode;
	counter++;
}

void Pop()
{
	Node* temp;
	temp = Top;
	if (temp == NULL) {
		//Fehlermeldung
		return;
	}
	else
	{
		cout << "Pop das element" << temp->data << endl;
		Top = Top->next;
		delete temp;
	}


}
void Print() {
	Node* temp;
	temp = Top;
	if (temp == NULL) {
		//Fehlermeldung
		return;
	}
	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
}


int main()
{
	for (int i = 1; i <= 10; i++) {
		Push(i);
	}
	Print();
	for (int i = 1; i <= counter; i++) {
		Pop();
	}
	Print();




}
