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
			std::cout << "Duplikat gefunden einfuegen: ";
			std::cin >> eingabe;

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
};

void combineList(Liste list1, Liste list2, Liste &listGesamt)
{
	Node* temp = list1.head;

	while (temp != NULL)
	{
		listGesamt.insert(temp->data);
		temp = temp->next;
	}

	temp = list2.head;

	while (temp != NULL)
	{
		listGesamt.insert(temp->data);
		temp = temp->next;
	}
}

int main()
{
	Liste list1;
	list1.insert(5);
	list1.insert(10);
	list1.insert(15);
	list1.insert(18);
	list1.insert(8);
	list1.insert(4);
	list1.insert(3);
	list1.insert(2);
	list1.insert(30);
	list1.insert(18);
	std::cout << list1.counter << std::endl;
	list1.printlist();

	Liste list2;
	list2.insert(7);
	list2.insert(22);
	list2.insert(13);
	list2.insert(4);
	std::cout << list2.counter << std::endl;
	list2.printlist();

	Liste listGesamt;
	combineList(list1, list2, listGesamt);
	std::cout << listGesamt.counter << std::endl;
	listGesamt.printlist();

    return 0;
}