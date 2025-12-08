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



/* Umsetzung Trainer
 *#include <iostream>

#include <vector>

using namespace std;
 
int binarysearch(vector<int> a, int value);
 
 
int binarysearch(vector<int> a, int value) 

{

    int low = 0;

    int high = a.size() - 1;

    int mitte = 0;
 
    while (low <= high) 

    {

         mitte = low + (high - low) / 2;
 
         if (a[mitte] == value) 

         {

             return mitte;

         }

         else if (a[mitte] < value)

         {

             low = mitte + 1;

         }

         else {

             high = mitte - 1;

         }

    }
 
    return -1;

}
 
int main()

{

    vector<int> a = { -5,-2,0,1,2,4,5,6,7,10 };

    int index = binarysearch(a, 7);
 
    if (index != -1) {

        cout << index << endl;

    }
 
    

}
 
*/