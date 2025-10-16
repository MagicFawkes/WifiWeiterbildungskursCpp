/*
===============================================================================
Programm: Durchschnitt von drei Zahlen berechnen

Beschreibung:
Dieses einfache C-Programm liest drei Ganzzahlen (Integer) von der Tastatur ein
und berechnet anschließend ihren Durchschnittswert.

Ablauf:
1. Der Benutzer wird aufgefordert, drei ganze Zahlen einzugeben.
2. Die Eingabe erfolgt über `scanf`, wobei alle drei Zahlen nacheinander
   eingelesen werden.
3. Anschließend wird der Durchschnitt berechnet:
       (zahl1 + zahl2 + zahl3) / 3.0
   Durch die Division mit 3.0 (anstatt 3) wird sichergestellt, dass eine
   Gleitkomma-Berechnung (float/double) erfolgt, damit auch Nachkommastellen
   berücksichtigt werden.
4. Das Ergebnis wird mit zwei Nachkommastellen formatiert auf dem Bildschirm
   ausgegeben.

Zweck:
Das Programm dient dem Üben grundlegender C-Konzepte wie:
- Einlesen von Benutzereingaben mit `scanf`
- Arbeiten mit Variablen und Datentypen
- Formatierte Ausgabe mit `printf`
- Einfache mathematische Berechnungen

Autor: (Dein Name)
===============================================================================
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
    int zahl1 = 0;
    int zahl2 = 0;
    int zahl3 = 0;

    printf("Bitte gib drei Zahlen ein:\n");
    scanf("%d %d %d", &zahl1, &zahl2, &zahl3);

    printf("Durchschnitt der 3 Zahlen ergibt %.2f", (zahl1+zahl2+zahl3)/3.0);

    return 0;
}
