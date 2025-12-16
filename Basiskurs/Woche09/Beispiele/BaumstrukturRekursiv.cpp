/*

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

struct Node 
{
	int data;
	struct Node* links;
	struct Node* rechts;

	Node(int value) 
	{
		data = value;
		links = nullptr;
		rechts = nullptr;
	}
};

//Insert mit Rekursiv
Node* insert(Node* root, int value) //2000 5
{
	if (root == nullptr)
	{
		return new Node(value);
	}
	if (value <= root->data)
	{
		root->links = insert(root->links, value); //1000
	}
	else
	{
		root->rechts = insert(root->rechts, value);
	}
	return root;
}

void printlistLeft(Node* head) 
{
	if (head == NULL) 
	{
		std::cout << "Liste leer" << std::endl;
		return;
	}

	Node* temp = head;

	while (temp != NULL)
	{
		std::cout << temp->data << " -> ";
		temp = temp->links;
	}
	std::cout << "\n";
}

void printlistRight(Node* head) 
{
	if (head == NULL)
	{
		std::cout << "Liste leer" << std::endl;
		return;
	}

	Node* temp = head;

	while (temp != NULL)
	{
		std::cout << temp->data << " -> ";
		temp = temp->rechts;
	}
	std::cout << "\n";
}


//Iterative Variante mit Insert
void insertNormal(Node* head, int value)
{
	if (head == NULL)
	{
		std::cout << "Liste leer" << std::endl;
		return;
	}

	Node* temp[2];
	temp[0] = head;

	while (temp[0] != nullptr)
	{
		temp[1] = temp[0];

		if (temp[0]->data < value)
		{
			temp[0] = temp[0]->links;
		}
		else
		{
			temp[0] = temp[0]->rechts;
		}
	}

	if (value <= temp[1]->data)
	{
		temp[1]->links = new Node(value);
	}
	else
	{
		temp[1]->rechts = new Node(value);
	}
}

//Rekursiv
bool SearchRekursiv(Node* root, int value) 
{
	if (root == nullptr) {

		return false;
	}
	
	if (root->data > value)
	{
		SearchRekursiv(root->links, value);
	}
	else if (root->data == value)
	{
		return true;
	}
	else
	{
		SearchRekursiv(root->rechts, value);
	}
}

//Iterativ
bool SearchIterativ(Node* root, int value)
{
	if (root == nullptr) 
	{
		return false;
	}

	while (root != nullptr)
	{
		if (root->data > value)
		{
			root = root->links;
		}
		else if (root->data == value)
		{
			return true;
		}
		else
		{
			root = root->rechts;
		}
	}

	return false;
}

/*
	Rekursives Löschen eines Knotens aus einem Binären Suchbaum (BST).

	Grundidee:
	- Ein BST hat die Eigenschaft: links < root->data < rechts
	- Wir suchen den zu löschenden Wert rekursiv, indem wir wie beim Suchen
	  immer nach links oder rechts absteigen.
	- Wenn der Knoten gefunden wurde, gibt es 3 Fälle:
		1) 0 Kinder (Blatt)
		2) 1 Kind
		3) 2 Kinder

	Ablauf Schritt für Schritt:

	1) Abbruchbedingung (Base Case):
	   Wenn root == nullptr:
	   - Wir sind an einem leeren Teilbaum angekommen -> Wert existiert hier nicht.
	   - Rückgabe nullptr (bzw. root unverändert).

	2) Rekursives Suchen:
	   Wenn value < root->data:
	   - Der gesuchte Wert muss (wenn vorhanden) im linken Teilbaum liegen.
	   - Also: root->links = Delete(root->links, value);
		 Wichtig: Das Ergebnis wird zurück in root->links gespeichert,
		 weil sich die Wurzel des linken Teilbaums durch Löschen ändern kann
		 (z.B. wenn der gelöschte Knoten die Teilbaum-Wurzel war).
	   - Danach geben wir root zurück (Wurzel dieses Teilbaums bleibt bestehen).

	   Wenn value > root->data:
	   - Analog im rechten Teilbaum:
		 root->rechts = Delete(root->rechts, value);
	   - Danach root zurückgeben.

	3) Knoten gefunden (value == root->data):
	   Jetzt wird wirklich gelöscht. Es gibt 3 klassische Fälle:

	   Fall A: Keine Kinder (Blattknoten)
	   - root->links == nullptr und root->rechts == nullptr
	   - Speicher des Knotens freigeben: delete root;
	   - nullptr zurückgeben, damit der Elternzeiger auf "leer" gesetzt wird.

	   Fall B: Genau ein Kind
	   - Wenn links leer ist, aber rechts existiert:
		   temp = root->rechts;
		   delete root;
		   return temp;
		 -> Der Elternknoten zeigt danach direkt auf das rechte Kind.
	   - Wenn rechts leer ist, aber links existiert:
		   temp = root->links;
		   delete root;
		   return temp;
		 -> Der Elternknoten zeigt danach direkt auf das linke Kind.

	   Fall C: Zwei Kinder
	   - Man kann den Knoten nicht einfach entfernen, ohne die BST-Eigenschaft zu verletzen.
	   - Typischer Trick:
		 * Suche den "Inorder-Nachfolger" im rechten Teilbaum:
		   Das ist das kleinste Element im rechten Teilbaum,
		   also: ganz nach links gehen ab root->rechts.
		 * Kopiere dessen Wert in den aktuellen Knoten (root->data = temp->data).
		   Dadurch ist der Wert "gelöscht", aber der Knoten bleibt an Ort und Stelle.
		 * Jetzt existiert der kopierte Wert noch einmal im rechten Teilbaum (bei temp),
		   daher löschen wir den Nachfolger-Knoten rekursiv:
		   root->rechts = Delete(root->rechts, temp->data);

	Ergebnis:
	- Jede Rekursion gibt die (möglicherweise neue) Wurzel ihres Teilbaums zurück.
	- Dadurch werden Elternzeiger korrekt aktualisiert, selbst wenn Teilbäume
	  durch Löschen ihre Wurzel wechseln.
*/

