/*
===============================================================================
Programm: Berechnung der Halbwertszeiten

Beschreibung:
Dieses Programm berechnet, wie viele Halbwertszeiten (HWZeiten) nötig sind,
damit ein gegebener Anfangswert durch wiederholtes Halbieren einen bestimmten
Endwert oder kleiner erreicht.

Ablauf:
1. Zu Beginn zeigt das Programm einen Startbildschirm mit einer kurzen Erklärung.
2. Danach wird der Benutzer aufgefordert, einen Anfangswert und einen gewünschten
   Endwert einzugeben.
3. Das Programm überprüft, ob der Endwert kleiner als der Anfangswert ist –
   andernfalls wird ein Hinweis ausgegeben und das Programm beendet sich.
4. In einer Schleife wird der Anfangswert so oft halbiert, bis er den Endwert
   erreicht oder unterschreitet. Dabei wird nach jeder Halbierung die aktuelle
   Anzahl der Halbwertszeiten und der neue Wert ausgegeben.
5. Am Ende wird ausgegeben, wie viele Halbwertszeiten insgesamt nötig waren.

Zweck:
Das Programm dient dem Verständnis des physikalischen Konzepts der Halbwertszeit
bzw. dem Üben von Schleifen, Funktionen und Ein-/Ausgabe in C.
===============================================================================
*/


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int wertEinlesen();
void startbildschirmProduzieren();
int wertHalbieren(int wert);
void ausgabeHalbwertszeit(int anfangswert, int endwert);

int main()
{
    startbildschirmProduzieren();

    printf("Bitte gib einen Anfangswert ein: ");
    int anfangswert = wertEinlesen();

    printf("Bitte gib einen gewuenschten Endwert ein: ");
    int endwert = wertEinlesen();

    if (anfangswert < endwert)
    {
        printf("Der Endwert muss kleiner als der Anfangswert sein.");
        return 1;
    }

    ausgabeHalbwertszeit(anfangswert, endwert);

    return 0;
}

int wertEinlesen()
{
    int eingabe = 0;

    scanf("%d", &eingabe);

    return eingabe;
}

void startbildschirmProduzieren()
{
    printf("Programm berechnet die Anzahl der Halbwertszeiten je nach Anfangsintensität und gewuenchten Endwert\n");
}

void ausgabeHalbwertszeit(int anfangswert, int endwert)
{
    int i = 0;

    do
    {
        i++;
        anfangswert = wertHalbieren(anfangswert);

        if (i == 1)
            printf("Nach %d HWZeit: %d\n", i, anfangswert);
        else
            printf("Nach %d HWZeiten: %d\n", i, anfangswert);
    } while (anfangswert > endwert);

    printf("Es ist/sind %d %s noetig", i, i == 1 ? "HWZeit" : "HWZeiten");
}

int wertHalbieren(int wert)
{
    return wert / 2;
}