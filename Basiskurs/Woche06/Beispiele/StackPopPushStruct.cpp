/*
    Dieses Programm implementiert einen einfachen Stack (LIFO – Last In, First Out)
    mit Hilfe von std::shared_ptr, um die Speicherverwaltung automatisch zu übernehmen.

    Funktionsweise des Stacks:
    --------------------------
    - Ein Stack ist eine Datenstruktur, bei der das zuletzt eingelegte Element
      als erstes wieder entfernt wird (LIFO-Prinzip).
    - Die Struktur 'Stack' besteht aus einem Datenwert (data) und einem Zeiger
      auf das nächste Element (next).
    - Das globale shared_ptr 'top' zeigt immer auf das oberste Element des Stacks.

    push(x):
      - Erstellt einen neuen Stack-Knoten.
      - Setzt seinen 'next'-Zeiger auf das aktuelle 'top'.
      - Verschiebt 'top' auf den neuen Knoten.
      => Das Element liegt nun oben auf dem Stack.

    pop():
      - Entfernt das oberste Element.
      - 'top' zeigt danach auf das nächste Element.
      - Durch shared_ptr wird der Speicher automatisch freigegeben,
        sobald keine Referenzen mehr vorhanden sind.

    Hinweis:
      Die Funktion peek() sollte normalerweise den obersten Wert zurückgeben.
      Beispiel: return top ? top->data : <Fehlerwert>;

    Zusatzinfo – Queue (Warteschlange):
    -----------------------------------
    - Eine Queue arbeitet nach dem FIFO-Prinzip (First In, First Out).
    - Elemente werden hinten eingefügt (enqueue) und vorne entnommen (dequeue).
    - Im Gegensatz zum Stack werden bei einer Queue die ersten eingefügten
      Elemente zuerst wieder entfernt.
    - Wird häufig für Aufgaben wie Scheduling, Puffern oder Event-Verarbeitung verwendet.
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
