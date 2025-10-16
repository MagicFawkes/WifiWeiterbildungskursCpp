/*
===============================================================================
Programm: Berechnung der Stromkosten

Beschreibung:
Dieses Programm berechnet die Stromkosten anhand des eingegebenen
Stromverbrauchs in Kilowattstunden (kWh). Dabei wird ein unterschiedlicher
Preis pro kWh verwendet, je nachdem, ob der Verbrauch über oder unter einer
bestimmten Grenze liegt.

Ablauf:
1. Der Benutzer wird aufgefordert, den Stromverbrauch in kWh einzugeben.
2. Das Programm prüft anschließend:
      - Wenn der Verbrauch größer als 10 kWh ist, kostet eine kWh 0,30 €.
      - Wenn der Verbrauch 10 kWh oder weniger beträgt, kostet eine kWh 0,20 €.
3. Danach werden die Gesamtkosten berechnet:
      stromverbrauch * kostenProKWh
4. Das Ergebnis wird mit zwei Nachkommastellen auf dem Bildschirm ausgegeben.

Zweck:
Dieses Programm dient dem Üben von:
- Benutzereingaben mit `scanf`
- Verwendung von Gleitkommazahlen (float)
- Bedingten Anweisungen (`if` / `else`)
- Formatierter Ausgabe mit `printf`

Autor: (Dein Name)
===============================================================================
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
    float stromverbrauch = 0;
    float kostenProKWh;

    printf("Bitte gib deinen Stromverbracuh in kWh ein: ");
    scanf("%f", &stromverbrauch);

    if (stromverbrauch > 10)
        kostenProKWh = 0.30f;
    else
        kostenProKWh = 0.20f;

    printf("Der Stromverbrauch betraegt: EUR %.2f", stromverbrauch * kostenProKWh);
}
