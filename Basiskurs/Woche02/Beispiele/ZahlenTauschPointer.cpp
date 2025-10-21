/*
 * Die Funktion pointerTausch tauscht zwei Pointer vom Typ int* miteinander.
 *
 * Parameter:
 *   - int** a: Adresse des ersten int-Pointers
 *   - int** b: Adresse des zweiten int-Pointers
 *
 * Funktionsweise:
 *   Da die Funktion die Adressen der Pointer (also Pointer auf Pointer) erhält,
 *   kann sie die tatsächlichen Zeiger in main() vertauschen.
 *   Dadurch zeigen nach dem Funktionsaufruf beide Pointer auf die jeweils
 *   andere Speicheradresse.
 *
 * Beispiel:
 *   Wenn a auf 47 und b auf 5 zeigt, zeigen nach dem Aufruf beide Pointer
 *   auf die jeweils andere Zahl.
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

void pointer_tausch(int** a, int** b);

int main()
{
	int *zahl1 = (int*)malloc(sizeof(int));
	*zahl1 = 47;
	int *zahl2 = (int*)malloc(sizeof(int));
	*zahl2 = 5;

	printf("Vor dem Tausch: zahl1 = %d, zahl2 = %d\n", *zahl1, *zahl2);
	pointer_tausch(&zahl1,&zahl2);
	printf("Nach dem Tausch: zahl1 = %d, zahl2 = %d\n", *zahl1, *zahl2);

	free(zahl1);
	free(zahl2);

    return 0;
}

void pointer_tausch(int** a, int** b)
{
	int* temp = *a;
	*a = *b;
	*b = temp;
}