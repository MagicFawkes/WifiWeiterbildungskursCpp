
/*

Beschreibung:
----------------------------------------
Dieses Programm berechnet die **Fakultät** einer vom Benutzer eingegebenen Zahl.

Definition:
------------
Die Fakultät einer natürlichen Zahl *n* (geschrieben als *n!*) ist das Produkt
aller positiven ganzen Zahlen von 1 bis *n*.

Beispiel:
---------
5! = 5 × 4 × 3 × 2 × 1 = 120

Ablauf des Programms:
----------------------
1. **Eingabe der Zahl**
   Der Benutzer wird aufgefordert, eine ganze Zahl einzugeben, z. B. 6.

2. **Berechnung der Fakultät**
   Eine Schleife vom Wert der Eingabe bis 1 multipliziert fortlaufend alle Zahlen:
   ```c
   for (int i = eingabe; i > 0; i--)
       fakultät *= i;
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
    int eingabe = 0;
    int fakultät = 1;

    printf("Bitte gib eine Zahl ein: ");
    scanf("%d", &eingabe);

    for (int i = eingabe; i > 0; i--)
    {
        fakultät *= i;
    }

    printf("Fakultät einer Zahl ist: %d", fakultät);

    return 0;
}
