/*
Aufgabe 2
Erstellen Sie ein Programm, bei dem der Benutzer eine Dezimalzahl eingibt. Das Programm soll
folgende Funktionen besitzen:
• Eine zur Umwandlung von Binär zu Dezimal
• Eine zur Speicherung der Werte in einem Array
Beachten Sie, dass Sie mit einem Array von Größe 1 Starten (int* a = (int *)(malloc(sizeof(int)))
*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdlib>
#include <stdio.h>

int eingabe(const char* message);
void printf_binary(int value);

int main()
{
    int* array = (int*)(malloc(sizeof(int)));
    int dezimalZahl;
    int anzahl = 0;

    do
    {
        dezimalZahl = eingabe("\nBitte Zahl eingeben \n0 = Eingabe beenden \nEingabe: ");

        if (dezimalZahl != 0)
        {
            anzahl++;
            array[anzahl - 1] = dezimalZahl;

			void* tmp = realloc(array, (anzahl + 1) * sizeof(int)); // Memory Leak vermeiden --> tmp Variable

        	if (tmp == NULL) 
            {
                perror("realloc failed"); //gibt eine Fehlermeldung von global Var errno aus

                return -1;
            }

            array = (int*)tmp;
			printf_binary(dezimalZahl);
        }

    } while (dezimalZahl != 0);

	free(array);

    return 0;
}

void printf_binary(int value)
{
    int anzahl = 0;
    int mask = 0;
    int temp = value;
    bool condition = true;

    while (condition) 
    {
        mask = (mask << 1) | 1; //0000 | 0001 = 0001, 0010 | 0001 = 0011, 0110 | 0001 = 0111 
        temp >>= 1;             //0101 -> 0010 -> 0001 -> 0000
        anzahl = anzahl + 1;
        if (temp == 0) 
        {
            break;
            //condition = false;
        }
    }

    printf("Binaer: 0b");

    for (int i = anzahl-1; i >= 0; i--) 
    {
        putchar((value & (1 << i)) ? '1' : '0');
        if (i % 4 == 0) putchar(' '); // nach 4 Bit trennen
    }
    printf("\n");
}

int eingabe(const char* message)
{
    int wert;
    int result;

    printf("%s", message);
    result = scanf("%d", &wert);

    if (result != 1)
    {
        // Eingabefehler behandeln
        printf("Ungueltige Eingabe. Standardwert 0 wird verwendet.\n");
        wert = 0;
    }

    return wert;
}