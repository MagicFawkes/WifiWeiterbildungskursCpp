
/*
Rekursiv mit Fakultät Erklärung
*/

#include <iostream>
#include <vector>

using namespace std;

int fakultaet(int n)
{
	if (n <= 1) {
		return 1;
	}

	return n * fakultaet(n - 1);
}

//5 4 3 2 1
//faku(1)
//1 pop

//faku(2)
// 2 *faku(1) // 2 pop

//faku(3)
// 3 *faku(2) // 6 pop

//faku(4)
// 4 *faku(3) // 24 // pop

//faku(5) 
// 5* faku(4) // 120 //pop


int main()
{


};