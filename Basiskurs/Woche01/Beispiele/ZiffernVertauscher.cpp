/*
    Dieses Programm liest eine ganze Zahl vom Benutzer ein und bildet daraus eine neue Zahl,
    deren Ziffern in umgekehrter Reihenfolge erscheinen — jedoch nur solange,
    bis eine durch 10 teilbare Zahl (also eine mit der Endziffer 0) erreicht wird.

    Beispiel:
        Eingabe: 1234
        Ablauf:
            - 4 wird entnommen und an neueSumme angehängt → neueSumme = 4
            - 3 wird entnommen → neueSumme = 43
            - 2 wird entnommen → neueSumme = 432
            - 1 wird entnommen → neueSumme = 4321
        Ergebnis: Neue Zahl = 4321

        Wenn die Eingabe mit 0 endet (z. B. 120), wird die Schleife beendet,
        sobald eingabe % 10 == 0 (also 0) ist — die 0 selbst wird nicht mehr berücksichtigt.

    Wichtige Schritte im Programm:
      1. Benutzer wird aufgefordert, eine Zahl einzugeben.
      2. Die letzte Ziffer der Zahl (eingabe % 10) wird isoliert.
      3. Diese Ziffer wird an „neueSumme“ angehängt (neueSumme = zahl + neueSumme * 10).
      4. Die Eingabe wird durch 10 geteilt, um die letzte Ziffer zu entfernen.
      5. Vorgang wiederholt sich, bis eine 0 am Ende der Zahl steht.
      6. Am Ende wird die neu gebildete, umgedrehte Zahl ausgegeben.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int eingabe = 0, neueSumme = 0, zahl = 0;

    printf("Bitte gib eine Zahl ein: ");
    scanf("%d", &eingabe);

    while (eingabe)
    {
        zahl = eingabe % 10;
        neueSumme = zahl + (neueSumme * 10);
        eingabe = eingabe / 10;
    }

    printf("Neue Zahl: %d\n", neueSumme);

    return 0;
}
