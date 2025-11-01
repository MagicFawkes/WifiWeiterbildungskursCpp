/*
Aufgabe 5
Schreiben Sie ein C-Programm, das die n-größte Zahl in einem gegebenen Array bestimmt.
Der Benutzer soll eine Zahl n eingeben, und das Programm gibt anschließend die n-größte Zahl
des Arrays aus. Beispiel n = 3 dritt größte Zahl.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int eingabe(const char* message);
void arraySortieren(int arr[], int anzahl);

int main()
{
    int arr[] = { 2, 0, 1, 3, 4, 5, 3, 7, 8, 9, 10 };
    int anzahl = sizeof(arr) / sizeof(arr[0]);

	int zahl = eingabe("Geben Sie eine Zahl n ein, um die n-groesste Zahl zu finden: ");

    arraySortieren(arr, anzahl);

    if (zahl <= anzahl && zahl > 0)
    {
        printf("\n%d. groesste Zahl ist %d", zahl, arr[zahl - 1]);
    }
    else
    {
        printf("\nZahl nicht im gueltigen Bereich!\n");
    }

    return 0;
}

int eingabe(const char* message)
{
    int wert;
    int result;

    printf("%s", message);
    result = scanf("%d", &wert);

    if (result != 1)
    {
        // Handle input error, e.g., set default value or print error
        printf("Ungueltige Eingabe. Standardwert 0 wird verwendet.\n");
        wert = 0;
    }

    return wert;
}

void arraySortieren(int arr[], int anzahl)
{
    int tmp = 0;

    for (int i = 0; i < anzahl; i++)
    {
        for (int u = i + 1; u < anzahl; u++)
        {
            if (arr[u] > arr[i])
            {
                tmp = arr[i];
                arr[i] = arr[u];
                arr[u] = tmp;
            }
        }
    }
}