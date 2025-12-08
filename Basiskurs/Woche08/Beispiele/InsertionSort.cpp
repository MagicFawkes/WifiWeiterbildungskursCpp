
/*
Insertion Sort ist ein einfacher Sortieralgorithmus in C++, der ein Array schrittweise aufbaut, 
indem jedes neue Element an die richtige Stelle eingefügt wird. Dabei wird jedes Element mit den 
vorherigen verglichen und so lange nach links verschoben, bis es korrekt einsortiert ist. 
Der Algorithmus ist sehr effizient für kleine oder fast sortierte Datenmengen, 
hat aber im schlimmsten Fall eine Laufzeit von
O(n2)
*/

#include <iostream>
#include <vector>
using namespace std;


int main()
{
	vector<int> a = { 4,2,8,4,2,86,3,7,45,9,5,43,87,4,76,43,76,32,4,7,3,87,89,4,23,21,2,5464,78,9,0,0 };

	int n = a.size();
	int j = 0;
	int value = 0;

	for (int i = 1; i < n; i++)
	{
		value = a[i];
		j = i - 1;

		while (j >= 0 && a[j] > value)
		{
			a[j + 1] = a[j];
			j--;
		}

		a[j + 1] = value;

	}

	for (int x : a) 
	{
		cout << x << endl;
	}
};