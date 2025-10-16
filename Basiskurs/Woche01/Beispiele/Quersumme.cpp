/*
Beschreibung:
----------------------------------------
Dieses Programm liest eine ganze Zahl vom Benutzer ein und führt darauf mehrere
Berechnungen durch:

1. **Ziffernanzahl zählen**
   Das Programm zerlegt die eingegebene Zahl in ihre einzelnen Ziffern, indem es
   wiederholt den Rest der Division durch 10 (`eingabe % 10`) nimmt und die Zahl
   anschließend durch 10 teilt (`eingabe /= 10`).
   Dabei wird gezählt, wie viele Ziffern die Zahl hat.

2. **Quersumme berechnen**
   Gleichzeitig wird die Quersumme berechnet – das ist die Summe aller Ziffern
   der eingegebenen Zahl.
   Beispiel: Eingabe `1234` → Quersumme = `1 + 2 + 3 + 4 = 10`.

3. **Teilbarkeit durch 3 prüfen**
   Eine mathematische Eigenschaft besagt:
   Eine Zahl ist durch 3 teilbar, **wenn ihre Quersumme durch 3 teilbar ist**.
   Das Programm überprüft diese Bedingung mit:
   ```c
   if ((quersumme % 3) == 0)
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
    int eingabe = 0, quersumme = 0, anzahl = 0;

    printf("Bitte gib eine Zahl ein: ");
    scanf("%d", &eingabe);

    while (eingabe % 10 != 0)
    {
        anzahl++;
        quersumme += eingabe % 10;
        eingabe /= 10;
    }

    printf("Anzahl der Ziffern %d\n", anzahl);
    printf("Die Quersumme der eingegebenen Zahlen ist: %d\n", quersumme);

    if ((quersumme % 3) == 0)
        printf("Die Quersumme ist durch 3 teilbar\n");
    else
        printf("Die Quersumme ist nicht durch 3 teilbar\n");

    return 0;
}
