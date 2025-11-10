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
	float x, y, z;
};

bool betrag(struct vector v[], int n)
{
	bool condition = false;

	float betrag1 = pow(v[0].x, 2) + pow(v[0].y, 2) + pow(v[0].z, 2);
	float betrag2 = pow(v[1].x, 2) + pow(v[1].y, 2) + pow(v[1].z, 2);

	return betrag1 > betrag2;
}

void move(struct vector v[], int n)
{
	v[0].x += v[1].x;
	v[0].y += v[1].y;
	v[0].z += v[1].z;
}

int main()
{
	using namespace std;

	struct vector objekte[2];

	objekte[0].x = 1;
	objekte[0].y = 2;
	objekte[0].z = 3;

	objekte[1].x = 1;
	objekte[1].y = 5;
	objekte[1].z = 1;


	cout << "Erste Objekt ist " << (betrag(objekte, 2) == true ? "groesser" : "nicht groesser");

	return 0;
}