Node* Delete(Node* root, int value)
{
	if (root == nullptr)
	{
		return root;
	}

	if (value < root->data)
	{
		root->links = Delete(root->links, value);
		return root;
	}
	else if (value > root->data)
	{
		root->rechts = Delete(root->rechts, value);
		return root;
	}
	else
	{
		//keine Kinder:
		Node* temp;
		if (root->links == nullptr && root->rechts == nullptr) {
			delete root;
			return nullptr;
		}
		//ein Kind jeweils
		else if (root->links == nullptr)
		{
			temp = root->rechts;
			delete root;
			return temp;
		}
		//ein Kind jeweils
		else if (root->rechts == nullptr)
		{
			temp = root->links;
			delete root;
			return temp;

		}

		//2 kinder
		temp = root->rechts;

		while (temp && temp->links != nullptr) {
			temp = temp->links;
		}

		root->data = temp->data;

		root->rechts = Delete(root->rechts, temp->data);
	}
}

void freenodes(Node*& root)	//Referenz auf den Zeiger, damit Refrenz also root auch gelöscht wird, sonst bleibt es auf eine Adresse gesetzt
{
	if (root == nullptr)
	{
		return;
	}

	freenodes(root->links);
	freenodes(root->rechts);
	delete root;
	root = nullptr;
}

int main()
{
	Node* root = nullptr;
	root = insert(root, 10); // 0 10

	int values[] = { 10, 5, 20, 3, 7, 20 };

	for (int v : values)
		root = insert(root, v);

	printlistRight(root);
	printlistLeft(root);

	std::cout << SearchRekursiv(root, 5) << std::endl;
	std::cout << SearchIterativ(root, 7) << std::endl;

	Delete(root, 5);
	std::cout << SearchIterativ(root, 5) << std::endl;

	Delete(root, 7);
	std::cout << SearchIterativ(root, 7) << std::endl;

	freenodes(root);

	if (root == nullptr)
	{
		std::cout << "Root ist nullpointer";
	}
}
