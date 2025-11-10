/*
„Schreiben Sie eine Funktion move, die zwei Vektordatenobjekten als Parameter
erhält und das erste Objekt um die Werte des zweiten Objekts verschiebt;
also das erste Objekt damit verändert.“
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
	move(objekte, 2);
	cout << "\nErste Objekt ist " << (betrag(objekte, 2) == true ? "groesser" : "nicht groesser");

	return 0;
}