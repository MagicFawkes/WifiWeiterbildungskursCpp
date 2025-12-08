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

		if (zahlen[mid] == suchWert)
			break;

		if (zahlen[mid] < suchWert)
			low = mid + 1;
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

