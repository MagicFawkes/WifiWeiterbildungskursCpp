/*
Aufgabe 1:
Schreibe eine Klasse, die: Elemente immer sortiert einfügt Duplikate optional erlaubt oder
verbietet Eine Funktion hat: merge(DLL other) ? zwei sortierte Listen effizient
zusammenführen.
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

	Node* head = NULL;

public:
	int counter = 0;

	void insert(int value)
	{
		if (this->head == NULL) {
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
			std::cout << "Duplikat gefunden einfuegen: ";
			std::cin >> eingabe;

			if (eingabe == "nein")
				return;

			Node* newNode = this->GetNewNode(value);
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
};

int main()
{
	Liste list;

	list.insert(5);
	list.insert(10);
	list.insert(15);
	list.insert(18);
	list.insert(8);
	list.insert(4);
	list.insert(3);
	list.insert(2);
	list.insert(30);
	list.insert(18);
	list.printlist();

    return 0;
}