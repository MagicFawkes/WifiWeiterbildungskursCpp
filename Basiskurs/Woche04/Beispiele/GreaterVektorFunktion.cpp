/*
c) Schreiben Sie eine Funktion greater, die zwei Vektordatenobjekte als Parameter erhält
und einen bool’schen Wert zurückgibt, der anzeigt, ob der Betrag
des ersten Objekts größer ist als der des zweiten.
Der Betrag eines Vektors sei dabei definiert durch:
∣a⃗∣=wurzel(a1^2+a2^2+a3^2)
*/

#include <iostream>

struct vector
{
	int a, b;
};

bool greaterA(struct vector objekte);

int main()
{
	using namespace std;
	struct vector objekte;

	cout << "Bitte zwei Werte eingeben: ";
	cin >> objekte.a >> objekte.b;
	cout << "Erste Objekt ist " << (greaterA(objekte) == true ? "groesser" : "nicht groesser");

	return 0;
}

bool greaterA(struct vector objekte)
{
	if (objekte.a > objekte.b)
		return true;

	return false;
}