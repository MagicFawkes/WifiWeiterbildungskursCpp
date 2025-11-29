/*
Aufgabe 3:
Doubly Linked List rotieren Schreibe eine Funktion: rotate(k) → verschiebt die Liste zyklisch
nach rechts um k Elemente.
*/

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
			std::cout << "Duplikat gefunden: " << value << " - einfuegen: ";
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

void rotate(Liste& list, int verschiebung)
{
	if (list.counter < verschiebung)
	{
		std::cout << "Verschiebung nicht moeglich - Liste zu klein\n";
		return;
	}

	if (verschiebung <= 0)
	{
		std::cout << "keiner Verschibeung Eingabe ist kleiner gleich 0 \n";
		return;
	}

	Node* temp = list.head;
	Node* temp1 = list.head;

	for (int i = 0; i < verschiebung; ++i)
	{
		temp1 = temp1->next;
	}

	list.head = temp1;

	temp1->prev->next = nullptr;

	while (temp1->next != nullptr)
	{
		temp1 = temp1->next;
	}
	temp1->next = temp;
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

	rotate(list1, 1);
	std::cout << list1.counter << std::endl;
	list1.printlist();

	return 0;
}