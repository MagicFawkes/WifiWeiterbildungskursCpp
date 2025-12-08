/*

*/

#include <iostream>

using namespace std;

int main()
{
	int anzahl = 10;
	int zahlen[] = {-1,-2,3,4,5,6,7,8,9,10};
	int suchWert = -2;

	int low = 0;
	int high = anzahl - 1;
	int mid;

	do
	{
		mid = low + (high - low) / 2;
		// Check if x is present at mid
		if (zahlen[mid] == suchWert)
			break;

		// If x greater, ignore left half
		if (zahlen[mid] < suchWert)
			low = mid + 1;

		// If x is smaller, ignore right half
		else
			high = mid - 1;

		if (low > high)
		{
			mid = -1;
			break;
		}
	}
	while (true);


	cout << mid;

}

