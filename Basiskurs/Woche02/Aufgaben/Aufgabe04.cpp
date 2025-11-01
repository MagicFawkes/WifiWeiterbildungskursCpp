/*
Aufgabe 4
Erstellen Sie ein Programm zur Berechnung der Fibonacci Folge
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int berechungFibonacci(int n);

int main()
{
    for (int i = 0; i < 20; i++)
    {
        printf("Die Zahlen %d \n", berechungFibonacci(i));
    }
   
    return 0;
}

int berechungFibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }

	if (n == 1)
	{
        return 1;
	}

	return berechungFibonacci(n - 1) + berechungFibonacci(n - 2);
}