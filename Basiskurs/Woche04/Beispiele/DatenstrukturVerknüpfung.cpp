/*
Erstelle folgende Datenstruktur und zwar eine, bei der jedes Element
auf das nächste zeigt. Man kann Elemente am Anfang und am Ende
hinzufügen sowie löschen. Jede Struktur beinhaltet einen Wert
und zeigt auf das nächste Element.
*/

#include <iostream>

int wert = 0;

void elementAmEndeHinzufügen(struct example* struktur);
void elementAmAnfangHinzufügen(struct example* struktur);

struct example
{
	int wert;
	struct example *weiter = NULL;
	struct example *vorher = NULL;
};

int main()
{
	struct example* struktur = new example{ ++wert };

	elementAmEndeHinzufügen(struktur);
	elementAmEndeHinzufügen(struktur);
	elementAmEndeHinzufügen(struktur);
	elementAmEndeHinzufügen(struktur);
	elementAmEndeHinzufügen(struktur);

	elementAmAnfangHinzufügen(struktur);
	elementAmAnfangHinzufügen(struktur);
	elementAmAnfangHinzufügen(struktur);
	elementAmAnfangHinzufügen(struktur);

	struct example* aktuelleElement = struktur;

	while (aktuelleElement->vorher != NULL)
	{
		//std::cout << '\n' << aktuelleElement->wert;
		aktuelleElement = aktuelleElement->vorher;
	}

	std::cout << '\n' << aktuelleElement->wert;

	while (aktuelleElement->weiter != NULL)
	{
		aktuelleElement = aktuelleElement->weiter;
		delete(aktuelleElement->vorher);
		std::cout << '\n' << aktuelleElement->wert;
	}

	delete(aktuelleElement);

	return 0;
}

void elementAmEndeHinzufügen(struct example* struktur)
{
	while (struktur->weiter != NULL)
	{
		struktur = struktur->weiter;
	}

	struktur->weiter = new example{ ++wert };
	struktur->weiter->vorher = struktur;
}

void elementAmAnfangHinzufügen(struct example* struktur)
{
	while (struktur->vorher != NULL)
	{
		struktur = struktur->vorher;
	}

	struktur->vorher = new example{ ++wert };
	struktur->vorher->weiter = struktur;
}

//Lösung von Kursleter
//#include <iostream>
//#include <string>
//using namespace std;
//void print();
//void Insertb(Node** head, int value);
//void printList(Node** head);
//
//struct Node {
//	int data;
//	Node* nextnode;
//};
//
//enum werte {
//	ADD_B = 1, ADD_E, REMOVE, PRINT, END
//};
//
//
//void printList(Node** head) {
//	Node* temp = *head;
//	while (temp != nullptr) {
//		cout << temp->data << endl;
//		temp = temp->nextnode;
//	}
//	cout << "nullptr" << endl;
//}
//void print() {
//	cout << "Menu" << endl;
//	cout << "1 Hinzufeugen am Anfang" << endl;
//	cout << "2 Hinzufeugen am Ende" << endl;
//	cout << "3 Loeschen eines Elements" << endl;
//	cout << "4 Liste an der Konsole ausgeben" << endl;
//	cout << "5 Programm wird beendet" << endl;
//}
//void Insertb(Node** head, int value)
//{
//	Node* newNode = new Node;
//	newNode->data = value;
//	newNode->nextnode = *head;
//	*head = newNode;
//}
//void INsertEnde(Node** head, int value)
//{
//	Node* newNode = new Node;
//	newNode->data = value;
//	newNode->nextnode = nullptr;
//
//
//	if (*head == nullptr) {
//		newNode->nextnode = *head;
//		*head = newNode;
//		return;
//	}
//
//	Node* temp = *head;
//	while (temp->nextnode != nullptr) {
//		temp = temp->nextnode;
//	}
//
//	temp->nextnode = newNode;
//
//}
//void remove(Node** head, int value) {
//	if (*head == nullptr) {
//		return;
//	}
//
//	Node* temp = *head;
//
//	Node* temp1 = temp;
//
//	while (temp != nullptr && temp->data != value) {
//		temp1 = temp;
//		temp = temp->nextnode;
//	}
//
//	if (temp != nullptr) {
//		temp1->nextnode = temp->nextnode;
//		delete temp;
//	}
//
//
//}
//
//void freelist(Node* head) {
//	Node* temp;
//	while (temp->nextnode != nullptr) {
//		temp = head;
//		head = head->nextnode;
//		delete temp;
//	}
//}
//
//int main()
//{
//	Node* head = nullptr;
//
//	int wahl, value;
//
//	do {
//		print();
//		cin >> wahl;
//		cout << "Wahl:" << wahl;
//
//		switch (wahl) {
//		case ADD_B:
//			cout << "Wert";
//			cin >> value;
//			Insertb(&head, value);
//			break;
//
//		case ADD_E:
//			cout << "Wert";
//			cin >> value;
//			INsertEnde(&head, value);
//			break;
//
//		case REMOVE:
//			cout << "Wert";
//			cin >> value;
//			remove(&head, value);
//			break;
//
//		case PRINT:
//			printList(&head);
//			break;
//
//		case END:
//			cout << "Beende das Programm";
//			freelist(head);
//			break;
//
//		default:
//			cout << "Es wurde nichts ausgewählt";
//			break;
//
//		}
//
//	} while (wahl != END);
//
//
//
//}
//
