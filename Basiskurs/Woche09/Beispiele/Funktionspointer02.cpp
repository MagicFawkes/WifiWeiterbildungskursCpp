/*
	Funktionspointer Beispiel
*/


#include <iostream>
#include <vector>
#include<fstream>

using namespace std;


void function(int x) {
    cout << x << endl;
}

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

bool Aufsteigend(int a, int b) {
    return a > b;
}

bool Absteigend(int a, int b) {
    return a < b;
}

void bubbleSortAufsteigend(vector<int>& arr) {

    for (int i = 0; i < arr.size(); i++) {
        for (int k = 0; k < arr.size() - 1 - i; k++) {
            if (Aufsteigend(arr[k], arr[k + 1])) {
                int temp = 0;
                arr[k] = arr[k + 1];
                arr[k + 1] = temp;
            }
        }
    }

}


void bubbleSortAbsteigend(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int k = 0; k < arr.size() - 1 - i; k++) {
            if (Absteigend(arr[k], arr[k + 1]))
            {
                int temp = 0;
                arr[k] = arr[k + 1];
                arr[k + 1] = temp;
            }
        }
    }
}


void bubblesort(vector<int>& arr, bool(*ptr)(int, int))
{
    for (int i = 0; i < arr.size(); i++) {
        for (int k = 0; k < arr.size() - 1 - i; k++) {
            if (ptr(arr[k], arr[k + 1]))
            {
                int temp = 0;
                arr[k] = arr[k + 1];
                arr[k + 1] = temp;
            }
        }
    }

}

int (*select_operation())(int, int) {
    //Code...//
    return add;
}


int main()
{
    int c = 10;
    int* ptr = &c;
    ptr = &c;

    void(*function_pointer)(int) = &function;
    //void(*function_pointer)(int);
    //function_pointer = function;
    //function_pointer = &function;

    (*function_pointer)(10);

    int(*ptr_func)(int, int);

    ptr_func = add;

    int result = (*ptr_func)(1, 2);

    cout << result << endl;

    int (*a[])(int, int) = { add,sub };

    a[0] = &sub;
    int summe = (a[0])(10, 5);

    vector<int> arr = { 1,2,4,9,5,0 };

    bubblesort(arr, Aufsteigend);
}


