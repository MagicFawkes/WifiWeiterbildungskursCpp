/*
    Dieses Programm demonstriert die grundlegende Verwendung einer
    doppelt verketteten Liste in C++.

    Eine doppelt verkettete Liste besteht aus Knoten (Nodes),
    die jeweils auf den vorherigen (links) und den nächsten
    (rechts) Knoten zeigen können. Dadurch kann in beide
    Richtungen navigiert werden, im Gegensatz zur einfach
    verketteten Liste, die nur eine Richtung kennt.

    Jeder Node enthält:
        - einen Datenwert (data)
        - einen Zeiger auf den linken Nachbarn (links)
        - einen Zeiger auf den rechten Nachbarn (rechts)
        - einen statischen Zähler (counter), der mitzählt,
          wie viele Knoten insgesamt angelegt wurden.

    Im main()-Block wird:
        - überprüft, ob die Liste leer ist (head == nullptr)
        - der erste Knoten erzeugt (head = GetNewNode(10))
        - anschließend wird die "rechts"- und "links"-Seite des
          head-Knotens erweitert, sowie deren Nachbarn

    Hinweis zu Queues:
        Eine Queue („Warteschlange“) ist eine Datenstruktur,
        die nach dem FIFO-Prinzip arbeitet (First In – First Out).
        Man fügt Elemente hinten an (enqueue) und nimmt sie
        vorne wieder heraus (dequeue). Queues lassen sich
        leicht mithilfe von verketteten Listen implementieren:
            - head zeigt auf das vorderste Element (dequeue)
            - tail zeigt auf das hinterste Element (enqueue)
        Doppelt verkettete Listen erleichtern es zusätzlich,
        in beide Richtungen zu traversieren.
*/

#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node* links;
	struct Node* rechts;
	static int counter;
};

int Node::counter = 0;

struct Node* head = NULL;

Node* GetNewNode(int x)
{
	Node* newNode = new Node();
	newNode->data = x;
	newNode->links = NULL;
	newNode->rechts = NULL;
	Node::counter++;
	return newNode;
}

enum direction
{
	rechts,
	links
};

int main()
{
	if (head == nullptr)
	{
		head = GetNewNode(10);
	}
	head->rechts = GetNewNode(20);
	head->links = GetNewNode(20);
	head->rechts->links = GetNewNode(10);
	head->links->links = GetNewNode(10);

}