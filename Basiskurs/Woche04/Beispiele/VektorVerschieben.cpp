/*
„Schreiben Sie eine Funktion move, die zwei Vektordatenobjekten als Parameter
erhält und das erste Objekt um die Werte des zweiten Objekts verschiebt;
also das erste Objekt damit verändert.“
*/

#include <iostream>

struct vector
{
	int a, b;
};

void verschiebeObjekte(struct vector *objekteA, struct vector objekteB);

int main()
{
	using namespace std;

	struct vector objektA = {0};
	struct vector objektB = {0};

	cout << "Bitte zwei Werte eingeben: ";
	cin >> objektB.a >> objektB.b;

	verschiebeObjekte(&objektA, objektB);

	cout << "Werte von Objekt a ist: " << objektA.a << " und " << objektA.b;


	return 0;
}

void verschiebeObjekte(struct vector *objektA, struct vector objektB)
{
	objektA->a = objektB.a;
	objektA->b = objektB.b;
}