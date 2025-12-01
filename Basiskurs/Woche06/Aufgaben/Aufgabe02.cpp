/*
Aufgabe 2:
Gegeben eine nicht sortierte doubly linked list:
Entferne alle Duplikate ohne zusätzliche Datenstruktur (O(1) Speicher). Hinweis: O(n²) Lösung
ist erlaubt.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <ostream>

class Node
{
public:
	int data;
	struct Node* next;
	struct Node* prev;

	Node(int value) : data(value)
	{

	}
};

class Liste
{
private:
	Node* GetNewNode(int x)
	{
		Node* newNode = new Node(x);
		newNode->data = x;
		newNode->next = NULL;
		newNode->prev = NULL;
		this->counter++;
		return newNode;
	}

public:
	int counter = 0;

	Node* head = NULL;

	void insert(int value)
	{
		if (this->head == NULL)
		{
			std::cout << "Liste ist leer, anlegen" << std::endl;
			this->head = GetNewNode(value);
			return;
		}

		Node* temp = this->head;

		while (temp->next != NULL && temp->data < value)
		{
			temp = temp->next;
		}

		if (temp->data == value)
		{
			std::string eingabe;
			std::cout << "Duplikat gefunden: " << value <<" - einfuegen: ";
			eingabe = "ja";
			std::cout << eingabe << std::endl;

			if (eingabe == "nein")
				return;

			Node* newNode = this->GetNewNode(value);
			newNode->next = temp->next;
			temp->next = newNode;
			newNode->prev = temp;
		}
		else if (temp->data > value)
		{
			Node* newNode = this->GetNewNode(value);
			newNode->next = temp;
			newNode->prev = temp->prev;

			if (temp->prev != nullptr)
				temp->prev->next = newNode;

			temp->prev = newNode;

			if (temp == this->head)
				this->head = newNode;
		}
		else
		{
			Node* newNode = this->GetNewNode(value);
			newNode->next = temp->next;
			temp->next = newNode;
			newNode->prev = temp;
		}
	}

	void printlist()
	{
		if (head == NULL) {
			std::cout << "Liste leer" << std::endl;
			return;
		}

		Node* temp = head;

		while (temp != NULL)
		{
			std::cout << "Wert: " << temp->data << std::endl;
			temp = temp->next;
		}
		std::cout << "\n";
	}

	void remove(int value)
	{
		if (head == NULL) 
		{
			std::cout << "Liste leer" << std::endl;
		}

		Node* temp = head;

		while (temp->next != NULL && temp->next->data != value) {}
		{
			temp = temp->next;
		}
		if (temp->next == NULL) {
			std::cout << "Element nicht gefunden" << std::endl;
		}

		Node* temp2 = temp->next;
		temp->next = temp2->next;
		free(temp2);
	}
};

void removeDuplicates(Liste &list)
{
	Node* temp = list.head;

	while (temp != nullptr)
	{
		Node* temp1 = temp->next;

		while (temp1 != nullptr)
		{
			if (temp->data == temp1->data)
			{
				Node* temp2 = temp1;
				temp->next = temp1->next;
				temp1->next->prev = temp;
				temp1 = temp;
				free(temp2);
			}

			temp1 = temp1->next;
		}

		temp = temp->next;
	}
}

int main()
{
	Liste list1;
	list1.insert(54);
	list1.insert(5);
	list1.insert(10);
	list1.insert(15);
	list1.insert(18);
	list1.insert(8);
	list1.insert(4);
	list1.insert(4);
	list1.insert(3);
	list1.insert(2);
	list1.insert(30);
	list1.insert(18);
	list1.insert(30);
	list1.insert(18);
	std::cout << "\n";
	std::cout << list1.counter << std::endl;
	list1.printlist();

	removeDuplicates(list1);

	std::cout << list1.counter << std::endl;
	list1.printlist();

	return 0;
}

//Lösung von Trainer

/*
 *
 *#include <iostream>
using namespace std;
 
class dll 
{
private:
    struct Node {
        int value;
        Node* prev;
        Node* next;
        Node(int x):value(x),prev(NULL),next(NULL){}
    };
 
    Node* head;
 
public:
   dll():head(NULL){}
 
   //void insert();
 
   void remove() 
   {
       Node* current = head;
       Node* temp;
 
       while (current != NULL) 
       {
           temp = current->next;
 
           while (temp != NULL) 
           {
               if (temp->value == current->value) 
               {
                   Node* delte = temp;
                   temp = temp->next;
                   if (delte->prev) 
                   {
                       delte->prev->next = delte->next;
                   }
                   if (delte->next) 
                   {
                       delte->next->prev = delte->prev;
                   }
 
                   delete delte;
               }
               else 
               {
                   temp = temp->next;
               }
 
           }
 
           current = current->next;
       }
 
   }
 
 
};
 
 
class Stack {
private:
    static const int MAX = 100;
    int a[MAX] = {0};
    int top;
public:
    Stack():top(-1){}
 
    void pop(){
        return;
    }
 
    void push(int x) {
        return;
    }
 
    int top() const {
        return 0;
    }
 
    bool empty() const 
    {
        return (top < 0);
    }
    //push, pop, top, empty
};
 
class Queue
{
private:
    Stack stack_in;
    Stack stack_out;
 
    void function() 
    {
        if (stack_out.empty()) 
        {
            int value = 0;
            while (!stack_in.empty()) {
                value = stack_in.top();
                stack_in.pop();
                stack_out.push(value);
            }
 
        }
 
    }
 
public:
    void enqueue(int x) 
    {
        stack_in.push(x);
    }
 
    void deque() 
    {
        function();
        if (!stack_out.empty()) {
            stack_out.pop();
        }
    }
 
};
 
 
int main()
{
 
    std::cout << "Hello World!\n";
}
*/