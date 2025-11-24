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


int main()
{
	push(10);
	pop();

}
